/* File : adtstack.h */
/*nama[nim] : miftahul mahfuzh[13513017]*/
/* Implementasi Stack dalam bahasa C dengan alokasi statik */

#ifndef stack_H
#define stack_H
#include <stdio.h>
#include "boolean.h"
#define Nil 0 /* Nil adalah stack dengan elemen kosong */
#define MaxEl 10
typedef int infotype;
typedef int address;

/* indeks tabel */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit */
typedef struct { 
	infotype T[MaxEl+1]; /* tabel penyimpan elemen */
	address TOP;
/* alamat TOP: elemen puncak */
} Stack;

/* Definisi akses dengan Selektor : */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/*** Konstruktor/Kreator ***/
void CreateEmpty(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1..MaxEl karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/********** Predikat Untuk test keadaan KOLEKSI **********/
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/*********** Menambahkan sebuah elemen ke Stack **********/
void Push (Stack *S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/*********** Menghapus sebuah elemen Stack **********/
void Pop (Stack *S, infotype *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void TulisStack (Stack S); 
/* Menuliskan isi S ke layar dari top ke bottom secara horizontal (ke samping, */ 
/* lihat contoh) dengan hanya memanfaatkan operasi‐operasi dasar stack */ 
/* I.S. S terdefinisi, mungkin kosong */ 
/* F.S. Isi S tertulis di layar dari top ke bottom. Di akhir penulisan, S */ 
/* kembali ke kondisi I.S. */ 
/* Jika S kosong, tuliskan “Stack kosong” */ 
void FilterStack (Stack *S); 
/* I.S. Stack S terdefinisi dan tidak kosong */ 
/* F.S. S hanya berisi bilangan genap dan 0, semua bilangan ganjil dibuang */ 
/* Urutan elemen S sesuai urutan semula S, tanpa elemen bilangan ganjil */ 
void InverseStack(Stack *S);
#endif