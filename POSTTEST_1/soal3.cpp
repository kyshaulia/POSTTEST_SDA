#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int cariIPKTertinggi(Mahasiswa m[], int N) {
    int index = 0;
    for (int i = 1; i < N; i++) {
        if (m[i].ipk > m[index].ipk) index = i;
    }
    return index;
}

int main() {
    const int N = 5;
    Mahasiswa m[N];

    cout << "Input data mahasiswa:\n";
    for (int i = 0; i < N; i++) {
        cin.ignore();
        cout << "Nama: "; 
        getline(cin, m[i].nama);
        cout << "NIM : "; 
        cin >> m[i].nim;
        cout << "IPK : "; 
        cin >> m[i].ipk;
        cout << endl;
    }

    int index = cariIPKTertinggi(m, N);

    cout << "Mahasiswa dengan IPK tertinggi:\n";
    cout << "Nama: " << m[index].nama << endl;
    cout << "NIM : " << m[index].nim << endl;
    cout << "IPK : " << m[index].ipk << endl;
}
