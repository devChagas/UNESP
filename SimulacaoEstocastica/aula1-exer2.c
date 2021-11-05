#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	long long int xn, x0;
	int i = 0;
	long long int M;
	double res;
	
	M = pow(2, 31) - 1;

	printf("Insira o valor da semente inicial: ");
	scanf(" %ld", &x0);
	
	 	/*while (i < M)*/	
		while (i < 10){						//Aqui limitei para somente 10 iterações, mas na prática o ciclo da sequência de número pseudoaleatórios
		xn = (16807 * x0) % M;				//Iria até o valor de M, podendo trocar o while para while ( i < M) entretanto o programa geraria um número
		printf("x(i) = %ld      ", x0);		//enorme de números. Assim como também podemos facilmente aumentar para 20, 30, 40 iterações.
		res = (double)x0 /(double) M;
		printf("x(i)/M = %lf\n", res);
		
		x0 = xn;
		i++;
	}
	
}