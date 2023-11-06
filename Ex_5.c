#include <stdio.h>

#define TAM_NOME 41

typedef struct {
    char nome[TAM_NOME];
    int anoNascimento;
} Pessoa;

int main() {
    int anoCorrente;
    char nomeArquivoEntrada[100];
    char nomeArquivoSaida[100];

    printf("Digite o ano corrente: ");
    scanf("%d", &anoCorrente);

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nomeArquivoSaida);

    FILE *arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de entrada ou de saída.\n");
        return 1;
    }

    Pessoa pessoa;

    while (fscanf(arquivoEntrada, "%40s %d\n", pessoa.nome, &pessoa.anoNascimento) == 2) {
        int idade = anoCorrente - pessoa.anoNascimento;

        if (idade < 18) {
            fprintf(arquivoSaida, "%s menor de idade\n", pessoa.nome);
        } else if (idade > 18) {
            fprintf(arquivoSaida, "%s maior de idade\n", pessoa.nome);
        } else {
            fprintf(arquivoSaida, "%s entrando na maior idade\n", pessoa.nome);
        }
    }

    printf("Verificações de idade foram salvas no arquivo de saída.\n");

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 0;
}

