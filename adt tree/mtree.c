#include "pohonbiner.h"
int main()
{
	/*kamus*/
	BinTree P;
	int X,i;
	/*algoritma*/
	MakeTree(1,Nil,Nil,&P);
	for (i=1;i<=3;i++)
		AddDaun(&P,i,i+1,false);

	AddDaunTerkiri(&P,-1);
	
	// cek print left-akar-right(menurun ke bawah)
	PrintInorder(P);

	DelDaunTerkiri(&P,&X);
	printf("\n");

	// cek is uner left
	if (IsUnerLeft(P)) printf("uner left\n");

	// cek is uner right
	if (IsUnerRight(P)) printf("uner right\n");
	
	// cek print left-right (menaik ke atas)-akar
	PrintPostorder(P);

	// cek skew left
	if(IsSkewLeft(P)) printf("kiri\n");
	else if (IsSkewRight(P)) printf("kanan\n");

	// cek level
	printf("%d\n",Level(P,4));
	
	//BuildTree(&Left(P));
	//DelDaunTerkiri(&P,&X);
	return 0;
}