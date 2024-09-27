#include<stdio.h>

int buscaBinariaIt(int vet[], int n, int x){
    int esq = 0, dir = n-1, meio;
    while(esq <= dir) {
        meio = (esq + dir)/2;
        if (vet[meio] == x) 
            return meio;
        if (vet[meio] > x)
            dir = meio - 1;
        else
            esq = meio + 1;
    }
    return -1;
}

int buscaBinariaRec(int vet[], int esq, int dir, int x){
    if (esq > dir)
        return -1;
    int meio = (esq + dir)/2;
    if (vet[meio] > x)
        return buscaBinariaRec(vet, esq, meio-1, x);
    if (vet[meio] < x)
        return buscaBinariaRec(vet, meio+1, dir, x);
    return meio;
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

    printf("\nBUSCA BINARIA ITERATIVA: ");
    res = buscaBinariaIt(vet, n, x);
    if (res == -1)
        printf("Elemento %d nao encontrado!\n", x);
    else
        printf("Elemento %d encontrado na posicao %d\n", x, res);

    printf("\nBUSCA BINARIA RECURSIVA: ");
    res = buscaBinariaRec(vet, 0, n-1, x);
    if (res == -1)
        printf("Elemento %d nao encontrado!\n", x);
    else
        printf("Elemento %d encontrado na posicao %d\n", x, res);
}