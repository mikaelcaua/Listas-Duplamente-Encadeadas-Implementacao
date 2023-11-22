#include "DLList.h"
#include <stdlib.h>
#include <string.h>

  typedef struct _dlnode_{
    struct _dlnode_ *next;
    struct _dlnode_ *prev;
    void* data;
  }DLNode;

  typedef struct _dllist_{
    struct _dlnode_ *first;
    struct _dlnode_ *cur;
  }DLList;

  typedef struct _student_{
    char *name;
    int age;
    float grade;
  }Student;

  //funções estudante
  //funções estudante
  //funções estudante
  //funções estudante
  Student* createStudent(char *name, int age, float grade){
    if(name!=NULL){
      Student *novo = (Student*)malloc(sizeof(Student));
      novo->name = (char*)malloc(sizeof(char)*30);
        if(novo->name!=NULL){
          strcpy(novo->name, name);
          novo -> age = age;
          novo -> grade = grade;
          return novo;
        }
    }
    return NULL;
  }

  char* getNameStudent(DLNode *s){
      if(s!=NULL){
        return  ((Student*)s->data)->name;
      }
      return NULL;
    }

  int getAgeStudent(DLNode *s){
    if(s!=NULL){
      return  ((Student*)s->data)->age;
    }
    return ERROR;//-32767
  }

  float getGradeStudent(DLNode *s){
    if(s!=NULL){
      return  ((Student*)s->data)->grade;
    }
    return ERROR;
  }

  //funções lista
  //funções lista
  //funções lista
  //funções lista
  DLList *dllistCreate(){
    DLList *l = (DLList*)malloc(sizeof(DLList));
    if(l!=NULL){
      l->first = NULL;
      l->cur = NULL;
      return l;
    }
    return NULL;
  }

  int dllistDestroy(DLList *l){
    if(l->first==NULL){
      free(l);
      return TRUE;
    }
    return FALSE;
  }

  void* getFirst(DLList *l){
    if(l!=NULL){
      l->cur = l->first;
      return l->first;
      
    }
    return NULL;
  }

  void* getNext(DLList *l){
    if(l!=NULL){
        if(l->cur!=NULL){
          l->cur = l->cur->next;
          return l->cur;
        }
    }
    return NULL;
  }
  
  int insertElementAsFirst(void* data, DLList *l){
    if(l!=NULL && data!=NULL){
      DLNode *newnode = (DLNode*)malloc(sizeof(DLNode));
      newnode->data = data;
      if(l->first!=NULL){
        newnode -> next = l->first;
        newnode -> prev = NULL;
        l->first->prev = newnode;
        l->first = newnode;
        return TRUE;
      }
      else{
        newnode->next = NULL;
        newnode->prev = NULL;
        l->first = newnode;
        l->cur = newnode;
        return TRUE;
      }
    }
    return FALSE;
  }

  void* consultElementByName(DLList *l, char *name, int age, float grade){
    if(l!=NULL && name!=NULL){
      DLNode *aux = l->first;
      while(aux!=NULL){
        if((strcmp(name, getNameStudent(aux))==0) && age==getAgeStudent(aux) && grade==getGradeStudent(aux)){
          return aux->data;
        }
        aux = aux->next;
      }
    }
    return NULL;
  }  

  // void* removeElementByIndex(DLList *l, int index){
  //   if(l!=NULL && index>=0){
  //     if(l->first!=NULL){
  //       DLNode *spec = l->first;
  //       void *data;
  //       while(index>0 && spec!=NULL){
  //         spec = spec->next;
  //         index--;
  //       }
  //       if(spec->next!=NULL){
  //         spec->next->prev = spec->prev;
  //       }
  //       if(spec->prev!=NULL){
  //         spec->prev->next = spec->next;
  //       }
  //       if(spec==l->first){
  //         l->first=spec->next;
  //       }
  //       data = spec->data;
  //       free(spec);
  //       return data;
  //     }
      
      
  //   }
  //   return NULL;
  // }

  void* removeElement(DLList *l, char *name, int age, float grade){
    if(l!=NULL){
      if(l->first!=NULL){
        DLNode *spec = l->first;
        void *data;
        while(spec!=NULL){
          if(strcmp(name, getNameStudent(spec))==0 && age == ((Student*)spec->data)->age && grade == ((Student*)spec->data)->grade){
            break;
          }
          spec = spec->next;
        }
        if(spec!=NULL){
          if(spec->next!=NULL){
            spec->next->prev = spec->prev;
          }
          if(spec->prev!=NULL){
            spec->prev->next = spec->next;
          }
          if(spec==l->first){
            l->first=spec->next;
          }
          data = spec->data;
          free(spec);
          return data;
        }
      }
    }
    return NULL;
  }

  int cleanCollection(DLList *l){
    if(l!=NULL){
      
      if(l->first!=NULL){
        DLNode *aux = getFirst(l);
        DLNode *aux2;
        while(aux!=NULL){
          aux2 = aux;
          aux = getNext(l);
          free(aux2);
        }
        l->first = NULL;
        return TRUE;
      }
    }
    return FALSE;
  }