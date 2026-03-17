#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double m[3][3];

    cout << "Введіть елементи матриці 3x3:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cout << "m[" << i << "][" << j << "] = ";
            cin >> m[i][j];
        }

    double prod = 1;
    bool hasNeg = false;
    for (int i = 1; i < 3; i += 2) {
        for (int j = 0; j < 3; j++) {
            if (m[i][j] < 0) {
                prod *= m[i][j];
                hasNeg = true;
            }
        }
    }

    if (hasNeg)
        cout << "Добуток від’ємних у парних рядках = " << prod << endl;
    else
        cout << "В парних рядках немає від’ємних елементів.\n";

    double a[9];
    int k = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[k++] = m[i][j];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8 - i; j++) {
            if (j % 2 == 0 && a[j] > a[j + 1]) swap(a[j], a[j + 1]);
            if (j % 2 != 0 && a[j] < a[j + 1]) swap(a[j], a[j + 1]);
        }

    cout << "\nВідсортована матриця:\n";
    for (int i = 0; i < 9; i++) {
        cout << a[i] << "\t";
        if ((i + 1) % 3 == 0) cout << endl;
    }
    system("pause"); 
    return 0;
}