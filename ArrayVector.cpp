//
// Created by peter on 9/16/20.
// Modified by Ruby Shrestha.
//

#include "ArrayVector.h"
#include <algorithm>
#include <iostream>
#include <climits>

//using namespace std;
using std::cout;
using std::endl;

const size_t resize_amount = 5;


/* ArrayVector
 *
 * This method is a constructor which takes in the size of array  as parameter.
 * It creates a new array of given size in the heap.
  */
ArrayVector::ArrayVector(size_t av_size) {
    array_for_vector = new int[av_size];
    total_elements = av_size;
    current_elements = 0;
}


/*ArrayVector
 *
 * This method is a constructor which takes in an array and its size as parameters .
 * It creates a new array in the heap and copies all the elements from given array to it.
  */
ArrayVector::ArrayVector(size_t other_sz, int *other_array) {
    array_for_vector = new int[other_sz];
    for (int i = 0; i < other_sz; i++) {
        array_for_vector[i] = other_array[i];
    }
    total_elements = other_sz;
    current_elements = other_sz;
}


/* AddArray

 * Pre: This method takes in an int array and its size of type size_t.
 *
 * There are two cases:
 * a. If total elements is smaller than sum of current elements and given array size, it creates a temporary array
 *      that can hold original array and the passed array. All the elements from original array and passed array are
 *      copied into temporary array respectively. The original array is deleted and temporary array is assigned to
 *      original array.
 * b. If total elements is equal to or greater than the sum of current elements and given array size, the elements from
 *      passed array is copied into original array.
 *
 * Post:It adds the passed array to the end of existing array.
  */
void ArrayVector::AddArray(size_t arg_size, int *other_array) {
    if (total_elements < current_elements + arg_size) {
        int new_size = current_elements + arg_size + resize_amount;
        int *temp_vector = new int[new_size];
        for (int i = 0; i < current_elements; i++) {
            temp_vector[i] = array_for_vector[i];
        }
        for (int i = 0; i < arg_size; i++) {
            temp_vector[i + current_elements] = other_array[i];
        }
        total_elements = new_size;
        delete[] array_for_vector;
        array_for_vector = temp_vector;
    }
    else{
        int j=0;
        for (int i=current_elements; i<current_elements+arg_size;i++){
            array_for_vector[i]=other_array[j];
            j++;
        }
    }
    current_elements+=arg_size;

}


/*Get
 * Pre: This method takes in an index of type size_t as a parameter.
 *
 * It checks if the passed index is valid and returns the result accordingly. If index is valid, the value at that index
 * is returned, else an error message is printed and -123456 is returned.
 *
 * Post: It returns the value of vector at that index.
 * */
int ArrayVector::Get(size_t index) {
    if (index >= 0 && index < current_elements) {
        return array_for_vector[index];
    } else {
        cout << "Index error: No index found " ;
        return -123456;
    }
}


/*Pop
 *
 * Pre: This method takes no parameter.
 *
 * It checks if the list is empty. If empty, it prints an error message and return -123456. When list is not empty,
 * it returns the last element of list and removes it from the list.
 *
 * Post: It returns the deleted last value of the list.
 */
int ArrayVector::Pop() {
    if (current_elements < 1) {
        cout << "Vector is empty ";
        return -123456;
    } else {
        int value = array_for_vector[current_elements - 1];
        current_elements--;
        return value;
    }
}


/* AddSpace
 *
 * Pre: This method takes no parameters.
 *
 * If the current elements is equal to total elements, it creates a temporary array with size 5 more than original
 * array. All the elements from original array are copied into temporary array. The original array is deleted and
 * temporary array is assigned to original array.
 *
 * Post:It adds the space to the original vector.
 * */
void ArrayVector::AddSpace() {
    if (current_elements == total_elements) {
        int *temp_vector = new int[total_elements + resize_amount];
        for (int i = 0; i < current_elements; i++) {
            temp_vector[i] = array_for_vector[i];
        }
        total_elements += resize_amount;
        delete[] array_for_vector;
        array_for_vector = temp_vector;
    }
}


/*PushBack
 *
 * Pre: It takes in an int value.
 *
 * It calls AddSpace method to increase the size of array if needed and adds the passed value to the back of array.
 *
 * Post: Passed value is added to the list at the back.
 **/
void ArrayVector::PushBack(int val) {
    AddSpace();
    array_for_vector[current_elements] = val;
    current_elements++;
}


/*Insert
 *
 * Pre: Two parameters, index and value of type size_t and int respectively are passed.
 *
 * There are three cases:
 * a. If index equals current elements, it calls PushBack method to add it to the back of array.
 * b. If index is greater than total elements, it gives an error message.
 * c. If both of the cases fail, it calls AddSpace function. All the elements from the given index in original array are
 *      shifted one position right. The passed value is inserted at the given index.
 *
 * Post: Given value is inserted at given index.
 * */
void ArrayVector::Insert(size_t index, int val) {
    if (index == current_elements) {
        PushBack(val);
    }
    else if (index > total_elements) {
        cout << "Index Out of Bound" << endl;
    }
    else {
        AddSpace();
        for (int i = current_elements; i > index; i--) {
            array_for_vector[i] = array_for_vector[i - 1];
        }
        array_for_vector[index] = val;
        current_elements++;
    }
}


/*Remove
 *
 * Pre: It takes an int value as a parameter.
 *
 * It checks if the given value is present in the list. If present, it deletes that value. All the other elements
 * behind the index of removed value are shifted one position left.
 *
 * Post: Given value is removed from the array.
 * */
void ArrayVector::Remove(int val) {
    if (current_elements < 1) {
        cout << "Vector is empty" << endl;
    }
    else {
        bool check = false;
        int i;
        for (i = 0; i < current_elements; i++) {
            if (array_for_vector[i] == val) {
                check = true;
                break;
            }
        }
        if (check) {
            current_elements--;
            for (int j = i; j < current_elements; j++) {
                array_for_vector[j] = array_for_vector[j + 1];
            }
        } else
            cout << "Element not found" << endl;
    }
}


/*GetCurrentSize
 *
 * Pre: It takes no parameter.
 *
 * Post: Returns the current elements of array.
 * */
int ArrayVector::GetCurrentSize() {
    return current_elements;
}


/*GetTotalSize
 *
 * Pre: It takes no parameter.
 *
 * Post: Returns the total elements (capacity) of array.
 * */
int ArrayVector::GetTotalSize() {
    return total_elements;
}


/*PrintVector
 *
 * Pre: It takes in no parameters
 *
 * Prints [] if vector is empty.
 * If not empty, it print all the elements of array inside the big brackets separated by comma.
 * */
void ArrayVector::PrintVector() {
    if (current_elements == 0) {
        cout << "[]" << endl;
    } else {
        cout << "[" << " ";
        for (int i = 0; i < current_elements; i++) {
            if (i + 1 == current_elements) {
                cout << array_for_vector[i]<< " ";
            } else {
                cout << array_for_vector[i] << " , ";
            }
        }
        cout << "]" << endl;
    }
}


/*Sum
 *
 * Pre: It takes in no parameters
 *
 * It calculates and returns the sum of all the numbers in array. If the array is empty it return 0.
 *
 * Post: It returns the sum of all the numbers in array.
 * */
int ArrayVector::Sum() {
    if (current_elements == 0) {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < current_elements; i++) {
        sum += array_for_vector[i];
    }
    return sum;
}


/*Max
 *
 * Pre: It takes in no parameters
 *
 * It checks for the maximum numbers in an array. If the array is empty, it prints an error message and returns the
 * minimum integer.
 *
 * Post: It returns the maximum value of an array.
 * */
int ArrayVector::Max() {
    int max = INT_MIN;
    if (current_elements <= 0) {
        cout << "No elements in vector. Returning smallest integer" << endl;
    }
    else {
        for (int i = 0; i < current_elements; i++) {
            if (array_for_vector[i] > max) {
                max = array_for_vector[i];
            }
        }
    }
    return max;
}


/*Min
 *
 * Pre: It takes in no parameters
 *
 * It checks for the minimum numbers in an array. If the array is empty, it prints an error message and returns the
 * maximum integer.
 *
 * Post: It returns the minimum value of an array.
 * */
int ArrayVector::Min() {
    int min = INT_MAX;
    if (current_elements <= 0) {
        cout << "No elements in vector. Returning biggest integer" << endl;
    }
    else {
        for (int i = 0; i < current_elements; i++) {
            if (array_for_vector[i] < min) {
                min = array_for_vector[i];
            }
        }
    }
    return min;

}


/*Average
 *
 * Pre: It takes in no parameters
 *
 * It calculates the average value of elements in an array. If the array is empty, it prints an error message and
 * returns -123456
 * minimum integer.
 *
 * Post: It returns the maximum value of an array.
 * */
double ArrayVector::Average() {
    if (current_elements < 1) {
        cout << "No elements in vector. Returning random number -123456" << endl;
        return -123456;
    }
    double sum = Sum();
    return sum / GetCurrentSize();
}


/*~ArrayVector
 *
 * It is a destructor that deletes the array memory from heap when array gets out of scope.
 * */
ArrayVector::~ArrayVector() {
    delete[] array_for_vector;
}
