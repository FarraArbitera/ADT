/*nama file : tabel1.c*/
/*miftahul mahfuzh [13513017]*/
/*berisi semua algoritma pemrosesan tabel integer*/
/*penempatan elemen selalu input kiri*/
/*dinamik implisit*/

#include "tabel4.h"

/*KONSTRUKTOR*/
void MakeEmpty(TabInt *T, int N)
/*I.S : sembarang*/
/*F.S : terbentuk tabel T */
{
 /*kamus lokal*/

 /*algoritma*/
   (*T).TI = (ElType*)malloc((N+1)*sizeof(ElType));
   for(i=0; i<=N; i++)
    (*T).TI[i]=ValUndef;
   T.Size = N;
}

/*SELEKTOR*/
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{ 
 /*kamus lokal*/
   int i;
 /*algoritma*/
   i = GetFirstIdx(T);
   while(GetElmt(T,i) != ValUndef)
    i++;
   return(i-1);
}

/*daya tampung container*/
int MaxNbEl(TabInt T)
/*mengirimkan maksimum elemen yang ditampung oleh tabel*/
{
 /*kamus lokal*/

 /*algoritma*/
   return(T.Size);
}

/*selektor INDEKS*/
IdxType GetFirstIdx(TabInt T)
/*I.S : Tabel T tidak kosong*/
/*mengirimkan indeks elemen pertama*/
{
 /*kamus lokal*/

 /*algoritma*/
   return(IdxMin);
}

IdxType GetLastIdx(TabInt T)
/*I.S : Tabel T tidak kosong*/
/*mengirimkan indeks elemen terakhir*/
{
 /*kamus lokal*/

 /*algoritma*/
   return(IdxMin+NbElmt(T)-1);
}

/*menghasilkan sebuah elemen*/
ElType GetElmt (TabInt T,IdxType i) 
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
 /*kamus lokal*/

 /*algoritma*/
   return(T.TI[i]);
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */

void SetTab (TabInt Tin,TabInt *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
 /*kamus lokal*/
   int i;
 /*algoritma*/
   for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++)
    SetEl(Tout,i,GetElmt(Tin,i));
}

void SetEl (TabInt *T,IdxType i,ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
 /*kamus lokal*/

 /*algoritma*/
   (*T).TI[i] = v;
}


/* ********** Test Indeks yang valid ********** */

boolean IsIdxValid (TabInt T,IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
 /*kamus lokal*/

 /*algoritma*/
   if((i >= GetFirstIdx(T)) && (i <= MaxNbEl(T)))
     return true;
   else
   	return false;
}

boolean IsIdxEff (TabInt T,IdxType i) 
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
 /*kamus lokal*/

 /*algoritma*/
   if((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)))
     return true;
   else 
   	 return false;
}


/* ********** TEST KOSONG/PENUH ********** */

/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
 /*kamus lokal*/

 /*algoritma*/
   if(NbElmt(T)==0)
   	return true;
   else 
   	return false;
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T) 
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
 /*kamus lokal*/

 /*algoritma*/
   if(NbElmt(T)==MaxNbEl(T))
   	 return true;
   else 
   	 return false;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt *T)
/* I.S. sembarang */
/* F.S. tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
{
 /*kamus lokal*/
   IdxType last;
   IdxType v,i;
 /*algoritma*/
   printf("masukkan kapasitas Tabel : ");
   scanf("%d",&v);
   MakeEmpty(T,v);
   printf("masukkan jumlah elemen : ");
   scanf("%d",&last);
   for(i=GetFirstIdx(*T);i<=last;i++)
	  {
		 printf("%d. ",i);
		 scanf("%d",&(*T).TI[i]);
	  }
}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
 /*kamus lokal*/
   int i;
 /*algoritma*/
   if(~IsEmpty(T))
   {
     for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++)
		   printf("%d. %d\n",i,GetElmt(T,i));
	 } 
   else
   	 printf("Tabel kosong\n");

}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung
siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1, e2, ... ,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 : [1, 20, 30] */
/* Jika tabel kosong : menulis [] */
{
 /*kamus lokal*/
   int i;
 /*algoritma*/
	for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++)
	{
		printf("[");
		for(i=GetFirstIdx(T);i<GetLastIdx(T);i++)
		 {
		 	printf("%d, ",GetElmt(T,i));
		 }
		printf("%d]\n",GetElmt(T,GetLastIdx(T)));
	}

}


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1,TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
{
 /*kamus lokal*/
   TabInt T;
   int i;
 /*algoritma*/
	for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++)
      T.TI[i] = GetElmt(T1,i) + GetElmt(T2,i);
	T.Size = T1.Size; 
	return(T);
}

TabInt MinusTab (TabInt T1,TabInt T2) 
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
{
 /*kamus lokal*/
   TabInt T;
   int i;
 /*algoritma*/
  MakeEmpty(T,T1.Size);
	for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++)
      T.TI[i] = GetElmt(T1,i) - GetElmt(T2,i); 
	return(T);

}

TabInt KaliTab (TabInt T1,TabInt T2) 
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama
dikalikan */
{
 /*kamus lokal*/
   TabInt T;
   int i;
 /*algoritma*/
  MakeEmpty(T,T1.Size); 
	for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++)
      T.TI[i] = GetElmt(T1,i) * GetElmt(T2,i);
	return(T);

}

TabInt KaliKons (TabInt Tin,ElType c) 
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
 /*kamus lokal*/
   TabInt T;
   int i;
 /*algoritma*/   
  MakeEmpty(T,T1.Size);
	for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++)
      T.TI[i] = GetElmt(Tin,i) * c;
	return(T);

}

/* ********** OPERATOR RELASIONAL ********** */

/* *** Operasi pembandingan tabel : < =, > *** */

boolean IsEQ (TabInt T1,TabInt T2) 
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua
elemennya sama */
{
 /*kamus lokal*/
   int i,ls;
 /*algoritma*/
   i = 1;
   if(NbElmt(T1) == NbElmt(T2))
    {
      while((GetElmt(T1,i) == GetElmt(T2,i)) && (i < NbElmt(T1)))
       	i++;
      ls = GetLastIdx(T1); 
      if((i==ls)&&(GetElmt(T1,ls) == GetElmt(T2,ls)))
        return true;	
      else
      	return false;
    }
   else
   	return false;
}

boolean IsLess (TabInt T1,TabInt T2) 
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
 /*kamus lokal*/
   int i,ls;
 /*algoritma*/
   i = 1;
   if(NbElmt(T1) == NbElmt(T2))
    {
      while((GetElmt(T1,i) < GetElmt(T2,i)) && (i < NbElmt(T1)))
       	  i++;
      ls = GetLastIdx(T1); 
      if((i==ls)&&(GetElmt(T1,ls) < GetElmt(T2,ls)))
        return true;	
      else
      	return false;
    }
   else
   	return false;
}

/* ********** SEARCHING ********** */
/* *** Perhatian : Tabel boleh kosong!! *** */

IdxType Search1 (TabInt T,ElType X) 
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
 /*kamus lokal*/
   int i;
 /*algoritma*/
	if(IsEmpty(T))
		return(IdxUndef);
	else
	 {
	 	i = IdxMin;
	    while((X != GetElmt(T,i)) && (i < NbElmt(T)))
	     {/*mencari indeks i yang tepat*/
		    i++;
		   }
        /*cari X di T[last]*/
		if(X != GetElmt(T,i))
           return(IdxUndef);
		else
		 {	
		   if((X == GetElmt(T,i)) && (i == GetLastIdx(T)))
		 	 return(i);
		   else
		   	 return(i-1);
		 }
	 }
}

IdxType Search2 (TabInt T,ElType X) 
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
 /*kamus lokal*/
   int i;
   boolean Found;
 /*algoritma*/
   if(~IsEmpty(T))
    {
      Found = false;
      i = GetFirstIdx(T);
	  while((~Found) && (i<=NbElmt(T)))
	   {
         if(X == GetElmt(T,i))
      	   Found = true;
         i++;
	   }
	  if(Found)
	    return(i-1);
	  else
	    return(IdxUndef);
    }
   else
   	 return(IdxUndef);
}

boolean SearchB (TabInt T,ElType X) 
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai Skema search DENGAN boolean */
{
 /*kamus lokal*/
 int i;
   boolean Found;
 /*algoritma*/
    if (~IsEmpty(T))
    {
       Found = false;
       i = GetFirstIdx(T);
	     while((~Found) && (i<=NbElmt(T)))
	     {
        if(X == GetElmt(T,i))
          Found = true;
        i++;
	     }
	     if(Found)
	       return(true);
	     else
	       return(false);
    }
    else
      return(false);
}

IdxType SearchSentinel (TabInt T,ElType X) 
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C yang
tidak dipakai dalam definisi tabel */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
{
 /*kamus lokal*/; 
   int i;
 /*algoritma*/
   /*inisialisasi awal*/
   i = GetLastIdx(T);
   SetEl(&T,GetFirstIdx(T)-1,X);

   /*searching*/
   while(GetElmt(T,i) != X)
   	 i--;

   /*if-else*/
   if(i == 0)
     return(IdxUndef);
   else
     return(i);
}

/* ********** NILAI EKSTREM ********** */

ElType ValMax (TabInt T) 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
 /*kamus lokal*/
   ElType mx;
   int i;
 /*algoritma*/
   mx =  T.TI[IdxMin];
   for (i=IdxMin + 1;i<=GetLastIdx(T);i++)
   {
     if(mx < GetElmt(T,i))
       mx = GetElmt(T,i);
   }
   return (mx);
}

ElType ValMin (TabInt T) 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
{
 /*kamus lokal*/
   ElType mn;
   int i;
 /*algoritma*/
   mn =  T.TI[IdxMin];
   for (i=IdxMin + 1;i<=GetLastIdx(T);i++)
   {
     if(mn > T.TI[i])
       mn = T.TI[i];
   }
   return (mn);
}

IdxType IdxMaxTab (TabInt T) 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
{
 /*kamus lokal*/
   ElType mxi;
   int i;
 /*algoritma*/
   mxi =  GetFirstIdx(T);
   for (i = GetFirstIdx(T) + 1;i <= GetLastIdx(T); i++)
   {
     if(GetElmt(T,mxi) < GetElmt(T,i))
       mxi = i;
   }
   return (mxi);
}

IdxType IdxMinTab (TabInt T) 
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
{
 /*kamus lokal*/
   ElType mni;
   int i;
 /*algoritma*/
   mni =  GetFirstIdx(T);
   for (i = GetFirstIdx(T) + 1;i <= GetLastIdx(T); i++)
   {
     if(GetElmt(T,mni) > GetElmt(T,i))
       mni = i;
   }
   return (mni);
}


/* ********** OPERASI LAIN ********** */

void CopyTab (TabInt Tin,TabInt *Tout)
/* I.S. sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
 /*kamus lokal*/
   int i;
 /*algoritma*/
   for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++);
    SetEl(Tout,i,GetElmt(Tin,i));
}

TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
 /*kamus lokal*/
  int i,j;
  TabInt Tl;
 /*algoritma*/	
 if(IsEmpty(T1))
 	SetEmpty(Tl,T.Size);
 else
  {
  	j = GetLastIdx(T);
    for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
    {
      SetEl(Tl,j,GetElmt(T,i));
      j--;	
    }
  }
 return(Tl);  
}

boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*elemen pertama = elemen terakhir, */
/*elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
  /*kamus lokal*/
	int i,j;
  /*algoritma*/
    if(IsEmpty(T))
      return(true);
    else
      {
      	i = GetFirstIdx(T);
      	j = GetLastIdx(T);
      	while((i<(NbElmt(T)/2)) && (GetElmt(T,i)==GetElmt(T,j)))
         {
         	i++;
         	j--;
         }
        if(GetElmt(T,i)!=GetElmt(T,j))
          return(false);
        else
          return(true);
      }
}

/* ********** SORTING ********** */

void MaxSortDesc (TabInt *T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses mengurutkan T sehingga elemennya menurun/mengecil */
/*tanpa menggunakan tabel kerja */
{
  /*kamus lokal*/
	IdxType i,j;
    ElType tmp,mx;
    IdxType mxidx;
  /*algoritma*/
    j = GetFirstIdx(*T);
    for(i=GetFirstIdx(*T);i<=GetLastIdx(*T)-1;i++)
      {
      	mx = GetElmt(*T,i);
      	mxidx = i;
      	for (j=i+1; j <= GetLastIdx(*T); i++)
      	{
      	  if(GetElmt(*T,j) > mx) {
      	  	mx = GetElmt(*T,j);
      	    mxidx = j;
      		}      	  	
      	}
      	tmp = GetElmt(*T,i);
      	SetEl(T,i,mx);
      	SetEl(T,mxidx,tmp);               
      }
}
void InsSortAsc (TabInt *T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses mengurutkan T sehingga elemennya menaik/membesar */
/*tanpa menggunakan tabel kerja */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
{
  /*kamus lokal*/
	IdxType i,j;
    ElType tmp,mx;
    IdxType mxidx;
  /*algoritma*/
    j = GetFirstIdx(*T);
    for(i=GetFirstIdx(*T);i<=GetLastIdx(*T)-1;i++)
      {
      	mx = GetElmt(*T,i);
      	mxidx = i;
      	for (j=i+1; j <= GetLastIdx(*T); i++)
      	{
      	  if(GetElmt(*T,j) < mx) {

      	  } {
      	  	mx = GetElmt(*T,j);
      	    mxidx = j;
      		}      	  	
      	}
      	tmp = GetElmt(*T,i);
      	SetEl(T,i,mx);
      	SetEl(T,mxidx,tmp);               
      }
}

void AddAsLastEl (TabInt *T,ElType X)
/* Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* Proses Menambahkan sebagai elemen ke-i yang baru */
{
  /*kamus lokal*/
  /*algoritma*/
    T.Size++;
    SetEl(T,GetLastIdx(*T),X);	
}

void AddEli (TabInt *T,ElType X ,IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas terhadap
elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses Geser elemen ke-i+1 s.d. terakhir */
/*Isi elemen ke-i dengan X */
{
  /*kamus lokal*/
	int j;
 /*algoritma*/	
       	 if(i < GetLastIdx(*T))
   	      {/*berarti bukan T[last] yang kosong*/
            for(j = GetLastIdx(*T); j > i; j--)
            /*menggeser elmt tabel, mengosongkan T[i]*/
              {SetEl(T,j,GetElmt(*T,j-1));}
            SetEl(T,i,X);
          }
         else
          {/*T[last] yang kosong*/
            SetEl(T,i+1,GetElmt(*T,i));
            SetEl(T,i,X);
          }	
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt *T,ElType *X )
/* Proses Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*Banyaknya elemen tabel berkurang satu */
/*Tabel T mungkin menjadi kosong */
{
  /*kamus lokal*/
  /*algoritma*/
    (*X) = GetElmt(*T,GetLastIdx(T));	
}

void DelEli(TabInt *T,IdxType i ,ElType *X )
/* Proses Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. Elemen T berkurang satu */
/*Banyaknya elemen tabel berkurang satu */
/*Tabel T mungkin menjadi kosong */
/* Proses Geser elemen ke-i+1 s.d. elemen terakhir */
/*Kurangi elemen efektif tabel */
{
  /*kamus lokal*/
   int i,j;
 /*algoritma*/
     /*seleksi elemen terakhir*/
     if(i<GetLastIdx(*T))
      {/*jika bukan di LastIdx, maka lakukan pergeseran nilai*/
   	    for(j=i;j=GetLastIdx(*T);j++);
   	     SetEl(T,j-1,GetElmt(*T,j));
      }
    }
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */

void AddElUnik (TabInt *T ,ElType X )
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik*/
/* I.S. Tabel boleh kosong, tetapi tidak penuh */
/*dan semua elemennya bernilai unik, tidak terurut*/
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, jika belum ada
elemen yang bernilai X. Jika sudah ada elemen tabel yang bernilai X maka I.S. =
F.S. dan dituliskan pesan "nilai sudah ada" */
/* Proses Cek keunikan dengan sequential search dengan sentinel*/
/*kemudian tambahkan elemen jika belum ada */
{
  /*kamus lokal*/
	int i;
  /*algoritma*/
    if(IsEmpty(*T))
      {
      	SetEl(T,1,X);
      }	
     else
      { 
      	SetEl(T,GetFirstIdx(*T)-1,X);
        i = GetLastIdx(*T);
        while(i>=GetFirstIdx(*T)-1)
         {
           i--;	
         }
        if(i<GetLastIdx(*T))
         {
           SetEl(T,GetLastIdx(*T),X);
         }
        else
         printf("nilai sudah ada");
      }
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* PrekondisiTabel boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
 /*kamus lokal*/
    boolean Found; 
    int i;
 /*algoritma*/
	if (IsEmpty(T))
	 {
	 	return(IdxUndef);
	 }
	else
	 {
        Found = false;
        i = GetLastIdx(T);
        while((i >= 0) && (~Found))
         {
   	       if (GetElmt(T,i) == X)
            Found = true;
   	     }
   	    i--;
     
    if (i == 0)
     return(IdxUndef);   
    else
     return(i+1);
    }
}

ElType Max(TabInt T)
/* Prekondisi Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel*/
{
 /*kamus lokal*/
   ElType mx;
   int i;
 /*algoritma*/
   mx =  T.TI[IdxMin];
   for (i=IdxMin + 1;i<=GetLastIdx(T);i++)
   {
     if (mx < GetElmt(T,i))
     {
     	mx = GetElmt(T,i);
     }
   }
   return (mx);
}

ElType Min (TabInt T)
/* Prekondisi Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
 /*kamus lokal*/
   ElType mn;
   int i;
 /*algoritma*/
   mn =  GetElmt(T,GetFirstIdx(T)); 
   /*mn diisi oleh elemen pertama T*/
   for (i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++) 
   {/*looping dari nilai kedua T - Nilai terakhir T*/
     if (mn > GetElmt(T,i))/*jika mn > T[i]*/
     {
     	mn = GetElmt(T,i);/*mn <-- T[i]*/
     }
   }
   return (mn);
}

duo MaxMin (TabInt T)
/* Prekondisi Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum dan minimum pada tabel */
{
 /*kamus lokal*/
    duo TT;
 /*algoritma*/
	TT.E1 = Max(T);
	TT.E2 = Min(T);
	return(TT);

}

void Add1Urut (TabInt *T ,ElType X )
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel boleh kosong, boleh penuh. */
/* Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/* Jika tabel penuh, maka tabel tetap. */
/* Proses Search tempat yang tepat sambil geser */
/* Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
 /*kamus lokal*/
   int i,j;
 /*algoritma*/
   if(~IsFull(*T))
   {
   	 if(IsEmpty(*T))
   	  {
       SetEl(T,1,X);
   	  }
     else
   	  {
   	   /*algoritma searching*/
       i = GetFirstIdx(*T);
       while((X < GetElmt(*T,i)) && (i < GetLastIdx(*T)))
        {/*looping selama X < T[i] dan i < T[last]*/
       	 /*pencarian i yang tepat*/
          i++;
        }
       i--;
       AddEli(T,X,i);
      }
    }
}

void Del1Urut (TabInt *T,ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/* maka banyaknya elemen tabel berkurang satu. */
/* Jika tidak ada yang bernilai X, tabel tetap. */
/* Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses Search indeks ke-i dengan elemen ke-i=X. */
/* Delete jika ada. */
{
 /*kamus lokal*/
   int i,j;
 /*algoritma*/
   i = GetFirstIdx(*T);
   while((i<GetLastIdx(*T)) && (GetElmt(*T,i) == X))
    {/*pencarian indeks i yang tepat*/
   	 i++;
    }
   i--; 
   DelEli(T,X,i);
}