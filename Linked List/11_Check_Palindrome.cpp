#include <iostream>
#include <vector>
#include<stack>
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

Node* reverseList(Node *head){
    if(head == NULL || head->next == NULL) return head;
    Node* prev = NULL, *front = NULL;
    Node* temp = head;

    while(temp != NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

//New Concepts start from here.
/*
Brute Frute Solution : Traversting two times and using the stack data structure.
Step 1 : Write the edge case when head is null or if there is a single element in the linked list.
Step 2 : First, we have to traverse once and store each data in stack.
Step 3 : Traverse again and compare the stack's top data and nodes data in the linked list.
Step 4 : If at any point the values does not match then return Fasle else return True.

Time Complexity : O(2N)
Space Complexity : O(N)
*/
bool isPalindromeBrute(Node *head){
    if(head == NULL || head->next == NULL) return true;
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){ // Storing the data in the stack.
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head; // Reinitialization of temp
    while(temp != NULL){
        if(temp->data != st.top()) return false; // If does not match then return false straightaway.
        temp = temp->next;
        st.pop();
    }
    return true;
}

/*
Better Solution : By reversing the second half of the linked list.
Step 1 : Write the base case i.e. head is null or if there is a single element in the linked list.
Step 2 : Find the middle node of the linked list, In case of even length find the M1 node.
Step 3 : Reverse the second half of the linked list starting from the middle (‘slow->next’) node.
Step 4 : Match the first half of the linked list with the second half of the linked list and return T/F.

Time Complexity : O(3N/2) ~ O(2N) 
Space Complexity : O(1)
*/
bool isPalindrome(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* slow = head, *fast = head;
    while(fast->next != NULL && fast->next->next != NULL){ // Finding the middle of the linked list.
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseList(slow->next); // Reversing the second half of the linked list.

    Node* first = head, *second = newHead; // Pointeres to compare the two halves of the linked list.

    while(second != NULL){ // Traversing through linked list to compare data.
        if(first->data != second->data) return false;
        second = second->next;
        first = first->next;
    }
    return true;
}

int main()
{
    vector<int> arr = {12, 11, 0, 1, 12};
    Node* head = Convert_Arr2LL(arr);

    bool answer = isPalindromeBrute(head);
    cout<<answer<<endl;

    answer = isPalindrome(head);
    cout<<answer<<endl;
                 
  return 0;
}