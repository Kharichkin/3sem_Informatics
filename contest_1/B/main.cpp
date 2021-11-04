#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int n;
    string word;

    cin >> n;

    set <string> my_set;

    for (int i = 0; i < n; i ++){

        cin >> word;
        for (char j = 0; j < word.size(); j++){
            word[j] = tolower(word[j]);
        }

        my_set.insert(word);
    }

    for (auto i = my_set.rbegin(); i != my_set.rend(); ++i){
        cout << *i << ' ';
    }

    return 0;
}