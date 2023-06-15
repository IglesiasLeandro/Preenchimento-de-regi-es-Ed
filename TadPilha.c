#include <stdlib.h>
#include <stdio.h>
#include "TadPilha.h"



SlList* CreatePilha(){
  SlList *l=(SlList*)malloc(sizeof(SlList));
  if(l!=NULL){
    l->first=NULL;
    return l;
  }
  return NULL;
}

int destroyList(SlList *l){
  if(l!=NULL){
    if(l->first==NULL){
      free(l);
      return 1;
    }
  }
  return 0;
}

int Push(SlList *l, void *data){
  Slnode *newNode;
  if(l!=NULL && newNode!=NULL){
     newNode=(Slnode*) malloc(sizeof(Slnode));
     newNode->data=data;
     newNode->next=l->first;
     l->first=newNode;
     return True;
  }
  return False;
}


void* Pop(SlList *l){
  if(l!=NULL && l->first!=NULL){
    Slnode *a=l->first;
    void *copia=a->data;
    l->first=a->next;
    free(a);
    return copia;
  }
  return NULL;
}

int printList(SlList *l, void mostra(void *elemento)){
  if(l!=NULL && l->first!=NULL){
    Slnode *cuur=l->first;
    while(cuur!=NULL){
      mostra(cuur->data);
      cuur=cuur->next;
    }
  }
}
