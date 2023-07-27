#include <stdio.h>

void main() {
int i,n;
char mystring[100];
char a[5];
FILE *outfile1;
FILE *outfile2;

outfile1 = fopen("out.txt","r");
i=0;
n=0;
fgets (mystring , 100 , outfile1); 
fclose(outfile1);

while(mystring[i]!='*')
{
if(mystring[i]==32)
{n++;}
i++;}

sprintf (a, "%d", n);

outfile2 = fopen("out1.txt","w");
fputs (a,outfile2);
fclose(outfile2);
}
  
