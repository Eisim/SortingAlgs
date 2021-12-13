#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef float NeedType;

void CreateArray(NeedType* arr, int n);
void swap(NeedType* a, NeedType* b);
unsigned int checkTime(void func(NeedType*, int), NeedType* arr, int n);

void BubbleSort(NeedType* array, int n);
void InsertionSort(NeedType* arr, int n);
void startMergeSort(NeedType a[], int n);
void MergeSort(NeedType a[], int l, int r);