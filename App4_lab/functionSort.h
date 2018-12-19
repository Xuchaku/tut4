#pragma once
int BinarySearch(int arr[], int N, int key);
void QuickSort(int arr[], int LowerLimit, int MaxLimit);
void BubbleSort(int arr[], int sizeArr);

void siftDown(int arr[], int root, int bottom);
void HeapSort(int arr[], int array_size);

void BogoSort(int arr[], int size);
void shuffle(int arr[], int size);
int correct(int arr[], int size);

void CountingSort(int size, char arr[], char sortArr[]);
char getRandomSymbol();

void initFiles(int fileSize, bool operatingMode);
void initArr(int arr[], int fileSize, int arrSize);
void initArr(char arr[], int fileSize, int arrSize);
void printArray(int arr[], int size);
void printArray(char arr[], int size);

void interfaceMenu();
void middleRunTimeFunction(bool operatingMode, int initFile, int N);
void runTime(unsigned int start_time, unsigned int end_time, int N);
