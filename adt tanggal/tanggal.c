#ifndef tanggal_H
#define tanggal_H
#include "stdio.h"
#include "math.h"

/*selektor get*/
#define Day(T) (T).DD
#define Month(T) (T).MM
#define Year(T) (T).YY
typestruct
{
 int DD;/*hari*/
 int MM;/*bulan*/
 int YY;/*tahun*/
} TANGGAL;

/*selektor set*/
void SetDay (TANGGAL *T,int newDay)
/*mengubah nilai komponen DD dari TT*/
{
/*KAMUS LOKAL*/

/*ALGORITMA*/
  Day(*T) = newDay;
}

void SetMonth(TANGGAL *T, int newMonth)
/*mengubah nilai komponen MM dari TT*/
{
/*KAMUS LOKAL*/

/*ALGORITMA*/
  Month(*T) = newMonth;
}


void SetYear(TANGGAL *T, int newYear)
/*mengubah nilai komponen YY dari TT*/
{
/*KAMUS LOKAL*/

/*ALGORITMA*/
  Year(T) = newYear;
}


/*validasi terhadap type*/
boolean IsTanggalValid (int D,int M,int Y)
/*mengirm true jika D,M,Y dapat membentuk TANGGAL yang valid*/
/*dipakai untuk mengetes sebelum membentuk sebuah tanggal*/
{
/*KAMUS LOKAL*/

/*ALGORITMA*/
  return false;
  if (Y > 0)
   {
    switch (M) 
     1:{
        if (0<D<32) 
         {return true;}
       }
     2:{
        if ((Y mod 4 = 0) && (Y mod 10 <> 0)) 
         {
           if (0<D<30) 
            {return true;} 
         }
        else
         {
           if (0<D<29)
            {return true;}
         }
       }
     3:{
        if (0<D<32) 
         {return true;}
       }
     4:{ 
        if(0<D<31) 
         {return true;}
       }
     5:{
        if (0<D<32) 
         {return true;}
       }
     6:{ 
        if(0<D<31) 
         {return true;} 
       }
     7:{
        if (0<D<32) 
         {return true;} 
       }
     8:{ 
        if(0<D<32) 
         {return true;} 
       }
     9:{
        if (0<D<31) 
         {return true;} 
       }
     10:{ 
        if(0<D<32) 
         {return true;}
        }
     11:{ 
        if(0<D<31) 
         {return true;} 
        }
     12:{
        if (0<D<32) 
         {return true;}         
        }     
    }   
}


/*defenisi dan spesifikasi konstruktor*/
TANGGAL MakeTANGGAL (int h, int b, int t)
/*membentuk TANGGAL dari tanggal h, bulan b, tahun t*/
/*prekondisi : h,b,t bisa membentuk TANGGAL yang valid*/
{
/*KAMUS LOKAL*/
  TANGGAL T;
/*ALGORITMA*/
  Day(T) = h;
  Month(T) = b;
  Year(T) = t;
  return(T);
}