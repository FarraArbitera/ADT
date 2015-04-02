/* NIM/Nama : 13513017
Nama file   : P05135100171.c
Topik       : mesin token
Tanggal     : 2 oktober 2014
Deskripsi   : meyeleksi token dan angka */

#include "kata.h"

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC ≠ BLANK atau CC = MARK */
{
  /* Algoritma */
  while ((CC == BLANK || CC == EOL) && (CC != MARK)) 
    ADV();
  /* CC != BLANK or CC = MARK */
}

void STARTKATA(boolean kata,char file[10])
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = Mark;
       atau EndKata = false, CKata adalah kata yang sudah
diakuisisi, CC karakter pertama sesudah karakter terakhir kata
jika ingin menggunakan SalinKata, input boolean kata = true, else false*/  
{ 
  /* Algoritma*/
  START(file);
  IgnoreBlank();
  if (CC == MARK) 
    EndKata = true;
  else 
   {/* CC != MARK */
    EndKata = false;
    if(kata) SalinKata();
    else SalinToken();
   }
}

void ADVKATA(boolean kata)
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  /* Algoritma*/
  IgnoreBlank();
  if (CC == MARK) 
    EndKata = true;
  else /* CC != MARK */ 
  if(kata) SalinKata();
  else SalinToken();
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
{
  /* Kamus Lokal */
  int i = 1; /* inisialisasi */
  /* Algoritma*/
  for (;;) 
  {
    CKata.TabKata[i] = CC;
    ADV();
    if ((CC == MARK) || (CC == BLANK) || (CC == EOL))
      break;
    else
      i++;
  } /* CC = MARK or CC = BLANK */
  CKata.Length = i;
}

void SalinToken(){
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
  /* Kamus Lokal */
  int i = 1; /* inisialisasi */
  /* Algoritma*/
  ctoken.val = 0; 
  if (CC < '0') { 
    ctoken.val--;
    ctoken.tkn = CC;
    ADV();
  } 
  else {
    for (;;) {
      ctoken.val = ctoken.val*10+(CC - '0');
      ADV();
      if ((CC == MARK) || (CC == BLANK || CC == EOL))
        break;
      else
        i++;
    } /* CC = MARK or CC = BLANK */
  }
}
