#include <stdio.h>

float soma(float *conjunto)
{
    float soma = 0;
    for (int i = 0; i < 3; i++)
    {
        soma = soma + conjunto[i];
    }
    return soma;
}

float media(float soma)
{
    float media;
    media = soma / 3;
    return media;
}

float produto(float *conjunto)
{
    float produto = 1;
    for (int i = 0; i < 3; i++)
    {
        produto = produto * conjunto[i];
    }
    return produto;
}
int main()
{
    float conjunto[3];

    for (int i = 1; i == 1;)
    {
        printf("digite 3 valores em ordem crescente:\n");
        for (int f = 0; f < 3; f++)
        {
            scanf("%f", &conjunto[f]);
        }
        if ((conjunto[0] < conjunto[1]) && conjunto[1]< conjunto[2])
        {
            printf("soma: %f\n", soma(conjunto));
            printf("produto: %f\n", produto(conjunto));
            printf("media: %f\n", media(soma(conjunto)));
        }
        else{
            printf("os valores não estão em ordem");
            i=0;
        }
    }
}
