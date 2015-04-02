/*nama file : mesinkata1.h*/
/*miftahul mahfuzh [13513017]*/

#ifndef __kata_H__
#define __kata_H__
#include "mesinkar.h"
#define NMax 50
#define BLANK ' '

typedef struct {
char TabKata[NMax+1];
int Length;
} Kata;

typedef struct {
	char tkn; /*token yang dibaca*/
	int val;          /*nilai bilangan apabila tkn = ‘b’*/
} Token;

/* State Mesin Kata */
boolean EndKata;
Kata CKata;
Token ctoken;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(boolean kata,char file[10]);
/* I.S. : CC sembarang
F.S. : EndKata = true, dan CC = Mark;
atau EndKata = false, CKata adalah kata yang sudah
diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(boolean kata);
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */

void SalinToken();
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */

#endif