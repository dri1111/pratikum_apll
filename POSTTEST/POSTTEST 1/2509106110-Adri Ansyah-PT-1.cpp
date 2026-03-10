#include <iostream>
using namespace std;

int main() {
	cout << "===== Buat Akun =====" << endl;
    string nama, password;
    string nama_benar = "Adri";      
    string password_benar = "110";
    cout << "data tersimpan" << endl;
    int percobaan = 0;
    int pilihan;
    
    while (percobaan < 3) {
        cout << "===== LOGIN =====" << endl;
        cout << "Masukkan Nama     : ";
        cin >> nama;		
        cout << "Masukkan Password: ";
        cin >> password;

        if (nama == nama_benar && password == password_benar) {
            cout << "Login Berhasil!\n" << endl;
            break;
        } else {
            cout << "Nama atau Password salah!\n" << endl;
            percobaan++;
        }
    }

    if (percobaan == 3) {
        cout << "salah 3 kali tuh. Program berhenti." << endl;
        return 0;
    }

    do {
        cout << "===== MENU KONVERSI WAKTU =====" << endl;
        cout << "1. Jam ke Menit dan Detik" << endl;
        cout << "2. Menit ke Jam dan Detik" << endl;
        cout << "3. Detik ke Jam dan Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        if (pilihan == 1) {
            int jam;
            cout << "Masukkan jumlah jam: ";
            cin >> jam;
            cout << jam << " Jam = " 
                 << jam * 60 << " Menit dan "
                 << jam * 3600 << " Detik\n" << endl;
        }
        else if (pilihan == 2) {
            int menit;
            cout << "Masukkan jumlah menit: ";
            cin >> menit;
            cout << menit << " Menit = "
                 << menit / 60 << " Jam dan "
                 << menit * 60 << " Detik\n" << endl;
        }
        else if (pilihan == 3) {
            int detik;
            cout << "Masukkan jumlah detik: ";
            cin >> detik;
            cout << detik << " Detik = "
                 << detik / 3600 << " Jam dan "
                 << detik / 60 << " Menit\n" << endl;
        }
        else if (pilihan == 4) {
            cout << "Program selesai." << endl;
        }
        else {
            cout << "Pilihan ga ada oi!\n" << endl;
        }

    } while (pilihan != 4);

    return 0;
}