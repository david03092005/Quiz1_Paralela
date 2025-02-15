#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <random>
#include <time.h>

using namespace std;

float monteCarloPi(int threads, int tosses);
void *calculatePi(void *arg);

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<double> dist(-1.0, 1.0);
int tossesT;


int main(int argc, char* argv[]){
	clock_t cpuStart, cpuEnd;
	time_t timeStart, timeEnd;
	timeStart = time(NULL);
	cpuStart = clock();
	
	if (argc != 3){
		printf("Cantidad de parametros invalida, ingrese 2 argumentos.");
	}
	else {
		int threads = atoi(argv[1]);
		int tosses = atoi(argv[2]);
		float resultPi = monteCarloPi(threads, tosses);	
		printf("Aproximación de pi: %f\n", resultPi);
		printf("Error: %f\n", (M_PI - resultPi));
	}
	
	timeEnd = time(NULL);
	cpuEnd = clock();

	double cpuTime = ((double) (cpuEnd - cpuStart)) / CLOCKS_PER_SEC;
   	double realTime = difftime(timeEnd, timeStart);

       	printf("Tiempo de CPU: %.6f segundos\n", cpuTime);
    	printf("Tiempo real: %.6f segundos\n", realTime);

	return 0;
}


float monteCarloPi(int cantThreads, int tosses){
	pthread_t threads[cantThreads];
	int result[cantThreads];
	tossesT = (int) ceil(tosses / cantThreads);
	
	for (int t = 0; t < cantThreads; t++){
		pthread_create(&threads[t], NULL, calculatePi, &result[t]);
	}
	
	int total = 0; 
	for (int i = 0; i < cantThreads; i++){
		pthread_join(threads[i], NULL);
		total += result[i];
	}	
	
	float ans = ((float)total / (float)tosses) * 4;
	
	return ans;
}


void *calculatePi(void *arg){
	int *ans = (int *) arg;
	int count = 0;
	for (int t = 0; t < tossesT; t++){
		float x = dist(gen);
		float y = dist(gen);
		if ((x*x) + (y*y) <= 1){
			count += 1;
		}
	}
	*ans = count;
	pthread_exit(NULL);
}



