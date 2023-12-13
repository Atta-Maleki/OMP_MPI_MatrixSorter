//#include <iostream>
//#include <omp.h>
//
//#define SIZE 8
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
//void merge(int *a, int low, int high, int mid)
//{
//	// We have low to mid and mid+1 to high already sorted.
//	int i, j, k;
//	int* temp = new int[high - low + 1];
//	i = low;
//	k = 0;
//	j = mid + 1;
//
//	// Merge the two parts into temp[].
//	while (i <= mid && j <= high)
//	{
//		if (a[i] < a[j])
//		{
//			temp[k] = a[i];
//			k++;
//			i++;
//		}
//		else
//		{
//			temp[k] = a[j];
//			k++;
//			j++;
//		}
//	}
//
//	// Insert all the remaining values from i to mid into temp[].
//	while (i <= mid)
//	{
//		temp[k] = a[i];
//		k++;
//		i++;
//	}
//
//	// Insert all the remaining values from j to high into temp[].
//	while (j <= high)
//	{
//		temp[k] = a[j];
//		k++;
//		j++;
//	}
//
//
//	// Assign sorted data stored in temp[] to a[].
//	for (i = low; i <= high; i++)
//	{
//		a[i] = temp[i - low];
//	}
//	delete[] temp;
//}
//
//void mergeSort(int* arr, int startIdx, int endIdx) {
//	int mid;
//	if (((endIdx - startIdx)+1) < 2*SUBSIZE) {
//		return;
//	}
//
//	 mid = endIdx / 2;
//	 int newEnd = mid;
//	mergeSort(arr, startIdx, newEnd);
//
//	mergeSort(arr, newEnd +1 , endIdx);
//
//
//
//
//	//int* left = new int[mid];
//	//int* right = new int[size - mid];
//
//	////#pragma omp parallel num_threads(THNUM)
//	////	{
//
//	//for (int i = 0; i < mid; i++) {
//	//	left[i] = arr[i];
//	//}
//	//mergeSort(left, mid);
//
//
//
//	//for (int i = mid; i < size; i++) {
//	//	right[i - mid] = arr[i];
//	//}
//	//mergeSort(right, size - mid);
//
//	////}
//	if (((endIdx+1) - startIdx) == SUBSIZE) {
//
//		quickSort(arr, startIdx, mid);
//		quickSort(arr, mid+1, endIdx);
//	}
//	merge(arr, startIdx, endIdx, mid );
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
//	cout << SUBSIZE << " " << arraySize << " " << endl;
//	mergeSort(arr, 0, arraySize -1);
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
