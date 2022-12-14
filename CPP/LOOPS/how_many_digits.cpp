// Programme will show how many digits are divisible by 3 and non-divisible by 7 in range 0-50, 50-100 and 100-150

#include <iostream>

using namespace std;

int howmany(int a, int b) {
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

void show(int a, int b) {
    cout << "From "<< a+1 << " to "<< b << " there are "<< howmany(a,b)<< " digits" << endl;
}

int main()
{
    for (int i = 0; i < 3; i++) {
        show(i * 50, (i + 1) * 50);
    }
    return 0;
}
