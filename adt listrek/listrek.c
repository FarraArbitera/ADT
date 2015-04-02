#include "listrek.h"

/* Manajemen Memori */

address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P;
	P = (address)malloc(sizeof(infotype));
	if (P != Nil)
	{
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

/* Pemeriksaan Kondisi List */

int IsEmpty(List L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
{
	if (IsListEmpty(L)) return 1;
	else return 0;
}

int IsOneElmt(List L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
/* Primitif-Primitif Pemrosesan List */
{
	if(NBElmtList(L)==1) return 1;
	else return 0;
}

infotype FirstElmt (List L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
{
	return Info(L);
}

List Tail(List L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
{
	return Next(L);
}

List Konso(infotype e, List L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. e dialokasi
terlebih dahulu. Jika alokasi gagal, mengirimkan L */
/* Fungsi dan Prosedur Lain */
{
	/*KAMUS LOKAL*/
	address P; 
	/*ALGORITMA*/
	P = Alokasi(e);
	if (P = Nil) return L;
	else
	{
		Next(P) = L;
		return P;
	}
}

 List Konsdot ( List L,infotype e)  
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhir */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
/* *** Predikat *** */
{
	if (IsEmpty(L))	return Alokasi(e);
	else
	{
		Next(L) =	Konsdot(Tail(L),e);
		return L;
	}
}

boolean IsListEmpty (List L)  
/* Mengirimkan true jika list kosong, false jika tidak kosong */
/* Mungkin yang dikirimkan adalah sebuah list kosong */
{
	return (L == Nil);
}

/* *** Operasi Lain *** */

List Copy (List L)  
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
{
	if (IsEmpty(L)) return Nil;
	else /* Rekurens */
	return Konso(FirstElmt(L),Copy(Tail(L)));
}

List Concat (List L1,List L2)  
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
{
	if (IsEmpty(L1))	return Copy(L2);
	else /* Rekurens */
	return Konso(FirstElmt(L1),Concat(Tail(L1),L2));
}

void PrintList (List L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
{
	/*ALGORITMA*/
	if (!IsEmpty(L))
	{	
		printf("%d\n",Info(L));
		PrintList(Next(L));
	}
}

int NBElmtList (List L)  
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
{
	if (IsEmpty(L)) return 0;
	else /* Rekurens */
	return 1 + NBElmtList(Next(L));
}

boolean Search (List L,infotype X)  
/* Mengirim true jika X adalah anggota list, false jika tidak */
{
	if (IsEmpty(L)) return false;
	else /* Rekurens */
	{
		if (Info(L) = X) return true;
		else return Search(Next(L),X);
	}
}