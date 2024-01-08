
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

class Solution
{
    public:
    // Function to reverse a linked list
    Node* reverse(Node* head){
        Node* nextnode = head;
        Node* currnode = head;
        Node* prevnode = NULL;

        // Reversing the linked list iteratively
        while (nextnode != NULL) {
            nextnode = currnode->next;
            currnode->next = prevnode;
            prevnode = currnode;
            currnode = nextnode;
        }
        head = prevnode; // Assigning the new head after reversal
        return head;
    }

    // Function to merge two linked lists in non-increasing order and reverse the merged list
    struct Node* mergeResult(struct Node *node1, struct Node *node2){
        // Pointers for traversing the linked lists
        Node* p1 = node1;
        Node* p2 = node2;

        // Creating a dummy node to hold the merged list
        Node* dummy = new Node;
        Node* ans = dummy;

        // Merging the lists in non-increasing order
        while (p1 && p2){
            if (p1->data > p2->data){
                ans->next = p1;
                p1 = p1->next;
            }
            else if (p1->data <= p2->data){
                ans->next = p2;
                p2 = p2->next;
            }
            ans = ans->next;
        }

        // Appending remaining elements from list 1, if any
        while (p1 != NULL){
            ans->next = p1;
            p1 = p1->next;
            ans = ans->next;
        }

        // Appending remaining elements from list 2, if any
        while (p2 != NULL){
            ans->next = p2;
            p2 = p2->next;
            ans = ans->next;
        }

        // Get the merged list's head excluding the dummy node
        Node* merged = dummy->next;
        delete dummy; // Deleting the dummy node as it's no longer needed

        // Return the merged list in reverse order
        return reverse(merged);
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}
