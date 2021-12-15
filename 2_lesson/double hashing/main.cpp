#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hash_function(string word, int size, int prime = 11){
    int hash  = 0;
    for(int  i = 0; i < word.size(); i++){
        hash = (prime * hash + word[i]) % size;
    }
    return hash;
}

int double_hashing(string word, int size, int prime = 41, int shift = 1){
    return ((hash_function(word, size, prime) * prime + shift) % size);
}

struct Word{
    string word;
    bool is_empty = true;
};

class Double_hashing{
public:
    vector <Word> hash_table;
    int size = 0;
    int size_occupied;

    Double_hashing(int new_size){
        hash_table = vector <Word> (new_size);
        size = new_size;
        size_occupied = 0;
    }

    Double_hashing(): Double_hashing(100){
    }

    void insert_word(string word){
        int hash = hash_function(word, size);
        int double_hash = double_hashing(word, size);
        int count = 0;
        while ((!hash_table[hash].is_empty) && (count < size)){
            hash = (hash + double_hash) % size;
            count++;
        }
        hash_table[hash].word = word;
        hash_table[hash].is_empty = false;
        size_occupied++;
    }


    void resize_table(){
        vector <Word> old_hash_table;
        old_hash_table.insert(old_hash_table.begin(), hash_table.begin(), hash_table.end());
        hash_table.clear();
        int old_table_size = size;
        hash_table = vector <Word>(2*old_table_size);
        size = 2*old_table_size;
        size_occupied = 0;
        for (int i = 0; i < old_table_size; i++){
            if (!old_hash_table[i].is_empty) {
                insert_word(old_hash_table[i].word);
            }
        }
        old_hash_table.clear();
    }

    Word* find_Word(string word){
        int hash = hash_function(word, size);
        int double_hash = double_hashing(word, size);
        bool flag = true;
        int count = 0;

        while (flag && (count < size)){
            if (hash_table[hash].word == word){
                flag = false;
            } else {
                hash = (hash + double_hash) % size;
            }
            count++;
        }
        if (!flag){
            return &hash_table[hash];
        } else {
            return nullptr;
        }
    }

    string* find_word(string elem){
        Word* node = find_Word(elem);
        return &node->word;
    }

    void add_word(string word){
        if (size_occupied + 1 > 0.75 * size){
            resize_table();
        }
        insert_word(word);
    }

    void delete_word(string elem){
        Word* node_to_del = find_Word(elem);
        node_to_del->is_empty = true;
        size_occupied--;
    }

    void print_hash_table(){
        for (int i = 0; i < size; i++){
            if (!hash_table[i].is_empty){
                cout << hash_table[i].word << endl;
            }
        }
    }
};

int main(){

    Double_hashing my_double_hashing(1);
    my_double_hashing.add_word("abcde");
    my_double_hashing.print_hash_table();

    return 0;
}