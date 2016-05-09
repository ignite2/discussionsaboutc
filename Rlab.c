#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define IX 1  //x inicial do programa
#define IY 1  //y inicial do programa
#define GX 8  //x final
#define GY 5  //y final
#define ABS(x)((x)?1:0)

char mapa[MAX][MAX+2] = {
    "###########",
    "# #  #   ##",
    "#      #  #",
    "# # # #  ##",
    "# #  ### ##",
    "# # ####  #",
    "#   #  ## #",
    "# #### #  #",
    "#   #    ##",
    "###########"
};

int teste(int x, int y);

void imprima(void);

int main(void)
{
    teste(IX, IY);

    return 0;
}
void imprima(void)  //funcao auxilixar para imprimir o mapa
{
    int i, j;

    for(i=0;i<MAX;i++)
    {
        for(j=0;j<=MAX;j++)
            printf("%c", mapa[i][j]);
        printf("\n");
    }
    printf("\n\n\n");

    EXIT_SUCCESS;
}
int teste(int x, int y)     //coordenadas x e y, em que x e o vertical e y horizontal
{
    int dy, dx, st;         //st -> stop; se st for 0 entao nao obteve-se resposta ainda e 1 se encontrou a resposta

    if((x==GX)&&(y==GY))    //se encontrar a resposta ele termina add st=1
    {
        mapa[x][y] = '!';
        printf("Venceu!\n");
        imprima();
        st = 1;             //unico momento de st=1; isso causara os fechamentos das funcoes em aberto
        return st;
    }
    else
    {
        st = 0;
        if((mapa[x][y]!='x')&&(mapa[x][y]!='#'))    //ele so pode ir para lugares livres
        {
            mapa[x][y] = 'x';   //marca aonde esta
            printf("Tentando:\n");
            imprima();

            for(dx=1;dx>=-1;dx--)   //lacos para determinar suas possibilidades
                for(dy=1;dy>=-1;dy--)
                {
                    if(ABS(dy) == ABS(dx))  //ignoradas
                        continue;
                    else                    //tentadas
                    {
                        st = teste(x+dx, y+dy); //chama a funcao novamente e garda o valor em st
                        if(st==1)               //com isso ele fecha essa chamada teste e retorna st=1. Deste modo (linhas 79 e 80) ele ira fechar todas as chamadas teste pq st=1
                            return st;
                    }
                }
            mapa[x][y] = ' ';
        }
    }
    return st;
}
