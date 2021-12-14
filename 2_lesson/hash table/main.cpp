#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int hash_function(string word, int size, int prime = 47){
    int hash  = 0;
    for(int  i = 0; i < word.size(); i++){
        hash = (prime * hash + word[i]) % size;
    }
    return hash;
}

int double_hashing(string word, int size, int prime = 43, int shift = 1){
    return ((hash_function(word, size, prime) * prime + shift) % size);
}

class Hash_table{
public:
    int table_size;
    vector<vector <string>> hash_list;
    int size_occupied;
    int word_number;

    Hash_table(int size_table){
        table_size = size_table;
        for (int i = 0; i < table_size; i++){
            hash_list.push_back(vector <string>());
        }
        size_occupied = 0;
    }

    Hash_table(): Hash_table(100){
    }

    void resize_table(){
        int new_table_size = table_size * 2;
        vector<vector <string>> new_hash_list(new_table_size);
        for (int i = 0; i < table_size; i++){
            for (string j : hash_list[i]){
                int hash = hash_function(j, new_table_size);
                new_hash_list[hash].push_back(j);
            }
        }
        hash_list.clear();
        hash_list.insert(hash_list.begin(), new_hash_list.begin(), new_hash_list.end());
        table_size = new_table_size;
    }

    string* find_word(string word){
        int hash = hash_function(word, table_size);
        auto word_to_find = find(hash_list[hash].begin(), hash_list[hash].end(), word);
        if (word_to_find < hash_list[hash].end()){
            int index = distance(hash_list[hash].begin(), word_to_find);
            return &hash_list[hash][index];
        } else {
            return nullptr;
        }
    }

    void add_word(string word){
        if (size_occupied > 0.75 * table_size){
            resize_table();
        }
        int hash_elem = hash_function(word, table_size);
        if (hash_list[hash_elem].size() == 0){
            size_occupied++;
        }
        hash_list[hash_elem].push_back(word);
        word_number++;
    }

    void delete_word(string word){
        int hash = hash_function(word, table_size);
        auto word_to_delete = find(hash_list[hash].begin(), hash_list[hash].end(), word);
        if (word_to_delete < hash_list[hash].end()){
            int index = distance(hash_list[hash].begin(), word_to_delete);
            hash_list[hash].erase(hash_list[hash].begin() + index);
            if (hash_list[hash].size() == 0){
                size_occupied--;
            }
            word_number--;
        }
    }

    void print_hash_table(){
        for(int i = 0; i < table_size; i++){
            if(hash_list[i].size() != 0){
                for (string j : hash_list[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
        }
        cout << size_occupied << " " << word_number << endl;
    }
};

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
        hash_table = vector <Word>(old_table_size * 2);
        size = old_table_size * 2;
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
        if (size_occupied + 1 > (3 * size) / 4){
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
