//
// Created by ricar on 9/23/2025.
//
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "AVL.h"

using namespace std;
// Node of BST/AVL
Node::Node(const string& n, int i) {
    name = n;
    id = i;
    height = 1;
    left = nullptr;
    right = nullptr;
}

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

// Same thing but for left rotation. Every left swaps with right
Node* leftRotation(Node* n) {
    Node* x = n->right;
    Node* T = x->left;

    x->left = n;
    n->right = T;

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

// Now the insert node function by ID, with the rebalance function we defined. If we
// If we get a duplicate we dont insert.

Node* insertAVL(Node* n, const string& name, int id, bool& success) {
    if (n == nullptr) {
        success = true;
        return new Node(name, id);
    }

    else {
        if (id < n->id) {
            n->left = insertAVL(n->left, name, id, success); // by sorting we know to insert id on left if id < n->id
        }
        else if (id > n->id) {
            n->right = insertAVL(n->right, name, id, success); // same for this, but other way around
        }
        else {
            // if there's a dupe we don't insert
            success = false;
            return n;
        }

        return rebalance(n); // using the rebalance function to rebalance back up
    }


}

// function to find smallest node to find inorder successor

Node* minimum(Node* n) {
    while (n != nullptr && n->left != nullptr) {
        n = n->left;
    }
    return n;
}

// Function that deletes nodes by ID, also uses minimum to find inorder successor
Node* deleteNode(Node* n, int id, bool& success) {
    if (n == nullptr) {
        return nullptr;
    }
    // if id is smaller, go left and delete that node
    if (id < n->id) {
        n->left = deleteNode(n->left, id, success);
    }
    // same thing but for right node
    else if (id > n->id) {
        n->right = deleteNode(n->right, id, success);
    }

    else {
        // we find the node, id's are equal
        success = true;
        // if it has no children we just delete
        if (n->left == nullptr && n->right == nullptr) {
            delete n;
            return nullptr;
        }

        // if it has a right child, delete the node and return the right child
        else if (n->left == nullptr) {
            Node* right = n->right;
            delete n;
            return right;
        }
        // same thing for having a left child
        else if (n->right == nullptr) {
            Node* left = n->left;
            delete n;
            return left;
        }
        // If it has two kids, we replace the data with the inorder successor, then delete the successor node from the right
        else {
            Node* s = minimum(n->right);
            n->id = s->id;
            n->name = s->name;
            n->right = deleteNode(n->right, s->id, success);
        }
    }
    // now we simply update height
    heightUpdater(n);
    return n;
}

// search if ID is in tree
bool searchId(Node* n, int id, string& oName) {
    // we go through the BST till we find it, if we go thru entire thing and don't find it it returns false
    while (n != nullptr) { //smaller id's are on the left, bigger ones on the right, and we go thru the entire tree till id = n->id, and if we never find it, it exits the while loop as n == nullptr
        if (id < n->id) {
            n = n->left;
        }
        else if (id > n->id) {
            n = n->right;
        }
        else {
            oName = n->name;
            return true;
        }
    }
    return false;
}
// gets ids in preorder, to later print
void preorderCollectID(Node* n, const string& name, vector<int>& ids) {
    // if empty return
    if (n == nullptr) {
        return;
    }
    // if node name is the same as string name, add node id to vector
    if (n->name == name) {
        ids.push_back(n->id);
    }
    // Continue for the children
    preorderCollectID(n->left, name, ids);
    preorderCollectID(n->right, name, ids);

}
// similar to previous function, but collects names inorder instead of preorder ids.
void inOrderNames(Node* n, vector<string>& out) {
    if (n == nullptr) {
        return;
    }
    // goes to left node
    inOrderNames(n->left, out);

    // add name to vector
    out.push_back(n->name);

    // goes to right node
    inOrderNames(n->right, out);
}

void preOrderNames(Node* n, vector<string>& out) {
    if (n == nullptr) {
        return;
    }
    // moves push_back to be first to be preorder instead of inorder
    out.push_back(n->name);
    preOrderNames(n->left, out);
    preOrderNames(n->right, out);
}

// for getting postorder names, moving push_back as the last line in comparison to the previous functions
void postOrderNames(Node* n, vector<string>& out) {
    if (n == nullptr) {
        return;
    }
    postOrderNames(n->left, out);
    postOrderNames(n->right, out);
    out.push_back(n->name);
}

// get IDS in order like we did for names, so same thing except we use n->id
void inOrderIDS(Node* n, vector<int>& ids) {
    if (n == nullptr) {
        return;
    }
    else {
        inOrderIDS(n->left, ids);
        ids.push_back(n->id);
        inOrderIDS(n->right, ids);
    }
}
// to fulfill the the requirement of printing the number of levels in AVL tree
int lvlCount(Node* n) {
    return heightShower(n);
}

// checks if ID is 8 digits and is valid.
bool eightDigitId(const string& str) {
    // checks if its 8 digits, returns false if it isnt
    if (str.size() != 8) {
        return false;
    }
    // goes thru every character, and if 1 isn't a number, it returns false
    for (char c : str) {
        if (isdigit(c) == false) {
            return false;
        }
    }
    // if every character is a number and the string is 8 digits, it returns true
    return true;
}
// checks to make sure a name is valid, ie, has only letters and spaces
bool validName(const string& str) {
    // if the string is empty return false
    if (str.empty() == true) {
        return false;
    }
    // checks for every character if it isnt between A-Z and a-z, and space
    for (char c : str) {
        if (isalpha(c) == false && c != ' ') {
            return false;
        }
    }

    return true;
}

bool extractQuote(const string& line, string& out) {
    bool inside = false; // boolean for if we are inside quotes
    out = "";

    for (char c : line) {
        if (c == '"') {
            // if we're inside, job is done, we return true
            if (inside == true) {
                return true;
            }

            // if not, we found the first quote
            else {
                inside = true;
            }
        }
        // we add the characters inside the quote
        else if (inside == true) {
            out += c;
        }
    }
    // if there was no closing quote

    return false;
}

// prints each name separated by a comma
void printNamesByComma(const vector<string>& names) {
    // goes thru every name
    for (int i = 0; i < names.size(); i++) {
        cout << names[i];
        // checks if its the last element, if it is it doesnt print a comma and ends for loop
        if (i + 1 >= names.size()) {
            break;
        }
        cout << ", ";
    }

    // new line after loop
    cout << "\n";
}

