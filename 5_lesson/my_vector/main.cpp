#include <iostream>

template <class T>
struct Node{
    T value;
    Node* next_node = nullptr;

    Node(T val): value(val){};
};


template <class T>
class  Vector{
public:
    Node<T>* first_node;
    int lenght;

    Vector (){
        lenght = 0;
        first_node = nullptr;
    }

    int size () const{
        return lenght;
    }
    Node<T>* get_pointer (int place){
        Node<T>* current_node = first_node;
        for (int i = 0; i < place; i++){
            current_node = current_node->next_node;
        }
        return current_node;
    }

    T get_value(int i){
        return get_pointer(i)->value;
    }

    void set_value(int i, T val){
        if (i < lenght){
            get_pointer(i)->value = val;
        }
    }

    void insert_value(int i, T val){
        if (i <= lenght){
            Node<T>* node_to_add = new Node<T>(val);
            if (lenght == 0){
                first_node = node_to_add;
            } else {
                if (i == 0){
                    node_to_add->next_node = first_node;
                    first_node = node_to_add;
                } else {
                    Node<T>* prev_node = get_pointer(i - 1);
                    node_to_add->next_node = prev_node->next_node;
                    prev_node->next_node = node_to_add;
                }
            }
            lenght++;
        }
    }

    void push_back(T val){
        insert_value(lenght, val);
    }

    void pop(){
        if ((lenght == 0) || (lenght == 1)){
            delete first_node;
            first_node = nullptr;
            lenght = 0;
        } else {
            Node<T>* current_node = get_pointer(lenght - 2);
            Node<T>* node_to_del = current_node->next_node;
            delete node_to_del;
            current_node->next_node = nullptr;
            lenght--;
        }
    }

    friend std::ostream& operator << (std::ostream &output, const Vector<T> &vector){
        Node<T>* current_node = vector.first_node;
        output << current_node->value << " ";

        for (int i = 0; i < vector.size() - 1; i++){
            current_node = current_node->next_node;
            output << current_node->value << " ";
        }

        return output;
    }
};



int main(){

    Vector<int> vec;
    vec.push_back(5);
    vec.set_value(0, 1);
    std::cout << vec;

    return 0;
}
