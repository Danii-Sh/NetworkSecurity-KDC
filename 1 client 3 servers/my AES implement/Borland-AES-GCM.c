//#include <iostream>
#include <stdio.h>
//#include <conio.h>



char a[16];



const int plain1[16]={0xd9,0x31,0x32,0x25,0xf8,0x84,0x06,0xe5,0xa5,0x59,0x09,0xc5,0xaf,0xf5,0x26,0x9a};
const int plain2[16]={0x86,0xa7,0xa9,0x53,0x15,0x34,0xf7,0xda,0x2e,0x4c,0x30,0x3d,0x8a,0x31,0x8a,0x72};
const int plain3[16]={0x1c,0x3c,0x0c,0x95,0x95,0x68,0x09,0x53,0x2f,0xcf,0x0e,0x24,0x49,0xa6,0xb5,0x25};
const int plain4[16]={0xb1,0x6a,0xed,0xf5,0xaa,0x0d,0xe6,0x57,0xba,0x63,0x7b,0x39,0x1a,0xaf,0xd2,0x55};
const int key[16]={0xfe,0xff,0xe9,0x92,0x86,0x65,0x73,0x1c,0x6d,0x6a,0x8f,0x94,0x67,0x30,0x83,0x08};
const int AAD=0;
const int IV[12]={0xca,0xfe,0xba,0xbe,0xfa,0xce,0xdb,0xad,0xde,0xca,0xf8,0x88};   ///araye 3*4
const int sbox[16][16]={
   {0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76},
   {0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0},
   {0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15},
   {0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75},
   {0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84},
   {0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf},
   {0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8},
   {0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2},
   {0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73},
   {0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb},
   {0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79},
   {0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08},
   {0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a},
   {0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e},
   {0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf},
   {0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16}};

int crypted1[16], crypted2[16],crypted3[16],crypted4[16],Hash[16],Tag[16],GHASH[16];
int temp[16],temp1[16];
int tempkey[16],tempkey1[16];
int c1,c2,c3,c4;
int Y[16];
void subbytes();
void shiftrows();
void arrayXOR();
void mixcolumns();
void ExpandKey();
int GFmul(int,int);
void GFmul128();
void AES();
void buildTag();

void main()

{




//cout<<"";

//cout<<"+ GCM";


printf("AES::Rijndael \n");

////**************/start/**********\\\\\\\\\\\\\\

//cout<<"\n";


c1=0;
while(c1!=12)
{ Y[c1]=IV[c1];
c1++;
}
while(c1!=15)
{ Y[c1]=0;
c1++;
}
Y[c1]=1;


c1=0;
while(c1!=16)
{temp[c1]=Y[c1];
c1++;}
AES();                                      ////////////   AES (Y0)
c1=0;
while(c1!=16)
{Tag[c1]=temp[c1];
c1++;}



c1=0;
while(c1!=16)
{temp[c1]=0;
c1++;}
AES();                                      ////////////Hash
c1=0;
while(c1!=16)
{Hash[c1]=temp[c1];
c1++;}


Y[15]++;
c1=0;
while(c1!=16)
{temp[c1]=Y[c1];
c1++;}
AES();                                      ////////////2222222222
c1=0;
while(c1!=16)
{crypted1[c1]=temp[c1]^plain1[c1];
c1++;}


Y[15]++;
c1=0;
while(c1!=16)
{temp[c1]=Y[c1];
c1++;}                                        ////////3333333333
AES();
c1=0;
while(c1!=16)
{crypted2[c1]=temp[c1]^plain2[c1];
c1++;}


Y[15]++;
c1=0;
while(c1!=16)
{temp[c1]=Y[c1];
c1++;}                                       //////////444444444
AES();
c1=0;
while(c1!=16)
{crypted3[c1]=temp[c1]^plain3[c1];
c1++;}


Y[15]++;
c1=0;
while(c1!=16)
{temp[c1]=Y[c1];
c1++;}                                     ////////////55555555555
AES();
c1=0;
while(c1!=16)
{crypted4[c1]=temp[c1]^plain4[c1];
c1++;}



buildTag();                      /////////Tag Tag Tag Tag Tag Tag  ::m=0 ==> ma faghat niaz be GHASH (i=m+1,...,n+m+1)






c2=0;

while(c2!=16)
{
sprintf(a,"%x",crypted1[c2]);      /////change to temp::or::tempkey
if(a[1]==0)
{printf("0 ");}
printf("%s ",a);
c2++;
}

printf("\n ");

c2=0;

while(c2!=16)
{
sprintf(a,"%x",crypted2[c2]);      /////change to temp::or::tempkey
if(a[1]==0)
{printf("0 ");}
printf("%s",a);
c2++;
}
printf("\n ");
c2=0;

while(c2!=16)
{
sprintf(a,"%x",crypted3[c2]);      /////change to temp::or::tempkey
if(a[1]==0)
{printf("0 ");}
printf("%s ",a);
c2++;
}
printf("\n ");
c2=0;

while(c2!=16)
{
sprintf(a,"%x",crypted4[c2]);      /////change to temp::or::tempkey
if(a[1]==0)
{printf("0 ");}
printf("%s ",a);
c2++;
}

printf("\n ");
c2=0;

while(c2!=16)
{
sprintf(a,"%x",Tag[c2]);      /////change to temp::or::tempkey
if(a[1]==0)
{printf("0 ");}
printf("%s ",a);
c2++;
}

printf("\n ");
// getchar();

}







 ////Extra  Functions
void AES()
{

c1=0;
while(c1!=16)
{tempkey[c1]=key[c1];
c1++;}


c3=0;
while(c3<10)
{
arrayXOR();

subbytes();

shiftrows();
if(c3!=9)
{
mixcolumns();
}
ExpandKey();

if(c3==9)
{arrayXOR();}
c3++;
}


}




void subbytes()
{
int x,y;

c1=0;
while(c1!=16)
{

x=temp[c1]>>4;
y=(temp[c1] & 15);

temp[c1]= sbox[x][y];
c1++;
}
}


void arrayXOR()
{
c1=0;
while(c1!=16)
{
temp[c1]=temp[c1]^tempkey[c1];
c1++;
}
}


void shiftrows()
{
c1=0;
while(c1!=16)
{temp1[c1]=temp[c1];
c1++;}

temp[13]=temp1[1];
temp[9]=temp1[13];
temp[5]=temp1[9];       ////2nd row
temp[1]=temp1[5];

temp[10]=temp1[2];
temp[6]=temp1[14];
temp[14]=temp1[6];      ////3d row
temp[2]=temp1[10];

temp[7]=temp1[3];
temp[11]=temp1[7];
temp[15]=temp1[11];     ////4d row
temp[3]=temp1[15];


}

void mixcolumns()
{
c1=0;

while(c1<16)
{
if(c1%4==0)
{temp1[c1]=(GFmul(0x03,temp[c1+1]))^(GFmul(0x02,temp[c1]))^(temp[c1+2])^(temp[c1+3]);
}

if(c1%4==1)
{temp1[c1]=(GFmul(0x03,temp[c1+1]))^(GFmul(0x02,temp[c1]))^(temp[c1+2])^(temp[c1-1]);
}

if(c1%4==2)
{temp1[c1]=GFmul(0x03,temp[c1+1])^GFmul(0x02,temp[c1])^(temp[c1-1])^(temp[c1-2]);
}

if(c1%4==3)
{temp1[c1]=GFmul(0x03,temp[c1-3])^GFmul(0x02,temp[c1])^(temp[c1-2])^(temp[c1-1]);
}
c1++;
}
c1=0;
while(c1!=16)
{temp[c1]=temp1[c1];
c1++;}

}

int GFmul(int x,int y)
{
int z=0;
int w;
c4=0;
while(c4<8)
{
w=y<<c4;
if((x &(1<<c4))>0)
{
if(w>255)
{w=w^0x1b;
w=w & 255;
}
z= w ^ z;
}
c4++;
}
return z;
}

void ExpandKey()
{
int x,y;

tempkey1[3]=tempkey[12];
tempkey1[0]=tempkey[13];
tempkey1[1]=tempkey[14];
tempkey1[2]=tempkey[15];





c1=0;
while(c1<4)
{
x=tempkey1[c1]>>4;
y=(tempkey1[c1] & 15);

tempkey1[c1]= sbox[x][y];

c1++;
}


switch(c3){
case 0 :tempkey1[0]=tempkey1[0]^0x01; break;
case 1 :tempkey1[0]=tempkey1[0]^0x02; break;
case 2 :tempkey1[0]=tempkey1[0]^0x04; break;
case 3 :tempkey1[0]=tempkey1[0]^0x08; break;
case 4 :tempkey1[0]=tempkey1[0]^0x10; break;
case 5 :tempkey1[0]=tempkey1[0]^0x20; break;
case 6 :tempkey1[0]=tempkey1[0]^0x40; break;
case 7 :tempkey1[0]=tempkey1[0]^0x80; break;
case 8 :tempkey1[0]=tempkey1[0]^0x1b; break;
case 9 :tempkey1[0]=tempkey1[0]^0x36; break; }







c1=0;
while(c1<4)
{
tempkey1[c1]=tempkey[c1]^tempkey1[c1];
c1++;}

while(c1<16)
{
tempkey1[c1]=tempkey1[c1-4]^tempkey[c1];
c1++;}

c1=0;
while(c1<16)
{
tempkey[c1]=tempkey1[c1];
c1++;}
}   


void GFmul128()
{

c2=0;
while(c2<16)
{
GHASH[c2]=0;
c2++;}


c2=0;
while (c2!=128) 
{
 if (((Hash[c2>>3] >> (7-(c2 & 0x07 )))&1) ==1) 
{ 
c3=0;
while(c3!=16)
{GHASH[c3]=GHASH[c3]^temp[c3];
c3++;} 
}
if((temp[15]& 1)==0)
{
c3=0;
while(c3!=16)
{
Y[c3]=temp[c3] & 1;
c3++;
}
c3=1;
while(c3!=16)
{
temp[c3]=(temp[c3]>>1)|(Y[c3-1]<<7);
c3++;
}
temp[0]=temp[0]>>1;
}

else
{
c3=0;
while(c3!=16)
{
Y[c3]=temp[c3] & 1;
c3++;
}
c3=1;
while(c3!=16)
{
temp[c3]=(temp[c3]>>1)|(Y[c3-1]<<7);
c3++;
}
temp[0]=temp[0]>>1;
temp[0]=temp[0]^0xe1;
}

c2++;
}}

void buildTag()
{


c1=0;
while(c1!=16)
{temp[c1]=(crypted1[c1]);
c1++;}
        GFmul128(); 
c1=0;
while(c1!=16)
{temp[c1]=(GHASH[c1]^crypted2[c1]);
c1++;}
        GFmul128(); 
c1=0;
while(c1!=16)
{temp[c1]=(GHASH[c1]^crypted3[c1]);
c1++;}                          
        GFmul128(); 
c1=0;
while(c1!=16)
{temp[c1]=(GHASH[c1]^crypted4[c1]);
c1++;}
        GFmul128();
c1=0;
while(c1!=16)
{temp[c1]=(GHASH[c1]);
c1++;}

temp[14]=temp[14]^0x02;

        GFmul128();  
c1=0;
while(c1!=16)
{Tag[c1]=Tag[c1]^GHASH[c1];                    ////Tag = Y0 ,,,   H = AES(0)
c1++;}


}
