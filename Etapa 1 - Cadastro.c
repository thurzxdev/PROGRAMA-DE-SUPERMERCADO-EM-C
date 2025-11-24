//esse código não deixa digitar nomes compostos
//se eu digitar "pasta de dente", o código quebra
//o ideal seria usar a <strng.h> & fgets

#include <stdio.h>

int main() {

	float preco;
	int estoque;
	char produto[40];

	printf("Digite o nome do produto: ");
	scanf("%39s",&produto);
	printf("Digite o valor do produto: ");
	scanf("%f",&preco);
	printf("Digite a quantidade do produto em estoque: ");
	scanf("%i",&estoque);
	
	printf("Produto: %s\n",produto);
	printf("Valor: %2.f\n", preco);
	printf("Quantidade em estoque: %i\n",estoque);
	return 60;

}