/* NIM/Nama : miftahul mahfuzh
Nama file   : P04135105001.h
Topik       : matriks
Tanggal     : 25 september 2014
Deskripsi   : olah data matriks*/

#ifndef matriks_H
#define matriks_H
#include <stdio.h>
#include "boolean.h"
#include <math.h>

/* ********** Definisi TYPE MATRIKS dengan indeks int ********** */
/* Ukuran minimum dan maksimum baris dan kolom */
typedef int indeks; /* indeks baris, kolom */
#define BrsMin   1
#define BrsMax 100
#define KolMin   1
#define KolMax 100
typedef double el_type; 
typedef struct 
{
el_type Mem[BrsMax+1][KolMax+1];
int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
int NKolEff;  /* banyaknya/ukuran kolom yg terdefinisi */
}MATRIKS; 
/* NBrsEff ≥ 1 dan NKolEff ≥ 1 */
/* Memori MATRIKS yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB,int NK,MATRIKS *M);
/* Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” memori */
/* I.S. NB dan NK adalah valid untuk memori MATRIKS yang dibuat */
/* F.S. MATRIKS M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */

indeks GetIdxBrsMin();
/* Mengirimkan indeks baris minimum MATRIKS apapun */

indeks GetIdxKolMin();
/* Mengirimkan indeks kolom minimum MATRIKS apapun */

indeks GetIdxBrsMax();
/* Mengirimkan indeks baris maksimum MATRIKS apapun */

indeks GetIdxKolMax();
/* Mengirimkan indeks kolom maksimum MATRIKS apapun */

boolean IsIdxValid (int i,int  j);
/* Mengirimkan true jika i, j adalah indeks yang valid */

/* *** Untuk sebuah MATRIKS M yang terdefinisi: *** */
indeks FirstIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */

indeks FirstIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */

indeks LastIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */

indeks LastIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */

indeks GetNBrsEff (MATRIKS M);
/* Mengirimkan banyaknya baris efektif M */

indeks GetNKolEff (MATRIKS M);
/* Mengirimkan banyaknya kolom efektif M */

boolean IsIdxEff (MATRIKS M,indeks i,indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

el_type GetElmt (MATRIKS M,indeks i,indeks j);
/* Mengirimkan elemen M dg nomor baris i dan nomor kolom j */

el_type GetElmtDiagonal (MATRIKS M,indeks i);
/* Mengirimkan elemen M(i,i) */
/* *** Operasi mengubah nilai elemen MATRIKS: Set / Assign *** */

void SetBrsEff (MATRIKS *M,int NB);
/* I.S. M sudah terdefinisi */
/* F.S. Nilai M.BrsEff diisi dengan NB, */

void SetKolEff (MATRIKS *M,int NK);
/* I.S. M sudah terdefinisi */
/* F.S. Nilai M.NKolEff diisi dengan NK */

void SetEl (MATRIKS *M,int  i,int j,el_type X);
/* I.S. M sudah terdefinisi */
/* F.S. M(i,j) bernilai X */
/* Proses: Mengisi M(i,j) dengan X */

/* ********** Assignment MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn,MATRIKS *MHsl);
/* Melakukan assignment MHsl ← Min */

/* ********** KELOMPOK BACA/TULIS ********** */

void BacaMATRIKS (MATRIKS *M,indeks NB,int NK);
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK */
/* Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* dari pembacaan dengan traversal per baris */

void TulisMATRIKS (MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar*/
/* Menulis nilai setiap indeks dan elemen M ke layar dengan traversal per baris */

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */

MATRIKS tambah (MATRIKS M1,MATRIKS M2);
/* PrekondisiM1 berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan MATRIKS: M1 + M2 */

MATRIKS kurang (MATRIKS M1,MATRIKS M2);
/* PrekondisiM berukuran sama dengan M */
/* Mengirim hasil pengurangan MATRIKS: salinan M1 – M2 */

MATRIKS kalimatriks (MATRIKS M1,MATRIKS M2);
/* PrekondisiUkuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian MATRIKS: salinan M1 * M2 */

MATRIKS kalielemen (MATRIKS M,int X);
/* Mengirim hasil perkalian setiap elemen M dengan X */

void kali (MATRIKS *M,int K);
/* Mengalikan setiap elemen M dengan K */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M);
/* Mengirimkan banyaknya elemen M */

el_type RataNilai (MATRIKS M,indeks N);
/*Prekondisi: Matriks tidak kosong. */
/*Mengirimkan rata-rata nilai ujian ke-N */

indeks RataTestTertinggi (MATRIKS M);
/*Prekondisi : Matriks tidak kosong */
/*Mengirim nomor test yang memiliki rata-rata kelas tertinggi*/

void TulisStatistikTest (MATRIKS M);
/*I.S. : M terdefinisi, tidak kosong. */
/*F.S. : Untuk setip test yang pernah dilakukan ditayangkan nilai*/
/*terkecil dan terbesar yang diperoleh mahasiswa, berikut*/
/*nilai rata-rata dari seluruh mahasiswa.*/
/*Setiap baris menampilkan data statistik sebuah test. */
/*Proses : */

void TulisMatriks1 (MATRIKS M);
/*I.S. : M terdefinisi, tidak kosong */
/*F.S. : Semua elemen matriks tertulis di layar.*/
/*Setiap baris akan menampilkan data satu mahasiswa, berupa:*/
/*Nomor urut, nilai untuk setiap test, dan rata-rata nilai dari*/
/*seluruh test. */
/*Proses : */ 	
#endif
