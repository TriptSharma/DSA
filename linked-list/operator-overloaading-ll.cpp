#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* insertAtBack(int data, Node* &head){
    if(head==NULL){
        head=new Node(data);
        return head;
    }
    Node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next = new Node(data);
    return head;
}

istream& operator>> (istream &is, Node* &head){
    int data;
    is>>data;
    while(data!=-1){
        insertAtBack(data, head);
        is>>data;
    }
}
ostream& operator<<(ostream &os, Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return os;
}

int main(){
    Node *head = NULL;
    cin>>head;
    cout<<head;
}