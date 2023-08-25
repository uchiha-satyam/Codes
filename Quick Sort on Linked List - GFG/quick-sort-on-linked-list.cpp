//{ Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}
// } Driver Code Ends

#include <bits/stdc++.h>
 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

int partition(vector<node*>& vec, int low, int high)
{
    int l = low, r = high;
    for(int i=l; i<r; i++)
    {
        if(vec[i]->data>=vec[r]->data) continue;
        swap(vec[i],vec[l]);
        l++;
    }
    swap(vec[r],vec[l]);
    return l;
}

void sort(vector<node*>& vec, int low, int high)
{
    if(low>=high) return;
    int pivot = partition(vec,low,high);
    sort(vec,low,pivot-1);
    sort(vec,pivot+1,high);
}

//you have to complete this function
void quickSort(struct node **headRef) {
    vector<node*> vec;
    while(*headRef)
    {
        vec.push_back(*headRef);
        *headRef = (*headRef)->next;
    }
    sort(vec,0,vec.size()-1);
    for(int i=0; i<vec.size()-1; i++) vec[i]->next = vec[i+1];
    vec.back()->next = NULL;
    *headRef = vec[0];
}