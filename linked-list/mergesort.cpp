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
Node *merge(Node *a, Node*b){
    //merge two SORTED linked lists
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    
    Node *c;
    if(a->data<b->data){
        c=a;
        c->next = merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a, b->next);
    }
    return c;
}
int main(){
    Node *head2, *head1;
    cin>>head1>>head2;
    cout<<head1<<head2;
    head1 = merge(head1, head2);
    cout<<head1;

}