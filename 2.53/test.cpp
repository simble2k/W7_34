#include <iostream>
using namespace std;

struct node{
    int val;
    node* next = nullptr;
};
void input(node* &head){
    node* cur = nullptr;
    int x;
    if(cin >> x && x != 0){
        head = new node;
        head->val = x;
        head->next = nullptr;
        cur = head;
        while(cin >> x){
            if(x == 0) break;
            cur->next = new node;
            cur = cur->next;
            cur->val = x;
            cur->next = nullptr;
        }
    }
}
void insertBegin(node* &head){
    node* temp = new node;
    cin >> temp->val;
    temp->next = head;
    head = temp;
}
void insertEnd(node* &head){
    node* temp = new node;
    cin >> temp->val;
    temp->next = nullptr;
    node* p = head;
    while(p->next != nullptr) p = p->next;
    p->next = temp;
}
void insertAfterNodek(node* &head){
    node* temp = new node;
    cin >> temp->val;
    temp->next = nullptr;
    int k; cin >> k;
    int cnt = 0;
    node* p = head;
    while(p != nullptr && cnt < k){
        p = p->next;
        cnt++;
    }
    temp->next = p->next;
    p->next = temp;
}
void insertBeforeNodek(node* &head){
    node* temp = new node;
    cin >> temp->val;
    temp->next = nullptr;
    int k; cin >> k;
    int cnt = 0;
    node* p = head;
    while(p != nullptr && cnt < k - 1){
        p = p->next;
        cnt++;
    }
    temp->next = p->next;
    p->next = temp;
}
void printList(node* &head){
    node* tmp = head;
    while(tmp != nullptr){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
void deleteList(node* &head){
    while(head){
        node* tmp = head;
        head = head->next;
        delete tmp;
    }
}
int main(){
    node* head = nullptr;
    input(head);
    printList(head);
    deleteList(head);
    return 0;
}

