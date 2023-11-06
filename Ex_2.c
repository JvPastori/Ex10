#include <stdio.h>

int main() {
    FILE *arquivoEntrada, *arquivoSaida;
    char nomeArquivoEntrada[100];
    char caractere;

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    arquivoEntrada = fopen(nomeArquivoEntrada, "r");

    if (arquivoEntrada == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.");
        return 1;
    }

    arquivoSaida = fopen("saida.txt", "w");

    if (arquivoSaida == NULL) {
        printf("Não foi possível criar o arquivo de saída.");
        return 1;
    }

    while ((caractere = fgetc(arquivoEntrada)) != EOF) {
        if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u' ||
            caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U') {
            fputc('*', arquivoSaida);
        } else {
            fputc(caractere, arquivoSaida);
        }
    }

    printf("Texto com vogais substituídas por '*' foi salvo no arquivo 'saida.txt'.\n");

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 0;
}

