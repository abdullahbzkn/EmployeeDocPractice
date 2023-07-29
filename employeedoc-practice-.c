//librarys
#include <stdio.h>
#include <stdlib.h>

//prototypes
void verileriduzenle(void);
void ciz(FILE *a);

//variables
 int i,secim1,secim2;
 char gender;
 char isim[11];
 char soyisim[11];
 int yas;
 char medenihal[7];
 float maas,sayac=0.0;
 char pozisyon[15];
 char telefon[11];
 char mail[30]; 
 
int main()
{
   FILE *hedefpt;
   FILE *kaynakpt;
   hedefpt=fopen("hedef.txt","w+"); //hedefpt=fopen("c:\hedef.txt","w"); bu þekilde yazýp c diskinde yazma modunda hedef.txt klasoru olusturulup acýlabilirdi ancak zaten direk ayný klasorde kaynak ve hedef olusmasý icin bu sekilde yazdým
   kaynakpt=fopen("kaynak.txt","r"); //kaynakpt=fopen("c: \kaynak.txt","r");
   
   if(hedefpt==NULL){
   	 printf("\tDosyalar acilirken bir hata olustu.\n");
    }
    
   else{
	 printf("\n\n\t\tRICHMAND OTEL Mutfak Calisanlari Analiz Programina Hosgeldiniz.\n\n");
	 printf("\tListeleme filtresini seciniz : \n\n");
	 printf("  1- Cinsiyete Gore\n");
	 printf("  2- Pozisyona Gore\n");
	 printf("  3- Medeni Hale Gore\n");
     printf("\n\n Veri almadan cikis yapmak icin 0 giriniz.\n\n\n");
	 scanf("%d",&secim1);
	 system("cls");
	 if(secim1==0){
	     printf("\n\n Cikis Yapiliyor...\n");
	     fputs("Listelenecek veri kaynaktan çekilmemiþtir.",hedefpt);
	    }
	 else if(secim1 == 1){
	 	 printf("\tListelemek istediginiz personelleri seciniz : \n\n");
	 	 printf("  1- Erkek Personeller\n");
	 	 printf("  2- Kadin Personeller\n");
	 	 scanf("%d",&secim2);
	 	 if(secim2==1)
	 	  	 fputs("Tüm Erkek Mutfak Personellerimiz Listededir.\n",hedefpt);
	 	 else if(secim2==2)
	 	 	 fputs("Tüm Kadýn Mutfak Personellerimiz Listededir.\n",hedefpt);
	 	 ciz(hedefpt);
	 	 while(fscanf(kaynakpt," %c %s %s %d %s %f %s %s %s\n",&gender,isim,soyisim,&yas,medenihal,&maas,pozisyon,telefon,mail) != EOF){ //liste sonunda kadar tum veriler tek tek çekilir
	 	 	 verileriduzenle();
	 	 if(secim2==2 & gender=='K' || secim2==1 & gender=='E'){ //burda personellerin cinsiyeti analiz ediliyor istenene göre ve yazdýrýlýyor.
	 	 	 sayac++;
			 fprintf(hedefpt,"|    %c     | %s %s | %d  |    %s    |  %7.2f tl",gender,isim,soyisim,yas,medenihal,maas);
		 	 if(maas < 10000.00){ //liste gorunumu icin eger maas 5.2 haneden kucukse bir bosluk atiliyor eger maas verilerinde cok farkli basamaklar olsaydi ona gore duzenlenebilirdi
	 		     fprintf(hedefpt," ");
	            }
	         fprintf(hedefpt," |  %s|   %s  |%s|\n|          |                       |     |             |              |                |               |                            |\n",pozisyon,telefon,mail);
	        }	 
		}
		 fputs("|__________|_______________________|_____|_____________|______________|________________|_______________|____________________________|\n",hedefpt);
		 fprintf(hedefpt,"\n\n  %.0f personel listelendi. Personeller Yüzde %.0f oranýnda",sayac,(sayac/50)*100); //belgede 50 eleman var ancak bu kod eleman giriþ çýkýþýnda yanlýþ deðer vericektir çözüm döküman okunurken satýr sayýsýyla eleman sayýsýný bulup degiskene atýp burda 50 yerine degiskeni isleme tabii tutmaktýr.Pull request gönderebilirsiniz :)
		 if(secim2==1)
	 	  	 fputs(" erkek. ",hedefpt);
	 	 else if(secim2==2)
	 	  	 fputs(" kadýn. ",hedefpt);
        }
	 else if(secim1 == 2){
         printf("\tListelenecek personelleri seciniz : \n\n");
	 	 printf("  1- Executive Chef\n");
	 	 printf("  2- Sous Chefler\n");
	 	 printf("  3- Chef de Partieler\n");
	 	 printf("  4- Demi Chefler\n");
	 	 printf("  5- Commiler\n");
	 	 printf("  6- Stajyerler\n");
	 	 scanf("%d",&secim2);
	 	 if(secim2==1)
	 	 	 fputs(" Executive Chefimiz Listededir.\n",hedefpt);
	 	 else if(secim2==2)
	 	     fputs(" Sous Cheflerimiz Listededir.\n",hedefpt);
	 	 else if(secim2==3)
	 	     fputs(" Chef De Partielerimiz Listededir.\n",hedefpt);
	 	 else if(secim2==4)
	 	 	 fputs(" Demi Cheflerimiz Listededir.\n",hedefpt);
	 	 else if(secim2==5)
	 	     fputs(" Tüm Commilerimiz Listededir.\n",hedefpt);
	 	 else if(secim2==6)
	 	 	 fputs(" Tüm Stajyerlerimiz Listededir.\n",hedefpt);
	 	 ciz(hedefpt);
		 while(fscanf(kaynakpt," %c %s %s %d %s %f %s %s %s\n",&gender,isim,soyisim,&yas,medenihal,&maas,pozisyon,telefon,mail) != EOF){ //liste sonunda kadar tum veriler tek tek çekilir
	 	 	 verileriduzenle();
			 if(pozisyon[0]=='E' && pozisyon[1]=='x' && secim2==1 || pozisyon[0]=='S' && pozisyon[1]=='o' && secim2==2 || pozisyon[0]=='C' && pozisyon[1]=='h' && secim2==3 || pozisyon[0]=='D' && pozisyon[1]=='e' && secim2==4 || pozisyon[0]=='C' && pozisyon[1]=='o' && secim2==5 || pozisyon[0]=='S' && pozisyon[1]=='t' && secim2==6){ //burda personellerin pozisyonu analiz ediliyor istenene göre ve yazdýrýlýyor.
	 	 	 	 fprintf(hedefpt,"|    %c     | %s %s | %d  |    %s    |  %7.2f tl",gender,isim,soyisim,yas,medenihal,maas);
	 	 	 	 if(maas < 10000.00){ //liste gorunumu icin eger maas 5.2 haneden kucukse bir bosluk atiliyor eger maas verilerinde cok farkli basamaklar olsaydi ona gore duzenlenebilirdi
	 	     	     fprintf(hedefpt," ");
	                }
	                 fprintf(hedefpt," |  %s|   %s  |%s|\n|          |                       |     |             |              |                |               |                            |\n",pozisyon,telefon,mail);
	            }
			}
		     fputs("|__________|_______________________|_____|_____________|______________|________________|_______________|____________________________|\n",hedefpt);
	    }
	 else if(secim1 == 3){
	 	 printf("\tListelenecek personel turunu seciniz : \n\n");
	 	 printf("  1- Evli Personeller\n");
	 	 printf("  2- Bekar Personeller\n");
	 	 scanf("%d",&secim2);
	 	 if(secim2==1)
	 	 	 fputs(" Tüm Evli Personellerimiz Listededir.\n",hedefpt);
	 	 else if(secim2==2)
	 	 	 fputs(" Tüm Bekar Personellerimiz Listededir.\n",hedefpt);
	     ciz(hedefpt);
		 while(fscanf(kaynakpt," %c %s %s %d %s %f %s %s %s\n",&gender,isim,soyisim,&yas,medenihal,&maas,pozisyon,telefon,mail) != EOF){ //liste sonunda kadar tum veriler tek tek çekilir
	 	 	 verileriduzenle();
			 if(medenihal[0]=='E' && medenihal[1]=='v' && secim2==1 || medenihal[0]=='B' && medenihal[1]=='e' && secim2==2){ //burda personellerin medeni hali analiz ediliyor istenene göre ve yazdýrýlýyor.
	 	 	 	 fprintf(hedefpt,"|    %c     | %s %s | %d  |    %s    |  %7.2f tl",gender,isim,soyisim,yas,medenihal,maas);
	 	 	 	 if(maas < 10000.00){ //liste gorunumu icin eger maas 5.2 haneden kucukse bir bosluk atiliyor eger maas verilerinde cok farkli basamaklar olsaydi ona gore duzenlenebilirdi
	 	 	 	 	 fprintf(hedefpt," ");
	                }
	             fprintf(hedefpt," |  %s|   %s  |%s|\n|          |                       |     |             |              |                |               |                            |\n",pozisyon,telefon,mail);
	            }
			}
		     fputs("|__________|_______________________|_____|_____________|______________|________________|_______________|____________________________|\n",hedefpt);
		}
		  
	 fclose(hedefpt);
	 fclose(kaynakpt);
    }
	return 0;
}
void verileriduzenle(void){
 	 for(i=0;i<=9;i++){ //burdaki forlarin amaci boþ karakter ekleyip liste gorunumunun guzel olmasini saglamak 
		 if(isim[i]=='\0'){
		 	 isim[i]=' ';
		 	 isim[i+1]='\0';
		    }
		 if(soyisim[i]=='\0'){
		 	 soyisim[i]=' ';
		 	 soyisim[i+1]='\0';
		    }
	    }
	 for(i=0;i<=13;i++){
		 if(pozisyon[i]=='\0'){
		 	 pozisyon[i]=' ';
		 	 pozisyon[i+1]='\0';
		    }
	    }
	 for(i=0;i<=27;i++){
		 if(mail[i]=='\0'){
		 	 mail[i]=' ';
		 	 mail[i+1]='\0';
		    }
	    }
     if(medenihal[0]=='E'){ //burda yine liste goruntusu bozulmasin diye evli kelimesine bir bosluk karakteri atýlýyor
	     medenihal[4]=' ';medenihal[5]='\0';
	    }
	    isim[10]='\0';
	    soyisim[10]='\0';
}
void ciz(FILE *hedefpt){
	 fputs(" ___________________________________________________________________________________________________________________________________\n|          |                       |     |             |              |                |               |                            |\n",hedefpt);
	 	 	 fputs("| Cinsiyet |       Personel        | Yaþ | Medeni Hal  |     Maaþ     |    Pozisyon    |  Telefon No   |    Mail Adresi             |\n",hedefpt);
	 	 	 fputs("|__________|_______________________|_____|_____________|______________|________________|_______________|____________________________|\n|          |                       |     |             |              |                |               |                            |\n",hedefpt);
			 
}
