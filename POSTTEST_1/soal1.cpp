#include <iostream>
using namespace std;

int* balikArray(int *arr, int n) {
    for (int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
    return arr;
}

int main() {
    const int N = 7;
    int arr[N];

    for (int i = 0; i < N; i++) {
        arr[i] = (i+1) * 3;
    }

    cout << "Array sebelum dibalik: " << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
        
    int *hasil = balikArray(arr, N);
    cout << endl;
    
    cout << "Array sesudah dibalik: " << endl;
    for (int i = 0; i < N; i++) {
        cout << hasil[i] << " ";
    }
        
}
