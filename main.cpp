#include <iostream>
#include <string>

struct Input {
    std::string dot = ".";
    std::string x = "X";
};

void space() {
    std::cout << "\n\n\n";
}

void printDescending(int rows, int scope, std::string* content, std::string* space) {
    for (int row = 1; row <= scope; row++) {
        for (int item = 1; item <= rows; item++) {
            if (item < row || item > (rows-(row-1))) {
                std::cout << *space;
            } else {
                std::cout << *content;
            }
        }
        std::cout << std::endl;
    }
}

void printAscending(int rows, int scope, std::string* content, std::string* space) {
    for (int row = scope; row <= rows; row++) {
        for (int item = 1; item <= rows; item++) {
            if (item > row || item < (rows-(row-1))) {
                std::cout << *space;
            } else {
                std::cout << *content;
            }
        }
        std::cout << std::endl;
    }
}


void FourthFigure(int rows, std::string* content, std::string* space) {
    if (rows%2 != 1) {
        std::cout << "Mosaic didn't generate. Please provide odd number.\n";
        return;
    }

    int halfOfMosaic = rows/2+1;
    
    printDescending(rows, halfOfMosaic, content, space);
    printAscending(rows, halfOfMosaic+1, content, space);
}

void ThirdFigure(int rows, std::string* content, std::string* space) {
    for (int row = 1; row <= rows; row++) {
        for (int item = 1; item <= rows; item++) {
            if (item < row) {
                std::cout << *space;
            } else {
                std::cout << *content;
            }
        }
        std::cout << std::endl;
    }
}

void printMosaic(int rows, int repeats, std::string* firstSymbol, std::string* secondSymbol) {
    for (int r = 1; r <= rows; r++) {
        for (int repeat = 1; repeat <= repeats; repeat++) {
            if (r%2 == 1) {
                std::cout << *firstSymbol;
            } else {
                std::cout << *secondSymbol;
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    Input input;
    std::string xDotMosaic = input.x + input.dot;
    std::string dotXMosaic = input.dot + input.x;

    space();
    printMosaic(7,13, &input.x, &input.dot);
    space();
    printMosaic(8, 10, &xDotMosaic, &xDotMosaic);
    space();
    ThirdFigure(11, &input.x, &input.dot);
    space();
    FourthFigure(11, &input.x, &input.dot);
    space();
    printMosaic(10,10, &xDotMosaic, &dotXMosaic);
    return 0;
}