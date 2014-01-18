#include <stdio.h>
#include <stdlib.h>
#define max 20


typedef struct recdata
  {
    char nama[100];
    char nim[100];
    int uts,uas,quis;
  }dt;

int n;
dt dat[max];

void data(int n)
{ 
  FILE *PF;
  int j;
  PF=fopen("data.txt","a+");
  for(j=1;j<=n;j++)
  { 
    if(PF != NULL)
      {   
        fprintf(PF,"\n-Nama         : %s \n ",dat[j].nama);
        fprintf(PF,"NIM         : %s \n ",dat[j].nim);
        fprintf(PF,"Nilai UTS   : %d \n ",dat[j].uts);
        fprintf(PF,"Nilai UAS   : %d \n ",dat[j].uas);
        fprintf(PF,"Nilai Quis  : %d \n ",dat[j].quis);
     }
   }
    fclose(PF);
} 
int tambah_data(dt dat[],int n)
{  
 
    printf("Masukkan data : \n");
    printf("-------------\n\n");
    printf("Nama     : "); fflush(stdin);gets(dat[n].nama);
    printf("NIM      : "); fflush(stdin);gets(dat[n].nim);
    printf("UTS      : "); scanf("%d",&dat[n].uts);   
    printf("UAS      : "); scanf("%d",&dat[n].uas);
    printf("Quis     : "); scanf("%d",&dat[n].quis);
    printf("\n");
  system("PAUSE");
  return 0;
}

void tampil_data()
{
 FILE *PF;
 char kar;
 PF=fopen("data.txt","a+");
 if ((PF=fopen("data.txt","r+")) == NULL)
 {
  printf("Data tidak ada\n");
 }
 else
 {
 while((kar=fgetc(PF))!=EOF)
 putchar(kar);
 }
 fclose(PF);            
}

void edit(dt dat[],int n)
{
  int index;
 
  printf("Edit Data\n============\n");
  printf("Masukkan index data yg akan diganti : ");scanf("%d",&index);  
  printf("\n");
  printf("Nama       : %s\n",dat[index].nama);
  printf("Posisi     : %s\n",dat[index].nim);
  printf("uts        : %d\n",dat[index].uts);
  printf("uas        : %d\n",dat[index].uas);
  printf("quis       : %d\n",dat[index].quis);
  printf("\n");
  printf("===============================\n");
  printf("Silahkan masukan data yang baru :\n");
  printf("===============================\n");
  printf("Nama       : "); fflush(stdin);gets(dat[index].nama);
  printf("Posisi     : "); fflush(stdin);gets(dat[index].nim);
  printf("uts        : ");scanf("%d",&dat[index].uts);    
  printf("uas        : ");scanf("%d",&dat[index].uas);
  printf("quis       : ");scanf("%d",&dat[index].quis);
  system ("PAUSE");

}    
void nilai_akhir(dt dat[],int n)
{
 FILE *PF;
 char kar;
 int cari,j;
 float NA;
    PF=fopen("data.txt","a+");
    printf("\nCari Data Karakter\n");
    printf("====================\n\n");
 if((PF=fopen("data.txt","a")) == NULL)
    {  
    printf("Data Masih Kosong\n"); 
    }
   else
   {
       printf("Masukkan Nomor Karakter : "); scanf("%i",&cari);
       j=1;
       while((j<=n)&&(j!= cari))
         {
          j++;
         }
         if(j == cari)
          {
            printf("=======================\n");
          
            printf("Nama            : %s\n\n",dat[j].nama);
            printf("NIM             : %s\n\n",dat[j].nim);
            printf("uts             : %d\n\n",dat[j].uts);
            printf("uas             : %d\n\n",dat[j].uas);
            printf("quis            : %d\n\n",dat[j].quis);
            NA = (dat[j].uas*0.5)+(dat[j].uts*0.3)+(dat[j].quis*0.2);
            printf("Nilai Akhir     : %.2f\n",NA);
          }
          
          
         else
             {
                                    printf("Data Tidak Ditemukan \a\n");
             }
         }
         fclose(PF);
         system("PAUSE");
        }

int hapus_data(dt dat[], int n)
{
 int cari,i,j;
 char pilih;
 printf("\nHapus Data karakter\n");
 printf("=====================\n\n");
 printf("Masukkan Nomor Urut : "); scanf("%i",&cari);
 i=1;
 while((i<=n)&&(i != cari))
 {
  i++;
 }
 if(i == cari)
  {
        printf("\n---------------------\n");
        printf("Nama         : %s\n",dat[i].nama);
        printf("Posisi       : %s\n",dat[i].nim);
        printf("uts          : %d\n\n",dat[i].uts);
        printf("uas          : %d\n\n",dat[i].uas);
        printf("quis         : %d\n\n",dat[i].quis);
   printf("Hapus Data Penghuni Yang Dipilih ? [Y/T] : "); scanf("%s",&pilih);
   if((pilih=='Y')||(pilih=='y'))
   {
    printf("\n\n %i\n",i);
    for(j=i; j<=n-1; j++)
    {
     dat[j]=dat[j+1];
    }  
    n=n-1;
   }
     }
     else
     {
   printf("\n\nData Tidak Ada\n");
     }
 system("PAUSE");
 return n;
}



int main()
{
 int menu;
 
  do
  {
    printf("\n============================\n");
    printf(" 1.Tambah\n");
    printf(" 2.Edit\n");
    printf(" 3.Nilai Akhir\n");
    printf(" 4.Hapus\n");
    printf(" 5.Tampil\n");
    printf("==============================\n");       
    printf(" Pilih Menu: ");scanf("%i",&menu);
    printf("==============================\n");
    system("CLS");   
    switch(menu)
    {
      case 1 :
             {
               n=n+1;
               system("CLS");
               tambah_data(dat,n);
               break;
             }
      case 2 :
             {
               system("CLS");
               edit(dat,n);
               break;
             }
      case 3 :
             {
               system("CLS");
               nilai_akhir(dat,n);
               break;
             }
      case 4 :
             {
               system("CLS");
               n=hapus_data(dat,n);
               break;
             }
      case 5 :
             {
               system("CLS");
               data(n);
               tampil_data();
               break;
             }
             
             
      case 0 :
             {
               system("CLS");
               printf("Keluar\n");
               break;
             }
      default :
              {             
                printf("Salah Memasukkan Menu!\n");
                getch();
                break;                    
              }                                                     
    }
  
} 
    
  while(menu!=0);
  system("PAUSE"); 
  return 0;
}
