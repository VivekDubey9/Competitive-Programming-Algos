#include <bits/stdc++.h>
using namespace std;
 
/* A linked list node */
struct Node {
    int data;
    struct Node* next;
};
 
// Utility function to create a new Node
struct Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
