/* You are given a linked list containing 'n' 'head' nodes, where every node in the linked list. 
contains two pointers:

(1) ‘next’ which points to the next node in the list.
(2) ‘child’ pointer to a linked list where the current node is the head.

Each of these child linked lists is in sorted order and connected by 'child' pointer.
Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../../../MinGW/lib/gcc/mingw32/6.3.0/include/c++/bits/algorithmfwd.h"
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* child;

    public:
    Node(int data, Node * next, Node* child){
        this->data = data;
        this->next = next;
        this->child = child;
    }

    public:
    Node(int data)
    {
      this->data = data;
      next = nullptr;
      child = nullptr;
    }
};

Node* Convert_Arr2LL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}  

void Traverse_LL(Node* head){

    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<< " ";
        temp = temp->next;
    }  
}

//New Concepts start from here. 
/*
Brute Frute Solution : Iterate over the linked list using 2 loops and convert to LL after sorting it.
Step 1 : Iterate through the linked list using temp.
Step 2 : Now iterate over the child pointers of the current node in the linked list and push it into the array.
Step 3 : Sort the array and then convert it to a linked list in form of child pointers.
Step 4 : Return the head of the new linked list.

Length of the linked list : N
Maximum length of linked list in form of child pointers : M
Time Complexity : 2 * O(N*M) + O(N*M) log(N*M)
Space Complexity : 2 * O(N*M)

In space complexity 1 (N*M) is for storing it in array and the other is for creating a new linked list
of size N*M.
*/
Node* merge_K_Sorted_LLBrute(Node* head){
    
}

/*
Optimal Solution: Make comparisons over the two linked list and do link changes.
Step 1 : Place a t1 on head1 and t2 at head2. Create a dummy node call it as temp.
Step 2 : Do comparisons on value of the both the linked list.
Step 3 : If t1's value is less than point temp's next to t1 and move t1 by one place.
Step 4 : If t2's value is less than point temp's next to t2 and move t2 by one place.
Step 5 : Move temp to its next for updating the links ahead.
Step 6 : Check if t1 or t2 is left or not and attach it to the temp's next.
Step 7 : Return the head i.e. dummyNode's next.

Time Complexity : O(N1 + N2) 
Space Complexity : O(1)
*/
Node* merge_K_Sorted_LLOptimal(Node* head){
        
}

int main (){
    vector<int> arr = {1,9,19,28};
    

    return 0;
}