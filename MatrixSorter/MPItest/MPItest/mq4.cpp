//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//#include <mpi.h>
//
//
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
//
///*****************************--------------------------QUICK SORT  ---------------------*********************/
//void quickSort(int* arr, int low, int high) {
//	if (low < high) {
//		int pivot = partition(arr, low, high);
//		quickSort(arr, low, pivot - 1);
//		quickSort(arr, pivot + 1, high);
//	}
//}
//
///***********************--------------------Regular MERGE function----------------****************************/
//void merge(int* arr, int low, int mid, int high) {
//	int i, j, k;
//	int* temp = new int[high - low + 1];
//	i = low;
//	k = 0;
//	j = mid + 1;
//
//	while (i <= mid && j <= high) {
//		if (arr[i] < arr[j]) {
//			temp[k] = arr[i];
//			i++;
//		}
//		else {
//			temp[k] = arr[j];
//			j++;
//		}
//		k++;
//	}
//
//	while (i <= mid) {
//		temp[k] = arr[i];
//		i++;
//		k++;
//	}
//
//	while (j <= high) {
//		temp[k] = arr[j];
//		j++;
//		k++;
//	}
//
//	for (int m = low; m <= high; m++) {
//		arr[m] = temp[m - low];
//	}
//
//	delete[] temp;
//}
//
///*****************************------------MAIN FUNCTION---------------*******************************/
//int main(int argc, char** argv) {
//	int size, rank;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	const int SIZE = 4096;
//	const int SIZE2 = SIZE * SIZE;
//	const int RANDRANGE = 8192;
//	const int THNUM = 8;
//	const int SUBSIZE = SIZE2 / THNUM;
//
//	int* mainArray = nullptr;
//	int* subArray = NULL;
//	subArray = (int*)malloc(SUBSIZE*sizeof(int));
//
//	if (rank == 0) {
//		mainArray = new int[SIZE2];
//		srand(static_cast<unsigned int>(time(nullptr)));
//		for (int i = 0; i < SIZE2; i++) {
//			mainArray[i] = rand() % RANDRANGE;
//		}
//		// Scatter subArrays to other ranks
//		for (int i = 1; i < THNUM; i++) {
//			MPI_Send(&mainArray[i*SUBSIZE], SUBSIZE, MPI_INT, i, 0, MPI_COMM_WORLD);
//		}
//	}
//	
//	
//	else {
//		// Receive subArray from rank 0
//		MPI_Recv(subArray, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		/*if (rank == 4)
//		{
//			cout << SUBSIZE << endl;
//			for (int i = 1; i < SUBSIZE; i++) {
//				cout << subArray[i] << " ";
//			}cout << endl;
//		}*/
//		quickSort(subArray, 0, SUBSIZE - 1);
//		/*if (rank == 4)
//		{
//		cout << SUBSIZE << endl;
//		for (int i = 1; i < SUBSIZE; i++) {
//		cout << subArray[i] << " ";
//		}cout << endl;
//		}*/
//	}
//	// Sort the subArray using quick sort
//	
//	
//
//	if (rank == 0)
//	{
//		for (int i = 0; i < THNUM;i++)
//		{
//			MPI_Recv(&mainArray[i*SUBSIZE], SUBSIZE, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		}
//	}
//	else
//	{
//		MPI_Send(subArray, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD);
//		for (int i = 0; i < 5500;i++)
//		{
//			cout<<mainArray[i];
//		}
//	}
//
//	// Merge the sorted subArrays in parallel
//	int divider = 2;
//
//	//for (int j = 1; j < THNUM; j *= 2) {
//	//	for (int i = 0; i < THNUM; i += 2 * j) {
//	//		int start = i * SUBSIZE;
//	//		int mid = (i + j) * SUBSIZE - 1;
//	//		int end = (i + 2 * j) * SUBSIZE - 1;
//	//		if (end >= SIZE2) {
//	//			end = SIZE2 - 1;
//	//		}
//
//	//		std::cout << "Rank " << rank << ": start=" << start << " mid=" << mid << " end=" << end << std::endl;  // Add this line
//
//	//		merge(mainArray, start, mid, end);
//	//	}
//	//}
//	
//	if (rank == 0) {
//		// Print the sorted array
//		std::cout << "Sorted array: ";
//		/*for (int i = 0; i < 5500; i++) {
//			std::cout << mainArray[i] << "--";
//			std::cout << mainArray[SIZE2 - i - 1] << " ";
//		}
//		std::cout << std::endl;*/
//		for (int i = 0; i < 5500;i++)
//		{
//			std::cout << mainArray[i] << " ";
//		}
//
//		delete[] mainArray;
//	}
//
//	delete[] subArray;
//
//	MPI_Finalize();
//	return 0;
//}
