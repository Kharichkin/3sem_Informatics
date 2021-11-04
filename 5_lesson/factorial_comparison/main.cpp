#include <iostream>
#include <chrono>
using namespace std;

template <typename T>
T factorial_template (T number){
    if (number == 1 || number == 0){
        return 1;
    }
    else{
        return number * factorial_template(number - 1);
    }
}

int factorial (int number){
    if (number == 1 || number == 0){
        return 1;
    }
    else{
        return number * factorial(number - 1);
    }
}

int main(){
    auto start1 = chrono::steady_clock::now();
    cout << "factorial_template: " << factorial_template(10) << endl;
    auto finish1 = chrono::steady_clock::now();
    cout << "time: " << (finish1 - start1).count() << endl;

    auto start2 = chrono::steady_clock::now();
    cout << "factorial: " << factorial(10) << endl;
    auto finish2 = chrono::steady_clock::now();
    cout << "time: " << (finish2 - start2).count() << endl;
    return 0;
}
