#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<double> dist(-1.0, 1.0);

float idk(int tosses){

	srand(time(nullptr));
	int count = 0;
	for(int i =0; i<tosses;i++){

		float x = dist(gen);
                float y = dist(gen);
		
		if((x*x + y*y) <=1.0){count++;}	
	}
	float ans = ((float)count / (float)tosses) * 4.0;
	return ans;
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

        int tosses = atoi(argv[1]);
	float ans;
        ans = idk(tosses);
        printf("Result: %.6f\n", ans);

	finish(startCpu, startWall);
        return 0;
}
