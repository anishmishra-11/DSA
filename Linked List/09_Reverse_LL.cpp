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

//New Concepts start from here.
/*
Brute Frute Solution : Traversting two times and using the stack data structure.
Step 1 : Write the edge case when head is null or if there is a single element in the linked list.
Step 2 : First, we have to traverse once and store each data in stack.
Step 3 : Then by again traversing we have to pop the data from stack and replace it in the linked list.

Time Complexity : O(2N)
Space Complexity : O(N)
*/
Node* reverseListBrute(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

/*
Better Solution : Changing the links using a prev and front pointer.
Step 1 : Write the edge case when head is null or if there is a single element in the linked list.
Step 2 : Initialize two pointers prev and front and store null in it.
Step 3 : Run a loop till temp goes to null and update the pointers as per the requirement.
Step 4 : Return the new head carefully which will be prev pointer.

Time Complexity : O(N)
Space Complexity : O(1)
*/
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

/*
Better Solution : Recursive Solution
Step 1 : Write the base case i.e. head is null or if there is a single element in the linked list.
Step 2 : Call the recrusive function.
Step 3 : Solve it for 2 nodes by switching the links.
Step 4 : Return the new head carefully.

Time Complexity : O(N)
Space Complexity : O(N) this is recursive stack space.
*/
Node* reverseListRecursive(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseListRecursive(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    vector<int> arr = {12, 1, 9, 8, 7, 1, 5};
    Node* head = Convert_Arr2LL(arr);

    head = reverseListBrute(head);
    Traverse_LL(head);
    cout<<endl;

    head = reverseList(head);
    Traverse_LL(head);
    cout<<endl;

    head = reverseListRecursive(head);
    Traverse_LL(head);
                 
  return 0;
}