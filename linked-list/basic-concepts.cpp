#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node* createNode(int data=0){
    Node *head = new Node;
    head->data=data;
    head->next = NULL;
    return head;
}
Node *insertAtHead(int data, Node* &head){
    //here we pass REFERENCE TO POINTER because we want to modify the pointer rather than the object contained by the pointer. We do so by adding & to * ptr.
    Node *temp = createNode(data);
    if (head==NULL)
        return temp;
    temp->next = head;
    head = temp;
    return head;
}
Node *insertAtEnd(int data, Node* head){
    Node *end = createNode(data);
    Node *temp = head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next = end;
    return head;
}
Node *insertInMiddle(int data, Node* head, int pos){
    //pos = required pos starting from 0
    Node *n = createNode(data);
    Node *temp = head;
    int currpos=0;
    while(currpos!=pos-1){
        temp=temp->next;
        currpos++;
    }
    n->next = temp->next;
    temp->next = n;
    return head;
}


//DELETION FUNCTIONS
Node* deletionAtHead(Node * &head){
    Node* temp =head;
    head = head->next;
    delete temp;
    return head;
}
Node* deletionAtEnd(Node *head){
    Node *dummy, *temp =head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    dummy=temp->next;
    temp->next =NULL;
    delete dummy;
    return head;
}
Node* deletionInMiddle(int pos, Node* head){
    int currpos=0;
    Node *dummy, *temp = head;
    while(currpos!=pos-1){
        temp=temp->next;
        currpos++;
    }
    dummy = temp->next;
    temp->next = dummy->next;
    delete dummy;
}

//search
int searchRecursive(int data, int startpos, Node* head){
    if(head==NULL)
        return -1;
    if(data==head->data)
        return  startpos;
    searchRecursive(data, startpos+1, head->next);
}
int searchIterative(int data, Node * temp){
    int curpos = 0;
    while(temp!=NULL){
        if(temp->data==data)
            return curpos;
        temp=temp->next;
        curpos++;
    }
    return -1;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    //creation
    Node* head = createNode();
    // print(head);
    
    //insertion
    insertAtEnd(15, head);
    // print(head);
    insertAtHead(1, head);
    // print(head);
    insertInMiddle(23, head, 1);
    insertInMiddle(2, head, 1);
    insertInMiddle(5, head, 4);
    print(head);

    //deletion
    deletionAtEnd(head);
    // print(head);
    deletionAtHead(head);
    // print(head);
    //deletionInMiddle(2, head);
    print(head);

    //search
    cout<<searchRecursive(23, 0, head)<<endl;
    cout<<searchRecursive(2, 0, head)<<endl;
    cout<<searchIterative(23, head)<<endl;
    cout<<searchIterative(15, head)<<endl;
}