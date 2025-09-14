#include <iostream>
using namespace std;

int tukar(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
    return 1;
}

int main() {
    int x, y;
    cout << "Masukkan bilangan pertama: ";
    cin >> x; cout << endl;
    cout << "Masukkan bilangan kedua: ";
    cin >> y;

    cout << "\nSebelum tukar: x = " << x << " y = " << y << endl;

    int *px = &x, *py = &y;
    tukar(&px, &py);

    cout << "Sesudah tukar: x = " << x << " y = " << y << endl;
}
