//Floyd's cycle is an algorithm to check if the linked list contains cycle or not
#include<iostream>
using namespace std;
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

bool detectCycle(Node *head, Node*& slow, Node*& fast){
    // we use runner technique; if the slow and fast runners meet at any point loop exists. But if the fast ptr reaches NULL, no loop exists.
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
            return true;
    }
    return false;
}
void deCyclize(Node*&head){
    //Floyd says if we use runner technique and if the loop exists; the distance between the loop starting and the head is same as the distance btw loop start and node at which both slow and fast meet. Mathematical expalination at:
    //https://stackoverflow.com/questions/2936213/explain-how-finding-cycle-start-node-in-cycle-linked-list-work (answer by OldMonk)
    Node *slow, *fast;
    slow = fast = head;
    
    //find loop starting via floyd's theorem
    if(detectCycle(head, slow, fast)){
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }

        //de-cyclize
        while(fast->next!=slow)
            fast=fast->next;
        fast->next=NULL;    //decyclized
    }
    else
        cout<<"Linked List doesn't have a cycle"<<endl;
}
int main(){
    Node *head2=NULL, *head1=NULL;
    cin>>head1>>head2;
    cout<<head1<<head2;

    deCyclize(head1);
    deCyclize(head2);

    cout<<head1<<head2;

}