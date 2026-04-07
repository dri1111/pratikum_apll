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

void prosedurLogin(string *nama, string *nim, int *coba, bool *statusLogin, User *user) {
    cout << "=== LOGIN DULU ===\n";
    cout << "Nama : ";
    cin >> *nama;
    cout << "NIM  : ";
    cin >> *nim;

    if (*nama == user->nama && *nim == user->nim) {
        cout << "Login berhasil\n";
        *statusLogin = true;
    } else {
        cout << "Login salah\n";
        (*coba)++;
        cout << "Sisa percobaan: " << 3 - *coba << endl;
        *statusLogin = false;
    }
}

bool cekBatasPercobaan(int *coba) {
    return (*coba >= 3);
}

bool cekArrayPenuh(int *jumlah) {
    return (*jumlah >= 10);
}

bool cekArrayKosong(int *jumlah) {
    return (*jumlah == 0);
}

bool validasiNomor(int nomor, int *jumlah) {
    return (nomor >= 1 && nomor <= *jumlah);
}

void tambahZat(Zat *data, int *jumlah) {
    cout << "\n=== TAMBAH DATA ZAT ===\n";
    if (!cekArrayPenuh(jumlah)) {
        cout << "Nama Atom  : ";
        cin >> (data[*jumlah].namaAtom);
        cout << "Simbol     : ";
        cin >> (data[*jumlah].simbol);
        cout << "Massa Atom : ";
        cin >> (data[*jumlah].massaAtom);

        (*jumlah)++;
        cout << "Data berhasil ditambahkan!\n";
    } else {
        cout << "Data penuh!\n";
    }
}

void lihatZat(Zat *data, int *jumlah) {
    cout << "\n=== LIHAT DATA ZAT ===\n";
    if (!cekArrayKosong(jumlah)) {
        for (int i = 0; i < *jumlah; i++) {
            cout << i+1 << ". "
                 << data[i].namaAtom << " | "
                 << data[i].simbol << " | "
                 << data[i].massaAtom << endl;
        }
    } else {
        cout << "Data kosong!\n";
    }
}

void ubahZat(Zat *data, int *jumlah) {
    if (!cekArrayKosong(jumlah)) {
        int n;
        lihatZat(data, jumlah);

        cout << "Pilih nomor: ";
        cin >> n;

        if (validasiNomor(n, jumlah)) {
            cout << "Nama baru: ";
            cin >> data[n-1].namaAtom;
            cout << "Simbol baru: ";
            cin >> data[n-1].simbol;
            cout << "Massa baru: ";
            cin >> data[n-1].massaAtom;
        } else {
            cout << "Tidak valid\n";
        }
    }
}

void hapusZat(Zat *data, int *jumlah) {
    if (!cekArrayKosong(jumlah)) {
        int n;
        lihatZat(data, jumlah);

        cout << "Pilih nomor: ";
        cin >> n;

        if (validasiNomor(n, jumlah)) {
            for (int i = n-1; i < *jumlah-1; i++) {
                data[i] = data[i+1];
            }
            (*jumlah)--;
            cout << "Data dihapus\n";
        }
    }
}

int tampilkanMenu() {
    int pilih;
    cout << "\n1. Tambah\n2. Lihat\n3. Ubah\n4. Hapus\n5. Keluar\n";
    cout << "Pilih: ";
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
        prosedurLogin(&nama, &nim, &coba, &statusLogin, &user);

        if (cekBatasPercobaan(&coba)) {
            cout << "Gagal 3x, program berhenti\n";
            return 0;
        }
    } while (!statusLogin);

    int pilih;
    do {
        pilih = tampilkanMenu();

        switch (pilih) {
            case 1: tambahZat(data, &jumlah); break;
            case 2: lihatZat(data, &jumlah); break;
            case 3: ubahZat(data, &jumlah); break;
            case 4: hapusZat(data, &jumlah); break;
        }
    } while (pilih != 5);

    return 0;
}
