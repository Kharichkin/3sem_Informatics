#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class Cell{
public:
    char v;                                              // Вертикаль, от 'A' до 'H'
    unsigned short int h;                                // Горизонталь, от '1' до '8'
    Cell(): Cell('A',1) {}                         // Конструктор клетки по умолчанию
    Cell(char v, unsigned short int h): v(v), h(h) {}    // Конструктор заданной клетки поля с параметрами
};

class Piece {
protected:
    Cell cell;
public:
    explicit Piece(Cell cell): cell(cell) {};
    virtual bool available(Cell cell) = 0;
};

class King : public Piece {
public:
    explicit King(const Cell &cell): Piece(cell) {};

    bool available(Cell cell) {
        if(this->cell.v == cell.v && this->cell.h == cell.h) return false;

        return abs((int)cell.v - (int)this->cell.v) <= 1 && abs(cell.h - this->cell.h) <= 1;
    }
};

class Queen : public Piece {
public:
    explicit Queen(const Cell &cell): Piece(cell) {};

    bool available(Cell cell) {
        if(this->cell.v == cell.v && this->cell.h == cell.h) return false;

        return ((cell.v == this->cell.v) || (cell.h == this->cell.h)) || ((this->cell.v + this->cell.h == cell.v + cell.h) || (this->cell.v - this->cell.h == cell.v - cell.h));
    }
};

class Rook : public Piece {
public:
    explicit Rook(const Cell &cell): Piece(cell) {};

    bool available(Cell cell) {
        if(this->cell.v == cell.v && this->cell.h == cell.h) return false;

        return (cell.v == this->cell.v) || (cell.h == this->cell.h);
    }
};

class Bishop : public Piece {
public:
    explicit Bishop(const Cell &cell): Piece(cell) {};

    bool available(Cell cell) {
        if(this->cell.v == cell.v && this->cell.h == cell.h) return false;

        return (this->cell.v + this->cell.h == cell.v + cell.h) || (this->cell.v - this->cell.h == cell.v - cell.h);
    }
};


vector <bool> are_available(Cell c, vector<Piece*> const &pieces) {
    vector<bool> answ;
    for (auto p : pieces)
        answ.push_back(p->available(c));
    return answ;
}


int main(){
    vector<Piece*> pieces;
    pieces.push_back(new King(Cell('A',1)));
    pieces.push_back(new Queen(Cell('B',2)));
    pieces.push_back(new Rook(Cell('C',3)));
    pieces.push_back(new Bishop(Cell('D',4)));

    for(auto b : are_available(Cell('A',1),pieces))
        cout << b << ' ';
    cout << endl;

    for (auto p : pieces)
        delete p;

    return 0;
}
