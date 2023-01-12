#include <iostream>
#include <set>

using namespace std;

class Set {

public:
    int n;
    double* tab;

    Set() {
        n = 0;
        tab = 0;
    }

    Set(int a) {
        n = a;
        tab = new double[n];
        for (int i = 0; i < n; i++) {
            tab[i] = rand() % 101;
        }
    }

    Set(double *ntab, int c) {
        n = c;
        tab = ntab;
    }

    Set(const Set& d) {
        n = d.n;
        tab = new double[n];
        for (int i = 0; i < n; i++) {
            tab[i] = d.tab[i];
        }
    }

    void print() {
        cout << "The number of elements in the set: " << endl;
        cout << n << endl;
        cout << endl;
        cout << "The numbers in the set: " << endl;
        for (int i = 0; i < n; i++) {
            cout << tab[i] << " ";
        }
        cout << endl;
    }

    ~Set() {
        if (tab != nullptr) {
            delete[] tab;
        }
    }

    Set& operator+=(const Set& c) {
        int newn = n + c.n;

        double* newtab = new double[newn];
        int j = 0;

        for (int i = 0; i < n; i++)
            newtab[j++] = tab[i];

        for (int i = 0; i < c.n; i++)
            newtab[j++] = c.tab[i];

        for (int i = 0; i < (newn - 1); i++) {
            for (int k = (i + 1); k < newn; k++) {
                if (newtab[i] == newtab[k]) {
                    for (int l = (i + 1); l < newn; l++) {
                        newtab[l - 1] = newtab[l];
                    }
                    newn--;
                }
            }
        }

        delete[] tab;

        n = newn;
        tab = newtab;

        return *this;
    }

    Set& operator-=(const Set& c) {
        int newn = n; 
        double* newtab = new double[newn];
        int j = 0;

        for (int i = 0; i < n; ++i)
            newtab[j++] = tab[i];

        for (int i = 0; i < newn; i++) {
            for (int k = 0; k < c.n; k++) {
                if (newtab[i] == c.tab[k]) {
                    for (int l = (i + 1); l < newn; l++) {
                        newtab[l - 1] = newtab[l];
                    }
                    newn--;
                }
            }
        }

        delete[] tab;

        n = newn;
        tab = newtab;

        return *this; 
    }

    Set& operator*=(const Set& c) {
        int newn = c.n;
        double* newtab = new double[newn];
        int j = 0, l = 0;

        for (int i = 0; i < n; ++i)
            newtab[j++] = tab[i];

        for (int i = 0; i < newn; i++) {
            for (int k = 0; k < c.n; k++) {
                if (newtab[i] == c.tab[k]) {
                    newtab[l++] = c.tab[i];
                }
                else {
                    newn--;
                }
            }
        }

        delete[] tab;

        n = newn;
        tab = newtab;

        return *this;
    }
};

Set operator+(const Set& c1, const Set& c2) {
    int newn = c1.n + c2.n;
    double* newtab = new double[newn];
    int j = 0;

    for (int i = 0; i < c1.n; ++i)
        newtab[j++] = c1.tab[i];

    for (int i = 0; i < c2.n; ++i)
        newtab[j++] = c2.tab[i];

    for (int i = 0; i < (newn - 1); i++) {
        for (int k = (i + 1); k < newn; k++) {
            if (newtab[i] == newtab[k]) {
                for (int l = (i + 1); l < newn; l++) {
                    newtab[l - 1] = newtab[l];
                }
                newn--;
            }
        }
    }

    Set sum(newtab, newn);

    return sum;
}

Set operator-(const Set& c1, const Set& c2) {
    int newn = c1.n;
    double* newtab = new double[newn];
    int j = 0;

    for (int i = 0; i < newn; ++i)
        newtab[j++] = c1.tab[i];

    for (int i = 0; i < newn; i++) {
        for (int k = 0; k < c2.n; k++) {
            if (newtab[i] == c2.tab[k]) {
                for (int l = (i + 1); l < newn; l++) {
                    newtab[l - 1] = newtab[l];
                }
                newn--;
            }
        }
    }

    Set diff(newtab, newn);

    return diff;
}

Set operator*(const Set& c1, const Set& c2) {
    int newn = c1.n;
    double* newtab = new double[newn];
    int j = 0, l = 0;

    for (int i = 0; i < c1.n; ++i)
        newtab[j++] = c1.tab[i];

    for (int i = 0; i < newn; i++) {
        for (int k = 0; k < c2.n; k++) {
            if (newtab[i] == c2.tab[k]) {
                newtab[l++] = c2.tab[i];
            }
            else {
                newn--;
            }
        }
    }

    Set equal(newtab, newn);

    return equal;
}

ostream& operator<<(ostream& os, const Set& set)
{
    for (int i = 0; i < set.n; ++i) {
        os << set.tab[i] << " ";
    }
    return os;
}

int main()
{
    int a;
    srand(time(NULL));

    a = rand() % 10 + 1;

    Set z1(a);
    z1.print();
    cout << endl;

    Set z2(a);
    z2.print();
    cout << endl;

    cout << "Sum of the sets: " << endl;
    cout << z1 + z2 << endl;
    cout << endl;

    cout << "Difference of the sets: " << endl;
    cout << z1 - z2 << endl;
    cout << endl;

    cout << "Intersection of the sets: " << endl;
    cout << z1 * z2;

    return 0;
}
