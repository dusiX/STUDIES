#include <iostream>

using namespace std;

class Matrix {
private:
    static constexpr int N{ 10 };

public:
    int n;
    int** tab;

    Matrix(int a) {
        this->n = a;
        this->tab = new int* [n];
        for (int i = 0; i < n; i++)
            tab[i] = new int[n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                tab[i][j] = rand() % 100;
            }
        }
    }

    Matrix(int* a, int b) {
        this->n = b;
        *tab = a;
    }

    ~Matrix() {
        if (tab != nullptr) {
            for (int i = 0; i < n; ++i) {
                delete[] tab[i];
            }
        }
    }

    Matrix& operator+=(const Matrix& c) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                tab[i][j] += c.tab[i][j];
            }
        }
        return *this;
    }

    Matrix& operator-=(const Matrix& c) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                tab[i][j] -= c.tab[i][j];
            }
        }
        return *this;
    }

    Matrix& operator()(int &a, int &b) {
        this->tab[a][b];
        cout << tab[a][b] << endl;
        return *this;
    }

    void transp() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << tab[j][i] << " ";
            }
            cout << endl;
        }
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << tab[i][j] << " ";
            }
            cout << endl;
        }
    }

};

Matrix& operator+(const Matrix& a, const Matrix& b) {

    Matrix c(a.n);

    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.n; j++) {
            c.tab[i][j] = a.tab[i][j] + b.tab[i][j];
        }
    }

    return c;
}

int main()
{
    int a, b, c, d;
    Matrix m1(5);
    Matrix m2(5);

    cout << "Pierwsza macierz: " << endl;
    m1.print();
    cout << endl;

    cout << "Druga macierz: " << endl;
    m2.print();
    cout << endl;

    cout << "Co chcesz zrobic z macierzami?" << endl;
    cout << "Dodawanie --> 1" << endl;
    cout << "Odejmowanie --> 2" << endl;
    cout << "Wydrukowanie [i][j] elementu macierzy --> 3" << endl;
    cout << "Transponacja macierzy --> 4" << endl;
    cout << endl;
    cin >> a;
    cout << endl;

    switch (a) {
    case 1:
        cout << "Suma macierzy: " << endl;
        m1 += m2;
        m1.print();
        cout << endl;
        break;
    case 2:
        cout << "Roznica macierzy: " << endl;
        m1 -= m2;
        m1.print();
        cout << endl;
        break;
    case 3:
        cout << "Wybierz macierz 1 albo 2: " << endl;
        cout << endl;
        cin >> b;
        if (b > 2) { break; }
        cout << endl;

        cout << "Wybierz rzad macierzy od 0 do 4:" << endl;
        cout << endl;
        cin >> c;
        if (c > 4) { break; }
        cout << endl;

        cout << "Wybierz wiersz macierzy od 0 do 4:" << endl;
        cout << endl;
        cin >> d;
        if (c > 4) { break; }
        cout << endl;

        switch (b) {
        case 1:
            m1(d, c);
            break;
        case 2:
            m2(d, c);
            break;
        }

        break;
    case 4:
        cout << "Wybierz macierz 1 albo 2: " << endl;
        cout << endl;
        cin >> b;
        if (b > 2) { break; }
        cout << endl;

        cout << "Macierz transponowana: " << endl;
        cout << endl;

        switch (b) {
        case 1:
            m1.transp();
            break;
        case 2:
            m2.transp();
            break;
        }
    }

    return 0;
}
