#include <iostream>
#include <fstream>
#include <set>
#include <random>
#include <vector>

class State{
public:
    virtual bool contains(int s) const = 0;
};

class DiscreteState: public State { // одно точечное состояние
private:
    int const state;

public:
    DiscreteState(int state): state(state) { }

    bool contains(int s) const {
        return s == state;
    }
};

class SegmentState: public State {  // отрезок состояний
private:
    int const beg, end;

public:
    SegmentState(): beg(0), end(-1) { }
    SegmentState(int beg, int end): beg(beg), end(end) { }

    bool contains(int s) const {
        return s >= beg && s <= end;
    }
};

class SetState: public State {  // множество состояний
private:
    std::set<int> const states;

public:
    SetState(): states() { }
    SetState(std::set<int> const &src): states(src) { }

    bool contains(int s) const {
        return states.count(s) > 0;
    }
};

class UnionState: public State {  // объединение состояний
private:
    std::vector<State*> const states;

public:
    UnionState(): states() { }
    UnionState(std::vector<State*> const &src): states(src) { }

    bool contains(int s) const {
        bool is_anywhere = false;
        for(int i = 0; i < states.size(); i++){
            if(states[i]->contains(s)) is_anywhere = true;
        }
        return is_anywhere;
    }
};

class IntersectionState: public State {  // пересечение состояний
private:
    std::vector<State*> const states;

public:
    IntersectionState(): states() { }
    IntersectionState(std::vector<State*> const &src): states(src) { }

    bool contains(int s) const {
        bool is_everywhere = true;
        for(int i = 0; i < states.size(); i++){
            if(!(states[i]->contains(s))) is_everywhere = false;
        }
        return is_everywhere;
    }
};

class ProbabilityTest {
private:
    unsigned int seed;
    int test_min, test_max;
    unsigned int test_count;

public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count): seed(seed), test_min(test_min),test_max(test_max), test_count(test_count) { }

    float operator()(State const &s) const {
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<int> dstr(test_min,test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng))) ++good;

        return static_cast<float>(good)/static_cast<float>(test_count);
    }
};

void test(){
    DiscreteState d(1);
    SegmentState s(0,10);
    SetState ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});
    UnionState us({&d, &s, &ss});
    IntersectionState is({&d, &s, &ss});

    ProbabilityTest pt(10,0,99,100000);

    std::ofstream fos;
    fos.open("./default_test.txt");
    fos << "DiscreteState: " << pt(d) << std::endl;
    fos << "SegmentState: " << pt(s) << std::endl;
    fos << "SetState: " << pt(ss) << std::endl;
    fos << "UnionState: " << pt(us) << std::endl;
    fos << "IntersectionState: " << pt(is) << std::endl;
    fos.close();
}

void number_of_tests_dependence(State* state, int max_number, std::string filename){
    std::ofstream fos;
    fos.open(filename);
    for(int test_count = 1; test_count <= max_number; test_count++){
        ProbabilityTest pt(10, 0, 99, test_count);
        fos << test_count << ": " << pt(*state) << std::endl;
    }
    fos.close();
}

void set_state_test(){
    SetState ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});
    number_of_tests_dependence(&ss, 10000, "./number_of_tests_SetState_test.txt");
}
void segment_state_test(){
    SegmentState s(0, 10);
    number_of_tests_dependence(&s, 10000, "./number_of_tests_SegmentState_test.txt");
}

void number_of_elements_dependence(int max_number, std::string filename){
    std::ofstream fos;
    fos.open(filename);
    ProbabilityTest pt(10, 0, max_number, 10000);
    for(int elements_count = 0; elements_count <= max_number; elements_count++){
        SegmentState s(0, elements_count);
        fos << elements_count << ": " << pt(s) << std::endl;
    }
    fos.close();
}

void number_of_elements_test(){
    number_of_elements_dependence(9999, "./number_of_elements_test.txt");
}

int main(int argc, const char * argv[]) {
    test();
    set_state_test();
    segment_state_test();
    number_of_elements_test();
    return 0;
}
