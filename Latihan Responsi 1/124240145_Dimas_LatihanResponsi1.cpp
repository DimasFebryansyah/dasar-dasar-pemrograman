#include <iostream>
#include <string>
#include <cstdlib> // Untuk fungsi system()

using namespace std;

int menu;
struct Barang
{
    string nama;
    int stok;
    string tanggal;

    void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
    bool isBarangEmpty(const Barang &barang)
    {
        return barang.nama.empty() || barang.tanggal.empty() || barang.stok == 0;
    }
    void tampilkanMenu(Barang &barang1, Barang &barang2, int &kesempatan)
    {
        if (kesempatan > 0)
        {
            cout << "Menu Minimarket" << endl;
            cout << "1. Input Barang dan Stok\n";
            cout << "2. Pengecekan Barang dan Stok\n";
            cout << "3. Keluar\n"; // Mengubah opsi 3 menjadi Keluar
            cout << "=============================\n";
            cout << "Pilih Menu: ";
            cin >> menu;
            cout << endl;
            switch (menu)
            {
            case 1: // menu input barang dan stok
                cin.ignore();
                cout << "Masukkan nama barang pertama: ";
                getline(cin, barang1.nama);
                cout << "Masukkan stok barang pertama: ";
                cin >> barang1.stok;
                cin.ignore();
                cout << "Tanggal masuk barang1 (hh/bb): ";
                getline(cin, barang1.tanggal);
                cout << endl;
                cout << "Masukkan nama barang kedua  : ";
                getline(cin, barang2.nama);
                cout << "Masukkan stok barang kedua  : ";
                cin >> barang2.stok;
                cin.ignore();
                cout << "Tanggal masuk barang2 (hh/bb): ";
                getline(cin, barang2.tanggal);
                break;
            case 2: // menu Pengecekan Barang dan Stok
                if (isBarangEmpty(barang1) || isBarangEmpty(barang2))
                {
                    cout << "\nData barang belum lengkap. Silakan isi data barang terlebih dahulu.\n"
                         << endl;
                    kesempatan--;
                    cout << "Anda masih memiliki " << kesempatan << " kesempatan untuk mengakses halaman utama kembali." << endl;
                    cout << "Apakah Anda ingin membersihkan layar? (y/n): ";
                    char bersihkan;
                    cin >> bersihkan;
                    if (bersihkan == 'y' || bersihkan == 'Y')
                    {
                        clearScreen(); // Membersihkan layar jika pengguna memasukkan 'y'
                    } // Menambah jumlah kesempatan
                    tampilkanMenu(barang1, barang2, kesempatan); // Kembali ke menu utama untuk mengisi data barang
                }
                else
                {
                    cout << "\nData Barang yang Dimasukkan:" << endl;
                    cout << "Barang 1: " << barang1.nama << ", Stok: " << barang1.stok << ", Tanggal: " << barang1.tanggal << endl;
                    cout << "Barang 2: " << barang2.nama << ", Stok: " << barang2.stok << ", Tanggal: " << barang2.tanggal << endl
                         << endl;
                }
                break; // Tambahkan break di sini
            case 3:    // Menu Keluar
                cout << "Apakah Anda yakin ingin keluar dari program? (y/n): ";
                char keluar;
                cin >> keluar;
                if (keluar == 'y' || keluar == 'Y')
                {
                    cout << "Program tekah berakhir. Terima kasih!" << endl;
                    return; // Mengakhiri fungsi tampilkanMenu dan keluar dari program
                }
                else
                {
                    tampilkanMenu(barang1, barang2, kesempatan); // Melanjutkan program
                }
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
            }
            kesempatan--;
            if (kesempatan > 0)
            {
                cout << "Anda masih memiliki " << kesempatan << " kesempatan untuk mengakses halaman utama kembali." << endl;
                cout << "Apakah Anda ingin membersihkan layar? (y/n): ";
                char bersihkan;
                cin >> bersihkan;
                if (bersihkan == 'y' || bersihkan == 'Y')
                {
                    clearScreen(); // Membersihkan layar jika pengguna memasukkan 'y'
                }
                tampilkanMenu(barang1, barang2, kesempatan); // Menampilkan menu utama
            }
            else
            {
                cout << "Kesempatan habis. Program akan keluar." << endl;
            }
        }
    }
    int main()
    {
        // Login
        string username, inputUsername;
        int password, inputPassword;

        cout << "Masukkan username: ";
        cin >> inputUsername;
        cout << "Masukkan password: ";
        cin >> inputPassword;

        username = "dimas";   // Username Nama Panggilan
        password = 124240145; // Password yang digunakan

        if (inputUsername == username && inputPassword == password)
        {
            cout << "Login berhasil!" << endl;
        }
        else
        {
            cout << "Login gagal!" << endl;
            return 0; // Mengakhiri program jika login gagal
        }
        Barang barang1, barang2;                     // Deklarasi variabel barang di luar switch-case
        int kesempatan = 3;                          // Jumlah kesempatan untuk mengakses halaman utama
        tampilkanMenu(barang1, barang2, kesempatan); // Menampilkan menu utama
        return 0;                                    // Mengakhiri program dengan benar
    }
