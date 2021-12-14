#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, a;
    set<int> my_set;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> a;
        my_set.insert(a);
    }

    cout << my_set.size();
    return 0;
}
