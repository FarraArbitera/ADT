#include "list2.h"
/* ***************** PRIMITIF-PRIMITIF LIST ***************** */

/* *** TEST LIST KOSONG *** */

boolean IsListEmpty (List L) 
/* Mengirim true jika list kosong: First(L) = dummy@ dan Last(L) = dummy@ */
{ return (First(L) == Nil && Last(L) == Nil); }

/* *** PEMBUATAN LIST KOSONG *** */

void CreateList (List *L)
/* I.S. Sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
{
	First(*L) = Nil; 
	Last(*L) = Nil;
}

/* *** Manajemen Memori *** */

address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P;
	P = (address)malloc(sizeof(infotype));
	if (P != Nil)
	{
		Info(P) = X;
		Next(P) = Nil;
		Prev(P) = Nil;
	}
	return P;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{	free(*P);}

/* *** PENCARIAN SEBUAH ELEMEN LIST *** */

boolean FSearch (List L,address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
  address Pl;
  boolean ada = false;
  /*algoritma*/
  Pl = First(L);
  while(Pl != Nil && !ada)
  {
  	if (Pl == P) ada = true;
  	else Pl = Next(Pl);
  }
  return ada;
}

address Search (List L,infotype X) 
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tersebut */
/* Jika tidak ada, mengirimkan Nil */
{
	address P;
	/*algoritma*/
	P = First(L);
	while(P != Nil && Info(P) != X)
		P = Next(P);
	return P;
}

/* ***************** PRIMITIF BERDASARKAN NILAI ******************/

/* *** PENAMBAHAN ELEMEN *** */

void InsVFirst (List *L,infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan nilai
X jika alokasi berhasil */
{ 
	/* Kamus Lokal */
	address last,P;
	/* Algoritma */
	P = Alokasi(X);
	InsertFirst(L,P);
}



void InsVLast (List *L,infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan menambahkan elemen list di sebelum
elemen akhir (elemen sebelum elemen dummy) bernilai X
jika alokasi berhasil. */
/*Jika alokasi gagal: I.S. = F.S. */
{
	/*kamus lokal*/
	address P,Pl;
	/*algoritma*/
	P = Alokasi(X);
	if(P != Nil)
	{
		Pl = First(*L);
		if(Pl == Nil) InsVFirst(L,X);
		else
		{
			P = Last(*L);
			Next(P) = First(*L);
			while(Next(Pl) != First(*L)) Pl = Next(Pl);
			Next(Pl) = P;
		}
	}
}

/* *** PENGHAPUSAN ELEMEN *** */

void DelVFirst (List *L,infotype *X)
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus. nilai info disimpan pada X */
/*dan alamat elemen pertama didealokasi */
{
	address P;
	/*algoritma*/
	P = First(*L);
	(*X) = Info(P);
	First(*L) = Next(P);
}

void DelVLast (List *L,infotype *X)
/* I.S. List tidak kosong */
/* F.S. Elemen sebelum dummy dihapus nilai info disimpan pada X */
/*dan alamat elemen terakhir sebelum dummy di-dealokasi */
{
	address P;
	/*algoritma*/
	P = Last(*L);
	if(P == First(*L)) 
	{
		Last(*L) = Nil;
		First(*L) = Nil;
	}
	else
	{
		Last(*L) = Prev(P);
		Next(Last(*L)) = First(*L);
	}
	(*X) = Info(P);
	Dealokasi(&P);
}


/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */

/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */

void InsertFirst (List *L,address P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{ 
	/* Kamus Lokal */
	address last;
	/* Algoritma */
	if (IsListEmpty(*L)) Next(P) = P;
	else /* L tidak kosong */ 
	{
		last = First(*L);
		while (Next(last) != First(*L))
			last = Next(last);
		/* Next(last) = First(L) ==> elemen terakhir */
		Next(P) = First(*L);
		Next(last) = P;
	}
	First(*L) = P;
}

void InsertAfter (List *L,address P,address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//Kamus Lokal
	
	//Algoritma
	Next(P) = Next(Prec);
	Prev (Next(Prec)) = P;
	Next(Prec) = P;
	Prev (P) = Prec;
	
}

void InsertLast (List *L,address P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru, */
/*yaitu menjadi elemen sebelum dummy */
{
	//Kamus Lokal
	address Prec;
	//Algoritma
	if (IsListEmpty(*L)) {
		InsertFirst(L,P);
	}
	else {
		Prec = Prev(Last(*L));
		Next(P) = Nil;
		Next(Prec) = P;
		Prev (P) = Prec;
		Last(*L) = P;
	}
}


/* *** PENGHAPUSAN SEBUAH ELEMEN *** */

void DelFirst (List *L,address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	//Kamus Lokal
	
	//Algoritma
	(*P) = First(*L);
	if (First(*L) == Last(*L)) {
		First(*L) = Nil;
		Last(*L) = Nil;
	}
	else {
		First(*L) = Next(First(*L));
		Prev(First(*L)) = Nil;
		Next(*P) = Nil;
		Prev (*P) = Nil;
	}
}

void DelLast (List *L,address  *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir sebelum dummy pada list sebelum
penghapusan */
/*Elemen list berkurang satu (mungkin menjadi kosong) */
{ 
	(*P) = Last(*L);
	if (First(*L) == Last(*L)) { // 1 elemt
		First(*L) = Nil;
		Last(*L) = Nil;
	}
	else {
		Next(Prev(*P)) = Nil;
		Last(*L) = Prev(*P);
		Prev(*P) = Nil;
	}
}
void DelAfter ( List *L,address *Pdel,address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec) Pdel adalah alamat elemen list yang dihapus */
{
	(*Pdel) = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Prev(Next(Prec)) = Prec;
	Next(*Pdel) = Nil;
	Prev(*Pdel) = Nil;
}
/* ***************** PROSES SEMUA ELEMEN LIST ***************** */

void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list (kecuali dummy) diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
{ 
	/* Kamus Lokal */
	address P;
	/* Algoritma */
	if (IsListEmpty(L)) printf("List Kosong \n"); 
	else 
	{
		P = First(L);
		printf("List : \n");
		do 
		{
			printf("%d \n", Info(P));
			P = Next(P);
		} while (P != First(L));
	}	
}