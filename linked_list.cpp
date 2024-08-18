#include <iostream>
#include <malloc.h>

using namespace std;
struct node{
    int val;
    struct node* next;
};

struct node* head = NULL;

void insert_end(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = data;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
    }
    else{
        if(head->next == NULL){
            head->next = new_node;
        }
        else{
            struct node* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = new_node;
        }
    }
}

void insert_beg(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = data;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
    }
}

void pop_end(){
    if(head == NULL){
        cout<<"Empty array!"<<endl;
    }
    else{
        if(head->next == NULL){
            head = NULL;
        }
        else{
            struct node* current = head;
            while(current->next->next != NULL){
                current = current->next;
            }
            current->next = NULL;
        }
    }
}

void pop_beg(){
    head = head->next;
}

void traverse(){
    if(head == NULL){
        cout<<"Empty array!"<<endl;
    }
    else{
        if(head->next == NULL){
            cout<<head->val<<endl;
        }
        else{
            struct node* current = head;
            while(current->next != NULL){
                cout<<current->val<<"->";
                current = current->next;
            }
            cout<<current->val<<endl;;
        }
    }
}

int count(){
    int c=0;
    if(head == NULL){
        return 0;
    }
    else{
        if(head->next == NULL){
            return 1;
        }
        else{
            struct node* current = head;
            while(current->next != NULL){
                c++;
                current = current->next;
            }
        }
    }
    return c+1;
}

bool search(int data){
    if(head == NULL){
        cout<<"Empty array!"<<endl;
    }
    else{
        if(head->next == NULL){
            if(head->val == data){
                return true;
            }
        }
        else{
            struct node* current = head;
            while(current != NULL){
                if(current->val == data){
                    return true;
                }
                current = current->next;
            }
        }
    }
    return false;
}

int main(){
    cout<<"1)Push at End 2)Push at Beg 3)Pop at end 4)Pop at beg 5)Traverse 6)Count 7)Search 8)Exit"<<endl;
    int c,val;
    bool s;
    while(true){
        cout<<"Enter choice: ";
        cin>>c;
        switch(c){
            case 1:
                cout<<"Enter val: ";
                cin>>val;
                insert_end(val);
                break;
            case 2:
                cout<<"Enter val: ";
                cin>>val;
                insert_beg(val);
                break;
            case 3:
                pop_end();
                break;
            case 4:
                pop_beg();
                break;
            case 5:
                traverse();
                break;
            case 6:
                val = count();
                cout<<val<<endl;
                break;
            case 7:
                cout<<"Enter val: ";
                cin>>val;
                s = search(val);
                cout<<s<<endl;
                break;
            case 8:
                return -1;
        }
    }
    return 0;
}
