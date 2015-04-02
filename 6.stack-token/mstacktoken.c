#include "kata.h"
#include "stack.h"
int main() {
	Stack S;
	infotype op1,op2;
	char x;	
  /*algoritma*/
  CreateEmpty(&S);	
  STARTKATA(0,"pitakar.txt");
  while (!EndKata) {
    if(ctoken.val<0) {
    	Pop(&S,&op2);
    	Pop(&S,&op1); 
      x =ctoken.tkn;
      printf("%d %c %d\n",op1,x,op2);
      switch(x) {
      	case '*' : 
      				op1*=op2;
      				break;
      	case '/' : 
      				op1/=op2;
      				break;
      	case '+' : 
      				op1+=op2;
      				break;
      	case '-' : 
      				op1-=op2;
      }
      Push(&S,op1);
    } else Push(&S,ctoken.val);    	
    TulisStack(S);
    printf("\n");
    ADVKATA(0);
  } 
  if(IsEmpty(S)) printf("Ekspresi kosong\n");
  else printf("Hasil ekspresi: %d\n",InfoTop(S));
  return 0;
}