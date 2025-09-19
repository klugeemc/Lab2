#include <stdio.h>
#include <stdlib.h>

char **alocar(int N)
{
    char **matriz = (char **)malloc(N * sizeof(char *));
    if (matriz == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        matriz[i] = (char *)malloc(N * sizeof(char));
        if (matriz[i] == NULL)
        {
            printf("Erro de alocação de memória\n");
            for (int j = 0; j < i; j++)
                free(matriz[j]);
            free(matriz);
            exit(1);
        }
    }
    return matriz;
}

void desalocar(char **matriz, int N)
{
    for (int i = 0; i < N; i++)
        free(matriz[i]);
    free(matriz);
}

void inicializar(char **matriz, int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matriz[i][j] = ' ';
}

void imprimir(char **matriz, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("|%c", matriz[i][j]);
        }
        printf("|\n");
        for (int k = 0; k < N; k++)
            printf("--");
        printf("-\n");
    }
    printf("\n");
}

int verifica_cheio(char **matriz, int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matriz[i][j] == ' ')
                return 0;
    return 1;
}

int jogada(char **matriz, int N, char peca, int l, int c)
{
    if (l < 0 || l >= N || c < 0 || c >= N)
        return 0;
    if (matriz[l][c] == ' ')
    {
        matriz[l][c] = peca;
        return 1;
    }
    return 0;
}

int verifica_vitoria(char **matriz, int N)
{
    // linhas
    for (int i = 0; i < N; i++)
    {
        char p = matriz[i][0];
        if (p != ' ')
        {
            int ganhou = 1;
            for (int j = 1; j < N; j++)
                if (matriz[i][j] != p)
                {
                    ganhou = 0;
                    break;
                }
            if (ganhou)
            {
                printf("Parabéns, o %c ganhou!\n", p);
                return 1;
            }
        }
    }

    // colunas
    for (int j = 0; j < N; j++)
    {
        char p = matriz[0][j];
        if (p != ' ')
        {
            int ganhou = 1;
            for (int i = 1; i < N; i++)
                if (matriz[i][j] != p)
                {
                    ganhou = 0;
                    break;
                }
            if (ganhou)
            {
                printf("Parabéns, o %c ganhou!\n", p);
                return 1;
            }
        }
    }

    // diagonal principal
    char p = matriz[0][0];
    if (p != ' ')
    {
        int ganhou = 1;
        for (int i = 1; i < N; i++)
            if (matriz[i][i] != p)
            {
                ganhou = 0;
                break;
            }
        if (ganhou)
        {
            printf("Parabéns, o %c ganhou!\n", p);
            return 1;
        }
    }

    // diagonal secundária
    p = matriz[0][N - 1];
    if (p != ' ')
    {
        int ganhou = 1;
        for (int i = 1; i < N; i++)
            if (matriz[i][N - 1 - i] != p)
            {
                ganhou = 0;
                break;
            }
        if (ganhou)
        {
            printf("Parabéns, o %c ganhou!\n", p);
            return 1;
        }
    }

    return 0;
}

int main()
{
    int N, l, c;
    char op;

    do
    {
        printf("Digite o tamanho do tabuleiro (>=3): ");
        scanf("%d", &N);

        if (N < 3)
        {
            printf("O tamanho mínimo é 3!\n");
            continue;
        }

        char **matriz = alocar(N);
        inicializar(matriz, N);

        int fim = 0;
        imprimir(matriz, N);
        while (!fim)
        {
            do
            {
                printf("\nJogador X, digite linha e coluna (0 a %d): ", N - 1);
                scanf("%d %d", &l, &c);
            } while (!jogada(matriz, N, 'X', l, c));
            imprimir(matriz, N);
            if (verifica_vitoria(matriz, N))
            {
                fim = 1;
                break;
            }
            if (verifica_cheio(matriz, N))
            {
                printf("Empate!\n");
                break;
            }

            do
            {
                printf("\nJogador O, digite linha e coluna (0 a %d): ", N - 1);
                scanf("%d %d", &l, &c);
            } while (!jogada(matriz, N, 'O', l, c));
            imprimir(matriz, N);
            if (verifica_vitoria(matriz, N))
            {
                fim = 1;
                break;
            }
            if (verifica_cheio(matriz, N))
            {
                printf("Empate!\n");
                break;
            }
        }

        desalocar(matriz, N);

        printf("\nDeseja jogar de novo? (s/n): ");
        scanf(" %c", &op);

    } while (op == 's' || op == 'S');

    return 0;
}