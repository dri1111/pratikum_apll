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

void prosedurLogin(string &nama, string &nim, int &coba, bool &statusLogin, User &user) {
    cout << "=== LOGIN DULU ===\n";
    cout << "Nama : ";
    cin >> nama;
    cout << "NIM  : ";
    cin >> nim;

    if (nama == user.nama && nim == user.nim) {
        cout << "Login berhasil\n";
        statusLogin = true;
    } else {
        cout << "Login salah\n";
        coba++;
        cout << "Sisa percobaan: " << 3 - coba << endl;
        statusLogin = false;
    }
}

bool cekBatasPercobaan(int &coba) {
    return (coba >= 3);
}

bool cekArrayPenuh(int &jumlah) {
    return (jumlah >= 10);
}

bool cekArrayKosong(int &jumlah) {
    return (jumlah == 0);
}

bool validasiNomor(int nomor, int &jumlah) {
    return (nomor >= 1 && nomor <= jumlah);
}

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
    }
    else {
        cout << "Data penuh!\n";
    }
}

void lihatZat(Zat data[], int &jumlah) {

    cout << "\n=== LIHAT DATA ZAT ===\n";

    if (!cekArrayKosong(jumlah)) {

        for (int i=0;i<jumlah;i++) {

            cout << i+1 << ". "
                 << data[i].namaAtom << " | "
                 << data[i].simbol << " | "
                 << data[i].massaAtom << endl;
        }

    } else {

        cout << "Data kosong!\n";
    }
}

void ubahZat(Zat data[], int &jumlah) {

    if (!cekArrayKosong(jumlah)) {

        int n;

        lihatZat(data,jumlah);

        cout<<"Pilih nomor: ";
        cin>>n;

        if (validasiNomor(n,jumlah)) {

            cout<<"Nama baru   : ";
            cin>>data[n-1].namaAtom;

            cout<<"Simbol baru : ";
            cin>>data[n-1].simbol;

            cout<<"Massa baru  : ";
            cin>>data[n-1].massaAtom;

            cout<<"Data berhasil diubah!\n";
        }

        else {
            cout<<"Tidak valid\n";
        }

    } else {
        cout<<"Data kosong!\n";
    }
}

void hapusZat(Zat data[], int &jumlah) {

    if (!cekArrayKosong(jumlah)) {

        int n;

        lihatZat(data,jumlah);

        cout<<"Pilih nomor: ";
        cin>>n;

        if(validasiNomor(n,jumlah)) {

            for(int i=n-1;i<jumlah-1;i++) {
                data[i]=data[i+1];
            }

            jumlah--;

            cout<<"Data berhasil dihapus\n";
        }

        else {
            cout<<"Tidak valid\n";
        }

    } else {
        cout<<"Data kosong!\n";
    }
}

void sortNamaDescending(Zat data[], int &jumlah) {

    for(int i=0;i<jumlah-1;i++) {
        for(int j=0;j<jumlah-i-1;j++) {

            if(data[j].namaAtom < data[j+1].namaAtom) {
                swap(data[j],data[j+1]);
            }
        }
    }

    cout<<"Sorting nama Descending berhasil!\n";
    lihatZat(data,jumlah);
}

void sortMassaAscending(Zat data[], int &jumlah) {

    for(int i=0;i<jumlah-1;i++) {
        for(int j=0;j<jumlah-i-1;j++) {

            if(data[j].massaAtom > data[j+1].massaAtom) {
                swap(data[j],data[j+1]);
            }
        }
    }

    cout<<"Sorting massa Ascending berhasil!\n";
    lihatZat(data,jumlah);
}

void sortSimbolAscending(Zat data[], int &jumlah) {

    for(int i=0;i<jumlah-1;i++) {
        for(int j=0;j<jumlah-i-1;j++) {

            if(data[j].simbol > data[j+1].simbol) {
                swap(data[j],data[j+1]);
            }
        }
    }

    cout<<"Sorting simbol Ascending berhasil!\n";
    lihatZat(data,jumlah);
}

void cariNamaLinear(Zat data[], int &jumlah) {

    if(jumlah==0){
        cout<<"Data kosong!\n";
        return;
    }

    string cari;
    bool ketemu=false;

    cout<<"Masukkan nama atom yang dicari: ";
    cin>>cari;

    for(int i=0;i<jumlah;i++){

        if(data[i].namaAtom==cari){

            cout<<"\nData ditemukan:\n";
            cout<<data[i].namaAtom<<" | "
                <<data[i].simbol<<" | "
                <<data[i].massaAtom<<endl;

            ketemu=true;
            break;
        }
    }

    if(!ketemu)
        cout<<"Data tidak ditemukan.\n";
}

void cariMassaInterpolation(Zat data[], int &jumlah){

    if(jumlah==0){
        cout<<"Data kosong!\n";
        return;
    }

    float target;

    cout<<"Masukkan massa atom yang dicari: ";
    cin>>target;

    sortMassaAscending(data,jumlah);

    int low=0;
    int high=jumlah-1;

    while(low<=high &&
          target>=data[low].massaAtom &&
          target<=data[high].massaAtom){

        if(data[high].massaAtom==data[low].massaAtom){

            if(data[low].massaAtom==target){

                cout<<"\nData ditemukan:\n";

                cout<<data[low].namaAtom<<" | "
                    <<data[low].simbol<<" | "
                    <<data[low].massaAtom<<endl;
            }

            else{
                cout<<"Data tidak ditemukan.\n";
            }

            return;
        }

        int pos = low +
                 ((target-data[low].massaAtom)
                 *(high-low)
                 /(data[high].massaAtom-data[low].massaAtom));

        if(data[pos].massaAtom==target){

            cout<<"\nData ditemukan:\n";

            cout<<data[pos].namaAtom<<" | "
                <<data[pos].simbol<<" | "
                <<data[pos].massaAtom<<endl;

            return;
        }

        if(data[pos].massaAtom < target)
            low=pos+1;
        else
            high=pos-1;
    }

    cout<<"Data tidak ditemukan.\n";
}


int tampilkanMenu(){

    int pilih;

    cout<<"\n===== MENU =====\n";
    cout<<"1. Tambah\n";
    cout<<"2. Lihat\n";
    cout<<"3. Ubah\n";
    cout<<"4. Hapus\n";
    cout<<"5. Sort Nama Desc\n";
    cout<<"6. Sort Massa Asc\n";
    cout<<"7. Sort Simbol Asc\n";
    cout<<"8. Cari Nama (Linear Search)\n";
    cout<<"9. Cari Massa (Interpolation Search)\n";
    cout<<"10. Keluar\n";

    cout<<"Pilih: ";
    cin>>pilih;

    return pilih;
}


int main(){

    User user={"adri","110"};

    Zat data[10];

    int jumlah=0;

    string nama,nim;

    int coba=0;

    bool statusLogin=false;

    do{

        prosedurLogin(
            nama,
            nim,
            coba,
            statusLogin,
            user
        );

        if(cekBatasPercobaan(coba)){
            cout<<"Gagal 3x, program berhenti\n";
            return 0;
        }

    }
    while(!statusLogin);


    int pilih;

    do{

        pilih=tampilkanMenu();

        switch(pilih){

            case 1:
                tambahZat(data,jumlah);
                break;

            case 2:
                lihatZat(data,jumlah);
                break;

            case 3:
                ubahZat(data,jumlah);
                break;

            case 4:
                hapusZat(data,jumlah);
                break;

            case 5:
                sortNamaDescending(data,jumlah);
                break;

            case 6:
                sortMassaAscending(data,jumlah);
                break;

            case 7:
                sortSimbolAscending(data,jumlah);
                break;

            case 8:
                cariNamaLinear(data,jumlah);
                break;

            case 9:
                cariMassaInterpolation(data,jumlah);
                break;
        }

    }
    while(pilih!=10);

    cout<<"Program selesai.\n";

    return 0;
}