#include "sudoku.h"

Sudoku::Sudoku(std::ifstream &entrada) {
    entrada >> this->N >> this->J >> this->I;
    int aux;
    for (int i=0; i < this->N; i++) {
        this->sudoku.push_back({});
        this->checked.push_back({});
        for (int j=0; j < this->N; j++) {
            entrada >> aux;
            sudoku[i].push_back({aux});
            if (aux != 0)
                checked[i].push_back(true);
            else
                checked[i].push_back(false);
        }
    }
}

bool Sudoku::isResolved() {
    for (int i = 0; i < this->N; i++) {
        for (int j = 0; j < this->N; j++) {
            if (checked[i][j] == false)
                return false;
        }
    }
    return true;
}

void Sudoku::solveSudoku() {
    for (int k=0; k < (this->N*this->N); k++) {
        for (int i=0; i < this->N; i++) {
            for (int j=0; j < this->N; j++) {
                if (sudoku[i][j].size() == 1 and checked[i][j] == false) {
                    checked[i][j] = true;
                    updatePossibilities();
                } else if (checked[i][j] == false) {
                    tryAvailablePossibilities(i, j);
                }
            }
        }
    }
}

void Sudoku::printSudoku() {
    for (int i=0; i < this->N; i++) {
        for (int j=0; j < this->N; j++) {
            if (checked[i][j] == 1)
                std::cout << sudoku[i][j][0];
            else
                std::cout << "0";
            if (j != this->N-1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Sudoku::tryAvailablePossibilities(int p_i, int p_j) {
    std::map <int, int> possibilities;
    int i_start, j_start;

    i_start = (p_i/this->I)*this->I;
    j_start = (p_j/this->J)*this->J;

    for (int i=i_start; i < i_start+this->I; i++) {
        for (int j=j_start; j < j_start+this->J; j++) {
            if (i == p_i and j == p_j)
                continue;
            else {
                for (auto element : sudoku[i][j]) {
                    if (possibilities.find(element) == possibilities.end())
                        possibilities[element] = 1;
                }
            }
        }
    }

    for (auto i : sudoku[p_i][p_j]) {
        if (possibilities.find(i) == possibilities.end()) {
            sudoku[p_i][p_j] = {i};
            checked[p_i][p_j] = 1;
            break;
        }
    }
}

void Sudoku::updatePossibilities() {
    for (int i=0; i < this->N; i++) {
        for (int j=0; j < this->N; j++) {
            if (sudoku[i][j][0] == 0 or checked[i][j] == false) {
                std::vector <int> possibilities = getAllPossibilities(i, j);
                sudoku[i][j] = possibilities;
            }
        }
    }
}

std::vector <int> Sudoku::getAllPossibilities(int i, int j) {
    std::vector <int> poss;
    for (int i=1; i < this->N+1; i++) {
        poss.push_back(i);
    }

    std::vector <int> cant = getAllThatCantBe(i, j);

    for (auto i : cant) {
        poss.erase(std::remove(poss.begin(), poss.end(), i), poss.end());
    }

    return poss;
}

std::vector <int> Sudoku::getAllThatCantBe(int i, int j) {
    std::vector <int> cant;

    std::vector <int> line = getElementsInLine(i, j);
    std::vector <int> col = getElementsInCol(i, j);
    std::vector <int> square = getElementsInSquare(i, j);

    cant.insert(cant.end(), line.begin(), line.end());
    cant.insert(cant.end(), col.begin(), col.end());
    cant.insert(cant.end(), square.begin(), square.end());

    return cant;
}

std::vector <int> Sudoku::getElementsInLine(int i, int j) {
    std::vector <int> exists;

    for (int k=0; k < this->N; k++) {
        if (checked[i][k] == true)
            exists.push_back(sudoku[i][k][0]);
    }

    return exists;
}

std::vector <int> Sudoku::getElementsInCol(int i, int j) {
    std::vector <int> exists;

    for (int k=0; k < this->N; k++) {
        if (checked[k][j] == true)
            exists.push_back(sudoku[k][j][0]);
    }

    return exists;
}

std::vector <int> Sudoku::getElementsInSquare(int i, int j) {
    std::vector <int> exists;
    int i_start, j_start;

    i_start = (i/this->I)*this->I;
    j_start = (j/this->J)*this->J;

    for (int i=i_start; i < i_start+this->I; i++) {
        for (int j=j_start; j < j_start+this->J; j++) {
            if (checked[i][j] == true)
                exists.push_back(sudoku[i][j][0]);
        }
    }
    return exists;
}

Sudoku::~Sudoku() {
}
