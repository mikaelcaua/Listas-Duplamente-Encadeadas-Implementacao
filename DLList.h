#ifndef _DLLIST_
#define _DLLIST_
  #define TRUE 1
  #define FALSE 0
  #define ERROR -32767
  typedef struct _dllist_ DLList;
  typedef struct _dlnode_ DLNode;
  typedef struct _student_ Student;

  //LISTA
  DLList *dllistCreate();
  int dllistDestroy(DLList *l);
  int insertElementAsFirst(void* data, DLList *l);
  void* getFirst(DLList *l);
  void* consultElementByName(DLList *l, char *name ,int age, float grade);
  void* getNext(DLList *l);
  int cleanCollection(DLList *l);
  void* removeElement(DLList *l, char *name, int age, float grade);


  //ESTUDANTE
  Student* createStudent(char *name, int age, float grade);
  char* getNameStudent(DLNode *s);
  int getAgeStudent(DLNode *s);
  float getGradeStudent(DLNode *s);


#endif
