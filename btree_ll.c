#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
typedef struct node
{
    struct node* left;
    int info;
    struct node* right;
    bool mark;
}node;

struct Stk{
    node* n;
    struct Stk* next;
};
typedef struct Stk stk;

void push(stk** top,node* n)
{
    stk* tmp=*top;
    //int c=0;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        //c++;
    }
    
    stk* new=(stk*)malloc(sizeof(stk));
    new->n=n;
    if(*top==NULL)
    {
        *top=new;
        (*top)->next=NULL;
    }
    else
    {
        new->next=*top;
        *top=new;
    }
}
node* pop(stk** top)
{
    if(*top==NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
    else
    {
    //printf("%d\n",(*top)->info);
    stk* tmp=*top;
    *top=(*top)->next;
    return tmp->n;
    }
}
bool isempty(stk** top)
{
    if(*top==NULL)
    return true;
    return false;
}
node* peek(stk** top)
{
    if(*top==NULL)
    printf("Nothing to show, stack is empty\n");  
    // else
    // printf("%d\n",top->n->info);
    return (*top)->n;
}
node* create(int data)
{
    node* newnode=malloc(sizeof(node));
    newnode->info=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void view_stack(stk** top)
{
  stk* tmp=*top;
  while(tmp!=NULL)
  {
  printf("%d ",tmp->n->info);
  tmp=tmp->next;
  }
  printf("End of viewing stack\n");
}
void Inorder(node**);
node* check_parent(node** root,int data)
{
    // if(*root==NULL)
    // return NULL;
    node* tmp=malloc(sizeof(node));
    tmp=*root;
    //node** t=root;
    printf("Root is %d\n",tmp->info);
    if(tmp->left)
    printf("Left of root %d and mark %d\n",tmp->left->info,tmp->left->mark);
    stk* stack_of_parents=NULL;
    push(&stack_of_parents,tmp);
    int c=0;
    Inorder(root);
    while(true)
    {
        c++;
        printf("%dth iteration\n",c);
        printf("Viewing stack\n");
        view_stack(&stack_of_parents);
        //push(&stack_of_parents,*t);
        if(tmp->left!=NULL && tmp->left->mark==false)
        printf("Left of tmp %d %d\n",tmp->left->info,tmp->left->mark);
        if(tmp->info==data)
        {
         printf("First if executed\n");
        return tmp;
        }
        else if(tmp->left!=NULL && tmp->left->mark==false)
        {
            //tmp=tmp->left;
            tmp=tmp->left;
            tmp->mark=true;
            if(tmp->info==data)
            {
            tmp->mark=false;
            return tmp;
            }
            if(tmp->left!=NULL && tmp->left->mark==true && tmp->right!=NULL && tmp->right->mark==true)
            tmp=pop(&stack_of_parents);
            else
            push(&stack_of_parents,tmp);
            printf("pointing to left, at %d now\n",tmp->info);
        }
        else if(tmp->right!=NULL && tmp->right->mark==false)
        {
            tmp=tmp->right;
            tmp->mark=true;
            push(&stack_of_parents,tmp);
            printf("pointing to right, at %d now\n",tmp->info);
        }
    
        if(tmp->left==NULL && tmp->right==NULL)
        {
            if(tmp->info==data)
            {
            printf("parent just found it was a leaf node(had no kids)!!\n");
            tmp->mark=false;
            return tmp;
            }
            tmp=pop(&stack_of_parents);
            //printf("peeked %d\n",tmp->info);
            // while(tmp->left->mark!=false || tmp->right->mark!=false || tmp->left==NULL || tmp->right==NULL)
            // {
            // tmp=pop(&stack_of_parents);
            // printf("At %d having mark %d\n",tmp->info,tmp->mark);
            // if(isempty(&stack_of_parents))
            // break;
            // }
            printf("Just popped the node %d since leaf was not the parent\n",tmp->info);
        }
        else if(tmp->left!=NULL && tmp->right!=NULL)
        {
            tmp=peek(&stack_of_parents);
            printf("Just peeked the node %d since both sides have been checked, so backtracking now\n",tmp->info);
        }
        else
        {
            if(tmp->right!=NULL && tmp->right->mark==false)
            {
            tmp=tmp->right;
            printf("Checking right since no left child....right child is %d\n",tmp->info);
            push(&stack_of_parents,tmp);
            }
            else if(tmp->left!=NULL && tmp->left->mark==false)
            {
            tmp=tmp->left;
            printf("Checking left since no right child....left child is %d\n",tmp->info);
            push(&stack_of_parents,tmp);
            }
        }
        
    }//while(!isempty(stack_of_parents))
    
}  
void insert(node** root,int parent_info,char nature,int data)
{
    node* tmp=check_parent(root,parent_info);
    printf("Parent %d found!\n",tmp->info);
    // if(tmp==NULL)
    node* child=create(data);
    // else 
    if(nature=='r' || nature== 'R')
    {
      tmp->right=child;
      printf("Right child %d placed at right of parent %d\n",child->info,tmp->info);
    }
    else if(nature=='l' || nature== 'L')
    {
        tmp->left=child;
        printf("Left child %d placed at left of parent %d\n",child->info,tmp->info);
    }
}
void delete(node** root,int parent_info,char nature)
{
    node* tmp=check_parent(root,parent_info);
    if(nature=='r' || nature== 'R')
    {
      free(tmp->right);
      printf("Deleted\n");
    }
    else if(nature=='l' || nature== 'L')
    {
        free(tmp->left);
        printf("Deleted\n");
    }
}
void Inorder(node** head)
{
    node* tmp=*head;
    if (tmp == NULL)
        return;
 
    // First recur on left child
    Inorder(&(tmp->left));
 
    // Then print the data of node
    tmp->mark=false;
    //printf("%d ", tmp->info);
    
    // Now recur on right child
    Inorder(&(tmp->right));
}
// void printPreorder(node* node)
// {
//     if (node == NULL)
//         return;
 
//     // First print data of node
//     printf("%d ", node->info);
 
//     // Then recur on left subtree
//     printPreorder(node->left);
 
//     // Now recur on right subtree
//     printPreorder(node->right);
// }
void main()
{
    printf("starting main\n");
    node* head=NULL;//(node*)malloc(sizeof(node));
    //printf("Enter the value of root: ");
    int root_val=1;
    //scanf("%d",&root_val);
    head=create(root_val);
    double start=clock();
    insert(&head,1,'L',2);
    double end=clock();
    printf("first insert successful\n");
    printf("Time taken %f\n",((end - start) / CLOCKS_PER_SEC)*(1000));
    start=clock();
    insert(&head,2,'r',4);
    end=clock();
    printf("Time taken %f\n",((end - start) / CLOCKS_PER_SEC)*(1000));
    printf("second insert successful\n");
    start=clock();
    insert(&head,1,'r',5);
    end=clock();
    printf("Time taken %f\n",((end - start) / CLOCKS_PER_SEC)*(1000));
    printf("second insert successful\n");
    start=clock();
    insert(&head,2,'l',3);
    end=clock();
    printf("Time taken %f\n",((end - start) / CLOCKS_PER_SEC)*(1000));
    printf("third insert successful\n");
    printf("Left child of root %d\n",(head)->left->info);
    //printf("HEAD IS %d\n",head->info);
    start=clock();
    insert(&head,5,'r',6);
    end=clock();
    printf("Time taken %f\n",((end - start) / CLOCKS_PER_SEC)*(1000));
    printf("fourth insert successful\n");
    start=clock();
    insert(&head,5,'l',7);
    end=clock();
    printf("Time taken %f\n",((end - start) / CLOCKS_PER_SEC)*(1000));
    printf("fifth insert successful\n");
    start=clock();
    delete(&head,5,'l');
    end=clock();
    printf("Time taken %f\n",((end - start) / CLOCKS_PER_SEC)*(1000));
    printf("Deletion successful\n");
    //printPreorder(head);
    //printInorder(&head);
}
