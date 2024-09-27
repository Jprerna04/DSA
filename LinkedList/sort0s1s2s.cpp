#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node() {
        this->data = 0;
        this->next = NULL;
    }

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(node* head){
    node* temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void sort0s1s2s(node* &head){
    node* temp=head;
    int zero=0;
    int one=0;
    int two=0;

    while (temp!=NULL){
        if (temp->data==0){
            zero++;
        }
        else if (temp->data==1){
            one++;
        }
        else if (temp->data==2){
            two++;
        }
        temp=temp->next;
    }

    temp=head;
    while (zero--){
        temp->data=0;
        temp=temp->next;
    }
    while (one--){
        temp->data=1;
        temp=temp->next;
    }
    while (two--){
        temp->data=2;
        temp=temp->next;
    }

}






node* sort2(node* &head){
    if (head==NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    if (head->next==NULL){
        cout<<"Only one node"<<endl;
        return head;
    }

    //create 3 dummy node
    node* zeroHead = new node(-1);
    node* zeroTail =  zeroHead;

    node* oneHead = new node(-1);
    node* oneTail =  oneHead;

    node* twoHead = new node(-1);
    node* twoTail =  twoHead;

    //add nums from head to dummy node

    node* temp=head;

    while (temp!=NULL){
        if (temp->data==0){
        //isolate from main node
        node* curr=temp;
        temp=temp->next;
        curr->next=NULL;

        //append in zeronode
        zeroTail->next=curr;
        zeroTail=curr;
        }

        else if (temp->data==1){
        //isolate from main node
        node* curr=temp;
        temp=temp->next;
        curr->next=NULL;

        //append in zeronode
        oneTail->next=curr;
        oneTail=curr;
        }

        else if (temp->data==2){
        //isolate from main node
        node* curr=temp;
        temp=temp->next;
        curr->next=NULL;

        //append in zeronode
        twoTail->next=curr;
        twoTail=curr;
        }
    }

    //3 nodes mil chuki hain

    //remove -1 from node 1 and 2
    temp=oneHead;
    oneHead=oneHead->next;
    temp->next=NULL;
    delete temp;

    temp=twoHead;
    twoHead=twoHead->next;
    temp->next=NULL;
    delete temp;

    //join nodes
    if (oneHead!=NULL){
        zeroTail->next=oneHead;
        if (twoHead!=NULL){
            oneTail->next=twoHead;
        }
    }
    else{
        if (twoHead!=NULL){
            zeroTail->next=twoHead;
        }
    }

    temp=zeroHead;
    zeroHead=zeroHead->next;
    temp->next=NULL;
    delete temp;

    return zeroHead;
}

int main(){
    node* first=new node(2);
    node* second=new node(2);
    node* third=new node(0);
    node* fourth=new node(0);
    node* fifth=new node(1);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    cout<<"Printing the LL: "<<endl;
    print(first);
    cout<<endl;

    cout<<"After sorting 0s and 1s and 2s: "<<endl;
    first = sort2(first);
    print(first);

    return 0;
}