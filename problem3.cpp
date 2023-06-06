#include <iostream>

void reverseFloyd(int row) {
    if (row == 1) {
        std::cout << 1;
    }
    else {
        int startValue = (row * (row - 1) / 2) + 1;
        std::cout << startValue;
        if (row != 1) {
            std::cout << ",";
        }
        reverseFloyd(row - 1);
    }
}

int main() {
    int numRows;
    std::cin >> numRows;

    reverseFloyd(numRows);
    std::cout << std::endl;

    return 0;
}
