#include <stdio.h>

//declaração das variavéis (variavéis globais)
char nome[20][50];
int quantidade[20];
float preco[20], ValorFinal[20], desconto[20], total[20];
float totalGeral = 0;
int opcao, i = 0;

//função que faz o cálculo do preço total do produto atual sendo cadastrado
void calcularTotal() {
    total[i] = preco[i] * quantidade[i];
}

// aplicação do desconto
void aplicarDesconto() {
    if (total[i] <= 100) {
        desconto[i] = 0;
    } else if (total[i] > 100 && total[i] <= 250) {
        desconto[i] = 0.05;
    } else if (total[i] > 250 && total[i] <= 500) {
        desconto[i] = 0.10;
    } else {
        desconto[i] = 0.15;
    }
    ValorFinal[i] = total[i] - (total[i] * desconto[i]);
    
    //cálculo do total geral(soma de todos os valores finais dos produtos)
    totalGeral += ValorFinal[i];
}

void adicionarProduto() {
    int opcao;

    do {
        if (i >= 20) {
            printf("Limite de produtos atingido!\n");
            break;
        }

        printf("\n--- Produto %d ---\n", i + 1);
        
        printf("Digite o nome do produto: ");
        scanf("%s", nome[i]);

        printf("Digite o preço do produto: ");
        scanf("%f", &preco[i]);

        printf("Digite a quantidade de produtos: ");
        scanf("%d", &quantidade[i]);

        //chamando as funções para uso
        calcularTotal();   
        aplicarDesconto();

        printf("Deseja cadastrar outro produto? (1-Sim / 0-Não): ");
        scanf("%d", &opcao);
    
        //continuação do cadastro
        if (opcao == 1) {
            i++; 
        } else {
            i++;
            break; 
        }

    } while (i < 20);
}

void emitirNotaFiscal() {
    printf("\n------- Dados dos Produtos -------");
    for (int j = 0; j < i; j++) {
        printf("\nProduto %d: ", j + 1);
        printf("Nome: %s ", nome[j]);
        printf("Preço: %.2f ", preco[j]);
        printf("Qtd: %d ", quantidade[j]);
        printf("Bruto: %.2f ", total[j]);
        printf("Desc: %.0f%% ", desconto[j] * 100);
        printf("Final: %.2f ", ValorFinal[j]);
        printf("\n----------------------------------");
    }
    
    printf("\nValor TOTAL da compra: %.2f ", totalGeral);
    printf("\n----------------------------------\n");
}

//execução do programa
int main() {
    adicionarProduto();
    emitirNotaFiscal();
    return 0;
}