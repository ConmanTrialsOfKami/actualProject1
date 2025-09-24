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

int heightShower(Node* n) {
    if (n == nullptr) {
        return 0; // if tree empty height is 0
    }
    else {
        return n->height; //Return height of tree
    }
}

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


int main(){

}
