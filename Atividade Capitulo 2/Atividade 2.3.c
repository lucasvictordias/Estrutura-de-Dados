#include <stdio.h>
#include <stdlib.h>

typedef struct plv {
    char conteudo;
    struct plv *prox;
} palavra;

void empilha(char c, palavra *topo) {
    palavra *nova = malloc(sizeof(palavra));
    nova->conteudo = c;
    nova->prox = topo->prox;
    topo->prox = nova;
}

char desempilha(palavra *topo) {
    palavra *p = topo->prox;
    char c = p->conteudo;
    topo->prox = p->prox;
    free(p);
    return c;
}

int main() {
    char frase[50];
    palavra cabeca;
    palavra *topo = &cabeca;
    topo->prox = NULL;
    printf("Digite a palavra para ser invertida:  \n");
    fgets(frase, 50, stdin);
    for (int i = 0; frase[i] != '\0'; i++) {
        empilha(frase[i], topo);
    }
    printf("A palavra invertida: \n ");
    while (topo->prox != NULL) {
        putchar(desempilha(topo));
    }

    return 0;
}
