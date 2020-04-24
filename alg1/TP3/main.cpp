#include <bits/stdc++.h>
#include "sudoku.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Ops.. o número de argumentos passados está incorreto =/" << std::endl;
        return 1;
    }

    std::ifstream entrada = std::ifstream(std::string(argv[1]));
    /* Create graph with edges */
    Sudoku s = Sudoku(entrada);

    s.updatePossibilities();

    s.solveSudoku();

    if (s.isResolved()) {
        std::cout << "solução" << std::endl;
    }
    else {
        std::cout << "sem solução" << std::endl;
    }
    s.printSudoku();

    return 0;
}
