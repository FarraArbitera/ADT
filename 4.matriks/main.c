/* NIM/Nama : miftahul mahfuzh
Nama file   : P041351050m01.c
Topik       : matriks
Tanggal     : 25 september 2014
Deskripsi   : olah data matriks*/
#include "matriks.h"
int main()
{ 
 /*kamus lokal*/
   MATRIKS M;
   indeks nbk,nbb,i;
 /*algoritma*/
 /*membaca inputan*/
 printf("masukkan jumlah mahasiswa = ");
 scanf("%d",&nbb);
 printf("masukkan jumlah test yang dilakukan = ");
 scanf("%d",&nbk); 
 MakeMATRIKS(nbb,nbk,&M);
 BacaMATRIKS(&M,nbb,nbk);

 /*cetak output*/
 printf("\nmencetak matriks\n");
 TulisMATRIKS(M);

 /*cetak highest average*/
 i = RataTestTertinggi(M);
 printf("\nnilai tertinggi ada pada indeks ke-%d dengan rata-rata nilai : %.2lf\n",i,RataNilai(M,i));
 printf("\nmencetak statistik nilai (min-max-average)\n");
 TulisStatistikTest(M);
 printf("\nmencetak data per mahasiswa (no-data-average)\n");
 TulisMatriks1(M);
 return 0;
} 
