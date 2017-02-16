#include <stdio.h>

int main(int argc, char** argv) {
	
	int n, fatorial = 1;
	
	printf("Digite o valor a ser fatorado:\n");
	scanf("%d", &n);
	
	if (n < 0){
		
		printf("Valor absurdo\n");
		
	}
	
	else if (n == 0){
		
		printf("Fatorial: 1\n");
		
	}
	
	else{
	
		for ( ; n>0; n--){
		
			fatorial *= n;
	
		}
	
		printf("Fatorial: %d\n", fatorial);
		
	}
	
	return 0;
}
