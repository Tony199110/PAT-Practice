# include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b;
    c = a + b;
    int format_output[8];
    int flag = 0, length = 0, i = 0;
    if (c < 0) { flag = 1; c = -1 * c; }
    while (c != 0) {
        format_output[i] = c % 10;
        c /= 10;
        length++;
        i++;
    }
    if (flag == 1) cout << "-";
    int flag2 = 0;
    if (length == 0) {
        cout << "0";
    }
    for (i = length - 1; i >= 0; i--) {
        if ((length - flag2) % 3 == 0 && i != length - 1) cout << ",";
        cout << format_output[i];
        flag2++;
    }
    return 0;
}