#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int front = -1, rear = -1;
int isFull(int SIZE) {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}
void enQueue(int items[],int SIZE,int element) {
  if (isFull(SIZE))
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}
int deQueue(int items[],int SIZE) {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}
void display(int items[],int SIZE) {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}
bool in(int arr[],int size,int ele)
{
  for(int i=0;i<size;i++)
  if(arr[i]==ele)
  return 1;
  return 0;
}
void bfs(int* adj_mat[],int start,int n,int visited_arr[])
{
   int c=0;
   visited_arr[c++]=start;
   for(int i=start;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
      if(adj_mat[i][j]==1 && !in(visited_arr,n,j))
      {
      printf("%d",j);
      visited_arr[c++]=j;
      }
      }
   }
   for(int i=0;i<start;i++)
   {
    for(int j=0;j<n;j++)
      {
      if(adj_mat[i][j]==1 && !in(visited_arr,n,j))
      {
      printf("%d",j);
      visited_arr[c++]=j;
      }
      }
   }
}
void dfs(int start)
{
   printf("How many vertices: ");
    int n;
    scanf("%d",&n);
    //int explo_q[n];
    int visited_arr[n];
    for(int i=0;i<n;i++)
    visited_arr[i]=-1;
    int adj_mat[n][n];
    printf("Enter adjacency matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        scanf("%d",&adj_mat[i][j]);
    }
}
int main()
{
    printf("How many vertices: ");
    int n;
    scanf("%d",&n);
    //int explo_q[n];
    int visited_arr[n];
    for(int i=0;i<n;i++)
    visited_arr[i]=-1;
    int adj_mat[n][n];
    printf("Enter adjacency matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        scanf("%d",&adj_mat[i][j]);
    }

    bfs(adj_mat,0,n,visited_arr);
   //  int start=2;
   //  int c=0;
   //  printf("%d ",start);
   // visited_arr[c++]=start;
   // for(int i=start;i<n;i++)
   // {
   //    for(int j=0;j<n;j++)
   //    {
   //    if(adj_mat[i][j]==1 && !in(visited_arr,n,j))
   //    {
   //    printf("%d ",j);
   //    visited_arr[c++]=j;
   //    }
   //    }
   // }
   // for(int i=0;i<start;i++)
   // {
   //  for(int j=0;j<n;j++)
   //    {
   //    if(adj_mat[i][j]==1 && !in(visited_arr,n,j))
   //    {
   //    printf("%d ",j);
   //    visited_arr[c++]=j;
   //    }
   //    }
   // }

   int start=0;
   int c=0;
   int visited_arr[c++]=start;
   int eq[n];
   printf("%d ",start);
   for(int i=start;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
      if(adj_mat[i][j]==1 && !in(visited_arr,n,j))
      {
         printf("%d ",j);
         enQueue(eq,n,j);
         visited_arr[c++]=j;
         i=j;
         break;
      }
      // for(int k=0;k<n;k++)
      // if(adj_mat[j][k]==1 !in(visited_arr,n,k))
      // {
      //    printf("%d ",k);
      //    visited_arr[c++]=k;
      // }
      // }
   }
}
}