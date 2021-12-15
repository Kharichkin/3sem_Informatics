#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

bool comp(int a[4], int b[4]){
    if(a[3] < b[3]){
        return true;
    } else if(a[3] = b[3]){
        if(a[2] < b[2]){
            return true;
        }
        else if(a[2] = b[2]){
            if(a[1] < b[1]){
                return true;
            } else if(a[1] = b[1]){
                if(a[4] < b[4]){
                    return true;
                } else{
                    return false;
                }
            } else{
                return false;
            }
        } else{
            return false;
        }
    } else{
        return false;
    }
}

int main() {
    vector<int[4]> dates;
    int N = 0, M = 0;
    string str;

    cin >> N;
    for (int i = 0; i < N; i++) {
        /*getline(cin, str);
        int pos = str.find('.');
        int day = stoi(str.substr(0, pos));
        str.erase(0, pos + 1);
        pos = str.find('.');
        int month = stoi(str.substr(0, pos));
        str.erase(0, pos + 1);
        pos = str.find(' ');
        int year = stoi(str.substr(0, pos));
        str.erase(0, pos + 1);
        int bursts = stoi(str.substr(0, pos));
        cout << day << "." << month << "." << year << " " << bursts;*/
        int day, month, year, bursts;
        char delimiter;
        cin >> day;
        cin >> delimiter;
        cin >> month;
        cin >> delimiter;
        cin >> year;
        cin >> bursts;
        dates.push_back({day, month, year, bursts});
    }

    sort(dates.begin(), dates.end(), comp);
    cin >> M;

    for (int i = 0; i < N; i++) {
        cout << dates[i];
    }


    return 0;
}
