#include "libarary.h"

template <typename T> class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename T> class binary_tree {
public:
    Node<T>* root;

    binary_tree() { root = nullptr; }

    void addNode(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node<T>* focusNode = root;
            Node<T>* parent;

            while (true) {
                parent = focusNode;

                if (data < focusNode->data) {
                    focusNode = focusNode->left;
                    if (focusNode == nullptr) {
                        parent->left = newNode;
                        return;
                    }
                }
                else {
                    focusNode = focusNode->right;
                    if (focusNode == nullptr) {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }
    void preOrderTraversal(Node<T>* focusNode) {
        if (focusNode != nullptr) {
            std::cout << focusNode->data << " ";
            preOrderTraversal(focusNode->left);
            preOrderTraversal(focusNode->right);
        }
    }
};