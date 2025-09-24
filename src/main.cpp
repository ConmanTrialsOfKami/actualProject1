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
int main(){

}
