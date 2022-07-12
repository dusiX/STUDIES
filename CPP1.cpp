#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 3) {
        int i, licz = 0, powt = 0;
        char c, c1, d, ile;
        string str(argv[2]);
        cout << str << endl;
        char output[1000];
        bool war = false;

        if (argv[1][0] == 'c') {
            c = str[0];
            for (i = 1; i < str.length(); i++) {
                c1 = str[i];
                if (c == c1) {
                    powt++;
                    if (i == (str.length() - 1)) {
                        output[licz++] = '[';
                        output[licz++] = 49 + powt;
                        output[licz++] = c;
                        output[licz++] = ']';
                        war = true;
                    }
                }
                else {
                    if (powt == 0) {
                        output[licz++] = c;
                    }
                    else {
                        output[licz++] = '[';
                        output[licz++] = 49 + powt;
                        output[licz++] = c;
                        output[licz++] = ']';
                        powt = 0;
                    }
                }
                c = c1;
            }
            if (!war) {
                output[licz++] = c;
            }
            output[licz] = '\0';
            string s(output);
            cout << s;
        }

        if (argv[1][0] == 'd') {
            for (i = 0; i < str.length(); i++) {
                d = str[i];
                if (str[i] == '[') {
                    i++;
                    ile = (str[i++] - 48);
                    d = str[i];
                    for (int j = 1; j <= ile; j++) {
                        output[licz++] = d;
                    }
                    i++;
                }
                else {
                    output[licz++] = d;
                }
            }
            output[licz] = '\0';
            string s(output);
            cout << s;
        }
    }
    return 0;
}