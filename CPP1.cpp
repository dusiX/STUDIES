#include <iostream>

using namespace std;

int ileliczb(int a, int b) {
    int i, j = 0;

    for (i = a+1; i <= b; i++) {
        if (i % 3 == 0) {
            if (i % 7 != 0) {
                j++;
            }
        }
    }

    return j;
}

void pokaz(int a, int b) {
    cout << "Od "<< a+1 << " do "<< b << " jest "<< ileliczb(a,b)<< " liczb" << endl;
}

int main()
{
    for (int i = 0; i < 3; i++) {
        pokaz(i * 50, (i + 1) * 50);
    }
    return 0;
}