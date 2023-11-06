#include <stdio.h>

int main() {
    char nomeArquivo[100];
    char caractere;
    int contador = 0;
    FILE *arquivo;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    printf("Digite o caractere a ser contado: ");
    scanf(" %c", &caractere);

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.");
        return 1;
    }

    int c;
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == caractere) {
            contador++;
        }
    }

    printf("O caractere '%c' ocorre %d vezes no arquivo.\n", caractere, contador);

    fclose(arquivo);

    return 0;
}
