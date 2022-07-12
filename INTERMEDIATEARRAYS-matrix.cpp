// Programme loads squared matrix and checks if it is triangular

#include <iostream>

using namespace std;

int main()
{
    int size;
    bool isValid = true;
    cout << "Provide matrix size: " << endl;
    cin >> size;

    int** array = new int* [size];

    for (int i = 0; i < size; i++) {
        array[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> array[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (array[i][j] != 0) {
                cout << "Matrix is not bottom triangular" << endl;
                isValid = false;
                break;
            }
        }
    }

    if (isValid) {
        cout << "Matrix is bottom triangular" << endl;
    }

    for (int i = 0; i < size; i++) {
        delete[] array[i];
    }

    return 0;
}
