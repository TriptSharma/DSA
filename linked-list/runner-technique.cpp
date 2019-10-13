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
    return is;
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
Node* getMid(Node* head){
    int count=0;
    if(head==NULL||head->next==NULL){
        cout<<"Pos: "<<count<<endl;
        return head;
    }
    Node *slow, *fast;
    slow=fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        count++;
    }
    cout<<"Pos: "<<count<<endl;
    return slow;
}
Node* getKthNodeFromBack(int k, Node* head){
    Node* slow=head, *fast=head;
    while(fast!=NULL && k--)
        fast=fast->next;
    if(k>=0) return NULL;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
int main(){
    Node *rev=NULL, *head = NULL;
    cin>>head;
    // cout<<head;

    cout<<"data at mid: "<<getMid(head)->data<<endl;
    if(getKthNodeFromBack(5, head)==NULL)
        cout<<"not found"<<endl;
    else
        cout<<"data at kth node from back : "<<getKthNodeFromBack(4, head)->data<<endl;
}