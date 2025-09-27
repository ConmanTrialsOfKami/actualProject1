//
// Created by ricar on 9/23/2025.
//

#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <vector>
#include <string>
#include <cctype>


using namespace std;
struct Node {
    string name;
    int id;
    int height;
    Node* left;
    Node* right;

    Node(const string& n, int i);
};

Node* insertAVL(Node* n, const string& name, int id, bool& success);

Node* deleteNode(Node* n, int id, bool& success);

Node* removeInOrder(Node* n, int k, bool& success);

bool searchId(Node* n, int id, string& oName);

void inOrderNames(Node* n, vector<string>& out);

void preOrderNames(Node* n, vector<string>& out);

void postOrderNames(Node* n, vector<string>& out);

void inOrderIDS(Node* n, vector<int>& ids);

void preorderCollectID(Node* n, const string& name, vector<int>& ids);

int lvlCount(Node* n);

bool eightDigitId(const string& s);

bool validName(const string& s);

bool extractQuote(const string& line, string& out);

void printNamesByComma(const vector<string>& names);

#endif //AVL_H
