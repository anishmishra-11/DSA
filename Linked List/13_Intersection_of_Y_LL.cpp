#include <iostream>
#include <vector>
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

int length(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr)
    {
        count++;
        temp = temp->next;
    }  
    return count;
}

//New Concepts start from here.
/*
Brute Frute Solution : Comparing one node of a linked list with all the other nodes of second linked list.
Step 1 : Keep any one of the list to check its node present in the other list.
Step 2 : Iterate through the other list, starting from the head of the other linked list.
Step 3 : Check if the both nodes are the same. If yes, we got our first intersection node else continue.
Step 4 : If any node does not matches then return null.

Time Complexity : O(N1 * N2)
Space Complexity : O(1)
*/
Node* findIntersectionBrute(Node* head1, Node* head2){
    Node* temp1 = head1;
    while(temp1 != NULL){
        Node* temp2 = head2;
        while(temp2 != NULL){
            if(temp1 == temp2) return temp1; //if both nodes are same
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return NULL;
}

/*
Better Solution : Using length and starting from a same point.
Step 1 : We have to find the length of both of the linked list.
Step 2 : And take a headstart by d i.e the difference between length of the linked lists.
Step 3 : Now start comparing the nodes and if a common node is found then return node else return NULL.

Time Complexity : O(N1) + O(N2) + O(N2 - N1) + O(N1) ~ O(N1 + 2N2)
Space Complexity : O(1)
*/
Node* collisonPoint(Node* smallHead, Node* largeHead, int d){
    while(d){
        d--;
        largeHead = largeHead->next;
    }
    while(smallHead != NULL){
        if(smallHead == largeHead) return smallHead;
        smallHead = smallHead->next;
        largeHead = largeHead->next;
    }
    return NULL;
}

Node* findIntersectionBetter(Node* firstHead, Node* secondHead){
    Node* temp1 = firstHead, *temp2 = secondHead;
    int n1, n2;

    n1 = length(firstHead);
    n2 = length(secondHead);

    if(n1 < n2) return collisonPoint(firstHead, secondHead, n2-n1);// Passing (small LL, Large LL, difference)
    else return collisonPoint(secondHead, firstHead, n1-n2);
}

/*
Optimal Solution : Two pointer technique and pointing to each other head before null.
Step 1 : Take two dummy nodes for each list. Point each to the head of the lists.
Step 2 : Iterate over them. If anyone becomes null, point them to the head of the opposite linked list.
Step 3 : Continue iterating until they collide, they will at one point of time either on a node or null.
Step 4 : Write the condition for while loop for case when both the linked list represent a same one.

Time Complexity : O(N1 + N2) 
Space Complexity : O(1)
*/
Node* findIntersectionOptimal(Node* firstHead, Node* secondHead){
    Node* temp1 = firstHead, *temp2 = secondHead;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;

        if(temp1->next == NULL) temp1 = secondHead;
        if(temp2->next == NULL) temp2 = firstHead;
    }
    return temp1;
}

int main()
{
    vector<int> arr = {9,1,19,9,8};
    Node* head1 = Convert_Arr2LL(arr);
    
    vector<int> arr1 = {11,14,19};
    Node* head2 = Convert_Arr2LL(arr1);

    
  return 0;
}