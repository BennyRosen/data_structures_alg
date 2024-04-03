#ifndef TREE_H
#define TREE_H

template <typename T>
class Node {

    T val;
    Node* right;
    Node* left;

    public:
        Node(T val = T(), Node* a = nullptr, Node* b = nullptr);

        T get_val();
        Node* get_left();
        Node* get_right();
        void set_val(T val);
        void set_left(Node* n);
        void set_right(Node* n);
};

template <typename T>
class Tree {

    Node<T>* root;

    public:
        Tree();
        Tree(T val);

        Node<T>* lookup(T val);
        bool insert(T val);
        bool contains(T val);

        Node<T>* get_top();
        void set_top(Node<T>* root);
        void get_top();
};

#endif