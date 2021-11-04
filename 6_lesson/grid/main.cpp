#include <iostream>

typedef float T;
using namespace std;

template <typename T>
class Grid{
private:
    T * memory;
    unsigned int x_size, y_size;

public:
    Grid(unsigned int x_size, unsigned int y_size): x_size(x_size), y_size(y_size){
        if ((x_size > 0) || (y_size > 0)) {
            memory = new T[x_size * y_size];
        } else {
            cerr << "Error";
        }
    }

    ~Grid(){
        delete[] memory;
    };

    T operator()(unsigned int x_idx, unsigned int y_idx) const{
        if ((0 <= x_idx) & (x_idx < this->x_size) & (0 <= y_idx) & (y_idx < this->y_size)) {
            return memory[x_size * y_idx + x_idx];
        } else {
            cerr << "Error";
        }
    };
    T & operator()(unsigned int x_idx, unsigned int y_idx){
        if ((0 <= x_idx) & (x_idx < this->x_size) & (0 <= y_idx) & (y_idx < this->y_size)) {
            T &a = memory[x_size * y_idx + x_idx];
            return a;
        } else {
            cerr << "Error";
        }
    };

    unsigned int get_xsize() const{
        return x_size;
    };
    unsigned int get_ysize() const{
        return y_size;
    };

    Grid& operator=(T value){
        for (unsigned int i = 0; i < this->x_size*y_size; i++){
            this->memory[i] = value;
        }
        return *this;
    };

    friend ostream& operator<<(ostream& stream, Grid const& grid){
        for (unsigned int j = 0; j < grid.get_ysize(); j++) {
            for (unsigned int i = 0; i < grid.get_xsize(); i++) {
                stream << grid(i, j) << " ";
            }
            stream << endl;
        }
        return stream;
    };

    friend istream& operator>>(istream& stream, Grid& grid){
        for (unsigned int k = 0; k < grid.get_xsize() * grid.get_ysize(); k++){
            stream >> grid(k % grid.get_xsize(), k / grid.get_xsize());
        }
        return stream;
    };
};

int main() {
    Grid<float> my_grid(3, 2);
    my_grid = 5;
    cin >> my_grid;
    my_grid(0,0) = 0;
    cout << my_grid;
    my_grid.~Grid();
    return 0;
}
