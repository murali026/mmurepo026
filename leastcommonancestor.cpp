#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
void getNode(Node* root, int v, map<Node*, pair<int, int>>& myMap, int depth) {
    if(root == NULL) {
        return;
    }
    if(root->data == v) {
        cout << "found value " << v << endl;
        return;
    } else {
        getNode(root->left, v, myMap, depth+1);
        getNode(root->right, v, myMap, depth+1);
    }
    map<Node*, pair<int, int>>::iterator mit;
    mit = myMap.find(root);
    if(mit != myMap.end()) {
        //this node already present in map, so 
    } else {
        myMap[root] = make_pair(root->data, depth);
        cout << "Adding " << root->data << endl;
    }
    return;
}

Node* find_node(Node* root, int v1) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == v1) {
        cout << "found node" << endl;
        return root;
    } else {
        Node* cur = find_node(root->left,v1);
        if(cur) {
            cout << "\tParentNode Left:" << root->data << endl;
            return cur;
        }
        cur = find_node(root->right,v1);
        if(cur) {
            cout << "\tParentNode Right:" << root->data << endl;
            return cur;
        }
    }
}

    Node *lca(Node *root, int v1,int v2) {
        if(root == NULL) {
            return NULL;
        }
        Node* f = find_node(root, v1);
        cout << "FINAL Node:" << f->data << endl;
        f = find_node(root, v2);
        cout << "FINAL Node:" << f->data << endl;
        return root;
        map<Node*, pair<int, int>> myMap;
        map<Node*, pair<int, int>> myMap2;
        map<Node*, pair<int, int>>::iterator it;
        //map<Node*, pair<int, int>>::iterator it2;
        //add root node with initial depth of 0
        getNode(root, v1, myMap, 0);
        getNode(root, v2, myMap, 0);
        //getNode(root, v2, myMap2, 0);
        for(it = myMap.begin(); it != myMap.end(); ++it) {
            cout << "Node for Value " <<  it->second.first << ":" << endl;
        }
		// Write your code here.
        return NULL;
    }

}; //End of Solution

int totalNodes = 0;

void printTree(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << endl;
    cout << " ";
    printTree(root->left);
    printTree(root->right);
    totalNodes += 1;
    return;
}

int main() {
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
    printTree(root);
    cout << "Total Nodes:" << totalNodes << endl; 

    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
