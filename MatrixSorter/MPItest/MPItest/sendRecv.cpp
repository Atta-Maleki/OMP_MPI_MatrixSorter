//#include <stdio.h>
//#include <stdlib.h>
//#include <mpi.h>
//#include <iostream>
//
//#define ARRAY_SIZE 100
//using namespace std;
//int main(int argc, char** argv) {
//	int rank, size;
//	int* array = NULL;
//	int* sub_array = NULL;
//	int sub_array_size;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//	if (rank == 0) {
//		// Initialize the array
//		array = (int*)malloc(ARRAY_SIZE * sizeof(int));
//		for (int i = 0; i < ARRAY_SIZE; i++) {
//			array[i] = i;
//		}
//	}
//
//	// Determine the size of each sub-array
//	sub_array_size = ARRAY_SIZE / size;
//
//	// Allocate memory for the sub-array
//	sub_array = (int*)malloc(sub_array_size * sizeof(int));
//
//	// Scatter the array to each rank
//	if (rank == 0) {
//		for (int dest_rank = 1; dest_rank < size; dest_rank++) {
//			MPI_Send(&array[dest_rank * sub_array_size], sub_array_size, MPI_INT, dest_rank, 0, MPI_COMM_WORLD);
//		}
//		// Root rank's sub-array
//		for (int i = 0; i < sub_array_size; i++) {
//			sub_array[i] = array[i];
//		}
//	}
//	else {
//		MPI_Recv(sub_array, sub_array_size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		cout << "I am rank = " << rank << endl;
//		for (int i = 0; i < sub_array_size;i++)
//		{
//			cout << sub_array[i] << " ";
//		}
//		cout << endl;
//	}
//
//	// Each rank now has its corresponding sub-array
//
//	// Perform operations on the sub-array, if desired
//
//	// Gather the results from all ranks to the root rank (rank 0)
//	if (rank == 0) {
//		for (int source_rank = 1; source_rank < size; source_rank++) {
//			MPI_Recv(&array[source_rank * sub_array_size], sub_array_size, MPI_INT, source_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		}
//	}
//	else {
//		MPI_Send(sub_array, sub_array_size, MPI_INT, 0, 0, MPI_COMM_WORLD);
//	}
//
//	if (rank == 0) {
//		// Display the gathered array
//		printf("Gathered array:\n");
//		for (int i = 0; i < ARRAY_SIZE; i++) {
//			printf("%d ", array[i]);
//		}
//		printf("\n");
//
//		free(array);
//	}
//
//	free(sub_array);
//
//	MPI_Finalize();
//	return 0;
//}
