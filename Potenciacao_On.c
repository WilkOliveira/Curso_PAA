#include <stdio.h>

int potencia(int base, int expoente){
    int result = 1;

        while (expoente >= 1){
            result*=base;
            expoente--;
        }
        return result;
    }

int main()
{
    double b = 4;
    double e = 3;

    printf("Resultado %d\n", potencia(b,e));

	return 0;
}
