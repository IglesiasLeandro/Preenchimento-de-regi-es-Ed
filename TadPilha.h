#define True 1
#define False 0
typedef struct Slnode{
     void *data;
     struct Slnode *next;
}Slnode ;

typedef struct SlList{
      Slnode *first;
}SlList;

SlList* CreatePilha();

int destroyList(SlList *l);
int Push(SlList *l, void *data);

void* Pop(SlList *l);

int printList(SlList *l, void mostra(void *elemento));
