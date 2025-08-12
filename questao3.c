#include <stdio.h>

void imprimir(int *vetor)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void inverter(int *vetor)
{
    int vetor2[5];
    for (int i = 0; i < 5; i++)
    {

        vetor2[i] = vetor[4 - i];
    }
    imprimir(vetor2);
}
void ordenar(int *vetor)
{
    int aux, i, j;

    // Loop externo: controla o número de passagens
    for (j = 0; j < 4; j++)
    {
        // Loop interno: realiza as comparações e trocas
        for (i = 0; i < 4 - j; i++)
        {

             if (vetor[i] < vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
    imprimir(vetor);
}

int main()
{
    int vetor[5];
    printf("digite os elementos do vetor\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &vetor[i]);
    }
    imprimir(vetor);
    inverter(vetor);
    ordenar(vetor);
}
