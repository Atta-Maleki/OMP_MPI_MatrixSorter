#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <omp.h>

using namespace std;
#define TOL 1.111

int main() {
	int n = 512;
	int thread_num = 8;
	omp_set_num_threads(thread_num);

	int done = 0;
	float tempdiff[8] = { 0 };
	float mydiff = 0;

	// Dynamically allocate memory for the 1D array
	float* myA = new float[(n + 2) * (n + 2)];

	// Initialize myA here
	for (int i = 0; i < (n + 2) * (n + 2); i++) {
		// Set initial values as needed
		myA[i] = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (100)));;
	}
	float prev = 0;
	int j;
	auto start = chrono::high_resolution_clock::now();
	//clock_t start = clock();
	while (!done) {
		mydiff = 0;
		//tempdiff = 0;
		for (int i = 0; i<thread_num; i++)
		{
			tempdiff[i] = 0;
		}
		j = 1;


#pragma omp parallel for private(j, prev) //reduction(+ : mydiff)
		for (int i = 1; i < n; i++) {
			for (j = 1; j < n - 1; j++) {
				int index = i * (n + 2) + j;
				prev = myA[index];
				myA[index] = 0.2 * (myA[(i - 1) * (n + 2) + j] + myA[index] + myA[(i + 1) * (n + 2) + j] + myA[index - 1] + myA[index + 1]);
				tempdiff[omp_get_thread_num()] += fabs(myA[index] - prev);
				//cout<<omp_get_thread_num()<<" perv="<<prev<<" i="<<i<<" j="<<j<<" m="<<myA[index]<<" diff="<<mydiff<<endl;
			}

			//mydiff += tempdiff;
		}
		for (int i = 0; i<thread_num; i++)
		{
			mydiff += tempdiff[i];
		}

		//cout<<mydiff<<endl;
		if (mydiff < TOL) {
			done = 1;
		}
	}


	// Cleanup memory
	delete[] myA;
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << "time is: " << elapsed_seconds.count() << " seconds" << endl;

	system("pause");

	/*clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	cout <<"time is :"<< seconds << endl;*/

	return 0;
}