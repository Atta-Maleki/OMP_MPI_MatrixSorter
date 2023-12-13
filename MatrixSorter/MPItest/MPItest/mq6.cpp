//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <mpi.h>
//using namespace std;
//
//void merge(int *a, int *b, int l, int m, int r) {
//
//	int h, i, j;
//	h = l;
//	i = l;
//	j = m + 1;
//
//	while ((h <= m) && (j <= r)) {
//
//		if (a[h] <= a[j]) {
//
//			b[i] = a[h];
//			h++;
//
//		}
//
//		else {
//
//			b[i] = a[j];
//			j++;
//
//		}
//
//		i++;
//
//	}
//
//	if (m < h) {
//
//		for (int k = j; k <= r; k++) {
//
//			b[i] = a[k];
//			i++;
//
//		}
//
//	}
//
//	else {
//
//		for (int k = h; k <= m; k++) {
//
//			b[i] = a[k];
//			i++;
//
//		}
//
//	}
//
//	for (int k = l; k <= r; k++) {
//
//		a[k] = b[k];
//
//	}
//
//}
//
//
//void mergeSort(int *a, int *b, int l, int r) {
//
//	int m;
//
//	if (l < r) {
//
//		m = (l + r) / 2;
//
//		mergeSort(a, b, l, m);
//		mergeSort(a, b, (m + 1), r);
//		merge(a, b, l, m, r);
//
//	}
//
//}
//
//int main(int argc, char** argv) {
//
//
//	int n = 16777216;
//	int* original_array = new int[n];
//
//
//	srand(time(NULL));
//
//
//	for (int c = 0; c < n; c++) {
//
//		original_array[c] = rand() % 1000;
//
//
//	}
//
//
//	printf("\n");
//	printf("\n");
//
//
//	int rank;
//	int world_size;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//
//	int size = n / world_size;
//
//
//	int* sub_array = new int[size];
//	for (int i = 0; i< size; i++) {
//		sub_array[i] = original_array[rank*size + i];
//	}
//	printf("rank is : %d \n", rank);
//
//	int* tmp_array = new int[size];
//	mergeSort(sub_array, tmp_array, 0, (size - 1));
//
//
//	MPI_Barrier(MPI_COMM_WORLD);
//	int k = rank*size;
//	for (int i = 0; i< size; i++) {
//		original_array[k] = sub_array[i];
//		k++;
//	}
//
//	delete[] sub_array;
//	delete[] tmp_array;
//
//
//	MPI_Barrier(MPI_COMM_WORLD);
//	int* sub_array_lvl_1 = new int[2 * size];
//	int* tmp_array_lvl_1 = new int[2 * size];
//	cout << "sub array cunstructed by : " << rank << endl;
//	if (rank == 0) {
//		MPI_Send(&original_array[0 * 2 * size], 2 * size, MPI_INT, 1, 0, MPI_COMM_WORLD);
//		MPI_Send(&original_array[1 * 2 * size], 2 * size, MPI_INT, 2, 0, MPI_COMM_WORLD);
//		MPI_Send(&original_array[2 * 2 * size], 2 * size, MPI_INT, 3, 0, MPI_COMM_WORLD);
//		MPI_Send(&original_array[3 * 2 * size], 2 * size, MPI_INT, 4, 0, MPI_COMM_WORLD);
//	}
//	if (rank == 1) {
//
//		MPI_Recv(&sub_array_lvl_1[0], 2 * size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		/*
//		for (int i = 0; i< 2 * size; i++) {
//			sub_array_lvl_1[i] = original_array[(rank - 1) * 2 * size + i];
//		}
//		*/
//		mergeSort(sub_array_lvl_1, tmp_array_lvl_1, 0, (2 * size - 1));
//		k = (rank - 1) * 2 * size;
//		for (int i = 0; i< 2 * size; i++) {
//			original_array[k] = sub_array_lvl_1[i];
//			k++;
//		}
//	}
//	if (rank == 2) {
//		MPI_Recv(&sub_array_lvl_1[0], 2 * size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		/*
//		for (int i = 0; i< 2 * size; i++) {
//			sub_array_lvl_1[i] = original_array[(rank - 1) * 2 * size + i];
//		}*/
//		mergeSort(sub_array_lvl_1, tmp_array_lvl_1, 0, (2 * size - 1));
//		k = (rank - 1) * 2 * size;
//		for (int i = 0; i< 2 * size; i++) {
//			original_array[k] = sub_array_lvl_1[i];
//			k++;
//		}
//	}
//	if (rank == 3) {
//		MPI_Recv(&sub_array_lvl_1[0], 2 * size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		/*
//		for (int i = 0; i< 2 * size; i++) {
//			sub_array_lvl_1[i] = original_array[(rank - 1) * 2 * size + i];
//		}*/
//		mergeSort(sub_array_lvl_1, tmp_array_lvl_1, 0, (2 * size - 1));
//		k = (rank - 1) * 2 * size;
//		for (int i = 0; i< 2 * size; i++) {
//			original_array[k] = sub_array_lvl_1[i];
//			k++;
//		}
//	}
//	if (rank == 4) {
//		MPI_Recv(&sub_array_lvl_1[0], 2 * size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		/*
//		for (int i = 0; i< 2 * size; i++) {
//			sub_array_lvl_1[i] = original_array[(rank - 1) * 2 * size + i];
//		}*/
//		
//		mergeSort(sub_array_lvl_1, tmp_array_lvl_1, 0, (2 * size - 1));
//		k = (rank - 1) * 2 * size;
//		for (int i = 0; i< 2 * size; i++) {
//			original_array[k] = sub_array_lvl_1[i];
//			k++;
//		}
//	}
//	delete[] sub_array_lvl_1;
//	delete[] tmp_array_lvl_1;
//
//
//
//	MPI_Barrier(MPI_COMM_WORLD);
//	int* sub_array_lvl_2 = new int[4 * size];
//	int* tmp_array_lvl_2 = new int[4 * size];
//	if (rank == 0) {
//		MPI_Send(&original_array[0 * 4 * size], 4 * size, MPI_INT, 5, 0, MPI_COMM_WORLD);
//		MPI_Send(&original_array[1 * 4 * size], 4 * size, MPI_INT, 6, 0, MPI_COMM_WORLD);
//	}
//	if (rank == 5) {
//		MPI_Recv(&sub_array_lvl_2[0], 4 * size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		/*
//		for (int i = 0; i< 4 * size; i++) {
//			sub_array_lvl_2[i] = original_array[(rank - 5) * 4 * size + i];
//		}*/
//		mergeSort(sub_array_lvl_2, tmp_array_lvl_2, 0, (4 * size - 1));
//		k = (rank - 5) * 4 * size;
//		for (int i = 0; i< 4 * size; i++) {
//			original_array[k] = sub_array_lvl_2[i];
//			k++;
//		}
//	}
//	if (rank == 6) {
//		MPI_Recv(&sub_array_lvl_2[0], 4 * size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		/*
//		for (int i = 0; i< 4 * size; i++) {
//			sub_array_lvl_2[i] = original_array[(rank - 5) * 4 * size + i];
//		}*/
//		mergeSort(sub_array_lvl_2, tmp_array_lvl_2, 0, (4 * size - 1));
//		k = (rank - 5) * 4 * size;
//		for (int i = 0; i< 4 * size; i++) {
//			original_array[k] = sub_array_lvl_2[i];
//			k++;
//		}
//	}
//	delete[] sub_array_lvl_2;
//	delete[] tmp_array_lvl_2;
//
//
//	MPI_Barrier(MPI_COMM_WORLD);
//	if (rank == 7) {
//
//		int* other_array = new int[n];
//		mergeSort(original_array, other_array, 0, (n - 1));
//
//
//		printf("This is the sorted array: ");
//		for (int c = 0; c < n; c++) {
//
//			printf("%d ", original_array[c]);
//
//		//}
//
//		printf("\n");
//		printf("\n");
//
//
//		free(other_array);
//
//	}
//
//
//	free(original_array);
//
//
//
//	MPI_Barrier(MPI_COMM_WORLD);
//	MPI_Finalize();
//
//}
//
//
