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

void prosedurLogin(string &nama, string &nim, int &coba, bool &statusLogin, User user) {
    cout << "=== LOGIN DULU ===\n";
    cout << "Nama : ";
    cin >> nama;
    cout << "NIM  : ";
    cin >> nim;
    
    if (nama == user.nama && nim == user.nim) {
        cout << "Login telah berhasil\n";
        statusLogin = true;
    } else {
        cout << "Loginnya salah\n";
        coba++;
        cout << "Sisa percobaan: " << 3 - coba << endl;
        statusLogin = false;
    }
}
bool cekLogin(string nama, string nim, User user) {
    return (nama == user.nama && nim == user.nim);
}

bool cekBatasPercobaan(int coba) {
    return (coba >= 3);
}

bool cekArrayPenuh(int jumlah) {
    return (jumlah >= 10);
}

bool cekArrayKosong(int jumlah) {
    return (jumlah == 0);
}

bool validasiNomor(int nomor, int jumlah) {
    return (nomor >= 1 && nomor <= jumlah);
}

// PROSEDUR untuk menambah data zat
void tambahZat(Zat data[], int &jumlah) {
    cout << "\n=== TAMBAH DATA ZAT ===\n";
    if (!cekArrayPenuh(jumlah)) {
        cout << "Nama Atom  : ";
        cin >> data[jumlah].namaAtom;
        cout << "Simbol     : ";
        cin >> data[jumlah].simbol;
        cout << "Massa Atom : ";
        cin >> data[jumlah].massaAtom;
        
        jumlah++;
        cout << "Data berhasil ditambahkan!\n";
    } else {
        cout << "Data sudah penuh (maksimal 10)!\n";
    }
}

void lihatZat(Zat data[], int jumlah) {
    cout << "\n=== LIHAT DATA ZAT ===\n";
    if (!cekArrayKosong(jumlah)) {
        cout << "No | Nama Atom | Simbol | Massa Atom\n";
        cout << "------------------------------------\n";
        for (int i = 0; i < jumlah; i++) {
            cout << i+1 << ".  "
                 << data[i].namaAtom << "      "
                 << data[i].simbol << "       "
                 << data[i].massaAtom << endl;
        }
    } else {
        cout << "Belum ada data zat kimia!\n";
    }
}

void ubahZat(Zat data[], int jumlah) {
    cout << "\n=== UBAH DATA ZAT ===\n";
    if (!cekArrayKosong(jumlah)) {
        int n;
        lihatZat(data, jumlah);
        cout << "\nPilih nomor zat yang akan diubah (1-" << jumlah << "): ";
        cin >> n;
        
        if (validasiNomor(n, jumlah)) {
            cout << "\nMasukkan data baru:\n";
            cout << "Nama Atom baru  : ";
            cin >> data[n-1].namaAtom;
            cout << "Simbol baru     : ";
            cin >> data[n-1].simbol;
            cout << "Massa Atom baru : ";
            cin >> data[n-1].massaAtom;
            cout << "Data berhasil diubah!\n";
        } else {
            cout << "Nomor tidak valid!\n";
        }
    } else {
        cout << "Belum ada data!\n";
    }
}

void hapusZat(Zat data[], int &jumlah) {
    cout << "\n=== HAPUS DATA ZAT ===\n";
    if (!cekArrayKosong(jumlah)) {
        int n;
        lihatZat(data, jumlah);
        cout << "\nPilih nomor zat yang akan dihapus (1-" << jumlah << "): ";
        cin >> n;
        
        if (validasiNomor(n, jumlah)) {
            for (int i = n-1; i < jumlah-1; i++) {
                data[i] = data[i+1];
            }
            jumlah--;
            cout << "Data berhasil dihapus!\n";
        } else {
            cout << "Nomor tidak valid!\n";
        }
    } else {
        cout << "Belum ada data!\n";
    }
}

int tampilkanMenu() {
    int pilih;
    cout << "\n=== MENU ZAT KIMIA ===\n";
    cout << "1. Tambah Zat\n";
    cout << "2. Lihat Zat\n";
    cout << "3. Ubah Zat\n";
    cout << "4. Hapus Zat\n";
    cout << "5. Keluar\n";
    cout << "Pilih (1-5): ";
    cin >> pilih;
    return pilih;
}

int main() {

    User user = {"adri", "110"};
    
    Zat data[10];
    int jumlah = 0;
    
    string nama, nim;
    int coba = 0;
    bool statusLogin = false;
    
    do {
        prosedurLogin(nama, nim, coba, statusLogin, user);
        
        if (cekBatasPercobaan(coba)) {
            cout << "\nAnda telah gagal login 3 kali. Program berhenti.\n";
            return 0;
        }
    } while (!statusLogin);
    
    int pilih;
    do {
        pilih = tampilkanMenu();
        
        if (pilih == 1) {
            tambahZat(data, jumlah);
        } 
        else if (pilih == 2) {
            lihatZat(data, jumlah);
        } 
        else if (pilih == 3) {
            ubahZat(data, jumlah);
        } 
        else if (pilih == 4) {
            hapusZat(data, jumlah);
        } 
        else if (pilih == 5) {
            cout << "\nTerima kasih telah menggunakan program ini!\n";
        } 
        else {
            cout << "\nPilihan tidak valid! Silakan pilih 1-5.\n";
        }
        
    } while (pilih != 5);
    
    return 0;
}
