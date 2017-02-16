#include <stdio.h>
#include <stdlib.h>

/**
* O(n^2)
*/

int main(int argc, char *argv[]) {

	int vetor[4] = {7, 5, 3, 1}, chave, i, j;

	for (i=1; i<4; i++)
	{
		chave = vetor[i];
		j = i-1;

		while((j >= 0) && (chave < vetor[j]))
		{
			vetor[j+1] = vetor[j];
			j=j-1;
		}

		vetor[j+1] = chave;
	}

	for(i=0; i<4; i++){
		printf("%d\n", vetor[i]);
	}

	return 0;
}
