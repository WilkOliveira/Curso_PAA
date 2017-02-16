#include <stdio.h>

int main(int argc, char** argv) {
	
	int n = 7, fatorial = 1;
	
	for ( ; n>0; n--){
		
		fatorial *= n;
	
	}
	
	printf("%d\n", fatorial);
	
	return 0;
}
