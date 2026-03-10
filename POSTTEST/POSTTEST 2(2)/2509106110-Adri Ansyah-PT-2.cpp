#include <iostream>
using namespace std;

struct User {
    string nama;
    string nim;
};

struct Zat {
    string namaAtom;
    string simbol;
    float massaAtom;
};

User user = {"adri", "110"}; 
Zat data[10];
int jumlah = 0;

int main() {

    string nama, nim;
    int coba = 0;

    while (coba < 3) {
        cout << "=== LOGIN DULU ===\n";
        cout << "Nama : ";
        cin >> nama;
        cout << "NIM  : ";
        cin >> nim;

        if (nama == user.nama && nim == user.nim) {
            cout << "Login telah berhasil\n";
            break;
        } else {
            cout << "Loginnya salah\n";
            coba++;
        }

        if (coba == 3) {
            cout << "Gagal sudah login 3 kali\n";
            return 0;
        }
    }

    int pilih;

    do {
        cout << "\n=== ZAT KIMIA ===\n";
        cout << "1. Tambah Zat\n";
        cout << "2. Lihat Zat\n";
        cout << "3. Ubah Zat\n";
        cout << "4. Hapus Zat\n";
        cout << "5. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;


        if (pilih == 1) {
            cout << "Nama Atom  : ";
            cin >> data[jumlah].namaAtom;
            cout << "Simbol     : ";
            cin >> data[jumlah].simbol;
            cout << "Massa Atom : ";
            cin >> data[jumlah].massaAtom;

            jumlah++;
            cout << "Data Tersimpan";
        }


        else if (pilih == 2) {
            cout << "\nData Zat Kimia\n";
            for (int i = 0; i < jumlah; i++) {
                cout << i+1 << ". "
                     << data[i].namaAtom << " | "
                     << data[i].simbol << " | "
                     << data[i].massaAtom << endl;
            }
        }

        else if (pilih == 3) {
            int n;
            cout << "Ubah Zat : ";
            cin >> n;

            cout << "Nama Atom baru  : ";
            cin >> data[n-1].namaAtom;
            cout << "Simbol baru     : ";
            cin >> data[n-1].simbol;
            cout << "Massa Atom baru : ";
            cin >> data[n-1].massaAtom;
        }

        
        else if (pilih == 4) {
            int n;
            cout << "Hapus Zat : ";
            cin >> n;

            for (int i = n-1; i < jumlah-1; i++) {
                data[i] = data[i+1];
            }

            jumlah--;
        }

    } while (pilih != 5);

}