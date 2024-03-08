/* Given a linked list of 'N' nodes, which has nodes in alternating non-decreasing and non-increasing. 
   Sort the list in non-decreasing order.*/
#include <iostream>
#include <vector>
#include <algorithm>
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
Brute Frute Solution : Store all the elements in an array and sort them and then again put them back.
Step 1 : Iterate through the linked list and store each node in an array.
Step 2 : Sort the array once all the elements are stored.
Step 3 : Run a loop again and replace the current values of the nodes with the sorted values in the array.
Step 4 : Return the head of the linked list as we have not changed the head.

Time Complexity : O(N) + O(N logN) + O(N)  
Space Complexity : O(N) 
*/
Node * sortLLBrute(Node* head) {
    Node* temp = head;
    vector<int> answer;
    while(temp != NULL){
        answer.push_back(temp->data);
        temp = temp->next;
    }
    sort(answer.begin(), answer.end());

    temp = head;
    for(int i=0; i<answer.size(); i++){
        temp->data = answer[i];
        temp = temp->next;
    }
    return head;
}

/*
Optimal Solution : Implement Merge Sort in Linked list.
Step 1 : Write the base case that is if head is null or head's next is null.
Step 2 : Find the middle node(1st middle in case of even length) of the linked list and break it in two parts.
Step 3 : Call a recursive function for the lefthead and righthead of the linked list.
Step 4 : Write the merge function two merge two sorted linked list.

Time Complexity : O(N + N/2) log N  
N/2 is added because we are using some time to find the middle of the linked list.
Space Complexity : O(1) 
*/
Node* findMiddle(Node* head){ // Using Tortoise and Hair Algorithm with small tweak
    if(head == NULL || head->next == NULL) return head;
    Node* slow = head;
    //This is done because in case of even length linked list we want the first middle of the linked list.
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge2(Node* head1, Node* head2){
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

Node* merge_sortLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* middle = findMiddle(head); // Finding the middle of the linked list
    Node* leftHead = head, *rightHead = middle->next; // Pointing the heads to the correct position.
    middle->next = nullptr; // Breaking the linked list in two parts to pass to the recursive functions.

    leftHead = merge_sortLL(leftHead); // Recursive call on the left linked list.
    rightHead = merge_sortLL(rightHead); // Recursive call on the right linked list.

    return merge2(leftHead, rightHead); // Function to merge two sorted linked list.
}

int main (){

    vector<int> arr = {4,6,3,1,2};
    Node* head = Convert_Arr2LL(arr);

    Node* headBrute = sortLLBrute(head);
    Traverse_LL(headBrute);
    cout<<endl;

    vector<int> arr1 = {404,63,31,111,12};
    Node* new_head = Convert_Arr2LL(arr1);
    Node* headOptimal = merge_sortLL(new_head);
    Traverse_LL(headOptimal);

    return 0;
}