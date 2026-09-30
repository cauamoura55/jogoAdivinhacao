#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validarNumero(int *chute)
{
    int resultado;

    resultado = scanf("%d", chute);

    if (resultado != 1)
    {
        int c;

        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        return 0;
    }

    if (*chute > 0 && *chute < 101)
    {
        return 1;
    }

    return 0;
}

int main()
{
    printf("**********************\n");
    printf("Bem-vindo ao Jogo de Adivinhacao *\n");
    printf("**********************\n\n");

    int vidas = 1;
    char resposta = 's';
    int chute;
    char dificuldade;
    srand(time(NULL));
    int numeroSecreto = (rand() % 100) + 1;

    while (resposta == 's')
    {
        int tentativas = 1;
        printf("numero Secreto: %d\n", numeroSecreto);

        do
        {
            printf("Selecione sua dificuldade -> f (facil), m (medio) e d (dificil): ");
            scanf(" %c", &dificuldade);

            if (dificuldade != 'f' && dificuldade != 'm' && dificuldade != 'd')
            {
                printf("\nApenas f, m ou d!\n");
            }

        } while (dificuldade != 'f' && dificuldade != 'm' && dificuldade != 'd');

        if (dificuldade == 'f')
        {
            numeroSecreto = (rand() % 10) + 1;
        }

        if (dificuldade == 'm')
        {
            numeroSecreto = (rand() % 100) + 1;
        }

        if (dificuldade == 'd')
        {
            numeroSecreto = (rand() % 1000) + 1;
        }
        do
        {
            printf("numero Secreto 1 a 10: %d\n", numeroSecreto);

            printf("Escolha sua quantidade de vidas de 1 a 10: ");

            while (!validarNumero(&vidas))
            {
                printf("Apenas numeros! Digite novamente: ");
            }
            if (vidas <= 0 || vidas >= 11)
            {
                printf("\nApenas de 1 a 10\n");
            }
        } while (vidas <= 0 || vidas >= 11);

        while (vidas > 0)
        {

            if (tentativas == 1)
            {
                printf("Digite um numero para tentar acertar o numero secreto de 1 a 100: ");
                tentativas = 0;
            }
            else
            {
                printf("Tente novamente: ");
            }
            while (!validarNumero(&chute))
            {
                printf("Apenas numeros de 1 a 100! Digite novamente: ");
            }

            if (chute != numeroSecreto)
            {
                vidas--;
            }

            printf("\n#############################################\n\n");

            if (chute < numeroSecreto && vidas > 0)
            {
                printf("Seu chute foi menor que o numero secreto\n\n");
            }
            else if (chute > numeroSecreto && vidas > 0)
            {
                printf("Seu chute foi maior que o numero secreto\n\n");
            }

            if (vidas > 0 && chute != numeroSecreto)
            {
                printf("voce tem %d vida(s)!\n\n", vidas);
            }

            if (chute == numeroSecreto)
            {
                printf("Parabens! voce acertou, o numero secreto era: %d\n", numeroSecreto);
            }

            if (vidas == 0)
            {
                printf("Voce perdeu, o numero secreto era: %d\n", numeroSecreto);
            }

            if (vidas == 0 || chute == numeroSecreto)
            {
                do
                {
                    printf("\nVoce deseja tentar novamente? s para sim e n para nao: ");
                    scanf(" %c", &resposta);

                    if (resposta != 's' && resposta != 'n')
                    {
                        printf("\nApenas s ou n\n");
                    }
                } while (resposta != 's' && resposta != 'n');
                break;
            }
        }

        if (resposta == 'n')
        {
            printf("\nObrigado por jogar!");
            return 0;
        }
    }
    return 0;
}