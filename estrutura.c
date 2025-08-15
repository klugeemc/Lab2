#include <stdio.h>

struct usuario
{
    int idade;
    int qtdade;
};
typedef struct usuario Usuario;

void leVetor(int n, Usuario *vet)
{
    for (int i = 0; i < n; i++)
    {
        printf("Digite a idade do usuario %d:\n", i + 1);
        scanf("%d", &vet[i].idade);
        printf("Digite a quantidade de livros lidos pelo usuario %d:\n", i + 1);
        scanf("%d", &vet[i].qtdade);
    }
}

int calculaQtidadeLivros(int n, Usuario *vet)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i].idade < 18)
        {
            cont = vet[i].qtdade + cont;
        }
    }
    return cont;
}

float calculaMedia(int n, Usuario *vet)
{
    float soma = 0;
    float media;
    for (int i = 0; i < n; i++)
    {
        soma = vet[i].qtdade + soma;
    }
    media = soma / n;
    return media;
}

int main()
{
    int n;
    printf("Quantos usuarios serao armazenados?\n");
    scanf("%d", &n);

    Usuario vet[n];

    leVetor(n, vet);
    
    printf("\nQuantidade de livros lidos por menores de 18 anos: %d\n", calculaQtidadeLivros(n, vet));
    printf("Media de livros lidos pelos usuarios: %f\n", calculaMedia(n, vet));


    return 0;
}