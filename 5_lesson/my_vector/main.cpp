#include <iostream>

template <class T>
struct Node{
    T value;
    Node* next_node = nullptr;

    Node(T value): value(value){}
};

template <class T>
struct Vector{
private:
    unsigned int size = 0;
    Node<T>* first_node = nullptr;

public:
    Vector(){}

    Vector(unsigned int size): size(size){
        first_node = Node<T>(0);
        Node<T>* current_node = first_node;
        for (int i = 1; i < size; i++){
            Node<T>* temporary_node = Node<T>(0);
            current_node->temporary_node;
            current_node = temporary_node;
        }
    }

    Vector(unsigned int size, T* array){
        Vecto
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
