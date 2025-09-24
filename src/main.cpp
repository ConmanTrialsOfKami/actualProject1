#include <iostream>

using namespace std;
// Node of BST/AVL
struct Node {
    string name; //student name
    int id; //UF id
    int height; //height of AVL
    Node* left;
    Node* right;

    Node(string& n, int i) {
        name = n;
        id = i;
        height = 1;
        left = nullptr;
        right = nullptr;

    }
};

// gets height
int heightShower(Node* n) {
    if (n == nullptr) {
        return 0; // if tree empty height is 0
    }
    else {
        return n->height; //Return height of tree
    }
}

// updates height
void heightUpdater(Node* n) {
    if (n != nullptr) {
        int leftHeight = heightShower(n->left); //gets height from left child
        int rightHeight = heightShower(n->right); // gets height from right child

        if (leftHeight > rightHeight) {
            n->height = 1 + leftHeight; // height = 1 (this node) + taller child height
        }
        else {
            n->height = 1 + rightHeight; // same thing but for rightHeight
        }
    }
}

// check if tree is balanced, and then call rotation functions when not

int balanceFactor(Node* n) {
    if (n == nullptr) {
        return 0; // return 0 if nullptr
    }
    else {
        return heightShower(n->left) - heightShower(n->right); // return difference of heights between children.
    }
}

// Rotations when tree is not balanced

// Right rotation. Fixes left side thats unbalanced.
Node* rightRotation(Node* n) {
    Node* x = n->left;
    Node* T = x->right;

    x->right = n;
    n->left = T;

    heightUpdater(n);
    heightUpdater(x);

    return x;
}

// Same thing but for left rotation.
Node* leftRotation(Node* n) {
    Node* x = n->right;
    Node* T = x->right;

    x->right = n;
    n->left = T;

    heightUpdater(n);
    heightUpdater(x);

    return x;
}

// Here we decide when to apply rotations

Node* rebalance(Node* n) {
    heightUpdater(n); // make sure node's height is good

    int balanceF = balanceFactor(n); // get Balance factor
    if (balanceF > 1) {
        // if left child is right heavy, rotate left on the child (LR case)
        if (balanceFactor(n->left) < 0) {
            n->left = leftRotation(n->left);
        }
        // Now right rotation at node that handles LL
        return rightRotation(n);
    }
    else if (balanceF < -1) {
        // Same as before, but now opposite. RL case
        if (balanceFactor(n->right) > 0) {
            n->right = rightRotation(n->right);
        }

        // Same as before, but left rotation at node that handles RR case.
        return leftRotation(n);
    }
    else {
        return n; // if its balanced just return n
    }
}

int main(){

}
