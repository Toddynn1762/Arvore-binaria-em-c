#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 100

typedef struct no {
    int chave;
    char nome[MAX_NAME];
    struct no* dir;
    struct no* esq;
} No;

No* criarNo(int chave, char* nome) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    strcpy(novoNo->nome, nome);
    novoNo->esq = novoNo->dir = NULL;
    return novoNo;
}

No* inserirNo(No* raiz, int chave, char* nome) {
    if (raiz == NULL) {
        return criarNo(chave, nome);
    }
    if (chave < raiz->chave) {
        raiz->esq = inserirNo(raiz->esq, chave, nome);
    } else if (chave > raiz->chave) {
        raiz->dir = inserirNo(raiz->dir, chave, nome);
    }
    return raiz;
}

char* procurarChave(No* raiz, int chave) {
    if (raiz == NULL) {
        return NULL;
    }
    if (chave == raiz->chave) {
        return raiz->nome;
    } else if (chave < raiz->chave) {
        return procurarChave(raiz->esq, chave);
    } else {
        return procurarChave(raiz->dir, chave);
    }
}

No* menorChave(No* raiz) {
    while (raiz && raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

No* maiorChave(No* raiz) {
    while (raiz && raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz;
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("chave: %d, Nome: %s\n", raiz->chave, raiz->nome);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("chave: %d, Nome: %s\n", raiz->chave, raiz->nome);
        emOrdem(raiz->dir);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("Chave: %d, Nome: %s\n", raiz->chave, raiz->nome);
    }
}

int main() {
    No* raiz = NULL;
    int op, chave;
    char nome[MAX_NAME];

    No* resultado;

    while (1) {
        printf("//MENU//\n");
        printf("1. Inserir No\n");
        printf("2. Procurar chave\n");
        printf("3. Procurar a menor chave\n");
        printf("4. Procurar nome com a menor chave\n");
        printf("5. Procurar a maior chave\n");
        printf("6. Procurar nome com a maior chave\n");
        printf("7. Exibir pre-ordem\n");
        printf("8. Exibir em-ordem\n");
        printf("9. Exibir pos-ordem\n");
        printf("10. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                printf("Digite o nome: ");
                scanf("%s", nome);
                raiz = inserirNo(raiz, chave, nome);
                break;

            case 2:
                printf("Digite a chave para procurar: ");
                scanf("%d", &chave);
                char* chaveResultado = procurarChave(raiz, chave);
                if (chaveResultado) {
                    printf("Chave: %d, Nome: %s\n", chave, chaveResultado);
                } else {
                    printf("Chave nao encontrada.\n");
                }
                break;

            case 3:
                resultado = menorChave(raiz);
                if (resultado) {
                    printf("A menor chave eh: %d\n", resultado->chave);
                } else {
                    printf("A arvore esta vazia!\n");
                }
                break;

            case 4:
                resultado = menorChave(raiz);
                if (resultado) {
                    printf("O nome com a menor chave eh: %s\n", resultado->nome);
                } else {
                    printf("A arvore esta vazia!\n");
                }
                break;

            case 5:
                resultado = maiorChave(raiz);
                if (resultado) {
                    printf("A maior chave eh: %d\n", resultado->chave);
                } else {
                    printf("A arvore esta vazia!\n");
                }
                break;

            case 6:
                resultado = maiorChave(raiz);
                if (resultado) {
                    printf("O nome com a maior chave eh: %s\n", resultado->nome);
                } else {
                    printf("A arvore esta vazia!\n");
                }
                break;

            case 7:
                printf("Percorrer em pre-ordem:\n");
                preOrdem(raiz);
                break;

            case 8:
                printf("Percorrer em-ordem:\n");
                emOrdem(raiz);
                break;

            case 9:
                printf("Percorrer em pos-ordem:\n");
                posOrdem(raiz);
                break;

            case 10:
                exit(0);

            default:
                printf("Opcao invalida.\n");
        }
    }
    return 0;
}
