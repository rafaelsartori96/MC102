#include <stdio.h>

char intToChar(int value) {
	switch(value) {
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		default:
			return '?';
	}
}

int charToInt(char value) {
	switch(value) {
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		default:
			return -1;
	}
}

int lerNumero(int vetor[30]) {
	int temp[30];
	// Para fazermos a transferência temp -> vetor, iremos iniciar com -1 todos os valores do vetor temp
	// e com 0 os valores de vetor
	for(int i = 0; i < 30; i++) {
		temp[i] = -1;
		vetor[i] = 0;
	}

	char entrada;
	int numero, algarismo = 0;
	do {
		scanf("%c", &entrada);
		// Se a quebra de linha for lida antes do último algarismo da array, conseguimos ler o número ;)
		if (entrada != '\n') {
			numero = charToInt(entrada);

			// Se o número lido não corresponde a um algarismo (o Susy não deve abordar isso ainda)
			if (numero < 0) {
				// Retornar falso, não conseguimos ler o número
				return 0;
			}

			// Se corresponde, armazenamos em temp
			temp[algarismo++] = numero;
		} else {
			// Devemos, então, salvar o número temporário temp em vetor. Para isso:
			// o vetor temp estará ocupado com valores maiores ou iguais a zero, acharemos o
			// último índice de temp cujo valor é diferente de -1 (o último algarismo entrado)
			// Depois disso, moveremos temp[j] para vetor[29] e assim até terminarmos temp.
			for(int i = 29, j = 29; i >= 0 && j >= 0; j--) {
				// Pulando todos os valores de temp que não foram usados
				if (temp[j] == -1) {
					continue;
				}

				// Se chegamos aqui, é porque temp[j] != -1, ou seja, estamos no primeiro algarismo que
				// foi digitado. Moveremos o último algarismo entrado para o último espaço em vetor
				vetor[i--] = temp[j];
			}

			// Retornar true, conseguimos ler o número
			return 1;
		}
	} while (algarismo <= 30); // Menor ou igual pois devemos ler o último algarismo até com algarismo=29
	// O número de algarismos foi ultrapassado sem lermos a quebra de linha
	return 0;
}

void printNumero(int numero[30]) {
	for(int i = 0; i < 30; i++) {
		printf("%c", intToChar(numero[i]));
	}
}

void calcularImprimir(int numero1[30], int numero2[30], char operador) {
}

int main() {
	int numero1[30], numero2[30];
	char operador;

	// Se não conseguimos ler o primeiro número
	if(!lerNumero(numero1)) {
		// Retornar overflow (ou o algarismo digitado é incorreto, ou mais casas decimais do que conseguimos
		// trabalhar foram entradas)
		printf("overflow\n");
		return 0;
	}

	// Ler o operador => o '\n' ao digitar o operador é enviado para "lerNumero(numero2)" e isso faz com que o
	// vetor numero2 apareça vazio.
	// Corrigido: dica "do { (...) } while(c != '\n');" do laboratório
	char entrada;
	do {
		scanf("%c", &entrada);
		// Ler operador
		if (entrada != '\n') {
			operador = entrada;
		}
	} while(entrada != '\n');

	// Se não conseguimos ler o segundo número
	if(!lerNumero(numero2)) {
		printf("overflow\n");
		return 0;
	}

	// Debugging
	printf("Os números digitados foram ");
	printNumero(numero1);
	printf(" e ");
	printNumero(numero2);
	printf("\nO operador foi %c.\n", operador);

	// Fazer operação e mostrar resultado
	calcularImprimir(numero1, numero2, operador);
}
