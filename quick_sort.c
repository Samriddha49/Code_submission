#include<stdio.h>
#include<stdlib.h>
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
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition_index(int *arr,int low,int high,char ch)
{
    // printf("Inside partition func: \n");
    // printf("Before Partition\n");
    // for(int i=0;i<10;i++)
    // printf("%d ",arr[i]);
    // printf("\n");
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    if(ch=='a' || ch=='A')
    {
    // int pivot=arr[low];
    // int i=low+1;
    // int j=high;
    while(i<j)
    {
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<j)
        {
        swap(&arr[i],&arr[j]);
        swap_count++;
        }
    }   
    if(arr[low]>=arr[j])
    {
    swap(&arr[low],&arr[j]);
    swap_count++;
    }
    }
    else
    {
    // int pivot=arr[low];
    // int i=low+1;
    // int j=high;
    while(i<j)
    {
        while(arr[i]>pivot) i++;
        while(arr[j]<pivot) j--;
        if(i<j)
        {
        swap(&arr[i],&arr[j]);
        swap_count++;
        }
    }   
    if(arr[low]<=arr[j])
    {
    swap(&arr[low],&arr[j]);
    swap_count++;
    }
    }
    // printf("After Partition\n");
    // for(int i=0;i<10;i++)
    // printf("%d ",arr[i]);
    // printf("\n");
    return j;
}
void quick_sort(int *arr,int low,int high,char ch)
{
    if(low<high)
    {
    int pi=partition_index(arr,low,high,ch);
    // printf("The partition index is %d\n",pi);
    // printf("Inside quick_sort\n");

    //if(pi!=0)
    quick_sort(arr,low,pi-1,ch);

    // printf("Printing result after first recursive call: \n");
    // for(int i=0;i<=pi-1;i++)
    // printf("%d ",arr[i]);
    // printf("\n");

    quick_sort(arr,pi+1,high,ch);

    // printf("Printing result after second recursive call: \n");
    // for(int i=pi+1;i<10;i++)
    // printf("%d ",arr[i]);
    // printf("\n");
    }
}
void print(int* arr,int size)
{
    for(int i=0;i<size;i++)
    printf("%d ",arr[i]);
    printf("\n");
}
void main()
{
    FILE* fh=fopen("Quick_sort_analysis3.csv","w");
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
        print(a,i);
        double start=clock();
        quick_sort(a,0,i-1,'a');
        printf("Sorted array:\n");
        print(a,i);
        print(a,i);
        double end=clock();
        printf("%f %d\n", ((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"%d,%.3f,%d",i,((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"\n");
        swap_count=0;
    }
    swap_count=0;
    fprintf(fh,"%s","Best case\n");
    for(int i=10;i<=n;i+=10)
    {
        //printf("Before sorting: %d \n",swap_count);
        a=gen_arr(i);
        print(a,i);
        quick_sort(a,0,i-1,'a');
        double start=clock();
        quick_sort(a,0,i-1,'a');
        print(a,i);
        double end=clock();
        printf("%f %d\n", ((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"%d,%.3f,%d",i,((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"\n");
        swap_count=0;
    }
    swap_count=0;
    fprintf(fh,"%s","Worst case\n");
    for(int i=10;i<=n;i+=10)
    {
        //printf("Before sorting: %d \n",swap_count);
        a=gen_arr(i);
        print(a,i);
        quick_sort(a,0,i-1,'d');
        print(a,i);
        double start=clock();
        quick_sort(a,0,i-1,'a');
        print(a,i);
        double end=clock();
        printf("%f %d\n", ((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"%d,%.3f,%d",i,((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"\n");
        swap_count=0;
    }
    fclose(fh);
}
