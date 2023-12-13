//#include <iostream>
//#include <vector>
//#include <omp.h>
//#include <algorithm>
//
//using namespace std;
//
//const int SIZE = 128;
//const int THREADS = 8;
//
//void quickSort(vector<int>& arr, int low, int high) {
//	if (low < high) {
//		int pivot = arr[high];
//		int i = low - 1;
//
//		for (int j = low; j <= high - 1; ++j) {
//			if (arr[j] <= pivot) {
//				++i;
//				swap(arr[i], arr[j]);
//			}
//		}
//
//		swap(arr[i + 1], arr[high]);
//
//		int pivot_index = i + 1;
//
//		quickSort(arr, low, pivot_index - 1);
//		quickSort(arr, pivot_index + 1, high);
//	}
//}
//
//void merge(vector<int>& arr, vector<int>& temp, int low, int mid, int high) {
//	int i = low, j = mid + 1, k = low;
//
//	while (i <= mid && j <= high) {
//		if (arr[i] <= arr[j])
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
//	for (int x = low; x <= high; ++x)
//		arr[x] = temp[x];
//}
//
//vector<int> parallelMergeSort(vector<int>& arr) {
//	vector<int> temp(SIZE);
//
//#pragma omp parallel num_threads(THREADS)
//	{
//		int tid = omp_get_thread_num();
//		int start = tid * (SIZE / THREADS);
//		int end = (tid + 1) * (SIZE / THREADS) - 1;
//
//		quickSort(arr, start, end);
//
//#pragma omp barrier
//
//		int step = 1;
//
//		while (step < THREADS) {
//			if (tid % (2 * step) == 0) {
//				int partner_tid = tid + step;
//
//				if (partner_tid < THREADS) {
//					int low = start;
//					int mid = start + step - 1;
//					int high = min(end, start + 2 * step - 1);
//
//					merge(arr, temp, low, mid, high);
//				}
//			}
//
//#pragma omp barrier
//
//			step *= 2;
//		}
//	}
//
//	return arr;
//}
//
//int main() {
//	vector<int> matrix(SIZE * SIZE);
//
//	// Initialize the matrix with random values
//	for (int i = 0; i < SIZE * SIZE; ++i)
//		matrix[i] = rand() % 100;
//
//	double start_time = omp_get_wtime();
//
//	// Perform parallel merge sort
//	vector<int> sortedMatrix = parallelMergeSort(matrix);
//
//	double end_time = omp_get_wtime();
//	double execution_time = end_time - start_time;
//
//	cout << "Merge sort completed." << endl;
//	cout << "Execution time: " << execution_time << " seconds" << endl;
//
//	// Print the sorted matrix
//	for (int i = 0; i < SIZE; ++i) {
//		for (int j = 0; j < SIZE; ++j) {
//			cout << sortedMatrix[i * SIZE + j] << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
