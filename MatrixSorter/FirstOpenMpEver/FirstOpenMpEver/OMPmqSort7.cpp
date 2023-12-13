//#include <iostream>
//#include <omp.h>
//#include <vector>
//
//#define SIZE 8
//#define SIZE2 SIZE*SIZE
//#define RANDRANGE 20
//#define THNUM 8
//#define SUBSIZE SIZE2/THNUM
//using namespace std;
//
//// Quicksort function
//void quicksort(int* arr , int left, int right) {
//	int tid = omp_get_thread_num();
//	//cout <<"doing quick sort by"<< tid << endl;
//	if (left < right) {
//		int pivot = arr[right];
//		int i = left - 1;
//
//		for (int j = left; j <= right - 1; ++j) {
//			if (arr[j] <= pivot) {
//				++i;
//				swap(arr[i], arr[j]);
//			}
//		}
//
//		swap(arr[i + 1], arr[right]);
//
//		int partitionIndex = i + 1;
//
//		quicksort(arr, left, partitionIndex - 1);
//		quicksort(arr, partitionIndex + 1, right);
//	}
//}
//
////Merge function from original merge sort algorithm.
////vector<int> mergeSortedVectors(const vector<int>& vec1, const vector<int>& vec2) {
////	vector<int> merged(vec1.size() + vec2.size());
////	int i = 0, j = 0, k = 0;
////	int tid = omp_get_thread_num();
////	//cout << "merge sort by " << tid << endl;
////
////
////	while (i < vec1.size() && j < vec2.size()) {
////		//cout << "comparing " << i << " with " << j <<" by thread : "<<tid<< endl;
////		if (vec1[i] <= vec2[j]) {
////
////
////			merged[k] = vec1[i];
////			++i;
////		}
////
////		else {
////
////			merged[k] = vec2[j];
////			++j;
////		}
////
////		++k;
////	}
////
////	while (i < vec1.size()) {
////
////		merged[k] = vec1[i];
////		++i;
////		++k;
////	}
////
////
////	while (j < vec2.size()) {
////
////		merged[k] = vec2[j];
////		++j;
////		++k;
////	}
////
////
////
////	return merged;
////}
//////merge sort (modified) for sum  vectors instead of elements of an array or sth.
////vector<int> mergeAllVectors(const vector<vector<int>>& vectors) {
////	if (vectors.empty())
////		return vector<int>();
////
////
////	vector<int> merged = vectors[0];
////
////#pragma omp parallel for shared(merged)
////	for (int i = 1; i < vectors.size(); ++i)
////	{
////		cout << "size of vector " << i << " = " << vectors[i].size() << "and size of merged  = " << merged.size() << endl;
////		merged = mergeSortedVectors(merged, vectors[i]);
////	}
////	return merged;
////}
//
//void mergeSortedArrays(int* arr1, int* arr2, int* result, int size1, int size2)
//{
//		int i = 0, j = 0, k = 0;
//		while (i < size1 && j < size2) {
//			if (arr1[i] <= arr2[j]) 
//			{
//				result[k] = arr1[i];
//				cout << result[k] << " ";
//				++i;
//			}
//			else 
//			{
//				result[k] = arr2[j];
//				cout << result[k] <<" ";
//				++j;
//			}
//			++k;
//		}
//	
//		while (i < size1)
//		{
//			result[k] = arr1[i];
//			cout << result[k] << " ";
//			++i;
//			++k;
//		}
//	
//		while (j < size2) 
//		{
//			result[k] = arr2[j];
//			cout << result[k] << " ";
//			++j;
//			++k;
//		}
//}
//
//
//
//
//
//void mergeAllArr(int* mainArray, int** subArrays)
//{
//	int** subArr2 = new int*[THNUM / 2];
//	for (int i = 0; i < THNUM/2; i++)
//	{
//		subArr2[i] = new int[SIZE];
//	}
//	int** subArr3 = new int*[THNUM / 4];
//	for (int i = 0; i < THNUM/4; i++)
//	{
//		subArr3[i] = new int[SIZE];
//	}
//	int size1 = SUBSIZE;
//	int size2 = SUBSIZE * 2;
//	int size3 = SUBSIZE * 4;
//	for (int i = 0; i < THNUM / 2 ;i++)
//	{
//		cout << endl;
//		mergeSortedArrays(subArrays[2 * i], subArrays[2 * i + 1], subArr2[i], size1, size1 );
//		for (int j = 0; j < size2;j++)
//			cout  << subArr2[i][j];
//	}
//	for (int i = 0; i < THNUM / 4; i++)
//	{
//		cout << endl;
//		mergeSortedArrays(subArr2[2 * i], subArr2[2 * i + 1], subArr3[i], size2, size2);
//		for (int j = 0; j < size3;j++)
//			cout << subArr3[i][j];
//	}
//	cout << endl;
//	mergeSortedArrays(subArr3[0], subArr3[1], mainArray, size3, size3);
//	//for (int i = 0; i < THNUM / 2; i++)
//	//{
//	//	delete[] subArr2[i];
//	//}
//	//delete[] subArr2;
//	//for (int i = 0; i < THNUM / 4; i++)
//	//{
// //       delete[] subArr3[i];
//	//}
//	//delete[] subArr3;
//
//}
//
//
//
//int main() 
//{
//	//create the main matrix as a linear array and fill it.
//	int* mainArray = new int[SIZE2];
//	for (int i = 0; i < SIZE2; ++i) {
//		mainArray[i] = rand() % RANDRANGE;
//	}
//
//	int **subArrays = new int*[THNUM];
//	for (int i = 0; i < THNUM; i++)
//	{
//		subArrays[i] = new int[SIZE];
//	}
//
//		//spliting the data
//	for (int j = 0; j < THNUM; j++)
//	{
//		for (int i = 0; i < SUBSIZE;i++)
//		{
//			subArrays[j][i] = mainArray[i + j *SUBSIZE];
//			cout << subArrays[j][i] << " ";
//		}
//		cout << endl;
//	}
//#pragma omp parallel num_threads(THNUM)
//	{
//		int threadID = omp_get_thread_num();
//		quicksort(subArrays[threadID], 0, SUBSIZE - 1);
//	}
//	cout << "//////////////////****************************************////////////////////" << endl;
//		///////////////print sorted subArrays
//		for (int i = 0; i < THNUM;i++)
//		{
//			for (int j = 0 ; j < SUBSIZE; j++)
//				cout << subArrays[i][j]<<" ";
//			cout << endl;
//		}
//	
//		cout << "//////////////////****************************************////////////////////" << endl;
//	
//		mergeAllArr(mainArray, subArrays);
//
//	//printing separate sorted subarrays
//	//for (int i = 0; i < THNUM; ++i) 
//	//{
//	//	cout << "\n\nThread " << i << ": \n\n";
//	//	for (int j = 0; j < subArrays[i].size(); ++j) {
//	//		cout << subArrays[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//
//
//
//		for (int i = 0; i < SIZE2;i++)
//		{
//			cout << mainArray[i] << " - ";
//		}
//		cout << endl;
//
//
//
//
//
//
//
//
//
//	//vector<int> merged = mergeAllVectors(subArrays);
//
//	////print sorted final array
//	//for (int i = 0; i < merged.size(); ++i)
//	//{
//	//	cout << merged[i] << " ";
//	//}
//	//cout << std::endl;
//
//	//cout << "Original array:" << endl;
//	//for (int i = 0; i < arraySize; i++) {
//	//cout << arr[i] << " ";
//	//}
//	//cout << endl;
//	//#pragma omp parallel num_threads(8)
//	//	{
//	//		mergeSort(arr, arraySize);
//	//	}
//	//cout << "Sorted array:" << endl;
//	//for (int i = 0; i < 5500; i++) {
//	//	cout << arr[i] << "--";
//	//	cout << arr[SIZE2 - i - 1] << " ";
//	//}
//	//cout << endl;
//	//for (int i = 0; i < arraySize; i++) {
//	//cout << arr[i] << " ";
//	//}
//	//cout << endl;
//
//
//
//
//
//
///*
//		for (int i = 0; i < THNUM; i++)
//		{
//			 delete[] subArrays[i];
//		}
//		delete[] subArrays;
//	delete mainArray;*/
//	system("pause");
//	return 0;
//}
