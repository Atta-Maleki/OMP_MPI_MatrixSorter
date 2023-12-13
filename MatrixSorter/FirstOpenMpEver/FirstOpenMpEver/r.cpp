//#include <iostream>
//#include <omp.h>
//#include <ctime>
//using namespace std;
//#define ARRAY_SIZE 4096
//#define NUM_THREADS 8
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
//	int** twoDArr = new int*[ARRAY_SIZE];
//
//	srand(time(NULL));
//
//	for (int i = 0; i<ARRAY_SIZE; i++) {
//		twoDArr[i] = new int[ARRAY_SIZE];
//	}
//	printf("original array: ");
//	for (int i = 0; i < ARRAY_SIZE; i++) {
//		for (int j = 0; j < ARRAY_SIZE; j++) {
//			twoDArr[i][j] = rand() % 100;
//			//printf("%d ", twoDArr[i][j]);
//		}
//		//printf("\n");
//	}
//
//	int* arr = new int[ARRAY_SIZE*ARRAY_SIZE];
//	int k = 0;
//	for (int i = 0; i < ARRAY_SIZE; i++) {
//		for (int j = 0; j < ARRAY_SIZE; j++) {
//			arr[k] = twoDArr[i][j];
//			k++;
//		}
//	}
//
//
//	int chunk_size = ARRAY_SIZE / NUM_THREADS;
//	int i;
//
//
//#pragma omp parallel num_threads(NUM_THREADS)
//	{
//		//printf("thread index in quick sort is : %d \n", omp_get_thread_num());
//		int thread_num = omp_get_thread_num();
//		int start_index = thread_num * chunk_size;
//		int end_index = start_index + chunk_size - 1;
//
//		quickSort(arr, start_index, end_index);
//	}
//
//	// Merge the sorted parts in parallel
//	int step = 1;
//	int thread_step = 2;
//	while (step < NUM_THREADS) {
//#pragma omp parallel for num_threads(NUM_THREADS/thread_step)
//		for (i = 0; i < NUM_THREADS; i += 2 * step) {
//			//printf("thred index is : %d \n", omp_get_thread_num());
//			int start_index = i * chunk_size;
//			int mid_index = (i + step) * chunk_size - 1;
//			int end_index = (i + 2 * step) * chunk_size - 1;
//
//
//			merge(arr, start_index, mid_index, end_index);
//		}
//
//		step *= 2;
//		thread_step *= 2;
//	}
//
//	// Print the sorted array
//	printf("Sorted array: ");
//	for (int i = 0; i < ARRAY_SIZE; i++) {
//		for (int j = 0; j < ARRAY_SIZE; j++) {
//			printf("%d ", arr[i]);
//		}
//		printf("\n");
//	}
//
//
//	for (int i = 0; i<ARRAY_SIZE; i++) {
//		delete[] twoDArr[i];
//	}
//
//	delete[] twoDArr;
//
//	delete[] arr;
//
//	return 0;
//}
//
