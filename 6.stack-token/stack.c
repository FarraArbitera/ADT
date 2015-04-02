/* File : adtstack.c */
/*nama[nim] : miftahul mahfuzh[13513017]*/
/* Implementasi Stack dalam bahasa C dengan alokasi statik */
#include "stack.h"

void CreateEmpty(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{ /* Kamus Lokal */
/* Algoritma */
Top(*S) = Nil;
}

boolean IsEmpty (Stack S) {
/* Mengirim true jika Stack kosong: lihat definisi di atas */
/* Algoritma */
return (Top(S)==Nil);
}

boolean IsFull(Stack S) {
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
/* Algoritma */
return(Top(S)==MaxEl);
}

void Push (Stack *S, infotype X) {
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru, TOP bertambah 1 */
/* Algoritma */
Top(*S)++;
InfoTop(*S) = X;
}

void Pop (Stack *S, infotype *X) {
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
/* Algoritma */
*X = InfoTop(*S);
Top(*S)--;
}

void TulisStack (Stack S) {
/* Menuliskan isi S ke layar dari top ke bottom secara horizontal (ke samping, */ 
/* lihat contoh) dengan hanya memanfaatkan operasi‐operasi dasar stack */ 
/* I.S. S terdefinisi, mungkin kosong */ 
/* F.S. Isi S tertulis di layar dari top ke bottom. Di akhir penulisan, S */ 
/* kembali ke kondisi I.S. */ 
/* Jika S kosong, tuliskan “Stack kosong” */ 
	infotype x;
	Stack R;
	CreateEmpty(&R);
	while(!IsEmpty(S)) {
		Pop(&S,&x);
		printf("%d ",x);		
		Push(&R,x);
	} //R inverse S
	while(!IsEmpty(R)) {
		Pop(&R,&x);
		Push(&S,x);
	}	
}
void FilterStack (Stack * S) {
/* I.S. Stack S terdefinisi dan tidak kosong */ 
/* F.S. S hanya berisi bilangan genap dan 0, semua bilangan ganjil dibuang */ 
/* Urutan elemen S sesuai urutan semula S, tanpa elemen bilangan ganjil */ 
	infotype x;
	Stack R;
	CreateEmpty(&R);
	while(!IsEmpty(*S)) {
		Pop(S,&x);
		if(x%2==0) Push(&R,x);
	} //R inverse S
	while(!IsEmpty(R)) {
		Pop(&R,&x);
		Push(S,x);
	}
}

void InverseStack(Stack *S) {
	infotype x;	
	if(!IsEmpty(*S)) {
		Pop(S,&x);
		InverseStack(S);
		Push(S,x);
	}
}