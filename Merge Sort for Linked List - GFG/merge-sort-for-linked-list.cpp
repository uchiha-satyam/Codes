//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
    Node* merge(Node* head, int n)
    {
        if(head==NULL||n==1) return head;
        Node* org = head;
        int k = (n+1)/2;
        Node* n1 = head;
        while(--k) head = head->next;
        Node* n2 = (head) ? head->next : head;
        head->next = NULL;
        n1 = merge(n1,(n+1)/2);
        n2 = merge(n2,n/2);
        if((n1&&n2&&n1->data<n2->data)||(n1&&!n2))
        {
            org = n1;
            n1 = n1->next;
        }
        else
        {
            org = n2;
            n2 = n2->next;
        }
        head = org;
        while(n1||n2)
        {
            if((n1&&n2&&n1->data<n2->data)||(n1&&!n2))
            {
                head->next = n1;
                n1 = n1->next;
            }
            else
            {
                head->next = n2;
                n2 = n2->next;
            }
            head = head->next;
        }
        return org;
    }
    public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        int n = 0;
        Node* temp = head;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        Node* sorted = merge(head,n);
        return sorted;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends