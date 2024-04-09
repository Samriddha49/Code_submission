#include <stdio.h> 
#include <stdlib.h> 
#include<time.h>
int swap_count=0;
int *gen_arr(int size)
{
    srand(time(NULL));
    int *ptr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        ptr[i] = (rand()%100)+1;
    }
    return ptr;
}
void merge(int arr[], int left, int mid, int right,char ch) 
{ 
	int i, j, k; 
	int l1 = mid - left + 1; 
	int l2 = right - mid; 
	int L[l1], R[l2]; 
	for (i = 0; i < l1; i++) 
		L[i] = arr[left + i]; 
	for (j = 0; j < l2; j++) 
		R[j] = arr[mid + 1 + j]; 
	i = 0; 
	j = 0; 
	k = left; 
    if(ch=='a')
    {
	while (i < l1 && j < l2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
            swap_count++;
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
            swap_count++;
		} 
		k++; 
	} 
	while (i < l1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
        swap_count++;
	} 
	while (j < l2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
        swap_count++;
	}
    }
    else
    {
        while (i < l1 && j < l2) { 
		if (L[i] >= R[j]) { 
			arr[k] = L[i]; 
			i++; 
            swap_count++;
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
            swap_count++;
		} 
		k++; 
	} 
	while (i < l1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
        swap_count++;
	} 
	while (j < l2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
        swap_count++;
	}
    }
    //return swap_count;
} 
void mergeSort(int arr[], int left, int right,char ch) 
{ 
	if (left < right) { 
		int m = left + (right - left) / 2;
		mergeSort(arr, left, m,ch); 
		mergeSort(arr, m + 1, right,ch); 
        merge(arr, left, m, right,ch); 
	} 
} 
void print(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
}
int main() 
{ 
    FILE* fh=fopen("Merge_sort_analysis.csv","w");
    fprintf(fh,"%s","Average case\n");
    fprintf(fh,"%s","array size,time_taken,no_of_swaps");
    fprintf(fh,"\n");
    int n;
    printf("Enter the upper limit on array size: ");
    scanf("%d",&n);
    int* a;
    for(int i=10;i<=n;i+=10)
    {
        
        //printf("Before sorting: %d \n",swap_count);
        a=gen_arr(i);
        printf("Before sorting\n");
        print(a,i);
        double start=clock();
        mergeSort(a,0,i,'a');
        printf("Sorted array:\n");
        print(a,i);
        double end=clock();
        printf("%f %d\n", ((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"%d,%.3f,%d",i,((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"\n");
        swap_count=0;
    }
printf("Average case over\n");
printf("Best case starts\n");
fprintf(fh,"%s","Best case\n");
for(int i=10;i<=n;i+=10)
    {
        
        //printf("Before sorting: %d \n",swap_count);
        a=gen_arr(i);
        mergeSort(a,0,i,'a');
        printf("Before sorting\n");
        print(a,i);
        double start=clock();
        mergeSort(a,0,i,'a');
        printf("Sorted array:\n");
        print(a,i);
        double end=clock();
        printf("%f %d\n", ((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"%d,%.3f,%d",i,((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"\n");
        swap_count=0;
    }
printf("Best case over\n");
fprintf(fh,"%s","Worst case\n");
printf("Worst case starts\n");
for(int i=10;i<=n;i+=10)
    {
        
        //printf("Before sorting: %d \n",swap_count);
        a=gen_arr(i);
        mergeSort(a,0,i,'d');
        printf("Before sorting\n");
        print(a,i);
        double start=clock();
        mergeSort(a,0,i,'a');
        printf("Sorted array:\n");
        print(a,i);
        double end=clock();
        printf("%f %d\n", ((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"%d,%.3f,%d",i,((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"\n");
        swap_count=0;
    }
fclose(fh);
}
