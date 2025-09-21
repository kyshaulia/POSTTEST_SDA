#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item *next;
};

Item *head = nullptr;

const string NIM  = "2409106077";
const string NAMA = "Keysha Khoirunnisa";
int duaDigitAkhir() {
    return stoi(NIM.substr(NIM.size()-2));
}
int posisiSisip() {
    int digitAkhir = (NIM.back() - '0');
    return (digitAkhir == 0) ? 2 : digitAkhir + 1;
}
bool isEmpty() {
    return head == nullptr;
}

void tambahItemBaru() {
    Item *nodeBaru = new Item;
    cout << "Nama Item  : "; 
    cin.ignore(); 
    getline(cin, nodeBaru->namaItem);
    cout << "Tipe Item  : "; 
    getline(cin, nodeBaru->tipe);
    nodeBaru->jumlah = duaDigitAkhir();
    nodeBaru->next = nullptr;

    if (isEmpty()) head = nodeBaru;
    else {
        Item *temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = nodeBaru;
    }
    cout << "Yashhh, Item berhasil ditambahkan dengan jumlah awal "
         << nodeBaru->jumlah << " ;)" << endl;
}

void sisipItem() {
    int pos = posisiSisip();
    cout << "Posisi sisip otomatis: " << pos << endl;

    Item *nodeBaru = new Item;
    cout << "Nama Item  : "; 
    cin.ignore(); 
    getline(cin, nodeBaru->namaItem);
    cout << "Tipe Item  : "; 
    getline(cin, nodeBaru->tipe);
    nodeBaru->jumlah = duaDigitAkhir();

    if (pos <= 1 || isEmpty()) {
        nodeBaru->next = head;
        head = nodeBaru;
        return;
    }

    Item *temp = head;
    int hitung = 1;
    while (temp->next != nullptr && hitung < pos - 1) {
        temp = temp->next;
        hitung++;
    }
    nodeBaru->next = temp->next;
    temp->next = nodeBaru;
}

void hapusItemTerakhir() {
    if (isEmpty()) {
        cout << "Yahh, Inventory masih kosong niehh :(\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Yahh, item terakhir dihapus :(\n";
        return;
    }
    Item *temp = head;
    while (temp->next->next != nullptr) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    cout << "Yahh, item terakhir dihapus :(\n";
}

void gunakanItem() {
    if (isEmpty()) { 
        cout << "Yahh, inventory masih kosong niehh :(\n"; 
        return; 
    }
    string target;
    cout << "Masukkan nama item yang ingin digunakan: ";
    cin.ignore(); 
    getline(cin, target);

    Item *temp = head;
    Item *prev = nullptr;
    while (temp != nullptr && temp->namaItem != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Noo, Item tidak ditemukan :(\n";
        return;
    }

    temp->jumlah--;
    cout << "Item " << temp->namaItem << " digunakan. Sisa: "
         << temp->jumlah << endl;

    if (temp->jumlah <= 0) {
        cout << "Yahh, Item dihapus dari inventory :(\n";
        if (prev == nullptr) head = temp->next;
        else prev->next = temp->next;
        delete temp;
    }
}

void tampilkanInventory() {
    if (isEmpty()) {
        cout << "Yahh, inventory masih kosong niehh :(\n";
        return;
    }
    cout << "\n=== DAFTAR INVENTORY ===\n";
    Item *temp = head;
    while (temp != nullptr) {
        cout << "Nama: " << temp->namaItem
             << " | Tipe: " << temp->tipe
             << " | Jumlah: " << temp->jumlah << endl;
        temp = temp->next;
    }
}

int main() {
    int pilih;
    do {
        cout << "\n+-------------------------------------------------+\n";
        cout << "|            GAME INVENTORY MANAGEMENT            |\n";
        cout << "|     [ " << NAMA << " | NIM: " << NIM <<" ]    |\n";
        cout << "+-------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                             |\n";
        cout << "| 2. Sisipkan Item                                |\n";
        cout << "| 3. Hapus Item Terakhir                          |\n";
        cout << "| 4. Gunakan Item                                 |\n";
        cout << "| 5. Tampilkan Inventory                          |\n";
        cout << "| 0. Keluar                                       |\n";
        cout << "+-------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tambahItemBaru(); 
            break;
            case 2: sisipItem(); 
            break;
            case 3: hapusItemTerakhir(); 
            break;
            case 4: gunakanItem(); 
            break;
            case 5: tampilkanInventory(); 
            break;
            case 0: cout << "Terima kasih ;), Jumpa lagiii\n"; 
            break;
            default: cout << "Yahh, menu tidak valid niehh :(\n";
        }
    } while (pilih != 0);

    while (!isEmpty()) hapusItemTerakhir();
    return 0;
}