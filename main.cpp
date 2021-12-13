#include"Header.h"

int main() {
	srand(time(0));

	int n;
	printf("Lenght:");
	scanf_s("%d", &n);

	NeedType* array = (NeedType*)malloc(n * sizeof(NeedType));
	CreateArray(&array[0], n);

	//for (int i = 0; i < n; i++) printf("%f\n", array[i]);
	printf("\n---Result---\n");
	
	unsigned res =  checkTime(startMergeSort, &array[0], n);
	
	//for (int i = 0; i < n; i++) printf("%lf\n", array[i]);

	printf("Time:%d",res);
	free(array);
	return 0;
}