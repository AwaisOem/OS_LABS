#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define frame 3

int main() {
    string s;
    int array[100], proc[4], buffer, i, len, count, fault = 0, j, k, temp;
    char cha[5];

    cout << "NO OF FRAMES = 3" << endl;
    cout << "ENTER STRING for the sequence of pages" << endl;
    getline(cin, s);

    len = s.length();

    // making ints of string
    for (i = 0; i < len; i++) {
        cha[0] = s[i];
        array[i] = cha[0] - '0';
        cout << array[i] << " ";
        memset(cha, 0, sizeof(cha));
    }

    cout << endl;

    count = -1;

    // processing
    for (i = 0; i < len; i++) {
        if (count < 2) {
            count++;
            proc[count] = array[i];
            fault++;
        } else {
            for (j = 0; j <= count; j++) {
                if (array[i] == proc[j]) {
                    break;
                }
            }

            if (j > 2) { // page is not in ram
                if (buffer != -1) {
                    if (array[i] != buffer)
                        fault++;
                }

                buffer = proc[0];
                for (k = 0; k < 2; k++) {
                    proc[k] = proc[k + 1];
                }

                proc[2] = array[i];
            }
        } // else
    }

    cout << "\nNo of faults= " << fault << endl << endl;

    return 0;
}
