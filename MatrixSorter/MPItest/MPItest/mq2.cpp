//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <mpi.h>
//
//#define SIZE 4096
//#define SIZE2 SIZE*SIZE
//#define RANDRANGE 8192
//#define THNUM 8
//#define SUBSIZE SIZE2/THNUM
//using namespace std;
///*****************************------------Swap func for quick sort---------------*******************************/
//void swap(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
///*****************************------------Partition func for quick sort---------------**************************/
//int partition(int* arr, int low, int high) {
//	int pivot = arr[high];
//	int i = (low - 1);
//
//	for (int j = low; j <= high - 1; j++) {
//		if (arr[j] < pivot) {
//			i++;
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[high]);
//	return (i + 1);
//}
///*****************************--------------------------QUICK SORT  ---------------------*********************/
//void quickSort(int* arr, int low, int high)
//{
//	if (low < high) {
//		int pivot = partition(arr, low, high);
//		quickSort(arr, low, pivot - 1);
//		quickSort(arr, pivot + 1, high);
//	}
//}
//
///***********************--------------------Regular MERGE function----------------****************************/
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
///**********---------------------------- Regular MergeSort Function ------------------**********/
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
///*****************************------------MAIN FUNCTION---------------*******************************/
//
//int main(int argc, char** argv) {
//
//	/********** Create and populate the array **********/
//	//int n = atoi(argv[1]);
//	int n = 32;
//	int* original_array = new int[n];
//
//
//	srand(time(NULL));
//	printf("This is the unsorted array: ");
//	for (int c = 0; c < n; c++) {
//
//		original_array[c] = rand() % n;
//		printf("%d ", original_array[c]);
//
//	}
//
//	printf("\n");
//	printf("\n");
//
//	/********** Initialize MPI **********/
//	int world_rank;
//	int world_size;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//	/********** Divide the array in equal-sized chunks **********/
//	int size = n / world_size;
//
//	/********** Send each subarray to each process **********/
//	int* sub_array = new int[size];
//	printf("world_rank is : %d \n", world_rank);
//	MPI_Scatter(original_array, size, MPI_INT, sub_array, size, MPI_INT, 0, MPI_COMM_WORLD);
//
//
//	/********** Perform the mergesort on each process **********/
//	int* tmp_array = new int[size];
//	mergeSort(sub_array, tmp_array, 0, (size - 1));
//
//	/********** Gather the sorted subarrays into one **********/
//	int* sorted = NULL;
//	if (world_rank == 0) {
//
//		sorted = new int[n];
//
//	}
//
//	MPI_Gather(sub_array, size, MPI_INT, sorted, size, MPI_INT, 0, MPI_COMM_WORLD);
//
//	/********** Make the final mergeSort call **********/
//	if (world_rank == 0) {
//
//		int* other_array = new int[n];
//		mergeSort(sorted, other_array, 0, (n - 1));
//
//		/********** Display the sorted array **********/
//		printf("This is the sorted array: ");
//		for (int c = 0; c < n; c++) {
//
//			printf("%d ", sorted[c]);
//
//		}
//
//		printf("\n");
//		printf("\n");
//
//		/********** Clean up root **********/
//		free(sorted);
//		free(other_array);
//
//	}
//
//	/********** Clean up rest **********/
//	free(original_array);
//	free(sub_array);
//	free(tmp_array);
//
//	/********** Finalize MPI **********/
//	MPI_Barrier(MPI_COMM_WORLD);
//	MPI_Finalize();
//
//}
//
//
