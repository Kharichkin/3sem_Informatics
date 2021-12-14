#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, index;
    char sign;

    cin >> N;

    vector<int> goblins;
    vector<int> output;

    for (int i = 0; i < N; i++){
        cin >> sign;
        if (sign == '+'){
            cin >> index;
            goblins.push_back(index);
        }
        else if (sign == '*'){
            cin >> index;
            int temp = goblins.size();
            if(temp > 1) {
                goblins.push_back(goblins[temp - 1]);
                for (int j = temp - 1; j > temp / 2 + temp % 2; j--) {
                    goblins[j] = goblins[j - 1];
                }
                goblins[temp / 2 + temp % 2] = index;
            }
            else{
                goblins.push_back(index);
            }
        }
        else if (sign == '-'){
            output.push_back(goblins[0]);
            goblins.erase(goblins.begin());
        }
    }

    for(int i = 0; i < output.size(); i++){
        cout << output[i] << endl;
    }

    return 0;
}