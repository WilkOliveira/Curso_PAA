#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	  
	int n=0, vetor[n], chave, i, j;
	
	printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);
    printf("\n******************************\n");
    for(i=0; i <n; i++)
    {
    	printf("Digite o numero de posicao %d\n", i+1);
    	scanf("%d", &vetor[i]);
    }
    
    printf("*****************************\n\n");

	for (i=1; i<n; i++)
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

	for(i=0; i<n; i++){
		printf("%d\n", vetor[i]);
	}
	
	return 0;

}
