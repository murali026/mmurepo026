#include<iostream>

using namespace std;

typedef struct node {
    int data;
    struct node* np;
    node(int d) {
        data = d;
        np = NULL;
    }
}node;

void push_front(node** headref, int data) {
    node* root = *headref;
    node* n1 = new node(data);
    if(root == NULL) {
        *headref = n1;
    } else {
        n1->np = *headref;
        *headref = n1;
    }
}

void push_back(node** headref, int data) {
    node* root = *headref;
    node* n1 = new node(data);
    if(root == NULL) {
        *headref = n1;
    } else {
        node* prev;
        while(root) {
           prev = root;
           root = root->np;
        }
        prev->np = n1;
    }
}

void print_list(node** headref) {
    if(headref == NULL) {
        return;
    }
    node* cur = *headref;
    while(cur) {
        cout << cur->data << " ";
        cur = cur->np;
    }
}

int length(node** headref) {
    if(headref == NULL || *headref == NULL) {
        return 0;
    } else {
        node* cur = *headref;
        int len = 0;
        while(cur) {
            len += 1;
            cur = cur->np;
        }
        return len;
    }
}

int countN(node* root, int val) {
    int count = 0;
    while(root) {
        if(root->data == val) {
            count++;
        }
        root = root->np;
    }
    return count;
}

int getNthValue(node* root, int index) {
    int nth = 0;
    while(root) {
        nth++;
        if(index == nth) {
            return root->data;
        }
        root = root->np;
    }
    //not found;
    return -1;
}

node* getNthNode(node* root, int index) {
    int nth = 0;
    while(root) {
        nth++;
        if(index == nth) {
            return root;
        }
        root = root->np;
    }
    return NULL;
}

void deleteNthValue(node* root, int val) {
    node* prev = NULL;
    while(root) {
        node* prev = root;
        if(root->data == val) {
            prev->np = root->np;
        }
    }
}

void reverse(node** root) {
    if(root == NULL || *root == NULL) {
        return;
    }
    node* prev = NULL;
    node* cur = *root;
    node* next = NULL;
    while(cur) {
        next = cur->np;
        cur->np = prev;
        prev = cur;
        cur = next;
    }
    *root = prev;
}


int main() {
   node* root = NULL;
   push_back(&root, 45);
   push_back(&root, 5);
   push_front(&root, 10);
   push_front(&root, 11);
   push_front(&root, 5);
   push_back(&root, 77);
   print_list(&root);
   cout << endl << "length:" << length(&root) << endl;
   cout << endl << "Count:" << countN(root, 5) << endl;
   cout << endl << "NthValue:" << getNthValue(root, 4) << endl;
   reverse(&root);
   cout << endl << "Reverse:" << endl;
   print_list(&root);
   return 0;
}
