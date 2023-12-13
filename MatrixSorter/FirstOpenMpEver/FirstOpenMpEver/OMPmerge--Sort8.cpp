//#include <iostream>
//#include <omp.h>
//
//#define SIZE 32
//#define SIZE2 SIZE*SIZE
//#define RANDRANGE 8192
//#define THNUM 8
//#define SUBSIZE SIZE2/THNUM
//using namespace std;
//
//
//
//// Function to swap two elements
//void swap(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//// Partition function to rearrange the elements
//int partition(int* arr, int low, int high) {
//	int pivot = arr[high];
//	int i = low - 1;
//
//	for (int j = low; j <= high - 1; j++) {
//		if (arr[j] < pivot) {
//			i++;
//			swap(arr[i], arr[j]);
//		}
//	}
//	swap(arr[i + 1], arr[high]);
//	return (i + 1);
//}
//
//// Recursive function to perform Quick Sort
//void quickSort(int* arr, int low, int high) {
//	if (low < high) {
//		int pivot = partition(arr, low, high);
//
//		quickSort(arr, low, pivot - 1);
//		quickSort(arr, pivot + 1, high);
//	}
//}
//
//
//
//void merge(int arr[], int left[], int right[], int leftSize, int rightSize) {
//	int i = 0, j = 0, k = 0;
//
//	while (i < leftSize && j < rightSize) {
//		if (left[i] <= right[j]) {
//			arr[k] = left[i];
//			i++;
//		}
//		else {
//			arr[k] = right[j];
//			j++;
//		}
//		k++;
//	}
//
//	while (i < leftSize) {
//		arr[k] = left[i];
//		i++;
//		k++;
//	}
//
//	while (j < rightSize) {
//		arr[k] = right[j];
//		j++;
//		k++;
//	}
//}
//
//void mergeSort(int arr[], int size) {
//	if (size < SUBSIZE) {
//		return;
//	}
//
//	int mid = size / 2;
//	int* left = new int[mid];
//	int* right = new int[size - mid];
//
////#pragma omp parallel num_threads(THNUM)
////	{
//
//		for (int i = 0; i < mid; i++) {
//			left[i] = arr[i];
//		}
//		mergeSort(left, mid);
//
//
//
//		for (int i = mid; i < size; i++) {
//			right[i - mid] = arr[i];
//		}
//		mergeSort(right, size - mid);
//
//	//}
//	if (size == SUBSIZE) {
//		quickSort(left, 0, SUBSIZE - 1);
//		quickSort(right, 0, SUBSIZE - 1);
//	}
//	merge(arr, left, right, mid, size - mid);
//
//	delete[] left;
//	delete[] right;
//}
//
//int main() {
//	const int arraySize = SIZE2;
//	int* arr = new int[arraySize];
//
//	// Initialize the array with random values
//#pragma omp parallel for
//	for (int i = 0; i < arraySize; i++) {
//		arr[i] = rand() % RANDRANGE;
//	}
//
//	/*cout << "Original array:" << endl;
//	for (int i = 0; i < arraySize; i++) {
//	cout << arr[i] << " ";
//	}
//	cout << endl;*/
//
//	mergeSort(arr, arraySize);
//
//	cout << "Sorted array:" << endl;
//	for (int i = 0; i < 5500; i++) {
//		cout << arr[i] << "--";
//		cout << arr[SIZE2 - i - 1] << " ";
//	}
//	cout << endl;
//	/*for (int i = 0; i < arraySize; i++) {
//	cout << arr[i] << " ";
//	}
//	cout << endl;*/
//	system("pause");
//	return 0;
//}
