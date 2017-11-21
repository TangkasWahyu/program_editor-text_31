/*
    Nama    : I Made Tangkas Wahyu Kencana Yuda
    NIM     : 1608561031
    Matkul  : Pratikum Struktur Data (B)
    Penjelasan:
    Program ini menyimulasikan tentang cara editor data
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define Nama "PROGRAM MEURUTKAN HURUF"

struct data
{
	char huruf[50];
	struct data *next;
};

struct data *kepala, *ekor, *hapus, *cek, *temp, *baru;
int n=0, pil, z=1, maks=0;
char kata1[50], kata2[50];

int main()
{
	do
	{
		int i=0;
		system("cls");	
		printf("\t\t************************\n");
		printf("\t\t%s\n",Nama);
    	printf("\t\t************************\n");
		printf("pilih menu :\n1. add data\n2. printf\n3. shift_left\n4. shift_right\n5. delete");
		printf("\nKetik Pilihan : ");
		scanf("%d",&pil);
		switch(pil)
        {
        	case 1:
        		
				
        		system("cls");
				printf("Masukkan banyak kata yang ingin dibuat: ");
				scanf("%d",&maks);
				printf("\n");
				
				for(i=0;i<maks;i++)
				{
					baru=(struct data *)malloc(sizeof(struct data));
					printf("Masukkan Karakter %d : ",n+1);
					fflush(stdin);
					gets(baru->huruf);
					if(n==0||kepala==NULL)
					{
						kepala=baru;
						ekor=kepala;
						ekor->next=NULL;
						n++;
					}
					else
					{
						ekor->next=baru;
						ekor=baru;
						ekor->next=NULL;
						n++;
					}
				}
				getch();
				break;
        	case 2:
				system("cls");
				if(n==0)
				{
					printf("Tidak ada huruf yang dapat ditampilkan!\n");
					system("pause");
					main();
				}
				else
				{
					cek=kepala;
					i=0;
					while(cek!=NULL)
					{
						i++;
						printf("Kata ke-%d: %s\n",i,cek->huruf);
						cek=cek->next;
					}
				}
				getch();
				break;
			case 3:
				cek=kepala->next;
				cek!=ekor;
				if(n==1)
				{
					system("cls");
					printf("Huruf yang ditampilkan hanya 1 huruf jadi tidak bisa shift left!\n");
					system("pause");
					main();
				}
				strcpy(kata1, cek->huruf);
				strcpy(kata2, kepala->huruf);
				strcpy(kepala->huruf, kata1);
				strcpy(cek->huruf, kata2);
				break;
			case 4:
				cek=kepala->next;
				system("cls");
				if(n==1)
				{
					printf("Huruf yang ditampilkan hanya 1 huruf jadi tidak bisa shift right!\n");
					system("pause");
					main();
				}
				strcpy(kata1, cek->huruf);
				strcpy(kata2, ekor->huruf);
				strcpy(ekor->huruf, kata1);
				strcpy(cek->huruf, kata2);
				break;
			case 5:
				cek = kepala;
				if(n==0)
				{
					system("cls");
					printf("Tidak ada huruf yang dapat ditampilkan!\n");
					system("pause");
					main();
				}
				else if(n==1){
					kepala=NULL;
					n--;
				}
				else
				{
					while(cek->next!=ekor)
					{
			    		cek=cek->next;
					}
                	hapus=ekor;
                	ekor=cek;
                	ekor->next=NULL;
                	free(hapus);
                	n--;
                	printf("Berhasil menghapus!\n");	
				}
                system("pause");
                main();
				break;
			default :
				{
           			printf("Maaf, inputan salah!\n");
           			system("pause");
           			main();
            		break;
				}
		}
	}while(z!=0);
}
