#ifndef SUDOKU_H
#define SUDOKU_H

#include <bits/stdc++.h>

class Sudoku {
private:
    int N, I, J;
    std::vector <std::vector <std::vector<int>>> sudoku;
    std::vector <std::vector <bool>> checked;
public:
    Sudoku(std::ifstream &entrada);

    bool isResolved();

    void solveSudoku();
    void printSudoku();
    void updatePossibilities();
    void tryAvailablePossibilities(int i, int j);

    std::vector <int> getAllPossibilities(int i, int j);
    std::vector <int> getAllThatCantBe(int i, int j);
    std::vector <int> getElementsInLine(int i, int j);
    std::vector <int> getElementsInCol(int i, int j);
    std::vector <int> getElementsInSquare(int i, int j);

    ~Sudoku();
};

#endif /* SUDOKU_H */
