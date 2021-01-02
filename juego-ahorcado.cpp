/* 
  by osvaldo velazquez
  https://github.com/valdolab
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

void cabeza();
void cabeza_perdi();
void torzo();
void brazo_izquierdo();
void brazo_derecho();
void pie_izquierdo();
void pie_derecho();
void horca();
void hombre_gano();

void gotoxy(int x,int y)
	{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 	}

int main() 
{
    char palabra[60],rep[100],temporal[100];
    char pal;
    int longi=0,i,j=0,inicio=0,acert=0,temp=0,opor=7;
    int repet=0,gano=0;
   
    printf("\tJUEGO DEL AHORCADO!\n");
    printf("Introduzca la palabra a adivinar:\n");
    gets(palabra);
    system("cls");
   
    rep[0] = ' ';
    rep[1] = '\0';
   
    do 
	{
        system("cls");
        temp=0;   
        if(inicio == 0)
		 {
           for(i=0;i<strlen(palabra);i++) 
		 {
          if(palabra[i] == ' ') 
		  {
            temporal[i] = ' ';
             longi++;
          }
          else
		  {
             temporal[i] = '_';       
             longi++;
          }
         }
        }
        inicio = 1;
        temporal[longi] = '\0';
        for(i=0;i<strlen(rep);i++) 
		{
           if(rep[i] == pal) 
		   {
            repet = 1;
            break;
           }
          else 
		  {
           repet = 0;
          }
        }
       
        if(repet == 0) 
		{
         for(i=0;i<strlen(palabra);i++) 
		 {
            if(palabra[i] == pal) 
			{
              temporal[i] = pal;
              acert++;
              temp=1;
            }
          }
        }
        if(repet == 0) 
		{
         if(temp == 0) 
		 {
           opor = opor - 1;
         }
        }
        else 
		{
         printf("\nYa se ha introducido este caracter");
         printf("%c",07);
         printf("\n\n");
        }
        printf("\n\n\n");
        for(i=0;i<strlen(temporal);i++) 
		{
         printf(" %c ",temporal[i]);
        }
        //printf("\n");
        if(strcmp(palabra,temporal) == 0) 
		{
            gano = 1;
            break;
        }
        
        printf("\n\nLetras Acertadas: %d \n\n",acert);
        printf("\n");
        printf("Oportunidades Restantes: %d \n",opor);
		   
        rep[j] = pal;j++;
		
		if (opor==6)
        	{
		   		//cabeza();
		   		//torzo();
		   		//brazo_izquierdo();
		   		//brazo_derecho();
		   		//pie_izquierdo();
		   		//pie_derecho();
		   		horca();
			}
			else 
			if (opor==5)
			{
				cabeza();
		   		//torzo();
		   		//brazo_izquierdo();
		   		//brazo_derecho();
		   		//pie_izquierdo();
		   		//pie_derecho();
		   		horca();
			}
			else
			if (opor==4)
			{
				cabeza();
		   		torzo();
		   		//brazo_izquierdo();
		   		//brazo_derecho();
		   		//pie_izquierdo();
		   		//pie_derecho();
		   		horca();
			}
			else
			if (opor==3)
			{
				cabeza();
		   		torzo();
		   		brazo_izquierdo();
		   		//brazo_derecho();
		   		//pie_izquierdo();
		   		//pie_derecho();
		   		horca();
			}
			else
			if (opor==2)
			{
				cabeza();
		   		torzo();
		   		brazo_izquierdo();
		   		brazo_derecho();
		   		//pie_izquierdo();
		   		//pie_derecho();
		   		horca();
			}
			else
			if (opor==1)
			{
				cabeza();
		   		torzo();
		   		brazo_izquierdo();
		   		brazo_derecho();
		   		pie_izquierdo();
		   		//pie_derecho();
		   		horca();
			}
			else
			{
				cabeza_perdi();
		   		torzo();
		   		brazo_izquierdo();
		   		brazo_derecho();
		   		pie_izquierdo();
		   		pie_derecho();
		   		horca();
			}
		if (opor==0)
        {
           break;
        }
        gotoxy(0,11);
    	printf("\n\nIntroduzca una letra:");
        scanf("\n%c",&pal);
      
    }
	while(opor != 0);
   
		if(gano>0) 
		{
			//system("cls");
        	printf("\n\n\nFELICIDADES GANASTE!!!");
        	printf(":D\n\n\n");  
        	printf("%c",07);
			horca();    	
        	hombre_gano();
        	printf("\n");  
        	
    	}
    	else 
		{
			gotoxy(0,10);
        	printf("\nPERDISTE!!!\n");
        	printf("\n\nX__X");
        	printf("\n\n\nLa palabra o oracion correcta era: %s \n\n\n",palabra);
    	}
    getch();
    //return 0;
}
void cabeza()
{
  	gotoxy(45,6);
  	printf("|||||");
  	gotoxy(44,7);
  	printf("| . . |");
  	gotoxy(45,8);
  	printf("|_-_|");	
}
void cabeza_perdi()
{
	gotoxy(45,6);
  	printf("|||||");
  	gotoxy(44,7);
  	printf("| x x |");
  	gotoxy(45,8);
  	printf("|_-_|");
}
void torzo()
{
	gotoxy(47,9);
	printf("|");
	gotoxy(47,10);
	printf("|");
	gotoxy(47,11);
	printf("|");
	gotoxy(47,12);
	printf("|");
}
void brazo_izquierdo()
{
	gotoxy(48,9);
	printf("%c",92);
	gotoxy(50,10);
	printf("%c",92);
}
void brazo_derecho()
{
	gotoxy(46,9);
	printf("/");
	gotoxy(44,10);
	printf("/");
}
void pie_izquierdo()
{
	gotoxy(48,13);
	printf("%c",92);
	gotoxy(50,14);
	printf("%c",92);
}
void pie_derecho()
{
	gotoxy(46,13);
	printf("/");
	gotoxy(44,14);
	printf("/");	
}
void horca()
{
	int i,k;
	gotoxy(47,5);
	printf("%c",186);
	gotoxy(47,4);
	printf("%c",186);
	gotoxy(47,3);
	printf("%c",186);
	for (k=2;k<18;k++)
	{
	gotoxy(47,i);
	printf("%c",205);
	}
	for(i=3;i<18;i++)
		{
			gotoxy(64,i);
			printf("%c",186);
		}
	gotoxy(57,i);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);	
}
void hombre_gano()
{
 	//cabeza
  	gotoxy(15,11);
  	printf("|||||");
  	gotoxy(14,12);
  	printf("| %c %c |",248,248);
  	gotoxy(15,13);
  	printf("|_-_|");	

	//torzo
	gotoxy(17,14);
	printf("|");
	gotoxy(17,15);
	printf("|");
	gotoxy(17,16);
	printf("|");
	gotoxy(17,17);
	printf("|");
	gotoxy(17,18);
	printf("|");

	//brazo izquierdo
	gotoxy(18,15);
	printf("/");
	gotoxy(20,14);
	printf("/");

	//brazo derecho
	gotoxy(16,15);
	printf("%c",92);
	gotoxy(14,14);
	printf("%c",92);

	//pie izquierdo
	gotoxy(18,19);
	printf("%c",92);
	gotoxy(20,20);
	printf("%c",92);

	//pie derecho
	gotoxy(16,19);
	printf("/");
	gotoxy(14,20);
	printf("/");	
	
	//piso
	int p;
	for (p=4;p<32;p++)
	{
		gotoxy(p,21);
		printf("%c",223);
	}
}//fin del hombre_gano
