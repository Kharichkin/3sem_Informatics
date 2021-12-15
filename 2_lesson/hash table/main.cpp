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
    }
};

int main(){

    Hash_table my_hash_table(1);
    my_hash_table.add_word("abcde");
    my_hash_table.print_hash_table();

    return 0;
}
