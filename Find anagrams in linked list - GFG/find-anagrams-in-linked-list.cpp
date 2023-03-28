//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
    bool check(vector<int>& data)
    {
        for(auto& x : data)
        {
            if(x!=0) return false;
        }
        return true;
    }
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<int> data(26,0);
        vector<Node*> ans;
        for(auto& x : s)
        {
            data[x-'a']--;
        }
        int n = s.length();
        Node *h = head, *t = head;
        int c = 1;
        while(c<n)
        {
            data[t->data-'a']++;
            t = t->next;
            c++;
        }
        do
        {
            data[t->data-'a']++;
            if(check(data))
            {
                Node* temp = t->next;
                t->next = NULL;
                ans.push_back(h);
                h = temp;
                t = temp;
                for(auto& x : data)
                {
                    x=0;
                }
                for(auto& x : s)
                {
                    data[x-'a']--;
                }
                c = 1;
                while(c<n&&t)
                {
                    data[t->data-'a']++;
                    t = t->next;
                    c++;
                }
                continue;
            }
            data[h->data-'a']--;
            h = h->next;
            t = t->next;
        }while(t);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends