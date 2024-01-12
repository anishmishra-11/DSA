/* NOTES
A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. 
Better than the array data structure in cases where we don't have fixed size from start.

In array not possible to add a element after the array is full, but this is not the case in linked list.

Understanding the difference between Node and Node*: 
A node refers to the structure that contains data and the pointer to the next node. 
In contrast, Node* (Node pointer) specifically denotes a pointer variable that stores the address of the Node 
it is pointing to.


Types of Linked Lists : 
1. Singly-linked list: linked list in which each node points to the next node and the last node points to null.

2. Doubly-linked list : linked list in which each node has two pointers, p and n, such that p points to 
the previous node and n points to the next node; the last node's n pointer points to null.

3. Circular-linked list: linked list in which each node points to the next node and the last node points 
back to the first node.

4. Circular-Doubly-linked list : 

*/

#include <iostream>
#include <vector>
using namespace std;

/* Declaration of Linked List Node. It is the most basic part to store the data and the pointer to the next 
data point. */
class Node {
    public:
    int data;
    Node * next;

    public:
    Node(int data, Node * next){
        this->data = data;
        this->next = next;
    }

    public:
    Node(int data)
    {
      this->data = data;
      next = NULL;
    }
};

/* This Function is used to convert a given vector array to a linked list. 

Step 1 : store the first element as the starting node and point its next to null.
Step 2 : create a mover pointer to store the locatin of the first element. 
Step 3 : Iterate over the array and create a temp node and update the pointers through move and temp->next.
*/

Node * Convert_Arr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    //started from 1 because 0th index element was already included.
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}  


/* This function is used to traverse through a linked list. 

Step 1 : Run a loop from the head pointer till the temp pointer points towards null. 
*/

void Traverse_LL(Node* head){

    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<< " ";
        temp = temp->next;
    }  
}

/* This function is used to find the length of a linked list. 

Step 1 : Run a loop from the head pointer till the temp pointer points towards null. 
Step 2 : Increment count in each iteration.
*/

void Length_LL(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr)
    {
        count++;
        temp = temp->next;
    }  
    cout<<"Length of the Linked List : "<<count;
}

/* This function is used to find if a elment is present in a linked list. 

Step 1 : Run a loop from the head pointer till the temp pointer points towards null. 
Step 2 : Match the data present at each iteration if found return true.
Step 3 : Return false at the end of the loop which means the element is not found.
*/

bool Check_if_present(Node* head, int number){
    Node* temp = head;
    while(temp != nullptr)
    {
        if (temp->data == number)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;  
}

int main()
{
    vector<int> arr = {12,1,2,3,5};

    Node *y = new Node(arr[0],nullptr);

    cout<<y->data<<endl;
    cout<<y<<endl;  

    Node *x = new Node(arr[1],nullptr);
    cout<<x->data<<endl;
    cout<<x<<endl;    

    Node* head = Convert_Arr2LL(arr);
    cout<<head->data;

    // cout<<"\nTraversal of LL\n";
    // Traverse_LL(head); 
    // cout<<endl;

    // Length_LL(head);
    // cout<<endl;

    // bool answer = Check_if_present(head, 5);
    // cout<<answer<<endl;
    
    // bool value = Check_if_present(head, 9);
    // cout<<value<<endl;


  return 0;
}