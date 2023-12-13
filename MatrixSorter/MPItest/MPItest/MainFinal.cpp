#include <mpi.h>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

#define ORG_TAG 0
#define ROW_TAG 1
#define DIFF_TAG 2
#define DONE_TAG 3

#define TOL 1.111

int main(int argc, char** argv) {

	int world_rank;
	int world_size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Status status;
	MPI_Request request;
	int done = 0;
	srand(time(NULL));
	float temp, tempdiff, mydiff = 0;
	int n = atoi(argv[1]);
	int i, j;

	int rows_per_processor = n / world_size;
	int total_elements_for_myA = (n + 2) * (rows_per_processor + 2);



	//MPI_Bcast(&original_array[0], (n+2) * (n + 2) ,MPI_FLOAT, 0, MPI_COMM_WORLD)


	float* myA = new float[total_elements_for_myA];
	clock_t start_0 = clock();
	if (world_rank == 0) {

		float* original_array = new float[(n + 2) * (n + 2)];
		// Flatten the original_array
		for (i = 0; i < (n + 2) * (n + 2); i++) {
			original_array[i] = (float)(rand() % 100);
			//cout<<"this is original_array for rank : "<<world_rank <<" ////// "<<original_array[i]<<endl;
		}
		for (i = 1; i < world_size; i++) {
			if (i == world_size - 1) {
				//cout<<"SENDing "<<" the rank is "<<world_rank<<endl;
				MPI_Send(&original_array[(i*rows_per_processor + 1) * (n + 2)], (rows_per_processor + 1)*(n + 2), MPI_FLOAT, i, ORG_TAG, MPI_COMM_WORLD);
				//cout<<"SENDed"<<" the rank is "<<world_rank<<endl;
			}
			if (i != world_size - 1) {
				//cout<<"SENDing "<<" the rank is "<<world_rank<<endl;
				MPI_Send(&original_array[(i*rows_per_processor + 1) * (n + 2)], rows_per_processor*(n + 2), MPI_FLOAT, i, ORG_TAG, MPI_COMM_WORLD);
				//cout<<"SENDed"<<" the rank is "<<world_rank<<endl;
			}

		}

		// making myA for rank 0 itself
		for (i = 0; i < rows_per_processor + 1; i++) {
			for (j = 0; j < n + 2; j++) {
				myA[i * (n + 2) + j] = original_array[(0 + i) * (n + 2) + j];
				//cout<<"this is myA for rank : "<<world_rank <<"  //////  "<<myA[i * (n + 2) + j]<<endl;
			}
		}
		delete[] original_array;

	}
	//MPI_Barrier( MPI_COMM_WORLD );
	//cout<<"rankkkkkkkkkkkkkkkkk"<<world_rank<<endl;
	if (world_rank != 0) {

		// making myA for last rank
		if (world_rank == world_size - 1) {
			//cout<<"RECVing "<<" the rank is "<<world_rank<<endl;
			MPI_Recv(&myA[1 * (n + 2)], (rows_per_processor + 1)*(n + 2), MPI_FLOAT, 0, ORG_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			//cout<<"RECVED "<<" the rank is "<<world_rank<<endl;
		}
		if (world_rank != world_size - 1) {
			//cout<<"RECVing "<<" the rank is "<<world_rank<<endl;
			MPI_Recv(&myA[1 * (n + 2)], rows_per_processor*(n + 2), MPI_FLOAT, 0, ORG_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			//cout<<"RECVED "<<" the rank is "<<world_rank<<endl;
		}



		/*
		if (world_rank == 7){
		int counter = 0;
		for(i = 1 ; i < rows_per_processor + 1 ; i++){
		for (j = 0; j < n + 2; j++) {
		if(myA[i*(n+2)+j] >=0 )
		counter++;
		cout<<"this is myA for rank : "<<world_rank <<"  //////  "<<myA[i*(n+2)+j]<<endl;
		}
		}
		cout<<"this is counter : "<<counter<<endl;
		}
		*/




		/*
		for (i = 1; i < rows_per_processor + 1; i++) {
		for (j = 0; j < n + 2; j++) {
		myA[i * (n + 2) + j] = original_array[(start_row + i) * (n + 2) + j];
		cout<<"this is myA for rank : "<<world_rank <<"  //////  "<<myA[i * (n + 2) + j]<<endl;
		}
		}
		*/
	}

	//MPI_Barrier(MPI_COMM_WORLD);
	int send_error_code;
	while (!done) {
		//clock_t start_1 = clock();
		mydiff = 0;
		// cout<<"yohoooooooooooo rank "<<world_rank<<endl;
		if (world_rank != 0) {
			//cout<<"SENDing world_rank != 0"<<" the rank is "<<world_rank<<endl;
			MPI_Isend(&myA[n + 2], n + 2, MPI_FLOAT, world_rank - 1, ROW_TAG, MPI_COMM_WORLD, &request);
			//cout<<"SENDed world_rank != 0"<<" the rank is "<<world_rank<<endl;

		}
		if (world_rank != world_size - 1) {
			//cout<<"SENDing world_rank != world_size - 1"<<" the rank is "<<world_rank<<endl;
			MPI_Isend(&myA[rows_per_processor * (n + 2)], n + 2, MPI_FLOAT, world_rank + 1, ROW_TAG, MPI_COMM_WORLD, &request);
			//cout<<"SENDed world_rank != world_size - 1"<<" the rank is "<<world_rank<<endl;

		}
		//cout<<"yohoooooooooooo rank "<<world_rank<<endl;
		if (world_rank != 0) {
			//cout<<"RECVing world_rank != 0"<<" the rank is "<<world_rank<<endl;
			MPI_Irecv(&myA[0], n + 2, MPI_FLOAT, world_rank - 1, ROW_TAG, MPI_COMM_WORLD, &request);
			//cout<<"RECViED world_rank != 0"<<" the rank is "<<world_rank<<endl;
		}
		if (world_rank != world_size - 1) {
			//cout<<"RECVing world_rank != world_size - 1"<<" the rank is "<<world_rank<<endl;
			MPI_Irecv(&myA[(rows_per_processor + 1) * (n + 2)], n + 2, MPI_FLOAT, world_rank + 1, ROW_TAG, MPI_COMM_WORLD, &request);
			//cout<<"RECViED world_rank != world_size - 1"<<" the rank is "<<world_rank<<endl;
		}
		//cout<<"My rank is "<<world_rank<<endl;
		MPI_Wait(&request, &status);
		//clock_t end_1 = clock();
		//float seconds = (float)(end_1 - start_1) / CLOCKS_PER_SEC;
		//cout<<"yohoooooooooooo"<<seconds<<endl;
		for (i = 1; i < rows_per_processor + 1; i++) {
			for (j = 1; j < n + 1; j++) {
				float prev = myA[i * (n + 2) + j];
				myA[i * (n + 2) + j] = 0.2 * (myA[(i - 1) * (n + 2) + j] + myA[i * (n + 2) + j] + myA[(i + 1) * (n + 2) + j] + myA[i * (n + 2) + j - 1] + myA[i * (n + 2) + j + 1]);
				mydiff += fabs(myA[i * (n + 2) + j] - prev);
			}
		}

		if (world_rank != 0) {
			MPI_Send(&mydiff, 1, MPI_FLOAT, 0, DIFF_TAG, MPI_COMM_WORLD);
			MPI_Recv(&done, 1, MPI_INT, 0, DONE_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
		else {
			for (i = 1; i < world_size; i++) {
				MPI_Recv(&tempdiff, 1, MPI_FLOAT, i, DIFF_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				mydiff += tempdiff;
			}
			cout<<mydiff<<" this is my dif"<<endl;
			if (mydiff < TOL) done = 1;
			for (i = 1; i < world_size; i++) {
				MPI_Send(&done, 1, MPI_INT, i, DONE_TAG, MPI_COMM_WORLD);
			}
		}


	}

	clock_t end_0 = clock();
	float seconds = (float)(end_0 - start_0) / CLOCKS_PER_SEC;


	if (world_rank == 0) {
		cout << seconds << " i spent inghad before while" << endl;
	}


	delete[] myA;

	MPI_Finalize();

	return 0;
}