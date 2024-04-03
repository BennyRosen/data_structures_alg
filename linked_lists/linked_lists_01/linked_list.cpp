#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Node {
    private:
        T data;
        Node* next;

    public:
        Node() {
            this->data = data;
            this->next = nullptr; 
            int[] arr = {2,3,4,5};
        }

        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }

        T getData() {
            return this->data;
        }

        Node* getNext() {
            return this->next;
        }

        void setNext(Node* n) {
            this->next = n;
        }
};

template <typename T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;
    public:
        LinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        LinkedList(T val) {
            Node<T>* newNode = new Node<T>(val);
            this->head = newNode;
            this->tail = newNode;
            this->length = 1;
        }

        int size() {
            return this->length;
        }

        void append(T val) {
            Node<T>* newNode = new Node<T>(val);

            if(this->length == 0) {
                this->head = newNode;
                this->tail = this->head;
            } else {
                this->tail->setNext(newNode);
                this->tail = newNode;

                this->head = newNode;
                this->length++;
            }
        }

        void prepend(T val) {

        }

        // bool insert(int index, T val) {
        //     int count = 0;
        //     Node* temp = this->head;
        //     while()
        // }

        bool remove(int index) {
            if(index < 0 || index >= this->length || this->length == 0) { 
                return false;
             };

            if(index == 0) {
                if(this->length == 1) {
                    this->head = nullptr;
                    return true;
                }

                Node<T>* temp = this->head;
                this->head = this->head->getNext();
                delete temp;
                return true;
            }

            Node<T>* prev = this->head;
            Node<T>* curr = this->head->getNext();
            
            bool removed = false;
            int count = 1;
            while(curr) {
                if(count == index) {
                    Node<T>* temp = curr;
                    prev->setNext(temp->getNext());
                    delete temp;
                    removed = true;
                    break;
                }
                
                prev = curr;
                curr = curr->getNext();
                count++;
            }

            return removed;
        }

        // bool remove(int index1, int index2) {
        //     if(index1)
        //     while()
        // }

        void printList() {
            if(this->head == nullptr) { return; };

            Node<T>* temp = this->head;

            while(temp) {
                cout << temp-> getData() << " " << endl;
                temp = temp-> getNext();
            }

            cout << "There are " << this->length << "items. " << endl;
        }
};

int main () {
    LinkedList<int>* list = new LinkedList<int>(9);
    list->append(10);
    list->append(11);
    list->append(12);
    list->append(13);
    list->append(14);

    list->remove(6);
    list->printList();
};
