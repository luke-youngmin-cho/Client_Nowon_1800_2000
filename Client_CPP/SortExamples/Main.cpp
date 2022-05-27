#include <iostream>
#include "SortExamples.h"
int main() {

	
	int arr1[10] = { 7, 6, 2, 4, 5, 1, 7, 9, 8, 0 };
	std::cout << "버블 소트 시작 : " << arr1 << std::endl;
	SortExamples::BubbleSort(arr1, 10);

	// 셀렉션 소트가 버블 소트보다 일반적으로 더 빠르다.
	// 둘다 1/2 * N^2 의 시간이 걸리지만 스왑의 총 횟수가 
	// 셀렉션 소트가 적기 때문이다.
	int arr2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	std::cout << "셀렉션 소트 시작 : " << arr2 << std::endl;
	SortExamples::SelectionSort(arr2, 10);

	int arr3[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	std::cout << "인설션 소트 시작 : " << arr3 << std::endl;
	SortExamples::InsertionSort(arr3, 10);

	int const mergeSortArrayCount = 30;
	int arr4[mergeSortArrayCount] = { 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	std::cout << "머지 소트 시작 : " << arr4 << std::endl;
	SortExamples::MergeSort(arr4, 0, mergeSortArrayCount - 1);

	for (int i = 0; i < mergeSortArrayCount; i++)
	{
		std::cout << arr4[i];
	}

	return 0;
}