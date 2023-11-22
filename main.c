#include <stdio.h>
#include "DLList.h"
int main(void) {

  DLList *colecao = NULL;
  Student *novo;
  int testeInt;
  void *testeAluno, *showAux;
  char nome[30];
  float grade;
  int opcao, age;
  int loop = TRUE;
  while(loop){




    
    
    printf("\n\n\n-------------------------------------\n");
    printf("1 - Criar Coleção\n");
    printf("2 - Inserir Aluno\n");
    printf("3 - Remover Aluno\n");
    printf("4 - Consultar Aluno\n");
    printf("5 - Listar os elementos de uma coleção\n");
    printf("6 - Destruir Coleção\n");
    printf("7 - Esvaziar Coleção\n");
    printf("8 - Sair do Programa\n");
    printf("-------------------------------------\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    switch(opcao){



      
      case 1:
        printf("\n-------------------------------------\n");
        if(colecao==NULL){
          colecao = dllistCreate();
          printf("Coleção criada!");
        }
        else{
          printf("Coleção ja foi criada");
        }
        printf("\n-------------------------------------\n");
        break;




      
      case 2:
        printf("\n-------------------------------------\n");
        if(colecao!=NULL){
          printf("Nome do aluno: ");
            scanf("%s", nome);
          printf("Idade do aluno: ");
            scanf("%d", &age);
          printf("Nota do aluno: ");
            scanf("%f", &grade);
          novo = createStudent(nome, age, grade);
          if(novo!=NULL){
            insertElementAsFirst(novo, colecao);
            if(testeInt){
              printf("Aluno adicionado");
            }
            else{
              printf("Aluno não adicionado");
            }
          }
          else{
            printf("Aluno não Adicionado");
          }
        }
        else{
          printf("Coleção não criada");
        }
        printf("\n-------------------------------------\n");
       
        break;




      
      case 3:
        printf("\n-------------------------------------\n");
        if(colecao!=NULL){
          printf("Nome do aluno: ");
            scanf("%s", nome);
          printf("Idade do aluno: ");
            scanf("%d", &age);
          printf("Nota do aluno: ");
            scanf("%f", &grade);
          testeAluno = removeElement(colecao, nome, age, grade);
          if(testeAluno!=NULL){
            printf("Aluno removido");
          }
          else{
            printf("Aluno não removido");
          }
        }
        else{
          printf("Coleção não criada");
        }
        printf("\n-------------------------------------\n");
        break;




      
      case 4:
        printf("\n-------------------------------------\n");
        if(colecao!=NULL){
          printf("Nome do aluno: ");
            scanf("%s", nome);
          printf("Idade do aluno: ");
            scanf("%d", &age);
          printf("Nota do aluno: ");
            scanf("%f", &grade);
          testeAluno = consultElementByName(colecao, nome, age, grade);
          if(testeAluno!=NULL){
            printf("Aluno encontrado");
          }
          else{
            printf("Aluno não encontrado");
          }
        }
        else{
          printf("Coleção não criada");
        }
        printf("\n-------------------------------------\n");
        
        break;





      
      case 5:
        printf("\n-------------------------------------\n");
        if(colecao!=NULL){
          showAux = (Student*)getFirst(colecao);
          while(showAux!=NULL){
            printf("Nome: %s\n",getNameStudent(showAux));
            printf("Idade: %d\n",getAgeStudent(showAux));
            printf("Nota: %f\n",getGradeStudent(showAux));
            printf("\n\n");
            showAux = (Student*)getNext(colecao);
          }
        }
        else{
          printf("Coleção não foi criada");
        }
        printf("\n-------------------------------------\n");

        break;





      
      case 6:
        printf("\n-------------------------------------\n");
        if(colecao!=NULL){
          testeInt = dllistDestroy(colecao);
          if(testeInt){
            printf("Coleção Destruida");
            colecao = NULL;
          }
          else{
            printf("Coleção não destruida");
          }
        }
        else{
          printf("Coleção não criada");
        }
        printf("\n-------------------------------------\n");
        break;





      
      case 7:
        printf("\n-------------------------------------\n");
        if(colecao!=NULL){
          testeInt = cleanCollection(colecao);
          if(testeInt){
            printf("Coleção Vazia!");
          }
          else{
            printf("Não foi possivel esvaziar");
          }
        }
        else{
          printf("Coleção não criada");
        }
        printf("\n-------------------------------------\n");
        break;




      
      case 8:
        printf("\n-------------------------------------\n");
        printf("Programa Finalizado!");
        printf("\n-------------------------------------\n");
        loop = FALSE;
        break;
      
    }
  }
}