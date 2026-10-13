# Jogo de Adivinhação em C

Um jogo de adivinhação desenvolvido em **linguagem C**, no qual o jogador deve descobrir um número secreto gerado aleatoriamente pelo computador. O jogo permite escolher o nível de dificuldade, definir a quantidade de vidas e tentar novamente após vencer ou perder.

## Funcionalidades

- **Geração de números aleatórios:** o computador sorteia um número secreto.
- **Três níveis de dificuldade:**
  - **Fácil:** números de 1 a 10.
  - **Médio:** números de 1 a 100.
  - **Difícil:** números de 1 a 1000.
- **Sistema de vidas:** o jogador escolhe entre 1 e 10 vidas antes de começar a adivinhar.
- **Dicas durante a partida:** o jogo informa se o chute foi maior ou menor que o número secreto.
- **Opção de jogar novamente:** após acertar ou perder, o jogador pode iniciar outra partida.
- **Validação de entradas:** o programa verifica se as entradas são numéricas e se as opções selecionadas são válidas.

## Tecnologias utilizadas

- **Linguagem:** C
- **Bibliotecas:**
  - `stdio.h` — entrada e saída de dados.
  - `stdlib.h` — geração de números pseudoaleatórios.
  - `time.h` — inicialização do gerador de números aleatórios com base no horário.

## Como executar

### 1. Pré-requisitos

Tenha um compilador C instalado, como o GCC.

### 2. Clone o repositório

```bash
git clone URL_DO_SEU_REPOSITORIO
```

Substitua `URL_DO_SEU_REPOSITORIO` pelo endereço do seu repositório no GitHub.

### 3. Entre na pasta do projeto

```bash
cd NOME_DA_PASTA
```

### 4. Compile o programa

Se o arquivo principal se chamar `main.c`, execute:

```bash
gcc main.c -o jogo
```

### 5. Execute o jogo

No Windows:

```bash
.\jogo.exe
```

No Linux:

```bash
./jogo
```

## Como jogar

1. Inicie o programa.
2. Escolha a dificuldade digitando `f` para fácil, `m` para médio ou `d` para difícil.
3. Defina a quantidade de vidas, de 1 a 10.
4. Digite seus palpites para tentar descobrir o número secreto.
5. Use as dicas de números maiores ou menores para orientar suas próximas tentativas.
6. Acerte o número antes de perder todas as vidas.
7. Ao terminar, escolha `s` para jogar novamente ou `n` para encerrar.

## Objetivo do projeto

Este projeto tem como objetivo praticar conceitos fundamentais da linguagem C, incluindo:

- Variáveis e tipos de dados.
- Estruturas condicionais (`if`, `else` e `switch`).
- Estruturas de repetição (`while` e `do-while`).
- Funções e passagem de parâmetros por ponteiros.
- Entrada e saída de dados com `scanf` e `printf`.
- Geração de números pseudoaleatórios com `rand()` e `srand()`.
- Validação de entradas fornecidas pelo usuário.

## Autor
Cauã Moura
Desenvolvido como projeto de estudo para praticar lógica de programação e os fundamentos da linguagem C.
