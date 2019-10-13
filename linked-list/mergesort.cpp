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
Node* getMid(Node* head){
    if(head==NULL||head->next==NULL)
        return head;
    Node *slow, *fast;
    slow=head; fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node *mergesort(Node *head){
    if(head==NULL||head->next==NULL)
        return head;

    Node *temp, *first, *second;
    
    //get mid and divide the list into two part
    first=head;
    temp=getMid(head);
    second=temp->next;
    temp->next=NULL;

    //recursive call to break till each list is of 1 element 
    first = mergesort(first);
    second = mergesort(second);

    //merge the two lists
    return merge(first, second);
}
int main(){
    Node *head2=NULL, *head1=NULL;
    cin>>head1>>head2;
    cout<<head1<<head2;
    // head1 = merge(head1, head2);
    
    head1=mergesort(head1);
    head2=mergesort(head2);
    cout<<head1<<head2;

}