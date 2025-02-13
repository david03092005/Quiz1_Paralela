#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>

//Formula
double calc(int upper_bound){
	double answer;
	int i;
	//Sumatoria
	for(i =0;i<=upper_bound;i++){
		double one = i%2 == 0 ? 1.0:-1.0;
		answer += one/((2*i)+1);
	}
	answer*=4;

	return answer;
}


int main(int argc, char* argv[]){
	        
    	int upper_bound = atoi(argv[1]);
			
	double ans = calc(upper_bound);
	printf("Resultado: %.6f\n", ans);
	return 0;
}
