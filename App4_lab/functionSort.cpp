#include "functionSort.h"
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void QuickSort(int arr[], int LowerLimit, int MaxLimit) {
	int pivot; // разрешающий элемент
	int l_hold = LowerLimit; //левая граница
	int r_hold = MaxLimit; // правая граница
	pivot = arr[LowerLimit];
	while (LowerLimit < MaxLimit) // пока границы не сомкнутся
	{
		while ((arr[MaxLimit] >= pivot) && (LowerLimit < MaxLimit))
			MaxLimit--; // сдвигаем правую границу пока элемент [MaxLimit] больше [pivot]
		if (LowerLimit != MaxLimit) // если границы не сомкнулись
		{
			arr[LowerLimit] = arr[MaxLimit]; // перемещаем элемент [MaxLimit] на место разрешающего
			LowerLimit++; // сдвигаем левую границу вправо 
		}
		while ((arr[LowerLimit] <= pivot) && (LowerLimit < MaxLimit))
			LowerLimit++; // сдвигаем левую границу пока элемент [LowerLimit] меньше [pivot]
		if (LowerLimit != MaxLimit) // если границы не сомкнулись
		{
			arr[MaxLimit] = arr[LowerLimit]; // перемещаем элемент [LowerLimit] на место [MaxLimit]
			MaxLimit--; // сдвигаем правую границу вправо 
		}
	}
	arr[LowerLimit] = pivot; // ставим разрешающий элемент на место
	pivot = LowerLimit;
	LowerLimit = l_hold;
	MaxLimit = r_hold;
	if (LowerLimit < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		QuickSort(arr, LowerLimit, pivot - 1);
	if (MaxLimit > pivot)
		QuickSort(arr, pivot + 1, MaxLimit);
}

int BinarySearch(int arr[], int N, int key) {
	int search = -1;
	int left = 0, right = N - 1;
	QuickSort(arr, 0, N - 1);
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (key == arr[mid]) {
			search = mid;
			break;
		}
		if (key < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return search;
}
void BubbleSort(int arr[], int sizeArr) {
	for (int i = 0; i < sizeArr - 1; i++)
	{
		for (int j = (sizeArr - 1); j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void siftDown(int arr[], int root, int bottom)
{
	int maxChild;
	int done = 0;
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
			maxChild = root * 2;
		else if (arr[root * 2] > arr[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;

		if (arr[root] < arr[maxChild])
		{
			int temp = arr[root];
			arr[root] = arr[maxChild];
			arr[maxChild] = temp;
			root = maxChild;
		}
		else
			done = 1;
	}
}
void HeapSort(int arr[], int array_size) {
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(arr, i, array_size - 1);

	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		siftDown(arr, 0, i - 1);
	}
}
void shuffle(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		int temp = (rand() % size);
		int elem = arr[i];
		arr[i] = arr[temp];
		arr[temp] = elem;

	}

}
int correct(int arr[], int size) {
	while (--size > 0)
		if (arr[size - 1] > arr[size])
			return 0;
	return 1;
}
void BogoSort(int arr[], int size) {
	while (!correct(arr, size))
		shuffle(arr, size);
}

char getRandomSymbol()
{
	char ch;
	unsigned short tmp;
	tmp = rand() % 205 + 50;
	ch = tmp;
	return ch;
}

void CountingSort(int size, char arr[], char sortArr[]) {
	for (int i = 0; i < size; i++)
		sortArr[i] = 0;
	for (int i = 0; i < size; i++)
		sortArr[arr[i]] = sortArr[arr[i]] + 1; \
		int k = 0;
	for (int i = 0; i < size; i++) {
		while (sortArr[i] != 0) {
			arr[k] = i;
			sortArr[i]--;
			k++;
		}
	}
}
void initFiles(int fileSize, bool operatingMode) {
	ofstream fout;
	switch (fileSize) {
	case 10:fout.open("10.txt"); break;
	case 100:fout.open("100.txt"); break;
	case 1000:fout.open("1000.txt"); break;
	case 10000:fout.open("10000.txt"); break;
	case 100000:fout.open("100000.txt"); break;
	case 1000000:fout.open("1000000.txt"); break;
	}
	if (!fout.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		if (operatingMode) {
			for (int i = 0; i < fileSize; i++)
				fout << rand() << " ";
		}
		else {
			for (int i = 0; i < fileSize; i++)
				fout << getRandomSymbol();
		}
	}
	fout.close();
}
void initArr(int arr[], int fileSize, int arrSize) {
	ifstream fit;
	switch (fileSize) {
	case 1:fit.open("10.txt"); break;
	case 2:fit.open("100.txt"); break;
	case 3:fit.open("1000.txt"); break;
	case 4:fit.open("10000.txt"); break;
	case 5:fit.open("100000.txt"); break;
	case 6:fit.open("1000000.txt"); break;
	}
	if (!fit.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		int i = 0;
		while (!fit.eof() && arrSize >= 0) {
			fit >> arr[i];
			i++;
			arrSize--;
		}
	}
	fit.close();
}
void initArr(char arr[], int fileSize, int arrSize) {
	ifstream fit;
	switch (fileSize) {
	case 1:fit.open("10.txt"); break;
	case 2:fit.open("100.txt"); break;
	case 3:fit.open("1000.txt"); break;
	case 4:fit.open("10000.txt"); break;
	case 5:fit.open("100000.txt"); break;
	case 6:fit.open("1000000.txt"); break;
	}
	if (!fit.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		int i = 0;
		while (!fit.eof() && arrSize >= 0) {
			fit >> arr[i];
			i++;
			arrSize--;
		}
	}
	fit.close();
}
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
void printArray(char arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
void runTime(unsigned int start_time, unsigned int end_time, int N) {
	unsigned int search_time = end_time - start_time;
	cout << endl << "Run time function: " << search_time / 1000.0 << " for Array size: " << N << endl;
}
void middleRunTimeFunction(bool operatingMode, int initFile, int N) {
	unsigned int start_time, end_time, full_time = 0;
	if (operatingMode) {
		switch (initFile) {
		case 1: {
			for (int i = 0; i < 10; i++) {
				int key = rand();
				int *arrInt = new int[N];
				initArr(arrInt, initFile, N - 1);
				start_time = clock();
				BinarySearch(arrInt, N, key);
				end_time = clock();
				full_time += (end_time - start_time);
			}
		}; break;
		case 2: {
			for (int i = 0; i < 10; i++) {
				int *arrInt = new int[N];
				initArr(arrInt, initFile, N - 1);
				start_time = clock();
				QuickSort(arrInt, 0, N - 1);
				end_time = clock();
				full_time += (end_time - start_time);
			}

		}; break;
		case 3: {
			for (int i = 0; i < 10; i++) {
				int *arrInt = new int[N];
				initArr(arrInt, initFile, N - 1);
				start_time = clock();
				BubbleSort(arrInt, N);
				end_time = clock();
				full_time += (end_time - start_time);
			}
		}; break;
		case 4: {
			for (int i = 0; i < 10; i++) {
				int *arrInt = new int[N];
				initArr(arrInt, initFile, N - 1);
				start_time = clock();
				HeapSort(arrInt, N);
				end_time = clock();
				full_time += (end_time - start_time);
			}
		}; break;
		case 5: {
			for (int i = 0; i < 10; i++) {
				int *arrInt = new int[N];
				initArr(arrInt, initFile, N - 1);
				start_time = clock();
				BogoSort(arrInt, N);
				end_time = clock();
				full_time += (end_time - start_time);
			}
		}; break;
		default: cout << "ERROR";
		}
	}
	else {

		char *arrCh = new char[N];
		for (int l = 0; l < 10; l++) {
			char *sortArr = new char[N];
			for (int i = 0; i < N; i++) {
				arrCh[i] = getRandomSymbol();
			}
			start_time = clock();
			CountingSort(N, arrCh, sortArr);
			end_time = clock();
			full_time += (end_time - start_time);

		}
	}
	cout << endl << " Middle run (10 call) time function: " << full_time / 1000.0 << " for Array size: " << N << endl;
}
void interfaceMenu() {

	int N, initFile;
	bool operatingMode;
	unsigned int start_time, end_time;

	cout << "Input size array: ";
	cin >> N;
	int *arrInt = new int[N];
	char *arrCh = new char[N];
	cout << endl;
	cout << "Input number: initialize FILE.txt" << endl;
	cout << "10.txt - 1" << endl;
	cout << "100.txt - 2" << endl;
	cout << "1000.txt - 3" << endl;
	cout << "10000.txt - 4" << endl;
	cout << "100000.txt - 5" << endl;
	cout << "1000000.txt - 6" << endl;
	cin >> initFile;
	cout << "Choose operating Mode (1 - int), (0 - char)";
	cin >> operatingMode;
	switch (initFile) {
	case 1:initFiles(10, operatingMode); break;
	case 2:initFiles(100, operatingMode); break;
	case 3:initFiles(1000, operatingMode); break;
	case 4:initFiles(10000, operatingMode); break;
	case 5:initFiles(100000, operatingMode); break;
	case 6:initFiles(1000000, operatingMode); break;
	default: cout << "ERROR";
	}



	if (operatingMode) {
		initArr(arrInt, initFile, N - 1);
		cout << "Original array:" << endl;
		printArray(arrInt, N);
		cout << "Choose function sort" << endl;
		cout << "BinarySearch - 1" << endl;
		cout << "QuickSort - 2" << endl;
		cout << "BubbleSort - 3" << endl;
		cout << "HeapSort- 4" << endl;
		cout << "BogoSort - 5" << endl;
		cin >> initFile;
		switch (initFile) {
		case 1: {
			int key;
			cout << "Enter an item to search: ";
			cin >> key;
			start_time = clock();
			cout << "Index item: " << BinarySearch(arrInt, N, key);
			end_time = clock();
			runTime(start_time, end_time, N);
			middleRunTimeFunction(operatingMode, initFile, N);
		}; break;
		case 2: {
			start_time = clock();
			QuickSort(arrInt, 0, N - 1);
			end_time = clock();
			runTime(start_time, end_time, N);
			printArray(arrInt, N);
			middleRunTimeFunction(operatingMode, initFile, N);
		}; break;
		case 3: {
			start_time = clock();
			BubbleSort(arrInt, N);
			end_time = clock();
			runTime(start_time, end_time, N);
			middleRunTimeFunction(operatingMode, initFile, N);
			printArray(arrInt, N);
		}; break;
		case 4: {
			start_time = clock();
			HeapSort(arrInt, N);
			end_time = clock();
			runTime(start_time, end_time, N);
			middleRunTimeFunction(operatingMode, initFile, N);
			printArray(arrInt, N);
		}; break;
		case 5: {
			start_time = clock();
			BogoSort(arrInt, N);
			end_time = clock();
			runTime(start_time, end_time, N);
			middleRunTimeFunction(operatingMode, initFile, N);
			printArray(arrInt, N);
		}; break;
		default: cout << "ERROR";
		}

	}
	else {
		initArr(arrCh, initFile, N - 1);
		cout << "Original array:" << endl;
		printArray(arrCh, N);
		cout << endl;
		cout << "function is available (CountingSort)" << endl;
		char *sortArr = new char[N];
		start_time = clock();
		CountingSort(N, arrCh, sortArr);
		end_time = clock();
		runTime(start_time, end_time, N);
		printArray(sortArr, N);;
		delete[] sortArr;
	}






	delete[] arrInt;
	delete[] arrCh;
}
