/* localtime example */
#include <stdio.h>
#include <time.h>
#include <string.h>

char Distime[50];
int main ()
{
  time_t rawtime;         /// time_t yek variable makhsuse time.h monaseb baraye zakhire kardane zaman o tarikh kamel kenare ham
  struct tm * timeinfo;   /// structure : chand variable kenare ham ast , struct tm : monaseb baraye zaman tm-sec tm-min ...

  time ( &rawtime );      /// & be maanaye addrese pointer
  timeinfo = localtime ( &rawtime );


//int n=0;
//while(Distime[n]!=NULL)
//{Distime[n] = asctime(timeinfo);
//n++;}  

  printf (  "Current local time and date: %s and length is :%d\n",  asctime (timeinfo),strlen(asctime (timeinfo) ));

  return 0;
}
