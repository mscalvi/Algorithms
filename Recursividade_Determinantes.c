#include<stdio.h>
#define MAXN 100

void mostrar_matriz(int mat[MAXN][MAXN], int n){
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void menor_complementar(int mc[MAXN][MAXN], int mat[MAXN][MAXN], int n, int l, int c){
    int i_real = 0, j_real;
    for(int i = 0; i < n; i++)
    {
        if (i == l)
            continue;
        j_real = 0;
        for(int j = 0; j < n; j++){
            if (j == c)
                continue;
            mc[i_real][j_real] = mat[i][j];
            j_real++;
        }
        i_real++;
    }
}

int determinante(int mat[MAXN][MAXN], int n)
{
    if (n == 1)
        return mat[0][0];
    int mc[MAXN][MAXN];
    int det = 0;
    int sinal = 1;
    for(int j = 0; j < n; j++){
        menor_complementar(mc, mat, n, 0, j);
        det += sinal * mat[0][j] * determinante(mc, n-1);
        sinal *= -1;
    }
    return det;
}

int main()
{
    int mat[MAXN][MAXN];
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Determinante: %d", determinante(mat, n));
}