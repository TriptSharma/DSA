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
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head = createNode();
    print(head);
    insertAtEnd(15, head);
    print(head);
    insertAtHead(1, head);
    print(head);
    insertInMiddle(23, head, 1);
    print(head);
}