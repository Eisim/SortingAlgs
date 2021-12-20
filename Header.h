#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef float NeedType;
typedef long int LenType;//type for detect length of array

void CreateArray(NeedType* arr, LenType n);
void swap(NeedType* a, NeedType* b);
double checkTime(void func(NeedType*, LenType), NeedType* arr, LenType n);
bool isSorted(NeedType* arr, LenType n);
double average(double* arr, int n);

void BubbleSort(NeedType* array, LenType n);
void InsertionSort(NeedType* arr, LenType n);
void startMergeSort(NeedType a[], LenType n);
void MergeSort(NeedType a[], int l, int r, NeedType TmpMas[]);