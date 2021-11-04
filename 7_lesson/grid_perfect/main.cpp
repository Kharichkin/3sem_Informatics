#include <iostream>
#include <memory>

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

    Grid(): x_size(1), y_size(1){
        memory = new T[1];
    }

    Grid(Grid<T> & grid) = delete;

    Grid(Grid<T> && grid): x_size(grid.get_xsize()), y_size(grid.get_ysize()){
        swap(this->memory, grid.memory);
        grid.memory = nullptr;
        grid.x_size = 0;
        grid.y_size = 0;
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

    Grid& operator=(Grid<T> & grid) = delete;

    Grid& operator=(Grid<T> && grid){
        if(this != &grid) {
            if ((this->x_size == grid.get_xsize()) & (this->y_size == grid.get_ysize())) {
                swap(this->memory, grid.memory);
                grid.memory = nullptr;
                grid.x_size = 0;
                grid.y_size = 0;
            } else {
                cerr << "Error";
            }
        }
    }

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
    Grid<float> grid_1(3, 2);
    grid_1 = 5;

    Grid<float> grid_2(3, 2);
    grid_2 = move(grid_1);
    cout << grid_2;

    Grid<float> grid_3(move(grid_2));
    cout << grid_3;
    return 0;
}