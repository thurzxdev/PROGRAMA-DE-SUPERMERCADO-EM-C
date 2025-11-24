#include <stdio.h>
#include <string.h>

//define serve pra marcar valores que não vão mudar ao decorrer do código
//diferente das variáveis que são voláteis
#define max_prod 20
#define tam_nome 40

//structure do array de produtos
struct Produto {
    char nome[tam_nome];
    float valor;
};

//prototipo de funções
void adicionarProduto(struct Produto lista[], int *qtd);
// o *qtd é um ponteiro que serve pra fazer a contagem de quantos produtos tem
// as outras funcoes nao precisam do ponteiro pois elas só leem o valor, não alteram

float calcularTotal(struct Produto lista[], int qtd);
float aplicarDesconto(float total, float porcentagem);
void emitirNotaFiscal(struct Produto lista[], int qtd);
void limparBuffer(); 

int main() {
    struct Produto carrinho[max_prod];
    int qtd_produtos=0, opt;
    
    do{
        printf("Cadastro de produtos:\n");
        printf("#1 - Cadastrar novo produto.\n");
        printf("#2 - Gerar Nota Fiscal.\n");
        printf("#3 - Sair sem comprar.\n");
        printf("Digite o número correspondente: ");
        scanf("%i", &opt);
        limparBuffer();

        switch(opt){
            case 1:
                adicionarProduto(carrinho, &qtd_produtos);
                break;
            case 2:
                if (qtd_produtos > 0) {
                    emitirNotaFiscal(carrinho, qtd_produtos);
                    return 60;
                } else {
                    printf("Carrinho vazio.");
                }
                break;
            case 3:
                printf("Saindo...");
                break;
            default:
                printf("Opção inválida.");
                break;


        } 
    } while (opt != 3);
    return 60;
}

//essa funcao é padrão pra limpar o \n que sobra no input
void limparBuffer(){
    int c;
    while((c=getchar()) != '\n' && c != EOF);
}

//o * puxa o valor da memoria ao inves de rodar localmente dentro da funcao
void adicionarProduto(struct Produto lista[], int *qtd){
    if (*qtd >= max_prod){
        printf("Carrinho cheio, gere a nota fiscal antes de continuar.\n");
        return;
    }

    printf("Adicionar produto:\n");
    printf("Nome: ");
    fgets(lista[*qtd].nome, tam_nome, stdin);

    //essa linha limpa o \n que o fgets pega junto da string
    lista[*qtd].nome[strcspn(lista[*qtd].nome, "\n")] = 0;



    printf("Valor: R$ ");
    scanf("%f", &lista[*qtd].valor);
    limparBuffer();

    printf("Produto cadastrado com sucesso.\n");
    (*qtd)++;
}

float calcularTotal(struct Produto lista[], int qtd){
    float soma = 0;
    for (int i = 0; i < qtd; ++i)
    {
        soma += lista[i].valor;
    }
    return soma;
}

float aplicarDesconto(float total, float porcentagem){
    return total * (1-(porcentagem/100.0)); 
}

void emitirNotaFiscal(struct Produto lista[],int qtd){
    float total = calcularTotal(lista, qtd);
    float totalComDesconto = total, porc;
    char resp;
    int k;

    printf("Nota fiscal:\n");
    printf("ID | %-20s | Preço\n", "Produto");
    
    for (k=0; k < qtd; k++){
      printf("#%d | %-20s | R$ %.2f\n", k+1, lista[k].nome, lista[k].valor);
    }
    printf("O valor total é: R$ %.2f\n", total);
    printf("Deseja aplicar desconto? (s/n)  ");

    scanf("%c", &resp);

    if (resp == 's' || resp == 'S')
    {
        printf("Digite a porcentagem do desconto. (ex: 10)  ");
        scanf("%f", &porc);
        totalComDesconto = aplicarDesconto(total, porc);
        printf("Desconto aplicado: %.0f%%\n", porc);
    }
    printf("TOTAL A PAGAR: R$ %.2f\n", totalComDesconto);
}