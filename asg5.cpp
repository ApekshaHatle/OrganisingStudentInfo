#include <iostream>
#include <queue>
using namespace std;

// Node structure for the BST
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Function to insert a key into the BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        // Handle insertion of duplicate entry (optional)
        // For this example, duplicates will be ignored
        cout << "Duplicate key ignored: " << key << endl;
    }

    return root;
}

// Function to find the node with the minimum key value in a BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a key from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Function to search for a key in the BST
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (root->key == key) {
        return true;
    } else if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to display the tree (Inorder traversal)
void displayTree(Node* root) {
    if (root != nullptr) {
        displayTree(root->left);
        cout << root->key << " ";
        displayTree(root->right);
    }
}

// Function to calculate the depth of the tree
int calculateDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
}

// Function to create the mirror image of the tree
Node* mirrorImage(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* mirrored = new Node(root->key);
    mirrored->left = mirrorImage(root->right);
    mirrored->right = mirrorImage(root->left);

    return mirrored;
}

// Function to create a copy of the tree
Node* copyTree(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* copy = new Node(root->key);
    copy->left = copyTree(root->left);
    copy->right = copyTree(root->right);

    return copy;
}

// Function to display all parent nodes with their child nodes
void displayParents(Node* root) {
    if (root != nullptr) {
        if (root->left != nullptr || root->right != nullptr) {
            cout << "Parent: " << root->key << " - ";
            if (root->left != nullptr) {
                cout << "Left Child: " << root->left->key << " ";
            }
            if (root->right != nullptr) {
                cout << "Right Child: " << root->right->key;
            }
            cout << endl;
        }

        displayParents(root->left);
        displayParents(root->right);
    }
}

// Function to display leaf nodes
void displayLeafNodes(Node* root) {
    if (root != nullptr) {
        if (root->left == nullptr && root->right == nullptr) {
            cout << root->key << " ";
        }

        displayLeafNodes(root->left);
        displayLeafNodes(root->right);
    }
}

// Function to display tree level wise
void displayLevelWise(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            cout << current->key << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
    }
}

int main() {
    Node* root = nullptr;
    int choice;

    while (true) {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display Tree\n";
        cout << "5. Display Depth of Tree\n";
        cout << "6. Display Mirror Image\n";
        cout << "7. Create a Copy\n";
        cout << "8. Display Parents with Child Nodes\n";
        cout << "9. Display Leaf Nodes\n";
        cout << "10. Display Tree Level Wise\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int key;
                cout << "Enter the key to insert: ";
                cin >> key;
                root = insert(root, key);
                break;
            }
            case 2: {
                int key;
                cout << "Enter the key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;
            }
            case 3: {
                int key;
                cout << "Enter the key to search: ";
                cin >> key;
                if (search(root, key)) {
                    cout << key << " found in the tree." << endl;
                } else {
                    cout << key << " not found in the tree." << endl;
                }
                break;
            }
            case 4: {
                cout << "Original Tree (Inorder): ";
                displayTree(root);
                cout << endl;
                break;
            }
            case 5: {
                int depth = calculateDepth(root);
                cout << "Depth of the tree: " << depth << endl;
                break;
            }
            case 6: {
                Node* mirroredRoot = mirrorImage(root);
                cout << "Mirror Image of the Tree (Inorder): ";
                displayTree(mirroredRoot);
                cout << endl;
                break;
            }
            case 7: {
                Node* copyRoot = copyTree(root);
                cout << "Copy of the Tree (Inorder): ";
                displayTree(copyRoot);
                cout << endl;
                break;
            }
            case 8: {
                cout << "Parents with Child Nodes:" << endl;
                displayParents(root);
                break;
            }
            case 9: {
                cout << "Leaf Nodes: ";
                displayLeafNodes(root);
                cout << endl;
                break;
            }
            case 10: {
                cout << "Display Tree Level Wise:" << endl;
                displayLevelWise(root);
                break;
            }
            case 0:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
