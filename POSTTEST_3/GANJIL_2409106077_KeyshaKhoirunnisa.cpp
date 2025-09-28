#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item *next;
    Item *prev;
};

Item *head = nullptr;
Item *tail = nullptr;

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
    nodeBaru->prev = nullptr;

    if (isEmpty()) {
        head = tail = nodeBaru;
    } else {
        nodeBaru->prev = tail;
        tail->next = nodeBaru;
        tail = nodeBaru;
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
        nodeBaru->prev = nullptr;
        nodeBaru->next = head;
        if (head) head->prev = nodeBaru;
        head = nodeBaru;
        if (!tail) tail = nodeBaru;
        return;
    }

    Item *temp = head;
    int hitung = 1;
    while (temp->next && hitung < pos - 1) {
        temp = temp->next;
        hitung++;
    }
    nodeBaru->next = temp->next;
    nodeBaru->prev = temp;
    if (temp->next) {
        temp->next->prev = nodeBaru;
    }
    else tail = nodeBaru;
    temp->next = nodeBaru;
}

void hapusItemTerakhir() {
    if (isEmpty()) {
        cout << "Yahh, Inventory masih kosong niehh :(\n";
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Item *del = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete del;
    }
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
    while (temp && temp->namaItem != target) {
        temp = temp->next;
    }
    if (!temp) { 
        cout << "Yahhh, Item tidak ditemukan niehh :(\n"; 
        return; 
    }

    temp->jumlah--;
    cout << "Item " << temp->namaItem << " digunakan. Sisa: "
         << temp->jumlah << endl;

    if (temp->jumlah <= 0) {
        cout << "Item habis, dihapus dari inventory :(\n";
        if (temp == head && temp == tail) {
            head = tail = nullptr;
        } else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
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
    while (temp) {
        cout << "Nama: " << temp->namaItem
             << " | Tipe: " << temp->tipe
             << " | Jumlah: " << temp->jumlah << endl;
        temp = temp->next;
    }
}

void tampilkanDariBelakang() {
    if (isEmpty()) {
        cout << "Yahh, inventory masih kosong niehh :(\n";
        return;
    }
    cout << "\n=== DAFTAR INVENTORY ===\n";
    Item *temp = tail;
    while (temp != nullptr) {
        cout << "Nama: " << temp->namaItem
             << " | Tipe: " << temp->tipe
             << " | Jumlah: " << temp->jumlah << endl;
        temp = temp->prev;
    }
}

void detailItem() {
    if (isEmpty()) {
        cout << "Yahh, inventory masih kosong niehh :(\n";
        return;
    }
    string key;
    cout << "Masukkan nama item yang ingin dilihat detailnya: ";
    cin.ignore(); 
    getline(cin, key);

    Item *temp = head;
    while (temp && temp->namaItem != key) {
        temp = temp->next;
    }
    if (!temp) { 
        cout << "Yahhh, Item tidak ditemukan niehh :(\n"; 
        return; 
    }else {
        cout << "\n=== DETAIL ITEM ===\n";
        cout << "Nama: " << temp->namaItem << endl;
        cout << "Tipe: " << temp->tipe << endl;
        cout << "Jumlah: " << temp->jumlah << endl;
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
        cout << "| 5. Tampilkan Inventory (depan)                  |\n";
        cout << "| 6. Tampilkan Inventory (belakang)               |\n";
        cout << "| 7. Detail Item (by Nama)                        |\n";
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
            case 6: tampilkanDariBelakang(); 
            break; 
            case 7: detailItem(); 
            break;
            case 0: cout << "Terima kasih ;), Jumpa lagiii\n"; 
            break;
            default: cout << "Yahh, menu tidak valid niehh :(\n";
        }
    } while (pilih != 0);

    while (!isEmpty()) hapusItemTerakhir();
    return 0;
}