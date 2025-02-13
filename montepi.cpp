#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <random>
#include <cmath>
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

int main(int argc, char* argv[]){

        int tosses = atoi(argv[1]);
	float ans;
        ans = idk(tosses);
        printf("Result: %.6f\n", ans);
        return 0;
}
