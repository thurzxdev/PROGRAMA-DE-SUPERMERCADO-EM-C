//esse código não deixa digitar nomes compostos
//se eu digitar "pasta de dente", o código quebra
//o ideal seria usar a <strng.h> & fgets
#include <stdio.h>

int main()

{

	float preco, preco_desconto, valor_total, desconto=0;
	int estoque, tipo_produto;
	char produto[40];

	printf("Digite o nome do produto: ");
	scanf("%39s",&produto);

	printf("Digite o valor do produto: ");
	scanf("%f",&preco);

	printf("Digite a quantidade do produto em estoque: ");
	scanf("%i",&estoque);

	printf("Escolha o tipo de produto\n");
	printf("1-Alimentos\n");
	printf("2-Roupas\n");
	printf("3-Eletrônicos\n");
	printf("4-Outros\n");

	printf("Digite o número correspondente: ");
	scanf("%d", &tipo_produto);

//escolhendo a % de acordo com o tipo
	switch(tipo_produto) {
	case 1:
		desconto=0.06;
		break;
	case 2:
		desconto=0.09;
		break;
	case 3:
		desconto=0.12;
		break;
	case 4:
		desconto=0.04;
		break;
	}

//cálculo desconto
	preco_desconto = preco*(1-desconto);

//valor total em estoque
	valor_total = preco_desconto*estoque;

	printf("Produto: %s\n",produto);
	printf("Valor original: R$ %2.f\n", preco);

	printf("Desconto: %0.f%\n", desconto*100);
	printf("Valor da unidade com desconto: R$ %.2f\n", preco_desconto);

	printf("Quantidade em estoque: %i\n", estoque);
	printf("Valor do estoque com desconto: R$ %.2f\n", valor_total);

	return 60;
}