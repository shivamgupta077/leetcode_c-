#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }
};

// Returns true if there exists loop in a linked list
bool detectLoop(Node *head){

    if(head == NULL){
        return false;
    }

    Node* slow = head,*fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast ->next ->next;
        if(slow == fast)
            return true;
    }
    return NULL;

}

int main(){

    Node* head = new Node(1);
    Node* temp1 = new Node(2);
    head->next = temp1;
    Node* temp2 = new Node(3);
    temp1->next = temp2;
    Node* temp3 = new Node(4);
    temp2->next = temp3;
    temp3->next = temp1;

    /*
        Link List Created is 1 -> 2 -> 3 -> 4 -> 2.  Loop between 2 and 4
    */

    cout<<detectLoop(head)<<endl;

}
