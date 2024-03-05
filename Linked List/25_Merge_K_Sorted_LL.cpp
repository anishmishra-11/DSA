/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../../../MinGW/lib/gcc/mingw32/6.3.0/include/c++/bits/algorithmfwd.h"
using namespace std;

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
      next = nullptr;
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
Brute Frute Solution : Iterate over the all the linked list, store it in array and convert to LL after sorting it.
Step 1 : Iterate through the list of all the heads of the linked list.
Step 2 : Now iterate through each of the list and store the data in an array.
Step 3 : Sort the array and then convert it to a linked list.
Step 4 : Return the head of the new linked list.

Assumptions : 
Size of the given list is K.
Length of each linked list is N.
Time Complexity : O(N*K) + O(N*K)log(N*K) + O(N*K)
Space Complexity : O(M) + O(M)

*/
Node* merge_K_Sorted_LLBrute(vector<Node*>& lists){
    vector<int> array;
    for(int i=0; i<lists.size(); i++){
        Node* temp = lists[i];
        while(temp != NULL){
            array.push_back(temp->data);
            temp = temp->next;
        }
    }
    sort(array.begin(), array.end());
    Node* head = Convert_Arr2LL(array);
    return head;
}

/*
Better Solution: Merge two linked list once and use the merged linked list with next one to merge.
Step 1 : Use the first head of the list as the head 
Step 2 : Iterate from second head of the given list and merge the first two. Store it in head.
Step 3 : Write the merge function to merge two sorted linked list in-place.
Step 4 : Return the head of the final merged linked list.

Assuming that the length of each linked list is N.
Time Complexity : O(2N) + O(3N) + O(4N)
N + (2N + 3N + 4N) // Adding N 
N + 2N + 3N + .... + KN
N + (1 + 2 + 3 + 4 + .... + K)
Final TC : [N + (K . K+1) / 2] 
The time complexity is roughly in power of cubes near about N^3.
Space Complexity : O(1)
*/
Node* merge(Node* head1, Node* head2){
    if(head1 == NULL && head2 == NULL) return head1;

    Node* dummyNode = new Node(-1);
    Node* t1 = head1, *t2 = head2, *temp = dummyNode;

    while(t1 != NULL && t2 != NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }
    if(t1) temp->next = t1;
    if(t2) temp->next = t2;

    return dummyNode->next;    
}

Node* merge_K_Sorted_LLBetter(vector<Node*> lists){
    Node * head = lists[0];
    for(int i=1; i<lists.size(); i++){
        head = merge(head, lists[i]);
    }
    return head;
}

int main (){
    vector<Node*> lists;

    vector<int> arr1 = {1,9,19};
    Node* head1 = Convert_Arr2LL(arr1);
    lists.push_back(head1);

    vector<int> arr2 = {2,33,119};
    Node* head2 = Convert_Arr2LL(arr2);
    lists.push_back(head2);

    vector<int> arr3 = {4,5,90};
    Node* head3 = Convert_Arr2LL(arr3);
    lists.push_back(head3);

    Node* head = merge_K_Sorted_LLBetter(lists);
    Traverse_LL(head);
    

    return 0;
}