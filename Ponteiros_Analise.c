/*

int i = 7, j = 5;
int *p;
int **q;
p = &i;
q = &p;
int c = **q + j;


Passo a passo:
Declaração e Inicialização das Variáveis:

int i = 7; — Declara i como int e atribui o valor 7 a i.
int j = 5; — Declara j como int e atribui o valor 5 a j.
int *p; — Declara p como um ponteiro para int (mas ainda sem valor atribuído).
int **q; — Declara q como um ponteiro para ponteiro de int (também sem valor atribuído).
Atribuições:

p = &i; — O ponteiro p recebe o endereço de i, então p agora aponta para i.
q = &p; — O ponteiro q recebe o endereço de p, então q agora aponta para p.
Cálculo de c:

int c = **q + j;
Aqui, **q significa o valor apontado por q duas vezes.
*q é p, pois q aponta para p.
**q é o valor de i, pois p aponta para i, que tem o valor 7.
Portanto, **q é 7, e j é 5.
Logo, c = 7 + 5;, resultando em c = 12.

*/