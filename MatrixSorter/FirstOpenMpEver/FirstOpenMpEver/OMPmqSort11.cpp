//#include <iostream>
//#include <omp.h>
//#include <ctime>
///*****************************------------Static value defination---------------*******************************/
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
///*****************************------------Partition func for quick sort---------------*******************************/
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
///*****************************--------------------------QUICK SORT  ---------------------*******************************/
//void quickSort(int* arr, int low, int high) 
//{
//	if (low < high) {
//		int pivot = partition(arr, low, high);
//		quickSort(arr, low, pivot - 1);
//		quickSort(arr, pivot + 1, high);
//	}
//}
//
///*****************************-----------------------Regular MERGE function-------------------*******************************/
//
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
//
//
//int main() {
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
//		int startIdx;
//		int endIdx;
//
//	// as we know each section can have only one thread so we can devide the data by sections between each thread 
//		//then send them to the quick sort to have a normal sorting( not parallel) as mentioned in the assignment
//#pragma omp sections
//		{
//#pragma omp section // section 0
//			{
//				startIdx = 0;
//				int endIdx = startIdx + subArrSize - 1;
//				quickSort(mainArray, startIdx, endIdx);
//			}
//#pragma omp section // section 1
//			{
//				startIdx = subArrSize;
//				int endIdx = startIdx + subArrSize - 1;
//				quickSort(mainArray, startIdx, endIdx);
//			}
//#pragma omp section // section 2
//			{
//				startIdx =  2 *subArrSize;
//				int endIdx = startIdx + subArrSize - 1;
//				quickSort(mainArray, startIdx, endIdx);
//			}
//#pragma omp section // section 3
//			{
//				startIdx = 3 * subArrSize;
//				int endIdx = startIdx + subArrSize - 1;
//				quickSort(mainArray, startIdx, endIdx);
//			}
//#pragma omp section // section 4
//			{
//				startIdx = 4 * subArrSize;
//				int endIdx = startIdx + subArrSize - 1;
//				quickSort(mainArray, startIdx, endIdx);
//			}
//#pragma omp section // section 5
//			{
//				startIdx = 5 * subArrSize;
//				int endIdx = startIdx + subArrSize - 1;
//				quickSort(mainArray, startIdx, endIdx);
//			}
//#pragma omp section // section 6
//			{
//				startIdx = 6 * subArrSize;
//				int endIdx = startIdx + subArrSize - 1;
//				quickSort(mainArray, startIdx, endIdx);
//			}
//#pragma omp section // section 7
//			{
//				startIdx = 7 * subArrSize;
//				int endIdx = startIdx + subArrSize - 1;
//				quickSort(mainArray, startIdx, endIdx);
//			}
//		}
//	}
//
//	/*****************************------------Merge the sorted parts in parallel---------------*******************************/
//	int step = 1;
//	int division = 2;
//	int thread_step = 2;
//
//	for (int j = 1;j < THNUM; j)
//	{
//#pragma omp parallel for num_threads(THNUM/division)
//		for (int i = 0; i < THNUM; i += 2 * j)
//		{
//			//	printf("thred index is : %d \n", omp_get_thread_num());
//			int start = i * subArrSize;
//			int mid = (i + j) * subArrSize - 1;
//			int end = (i + 2 * j) * subArrSize - 1;
//			merge(mainArray, start, mid, end);
//		}
//		j *= 2;
//		division = division * 2;
//
//	}
//
//
//
//	// Print the sorted array
//	printf("Sorted array: ");
//	for (int i = 0; i < 5500; i++)
//	{
//		cout << mainArray[i] << "--";
//		cout << mainArray[SIZE2 - i - 1] << " ";
//	}
//
//
//	/*for (int i = 0; i<SIZE2; i++) {
//	delete[] twoDArr[i];
//	}
//
//	delete[] twoDArr;*/
//
//	delete[] mainArray;
//	system("pause");
//	return 0;
//}
//
