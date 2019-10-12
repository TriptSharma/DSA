#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* insertAtBack(int data, Node* &head){
    Node *temp=head, *t = new Node;
    t->data= data;
    while(temp->next!=NULL) temp=temp->next;
    temp->next = t;
    return head;
}

void buildLinkedList(Node* &head){
    int data;
    cin>>data;
    while(data==-1){
        insertAtBack(data, head);
        cin>>data;
    }
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
    Node *head = NULL;
    buildLinkedList(head);
    print(head);
}