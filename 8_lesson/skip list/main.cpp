#include <iostream>
#include <vector>
#include <random>

using namespace std;

template <class T>
struct Node{
    T value;
    int row;
    vector<Node*> nodes_in_row;

    Node (const T& new_value){
        value = new_value;
    }

    Node (const T& new_value, int new_row){
        value = new_value;
        row = new_row;

        for (int i = 0; i < row; i++){
            nodes_in_row.push_back(nullptr);
        }
    }
};

template <class T>
class SkipList{

public:
    int length;
    int rows_number;
    Node<T>* first_in_row;

    double seed = 0;

    void set_first_in_row(){
        first_in_row = new Node<T>(numeric_limits<T>::lowest());

        for (int i = 0; i < rows_number; i++){
            first_in_row->nodes_in_row.push_back(nullptr);
        }
    }

    int choose_row(){
        random_device rd;
        uniform_int_distribution<> distr(0, 100);
        double random_number = (double)distr(rd) / (100);

        int count = 0;
        while ((random_number <= seed) && (count < rows_number)){
            count++;
            random_number = (double)distr(rd) / (100);
        }
        return count;
    }

    SkipList(){
        seed = 0.5;
        length = 0;
        rows_number = 100;
        set_first_in_row();
    };

    SkipList(double new_seed, int new_rows_number){
        seed = new_seed;
        rows_number = new_rows_number;
        length = 0;
        set_first_in_row();
    };

    SkipList(double probability): SkipList(probability, 100){};

    SkipList(const SkipList& List){
        seed = List.seed;
        length = List.length;
        rows_number = List.rows_number;
        first_in_row = List.first_in_row;
    }

    SkipList(SkipList&& List){
        seed = List.seed;
        length = List.length;
        rows_number = List.rows_number;
        first_in_row = List.first_in_row;

        List.seed = 0;
        List.rows_number = 0;
        List.length = 0;
        List.first_in_row = nullptr;
    }

    SkipList& operator = (SkipList&& List){

        swap(first_in_row, List.first_in_row);
        swap(seed, List.seed);
        swap(length, List.length);
        swap(rows_number, List.rows_number);

        return *this;
    }


    void insert(const T& new_value){
        int row = choose_row();
        Node<T>* current_node = first_in_row;
        Node<T>* next_node = new Node<T>(new_value, row + 1);

        for (auto i = rows_number - 1; i >= 0; i--){
            while ((current_node->nodes_in_row[i] != nullptr) && ((*current_node).nodes_in_row[i]->value < new_value)){
                current_node = current_node->nodes_in_row[i];
            }

            if (i <= row){
                next_node->nodes_in_row[i] = current_node->nodes_in_row[i];
                current_node->nodes_in_row[i] = next_node;
            }
        }

        length++;
    }

    friend ostream& operator << (ostream &output, const SkipList<T> &skip_list){
        for (int i = skip_list.rows_number - 1; i >= 0; i--){
            Node<T>* it = skip_list.first_in_row;
            while (it->nodes_in_row[i] != nullptr){
                it = it->nodes_in_row[i];
                output << it->value << " ";
            }
        }

        return output;
    }
};

int main(){
    SkipList<int> List (0.1);
    List.insert(1);
    List.insert(2);
    List.insert(3);

    cout << List;

    return 0;
}
