#include <stdio.h>
int main()
{
    float p1, p2, p3, media, notamaior;
    printf("digite a nota da prova 1:\n");
    scanf("%f", &p1);
    printf("digite a nota da prova 2:\n");
    scanf("%f", &p2);
    media = (p1 + p2) / 2;
    if (media >= 5 && p1 >= 3 && p2 >= 3)
    {
        printf("Media do aluno: %f, APROVADO", media);
    }
    else
    {
        if (p1 > p2)
        {
            notamaior = p1;
        }
        else
        {
            notamaior = p2;
        }
        printf("digite a nota da prova 3\n");
        scanf("%f", &p3);
        media = (notamaior + p3)/2;
        if (media >= 5)
        {
            printf("Media do aluno: %f, APROVADO", media);
        }
        else
        {
            printf("Media do aluno: %f, REPROVADO", media);
        }
    }
}
