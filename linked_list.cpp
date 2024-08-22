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
    if(head == NULL){
    	cout<<"Empty list!"<<endl;
	}
	else{
		if(head->next == NULL){
			head->next = NULL;
		}
		else{
			head = head->next;
		}
	}
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

void sort(){
    int c = count();
    int t;
    for(int i=0; i<c; i++){
        struct node *temp = head;
        while(temp->next != NULL){
            if(temp->val > temp->next->val){
                t = temp->val;
                temp->val = temp->next->val;
                temp->next->val = t;
            }
            temp = temp->next;
        }
    }
}

void isDistinct(){
	struct node *outer_node = head;
	while(outer_node->next != NULL){
		struct node *inner_node = outer_node->next;
		while(inner_node != NULL){
			if(outer_node->val == inner_node->val){
				cout<<"Not distinct!"<<endl;
				return;
			}
			inner_node = inner_node->next;
		}	
		outer_node = outer_node->next;
	}
	cout<<"Distinct list!"<<endl;
}

void minimum(){
	if(head == NULL){
		cout<<"Empty list! Cannot find minimum"<<endl;
	}
	else{
		if(head->next == NULL){
			cout<<"Minimum is "<<head->val<<endl;
		}
		else{
			int min=head->val;
			struct node *temp = head->next;
			while(temp != NULL){
				if(temp->val < min){
					min = temp->val;
				}
				temp = temp->next;
			}
			cout<<"Minimum is "<<min<<endl;
		}
	}
}
void maximum(){
	if(head == NULL){
		cout<<"Empty list! Cannot find maximum"<<endl;
	}
	else{
		if(head->next == NULL){
			cout<<"Maximum is "<<head->val<<endl;
		}
		else{
			int max=head->val;
			struct node *temp = head->next;
			while(temp != NULL){
				if(temp->val > max){
					max = temp->val;
				}
				temp = temp->next;
			}
			cout<<"Maximum is "<<max<<endl;
		}
	}
}
int sum(){
	if(head == NULL){
		cout<<"Empty list! Cannot summate"<<endl;
		return 0;
	}
	else{
		if(head->next == NULL){
			return head->val;
		}
		else{
			int s=0;
			struct node *temp = head;
			while(temp != NULL){
				s = s + temp->val;
				temp = temp->next;
			}
			return s;
		}
	}
}
void avg(){
	if(head == NULL){
		cout<<"Empty list! Cannot find average!"<<endl;
	}
	else{
		if(head->next == NULL){
			cout<<"Average is "<<head->val<<endl;
		}
		else{
			int c = count();
			int s = sum();
			cout<<"Average is "<<s/c<<endl;
		}
	}
}

void remove(int data){
	if(head == NULL){
		cout<<"Empty list!"<<endl;
		return;
	}
	else{
		if(head->next == NULL){
			if(head->val == data){
				head = NULL;
				return;
			}
		}
		else{
			struct node *temp = head;
			while(temp != NULL){
				if(temp->next->val == data){
					temp->next = temp->next->next;
					return;
				}
				temp = temp->next;
			}
		}
	}
}

void insert_mid();
void pop_mid();
void sliding_window();

int main(){
    cout<<"1)Push at End 2)Push at Beg 3)Pop at end 4)Pop at beg 5)Traverse 6)Count 7)Search 8)Sort"<<endl;
    cout<<"9)Minimum 10)Maximum 11)Sum 12)Average 13)Distinct 14)Remove"<<endl;
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
                sort();
                break;
            case 9:
            	minimum();
            	break;
            case 10:
            	maximum();
            	break;
            case 11:
            	val = sum();
            	cout<<"The sum is "<<val<<endl;
            	break;
            case 12:
            	avg();
            	break;
            case 13:
            	isDistinct();
            	break;
            case 14:
            	cout<<"Enter val to be removed: ";
            	cin>>val;
            	remove(val);
            	break;
            default:
            	return -1;
        }
    }
    return 0;
}
