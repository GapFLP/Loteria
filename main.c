#include <stdio.h>
#include <stdlib.h> // Para rand() e srand().
#include <time.h> // Para time(NULL).
#include <ctype.h>  // Para fflush(stdin);

int main()
{
	int n_numeros, valor_max, i, j, n_repeticao, execucao, swap, min;
	char opcao;

	do {
		printf("\nQuantos números terão sua aposta (por exemplo: 6)? ");
		scanf("%d", &n_numeros);
		getchar(); // Para evitar loop infinito.

		printf("\nQual o valor máximo dos números de sua aposta (por exemplo: 60)? ");
		scanf("%d", &valor_max);
		getchar(); // Para evitar loop infinito.

		if (n_numeros > valor_max) {
			printf("\nCondição impossível, tente novamente.\n");
			execucao = 0;
		} 

		else if (n_numeros > (valor_max / 2)) {
			printf("\nOs valores digitados são imprudentes, você deseja continuar?\n1 - Sim, quero fazer isso.\n2 - Não, quero tentar de novo.\n");






			do {
				fflush(stdin);
				scanf("%c", &opcao);
			}
			
			while (isdigit(opcao) == 0 || (opcao != '1' && opcao != '2'));







			if (opcao == 2) execucao = 0; 
		}

		else execucao = 1;
	}

	while (execucao == 0);

	int numero[n_numeros];

	srand(time(NULL)); // Tenta criar uma variação de valores mais eficaz usando o relógio.

	do {

		/* Gera os números aleatórios */

		for (i = 0; i < n_numeros; i++) {

			numero[i] = (rand() % valor_max) + 1; // A função rand() gera os números aleatórios, "% valor_max" define o valor máximo que a função pode atingir.
												  // Foi somado 1 ao valor gerado pela função rand(), pois ela considera valores a partir de 0.

		}

		n_repeticao = 0; // Zera a variável que conta os números repetidos (para evitar loop infinito).

		/* Busca por números repetidos no vetor */

		for (i = 0; i < n_numeros; i++) {
			for (j = 0; j < n_numeros; j++) {

				/*

				   No IF temos como primeira expressão: "i != j";
				   pois não queremos comparar uma posição do vetor com ela mesma. Já que o conteúdo seria sempre igual, o programa entraria em loop.

				   Caso a condição acima seja verdadeira (i diferente de j), o programa dará continuidade para a próxima expressão: "numero[i] == numero [j]";
				   que verifica se o conteúdo das posições i e j são diferentes.

				*/

				if (i != j && numero[i] == numero [j]) {

					n_repeticao =  1; // Faz a contagem dos números repetidos caso toda a expressão do IF for verdadeira, pois estamos usando && (^, and, e), ou seja, só executa se for tautologia.
					j = n_numeros; // Força o FOR a sair do loop.
				}
			}
		}
	}

	while (n_repeticao != 0); // repete o trecho de código do DO até não haver repetições, ou seja, quando n_repeticao for igual a 0.

	/*for (i = 0; i > (n_numeros - 1); i++) {
    	min = i;
    	for (j = (i+1); j > n_numeros; j++) {
      		if(numero[j] > numero[min]) {
        		min = j;
      		}
    	}
    	if (i != min) {
      		swap = numero[i];
      		numero[i] = numero[min];
      		numero[min] = swap;
    	}
  	}*/

	/* Exibe o resultado */

	printf("\n");

	for (i = 0; i < n_numeros; i++) {
		printf("%d ", numero[i]);
	}

	printf("\n\n");

	return 0;
}