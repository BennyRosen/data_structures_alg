#include "../headers/tree.h"


//Tree implementations
template <typename T>
Tree<T>::Tree() {
    this->root = nullptr;
}

template <typename T>
Tree<T>::Tree(T val) {
    Node<T>* n = new Node(val);
}

template <typename T>
Node<T>* Tree<T>::lookup(T val) {
    Node<T>* curr = root;
    bool found = false;
    while(curr != nullptr) {
        if(curr->get_val() == val) {
            return curr;
        } else if(curr->get_val() > val) {
            curr = curr->get_left();
        } else {
            curr = curr->get_right();
        }
    }

    return nullptr;
}

template <typename T>
bool Tree<T>::insert(T val) {
    Node<T>* n = new Node<T>(val);

    if(root == nullptr) {
        top = n;
        return true;
    }

    Node<T>* curr = root;
    while(true) {
        if(curr->get_val() > val) {
            if(curr->get_left() == nullptr) {
                curr->set_left(n);
                return true;
            } 
            curr = curr->get_left();
        } else if(curr->get_val() < val) {
            if(curr->get_right() == nullptr) {
                curr->set_right(n);
                return true;
            } 
            curr = curr->get_right();
        } else {
            return false;
        }
    }
}

template <typename T>
bool Tree<T>::contains(T val) {
    if(root == nullptr) return false;
    
    Node<T>* curr = root;
    while(true) {
        if(curr->get_val() > val) {
            if(curr->get_left() == nullptr) return false;
            curr = curr->get_left();
        } else if(curr->get_val() < val) {
            if(curr->get_right() == nullptr) return false;
            curr = curr->get_right();
        } else {
            return true;
        }
    }
}

//Node implementations 
template <typename T>
Node<T>::Node(T val = T(), Node<T>* a = nullptr, Node<T>* b = nullptr) {
    this->val = val;
    this->left = a;
    this->right = b;
}