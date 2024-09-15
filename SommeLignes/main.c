#include <stdio.h>
#include <stdlib.h>

const int MATR_ = 100;

void SaisieM(int mat[MATR_][MATR_], int n, int m)
{
    for(int i= 0; i < n; ++i){
        for(int j= 0; j< m; ++j){
            scanf("%d", &mat[i][j]);
        }
    }
}

void Initialiser(int mat[MATR_][MATR_], int n, int m)
{
    for(int i= 0; i < n; ++i){
        for(int j= 0; j< m; ++j){
           mat[i][j] = 0;
        }
    }
}

int Sommes(int mat[MATR_][MATR_], int n, int m)
{
    int result = 0;
        for(int j= 0; j< m; ++j){
           result  += mat[n][j];
        }
        return result;
}

int SommeD1(int mat[MATR_][MATR_], int n, int m)
{
    int result =0;
    for(int i = 0; i< n; i++){
        for(int j =0; j<m; j++){
            if(i==j)
            {
                result += mat[i][j];
            }
        }
    }
     return result;
}

int SommeD2(int mat[MATR_][MATR_], int n, int m)
{
    int result =0;
    int i = 0;
    int j = n;
   do
   {
       --j;
       result += mat[i][j];
       ++i;
   }while(i != n);
     return result;
}

int main()
{
    int mat[MATR_][MATR_];
    int lgn, col;
    printf("Nombre de lignes: ");
    scanf("%d", &lgn);
    printf("Nombre de colonnes: ");
    scanf("%d", &col);

    SaisieM(mat, lgn, col);

    int tmp;
    tmp = 0;
    do
    {
        printf(" La somme des elements de la ligne numero %d est: %d \n", tmp, Sommes(mat, tmp, col));
        tmp++;
    }while(tmp != lgn);

    printf("Sommes des elements diagonaux 1 est: %d \n", SommeD1(mat, lgn, col));
    printf("Sommes des elements diagonaux 2 est: %d \n", SommeD2(mat, lgn, col));
    return 0;
}
