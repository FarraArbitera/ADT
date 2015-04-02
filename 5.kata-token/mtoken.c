/* NIM/Nama : 13513017
Nama file   : P05135100172.h
Topik       : mesin token
Tanggal     : 2 oktober 2014
Deskripsi   : meyeleksi token dan angka */

#include "kata.h"
int main() {
  /*algoritma*/	
  STARTKATA(0,"pitakar.txt");
  while (!EndKata) {
    if(ctoken.val<0) 
      printf("<'%c', -1>\n",ctoken.tkn);
    else 
      printf("<'b', %d>\n",ctoken.val);
    ADVKATA(0);
  }
  return 0;
}
