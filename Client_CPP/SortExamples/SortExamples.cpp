#include "SortExamples.h"
#include <iostream>
using namespace std;

int SortExamples::testCount1;
int SortExamples::testCount2;
void SortExamples::Merge(int arr[], int start, int end, int mid)
{
	static int mergeCount;
	int* tmp = new int[end + 1];

	// 원본 배열 복사
	for (int i = start; i <= end; i++)
	{
		tmp[i] = arr[i];
		cout << "정복중..";
		mergeCount++;
	}

	int part1 = start; // 왼쪽 , 왼쪽 파트의 가장 왼쪽 인덱스로 초기화
	int part2 = mid + 1; // 오른쪽, 오른쪽 파트의 가장 왼쪽 인덱스로 초기화
	int index = start; // 원본 배열 원소 위치

	// 파트 1과 파트 2의 정복이 끝날때 까지 순회
	while (part1 <= mid && // 파트 1이 파트 2의 영역을 넘어가지 않았을 떄
		   part2 <= end) // 파트 2가 최대 영역을 넘어가지 않았을 때 
	{
		// 파트 1 과 파트 2 의 크기 비교
		if (tmp[part1] <= tmp[part2]) 
		{
			arr[index++] = tmp[part1++]; // 파트 1 인덱스 요소를 원본에 대입하고 각 인덱스 증가
			cout << "정복중..";
			mergeCount++;
		}
		else
		{
			arr[index++] = tmp[part2++]; // 파트 2 인덱스 요소를 원본에 대입하고 각 인덱스 증가
			cout << "정복중..";
			mergeCount++;
		}
	}

	// 정복이 끝난 part1 이후부터 mid 까지의 요소를 원본에 덧붙임
	for (int i = 0; i <= mid - part1; i++)
	{
		arr[index + i] = tmp[part1 + i];
		cout << "정복중..";
		mergeCount++;
	}

	cout << "머지완료 (count : " << mergeCount << ") :";
	for (int i = start; i <= end; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;

	delete[] tmp;
}

int SortExamples::Partition(int arr[], int start, int end)
{
	int pivot = arr[(start + end) / 2];

	while (true)
	{
		while (arr[start] < pivot) start++;
		while (arr[end] > pivot) end--;

		if (start < end) {
			int temp = arr[end];
			arr[end] = arr[start];
			arr[start] = temp;

			cout << "스왑중..";
			for (int i = start; i <= end; i++)
			{
				cout << arr[i] << ", ";
			}
			cout << endl;
		}
		else
		{
			return end;
		}
	}

	return 0;
}



void SortExamples::BubbleSort(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		// 이미 정렬된 친구들은 할필요 없으므로 length - i - 1 까지 순회
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 스왑
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

				// 스왑 결과 출력
				cout << "스왑됨 : ";
				for (int k = 0; k < length; k++)
				{
					cout << arr[k] << ",";
				}
				cout << endl;
			}
		}
	}
}

void SortExamples::SelectionSort(int arr[], int length)
{
	int minIdx = 0;
	for (int i = 0; i < length - 1; i++)
	{
		minIdx = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
		
		}

		// 스왑
		int tmp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = tmp;

		// 스왑 결과 출력
		cout << "스왑됨 : ";
		for (int k = 0; k < length; k++)
		{
			cout << arr[k] << ",";
		}
		cout << endl;
	}
}

void SortExamples::InsertionSort(int arr[], int length)
{
	int key, j = 0;
	for (int i = 1; i < length; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 &&
			   arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
			cout << "스왑중.. : ";
		}
		arr[j + 1] = key;

		// 스왑 결과 출력
		cout << "스왑됨 : ";
		for (int k = 0; k < length; k++)
		{
			cout << arr[k] << ",";
		}
		cout << endl;
	}
}

void SortExamples::MergeSort(int arr[], int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;

		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);

		Merge(arr, start, end, mid);
	}
}

void SortExamples::QuickSort(int arr[], int start, int end)
{
	if (start < end) {
		int p = Partition(arr, start, end);

		QuickSort(arr, start, p - 1);
		QuickSort(arr, p + 1, end);
	}
}

void SortExamples::HeapSort(int arr[], int length)
{
	// 힙 자료구조로 변환
	//Heapify_TopDown(arr, length);
	Heapify_BottomUp(arr, length);

	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;

	// 변환된 힙 자료구조 정렬 하면서 기본 배열 자료구조로 변환
	int end = length - 1;
	while (end > 0)
	{
		int tmp = arr[0];
		arr[0] = arr[end];
		arr[end] = tmp;
		
		end--;
		SIFT_Down(arr, end, 1);
	}
}

void SortExamples::Heapify_TopDown(int arr[], int length)
{
	int end = 1;

	while (end < length)
	{		
		SIFT_Up(arr, 0, end++);
	}
	std::cout << "Swap 횟수 : " << testCount1 << std::endl;
}

void SortExamples::Heapify_BottomUp(int arr[], int length)
{
	int end = length - 1;
	int current = end - 1;

	while (current >= 0)
	{
		SIFT_Down(arr, end, current--);
	}
	std::cout << "Swap 횟수 : " << testCount1 << std::endl;
}

void SortExamples::SIFT_Up(int arr[], int root, int current)
{
	int parent = (current - 1) / 2;
	while (current > root)
	{
		if (arr[parent] < arr[current])
		{
			int tmp = arr[parent];
			arr[parent] = arr[current];
			arr[current] = tmp;
			
			current = parent;
			parent = (current - 1) / 2;
			testCount1++;
		}
		else
		{
			break;
		}
	}
}

void SortExamples::SIFT_Down(int arr[], int end, int current)
{
	int parent = (current - 1) / 2;
	bool doSwap = false;

	while (current <= end)
	{
		// 오른쪽 자식이 더 크면 오른쪽꺼로 스왑할지 비교함
		if ((current + 1) <= end &&
			arr[current] < arr[current + 1])
			current++;

		if (arr[parent] < arr[current])
			doSwap = true;

		if (doSwap) 
		{
			int tmp = arr[parent];
			arr[parent] = arr[current];
			arr[current] = tmp;
			
			doSwap = false;
			parent = current;
			current = parent * 2 + 1;
			testCount1++;
		}
		else
		{
			break;
		}
	}
}
