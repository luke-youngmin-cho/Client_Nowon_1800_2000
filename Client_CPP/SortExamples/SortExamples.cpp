#include "SortExamples.h"
#include <iostream>
using namespace std;

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
