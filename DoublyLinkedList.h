//
//

#ifndef PROJECT3_DOUBLYLINKEDLIST_H
#define PROJECT3_DOUBLYLINKEDLIST_H

#include <stdlib.h>

template<class T>
class DNode {
public:
    DNode(const T &e = T(), DNode *n = nullptr, DNode *p = nullptr) : element(e), next(n), previous(p) {}

    ~DNode() {}

    T element;
    DNode *next;
    DNode *previous;
};

template<class T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    explicit DoublyLinkedList(T elem);
    void Insert(T elem);
    void DeleteBefore();
    void DeleteAfter();

    DNode<T> *cursor;  //refers to node after which the cursor appears.
    DNode<T> *head;   // refers to first element of linked list.
    size_t count;


//added methods
    void Clear();
    void MoveLeft();
    void MoveRight();


};

/*DoublyLinkedList()
 * It is a default constructor of class DoublyLinkedList of generic type. It sets the head of doubly linked list
 * and cursor to nullptr.
 * */
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    cursor = head;
}


/*DoublyLinkedList(T elem)
 * It is a constructor of class DoublyLinkedList of generic type that takes in an element.
 * It creates a node with given value and sets it as the head of doubly linked list. Cursor is set to head.
 * */
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(T elem) {
    DNode<char> *node = new DNode<T>(elem, nullptr, nullptr);
    head = node;
    cursor = head;
}


/*Insert(T elem)
 *
 * Pre: This method takes in generic type value.
 * It creates a node of given value and inserts it in doubly linked list based on position of cursor.
 * */
template<class T>
void DoublyLinkedList<T>::Insert(T elem) {
    auto *node = new DNode<T>(elem, nullptr, nullptr);
    if (cursor != nullptr) {
        if (cursor->next != nullptr) {
            node->next = cursor->next;
            cursor->next->previous = node;
        }
        else {
            node->next = nullptr;
        }
        cursor->next = node;
    }
    else {
        node->next = head;
        head = node;
    }
    node->previous = cursor;
    cursor = node;
}


/*DeleteBefore()
 * Pre: It takes in no parameters.
 * It deletes an element to the left of the cursor if the elements are present.
 * */
template<class T>
void DoublyLinkedList<T>::DeleteBefore() {
    if (cursor!= nullptr) {
        if (cursor->previous == nullptr) {
            head= cursor->next;
            cursor = nullptr;
        } else {
            DNode<T> *temp = cursor->previous;
            temp->next = cursor->next;
            if (cursor->next != nullptr) {
                cursor->next->previous =temp;
            }
            delete cursor;
            cursor=temp;
        }
    }

}


/*DeleteAfter()
 * Pre: It takes in no parameters.
 *
 * It deletes an element to the right of the cursor if elements are present.
 * */
template<class T>
void DoublyLinkedList<T>::DeleteAfter() {
    if(cursor== nullptr) {
        if(head!= nullptr) {
            DNode<T> *temp = head->next;
            delete head;
            head = temp;
        }
    }
    else {
        if (cursor->next != nullptr) {
            DNode<T> *rightToCursor = cursor->next;
            cursor->next = rightToCursor->next;
            if (rightToCursor->next != nullptr) {
                rightToCursor->next->previous = cursor;
            }
            delete rightToCursor;
        }
    }
}


/*MoveLeft()
 * Pre: This method takes in no parameters.
 * It shifts the cursor to the left by one position if possible, i.e., if there are nodes at left of present cursor.
 * */
template<class T>
void DoublyLinkedList<T>::MoveLeft() {
    if (cursor != nullptr) {
        if (cursor->previous != nullptr) {
            cursor = cursor->previous;
        } else {
            cursor = nullptr;
        }
    }

}


/*MoveRight()
 * Pre: This method takes in no parameters.
 * It shifts the cursor to the right by one position if possible, i.e., if there are nodes at right of present cursor.
 * */
template<class T>
void DoublyLinkedList<T>::MoveRight() {
    if(cursor!= nullptr) {
        if (cursor->next != nullptr) {
            cursor = cursor->next;
        }
    }else{
        cursor=head;
    }

}


/*Clear()
 * It takes in no parameters.
 * It deletes all nodes of doubly linked list from heap when they get out of scope.*/
template<class T>
void DoublyLinkedList<T>::Clear() {
    if (head == nullptr)
        return;
    auto *previous = head;
    auto *current = head;
    while (current != nullptr) {
        current = current->next;
        delete previous;
        previous = current;
    }

}


#endif //PROJECT3_DOUBLYLINKEDLIST_H
