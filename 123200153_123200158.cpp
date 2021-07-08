#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct pemilik{
	string nama;
	string alamat;
	string notelp;
	string norek;
	string saldo;
}nasabah[100],temp;

int menuutama(int &pilih){
	system("cls");
	cout << "\t\t\t\t\t\t=====================" << endl;
	cout << "\t\t\t\t\t\t||     nasabah     ||" << endl;
	cout << "\t\t\t\t\t\t=====================" << endl;
	cout << "\t\t\t\t\t\t|| 1. Input Data   ||" << endl;
	cout << "\t\t\t\t\t\t|| 2. Output Data  ||" << endl;
	cout << "\t\t\t\t\t\t|| 3. Searching    ||" << endl;
	cout << "\t\t\t\t\t\t|| 4. Sorting      ||" << endl;
	cout << "\t\t\t\t\t\t|| 5. Transaksi    ||" << endl;
	cout << "\t\t\t\t\t\t|| 6. Exit         ||" << endl;
	cout << "\t\t\t\t\t\t====================" << endl;
	cout << "\t\t\t\t\t\tPilih [1-6]? : "; cin >> pilih;
	
	return pilih;
}

int menusearch(int &pilih){
	system("cls");
	cout << "\t\t\t\t\t=============================" << endl;
	cout << "\t\t\t\t\t||	 Menu Searching	   ||" << endl;
	cout << "\t\t\t\t\t=============================" << endl;
	cout << "\t\t\t\t\t|| 1. Sequential 	   ||" << endl;
	cout << "\t\t\t\t\t|| 2. Binary		   ||" << endl;
	cout << "\t\t\t\t\t|| 3. Kembali ke Menu Utama||" << endl;
	cout << "\t\t\t\t\t=============================" << endl;
	cout << "\t\t\t\t\tPilih Searching [1-3] : "; cin >> pilih;
	return pilih;
}

int menusorting(int &pilih){
	system("cls");
	cout << "\t\t\t\t\t==============================" << endl;
	cout << "\t\t\t\t\t||	 Menu Sorting	    ||" << endl;
	cout << "\t\t\t\t\t==============================" << endl;
	cout << "\t\t\t\t\t|| 1. Bubble Sort	    ||" << endl;
	cout << "\t\t\t\t\t|| 2. Selection Sort        ||" << endl;
	cout << "\t\t\t\t\t==============================" << endl;
	cout << "Pilih Sorting [1/2] : "; cin >> pilih;
	
	return pilih;
}

int menutransaksi(int &pilih){
	system("cls");
	cout << "\t\t\t\t\t=============================" << endl;
	cout << "\t\t\t\t\t||	Menu Transaksi	   ||" << endl;
	cout << "\t\t\t\t\t=============================" << endl;
	cout << "\t\t\t\t\t|| 1. Merging Sambung 	   ||" << endl;
	cout << "\t\t\t\t\t|| 2. Merging Urut   	   ||" << endl;
	cout << "\t\t\t\t\t|| 3. Kembali ke Menu Utama||" << endl;
	cout << "\t\t\t\t\t=============================" << endl;
	cout << "\t\t\t\t\tPilih Searching [1-3] : "; cin >> pilih;
	return pilih;
}

void garis(){
	for (int i = 0; i < 90; i++)
	{
		cout << "=";
	}
	cout << endl;
}

void header(){
	garis();
	cout << left << setw(20) << " Pemilik ke " << setw(20) << "Nama" << setw(10) << "Alamat" << setw(20) << "No telepon" << setw(10) << "No rekening" << setw(15) << "saldo" << endl;
	garis();
}

void writeData(ofstream &dataOut, int &jmlData, pemilik nasabah[], string &myFile){
	dataOut.open(myFile.c_str());
	for (int i = 0; i < jmlData; i++){
		dataOut << nasabah[i].nama << endl;
		dataOut << nasabah[i].alamat << endl;
		dataOut << nasabah[i].notelp<< endl;
		dataOut << nasabah[i].norek << endl;
		dataOut << nasabah[i].saldo << endl;

	}
	dataOut.close();
}

void input(ofstream &dataOut, int &jmlData, string &myFile){
	system("cls");
	cout << "\n Masukkan Nama File : "; cin >> myFile;
	cout << "Masukkan Jumlah data pemilik nasabah : "; cin >> jmlData;
	cin.ignore();
	for(int i = 0; i <  jmlData; i++){
		cout << "\nData Pemilik nasabah ke - " << i+1 << endl;
		cout << "Nama\t\t: "; getline(cin, nasabah[i].nama);
		cout << "No telepon\t: "; getline(cin,nasabah[i].notelp);
		cout << "NO rekening\t: "; cin >> nasabah[i].norek;
		cout << "saldo\t\t: "; cin >> nasabah[i].saldo;
		cout << "Alamat\t\t: "; cin.ignore(); getline(cin,nasabah[i].alamat);
	}
	writeData(dataOut, jmlData, nasabah, myFile);
}

void output(int &jmlData){
	cout << endl;
	cout << "\n==================================================\n";
	cout << "\nData yang sudah di urutkan\n";
	header();
	for(int i = 0 ; i < jmlData; i++){
		cout << setw(20) << i+1 << setw(20) << nasabah[i].nama << setw(10) << nasabah[i].alamat << setw(20) << nasabah[i].notelp<< setw(10) << nasabah[i].norek << setw(10) << nasabah[i].saldo << endl;
	}
	garis();
}

void readData(ifstream &dataIn, int &jmlData, pemilik nasabah[], string &myFile){
	int i = 0;
	label_continue :

	cout << "\n Masukkan Nama File : "; cin >> myFile;
	dataIn.open(myFile.c_str());

	if(dataIn.is_open()){
		header();
		while(true){
			getline(dataIn, nasabah[i].nama);
			if(dataIn.eof() || nasabah[i].nama==""){
				break;
			}else{
				
				getline(dataIn, nasabah[i].alamat);
				getline(dataIn, nasabah[i].notelp);
				getline(dataIn, nasabah[i].norek);
				getline(dataIn, nasabah[i].saldo);
				
				cout << setw(20) << i+1 << setw(20) << nasabah[i].nama << setw(10) << nasabah[i].alamat << setw(20) << nasabah[i].notelp<< setw(10) << nasabah[i].norek << setw(10) << nasabah[i].saldo << endl;
				i++;
			}
			
		}
		garis();
		jmlData = i;
			dataIn.close();
	}else{
		cout << "File " << myFile << " tidak ditemukan" << endl;
		dataIn.close();
		goto label_continue;
	}
}

void bubble(pemilik nasabah[], int &jmlData){
	int i, j; 
	int pilih;
	cout << "\n=====================================\n";
	cout << "Pengurutan Data Dengan Metode Bubble";
	cout << "\n=====================================\n";
	cout << "1. Nama " << endl;
	cout << "2. no rekening " << endl;
	cout << "Masukkan Pilihan :  "; cin >> pilih;
	switch (pilih) {
		case 1 :
			for(i = 0; i < jmlData-1; i++){
				for(j = 0; j < jmlData-1-i; j++){
					if(nasabah[j].nama > nasabah[j+1].nama){
						temp = nasabah[j];
						nasabah[j] = nasabah[j+1];
						nasabah[j+1] = temp;
					}
				}
			}
			output(jmlData);
		break;
		
		case 2 :
			for(i = 0; i < jmlData-1; i++){
				for(j = 0; j < jmlData-1-i; j++){
					if(nasabah[j].norek > nasabah[j+1].norek){
						temp = nasabah[j];
						nasabah[j] = nasabah[j+1];
						nasabah[j+1] = temp;
					}
				}
			}
			output(jmlData);
		break;
		
		default :
			cout << "Pilihan tidak ditemukan" << endl;
			break;
	}
	
}

void selection(pemilik nasabah[], int &jmlData){
	int i, j;
	int pilih;
	cout << "\n=====================================\n";
	cout << "Pengurutan Data Dengan Metode Selection";
	cout << "\n=====================================\n";
	cout << "1. Nama " << endl;
	cout << "2. NO rekening " << endl;
	cout << "Masukkan Pilihan :  "; cin >> pilih;
	switch (pilih) {
		case 1 :
			for(i = 0; i < jmlData; i++){
				for(j= i+1; j < jmlData; j++){
					if (nasabah[i].nama > nasabah[j].nama){
						temp = nasabah[i];
						nasabah[i] = nasabah[j];
						nasabah[j] = temp;
					}
				}
			}
			output(jmlData);
		break;
		
		case 2 :
			for(i = 0; i < jmlData; i++){
				for(j= i+1; j < jmlData; j++){
					if (nasabah[i].norek > nasabah[j].norek){
						temp = nasabah[i];
						nasabah[i] = nasabah[j];
						nasabah[j] = temp;
					}
				}
			}
			output(jmlData);
		break;
		
		default :
			cout << "Pilihan tidak ditemukan" << endl;
			break;
		
	}
	
}
void quicknama(pemilik nasabah[], int first, int last){
	int low, high;
	pemilik list_separate;
	low = first;
	high = last;
	list_separate = nasabah[(first + last)/2];
	do{
		while(nasabah[low].nama < list_separate.nama){
			low++;
		}
		while(nasabah[high].nama > list_separate.nama){
			high--;
		}
		if (low <= high){
			temp = nasabah[low];
			nasabah[low++] = nasabah[high];
			nasabah[high--] = temp;
		}

	}while(low <= high);
	if(first < high){
		quicknama(nasabah, first, high);
	}
	if (low < last ){
		quicknama(nasabah, low, last);
	}

}
void quicknorek(pemilik nasabah[], int first, int last){
	int low, high;
	pemilik list_separate;
	low = first;
	high = last;
	list_separate = nasabah[(first + last)/2];
	do{
		while(nasabah[low].norek < list_separate.norek){
			low++;
		}
		while(nasabah[high].norek > list_separate.norek){
			high--;
		}
		if (low <= high){
			temp = nasabah[low];
			nasabah[low++] = nasabah[high];
			nasabah[high--] = temp;
		}

	}while(low <= high);
	if(first < high){
		quicknorek(nasabah, first, high);
	}
	if (low < last ){
		quicknorek(nasabah, low, last);
	}
}

void sequential(int &jmlData, pemilik nasabah[]){
	bool found = false;
	string cariNama,cariAlamat,cariTgl,carinasabah,carisaldo;
	int i = 0, pilih;
	cout << endl;
	cout << "\n=====================================\n";
	cout << "Pencarian Dengan Sequensial";
	cout << "\n=====================================\n";
	cout << "1. Nama " << endl;
	cout << "2. No rekening " << endl;
	cout << "Masukkan Pilihan :  "; cin >> pilih;
	switch (pilih) {
		case 1 :
		system("cls");
			cout << "\n Masukkan Nama yang dicari : "; cin.ignore(); getline(cin, cariNama);
			while((i < jmlData) & (!found)){
				if(nasabah[i].nama == cariNama){
					found = true ;
				} else {
					i += 1;
				}
			}
			if(found){
				cout << "\nData ditemukan pada Pemilik nasabah ke - " << i+1 << endl;
				cout << "Nama\t\t: " << nasabah[i].nama << endl;
				cout << "Alamat\t\t: " << nasabah[i].alamat << endl;
				cout << "Tanggal\t\t: " << nasabah[i].notelp<< endl;
				cout << "No rekening\t: " << nasabah[i].norek << endl;
				cout << "saldo\t\t: " << nasabah[i].saldo << endl;
			} else {
				cout << endl;
				cout << cariNama << " tidak ditemukan dalam data" << endl;
			}
		break;
		
		case 2 :
		system("cls");
			cout << "\n Masukkan Nomor nasabah yang dicari : "; cin.ignore(); getline(cin, carinasabah);
			while((i < jmlData) & (!found)){
				if(nasabah[i].norek == carinasabah){
					found = true ;
				} else {
					i += 1;
				}
			}
			if(found){
				cout << "\nData ditemukan pada Pemilik nasabah ke - " << i+1 << endl;
				cout << "Nama\t\t: " << nasabah[i].nama << endl;
				cout << "Alamat\t\t: " << nasabah[i].alamat << endl;
				cout << "NO telepon\t: " << nasabah[i].notelp<< endl;
				cout << "NO rekening\t: " << nasabah[i].norek << endl;
				cout << "saldo\t\t: " << nasabah[i].saldo << endl;
			} else {
				cout << endl;
				cout << carinasabah << " tidak ditemukan dalam data" << endl;
			}
		break;
		
		default :
			cout << "Pilihan tidak ditemukan" << endl;
			break;
	}
}


void binary(int &jmlData, pemilik nasabah[]){
	int i , j , k, pilih;
	string cariNama,cariAlamat,cariTgl,carinasabah,carisaldo;
	bool found = false;
	cout << "\n=====================================\n";
	cout << "Pencarian Dengan Binary";
	cout << "\n=====================================\n";
	cout << "1. Nama " << endl;
	cout << "2. No rekening " << endl;
	cout << "Masukkan Pilihan :  "; cin >> pilih;
	switch (pilih) {
		case 1 :
		system("cls");
			cout << "\nMasukkan Nama yang dicari : "; cin.ignore(); getline(cin, cariNama);
			i = 0;
			j = jmlData;
			quicknama(nasabah, 0, jmlData-1);
			while((!found) & (i <= j)){
				k = (i+j) / 2 ;
				if(cariNama == nasabah[k].nama){
					found = true;
				} else if(cariNama < nasabah[k].nama){
					j = k - 1;
				} else {
					i = k + 1;
				}
			}
			if (found){
				cout << "\nData ditemukan pada Pemilik nasabah ke - " << k+1 << endl;
				cout << "Nama\t\t: " << nasabah[k].nama << endl;
				cout << "Alamat\t\t: " << nasabah[k].alamat << endl;
				cout << "no telepon\t: " << nasabah[k].notelp<< endl;
				cout << "no rekening\t: " << nasabah[k].norek << endl;
				cout << "saldo\t\t: " << nasabah[k].saldo << endl;
			} else {
				cout << endl;
				cout << cariNama << " tidak ditemukan dalam data" << endl;
			}
		break;
		
		case 2 :
		system("cls");
			cout << "\nMasukkan Nomor nasabah yang dicari : "; cin.ignore(); getline(cin, carinasabah);
			i = 0;
			j = jmlData;
			quicknorek(nasabah, 0, jmlData-1);
			while((!found) & (i <= j)){
				k = (i+j) / 2 ;
				if(carinasabah == nasabah[k].norek){
					found = true;
				} else if(carinasabah < nasabah[k].norek){
					j = k - 1;
				} else {
					i = k + 1;
				}
			}
			if (found){
				cout << "\nData ditemukan pada Pemilik nasabah ke - " << k+1 << endl;
				cout << "Nama\t\t: " << nasabah[k].nama << endl;
				cout << "Alamat\t\t: " << nasabah[k].alamat << endl;
				cout << "No telepon \t: " << nasabah[k].notelp<< endl;
				cout << "No rekening\t: " << nasabah[k].norek << endl;
				cout << "saldo\t\t: " << nasabah[k].saldo << endl;
			} else {
				cout << endl;
				cout << carinasabah << " tidak ditemukan dalam data" << endl;
			}
		break;
		
		default :
			cout << "Pilihan tidak ditemukan" << endl;
			break;
		
	}
	
}

void mergingsambung(ifstream &dataIn, ofstream &dataOut, int &jmlData, pemilik nasabah[]){
	string file1, file2, file;
	int i=0;

	satu :
	cout << "Ketik nama File Pertama : "; cin >> file1;
	dataIn.open(file1.c_str());
	if(dataIn.is_open()){
		header();
		while(true){
			getline(dataIn, nasabah[i].nama);
			if(dataIn.eof() || nasabah[i].nama==""){
				break;
			}else{
				
				getline(dataIn, nasabah[i].alamat);
				getline(dataIn, nasabah[i].notelp);
				getline(dataIn, nasabah[i].norek);
				getline(dataIn, nasabah[i].saldo);

				cout << setw(20) << i+1 << setw(20) << nasabah[i].nama << setw(10) << nasabah[i].alamat << setw(20) << nasabah[i].notelp<< setw(10) << nasabah[i].norek << setw(10) << nasabah[i].saldo << endl;
				i++;
			}
			
		}
		garis();
		jmlData = i;
			dataIn.close();
	}else{
		cout << "File " << file1 << " tidak ditemukan" << endl;
		dataIn.close();
		goto satu;
	}
	cout << endl << endl;
	dua :
	cout << "Ketik nama File kedua : "; cin >> file2;
	dataIn.open(file2.c_str());
	if(dataIn.is_open()){
		header();
		while(true){
			getline(dataIn, nasabah[i].nama);
			if(dataIn.eof() || nasabah[i].nama==""){
				break;
			}else{
				
				getline(dataIn, nasabah[i].alamat);
				getline(dataIn, nasabah[i].notelp);
				getline(dataIn, nasabah[i].norek);
				getline(dataIn, nasabah[i].saldo);

				cout << setw(20) << i+1 << setw(20) << nasabah[i].nama << setw(10) << nasabah[i].alamat << setw(20) << nasabah[i].notelp<< setw(10) << nasabah[i].norek << setw(10) << nasabah[i].saldo << endl;
				i++;
			}
			
		}
		garis();
		jmlData = i;
			dataIn.close();
	}else{
		cout << "File " << file2 << " tidak ditemukan" << endl;
		dataIn.close();
		goto dua;
	}
	cout << endl;
	cout << "Masukkan Nama File Baru : "; cin >> file;
	dataOut.open(file.c_str());
	for (int i = 0; i < jmlData; i++){
		dataOut << nasabah[i].nama << endl;
		dataOut << nasabah[i].alamat << endl;
		dataOut << nasabah[i].notelp<< endl;
		dataOut << nasabah[i].norek << endl;
		dataOut << nasabah[i].saldo << endl;

	}
	dataOut.close();
	cout << "Data berhasil dibuat , cek output";

}

void sortingmergeurut(pemilik nasabah[], int &jmlData){
	int i, j; 
	for(i = 0; i < jmlData-1; i++){
		for(j = 0; j < jmlData-1-i; j++){
			if(nasabah[j].saldo > nasabah[j+1].saldo){
				temp = nasabah[j];
				nasabah[j] = nasabah[j+1];
				nasabah[j+1] = temp;
			}
		}
	}

}


void mergingurut(ifstream &dataIn, ofstream &dataOut, int &jmlData, pemilik nasabah[]){
	string file1, file2, file;
	int i=0;

	satu :
	cout << "Ketik nama File Pertama : "; cin >> file1;
	dataIn.open(file1.c_str());
	if(dataIn.is_open()){
		header();
		while(true){
			getline(dataIn, nasabah[i].nama);
			if(dataIn.eof() || nasabah[i].nama==""){
				break;
			}else{
				
				getline(dataIn, nasabah[i].alamat);
				getline(dataIn, nasabah[i].notelp);
				getline(dataIn, nasabah[i].norek);
				getline(dataIn, nasabah[i].saldo);

				cout << setw(20) << i+1 << setw(20) << nasabah[i].nama << setw(10) << nasabah[i].alamat << setw(20) << nasabah[i].notelp<< setw(10) << nasabah[i].norek << setw(10) << nasabah[i].saldo << endl;
				i++;
			}
			
		}
		garis();
		jmlData = i;
			dataIn.close();
	}else{
		cout << "File " << file1 << " tidak ditemukan" << endl;
		dataIn.close();
		goto satu;
	}
	cout << endl << endl;
	dua :
	cout << "Ketik nama File kedua : "; cin >> file2;
	dataIn.open(file2.c_str());
	if(dataIn.is_open()){
		header();
		while(true){
			getline(dataIn, nasabah[i].nama);
			if(dataIn.eof() || nasabah[i].nama==""){
				break;
			}else{
				
				getline(dataIn, nasabah[i].alamat);
				getline(dataIn, nasabah[i].notelp);
				getline(dataIn, nasabah[i].norek);
				getline(dataIn, nasabah[i].saldo);

				cout << setw(20) << i+1 << setw(20) << nasabah[i].nama << setw(10) << nasabah[i].alamat << setw(20) << nasabah[i].notelp<< setw(10) << nasabah[i].norek << setw(10) << nasabah[i].saldo << endl;
				i++;
			}
			
		}
		garis();
		jmlData = i;
			dataIn.close();
	}else{
		cout << "File " << file2 << " tidak ditemukan" << endl;
		dataIn.close();
		goto dua;
	}
	cout << endl;
	cout << "Masukkan Nama File Baru : "; cin >> file;
	dataOut.open(file.c_str());
	sortingmergeurut(nasabah,jmlData);
	for (int i = 0; i < jmlData; i++){
		dataOut << nasabah[i].nama << endl;
		dataOut << nasabah[i].alamat << endl;
		dataOut << nasabah[i].notelp<< endl;
		dataOut << nasabah[i].norek << endl;
		dataOut << nasabah[i].saldo << endl;
	}
	dataOut.close();
	cout << "Data berhasil dibuat , cek output";
}


int main(){
	ifstream dataIn;
	ofstream dataOut;
	string myFile;
	char is_continue;
	int pilih, jmlData;

	enum menu{INPUT = 1, OUTPUT, SEARCHING, SORTING, TRANSAKSI, EXIT};

	int pilihan = menuutama(pilih);
	while(pilihan != EXIT){
		switch(pilihan){
			case INPUT :
				input(dataOut, jmlData, myFile);
				break;
			case OUTPUT :
				readData(dataIn, jmlData, nasabah, myFile);
				break;
			case SEARCHING :
				pilihan = menusearch(pilih);
				switch(pilihan){
					case 1 :
					system("cls");
					cout << "\n\t\t==============================Sequential Search==============================" << endl << endl;
						readData(dataIn, jmlData, nasabah, myFile);
						sequential(jmlData, nasabah);
					break;
					case 2 : 
					system("cls");
					cout << "\n\t\t==============================Binary Search==============================" << endl << endl;
						readData(dataIn, jmlData, nasabah, myFile);
						binary(jmlData, nasabah);
						break;	
					case 3 :
						pilihan = menuutama(pilih);
						break;
					default :
						cout << "Pilihan tidak ditemukan" << endl;
						break;
				}
				break;
			case SORTING :
				pilihan = menusorting(pilih);
				switch(pilihan){
					case 1 : 
					system("cls");
					cout << "\n\t\t==============================Bubble Sort==============================" << endl << endl;
						readData(dataIn, jmlData, nasabah, myFile);
						bubble(nasabah, jmlData);
					break;
					case 2 : 
					system("cls");
					cout << "\n\t\t==============================Selection Sort==============================" << endl << endl;
						readData(dataIn, jmlData, nasabah, myFile);
						selection(nasabah, jmlData);
					break;
					
					case 3: 
						pilihan = menuutama(pilih);
					break;
					default :
					cout << " Pilihan tidak ada \n";
					break;
				}
				break;
			case TRANSAKSI :
				pilihan = menutransaksi(pilih);
				switch(pilihan){
					case 1 :
					system("cls");
					cout << "\n\t\t==============================Merging Sambung==============================" << endl << endl;
					mergingsambung(dataIn, dataOut, jmlData, nasabah);
					break;
					case 2 :
					system("cls");
					cout << "\n\t\t==============================Merging Urut==============================" << endl << endl;
					mergingurut(dataIn, dataOut, jmlData, nasabah);
					break;
				}
				break;
			default :
			cout << " Pilihan tidak ada "<< endl;
			break;
		}
		label_continue:
		cout << "\n\n Lanjutkan ? (Y/N) : "; cin >> is_continue;
		if ((is_continue == 'y') | (is_continue == 'Y')){
			pilihan = menuutama(pilih);
		}else if ((is_continue == 'n') | (is_continue == 'N')){
			break;
		}else {
			goto label_continue;
		}
	}
	cout << endl << endl;
	cout << "\t\t\t\t\t\t====================" << endl;
	cout << "\t\t\t\t\t\t PROGRAM SELESAI" << endl;
	cout << "\t\t\t\t\t\t====================" << endl;
	
	system("pause");
	return 0;
}
