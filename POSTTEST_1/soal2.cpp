#include <iostream>
using namespace std;

int hitungDiagonal(int m[3][3], int N) {
    int jumlah = 0;
    for (int i = 0; i < N; i++) {
        jumlah += m[i][i]; 
        jumlah += m[i][N-1-i]; 
    }
    if (N % 2 == 1) jumlah -= m[N/2][N/2];
    return jumlah;
}

int main() {
    const int N = 3;
    int m[N][N] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << "Matriks:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    int hasil = hitungDiagonal(m, N);
    cout << "diagonal utama + diagonal sekunder = " << hasil << endl;
}