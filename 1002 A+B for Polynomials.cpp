# include <iostream>
# include<iomanip>
using namespace std;
int main() {
    float arr_A[1001] = { 0 }, arr_B[1001] = { 0 }, arr_C[1001] = { 0 };
    int length_A, length_B;
    int exp;
    float coe;
    cin >> length_A;
    for (int i = 0; i < length_A; i++) {
        cin >> exp >> coe;
        arr_A[exp] = coe;
    }
    cin >> length_B;
    for (int i = 0; i < length_B; i++) {
        cin >> exp >> coe;
        arr_B[exp] = coe;
    }
    int K = 0;
    for (int i = 0; i < 1001; i++) {
        arr_C[i] = arr_A[i] + arr_B[i];
        if (arr_C[i] != 0) K++;
    }
    cout << K;
    for (int i = 1000; i >= 0; i--) {
        if (arr_C[i] != 0) {
            cout << " " << i << " " << fixed << setprecision(1) << arr_C[i];
        }
    }
    return 0;
}