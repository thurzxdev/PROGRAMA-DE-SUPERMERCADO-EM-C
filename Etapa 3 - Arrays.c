//a biblioteca string.h serve pra manipular strings, já que o C nativo não tem suporte
#include <stdio.h>
#include <string.h>

// define serve pra marcar valores que não vão mudar ao decorrer do código, diferente das variáveis
#define max_prod 10
#define tam_nome 40

int main() {
    
    int i=0, k;
    char nomes[max_prod][tam_nome];
    float valor[max_prod], valor_total;

    printf("Lista de compras\n");
    printf("Para sair, digite 1 no campo NOME\n");
    
    while (i < max_prod) {
        
        printf("Produto #%d\n", i+1);
        printf("Nome: ");
        
        //fgets é uma alternativa melhor ao scanf, pois permite nomes compostos
        fgets(nomes[i], tam_nome, stdin);
        
        //strcspn limpa o \n que o fgets pega quando o user dá o input
        nomes[i][strcspn(nomes[i], "\n")] = 0;
        
        // aqui o strcmp checa se o user digitou o 1, para poder parar o looping
        if (strcmp(nomes[i], "1") == 0) {
            break;
        }
        
        printf("Valor: ");
        scanf("%f", &valor[i]);
        
        //getchar limpa o input, se não ele pula o nome quando roda o loop
        getchar();
        i++;
    }
    
    // o %-20s serve pra formatar o texto, adicionando espaços até atingir a quantidade digitada 
    printf("Lista de compras:\n");
    printf("ID | %-20s | Preço\n", "Produto");
    
    
    for (k=0; k < i; k++){
      printf("#%d | %-20s | R$ %.2f\n", k+1, nomes[k], valor[k]);
      valor_total = valor_total+valor[k];
    }
    printf("\n\nValor total: R$ %.2f", valor_total);
    
    return 60;
}