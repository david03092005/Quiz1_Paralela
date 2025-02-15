#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <ctime>

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

void finish(clock_t startCpu, time_t startWall){

        clock_t endCpu = clock();
        time_t endWall = time(nullptr);

        double cpuTime = double(endCpu - startCpu) / CLOCKS_PER_SEC;
        double wallTime = difftime(endWall, startWall);

        printf("Tiempo de CPU (segundos): %.6f\n", cpuTime);
        printf("Tiempo real (segundos): %.6f\n", wallTime);
}

int main(int argc, char* argv[]){
	
	clock_t startCpu = clock();
        time_t startWall = time(nullptr);

    	int upper_bound = atoi(argv[1]);
			
	double ans = calc(upper_bound);
	printf("Resultado: %.6f\n", ans);
	printf("Error: %f\n", (M_PI - ans));
	finish(startCpu, startWall);
	return 0;
}
