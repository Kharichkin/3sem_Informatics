#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> split(const string& str, char delimiter){
    vector<string> output{""};

    int i = 0;
    for(auto symbol : str){
        if(symbol != delimiter) {
            output[i].push_back(symbol);
        } else {
            output.emplace_back("");
            i++;
        }
    }
    output.pop_back();

    return output;
}

struct Date {
    int day;
    int month;
    int year;

    Date() = default;

    Date(const string& date){
        vector<string> temp = split(date, '.');
        day = stoi(temp[0]);
        month = stoi(temp[1]);
        year = stoi(temp[2]);
    }

    friend bool operator<(const Date &left, const Date &right){
        if (left.year < right.year) {
            return true;
        }
        if (right.year < left.year) {
            return false;
        }

        if (left.month < right.month) {
            return true;
        }
        if (right.month < left.month) {
            return false;
        }

        return left.day < right.day;
    }

    friend istream &operator>>(istream &input, Date &date) {
        string temp;
        input >> temp;
        date = Date(temp);
        return input;
    }
};

int main(){
    int N;
    int M;

    map<Date, int> calendar;

    cin >> N;
    for (int i = 0; i < N; i++) {
        Date date{};
        int bursts;
        cin >> date >> bursts;

        auto current_date = calendar.find(date);
        if(current_date == calendar.end()){
            calendar.emplace(date, bursts);
        } else {
            if(current_date->second < bursts){
                current_date->second = bursts;
            }
        }
    }

    int temp = calendar.begin()->second;
    for(auto& current_date : calendar){
        if(current_date.second < temp )
            current_date.second = temp;
        else
            temp = current_date.second;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        Date date{};
        cin >> date;

        auto current_date = calendar.upper_bound(date);
        if (current_date == calendar.begin()) {
            cout << 0 << endl;
            continue;
        }
        current_date--;
        cout << current_date->second << endl;
    }

    return 0;
}