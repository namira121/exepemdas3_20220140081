#include <iostream>
#include <string>
#include <vector>
using namespace std;

class penerbit {
public:
	string namapenerbit;
};

class pengarang {
public: 
	string namapengarang;
	vector<string> dikarang;
	penerbit* PENERBIT;
};

class buku {
public:
	string judulbuku;
	pengarang* PENGARANG;
};

int main() {
	penerbit GamaPress;
	GamaPress.namapenerbit = "Gama Press";

	penerbit IntanPariwara;
	IntanPariwara.namapenerbit = "Intan Pariwara";

	pengarang joko;
	joko.namapengarang = "Joko";
	joko.PENERBIT = &GamaPress;
	
	pengarang lia;
	lia.namapengarang = "Lia"; 
	lia.PENERBIT = &GamaPress;

	pengarang Asroni;
	Asroni.namapengarang = "Asroni"; 
	Asroni.PENERBIT = &IntanPariwara;

	pengarang giga;
	giga.namapengarang = "Giga";
	giga.PENERBIT = &IntanPariwara;

	buku fisika;
	fisika.judulbuku = "Fisika";
	fisika.PENGARANG = &joko;
	joko.dikarang.push_back(fisika.judulbuku);

	buku algoritma;
	algoritma.judulbuku = "Algoritma";
	algoritma.PENGARANG = &joko;
	joko.dikarang.push_back(algoritma.judulbuku);

	buku basisdata;
	basisdata.judulbuku = "Basisdata";
	basisdata.PENGARANG = &lia;
	lia.dikarang.push_back(basisdata.judulbuku);

	buku dasarpemrograman;
	dasarpemrograman.judulbuku = "Dasar Pemrograman";
	dasarpemrograman.PENGARANG = &Asroni;
	Asroni.dikarang.push_back(dasarpemrograman.judulbuku);

	buku matematika;
	matematika.judulbuku = "Matematika";
	matematika.PENGARANG = &giga;
	giga.dikarang.push_back(matematika.judulbuku);

	buku multimedia1;
	multimedia1.judulbuku = "Multimedia 1";
	multimedia1.PENGARANG = &giga;
	giga.dikarang.push_back(multimedia1.judulbuku);

	cout << "Daftar pengarang pada penerbit 'Gama Press' : " << endl;
	for (pengarang* PENGARANG : { &joko, &lia,&giga }) {
		if (PENGARANG->PENERBIT->namapenerbit == "Gama Press") {
			cout << PENGARANG->namapengarang << endl;
		}
	}
	cout << "\n";

	cout << "Daftar pengarang pada penerbit 'Intan Pariwara' : " << endl;
	for (pengarang* PENGARANG : { &Asroni, &giga }) {
		if (PENGARANG->PENERBIT->namapenerbit == "Intan Pariwara") {
			cout << PENGARANG->namapengarang << endl;
		}
	}
	cout << "\n";

	cout << "Daftar penerbit yang diikuti 'Giga' : " << endl; 
	for (penerbit* PENERBIT : { &GamaPress, &IntanPariwara }) {
		if (PENERBIT->namapenerbit == "Gama Press", "Intan Pariwara") {
			cout << PENERBIT->namapenerbit << endl; 
		}
	}
	cout << "\n";

	cout << "Daftar buku yang dikarang 'Joko': " << endl; 
	for (string buku : joko.dikarang) {
		cout << buku << endl;
	}
	cout << "\n";

	cout << "Daftar buku yang dikarang 'Lia': " << endl;
	for (string buku : lia.dikarang) {
		cout << buku << endl;
	}
	cout << "\n";

	cout << "Daftar buku yang dikarang 'Asroni': " << endl;
	for (string buku : Asroni.dikarang) {
		cout << buku << endl;
	}
	cout << "\n";

	cout << "Daftar buku yang dikarang 'Giga': " << endl;
	for (string buku : giga.dikarang) {
		cout << buku << endl; 
	}

	return 0;
}
