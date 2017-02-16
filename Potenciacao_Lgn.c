#include <stdio.h>

int potencia(int base, int expoente){
    int metade = 1;
    int result = 1;

        while (expoente/2 >= 1){
            metade*=base;
            expoente--;
        }
        result*= metade * 2;

        return result + result;
    }

int main()
{
    double b = 4;
    double e = 3;

    printf("Resultado %d\n", potencia(b,e));

	return 0;
}
