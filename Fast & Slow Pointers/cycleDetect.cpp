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

bool detLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

int main()
{
    struct Node* head = NULL;
  
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
  
    head->next->next->next->next = head;
    
    cout<<(detLoop(head)?"linked list has loop" : "linked list has no loop");

    return 0;
}
