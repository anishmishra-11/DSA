/* You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.
Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', 
then the last group of nodes should remain unchanged.*/
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
Brute Frute Solution : Iterate over both the linked list, store it in an array, sort it and convert to LL.
Step 1 : Iterate through the first linked list and push it into the array.
Step 2 : Now iterate over the second linked list and push it into the array.
Step 3 : Sort the array and then convert it to a linked list.
Step 4 : Return the head of the new linked list.

Time Complexity : O(N1) + O(N2)+ O(N1+N2) log(N1 + N2) + O(N1 + N2) 
Space Complexity : O(N1 + N2) + O(N1 + N2)

One (N1 + N2) is for sorting the vector while the other O(N1 + N2) is for conversion to LL.
*/
Node* merge_sorted_LLBrute(Node* head1, Node* head2){
    // If both the list contain 0 elements then vector will have 0 elements and no sorting will be done.
    if(head1 == NULL && head2 == NULL) return head1;

    vector<int> answer;
    Node* temp = head1;

    while(temp != NULL){
        answer.push_back(temp->data);
        temp = temp->next;
    }

    temp = head2; // Reinitialization of temp to head2.
    while(temp != NULL){
        answer.push_back(temp->data);
        temp = temp->next;
    }

    sort(answer.begin(), answer.end()); // Sorting the elements in answer vector.

    Node* head = Convert_Arr2LL(answer); // Converting the vector to linked list.

    return head;
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
Node* merge_sorted_LLOptimal(Node* head1, Node* head2){
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

int main (){
    vector<int> arr = {1,9,19,28};
    Node* head1 = Convert_Arr2LL(arr);
    
    vector<int> arr1 = {11,14,19};
    Node* head2 = Convert_Arr2LL(arr1);

    Node* new_Linked_List = merge_sorted_LLBrute(head1, head2);
    Traverse_LL(new_Linked_List);
    cout<<endl;

    new_Linked_List = merge_sorted_LLOptimal(head1,head2);
    Traverse_LL(new_Linked_List);

    return 0;
}