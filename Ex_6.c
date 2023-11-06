#include <stdio.h>

#define NUM_FILIAIS 4

typedef struct {
    int filial;
    float valorVenda;
} Venda;

int main() {
    FILE *arquivo;
    char nomeArquivo[100];
    Venda vendas[NUM_FILIAIS] = {0}; 
    float totalVendas[NUM_FILIAIS] = {0}; 
    int contagemVendas[NUM_FILIAIS] = {0}; 

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    Venda vendaLida;

    while (fscanf(arquivo, "%d,%f\n", &vendaLida.filial, &vendaLida.valorVenda) == 2) {
        if (vendaLida.filial >= 1 && vendaLida.filial <= NUM_FILIAIS) {
            int indice = vendaLida.filial - 1;
            vendas[indice].filial = vendaLida.filial;
            vendas[indice].valorVenda += vendaLida.valorVenda;
            totalVendas[indice] += vendaLida.valorVenda;
            contagemVendas[indice]++;
        }
    }

    printf("Total e valor médio das vendas por filial:\n");

    for (int i = 0; i < NUM_FILIAIS; i++) {
        printf("Filial %d - Total: R$ %.2f - Valor médio: R$ %.2f\n",
               vendas[i].filial,
               totalVendas[i],
               contagemVendas[i] > 0 ? totalVendas[i] / contagemVendas[i] : 0);
    }

    fclose(arquivo);

    return 0;
}
