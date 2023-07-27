#include <stdio.h>

void main() {
int i;
char c;
FILE *outfile;

outfile = fopen("out.txt","r");
i=0;

 while (c != EOF)
{
  c = fgetc (outfile);
  i++;
}
fclose(outfile);


outfile = fopen("out.txt","w");
fprintf(outfile,"%d",i);
fclose(outfile);
}
  
