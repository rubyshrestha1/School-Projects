//
// Created by peter on 10/24/20.
//

#include "Editor.h"
#include <iostream>


using std::cout;
using std::endl;

size_t cursor_index = 0;

/*AddChar(char value)
 * Pre: This method takes a character as input.
 *
 * It inserts the given character in particular position based on the position of cursor by using insert method of vector.*/
void Editor::AddChar(char c) {
    buffer.insert(buffer.begin() + cursor_index, c);
    cursor_index++;

}


/*PrintEditor()
 *Pre: This method takes in no parameters.
 *
 * It prints the elements of vector and cursor on their correct positions.
 * */
void Editor::PrintEditor() {
    char cursor = '|';
    if (buffer.empty() || cursor_index == 0 || cursor_index > buffer.size()) {
        cout << cursor;
    }
    for (int i = 0; i < buffer.size(); i++) {
        cout << buffer.at(i);
        if (i + 1 == cursor_index) {
            cout << cursor;}

    }
    cout<<"\n";
}


/*MoveLeft()
 * Pre:This method takes in no parameters.
 *
 * It decreases the current index of the cursor by 1 until it is greater than zero. It index is smaller than 1, it is
 * set to zero.
 * */
void Editor::MoveLeft() {
    if (cursor_index >= 1) {
        cursor_index--;
    } else {
        cursor_index = 0;
    }

}

/*MoveRight()
 * Pre:This method takes in no parameters.
 *
 * It increases the current index of the cursor by 1 until it is smaller than size of vector. It index is greater than
 * or equals to vector size, it is set of vector size.
 * set to zero.
 * */
void Editor::MoveRight() {
    if (cursor_index < buffer.size()) {
        cursor_index++;
    } else {
        cursor_index = buffer.size();
    }

}


/*Backspace()
 * Pre: This method takes no parameter.
 *
 * It removes an element in front of cursor by using erase method of vector and decreases the cursor index.
*/
void Editor::BackSpace() {
    if (!buffer.empty()) {
        if (cursor_index > 0) {
            buffer.erase(buffer.begin() + cursor_index - 1);
            cursor_index--;
        }
    }

}


/*Delete()
 * Pre: This method takes no parameter.
 *
 * It removes an element after cursor by using erase method of vector and increases the cursor index.
*/
void Editor::Delete() {

    if (!buffer.empty()) {
        if (cursor_index < buffer.size())
            buffer.erase(buffer.begin() + cursor_index);

    }
}


