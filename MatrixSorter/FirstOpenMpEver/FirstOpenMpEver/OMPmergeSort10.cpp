//#include <iostream>
//#include <omp.h>
//#include <ctime>
//
//#define SIZE 4096
//#define SIZE2 SIZE*SIZE
//#define RANDRANGE 8192
//#define THNUM 8
//#define SUBSIZE SIZE2/THNUM
//using namespace std;
//
//void swap(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
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
//void quickSort(int* arr, int low, int high) {
//	if (low < high) {
//		int pi = partition(arr, low, high);
//		quickSort(arr, low, pi - 1);
//		quickSort(arr, pi + 1, high);
//	}
//}
//
//void merge(int* arr, int low, int mid, int high) {
//	int* temp = new int[high - low + 1];
//	int i = low, j = mid + 1, k = 0;
//
//	while (i <= mid && j <= high) {
//		if (arr[i] < arr[j])
//			temp[k++] = arr[i++];
//		else
//			temp[k++] = arr[j++];
//	}
//
//	while (i <= mid)
//		temp[k++] = arr[i++];
//
//	while (j <= high)
//		temp[k++] = arr[j++];
//
//	for (i = low; i <= high; i++)
//		arr[i] = temp[i - low];
//	delete[] temp;
//}
//
//int main() {
//
//
//	//srand(time(NULL));
//	//int** twoDArr = new int*[ARRAY_SIZE];
//	//for (int i = 0; i<ARRAY_SIZE; i++) {
//	//	twoDArr[i] = new int[ARRAY_SIZE];
//	//}
//	//printf("original array: ");
//	//for (int i = 0; i < ARRAY_SIZE; i++) {
//	//	for (int j = 0; j < ARRAY_SIZE; j++) {
//	//		twoDArr[i][j] = rand() % 100;
//	//		printf("%d ", twoDArr[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//
//	//int* arr = new int[ARRAY_SIZE*ARRAY_SIZE];
//
//	//int k = 0;
//	//for (int i = 0; i < ARRAY_SIZE; i++) {
//	//	for (int j = 0; j < ARRAY_SIZE; j++) {
//	//		arr[k] = twoDArr[i][j];
//	//		k++;
//	//	}
//	//}
//
//	int* mainArray = new int[SIZE2];
//
//	for (int i = 0; i < SIZE2; i++)
//	{
//		mainArray[i] = rand() % RANDRANGE;
//	}
//
//
//
//
//	int subArrSize = SIZE2 / THNUM;
//
//	//this lines are for splitting the mainArray to subArrays
//	// and then make each thread run it by its ownself and in a normal
//	//way and then hold it
//#pragma omp parallel num_threads(THNUM)
//	{
//	//	printf("thread index in quick sort is : %d \n", omp_get_thread_num());
//		int thread_num = omp_get_thread_num();
//		int startIdx = thread_num * subArrSize;
//		int endIdx = startIdx + subArrSize - 1;
//
//		quickSort(mainArray, startIdx, endIdx);
//	}
//
//	// Merge the sorted parts in parallel
//	int step = 1;
//	int division = 2;
//	int thread_step = 2;
////	while (step < THNUM) {
////#pragma omp parallel for num_threads(THNUM/thread_step)
////		for ( int i = 0; i < THNUM; i += 2 * step) {
////		//	printf("thred index is : %d \n", omp_get_thread_num());
////			int start = i * subArrSize;
////			int mid = (i + step) * subArrSize - 1;
////			int end= (i + 2 * step) * subArrSize - 1;
////
////
////			merge(mainArray, start, mid, end);
////		}
////
////		step *= 2;
////		thread_step *= 2;
////	}
//
//	for (int j = 1;j < THNUM; j)
//	{
//		#pragma omp parallel for num_threads(THNUM/division)
//				for (int i = 0; i < THNUM; i += 2 * j) 
//				{
//				//	printf("thred index is : %d \n", omp_get_thread_num());
//					int start = i * subArrSize;
//					int mid = (i + j) * subArrSize - 1;
//					int end= (i + 2 * j) * subArrSize - 1;
//					merge(mainArray, start, mid, end);
//				}
//				j *= 2;
//				division = division * 2;
//
//	}
//	// Print the sorted array
//	printf("Sorted array: ");
//	for (int i = 0; i < 5500; i++)
//			{
//				cout << mainArray[i] << "--";
//				cout << mainArray[SIZE2 - i - 1] << " ";
//			}
//
//
//	/*for (int i = 0; i<SIZE2; i++) {
//		delete[] twoDArr[i];
//	}
//
//	delete[] twoDArr;*/
//
//	delete[] mainArray;
//	system("pause");
//	return 0;
//}
//
