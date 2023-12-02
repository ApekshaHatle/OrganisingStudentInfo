#include <iostream>
using namespace std;

// Node structure for the threaded binary tree
struct Node {
    int key;
    Node* left;
    Node* right;
    bool leftThread;
    bool rightThread;

    Node(int value) : key(value), left(nullptr), right(nullptr), leftThread(false), rightThread(false) {}
};

// Function to insert a key into the threaded binary tree
Node* insert(Node* root, int key) {
    Node* newNode = new Node(key);

    if (root == nullptr) {
        return newNode;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;

        if (key < current->key) {
            if (!current->leftThread) {
                current = current->left;
            } else {
                break;
            }
        } else if (key > current->key) {
            if (!current->rightThread) {
                current = current->right;
            } else {
                break;
            }
        } else {
            // Duplicate key, ignore for this example
            delete newNode;
            return root;
        }
    }

    if (key < parent->key) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->left = newNode;
        parent->leftThread = true;
    } else {
        newNode->left = parent;
        newNode->right = parent->right;
        parent->right = newNode;
        parent->rightThread = true;
    }

    return root;
}

// Function to find the in-order successor of a node in a threaded binary tree
Node* inOrderSuccessor(Node* node) {
    if (node->rightThread) {
        return node->right;
    } else {
        node = node->right;
        while (node->leftThread) {
            node = node->left;
        }
        return node;
    }
}

// Function to traverse the threaded binary tree in in-order
// Function to traverse the threaded binary tree in in-order
// Function to traverse the threaded binary tree in in-order
void inOrderTraversal(Node* root) {
    Node* current = root;

    while (current != nullptr) {
        while (current->left != nullptr && !current->leftThread) {
            current = current->left;
        }

        cout << current->key << " ";

        if (current->rightThread) {
            current = current->right;
        } else {
            current = current->right;
            while (current != nullptr && current->leftThread) {
                current = current->left;
            }
        }
    }
}


// Function to traverse the threaded binary tree in pre-order
void preOrderTraversal(Node* root) {
    Node* current = root;

    while (current != nullptr) {
        cout << current->key << " ";

        if (!current->leftThread) {
            current = current->left;
        } else if (!current->rightThread) {
            current = current->right;
        } else {
            current = inOrderSuccessor(current);
        }
    }
}

int main() {
    Node* root = nullptr;

    // Insertion
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // In-order traversal
    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Pre-order traversal
    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    return 0;
}
