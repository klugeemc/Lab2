#include <stdio.h>

void imprimir(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void inverter(int *vetor, int tamanho)
{
    int vetor2[tamanho];
    for (int i = 0; i < tamanho; i++)
    {

        vetor2[i] = vetor[4 - i];
    }
    imprimir(vetor2, tamanho);
}
void ordenar(int *vetor, int tamanho)
{
    int aux, i, j;

    // Loop externo: controla o número de passagens
    for (j = 0; j < tamanho - 1; j++)
    {
        // Loop interno: realiza as comparações e trocas
        for (i = 0; i < tamanho - 1 - j; i++)
        {

            if (vetor[i] < vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
    imprimir(vetor, tamanho);
}
void maior_valor(int *vetor, int tamanho)
{
    int maior = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
    printf("maior valor: %d\n", maior);
}
void menor_valor(int *vetor, int tamanho)
{
    int menor = vetor[0];
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }
    printf("menor valor: %d\n", menor);
}
int media(int *vetor, int tamanho)
{
    int soma = 0, media;
    for (int i = 0; i < tamanho; i++)
    {
        soma = soma + vetor[i];
    }
    media = soma / tamanho;
    return media;
}
int acima_media(int *vetor, int tamanho, int media)
{
    int cont = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] > media)
        {
            cont++;
        }
    }
    return cont;
}
int main()
{
    int vetor[5], tamanho = 5;
    printf("digite os elementos do vetor\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &vetor[i]);
    }
    printf("vetor:\n");
    imprimir(vetor, tamanho);
    printf("vetor invertido:\n");
    inverter(vetor, tamanho);
    printf("vetor ordenado:\n");
    ordenar(vetor, tamanho);
    maior_valor(vetor, tamanho);
    menor_valor(vetor, tamanho);
    printf("media: %d\n", media(vetor, tamanho));
    printf("quantidade de elementos acima da media: %d", acima_media(vetor, tamanho, media(vetor, tamanho)));
}
