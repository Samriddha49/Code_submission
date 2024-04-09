  #include <stdio.h>
  #include<time.h>
  #include<stdlib.h>
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
  void print(int* arr,int size)
{
    for(int i=0;i<size;i++)
    printf("%d ",arr[i]);
    printf("\n");
}
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i,char ch) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if(ch=='a'||ch=='A')
    {
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      swap_count++;
      heapify(arr, n, largest,ch);
    }
    }
    else
    {
        if (left < n && arr[left] < arr[largest])
      largest = left;
  
    if (right < n && arr[right] < arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      swap_count++;
      heapify(arr, n, largest,ch);
    }
    }
  }

  void heapSort(int arr[], int n,char ch) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i,ch);
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      swap_count++;
      heapify(arr, i, 0,ch);
    }
  }
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  int main()
  {
    FILE* fh=fopen("Heap_sort_analysis.csv","w");
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
        heapSort(a,i,'a');
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
        heapSort(a,i,'a');
        double start=clock();
        heapSort(a,i,'a');
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
        heapSort(a,i,'d');
        print(a,i);
        double start=clock();
        heapSort(a,i,'a');
        print(a,i);
        double end=clock();
        printf("%f %d\n", ((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"%d,%.3f,%d",i,((end - start) / CLOCKS_PER_SEC)*(1000),swap_count);
        fprintf(fh,"\n");
        swap_count=0;
    }
    fclose(fh);
  }