#include <iostream>
#include <map>
#include <set>
#include <functional>

using namespace std;

struct Data {
    int time_stamp;
    int id;
    float vit_d;
    float acat;
    float anti_tg;
    float neural_activity;
    float mch;

    Data(): Data(0,0,0,0,0,0,0) {};
    Data(int timeStamp, int id, float vitD, float acat, float antiTg, float neuralActivity, float mch):
        time_stamp(timeStamp), id(id), vit_d(vitD), acat(acat), anti_tg(antiTg), neural_activity(neuralActivity), mch(mch){}
};

istream & operator >> (istream& input, Data& data){
    return input >> data.time_stamp
                 >> data.id
                 >> data.vit_d
                 >> data.acat
                 >> data.anti_tg
                 >> data.neural_activity
                 >> data.mch;
}

bool operator <(const Data& a, const Data& b){
    return a.neural_activity < b.neural_activity;
}

float neural_difference(const multiset<Data>& set){
    if(set.size() == 1) {
        return -1;
    }
    return (*set.crbegin()).neural_activity - (*set.cbegin()).neural_activity;
}


int main() {
    map<int, multiset<Data>> table;
    int N;

    cin >> N;
    for(int i = 0; i < N; i++){
        Data temp;
        cin >> temp;

        if(table.count(temp.id) == 0){
            table.emplace(temp.id, multiset<Data>{temp});
        } else {
            table.at(temp.id).emplace(temp);
        }
    }

    auto comparator = [&table](int a, int b){
        return neural_difference(table[a]) < neural_difference(table[b]);
    };

    multiset<int, function<bool(int,int)>> set(function<bool(int,int)>{comparator}); // магическая хрень

    for(auto & entry : table){
        if(entry.second.size() == 1) continue;

        set.emplace(entry.first);
    }

    if(!set.empty()) {
        auto entry = set.begin();
        for (int i = 0; (i < 3) and (entry != set.end()); i++) {
            cout << *entry << ' ';
            entry++;
        }
    } else {
        cout << -1;
    }

    return 0;
}