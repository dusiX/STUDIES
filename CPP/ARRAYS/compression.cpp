//Programme loads text and makes compression of the text or loads text and makes decompression of the text

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 3) {
        int i, count = 0, repeat = 0;
        char c, c1, d, sum;
        string str(argv[2]);
        cout << str << endl;
        char output[1000];
        bool war = false;

        if (argv[1][0] == 'c') {
            c = str[0];
            for (i = 1; i < str.length(); i++) {
                c1 = str[i];
                if (c == c1) {
                    repeat++;
                    if (i == (str.length() - 1)) {
                        output[count++] = '[';
                        output[count++] = 49 + repeat;
                        output[count++] = c;
                        output[count++] = ']';
                        war = true;
                    }
                }
                else {
                    if (repeat == 0) {
                        output[count++] = c;
                    }
                    else {
                        output[count++] = '[';
                        output[count++] = 49 + repeat;
                        output[count++] = c;
                        output[count++] = ']';
                        repeat = 0;
                    }
                }
                c = c1;
            }
            if (!war) {
                output[count++] = c;
            }
            output[count] = '\0';
            string s(output);
            cout << s;
        }

        if (argv[1][0] == 'd') {
            for (i = 0; i < str.length(); i++) {
                d = str[i];
                if (str[i] == '[') {
                    i++;
                    sum = (str[i++] - 48);
                    d = str[i];
                    for (int j = 1; j <= sum; j++) {
                        output[count++] = d;
                    }
                    i++;
                }
                else {
                    output[count++] = d;
                }
            }
            output[count] = '\0';
            string s(output);
            cout << s;
        }
    }
    return 0;
}
