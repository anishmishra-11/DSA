/*You are given a linked list containing 'n' nodes, where every node in the linked list contains two pointers:
(1) ‘next’ which points to the next node in the list
(2) ‘random’ which points to a random node in the list or 'null'.

Your task is to create a 'deep copy' of the given linked list and return its head.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* random;

    public:
    Node(int data, Node* next, Node* random){
        this->data = data;
        this->next = next;
        this->random = random;
    }

    public:
    Node(int data)
    {
      this->data = data;
      next = nullptr;
      random = nullptr;
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
Brute Frute Solution : Make a copy of nodes in a traversal and then again traverse to copy the links.
Step 1 : Iterate through the linked list and make a copy of the linked list and store it in hashmap.
Step 2 : Reinitialize the temp and this time update the links by using copynode.
Step 3 : Return the duplicate copy of the head of the original linked list.

Time Complexity : O(2N)   
Space Complexity : O(N) + O(N) 

1 O(N) in the space complexity is because we need to return a copy and we cannot avoid it.
*/
Node * clone_LLBrute(Node* head) {
    Node* temp = head;
    unordered_map<Node*, Node*> mpp;

    while(temp != NULL){
        Node* newNode = new Node(temp->data); // Creating a duplicate copy of the node.
        mpp[temp] = newNode; // Storing the node in the hashmap with the origianl node.
        temp = temp->next; // Moving to the next node.
    }

    temp = head; // Reinitialization of head

    while(temp != NULL){
        Node* copyNode = mpp[temp]; // Finding the duplicate of the head node to update the pointers.
        copyNode->next = temp->next;
        // copyNode->next = mpp[temp->next];
        // copyNode->random = mpp[temp->random];
        copyNode->random = temp->random;

        temp = temp->next; // Updating the temp to the next node.
    }
    return mpp[head];  // Returning the copy node of the original head of the linked list.
}

/*
Optimal Solution : Insert a copy of nodes in between nodes. Connect the random pointers and then the next pointers.
Step 1 : Iterate through the linked list and make a new node and connect them in between of two nodes.
Step 2 : Traverse again and connect the random pointers of the original linked list.
Step 3 : Return the duplicate copy of the head of the original linked list.

Time Complexity : O(N) + O(N) + O(N) ~ O(3N)   
Space Complexity : O(N) This will be for creating a new list.
*/
Node* clone_LLOptimal(Node* head){
    Node* temp = head;
	while (temp != NULL){
		Node* newNode = new Node(temp->data);
		newNode->next = temp->next;
		temp->next = newNode;

		temp = temp->next->next;
	}

	temp = head;
    while(temp != NULL) {
        if(temp->random != NULL)
            temp->next->random = temp->random->next;
		else temp->next->random = temp->random;
        temp = temp->next->next;
    }

	Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    temp = head;
    Node* fast;
    while(temp != NULL) {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

int main (){

    vector<int> arr = {1,2,4,6,7};
    Node* head = Convert_Arr2LL(arr);

    // Making some random connections
    head->random = head->next->next->next;
    head->next->random = head;
    head->next->next->random = NULL;
    head->next->next->next->random = head->next;

    Node* new_head = clone_LLBrute(head);
    Traverse_LL(new_head);
    cout<<endl;
    
    Node* new_head_Optimal = clone_LLBrute(head);
    Traverse_LL(new_head_Optimal);
    cout<<endl;
    return 0;
}