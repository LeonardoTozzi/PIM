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
char modalidade[40];



int data[10];
int idade[10];
int equipe[10];
int alojamento[10];
};
typedef struct medico MEDICO;
    struct medico{




        char nome[40];
        char sexo[10];
        int idade[20];
        int ra[10];
        int equipe[10];


};



void cabecalho();
void cabecalho1();
void cabecalhoMed();

void inputCadastro();
void Listar();
void inputCadastro2();
void listarMedicos();


void main(){
 int opcao;
   setlocale(LC_ALL, "Portuguese");


 do{

 printf("-----------------------CADASTRO---------------\n");

 printf("1-CADASTRO DE ATLETAS \n");
 printf("2-RELATORIO DE ATLETAS \n");
 printf("3-CADASTRO DE MEDICOS \n");
 printf("4-CADASTRO DE MEDICOS \n");
 printf("5- COVID");
 printf("\n6- SAIR  ");
 printf("\n \n SELECIONE UMA OPÇÃO: ");
 scanf("%d" ,&opcao);

 system("cls");

 switch(opcao){


case 1: //cadastro do atleta
inputCadastro();



break;

case 2:
    Listar ();// historico de pesquisa atletas
break;

case 3:
    system("cls");
     inputCadastro2();
break;

case 4:listarMedicos();

case 5:
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

 system("cls");
}




 void inputCadastro(){
 FILE*arquivo;
 CADASTRO cds;

 arquivo = fopen("agenda.txt" ,"ab");
    if(arquivo ==NULL){

        printf("Problemas na abertura do arquivo!\n");

    }else{
        do{

            fflush(stdin);
            printf("\n Digite o nome: ");
            gets(cds.nome);


             fflush(stdin);
            printf("\nDigite o sexo: ");
            gets(cds.sexo);

             fflush(stdin);
            printf("\nDigite o local: ");
            gets(cds.local);

            fflush(stdin);
            printf("\n Digite sua modalidade olimpica: ");
            gets(cds.modalidade);

            fflush(stdin);
            printf("\n Data do jogo: ");
            gets(cds.data);

             fflush(stdin);
            printf("\nDigite o pais: ");
            gets(cds.pais);

             fflush(stdin);
            printf("\nDigite o equipamento:");
            gets(cds.equipamento);

            fflush(stdin);
            printf("\nDigite a idade: ");
            gets(cds.idade);


             fflush(stdin);
            printf("\nDigite o número da equipe: ");
            gets(cds.equipe);


             fflush(stdin);
            printf("\nDigite o alojamento: ");
            gets(cds.alojamento);

            fwrite(&cds ,sizeof(CADASTRO),1,arquivo);
            printf("Deseja continuar(s\n)?");

        }while(getche()=='s');
        fclose(arquivo);
        system("cls");
    }
 }
void Listar (){
 FILE*arquivo;
 CADASTRO cds;

 arquivo = fopen("agenda.txt" ,"rb");
    if(arquivo ==NULL){

        printf("Problemas na abertura do arquivo!\n");
    }else{

      while(fread(&cds , sizeof(CADASTRO),1,arquivo)==1){
            printf("Nome: %s\n" ,cds.nome);
            printf("Sexo: %s\n" ,cds.sexo);
            printf("Local: %s\n" ,cds.local);
            printf("Pais: %s\n" ,cds.pais);
            printf("Equipamento: %s\n" ,cds.equipamento);
            printf("Idade: %s\n" ,cds.idade);
            printf("Equipe: %s\n" ,cds.equipe);
            printf("Alojamento: %s\n" ,cds.alojamento);
            printf("Modalidade olimpica: %s \n", cds.modalidade);
            printf("Data do jogo: %s", cds.data);
            printf("\n\n\n");


    }

}
fclose(arquivo);
    getch();

    }



    void inputCadastro2(){



 FILE*arq;      //CADASTRO DE MEDICOS
MEDICO cds1;

 arq = fopen("cadastroMedicos.txt" ,"ab");
    if(arq==NULL){

        printf("Problemas na abertura do arquivo!\n");
    }else{
        do{

             printf("-------------------------CADASTRO DE MEDICOS------------------\n");
            fflush(stdin);
            printf("\n Digite o nome: ");
            gets(cds1.nome);


             fflush(stdin);
            printf("\nDigite o sexo: ");
            gets(cds1.sexo);




             fflush(stdin);
            printf("\nDigite sua idade: ");
            gets(cds1.idade);


            fflush(stdin);
            printf("\n Digite o numero da sua equipe ");
            gets(cds1.equipe);


            fwrite(&cds1 ,sizeof(MEDICO),1,arq);
            printf("Deseja continuar(s\n)?");

        }while(getche()=='s');
        fclose(arq);
    }
 }

listarMedicos(){
    printf("-------------------RELATORIO DE MEDICOS----------------\n");
     FILE*arq;
MEDICO cds1;


 arq = fopen("cadastroMedicos.txt" ,"rb");
    if(arq ==NULL){

        printf("Problemas na abertura do arquivo!\n");
    }else{

      while(fread(&cds1 , sizeof(MEDICO),1,arq)==1){
            printf("Nome: %s\n" ,cds1.nome);
            printf("Sexo: %s\n" ,cds1.sexo);
            printf("idade: %s\n" ,cds1.idade);
            printf("Equipe: %s\n" ,cds1.equipe);


            printf("\n\n\n");


    }
    fclose(arq);
    }
    getch();
}