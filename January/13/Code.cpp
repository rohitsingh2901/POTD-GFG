

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


class Solution
{
public:
    // Helper function for recursive insertion sort
    void helper(struct Node *cur)
    {
        // Base case: if current node is NULL, return
        if (!cur)
            return;

        // Recursively sort the rest of the linked list
        helper(cur->next);

        // Store the data and the next node for later use
        int key = cur->data;
        Node *next = cur->next;

        // Traverse the sorted part of the list and insert the current node at the correct position
        while (next)
        {
            if (next->data < key)
            {
                // Swap values
                cur->data = next->data;
                cur = next;
                next = cur->next;
            }
            else
            {
                // Break if the correct position is found
                break;
            }
        }

        // Set the current node's data to the stored key value
        cur->data = key;

        // Set the next pointer to NULL to terminate the sorted linked list
        cur->next = NULL;
    }

    // Function to perform insertion sort on the linked list
    Node *insertionSort(struct Node *head_ref)
    {
        // Call the helper function to perform insertion sort
        helper(head_ref);

        // Return the head of the sorted linked list
        return head_ref;
    }
};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        Node *head = NULL;
        Node *temp = head;

        // Input elements to create the linked list
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        // Create an instance of the Solution class
        Solution ob;

        // Call the insertionSort function to sort the linked list
        head = ob.insertionSort(head);

        // Print the sorted linked list
        printList(head);

        cout << "\n";
    }
    return 0;
}
