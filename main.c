#include <stdio.h>
#include <stdlib.h>
#include "tadPilha.h"
#include <time.h>
#include <locale.h>

int*** CriaMatriz(int n){
       int erro=False;
       int ***matriz=(int***)malloc(sizeof(int**)*n);
       if(matriz!=NULL){
        for(int i=0;i<n;i++){
            matriz[i]=(int**)malloc(sizeof(int*)*n);
            if(matriz[i]==NULL){
                for(int j=i;j>=0;j--){
                    free(matriz[j]);
                }
                 erro=True;
                 free(matriz);
                 break;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matriz[i][j]=(int*)malloc(sizeof(int)*3);
                if(matriz[i][j]== NULL){
                    for(int k=i;k>=0;k--){
                        for(int l=j;l>=0;l--){
                            free(matriz[i][j]);
                        }
                    }
                    erro=True;
                    free(matriz);

                }
            }
        }
        if(erro!=True){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matriz[i][j][0]=(int)(rand()%10)/5;
                    matriz[i][j][1]=i;
                    matriz[i][j][2]=j;
                }
            }
            return matriz;
        }
       }
       return NULL;

}

void MostraMatriz(int ***matriz, int n){
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ", matriz[i][j][0]);
    }
    printf("\n");
   }
}


int preencheRegiao(int ***ma, int n, int cor_antiga, int cor_nova,int x, int y){
    SlList *Pilha=CreatePilha();
    void *data;
    int *dado;
    int valor,i,j;
    if(Pilha!=NULL && ma!=NULL){
        Push(Pilha, (void*)ma[x][y]);
        data=Pop(Pilha);
        while(data!=NULL){
             dado=(int*)data;
            valor=dado[0];
            i=dado[1];
            j=dado[2];
            if(valor==cor_antiga){
                if(i>0){
                    Push(Pilha, (void*) ma[i-1][j]);
                }
                if(i<n-1){
                    Push(Pilha, (void*) ma[i+1][j]);
                }
                if(j>0){
                    Push(Pilha, (void*) ma[i][j-1]);
                }
                if(j<n-1){
                    Push(Pilha, (void*) ma[i][j+1]);
                }
                dado[0]=cor_nova;
            }
            data=Pop(Pilha);
        }
          return True;
    }
    return False;
}

int menu(int ***matriz, int ordem){
    setlocale( LC_ALL, "Portuguese");
    int escolha;
    if(matriz!=NULL && ordem!=0){
        MostraMatriz(matriz, ordem);
    }
    printf("Programa de preenchimento de regiões. Selecione uma das opções\n");
    printf("1.Definir a ordem da Matriz\n");
    printf("2.Digitar a coordenada e para qual cor você quer alterar\n");
    printf("3.Encerrar o Programa\n");
    scanf("%d", &escolha);
    return escolha;
}
int main(){
    int cor_antiga, cor_nova, ordem=0, x, y;
    int ***matriz;
    int rodando=True;
    while(rodando){
    switch(menu(matriz, ordem)){
        case 1:
            printf("Digite a ordem da matriz: ");
            scanf("%d", &ordem);
            matriz=CriaMatriz(ordem);
            system("cls");
            break;
        case 2:
            printf("Digite as coordenadas x e y, respectivamente");
            scanf("%d %d", &x, &y);
            cor_antiga=matriz[x][y][0];
            printf("Digite o valor para o qual você quer alterar");
            scanf("%d", &cor_nova);
            preencheRegiao(matriz, ordem, cor_antiga, cor_nova, x, y);
            system("cls");
            break;
        case 3:
            rodando=False;
            break;
    }
    }
    return 0;
}
