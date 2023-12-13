//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <mpi.h>
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
//	const int SIZE = 32;
//	const int SIZE2 = SIZE * SIZE;
//	const int RANDRANGE = 8192;
//	const int THNUM = 8;
//	const int SUBSIZE = SIZE2 / THNUM;
//
//	int* mainArray = new int[SIZE2];
//
//	if (rank == 0) {
//		srand(static_cast<unsigned int>(time(nullptr)));
//		for (int i = 0; i < SIZE2; i++) {
//			mainArray[i] = rand() % RANDRANGE;
//		}
//	}
//
//
//	if (rank == 0)
//	{
//		int* subArray0 = new int[SUBSIZE];
//		for (int i = 1; i < 8; i++)
//		{
//			MPI_Send(&mainArray[i*SUBSIZE], SUBSIZE, MPI_INT, i, 0, MPI_COMM_WORLD);
//		}
//		for (int i = 0; i < SUBSIZE;i++)
//		{
//			subArray0[i] = mainArray[i];
//		}
//		quickSort(subArray0, 0, SUBSIZE - 1);
//		int* subArray01 = new int[SUBSIZE*2];
//		for (int i = 0; i < SUBSIZE; i++)
//		{
//			subArray01[i] = subArray0[i];
//		}
//		MPI_Recv(&subArray01[SUBSIZE], SUBSIZE, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray01, 0, (SUBSIZE*2) - 1);
//		int* subArray0123 = new int[SUBSIZE * 4];
//		for (int i = 0; i < SUBSIZE * 2;i++)
//		{
//			subArray0123[i] = subArray01[i];
//		}
//		MPI_Recv(&subArray0123[SUBSIZE*2], SUBSIZE*2, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray0123, 0, (SUBSIZE * 4) - 1);
//		MPI_Recv(&mainArray[SUBSIZE * 4], SUBSIZE * 2, MPI_INT, 4, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(mainArray, 0, SIZE2);
//		
//
//	}
//	if (rank == 1)
//	{
//		int* subArray1 = new int[SUBSIZE];
//		MPI_Recv(subArray1, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD,  MPI_STATUS_IGNORE);
//		quickSort(subArray1, 0, SUBSIZE - 1);
//		MPI_Send(subArray1, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD);
//	}
//	if (rank == 2)
//	{
//		int* subArray2 = new int[SUBSIZE];
//		MPI_Recv(subArray2, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray2, 0, SUBSIZE - 1);
//		int* subArray23 = new int[SUBSIZE * 2];
//		for (int i = 0; i < SUBSIZE; i++)
//		{
//			subArray23[i] = subArray2[i];
//		}
//		MPI_Recv(&subArray23[SUBSIZE], SUBSIZE, MPI_INT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray23, 0, (SUBSIZE * 2) - 1);
//		MPI_Send(subArray23, SUBSIZE*2, MPI_INT, 0, 0, MPI_COMM_WORLD);
//	}
//	if (rank == 3)
//	{
//		int* subArray3 = new int[SUBSIZE];
//		MPI_Recv(subArray3, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray3, 0, SUBSIZE - 1);
//		MPI_Send(subArray3, SUBSIZE, MPI_INT, 2, 0, MPI_COMM_WORLD);
//	}
//	if (rank == 4)
//	{
//		int* subArray4 = new int[SUBSIZE];
//		MPI_Recv(subArray4, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray4, 0, SUBSIZE - 1);
//		int* subArray45 = new int[SUBSIZE * 2];
//		for (int i = 0; i < SUBSIZE; i++)
//		{
//			subArray45[i] = subArray4[i];
//		}
//		MPI_Recv(&subArray45[SUBSIZE], SUBSIZE, MPI_INT, 5, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray45, 0, (SUBSIZE * 2) - 1);
//		int* subArray4567 = new int[SUBSIZE * 4];
//
//		for (int i = 0; i < SUBSIZE * 2;i++)
//		{
//			subArray4567[i] = subArray45[i];
//		}
//		MPI_Recv(&subArray4567[SUBSIZE * 2], SUBSIZE * 2, MPI_INT, 6, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray4567, 0, (SUBSIZE * 4) - 1);
//		MPI_Send(subArray4567, SUBSIZE*4, MPI_INT, 0, 0, MPI_COMM_WORLD);
//	}
//	if (rank == 5)
//	{
//		int* subArray5 = new int[SUBSIZE];
//		MPI_Recv(subArray5, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray5, 0, SUBSIZE - 1);
//		MPI_Send(subArray5, SUBSIZE, MPI_INT, 4, 0, MPI_COMM_WORLD);
//	}
//	if (rank == 6)
//	{
//		int* subArray6 = new int[SUBSIZE];
//		MPI_Recv(subArray6, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray6, 0, SUBSIZE - 1);
//		int* subArray67 = new int[SUBSIZE * 2];
//		for (int i = 0; i < SUBSIZE; i++)
//		{
//			subArray67[i] = subArray6[i];
//		}
//		MPI_Recv(&subArray67[SUBSIZE], SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray67, 0, (SUBSIZE * 2) - 1);
//		MPI_Send(subArray67, SUBSIZE * 2, MPI_INT, 4, 0, MPI_COMM_WORLD);
//	}
//	if (rank == 7)
//	{
//		int* subArray7 = new int[SUBSIZE];
//		MPI_Recv(subArray7, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray7, 0, SUBSIZE - 1);
//		MPI_Send(subArray7, SUBSIZE, MPI_INT, 6, 0, MPI_COMM_WORLD);
//	}
//	cout << "everything is ok.";
//	for (int i = 0; i < SIZE2;i++)
//	{
//		cout << mainArray[i] << " ";
//	}
//	MPI_Finalize();
//	return 0;
//}
