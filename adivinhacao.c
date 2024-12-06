#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main () {
	setlocale(LC_ALL, "Portuguese");
	// imprime o cabeçalho

printf("\n\n");
printf("		      T~~                          		\n");
printf("		      |			      		        \n");
printf("		     /'\\			      		\n");
printf("	     T~~     |'| T~~		Bem vindo ao	        \n");
printf("	 T~~ |    T~ WWWW|	     Jogo de Adivinhação!	\n");
printf("	 |  /'\\   |  |  |/\\T~~				\n");
printf("	/'\\ WWW  /'\\ |' |WW|					\n");
printf("	WWWWW/\\| /   \\|'/\\|/'\\				\n");
printf("	|   /__\\/]WWW[\\/__\\WWWW				\n");
printf("	|'  WWWW'|I_I|'WWWW'  |					\n");
printf("	|   |' |/  -  \\|' |'  |				\n");
printf("	|'  |  |LI=H=LI|' |   |					\n");
printf("	|   |' | |[_]| |  |'  |					\n");
printf("	|   |  |_|###|_|  |   |					\n");
printf("	'---'--'-/___\\-'--'---'				\n");
printf("\n\n");

	int segundos = time(0);
	srand(segundos);

	int numerogrande = rand();

	int numerosecreto = numerogrande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;
	int acertou = 0;

	int nivel;
	printf("Qual o nível de dificuldade?\n");
	printf("(1) Facil (2) Medio (3) Dificil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	int numerodetentativas;
	switch(nivel) {
		case 1:
			numerodetentativas = 20;
			break;
		case 2:
			numerodetentativas = 15;
			break;
		default:
			numerodetentativas = 6;
			break;
	}

	for(int i = 1; i <= numerodetentativas; i++) {
		
		printf("Tentativa %d\n", tentativas);
		printf("Qual é o seu chute? ");
		
		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);
		
		if(chute < 0) {
			printf("Você não pode chutar números negativos!\n");
			continue;
		}

		acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;

		if(acertou) {
			break;
		}

		else if(maior) {
			printf("Seu chute é maior que o número secreto!\n");
		}

		else {
			printf("Seu chute é menor que o número secreto!\n");
		}

		tentativas++;

		double pontosperdidos = (double)(abs(chute - numerosecreto)) / (double)2;
		pontos = pontos - pontosperdidos;
	}

	printf("Fim de jogo!\n");

	if(acertou) {
		printf("Você ganhou!\n");
		printf("Você acertou em %d tentativas\n", tentativas);
        	printf("Total de pontos: %.2f\n", pontos);
	} else {
		printf("Você perdeu, tente de novo!\n");
	}
	return 0;
}	
