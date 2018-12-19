#include "stdafx.h"
#include "CppUnitTest.h"
#include "../App4_lab/functionSort.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(BinarySearchOneElement)
		{
			int arr[1] = { 1 };
			Assert::AreEqual(BinarySearch(arr, 1, 1), 0);
		}
		TEST_METHOD(BinarySearchIncorrectOneElement)
		{
			int arr[1] = { 1 };
			Assert::AreEqual(BinarySearch(arr, 1, 99), -1);
		}
		TEST_METHOD(BinarySearchNoElement)
		{
			int arr[9] = { 444, 2, 33,87,12,43,66,20,11 };
			Assert::AreEqual(BinarySearch(arr, 9, 99), -1);
		}
		TEST_METHOD(BinarySearchNElement)
		{
			int arr[9] = { 444, 2, 33,87,12,43,66,20,11 };
			Assert::AreEqual(BinarySearch(arr, 9, 2), 0);
		}


		TEST_METHOD(QuickSortOneElement)
		{
			int arr1[1] = { 444 };
			QuickSort(arr1, 0, 0);
			Assert::AreEqual(arr1[0], 444);
		}
		TEST_METHOD(QuickSortNElement)
		{
			int arr[9] = { 444, 2, 33,87,12,43,66,20,11 };
			int sortArr[9] = { 2,11,12,20,33,43,66,87,444 };
			QuickSort(arr, 0, 8);
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(arr[i], sortArr[i]);
			}

		}
		TEST_METHOD(QuickSortRepeatElement)
		{
			int arr[9] = { 2, 2, 33,87,12,43,66,2,11 };
			int sortArr[9] = { 2,2,2,11,12,33,43,66,87 };
			QuickSort(arr, 0, 8);
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(arr[i], sortArr[i]);
			}

		}

		TEST_METHOD(BubbleSortOneElement)
		{
			int arr1[1] = { 444 };
			BubbleSort(arr1, 1);
			Assert::AreEqual(arr1[0], 444);
		}
		TEST_METHOD(BubbleSortNElement)
		{
			int arr[9] = { 444, 2, 33,87,12,43,66,20,11 };
			int sortArr[9] = { 2,11,12,20,33,43,66,87,444 };
			BubbleSort(arr, 9);
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(arr[i], sortArr[i]);
			}

		}
		TEST_METHOD(BubbleSortRepeatElement)
		{
			int arr[9] = { 2, 2, 33,87,12,43,66,2,11 };
			int sortArr[9] = { 2,2,2,11,12,33,43,66,87 };
			BubbleSort(arr, 9);
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(arr[i], sortArr[i]);
			}

		}

		TEST_METHOD(HeapSortOneElement)
		{
			int arr1[1] = { 444 };
			HeapSort(arr1, 1);
			Assert::AreEqual(arr1[0], 444);
		}
		TEST_METHOD(HeapSortNElement)
		{
			int arr[9] = { 444, 2, 33,87,12,43,66,20,11 };
			int sortArr[9] = { 2,11,12,20,33,43,66,87,444 };
			HeapSort(arr, 9);
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(arr[i], sortArr[i]);
			}

		}
		TEST_METHOD(HeapSortRepeatElement)
		{
			int arr[9] = { 2, 2, 33,87,12,43,66,2,11 };
			int sortArr[9] = { 2,2,2,11,12,33,43,66,87 };
			HeapSort(arr, 9);
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(arr[i], sortArr[i]);
			}

		}

		TEST_METHOD(BogoSortOneElement)
		{
			int arr1[1] = { 444 };
			BogoSort(arr1, 1);
			Assert::AreEqual(arr1[0], 444);
		}
		TEST_METHOD(BogoSortNElement)
		{
			int arr[9] = { 444, 2, 33,87,12,43,66,20,11 };
			int sortArr[9] = { 2,11,12,20,33,43,66,87,444 };
			BogoSort(arr, 9);
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(arr[i], sortArr[i]);
			}

		}
		TEST_METHOD(BogoSortRepeatElement)
		{
			int arr[9] = { 2, 2, 33,87,12,43,66,2,11 };
			int sortArr[9] = { 2,2,2,11,12,33,43,66,87 };
			BogoSort(arr, 9);
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(arr[i], sortArr[i]);
			}

		}

		TEST_METHOD(CoutingSortOneElement)
		{
			char arrCh[1] = { 'a' };
			char sortArr[1];
			CountingSort(1, arrCh, sortArr);
			Assert::AreEqual(arrCh[0], 'a');
		}
		TEST_METHOD(CoutingSortNElement)
		{
			char arrCh[9] = { 'g', 'f', '-', '1', 'a', 't', '5', ',', '&' };
			char sortArr[9];
			CountingSort(9, arrCh, sortArr);
			for (int i = 8; i >0; i--) {
				Assert::AreEqual(int(sortArr[i] >= sortArr[i - 1]), 1);
			}

		}
		TEST_METHOD(CoutingSortRepeatElement)
		{
			char arrCh[9] = { 'g', 'f', 'f', '1', 'a', 't', 'f', ',', '&' };
			char sortArr[9];
			CountingSort(9, arrCh, sortArr);
			for (int i = 8; i >0; i--) {
				Assert::AreEqual(int(sortArr[i] >= sortArr[i - 1]), 1);
			}

		}



	};
}
