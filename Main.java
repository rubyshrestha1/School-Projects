/*
Name: Ruby Shrestha
CMPS 261 Honors Project
ULID: C00451990
Description: This project implements tim sort.
*
* */
package com.company;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Main {


    /* binaryInsertionSort
    * Pre: It takes in an array of unsorted integers.
    *
    * This method sorts the given list via binary insertion sort. It uses binary search to find the position
    * of element in array.
    *
    * Post: The given list is sorted.
  */
    public static void binaryInsertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int x = array[i];
            int j = Math.abs(Arrays.binarySearch(array, 0, i, x) + 1);
            System.arraycopy(array, j, array, j + 1, i - j);
            array[j] = x;
        }
    }



    /* mergeSort
    * Pre: It takes in he list of integers and three integers that represents left, middle and right index.
    *
    * This method divides the given list into two halves. It calls merge function to merge two halves of the list.
    *
    * Post: Merge function is called to execute merge sort process.
    * */
    public static void mergeSort(int[] myList, int l, int m, int r) {

        int[] firstHalf = new int[myList.length / 2];
        System.arraycopy(myList, 0, firstHalf, 0, myList.length / 2);

        int secondHalfLength = myList.length - myList.length / 2;
        int[] secondHalf = new int[secondHalfLength];
        System.arraycopy(myList, myList.length / 2, secondHalf, 0, secondHalfLength);

        merge(firstHalf, secondHalf, myList);

    }


/* merge
* Pre: It takes in three lists of integers as parameters
*
* This method merges two halves of lists obtained from mergeSort function and stores it in the original list.
*
* Post: The original list is sorted.
*
* */
    public static void merge(int[] firstHalf, int[] secondHalf, int[] myList) {
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < firstHalf.length && j < secondHalf.length) {
            if (firstHalf[i] <= secondHalf[j]) {
                myList[k++] = firstHalf[i++];
            } else {
                myList[k++] = secondHalf[j++];
            }
        }
        while (i < firstHalf.length) {
            myList[k++] = firstHalf[i++];
        }
        while (j < secondHalf.length) {
            myList[k++] = secondHalf[j++];
        }
    }


    /* timSort
    *  Pre: It takes in an array of unsorted integers and an integer that represents the size of array
    *
    * This method performs the tim sort. If the size of array is less than 32, it performs binary insertion. It performs
    * binary insertion for every 32 numbers and then performs merge sort on those lists.
    *
    * Post: Given array is sorted by timsort.
    * */
    public static void timSort(int[] arr, int n) {
        int run = 32;

        for (int i = 0; i < n; i += run) {
            binaryInsertionSort(arr);

        }


        for (int size = run; size < n; size = 2 * size) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = Math.min((left + 2 * size - 1), (n - 1));
                mergeSort(arr, left, mid, right);
            }
        }
    }


    /*printArray
    * Pre: It takes in an array of integers and an integer that represents the array size.
    *
    * This method prints the elements of array.
    * */
    public static void printArray(int[] arr, int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.print("\n");
    }


    /* Main
    *  The main method prompts user to decide if they want to generate random numbers or enter numbers manually. It also
    * prompts user to enter the size of array.
    * It also calculates the execution time for different cases of timsort, for instance, when the array is already sorted
    * and when it is not sorted. */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println(" Do you want to generate random numbers or enter numbers manually? (1/2)  ");
        int value = input.nextInt();
        System.out.println("How many numbers do you want? ");
        int number = input.nextInt();

        Random random = new Random();

        int[] intArray = new int[number];
        if (value == 1) {
            int i = 0;
            while (i < number) {
                intArray[i] = random.nextInt(1000);
                i++;
            }
        } else if (value == 2) {
            System.out.println("Enter numbers separated by space ");
            for (int i = 0; i < number; i++) {
                intArray[i] = input.nextInt();
            }

        }
        //printArray(intArray, intArray.length);
        long startTime = System.currentTimeMillis();
        timSort(intArray, intArray.length);
        long endTime = System.currentTimeMillis();
        long executionTime = endTime - startTime;
        //printArray(intArray, intArray.length);
        System.out.println("The time taken is " + executionTime + " milliseconds.");

System.out.println();
        System.out.println("Calculation for complexity: ");
        System.out.printf("%15s %15s %15s ", "Size/Case", "Best", "Average");

        System.out.println();
        System.out.println("---------------------------------------------------------------------------------------");
        int numberOfInput = number;
        int i = 0;

        while (i < 5) {
            numberOfInput *= 2;
            System.out.printf("%15d ", numberOfInput);
            int[] myArray = new int[numberOfInput];

            for (int j = 0; j < numberOfInput; j++) {
                myArray[j] = j;
            }

            startTime = System.currentTimeMillis();
            timSort(myArray, myArray.length);
            endTime = System.currentTimeMillis();
            executionTime = endTime - startTime;

            System.out.printf("%15d", executionTime);
    


            for (int j = 0; j < numberOfInput; j++) {
                myArray[j] = random.nextInt(1000);
            }
            startTime = System.currentTimeMillis();
            timSort(myArray, myArray.length);
            endTime = System.currentTimeMillis();
            executionTime = endTime - startTime;
            //printArray(myArray, myArray.length);
            System.out.printf("%15d", executionTime);

            i++;
            System.out.println();

        }

    }
}
