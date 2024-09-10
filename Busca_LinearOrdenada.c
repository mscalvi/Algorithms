#include<stdio.h>

int buscaLinearOrdIt(int vet[], int n, int x){
    int i;
    for(i = 0; i < n; i++)
        if (vet[i] == x)
            return i;
        else if (vet[i] > x)
            return -1;
    return -1;
}

int buscaLinearOrdRec(int vet[], int n, int x){
    if (n == 0 || vet[n-1] < x)
        return -1;
    if (vet[n-1] == x)
        return n-1;
    return buscaLinearOrdRec(vet, n-1, x);
}

int main()
{
    int n, i, x, res, vet[50];

    printf("Digite um numero entre 1 e 50: ");
    do{
        scanf("%d", &n);
    } while(n < 1 || n > 50);
    printf("\nDigite os elementos do vetor ORDENADO:\n");
    for(i = 0; i < n; i++){
        printf("v[%d] = ", i);
        scanf("%d", &vet[i]);
    }
    printf("\nDigite um numero a ser buscado no vetor: ");
    scanf("%d", &x);

    printf("\nBUSCA LINEAR ITERATIVA: ");
    res = buscaLinearOrdIt(vet, n, x);
    if (res == -1)
        printf("Elemento %d nao encontrado!\n", x);
    else
        printf("Elemento %d encontrado na posicao %d\n", x, res);

    printf("\nBUSCA LINEAR RECURSIVA: ");
    res = buscaLinearOrdRec(vet, n, x);
    if (res == -1)
        printf("Elemento %d nao encontrado!\n", x);
    else
        printf("Elemento %d encontrado na posicao %d\n", x, res);
}