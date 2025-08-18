#include <stdio.h>
void imprimir(int m, int matriz[][6])
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("\n%d\t", matriz[i][j]); // Usei '\t' para separar os valores e deixá-los alinhados.
        }
        printf("\n");
    }
}
void calcular_armazenar(int m, int matriz[][6])
{
    int inc_casos, inc_obitos;
    for (int i = 0; i < m; i++)
    {
        inc_casos = (matriz[i][2] * 100000) / matriz[i][1];
        matriz[i][4] = inc_casos;
        inc_obitos = (matriz[i][3] * 100000) / matriz[i][1];
        matriz[i][5] = inc_obitos;
    }
}
void preencher(int m, int matriz[][6])
{
    for (int i = 0; i < m; i++)
    {
        printf("Digite o codigo do municipio: \n");
        scanf("%d", &matriz[i][0]);
        printf("Digite a quantidade de habitantes do municipio: \n");
        scanf("%d", &matriz[i][1]);
        printf("Digite quantos casos foram confirmados: \n");
        scanf("%d", &matriz[i][2]);
        printf("Digite o numero de obitos: \n");
        scanf("%d", &matriz[i][3]);
    }
    calcular_armazenar(m, matriz);
}
int maior_mortalidade(int m, int matriz[][6])
{
    int cod, maior = 0;

    for (int i = 0; i < m; i++)
    {
        if (maior < matriz[i][5])
        {
            maior = matriz[i][5];
            cod = matriz[i][0];
        }
    }
    return cod;
}
int maior_inc_casos(int m, int matriz[][6])
{
    int cod, maior = 0;

    for (int i = 0; i < m; i++)
    {
        if (maior < matriz[i][4])
        {
            maior = matriz[i][4];
            cod = matriz[i][0];
        }
    }
    return cod;
}
int main()
{
    int m;
    printf("Digite quantos municipios serao armazenados: \n");
    scanf("%d", &m);

    int matriz[m][6];

    preencher(m, matriz);
    imprimir(m, matriz);
    printf("\n o municipio com maior mortalidade: codigo %d \n", maior_mortalidade(m, matriz));
    printf("\n o municipio com maior incidencia de casos: codigo %d \n", maior_inc_casos(m, matriz));
}