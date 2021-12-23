#include"Header.h"
//other algs

void CreateArray(NeedType* arr, LenType n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand();
    }
}
bool isSorted(NeedType* arr, LenType n) {
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}


void swap(NeedType* a, NeedType* b) {
    NeedType tmp = *a;
    *a = *b;
    *b = tmp;
}

double average(double* arr,int n) {
    double res=0;
    for (int i = 0; i < n;i++) res+=arr[i];
    return res/n;
}

double checkTime(void func(NeedType*, LenType), NeedType* arr, LenType n) {
    double t1, t2, time;
    t1 = clock();
    func(&arr[0], n);
    t2 = clock();
    time = (t2 - t1)/CLOCKS_PER_SEC;
    return time;
}


//sorting algs

void BubbleSort(NeedType* arr, LenType n) {

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

void InsertionSort(NeedType* arr, LenType n) {
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

void Merge(NeedType Mas[], int left, int right, int mid, NeedType TmpMas[])
{
    int j = left;
    int k = mid + 1;
    int count = right - left + 1;

    if (count <= 1) {
        return;
    }

   

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
}
void startMergeSort(NeedType a[], LenType n) {
    NeedType* TmpMas = (NeedType*)malloc(sizeof(NeedType) * n);
    MergeSort(a, 0, n - 1, TmpMas);
    free(TmpMas);
}


void MergeSort(NeedType a[], int l, int r,NeedType TmpMas[])
{
    int m;
    if (l >= r) return;
    m = (l + r) / 2;
    MergeSort(a, l, m,TmpMas);
    MergeSort(a, m + 1, r,TmpMas);
    Merge(a, l, r, m, TmpMas);
}
