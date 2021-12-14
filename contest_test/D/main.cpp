#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int n;
    string word;

    cin >> n;

    multiset <string> my_set;

    for (int i = 0; i < n; i ++){

        cin >> word;
        for (char j = 0; j < word.size(); j++){
            word[j] = tolower(word[j]);
        }

        my_set.insert(word);
    }

    string answer= *my_set.begin();
    int number, temp = 1;
    for (auto i = my_set.begin(); i != my_set.end(); ++i){
        temp = my_set.count(*i);
        if(temp > number){
            number = temp;
            answer = *i;
        }
    }

    cout << answer << ' ' << number;

    return 0;
}