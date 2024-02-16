#include <iostream>

using namespace std;

void garis() {
    //cout << "======================================================\n";
    cout << "==============================\n";
}

void menuJasa() {
    cout << "\nDaftar Layanan yang ada di BERTEMAN\n";
    cout << "\t1. Temenin Call (50k)\n";
    cout << "\t2. Temenin VC (75k)\n";
    cout << "\t3. Temenin Curhat (100k)\n";
    cout << "Note : Setiap Layanan Memiliki Biaya admin yang berbeda, Khusus Temenin Curhat bebas biaya Admin.\n";
}

void detailTrx(string nmUser,string nmaTal, int umrTal, string genTal,  string karterTal,  string jnisJasa, int jumJam, int biayaAdm, int totBiaya) {
    garis();
	  cout << "| Detail Transaksi Pelanggan\n";
	  garis();
    cout << "| " << "Nama Pelanggan   : " << nmUser << endl;
    cout << "| " << "Nama Talent      : " << nmaTal<<endl;
    cout << "| " << "Umur             : " << umrTal<<endl;
    cout << "| " << "Gender           : " << genTal<<endl;
    cout << "| " << "Karakter         : " << karterTal<<endl;
    cout << "| " << "Jasa yang disewa : " << jnisJasa<<endl;
    cout << "| " << "Total Jam        : " << jumJam<<endl;
    cout << "| " << "Biaya Admin      : " << biayaAdm<<endl;
    cout << "| " << "Total Bayar      : " << totBiaya<<endl;
    garis();
}

void detilTal(string nama, int umur, string gender, string karakter) {
	  garis();
	  cout << "| " << "Nama		: " << nama << endl;
    cout << "| " << "Umur		: " << umur << endl;
    cout << "| " << "Gender	: " << gender << endl;
    cout << "| " << "Karakter	: " << karakter << endl;
    garis();
}

int hitungBiaya(int hrgaJasa, int jumJam, int biayaAdm) {
    int total;
    total = (hrgaJasa * jumJam) + biayaAdm;
    return (total);
}

int main() {
    const int jmlhTalent = 5;
    
    string talNama[jmlhTalent] = {"Rani", "Hana", "Bella", "Anggi", "Neva"};
    string talGen[jmlhTalent] = {"Wanita", "Wanita", "Wanita", "Wanita", "Wanita"};
    string talKrakter[jmlhTalent] = {"Cerewet", "Sabar", "Ceria", "Random", "Bawel"};
    int talUmur[jmlhTalent] = {19, 20, 21, 20, 19};
    int hrgaJasa[3] = {50000, 75000, 100000};
    int admPerJam;
    
    string jnisJasa, nmUser, nmaTal, genTal, karterTal;
    int totBiaya;
    int totBiayaAdm, umrTal, plihTal, plihJasa, jumJam, umur;
    bool pesan;
    
    cout << "Silahkan masukkan nama kamu : ";
    getline(cin, nmUser);
    cout<<"Silahkan masukkan umur kamu : ";cin>>umur;
    if (umur < 17) {
      	cout<<"Belum cukup umur";
       	pesan = false;
	  } else {
	  	  pesan = true;
 	  }
    
    while(pesan) {
    	  system("cls");
        cout << "Hai " << nmUser << "! Selamat datang di BERTEMAN" << endl;
        cout << "Tempat Sewa Teman Online ^_^" << endl;
    	for (int i = 0; i < jmlhTalent; ++i) {
    		garis();
        	cout << "|" << " Talent "<< i + 1 <<endl;
        	garis();
        	detilTal(talNama[i],talUmur[i],talGen[i],talKrakter[i]);
        	garis();
    	}
	
	    do {
	        cout << "Pilih Talent (1-" << jmlhTalent << ") : ";
	        cin >> plihTal;
	        if (plihTal < 1 || plihTal > jmlhTalent) {
	            cout << "Talent yang di pilih tidak ada. Silahkan pilih ulang\n";
	        }	
	    } while (plihTal < 1 || plihTal > jmlhTalent);
	    system("cls");
	    
	    nmaTal = talNama[plihTal - 1];
	    umrTal = talUmur[plihTal - 1];
	    genTal = talGen[plihTal - 1];
	    karterTal = talKrakter[plihTal - 1];
		
	  	cout << "Talent pilihan kamu" << endl;
	  	detilTal(nmaTal,umrTal,genTal,karterTal);
		
	    menuJasa();
	    do {
	        cout << "Silahkan Pilih Layanan (1-3) : ";
	        cin >> plihJasa;
	        if (plihJasa < 1 || plihJasa > 3) {
	            cout << "Jasa yang di pilih tidak tersedia. Silahkan pilih ulang\n";
	        }
	    } while (plihJasa < 1 || plihJasa > 3);
	
	    if (plihJasa == 1) {
	        jnisJasa = "Temenin Call (50k / jam)";
	    } else if (plihJasa == 2) {
	        jnisJasa = "Temenin VC (75k / jam)";
	    } else {
	        jnisJasa = "Temenin Curhat (100k / jam)";
	    }
	
	    do {
	        cout << "Silahkan ketik berapa lama (jam)     : ";
	        cin >> jumJam;
	        if (jumJam <= 0) {
	            cout << "Jumlah kurang dari 0. Silahkan ketik ulang\n";
	        }
	    } while (jumJam <= 0);
	    
	    system("cls");
	    
	    admPerJam = 1500;
	    totBiayaAdm = admPerJam * jumJam;
	    totBiaya = hitungBiaya(hrgaJasa[plihJasa - 1], jumJam, totBiayaAdm);
	  
	    detailTrx(nmUser, nmaTal, umrTal, genTal, karterTal, jnisJasa, jumJam, totBiayaAdm, totBiaya);
	  
	    cout<<"Ingin memilih lagi ?"<<endl;
	    cout<<"ketik 1 jika IYA"<<endl;
	    cout<<"ketik 0 jika TIDAK"<<endl;
	    cout<<"Pilihan : ";
	    cin>>pesan;
	    if (!pesan) {
	    	cout<<"Terimakasih sudah mengunjungi layanan kami :)"<<endl;
		}
	}
  return 0;
}