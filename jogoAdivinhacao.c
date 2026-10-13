#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Verifica se o usuario digitou um numero inteiro
int validarNumero(int *numero)
{
    int resultado = scanf("%d", numero);

    if (resultado != 1)
    {
        int c;

        // Limpa a entrada caso o usuario digite algo invalido
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }

        return 0;
    }

    return 1;
}

// Confere se o chute esta dentro do intervalo da dificuldade
int validarIntervalo(int *chute, char *dificuldade)
{
    switch (*dificuldade)
    {
        case 'f':
            return *chute >= 1 && *chute <= 10;

        case 'm':
            return *chute >= 1 && *chute <= 100;

        case 'd':
            return *chute >= 1 && *chute <= 1000;

        default:
            return 0;
    }
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

    srand(time(NULL)); // Inicializa o gerador de numeros aleatorios
    int numeroSecreto;


    // Repete tudo assim que o jogador disser "S" e inicializa o loop
    while (resposta == 's')
    {
        int tentativas = 1;

        // O jogador escolhe a dificuldade
        do
        {
            printf("Selecione sua dificuldade -> f (facil), m (medio) e d (dificil): ");
            scanf(" %c", &dificuldade);

            if (dificuldade != 'f' && dificuldade != 'm' && dificuldade != 'd')
            {
                printf("\nApenas f, m ou d!\n");
            }

        } while (dificuldade != 'f' && dificuldade != 'm' && dificuldade != 'd');

        // Sorteia um numero de acordo com a dificuldade escolhida
        switch (dificuldade)
        {
            case 'f':
                numeroSecreto = (rand() % 10) + 1;
                break;

            case 'm':
                numeroSecreto = (rand() % 100) + 1;
                break;

            case 'd':
                numeroSecreto = (rand() % 1000) + 1;
                break;
        }

        // O jogador escolhe quantas vidas ele quer
        do
        {
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
            // Mostra uma mensagem diferente no primeiro chute
            if (tentativas == 1)
            {
                switch (dificuldade)
                {
                    case 'f':
                        printf("\nDigite um numero de 1 a 10: ");
                        break;

                    case 'm':
                        printf("\nDigite um numero de 1 a 100: ");
                        break;

                    case 'd':
                        printf("\nDigite um numero de 1 a 1000: ");
                        break;
                }
            }
            else
            {
                printf("\nTente novamente: ");
            }

            // Repete a leitura ate receber um chute dentro do escopo correto
            while (1)
            {
                while (!validarNumero(&chute))
                {
                    printf("Apenas numeros, digite novamente: ");
                }

                if (validarIntervalo(&chute, &dificuldade))
                {
                    break;
                }

                printf("Numero fora do escopo! Digite novamente: ");
            }

            // Perde uma vida quando erra o numero secreto
            if (chute != numeroSecreto)
            {
                vidas--;
            }

            tentativas++;

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

            // Pergunta se o jogador quer iniciar outra partida
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
