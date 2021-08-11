//
//

#include "LinkedEditor.h"
#include <iostream>

/*LinkedEditor()
 * It is a default constructor that creates instances of DoublyLinkedList in heap.
 * */
LinkedEditor::LinkedEditor() {
    buffer= new DoublyLinkedList<char>();
    char character='a';
    //buffer= new DoublyLinkedList<char>(character);

}


/*PrintEditor()
 *Pre: This method takes in no parameters.
 *
 * It prints the elements of doubly linked list and cursor on their correct positions.
 * */
void LinkedEditor::PrintEditor() {
    DNode<char>* temp= buffer->head;
    if (temp == nullptr || buffer->cursor== nullptr){
        std::cout<<"|";
    }

    while(temp!= nullptr){
        std::cout<<temp->element;
        if (temp==buffer->cursor){
            std::cout<<"|";
        }
        temp=temp->next;
    }
}


/*MoveLeft()
 * Pre:This method takes in no parameters.
 *
 * It calls MoveLeft() method of DoublyLinkedList which moves cursor to one node left of previous position if possible.
 * */
void LinkedEditor::MoveLeft() {
    buffer->MoveLeft();
}


/*MoveRight()
 * Pre:This method takes in no parameters.
 *
 * It calls MoveRight() method of DoublyLinkedList which moves cursor to one node right of previous position if possible.
 * */
void LinkedEditor::MoveRight() {
    buffer->MoveRight();
}


/*AddChar(char value)
 * Pre: This method takes a character as input.
 *
 * It calls Insert(char value) method of DoublyLinkedList which adds the given character in particular position based
 * on the position of cursor.*/
void LinkedEditor::AddChar(char c) {
    buffer->Insert(c);
}


/*Backspace()
 * Pre: This method takes no parameter.
 *
 * It calls DeleteBefore() method of DoublyLinkedList which removes a character in front of cursor if possible.
*/
void LinkedEditor::BackSpace() {
    buffer->DeleteBefore();
}


/*Delete()
 * Pre: This method takes no parameter.
 *
 * It calls DeleteAfter() method of DoublyLinkedList which removes a character after cursor if possible.
*/
void LinkedEditor::Delete() {
    buffer->DeleteAfter();
}

/*~LinkedEditor()
 * It is a destructor of LinkedEditor that calls the Clear() method of DoublyLinkedList*/
LinkedEditor::~LinkedEditor() {
    buffer->Clear();
    delete buffer;

}






