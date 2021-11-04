#include <iostream>
using namespace std;

template <typename T>
T max_function (T* numbers, unsigned int size){
    T max = numbers[0];
    for (int i = 1; i < size; i++){
        if (numbers[i] > max){
            max = numbers[i];
        }
    }

    return max;
}

int main() {
    int int_array[] = {1, 2, 3, 4, 5};
    char char_array[] = {'a', 'b', 'c', 'd', 'e'};
    double double_array[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    cout << max_function(double_array, 5) << endl;
    return 0;
}
