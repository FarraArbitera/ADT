/* NIM/Nama : miftahul mahfuzh
Nama file   : P04135105001.c
Topik       : matriks
Tanggal     : 25 september 2014
Deskripsi   : olah data matriks*/
 
#include "matriks.h"
/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Konstruktor membentuk MATRIKS *** */
void  MakeMATRIKS(int NB,int NK,MATRIKS *M) {
/* Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” memori */
/* I.S. NB dan NK adalah valid untuk memori MATRIKS yang dibuat */
/* F.S. MATRIKS M sesuai dengan definisi di atas terbentuk */
/*algoritma*/
	SetBrsEff(M,NB);
	SetKolEff(M,NK);
}

/* *** Selektor "DUNIA MATRIKS" *** */

indeks GetIdxBrsMin()
/* Mengirimkan indeks baris minimum MATRIKS apapun */
{
  /*kamus lokal*/
  /*algoritma*/
	return(BrsMin);
}

indeks GetIdxKolMin()
/* Mengirimkan indeks kolom minimum MATRIKS apapun */
{
  /*kamus lokal*/
  /*algoritma*/
	return(KolMin);
}

indeks GetIdxBrsMax()
/* Mengirimkan indeks baris maksimum MATRIKS apapun */
{
  /*kamus lokal*/
  /*algoritma*/
	return(BrsMax);
}

indeks GetIdxKolMax()
/* Mengirimkan indeks kolom maksimum MATRIKS apapun */
{
  /*kamus lokal*/
  /*algoritma*/
	return(KolMax);
}

boolean IsIdxValid (int i,int  j)
/* Mengirimkan true jika i, j adalah indeks yang valid */
{
  /*kamus lokal*/
  /*algoritma*/
	return((BrsMin <= i)&&(i <= BrsMax)&&(KolMin <= j)&&(j <= KolMax));
}

/* *** Untuk sebuah MATRIKS M yang terdefinisi: *** */
indeks FirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
  /*kamus lokal*/
  /*algoritma*/
	return(GetIdxBrsMin(M));
}

indeks FirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
  /*kamus lokal*/
  /*algoritma*/
    return(GetIdxKolMin(M));
}

indeks LastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
  /*kamus lokal*/
  /*algoritma*/
	return(FirstIdxBrs(M)+GetNBrsEff(M)-1);
}

indeks LastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
  /*kamus lokal*/
  /*algoritma*/
    return(FirstIdxKol(M)+GetNKolEff(M)-1);
}

indeks GetNBrsEff (MATRIKS M)
/* Mengirimkan banyaknya baris efektif M */
{
  /*kamus lokal*/
  /*algoritma*/
	return(M.NBrsEff);
}

indeks GetNKolEff (MATRIKS M)
/* Mengirimkan banyaknya kolom efektif M */
{
  /*kamus lokal*/
  /*algoritma*/
	return(M.NKolEff);
}

boolean IsIdxEff (MATRIKS M,indeks i,indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
  /*kamus lokal*/
  /*algoritma*/
	return((FirstIdxBrs(M)<=i)&&(i<=LastIdxBrs(M))&&(FirstIdxKol(M)<=j)&&(j<=LastIdxKol(M)));
}

el_type GetElmt (MATRIKS M,indeks i,indeks j)
/* Mengirimkan elemen M dg nomor baris i dan nomor kolom j */
{
  /*kamus lokal*/
  /*algoritma*/
	return(M.Mem[i][j]);
}

el_type GetElmtDiagonal (MATRIKS M,indeks i)
/* Mengirimkan elemen M(i,i) */
/* *** Operasi mengubah nilai elemen MATRIKS: Set / Assign *** */
{
  /*kamus lokal*/
  /*algoritma*/
	return(GetElmt(M,i,i));
}

void SetBrsEff (MATRIKS *M,int NB)
/* I.S. M sudah terdefinisi */
/* F.S. Nilai M.BrsEff diisi dengan NB, */
{
  /*kamus lokal*/
  /*algoritma*/
	(*M).NBrsEff= NB;
}

void SetKolEff (MATRIKS *M,int NK)
/* I.S. M sudah terdefinisi */
/* F.S. Nilai M.NKolEff diisi dengan NK */
{
  /*kamus lokal*/
  /*algoritma*/
	(*M).NKolEff = NK;
}

void SetEl (MATRIKS *M,int i,int j,el_type X)
/* I.S. M sudah terdefinisi */
/* F.S. M(i,j) bernilai X */
/* Proses: Mengisi M(i,j) dengan X */
{
  /*kamus lokal*/
  /*algoritma*/
	(*M).Mem[i][j] = X;
}

/* ********** Assignment MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn,MATRIKS *MHsl)
/* Melakukan assignment MHsl ← Min */
{
  /*kamus lokal*/
	indeks i,j;
  /*algoritma*/
	SetBrsEff(MHsl,GetNBrsEff(MIn));
	SetKolEff(MHsl,GetNKolEff(MIn));
	for(i=FirstIdxBrs(MIn);i<=LastIdxBrs(MIn);i++)
	  {
	  	for(j=FirstIdxKol(MIn);j<=LastIdxKol(MIn);j++)
	  		SetEl(MHsl,i,j,GetElmt(MIn,i,j));
	  }
}

/* ********** KELOMPOK BACA/TULIS ********** */

void BacaMATRIKS (MATRIKS *M,indeks NB,indeks NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK */
/* Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* dari pembacaan dengan traversal per baris */
{
  /*kamus lokal*/
	indeks i,j;
	el_type x;
  /*algoritma*/
	printf("\nmembaca inputan\n");
	for(i=FirstIdxBrs(*M);i<=LastIdxBrs(*M);i++)
	 {
	   for(j=FirstIdxKol(*M);j<=LastIdxKol(*M);j++)
         {
          printf("masukkan M[%d][%d] : ",i,j);
          scanf("%lf",&x);
          SetEl(M,i,j,x);
	     }
	 }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar*/
/* Menulis nilai setiap indeks dan elemen M ke layar dengan traversal per baris */
{
  /*kamus lokal*/	
	indeks i,j;
  /*algoritma*/
	for(i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++) {	
		for(j=FirstIdxKol(M);j<LastIdxKol(M);j++)
			printf("%.2f, ",GetElmt(M,i,j));
		printf("%.2f\n",GetElmt(M,i,LastIdxKol(M)));
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */

MATRIKS tambah (MATRIKS M1,MATRIKS M2)
/* PrekondisiM1 berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan MATRIKS: M1 + M2 */
{
  /*kamus lokal*/
	MATRIKS M;
	indeks i,j;
  /*algoritma*/
	MakeMATRIKS(GetNBrsEff(M1),GetNKolEff(M2),&	M);
	for(i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
	  {	
		for(j=FirstIdxKol(M);j<LastIdxKol(M);j++)
           {
             SetEl(&M,i,j,GetElmt(M1,i,j)+GetElmt(M2,i,j));
           }
	  }	
	return(M);  
}

MATRIKS kurang (MATRIKS M1,MATRIKS M2)
/* PrekondisiM berukuran sama dengan M */
/* Mengirim hasil pengurangan MATRIKS: salinan M1 – M2 */
{
  /*kamus lokal*/
	MATRIKS M;
	indeks i,j;
  /*algoritma*/
	MakeMATRIKS(GetNBrsEff(M1),GetNKolEff(M2),&M);
	for(i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
	  {	
		for(j=FirstIdxKol(M);j<LastIdxKol(M);j++)
           {
             SetEl(&M,i,j,GetElmt(M1,i,j)+GetElmt(M2,i,j));
           }
	  }	
	return(M);  
}

MATRIKS kalimatriks (MATRIKS M1,MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian MATRIKS: salinan M1 * M2 */
{
  /*kamus lokal*/
	MATRIKS M;
	el_type sum;
	indeks i,j,k;
  /*algoritma*/
	MakeMATRIKS(GetNBrsEff(M1),GetNKolEff(M2),&M);
	for(i=FirstIdxBrs(M1);i<=LastIdxBrs(M1);i++)
	  {	
		for(j=FirstIdxKol(M2);j<=LastIdxKol(M2);j++)
           {
           	 sum = 0;
           	 for(k=FirstIdxKol(M1);k<=LastIdxKol(M1);k++)
           	 	sum = sum + GetElmt(M1,i,k)*GetElmt(M2,k,j);
                SetEl(&M,i,j,sum);
           }
	  }	
	return(M);  
}

MATRIKS kalielemen (MATRIKS M,int X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
  /*kamus lokal*/
	MATRIKS M1;
	indeks i,j;
  /*algoritma*/
	MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M),&M);
	for(i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++)
	  {	
		for(j=FirstIdxKol(M);j<LastIdxKol(M);j++)
           {
             SetEl(&M1,i,j,GetElmt(M,i,j)*X);
           }
	  }	
	return(M1);  
}

void kali (MATRIKS *M,int K)
/* Mengalikan setiap elemen M dengan K */
{
  /*kamus lokal*/
	indeks i,j;
  /*algoritma*/
	MakeMATRIKS(GetNBrsEff(*M),GetNKolEff(*M),M);
	for(i=FirstIdxBrs(*M);i<=LastIdxBrs(*M);i++)
	  {	
		for(j=FirstIdxKol(*M);j<=LastIdxKol(*M);j++)
             SetEl(M,i,j,GetElmt(*M,i,j)*K);
	  }	 
}

int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
  /*kamus lokal*/
  /*algoritma*/
    return(GetNBrsEff(M)*GetNKolEff(M));
}

/* ********** Operasi lain ********** */

el_type RataNilai (MATRIKS M,indeks N)
/*Prekondisi: Matriks tidak kosong. */
/*Mengirimkan rata-rata nilai ujian ke-N */
{
  /*kamus lokal*/
    int i;
    double sum = 0;
  /*algoritma*/
	for(i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++) {
	  sum += GetElmt(M,i,N);
	}
	return(sum/GetNBrsEff(M));
}

indeks RataTestTertinggi (MATRIKS M) {
/*Prekondisi : Matriks tidak kosong */
/*Mengirim nomor test yang memiliki rata-rata kelas tertinggi*/
/*kamus lokal*/
  indeks j,jj;
  double max,temp;
/*algoritma*/
  max = RataNilai(M,FirstIdxKol(M)); jj=1;
  for(j=FirstIdxKol(M)+1;j<=LastIdxKol(M);j++) {
		temp = RataNilai(M,j);
		if(max < temp) {
			jj = j;
			max = temp;
 	  }
 	}
  return jj;	 
}

void TulisStatistikTest (MATRIKS M) {
/*I.S. : M terdefinisi, tidak kosong. */
/*F.S. : Untuk setip test yang pernah dilakukan ditayangkan nilai*/
/*terkecil dan terbesar yang diperoleh mahasiswa, berikut*/
/*nilai rata-rata dari seluruh mahasiswa.*/
/*Setiap baris menampilkan data statistik sebuah test. */
/*Proses : looping kolom, cari max dan min lewat looping baris */
/*lalu hasil max dan min per looping baris tadi di cetak melalui indeks kolom*/
/*tapi dicetaknya per baris*/
/*kamus lokal*/
  indeks i,j;
  el_type max,min,x;
/*algoritma*/
	for(j=FirstIdxKol(M);j<=LastIdxKol(M);j++) {
		max = GetElmt(M,FirstIdxBrs(M),j);
		min = GetElmt(M,FirstIdxBrs(M),j);
		for (i=FirstIdxBrs(M)+1;i<=LastIdxBrs(M);i++) {
			if (max < GetElmt(M,i,j))
			max = GetElmt(M,i,j);
			if (min < GetElmt(M,i,j))
	 		min = GetElmt(M,i,j);
	 	}
		x = RataNilai (M,j);
		printf("test [%d] : %.1lf, %.1lf, %.1lf \n",j,min,max,x);
	}	 
}

void TulisMatriks1 (MATRIKS M) {
/*I.S. : M terdefinisi, tidak kosong */
/*F.S. : Semua elemen matriks tertulis di layar.*/
/*Setiap baris akan menampilkan data satu mahasiswa, berupa:*/
/*Nomor urut, nilai untuk setiap test, dan rata-rata nilai dari*/
/*seluruh test. */
/*Proses : looping baris. cetak indeks, berikut data nilai melalui looping kolom*/
/*dalam looping kolom kita sematkan variabel untuk mencari nilai rata2*/ 
/*setelah looping kolom selesai [semua nilai di cetak], cetak nilai rata-rata*/
/*kamus lokal*/
  indeks i,j;
  el_type met;
  el_type sum;
/*algoritma*/
	for(i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++) {
	  printf("%d. ",i); sum=0;
	  for(j=FirstIdxKol(M);j<=LastIdxKol(M);j++) {
		  met = GetElmt(M,i,j);
	   	printf("%.1lf, ",met);
      sum += met;
	  }
	  printf("%.1lf \n",sum/GetNKolEff(M));
	}
}	
