/*
nama [13513017] : miftahul mahfuzh
ADT list rekursif
*/
#ifndef listrek_H
#define listrek_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
infotype info;
address next;
} ElmtList;
typedef address List;

/* Selektor */

#define Info(P) (P) -> info
#define Next(P) (P) -> next

/* Manajemen Memori */

address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P);=X, Next(P);=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L);
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmt(List L);
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
/* Primitif-Primitif Pemrosesan List */
infotype FirstElmt (List L);
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
List Tail(List L);
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
List Konso(infotype e, List L);
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. e dialokasi
terlebih dahulu. Jika alokasi gagal, mengirimkan L */
/* Fungsi dan Prosedur Lain */
 List Konsdot (List L, infotype e);  
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhir */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
/* *** Predikat *** */
boolean IsListEmpty (List L);  
/* Mengirimkan true jika list kosong, false jika tidak kosong */
/* Mungkin yang dikirimkan adalah sebuah list kosong */
/* *** Operasi Lain *** */
List Copy (List L);  
/* Mengirimkan salinan list L (menjadi list baru); */
/* Jika ada alokasi gagal, mengirimkan L */
List Concat (List L1,List L2);  
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru); */
/* Jika ada alokasi gagal, menghasilkan Nil */

void PrintList (List L);
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */

int NBElmtList (List L);  
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */

boolean Search (List L,infotype X);  
/* Mengirim true jika X adalah anggota list, false jika tidak */
#endif