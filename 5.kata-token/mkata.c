/*nama file : mainkata.c*/
/*miftahul mahfuzh [13513017]*/
#include "kata.h"
int main() 
{
  /*kamus*/
	int i,j;
	int d = 0; // hitungan diskon 10%
	int rg = 0; // jumlah kata regular
	int pj = 0; // jumlah kata panjang
	float by;
  /*algoritma*/
  printf("isi telegram :");
  STARTKATA();
  while (!EndKata) { 		
  	d += 1;
		if(CKata.Length < 10) rg += 1; 
		else pj += 1;  
		if (CKata.Length==5 && (CKata.TabKata[1] == 'T') && (CKata.TabKata[2] == 'I') && (CKata.TabKata[3] == 'T') && (CKata.TabKata[4] == 'I') &&  (CKata.TabKata[5] == 'K')) {
		  rg -= 1;
			printf(".");
		}
		else if (CKata.Length==4 && (CKata.TabKata[1] == 'K') && (CKata.TabKata[2] == 'O') && (CKata.TabKata[3] == 'M') && (CKata.TabKata[4] == 'A')) {
			rg -= 1;
			printf(",");
		} 
		else {
			printf(" "); 
			for (i=1;i<=CKata.Length;i++) printf("%c",CKata.TabKata[i]);
  	}
  	ADVKATA();
  }
  printf(".\nJumlah kata regular : %d\n",rg);
  printf("Jumlah kata panjang : %d\n",pj);
  by = rg * 1000 + pj * 1500 ;
  if (d > 10) by *= 0.9;
  printf("Biaya : %.0f\n",by);
  return 0;
}
