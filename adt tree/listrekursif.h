//NIM/Nama : 13513017/miftahulmahfuzh
//Nama file : listrekursif.h
//Topik : List rekursif
//Tanggal : 
//Deskripsi : List rekursif dengan pointer

/***************** MODUL LIST REKURSIF *****************/
// List rekursif direpresentasi dengan pointer

#ifndef listlinier_h
#define listlinier_h
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/** Konstanta **/
#define Nil NULL /*adrress tak terdefinisi*/
typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype Info; 
	address Next;
	} ElmtList;
typedef address List;
	
#define Info(P) (P)->Info
#define Next(P) (P)->Next

/***************** Manajemen Memori *****************/
address Alokasi (infotype X);
//{ Mengirimkan address hasil alokasi sebuah elemen }
//{ Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
//Info(P) = X, Next(P) = Nil }
//{ Jika alokasi gagal, mengirimkan Nil }

void Dealokasi (address *P);
//{ I.S. P terdefinisi }
//{ F.S. P dikembalikan ke sistem }
//{ Melakukan dealokasi/pengembalian address P }

/*** Primitif-primitif yang harus direalisasikan ***/

/*** Selektor ***/
infotype FirstELmt(List L);
//Mengirimkan elemen pertama sebuah list L yang tidak kosong

List Tail (List L);
//Mengirimkan list L yang tidak kosong tanpa elemen pertamanya

/*** Konstruktor ***/
List Konso (infotype e,List L);
//Mengirimkan list L dengan tambahan e sebagai elemen pertamanya
//e harus dialokasi terlebih dahulu
//Jika alokasi e gagal, mengirimkan L

List Konsdot (List L, infotype e);
//Mengirimkan list L dengan tambahan e sebagai elemen terakhir
//e harus dialokasi terlebih dahulu }
//Jika alokasi e gagal, mengirimkan L }

/*** Predikat ***/
boolean IsListEmpty (List L);
//Mengirimkan true jika list kosong, false jika tidak kosong
//Mungkin yang dikirimkan adalah sebuah list kosong }

/*** Operasi Lain ***/
List Copy (List L);
//Mengirimkan salinan list L (menjadi list baru)
//Jika ada alokasi gagal, mengirimkan L

List Concat (List L1, List L2);
//Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru)
//Jika ada alokasi gagal, menghasilkan Nil

void PrintList (List L);
//{ I.S. L terdefinisi. }
//{ F.S. Setiap elemen list dicetak. }

int NBElmtList (List L);
//Mengirimkan banyaknya elemen list L, Nol jika L kosong

boolean Search (List L, infotype X);
//Mengirim true jika X adalah anggota list, false jika tidak

#endif
