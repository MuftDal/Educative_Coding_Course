#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};
  
void push(struct Node** head, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

struct Node* startofLoop(struct Node* head) {
    struct Node *slow = head, *fast = head, *begin = head;    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            while(begin != slow) {
                    begin = begin->next;
                    slow = slow->next;
            }
            return begin;
        }
    }
    return NULL;
}

int main()
{
    struct Node* head = NULL;
  
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
  
    head->next->next->next->next = head->next;
    
    int entry = 0;
    while(head != startofLoop(head)) {
        head = head->next;
        entry++;
    }
    cout<<"tail connects to node index "<<entry;

    return 0;
}
