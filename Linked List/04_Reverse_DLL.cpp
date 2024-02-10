#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data, Node* next, Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }

    public:
    Node(int data)
    {
      this->data = data;
      next = nullptr;
      back = nullptr;
    }
};

void Traverse_LL(Node* head){

    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<< " ";
        temp = temp->next;
    }  
}

Node* Convert_Arr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i],nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;    
}  

//New Concepts start from here.
/*
Brute Frute Solution : By changing the values inside the nodes.

Step 1 : We have to use a stack data structure to store the data of the linked list.
Step 2 : First, we have to traverse to nullptr of the linked list and keep pushing the data in stack.
Step 3 : We will run a loop again and this time we will pop the data from the stack and replace in the list.

Why this works ? This solution works because stacks work on the basis of last in first out manner
and the last data of the stack gets stored on the top of the linked list. Also, the first data will be 
stored at the last in the stack.

Time Complexity : O(2n)
Space Complexity : O(n)
*/
Node* ReverseDllBrute(Node* head){
    stack<int> st;

    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* temp = head;

    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

/*
Optimal Solution : By switching the links of prev node and the front node in the linked list.

Step 1 : Write the edge cases that if DLL has only 1 or no elements.
Step 2 : Store the prev of the head and Run a loop till temp becomes null.
Step 3 : We have to swap the links using a single variable to store prev node.
Step 4 : The swapping will be same as of swap of 2 numbers using a third variable.
Step 5 : For Swap : temp = a, a = b, and b = a. This same logic is used here to swap lihks.
Step 6 : Carefully move to the next node by using temp.back not temp.next.
Step 7 : Now return the new head of the DLL which is prev's back.

Time Complexity : O(n)
Space Complexity : O(1)
*/
Node* ReverseDll(Node* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* prev = NULL;
    Node* temp = head;

    while(temp != NULL){ //Below 3 lines are used to swap the links by using a 3rd variable.
        prev = temp->back; //We have stored the previous node.
        temp->back = temp->next; //We are changing the temp's back with temp's next
        temp->next = prev; //We are changing temp's next to prev.

        temp = temp->back; //Since we have to move forward in the linked list but links have been swithced, 
        //so, we are using back to move ahead in the linked list. Try with one or two cases to understand better.
    }
    
    return prev->back; //The previous node will be on the 2nd last node when temp will be null.
    //That's why we have to return the head carefully
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head = Convert_Arr2DLL(arr);

    head = ReverseDllBrute(head);
    Traverse_LL(head); //This prints the reversed DLL.
    cout<<endl;

    head = ReverseDll(head);
    Traverse_LL(head); //This prints the reverse of reversed DLL i.e. the original Linked list.
    cout<<endl;

    return 0;
}