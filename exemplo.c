#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("**********************\n");
    printf("Bem-vindo ao Jogo de Adivinhacao *\n");
    printf("**********************\n\n");

    int vidas = 8;
    char resposta = 's';
    int chute;
    srand(time(NULL));
    int numeroSecreto = (rand() % 100) + 1;
    int validarNumero;

    while (resposta == 's')
    {
        while (vidas > 0)
        {

            do
            {
                if (vidas == 8)
                {
                    printf("Digite um numero para tentar acertar o numero secreto de 1 a 100: ");
                    validarNumero = scanf("%d", &chute);
                }
                else
                {
                    printf("Tente novamente: ");
                    validarNumero = scanf("%d", &chute);
                }
                if (validarNumero == 0)
                {
                    printf("\nApenas numeros!\n\n");

                    int c;

                    while ((c = getchar()) != '\n' && c != EOF)
                    {
                    }
                }
            } while (validarNumero == 0);

            if (chute != numeroSecreto)
            {
                vidas--;
            }

            // printf("numero Secreto: %d\n", numeroSecreto);
            
            if (vidas > 0)
            {
                printf("\n#############################################\n");
                printf("\nvoce tem %d vidas!\n\n", vidas);
            }

            if (chute < numeroSecreto && vidas > 0)
            {
                printf("Seu chute foi menor que o numero secreto\n\n");
            }
            else if (chute > numeroSecreto && vidas > 0)
            {
                printf("Seu chute foi maior que o numero secreto\n\n");
            }
            if (chute == numeroSecreto)
            {
                printf("Parabens! voce acertou, o numero era: %d\n", numeroSecreto);
            }

            if (vidas == 0)
            {
                printf("\nVoce perdeu, o numero secreto era: %d\n", numeroSecreto);
            }

            if (vidas == 0 || chute == numeroSecreto)
            {
                do
                {
                    printf("\nVoce deseja tentar novamente? s para sim e n para nao: ");
                    scanf(" %c", &resposta);

                    if (resposta != 's' && resposta != 'n')
                    {
                        printf("Apenas s ou n\n");
                    }
                } while (resposta != 's' && resposta != 'n');
                break;
            }
        }

        if (resposta == 's')
        {
            numeroSecreto = (rand() % 100) + 1;
            vidas = 8;
        }
        if (resposta == 'n')
        {
            printf("\nObrigado por jogar!");
            return 0;
        }
    }
    return 0;
}