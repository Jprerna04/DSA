#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node(){
        cout<<"Node with value: "<<this->data<<" deleted"<<endl;
    }
};

void printLL(Node* &head){
    Node* temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int findlen(Node* &head){
    Node* temp=head;
    int len=0;
    while (temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

//INSERT AT HEAD
void insertAtHead(Node* &head, Node* &tail, int data){
    //LL is empty
    if (head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    //LL is not empty
    Node* newNode=new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}


//INSERT AT TAIL
void insertAtTail(Node* &head, Node* &tail, int data){
    //LL is empty
    if (head==NULL){
        Node* newNode= new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    //LL is not empty
    else{
        Node* newNode=new Node(data);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}


//insert at position

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    //LL is empty
    if (head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    //LL is not empty
    else{

        if (position==1){
            insertAtHead(head,tail,data);
            return;
        }

        int len=findlen(head);
        if(position==len){
            insertAtTail(head,tail,data);
            return;
        }


        int i=1;
        Node* prev=head;
        while (i<position-1){
            prev=prev->next;
            i++;
        }
        Node* curr=prev->next;
        Node* newNode=new Node(data);
        prev->next=newNode;
        newNode->prev=prev;

        curr->prev=newNode;
        newNode->next=curr;
    }
}


//DELETE 

void deleteAtPosition(Node* &head, Node* &tail, int position){
    //WHEN LL IS EMPTY
    if (head==NULL){
        cout<<"LL is empty"<<endl;
    }

    //WHEN ONLY ONE NODE IS PRESENT
    if (head->next==NULL){
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }

    if (position==1){
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }

    int len=findlen(head);

    if (position>len){
        cout<<"INVALID DIGIT";
    }

    if (position==len){
        Node* temp=tail;
        tail=tail->prev;
        temp->prev=NULL;
        tail->next=NULL;
        delete temp;
        return;
    }

    //MIDDLE DELETE
    int i=1;
    Node* left=head;
    while (i<position-1){
        left=left->next;
        i++;
    }
    Node* curr=left->next;
    Node* right=curr->next;

    left->next=right;
    right->prev=left;

    curr->next=NULL;
    curr->prev=NULL;

    delete curr;
}

int main(){
    Node* n1=new Node(10);
    Node* n2=new Node(20);
    Node* n3=new Node(30);
    Node* n4=new Node(40);
    Node* head=n1;
    Node* tail=n4;

    n1->next=n2;
    n2->prev=n1;

    n2->next=n3;
    n3->prev=n2;

    n3->next=n4;
    n4->prev=n3;

    printLL(n1);

    cout<<endl;

    // insertAtPosition(head,tail,100,4);

    // printLL(head);

    // cout<<endl;

    deleteAtPosition(head,tail,4);

    printLL(head);

}