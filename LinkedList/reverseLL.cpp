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

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(node* &head, node* &tail, int data) {
    // Check for empty LL
    if (head == NULL) {
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step1: create node
    node* newNode = new node(data);
    // Step2: address of newnode
    newNode->next = head;
    // Step3: pos of head
    head = newNode;
}

void insertAtTail(node* &head, node* &tail, int data) {
    // Check for empty LL
    if (head == NULL) {
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step1: create a node
    node* newNode = new node(data);
    // Step2: connect newnode
    tail->next = newNode;
    // Step3: change pos of tail
    tail = newNode;
}

int findLength(node* head) {
    node* temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void insertAtPosition(int data, int position, node* &head, node* &tail) {
    if (head == NULL) {
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if (position == 0) {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);
    if (position == len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Find pos, prev and curr
    int i = 1;
    node* prev = head;
    while (i < position) {
        prev = prev->next;
        i++;
    }
    node* curr = prev->next;

    // Create newNode
    node* newNode = new node(data);

    // Assign newnode next to curr
    newNode->next = curr;

    // Prev next to newNode
    prev->next = newNode;
}

void deletenode(int position, node* &head, node* &tail) {
    if (head == NULL) {
        cout << "LL is empty" << endl;
        return;
    }

    if (position == 0) {
        node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);

    // Delete last node
    if (position == len - 1) {
        int i = 0;
        node* prev = head;
        while (i < position - 1) {
            prev = prev->next;
            i++;
        }
        prev->next = NULL;
        node* temp = tail;
        tail = prev;
        delete temp;
        return;
    }

    // Deleting middle node

    // Step1: find prev and curr
    int i = 0;
    node* prev = head;
    while (i < position - 1) {
        prev = prev->next;
        i++;
    }
    node* curr = prev->next;

    // Step2:
    prev->next = curr->next;
    // Step3:
    curr->next = NULL;
    // Step4:
    delete curr;
}

node* reverse(node* prev, node* curr){
    //base condition
    if (curr==NULL){
        return prev;
    }

    //one case solve
    node* forward=curr->next;
    curr->next=prev;

    //recursive call
    reverse(curr, forward);
}

node* reversebyloop(node* head){
    node* prev=NULL;
    node* curr=head;
    while (curr!=NULL){
        node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtTail(head, tail, 77);

    print(head);
    // insertAtPosition(25, 4, head, tail);
    // print(head);
    // deletenode(5, head, tail);

    // node* curr=head;
    // node* prev=NULL;

    head= reversebyloop(head);
    print(head);
    return 0;
}
