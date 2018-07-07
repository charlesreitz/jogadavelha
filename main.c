#include <stdio.h>
#include <stdlib.h>

int i=2,op,sequsu=0,l,c,a,b,c,acabou=0;
char matriz[4][4]={{'0',' ',' ',' '},{'0',' ',' ',' '},{'0',' ',' ',' '},{'0',' ',' ',' '}},cadastrado='n',ganhou='n';

struct cadastro         /*DECLARADO O REGRISTRO*/
{
       char nome[25];
       char sexo[10];
       char xo;
       int idade;
       int vitorias;
       } vet[2];
/*ZERA AS MATRAIZES DA TABELA================================================================================================================*/    
zeraJogo()
{
       a=0;   
       acabou=0;
       i=2;
       ganhou='n';
       acabou=0;
       
     for (l=0; l<4; l++)
         for (c=0; c<4; c++)
         matriz[l][c]=' ';
         
         } 

/*MOSTRA TELA================================================================================================================*/    
chamaTela()
 {
  printf ("\n   C1   C2   C3 ");
  printf ("\n      |    |    ");
  printf ("\nL1 %c  | %c  | %c",matriz[1][1],matriz[1][2],matriz[1][3]);
  printf ("\n   ___|____|___ ");
  printf ("\n      |    |    ");
  printf ("\nL2 %c  | %c  | %c",matriz[2][1],matriz[2][2],matriz[2][3]);
  printf ("\n   ___|____|___ ");
  printf ("\n      |    |    ");
  printf ("\nL3 %c  | %c  | %c",matriz[3][1],matriz[3][2],matriz[3][3]);
  printf ("\n      |    |    ");

         }
                    
/*1 - CADASTRO DE JOGADORES================================================================================================================*/    
incluirJogadores()  
{
    sequsu++;
    
    if (sequsu==2)
    cadastrado='s';
    
    
    if (sequsu>2) //VERIFICA SE FIO CADASTRO MAIS DE 2 JOGADORES
    {
    printf ("\n|                       CADASTRO DE JOGADORES COMPLETO                         |");
    printf ("\n| Para cadastrar novos jogadores necessario zerar jogadores na opcao 3 do menu |");
    printf ("\n                        --Tecle <enter> para continuar--");
    getch();
    }
    else         //CADASTRO DE JOGADORES
    {
    if (sequsu==1)
    vet[1].xo='X';
    else
    vet[2].xo='O';
    printf ("\n|=============================|");
    printf ("\n|   CADASTRO DE JOGADORES     |");
    printf ("\n|      MAX: 02 JOGADORES      |\n");
    printf ("\n|=============================|\n");
    
    printf ("\nDigite o nome do Jogador %d (%c)\n=>",sequsu,vet[sequsu].xo);
           fflush(stdin);
           gets(vet[sequsu].nome);
    printf ("\n Digite o sexo do Jogado %d \n1-Masculino\n2-Feminino\n=>",sequsu);
           fflush(stdin);
           scanf("%d",&op);
    switch(op){
              case 1:
              strcpy(vet[sequsu].sexo,"MASCULINO");
              break;
                   
              case 2:
              strcpy(vet[sequsu].sexo,"FEMININO");
              break;
         
              default: 
              printf ("Digite a Opcao Correta");
                 }
    printf ("\nDigite a idade do jogador %d\n=>",sequsu);
           fflush(stdin);
           scanf ("%d",&vet[sequsu].idade);
          
           } 
    
    system ("cls");                     
                        }
                      
/*2 - VER JOGADORES================================================================================================================*/                      
verJogadores()       
{
    printf ("\n|====================================|");
    printf ("\n|    LISTAR JOGADORES CADASTRADOR    |");
    printf ("\n|====================================|\n");
 int i;
 for (i=1; i<=2; i++){
  printf ("\n\n=============");
  printf ("\n|JOGADOR %d  |" ,i);
  printf ("\n==========================================");
  printf ("\n| NOME              |=>%s",vet[i].nome);
  printf ("\n| SEXO              |=>%s",vet[i].sexo);
  printf ("\n| IDADE             |=>%d",vet[i].idade);
  printf ("\n| SIMBOLO           |=>%c",vet[i].xo);
  printf ("\n| VITORIAS          |=>%d",vet[i].vitorias);
  printf ("\n==========================================");
 }getch();                                       
 system("CLS");
}

/*3 -ZERA JOGADORES================================================================================================================*/    
zeraJogadores()   
{
 sequsu=0;
 for (i=1; i<=2; i++)
  {
   strcpy(vet[i].nome,"                        ");
   strcpy(vet[i].sexo,"          ");
   vet[i].idade=0;
   vet[i].xo=' ';        
   vet[i].vitorias=0;
               }     
    printf ("\n|=============================|");
    printf ("\n Comando Executado com Sucesso");
    printf ("\n|=============================|\n");
    getch(); 
    system("cls");
              }

/*5- COMEÇA JOGO================================================================================================================ */
comecaJogo()
{
  zeraJogo();

if (cadastrado=='n')
{
    printf ("\n|                           NAO EXISTE JOGADORES                            |");
    printf ("\n| Para jogar cadastra os jogadores no Cadastro de jogadores opcao 1 do menu |");
    printf ("\n                   --Tecle <enter> para continuar--");
    getch();
    system("cls");
}

else
{

do
{
acabou++;

if (i==2)
i--;
else 
{
i++;
a=0;
}

 
do
{
chamaTela();
b=1;
printf ("\nJogador %d-[%c]",i,vet[i].xo);
printf ("\nL=>");
scanf  ("%d",&l);
printf ("\nC=>");
scanf  ("%d",&c);
if ((l<1) || (l>3) || (c<1) || (c>3))
{
                     printf ("\n      ++LOCAL INVALIDO++"); //VERIFICAR SE EXISTE LOCAIS QUE USUARIO DIGITOU
                     printf ("\n--Tecle <enter> para continuar--");
                     getch();
                     system("cls");
                     b=0;
                     }
if ((matriz[l][c]=='X') || (matriz[l][c]=='O')) //VERIFICA SE LOCAL ESTÁ SENDO USADO
{
                     printf ("\n       ++LOCAL USADO++");
                     printf ("\n--Tecle <enter> para continuar--");
                     getch();
                     system("cls");
                     b=0;
                     }
if (b==1) 
{
(matriz[l][c]=vet[i].xo);
b=1;
}

}  
while(b==0);
  
  if ((matriz[1][1]==vet[i].xo) && (matriz[1][2]==vet[i].xo) && (matriz[1][3]==vet[i].xo))
     ganhou='s';
     if ((matriz[2][1]==vet[i].xo) && (matriz[2][2]==vet[i].xo) && (matriz[2][3]==vet[i].xo))                    
     ganhou='s';               
     if ((matriz[3][1]==vet[i].xo) && (matriz[3][2]==vet[i].xo) && (matriz[3][3]==vet[i].xo))                    
     ganhou='s';
     if ((matriz[1][1]==vet[i].xo) && (matriz[2][1]==vet[i].xo) && (matriz[3][1]==vet[i].xo))                    
     ganhou='s';
     if ((matriz[1][2]==vet[i].xo) && (matriz[2][2]==vet[i].xo) && (matriz[3][2]==vet[i].xo))                    
     ganhou='s';
     if ((matriz[1][3]==vet[i].xo) && (matriz[2][3]==vet[i].xo) && (matriz[3][3]==vet[i].xo))
     ganhou='s';
     if ((matriz[1][1]==vet[i].xo) && (matriz[2][2]==vet[i].xo) && (matriz[3][3]==vet[i].xo))                    
     ganhou='s';
     if ((matriz[3][1]==vet[i].xo) && (matriz[2][2]==vet[i].xo) && (matriz[1][3]==vet[i].xo))                    
     ganhou='s';

if (ganhou=='s')
{
system("cls");
chamaTela();                 
                printf ("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf ("\n||        JOGADOR %d           ||",i);
                printf ("\n||         GANHOU             ||");               
                printf ("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf ("\n--Tecle <enter> para continuar--");
                vet[i].vitorias++;
                a=1;
                for(c=2500; c<2700; c++)
                _beep(c, 8);
                getch();
                }
if ((acabou==9) && (ganhou=='n'))
{
system("cls");
chamaTela();
                printf ("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf ("\n||        FIM DE JOGO         ||",i);
                printf ("\n||      NENHUM VENCEDOR       ||");               
                printf ("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf ("\n--Tecle <enter> para continuar--");
                a=1;
getch();
a=1;
}

system("cls");

}
while(a==0);
}

}

/*CREDITOS================================================================================================================*/ 
creditos()
{
    printf ("\n|==================================|");
    printf ("\n|     CREDITOS JOGO DA VELHA       |");
    printf ("\n|==================================|\n");
    printf ("\nCharles Reitz");
    printf ("\nE-mail/MSN: charles.reitz@gmail.com");
    printf ("\n18 anos");
    printf ("\nCursando 1 fase");
    printf ("\nCentro Universitario de Jaragua do Sul -UNERJ-");
    printf ("\nTecnicas de Programacao");
    printf ("\nProfessora Joice S. Mota");
    printf ("\n\n--Tecle <enter> para continuar--");
    getch();
    system ("cls");
}

/*INICIO================================================================================================================*/ 
main()                
{
 vet[1].vitorias=0;
 vet[2].vitorias=0;
  do 
  {
  

  
  printf ("\n1 - Cadastro de Jogadores");
  printf ("\n2 - Ver Jogadores");
  printf ("\n3 - Zerar Jogadores");
  printf ("\n4 - Comeca Jogo");
  printf ("\n5 - Creditos");
  printf ("\n6 - Sair\n=>");

  scanf ("%d",&op);
  system ("cls");
  switch(op)
  {
    case 1: incluirJogadores();break;
    case 2: verJogadores();break;
    case 3: zeraJogadores();break;
    case 4: comecaJogo();break;
    case 5: creditos();break;
    default: printf("valor invalido");
         }
          }
 while (op!=6);
  

  
}
