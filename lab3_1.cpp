#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> 

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    int N;
    cout << "Введіть розмір масиву N: ";
    cin >> N;

    vector<double> array(N);

  
    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    
    int sumPositiveIndices = 0;
    double sumAbsoluteValuesAfterPositive = 0;
    bool foundPositive = false;

    
    for (int i = 0; i < N; ++i) {
        if (array[i] > 0) {
            foundPositive = true;
            sumPositiveIndices += i;
        }

        if (foundPositive) {
            sumAbsoluteValuesAfterPositive += abs(array[i]);
        }
    }

    
    cout << "Сума індексів додатних елементів: " << sumPositiveIndices << endl;
    cout << "Сума модулів елементів після першого додатного: " << sumAbsoluteValuesAfterPositive << endl;

    
    stable_sort(array.begin(), array.end(), [](double a, double b) {
        return static_cast<int>(a) >= static_cast<int>(b);
        });

    
    cout << "Перетворений масив:\n";
    for (const auto& element : array) {
        cout << element << " ";
    }

    return 0;
}
