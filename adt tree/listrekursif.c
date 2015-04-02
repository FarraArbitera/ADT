//NIM/Nama : 13513017/miftahulmahfuzh
//Nama file : listrekursif.c
//Topik : List rekursif
//Tanggal : 
//Deskripsi : List rekursif dengan pointer

#include "listrekursif.h"

/***************** Manajemen Memori *****************/
address Alokasi (infotype X)
//{ Mengirimkan address hasil alokasi sebuah elemen }
//{ Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
//Info(P) = X, Next(P) = Nil }
//{ Jika alokasi gagal, mengirimkan Nil }
{
	//Kamus Lokal
	address P;
	//Algortima
	P = (address)malloc(sizeof(ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	else 
		P = Nil;
	return (P);
}
void Dealokasi (address *P)
//{ I.S. P terdefinisi }
//{ F.S. P dikembalikan ke sistem }
//{ Melakukan dealokasi/pengembalian address P }
{
	//Kamus Lokal
	
	//Algortima
	free (*P);
}

/*** Primitif-primitif yang harus direalisasikan ***/

/*** Selektor ***/
infotype FirstELmt(List L)
//Mengirimkan elemen pertama sebuah list L yang tidak kosong
{
	//Kamus Lokal
	
	//Algoritma
	return Info(L);
}
List Tail (List L)
//Mengirimkan list L yang tidak kosong tanpa elemen pertamanya
{
	//Kamus Lokal
	
	//Algoritma
	return Next(L);
}

/*** Konstruktor ***/
List Konso (infotype e,List L)
//Mengirimkan list L dengan tambahan e sebagai elemen pertamanya
//e harus dialokasi terlebih dahulu
//Jika alokasi e gagal, mengirimkan L
{
	//Kamus Lokal
	address P;
	//Algoritma
	P = Alokasi (e);
	if (P==Nil) 
		return L;
	else {
		Next (P) = L;
		return P;
	}
}
List Konsdot (List L, infotype e)
//Mengirimkan list L dengan tambahan e sebagai elemen terakhir
//e harus dialokasi terlebih dahulu }
//Jika alokasi e gagal, mengirimkan L }
{
	//Kamus Lokal
	address P;
	List Last;
	//Algoritma
	P = Alokasi (e);
	if (P==Nil) {
		return L;
	}
	else {
		if (IsListEmpty(L)) 
			return P;
		else {
			Last = L;
			while (Next(Last)!=Nil) {
				Last = Next(Last); }
			Next(Last) = P;
			return L;
		}
	}
}

/*** Predikat ***/
boolean IsListEmpty (List L)
//Mengirimkan true jika list kosong, false jika tidak kosong
//Mungkin yang dikirimkan adalah sebuah list kosong }
{
	//Kamus Lokal
	
	//Algoritma
	return (L==Nil);	
}
/*** Operasi Lain ***/
List Copy (List L)
//Mengirimkan salinan list L (menjadi list baru)
//Jika ada alokasi gagal, mengirimkan L
{
	//Kamus Lokal
	
	//Algoritma
	if (IsListEmpty(L)) {
		return Nil;
	}
	else 
		return Konso (FirstELmt(L), Copy(Tail(L)));
}
List Concat (List L1, List L2)
//Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru)
//Jika ada alokasi gagal, menghasilkan Nil
{
	//Kamus Lokal
	
	//Algoritma
	if (IsListEmpty(L1)) {
		return Copy(L2);
	}
	else {
		return Konso (FirstELmt(L1), Concat(Tail(L1), L2));
	}
}
void PrintList (List L)
//{ I.S. L terdefinisi. }
//{ F.S. Setiap elemen list dicetak. }
{
	//Kamus Lokal
//	infotype X;
	//Algoritma
	if (!IsListEmpty(L)) {
		//X = FirstElmt(L);
		printf("%d ", FirstELmt(L));
		PrintList(Tail(L));
	}
}
boolean Search (List L, infotype X)
//Mengirim true jika X adalah anggota list, false jika tidak
{
	//Kamus Lokal
	
	//Algoritma
	if (IsListEmpty(L)) {
		return false;
	}
	else {
		if (FirstELmt(L)==X) 
			return true; 
		else 
			Search(Tail(L), X); 
	}
}
int NBElmtList (List L)
//Mengirimkan banyaknya elemen list L, Nol jika L kosong
{
	//Kamus Lokal
	
	//Algoritma
	if (IsListEmpty(L)) {
		return 0;
	}
	else {
		return 1 + NBElmtList(Tail(L));
	}
}
