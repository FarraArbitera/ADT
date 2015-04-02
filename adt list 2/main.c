//NIM/Nama : 13512017/Miftahul Mahfuzh
//Nama file : main.c
//Topik : List linier double pointer 
//Tanggal : 5 November 2014
//Deskripsi : List Linier berkait double pointer dengan first dan last

#include "list2.h"

int main()
{
	List L;
  infotype nilai;
	CreateList(&L);
  printf("**Set List L**\n");
  printf("Masukkan nilai L : \n");
				do{
					scanf("%d",&nilai);
					if (nilai != -999)
						InsVLast(&L,nilai);
				} while (nilai != -999);
    if (First(L)==Last(L)) {
      printf ("List Kosong\n");
    }
    else {
      printf("List L : ");
      PrintInfo(L);
      printf("\n");      
    }
	return 0;
}
