/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../../../MinGW/lib/gcc/mingw32/6.3.0/include/c++/bits/algorithmfwd.h"
#include <queue>
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

Node* merge_K_Sorted_LLBetter(vector<Node*>& lists){
    Node * head = lists[0];
    for(int i=1; i<lists.size(); i++){
        head = merge(head, lists[i]);
    }
    return head;
}

/*
Optimal Solution: Use Min-Heap i.e. priority Queue to store the nodes and then doing the comparison.
Step 1 : Store all the heads of the given list in the PQ. Also, Create a dummy node call it as temp.
Step 2 : Take the minimum node out from the PQ and attach it to the next of the dummy Node.
Step 3 : Store the node's next node in the priority to continue with the comparison.
Step 4 : Before storing the next node make sure it is not null.
Step 5 : Do this untill the priority queue becomes empty. 
Step 6 : Return the head i.e. dummyNode's next.

Time Complexity : O(K log K) + N * K logK 
Space Complexity : O(K)

N can be the longest length of the the given linked lists.
K is the size of the priority queue.

The time complexity is somewhere near about N^2 * logN which is better than the previous solution.
*/
Node* merge_K_Sorted_LLOptimal(vector<Node*>& lists){
    // Below is the line for declaration of Priority Queue, used greater comparsion function to ensure a min heap.
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;

    for(int i=0; i<lists.size(); i++){ // Adding all the heads of the lists to the priority queue
        pq.push({lists[i]->data, lists[i]});
    }
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(!pq.empty()){ // Ensuring that all the nodes are added once to the priority queue.
        pair<int, Node*> pair = pq.top(); // Taking the minimum out of the PQ.
        temp->next = pair.second; // Pointing the next of the temp to the next least minimum node.
        pq.pop(); // Removing it from the priority queue.

        // storing the next node in the PQ after checking whether it is null or not.
        if(pair.second->next) pq.push({pair.second->next->data, pair.second->next}); 

        temp = temp->next; // Moving temp to the next node of sorted linked list.
    }
    return dummyNode->next;
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

    Node* headBrute = merge_K_Sorted_LLBrute(lists);
    Traverse_LL(headBrute);
    cout<<endl;

    Node* headBetter = merge_K_Sorted_LLBetter(lists);
    Traverse_LL(headBetter);
    cout<<endl;

/*  Since we have used the same nodes to sort the linked lists so optimal function is not executing that's why
    it's output is not showing while all three functions are called. You have to reinitialize lists as a 
    collection of multiple head's of different linked list.*/

    Node* headOptimal = merge_K_Sorted_LLOptimal(lists);
    Traverse_LL(headOptimal);    

    return 0;
}