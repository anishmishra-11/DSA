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

//New Concepts start from here.
/*
Brute Frute Solution : Storing nodes of linked list with a timer.
Step 1 : Iterate through the linked list and store each node in a unordered map.
Step 2 : Before storing check if the node already exists in the map or not.
Step 3 : If found, return true which means there is a loop else return false.

Time Complexity : O(N*2*(1)) 2 is the number of map operations and 1 is for time complexity of map operation. 
Space Complexity : O(N) 
*/
int LengthOfLoopBrute(Node* head){
    unordered_map<Node*, int> m;
    Node* temp = head;
    int timer = 0;

    while (temp != NULL) {
        if (m.find(temp) != m.end()) {
            return timer - m[temp] + 1;
        }
        timer++;
        m[temp] = timer; 
        temp = temp->next;
    }

    return 0; 
}

int main()
{
    vector<int> arr = {9,19,1,29,8};
    Node* head = Convert_Arr2LL(arr);

    head->next->next = head->next; // Making a loop for check

    int answer = detectLoopBrute(head);
    cout<<answer<<endl;

             
  return 0;
}