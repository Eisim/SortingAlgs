#include"Header.h"

int main() {
	srand(time(0));

	LenType n,checkNum;
	
	printf("Lenght:");
	scanf_s("%d", &n);
	printf("Check Number:");
	scanf_s("%d",&checkNum);
	//create array
	NeedType* array = (NeedType*)malloc(n * sizeof(NeedType));
	CreateArray(&array[0], n);
	//start sorting
	printf("\n---Result---\n");

	double* timeHistory=(double*)malloc(sizeof(double)* checkNum);
	//take average time
	for (int i = 0; i < checkNum; i++) {
		timeHistory[i] = checkTime(startMergeSort, array, n);
		CreateArray(&array[0], n);
		(isSorted(array, n)) ? printf("%d)Array sorted\n",i) : printf("Array not sorted.Please write to my creator)\n");
	}
	
	double res = average(timeHistory,checkNum);
	//print result
	
	
	printf("Average time(%d checks):%lf sec \n",checkNum,res);
	free(array);
	free(timeHistory);
	return 0;
}
