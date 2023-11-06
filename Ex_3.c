#include <stdio.h>

int main() {
    FILE *arquivo1, *arquivo2, *arquivo3;
    char nomeArquivo1[100], nomeArquivo2[100], caractere;

    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", nomeArquivo1);

    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", nomeArquivo2);

    arquivo1 = fopen(nomeArquivo1, "r");
    arquivo2 = fopen(nomeArquivo2, "r");

    if (arquivo1 == NULL || arquivo2 == NULL) {
        printf("Não foi possível abrir um dos arquivos.");
        return 1;
    }

    arquivo3 = fopen("terceiro_arquivo.txt", "w");

    if (arquivo3 == NULL) {
        printf("Não foi possível criar o terceiro arquivo.");
        return 1;
    }

    while ((caractere = fgetc(arquivo1)) != EOF) {
        fputc(caractere, arquivo3);
    }

    while ((caractere = fgetc(arquivo2)) != EOF) {
        fputc(caractere, arquivo3);
    }

    printf("Conteúdo dos arquivos foi combinado e salvo no arquivo 'terceiro_arquivo.txt'.\n");

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);

    return 0;
}
