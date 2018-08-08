
#include <iostream>
#include <string>
#include "decoderHuffman.h"

using namespace std;

void Decode::insertLeafAt(int val, string binaryString) {
    Node *current;
    current = root;
    for (int i = 0; i < binaryString.length(); i++) {
        if (binaryString.at(i) == '0') {
            if (current->leftnode == NULL) {
                Node* newNode = new (struct Node);
                current->leftnode = newNode;
            }
            current = current->leftnode;
        }
        else if (binaryString.at(i) == '1') {
            if (current->rightnode == NULL) {
                Node* newNode = new (struct Node);
                current->rightnode = newNode;
            }
            current = current->rightnode;
        }
    }
    current->val = val;
    current->checkLeaf = true;
}

int Decode::takeAt(string binaryString) {
    Node *current;
    current = root;

    for (int i = 0; i < binaryString.length(); i++) {
        if (current == NULL) {
            return -1;
        }
        else if (binaryString.at(i) == '0') {
            current = current->leftnode;
        }
        else if (binaryString.at(i) == '1') {
            current = current->rightnode;
        }
    }
    if (current->checkLeaf == true) {
        return current->val;
    }
    else {
        return -1;
    }
}

Node* Decode::getRoot() {
    return root;
}




