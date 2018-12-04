// Lista 8:
// 1:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Oi, Ana. Através desse script estou fazendo esse mini tutorial.
- Ponteiros e alocação dinâmica:
int *p; - Define-se uma variável apontadora. Seja para arquivo, conjunto de bits, etc ...
* -> Valor da posição de memoria cujo o ponteiro aponta.
& -> Posição de memoria cujo o ponteiro aponta.

# Ponteiros e vetores: Todo ponteiro pode ser um vetor, basta considerarmos posição de memoria cujo
o ponteiro aponta e somarmos 1 a ela.

#Alocação dinâmica: Aloca durante a execução do programa e não antes da execução.
malloc -> memory allocation.
malloc(n): Retorna um ponteiro capaz de armazenar n bytes.
sizeof(type): tamanho em bytes necessário para armazenar qualquer variável do tipo (type).
- Casting: Forçar a variável a ser do tipo (type). Como o malloc() retorna um ponteiro pra apontar
um vetor de qualquer tipo, precisamos forçar q o ponteiro seja do tio (type). Veja o exemplo abaixo:
Exemplo: Alocar um espaço de memoria para armazenar 4 inteiros.
int *p = (int *)malloc(4*(sizeof(int))); -> Observe que (int *) é o nosso casting.
- Para acessar o primeiro valor apontado pelo ponteiro p: p[0] ou *(p + 0) ou *p
- Para acessar o segundo valor apontado pelo ponteiro p : p[1] ou *(p + 1) ou *(p++)
- Para acessar o segundo valor apontado pelo ponteiro p : p[1] ou *(p + 2)
- Para acessar o segundo valor apontado pelo ponteiro p : p[1] ou *(p + 3)

free(p) -> Desaloca a porção de memoria alocada por malloc, porém os valores modificados não mudam, virando assim lixo de memória.
realloc(p, n)) -> Aloca um novo bloco de n bytes para o ponteiro p.

*/

// Questão 1:
void imprimeVetor(int *vetor, int n)
{
    printf("\nVetor: ");
    for (int i=0;i<n;i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int* criaVetor(int n)
{
    int *vetor = (int *)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        printf("Digite aqui o valor da posicao %d do vetor: ", i);
        scanf("%d",&vetor[i]);
    }
    return vetor;
}

// Questão 2:
char* criaString(int n)
{
    char *string = (char *)malloc(n * sizeof(char));
    printf("Digite aqui sua string: ");
    for(int i=0;i<n;i++)
    {
        scanf("%c",&string[i]);
    }
    *(string + n) = '\0';
    return string;
}

void tira_vogal(char *string, int n)
{
    char *auxstring = (char *)malloc(n * sizeof(char));
    int j=0;
    for (int i=0;i<n;i++)
    {
        if (((((*(string + i) != 'a') || (*(string + i) != 'e')) || (*(string + i) != 'i')) || (*(string + i) != 'o')) || (*(string + i) != 'u'))
        {
            *(auxstring + j) = *(string + i); // Enquanto string diferente de vogal, uma string auxiliar pega o valor da posição i da string cm valor não vogal e armazena na posição j.
            j++;
        }
    }
    *(auxstring + j) = '\0'; // Determina o final da string
    strcpy(string,auxstring); // Armazena o valor da auxstring na string.
    free(auxstring); // Libera os bits reservados para o ponteiro auxstring de volta para o sistema operacional.
}

// Questão 3:

int** criaMatrizInt(int m, int n)
{
    int **matriz = (int**)malloc(m * sizeof(int*));
    for (int i=0;i<m;i++)
    {
        matriz[i] = (int*)malloc(n * sizeof(int));
        for(int j=0;j<n;j++)
        {
            printf("Matriz[%d][%d] = ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    return matriz;
}

int localiza_maior_matriz(int **matriz, int m,int n)
{
    int a = matriz[0][0];
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (a < matriz[i][j])
            {
               a = matriz[i][j]; 
            }
        }
    }
    return a;
}
int main(void)
{
    int i,n,m;
    printf("Digite o numero da questao: ");
    scanf("%d",&i);
    switch(i)
    {
        case 1: // Main da questão 1.
            printf("Digite a quantidade de numeros inteiros a serem alocados: ");
            scanf("%d",&n);
            int *numeros;
            numeros = criaVetor(n);
            imprimeVetor(numeros, n);
            free(numeros);
            break;
        case 2: // Main da questão 2.
            printf("Digite o tamanho de uma string: ");
            scanf("%d",&n);
            char *string;
            string = criaString(n);
            tira_vogal(string,n);
            printf("%s",string);
            free(string);
            break;
        case 3: // Main da questão 3.
            printf("Digite a quantidade de linhas x colunas da matriz: ");
            scanf("%d x %d",&m,&n);
            int **matriz = criaMatrizInt(m,n);
            printf("%d",localiza_maior_matriz(matriz,m,n));
            break;
    }
    return 0;
}