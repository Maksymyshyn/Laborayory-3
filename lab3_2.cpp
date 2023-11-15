#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countNonNegativeElements(const std::vector<int>& row) {
    return std::count_if(row.begin(), row.end(), [](int element) {
        return element >= 0;
        });
}

int main() { 
    setlocale(LC_ALL, "ukr");
    int rows, columns;
    cout << "Введіть кількість рядків матриці: ";
    cin >> rows;

    cout << "Введіть кількість стовпців матриці: ";
    cin >> columns;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
        }
    }

    std::sort(matrix.begin(), matrix.end(), [](const std::vector<int>& row1, const std::vector<int>& row2) {
        return countNonNegativeElements(row1) < countNonNegativeElements(row2);
        });

    cout << "Впорядкована матриця за кількістю однакових елементів у рядках:\n";
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << '\n';
    }

    int firstNonNegativeColumn = -1;
    for (int j = 0; j < columns; j++) {
        bool hasNegativeElement = false;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] < 0) {
                hasNegativeElement = true;
                break;
            }
        }
        if (!hasNegativeElement) {
            firstNonNegativeColumn = j;
            break;
        }
    }

    if (firstNonNegativeColumn != -1) {
        cout << "Номер першого стовпця без від'ємних елементів: " << firstNonNegativeColumn << '\n';
    }
    else {
        cout << "Усі стовпці містять від'ємні елементи.\n";
    }

    return 0;
}
