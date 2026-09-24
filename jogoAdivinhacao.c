#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validarNumero(int *chute)
{
    int resultado;
    resultado = scanf("%d", chute);
    if (resultado == 1)
    {
        return 1;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
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
    srand(time(NULL));

    while (resposta == 's')
    {
        int tentativas = 1;
        int numeroSecreto = (rand() % 100) + 1;
        printf("numero Secreto: %d\n", numeroSecreto);
        do
        {
            printf("Digite a quantidade de vidas que voce quer: ");
            
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
                printf("Apenas numeros! Digite novamente: ");
            }

            if (chute != numeroSecreto)
            {
                vidas--;
            }

            if (vidas > 0 || chute == numeroSecreto)
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
            vidas = 1;
        }
        if (resposta == 'n')
        {
            printf("\nObrigado por jogar!");
            return 0;
        }
    }
    return 0;
}