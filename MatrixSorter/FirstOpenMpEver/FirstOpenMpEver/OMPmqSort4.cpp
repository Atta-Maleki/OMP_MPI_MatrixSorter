//#include <iostream>
//#include <omp.h>
//
//#define SIZE 2
//#define SIZE2 SIZE*SIZE
//#define RANDRANGE 512
//#define THNUM 8
//using namespace std;
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
//	if (size < 2) {
//		return;
//	}
//
//	int mid = size / 2;
//	int* left = new int[mid];
//	int* right = new int[size - mid];
//
//
//			for (int i = 0; i < mid; i++) {
//				left[i] = arr[i];
//			}
//			mergeSort(left, mid);
//
//
//	
//			for (int i = mid; i < size; i++) {
//				right[i - mid] = arr[i];
//			}
//			mergeSort(right, size - mid);
//		
//
//	merge(arr, left, right, mid, size - mid);
//
//	delete[] left;
//	delete[] right;
//	cout << "thread number : " << omp_get_thread_num() << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << "-";
//	}
//	cout << endl;
//}
//
//int main() {
//	const int arraySize = SIZE2;
//	int* arr = new int[arraySize];
//
//	// Initialize the array with random values
//#pragma omp parallel for num_threads(THNUM)
//	for (int i = 0; i < arraySize; i++) {
//		arr[i] = rand() % RANDRANGE;
//	}
//
//	/*cout << "Original array:" << endl;
//	for (int i = 0; i < arraySize; i++) {
//	cout << arr[i] << " ";
//	}
//	cout << endl;*/
//#pragma omp parallel num_threads(8)
//	{
//		mergeSort(arr, arraySize);
//	}
//	
//
//	cout << "Sorted array:" << endl;
//	//for (int i = 0; i < 5500; i++) {
//	//	cout << arr[i] << "--";
//	//	cout << arr[SIZE2 - i - 1] << " ";
//	//}
//	//cout << endl;
//	//for (int i = 0; i < arraySize; i++) {
//	//cout << arr[i] << " ";
//	//}
//	//cout << endl;
//	system("pause");
//	return 0;
//}
