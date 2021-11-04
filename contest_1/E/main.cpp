#include <iostream>
#include <stack>
using namespace std;

int main(){
    int v;

    stack<int> my_stack;

    cin >> v;
    while (v != 0){
        if (v > 0){
            my_stack.push(v);
        } else{
            if(my_stack.size() != 0) {
                if (-v < my_stack.top()) {
                    my_stack.top() += v;
                } else {
                    my_stack.pop();
                }
            }
        }

        cin >> v;
    }

    if(my_stack.size() != 0){
        cout << my_stack.size() << ' ' << my_stack.top();
    }else{
        cout << 0 << ' ' << -1;
    }

    return 0;
}