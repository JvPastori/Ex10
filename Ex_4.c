#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 100
#define TAM_NOME_CIDADE 41

typedef struct {
    char nome[TAM_NOME_CIDADE];
    long habitantes;
} Cidade;

int main() {
    char nomeArquivoEntrada[100];
    char nomeArquivoSaida[100];

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

    Cidade cidades[MAX_CIDADES];
    int quantidadeCidades = 0;

    
    while (fscanf(arquivoEntrada, "%40s %ld\n", cidades[quantidadeCidades].nome, &cidades[quantidadeCidades].habitantes) == 2) {
        quantidadeCidades++;
    }

    if (quantidadeCidades == 0) {
        
        printf("Nenhuma cidade encontrada no arquivo de entrada.\n");
        return 1;
    }

   
    Cidade cidadeMaisPopulosa = cidades[0];
    for (int i = 1; i < quantidadeCidades; i++) {
        if (cidades[i].habitantes > cidadeMaisPopulosa.habitantes) {
            cidadeMaisPopulosa = cidades[i];
        }
    }

    
    fprintf(arquivoSaida, "%s %ld\n", cidadeMaisPopulosa.nome, cidadeMaisPopulosa.habitantes);

    printf("Cidade mais populosa (%s) e seu número de habitantes (%ld) foram salvos no arquivo de saída.\n", cidadeMaisPopulosa.nome, cidadeMaisPopulosa.habitantes);

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 0;
}
