#include <stdio.h>

int main(int argc, char** argv) {
	
	int n = 7, fatorial = 1;
	
	while (n>0){
		
		fatorial *= n;
		n--;
		
	}
	
	printf("%d\n", fatorial);
	
	return 0;
	
}