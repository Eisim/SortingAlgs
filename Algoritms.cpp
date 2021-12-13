#include"Header.h"
//other algs

void CreateArray(NeedType* arr,int n) {
	for (int i = 0; i < n; ++i) {
		arr[i] = rand();
	}
}



void swap(NeedType* a, NeedType* b) {
	NeedType tmp = *a;
	*a = *b;
	*b = tmp;
}

unsigned int checkTime(void func(NeedType*,int),NeedType*arr,int n) {
    unsigned int t1, t2, time;
    t1 = clock();
    func(&arr[0],n);
    t2 = clock();
    time = t2 - t1;
    return time;
}


//sorting algs

void BubbleSort(NeedType* arr, int n) {

	for (int i = 0; i < n; ++i) {
		bool flag = true;
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				flag = false;
			}
		}
		if (flag) break;
		//printf("%lf\n",arr[i]);
	}
}

void InsertionSort(NeedType* arr, int n) {
	int index;
	for (int i = 1; i < n; i++) {
		index = i;
		NeedType value = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] < arr[j])index = j;
		}
		for (int j = i; j >= index; j--) 
			arr[j] = arr[j - 1];
		arr[index] = value;
		
	}
}

void Merge(NeedType Mas[], int left, int right, int mid)
{
    int j = left;
    int k = mid + 1;
    int count = right - left + 1;

    if (count <= 1) return;

    NeedType* TmpMas =  (NeedType*)malloc(sizeof(NeedType)*count);

    for (int i = 0; i < count; ++i) {
        if (j <= mid && k <= right) {
            if (Mas[j] < Mas[k])
                TmpMas[i] = Mas[j++];
            else
                TmpMas[i] = Mas[k++];
        }
        else {
            if (j <= mid)
                TmpMas[i] = Mas[j++];
            else
                TmpMas[i] = Mas[k++];
        }
    }
    j = 0;
    for (int i = left; i <= right; ++i) {
        Mas[i] = TmpMas[j++];
    }
    free(TmpMas);
}
void startMergeSort(NeedType a[],int n) {
    MergeSort(&a[0],0,n-1);
}
    

void MergeSort(NeedType a[], int l, int r)
{
    int m;
    if (l >= r) return;
    m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, r, m);
}
