#include <stdio.h>

void main() {
int i;
char mystring[100];
FILE *outfile1;
FILE *outfile2;

outfile1 = fopen("out.txt","r");
i=0;

fgets (mystring , 100 , outfile1); 
fclose(outfile1);


outfile2 = fopen("out1.txt","w");
fputs (mystring,outfile2);
fclose(outfile2);
}
  
