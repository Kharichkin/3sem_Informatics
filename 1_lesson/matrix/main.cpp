#include <iostream>

using namespace std;

class Matrix{
private:
    int m, n;
    int** matrix;

public:
    Matrix(int m = 1, int n = 1){
        this->m = m;
        this->n = n;
        matrix = new int*[m];
        for(int i = 0; i < m; i++){
            matrix[i] = new int[n];
            for(int j = 0; j < n; j++){
                matrix[i][j] = 0;
            }
        }
    }

    int get_rows_number(){
        return m;
    }

    int get_columns_number(){
        return n;
    }

    int get_value(int i, int j){
        return matrix[i][j];
    }
};

int main() {
    Matrix my_matrix;
    cout << my_matrix.get_value(0, 0) << " " << my_matrix.get_columns_number();
    return 0;
}
