#include "tabel1.h"
int main() {
	/*kamus*/
	TabInt T;
	IdxType i,nbm;
	ElType x;
	/*algoritma*/
	printf("*** PROGRAM UTAMA UNTUK ADT ARRAY DENGAN ELEMEN TERURUT ***\n\n");
	printf("*** Inisialisasi tabel ***\n");
	printf("Masukkan nilai efektif tabel = ");
	scanf("%d",&nbm); SetNeff(&T,nbm);
	for(i=1;i<=GetLastIdx(T);i++) {
		printf("Masukkan nilai elemen ke-%d = ",i);
		scanf("%d",&x);
		SetEl(&T,i,x);
	}
	printf("Isi tabel =\n");
	for(i=1;i<=GetLastIdx(T);i++) 
		printf("[%d] %d\n",i,GetElmt(T,i));
	
	printf("\n*** Penjumlahan seluruh elemen tabel ***\n");
	printf("Hasil penjumlahan seluruh elemen tabel = %d\n",SumTab(T));
	
	printf("\n*** Update elemen tabel ***\n");
	printf("Masukkan sebuah nilai baru = ");
	scanf("%d",&x);
	do {
		printf("Masukkan indeks untuk update (antara 1 s.d. 6) = ");
		scanf("%d",&i);
		if(i<1||i>6) printf("Masukan indeks salah.\n");
	}while (i<1||i>6);
	UpdateElmt(&T,i,x);
	printf("Isi tabel =\n");
	for(i=1;i<=GetLastIdx(T);i++) 
		printf("[%d] %d\n",i,GetElmt(T,i));

	printf("\n*** Penghapusan sebuah nilai elemen tabel ***\n");
	printf("Masukkan nilai yang akan dihapus = ");
	scanf("%d",&x);
	Del1Urut(&T,x);
	printf("Isi tabel =\n");
	for(i=1;i<=GetLastIdx(T);i++) 
		printf("[%d] %d\n",i,GetElmt(T,i));

	printf("\n*** Penghapusan semua elemen bernilai tertentu ***\n");
	printf("Masukkan nilai yang akan dihapus = ");
	scanf("%d",&x);
	DelAllX(&T,x);	
	printf("Isi tabel =\n");
	for(i=1;i<=GetLastIdx(T);i++) 
		printf("[%d] %d\n",i,GetElmt(T,i));

}