#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>




typedef struct cadastro CADASTRO;
struct cadastro{
char nome[41];
char sexo[10];
char local[40];
char pais[40];
char equipamento[40];



int idade;
int equipe;
int alojamento;
};

void cabecalho();
void cabecalho1();
void inputCadastro();
void Listar();
void senha();





void senha(){

    char login;
    char senha;
    char reg1;
    char reg2;
    char robo;



printf("\n\t\t\t--REGISTRAR--");
printf("\n\t\t\tRegistrar Login: ");
      scanf("%s",&reg1);

      printf("\n\n\t\tRegistrar Senha: ");
       scanf("%s", &reg2);


       printf("\n\t\t\tUsuario registrado!\n\n CONFIRME QUE NAO É UM ROBO, DIGITE *S*: ");
         scanf("%s",&robo);

         system("cls");

         printf("\n\t\t\t --LOGIN--");
         printf("\n\n\t\tlogin: ");
           scanf("%s", &login);


           printf("\n\n\t\t\tSenha: ");
           scanf("%s", &senha);


           if(login ==reg1){
            printf("Usuario logado!");
            }
             else if(login!=reg1){
                printf("Dados invalidos");
                }
                else if(senha == reg2){
                 printf("Usuario logado!");
                }
                 else if(senha!=reg2){
                    printf("Dados invalidos");
                 }

return 0 ;
}






void main(){

    senha();


 int opcao;
   setlocale(LC_ALL, "Portuguese");


 do{
 cabecalho();
 printf("1-CADASTRO DE ATLETAS \n");
 printf("2-CADASTRO DE MÉDICOS \n");
 printf("3-CADASTRO DE FUNCIONÁRIOS \n");
 printf("4-CADASTRO DE VOLUNTÁRIOS \n");
 printf("5- COVID");
 printf("\n6- SAIR  ");
 printf("\n \n SELECIONE UMA OPÇÃO: ");
 scanf("%d" ,&opcao);

 switch(opcao){


case 1: //cadastro do atleta
inputCadastro();



break;

case 2:// historico de pesquisa atletas

break;

case 3: //cadastro dos funcionarios
break;

case 4: //cadastro dos voluntarios
break;

case 5: //covid
break;

case 6:
    printf("Obrigado pela sua visita!");
    getch();
break;

default:
    printf("Opção inválida!\n");
    getch();
    break;
    return opcao;

 }

   } while(opcao != 6);
;
}


void cabecalho(){
system("cls");
 printf("--------------------CADASTRO DE EQUIPES--------------------------------- \n");
 }

 void cabecalho1(){
 printf("----------------------------- CADASTRO DOS ATLETAS ------------------------\n");



 }


 void inputCadastro(){

    FILE*arquivo;

    CADASTRO cds;
char nome[40];
 char sexo[40];
 char local[40];
 char pais[40];
 char equipamento[40];
 char modalidade[40];

 int equipe;
 int alojamento;
 int idade;

  arquivo= fopen("arquivo_palavra.txt", "w");


  if(arquivo == NULL)
  {
  printf("Erro na abertura do arquivo!");
  return 1;
  }


            printf("nome: ");
            scanf("%s" , &nome);
            gets(cds.nome);



            fflush(stdin);
            printf("sexo: ");
            scanf("%s", &sexo);
            gets(cds.sexo);

                  fflush(stdin);
                  printf("idade: ");
                scanf("%d", &idade);
                   gets(cds.idade);


                   fflush(stdin);
            printf("Numero do alojamento: ");
            scanf("%d",&alojamento);
                  gets(cds.alojamento);



                  fflush(stdin);
            printf("Numero da equipe: ");
            scanf("%d", &equipe);
                  gets(cds.equipe);

                     fflush(stdin);
            printf("Local do treino: ");
            scanf("%s", &local);
                     gets(cds.local);



                  fflush(stdin);
            printf("Equipamentos esportivos: ");
            scanf("%s", &equipamento);
                          gets(cds.equipamento);


                        fflush(stdin);
                        printf("Pais de origem: ");
                        scanf("%s", &pais);
                              gets(cds.pais);







  //usando fprintf para armazenar a string no arquivo
  fprintf(arquivo, " nome:%s\n sexo:%s\n idade:%d\n alojamento:%d\n equipe:%d\n local:%s\n equipamento:%s\n pais:%s",nome,sexo,idade,alojamento,equipe,local,equipamento,pais);

  //usando fclose para fechar o arquivo
  fclose(arquivo);

  printf("Dados gravados com sucesso!");

  getch();
  return(0);
}