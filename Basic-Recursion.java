//Name: Ruby Shrestha
// ULID: C00451990
//CMPS 261
//Program Description: This project consist of a main class and seven different methods to perform recursion.
//
//Certificate of Authenticity: I certify that the code in the method functions including method function main
//                          of this project are entirely my own work.
package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    //1. The sum of numbers from 1 to n can be defined recursively as follows:
    //a. If n = 1, the sum is 1.
    //b. for n > 1, the sum from 1 to n is n more than the sum from 1 to n-1
    //Write an int-method named sum that accepts an int parameter, n, and recursively calculates
    // and returns the sum of the numbers from 1 to n.


    /* sum

    Calculates the sum from 1 to given number,n recursively. Checks if the number is 1,
    if 1 returns 1 else recursively call the function to produce the desired result.

    Pre: A number greater than or equal to to 1 is passed.

    Post: The sum from 1 to given number is returned. The output is of integer type.
     */

    public static int sum(int number) {
        if (number == 1) {
            return 1;
        }
        return sum(number - 1) + number;
    }


    //2. Given m > n, Let gcd(m,n) denotes the greatest common divisor for integers m and n.
    // The gcd(m,n) could be defined recursively as follows:
    //a. If m%n is 0, gcd(m,n) = n.
    // Note: m%n = the remainder left after dividing m by n. For example, 7%3 = 1, 11%3 = 2, and 8 % 28 = 8.
    //b. Otherwise, gcd(m,n) = gcd (n, m%n)
    //Write an int-method named gcd that accepts two int parameters, m and n, and recursively calculates
    // and returns the gcd of the two given numbers.


    /* gcd

    This method calculates the greatest common divisor of given two numbers. If the larger number is divisible by
    the smaller number, the smaller number is returned as the output. If they are not exactly divisible,
    the method is called recursively with the smaller integer and remainder of the larger number divided by
    smaller number as arguments

    Pre: Two integers m and n, such that m > n is passed.

    Post: The greatest common divisor of the two numbers is returned. The returned value is of type integer.
    * */

    public static int gcd(int m, int n) {
        if (m % n == 0) {
            return n;
        } else {
            return gcd(n, m % n);
        }
    }



    //3. Write a recursive method that converts an integer into a binary number as a string.
    // Write a test program that prompts the user to enter an integer and displays its binary equivalent.
    // Assume that input integers are non-negative numbers.


    /* binaryEquivalent

    This method accepts the integer from user and converts it into its binary form with the help of the
    helper recursive function, binaryEquivalentHelper. The final output is produced as String.

    Pre: A user choice integer is provided as an argument.

    Post: The binary equivalent of given integer is returned as result. The result is of type String.
    */

    public static String binaryEquivalent(int number) {
        String answer = "";
        return binaryEquivalentHelper(number, answer);

    }

    public static String binaryEquivalentHelper(int number, String answer) {
        int remainder = number % 2;
        answer = remainder + answer;
        if  ((number == 0) || (number==1)) {
            return answer;
        }

        return binaryEquivalentHelper((number / 2), answer);

    }


    //4. The nth harmonic number is defined non-recursively as:
    //𝐻(𝑛)=1+1/2+1/3+1/4+⋯+1/𝑛
    //Come up with a recursive definition and use it to guide you to write a method definition for a
    // double-valued method named “harmonic” that accepts an int parameter n and recursively
    // calculates and returns the nth harmonic.
    // Write a test program that displays the harmonic numbers, 𝐻(𝑛), for 𝑛=1,2,3,⋯,10.


    /* harmonic

    This method calculates the harmonic number from 1 to 10 recursively. Harmonic number is given as:
    H(𝑛)=1+1/2+1/3+1/4+⋯+1/𝑛.  The final result is produced as double.

    Pre: Integers from 1 to 10 is passed into the method to get the desired output.

    Post: The harmonic number up to n=10 of type double is produced as output, i.e. 10 different results are produced
    for values of n=1 to n=10 respectively.
     */
    public static double harmonic(int n) {
        if (n == 1) {
            return (1);
        }
        return harmonic(n - 1) + (1.0 / n);
    }


    //5. Write a recursive method to compute the following series:
    //𝑚(𝑖)=1/3+2/5+3/7+4/9+5/11+6/13+⋯+𝑖/2𝑖+1
    //Write a test program that displays 𝑚(𝑖) for 𝑖=1,2,3,⋯,10.

    /* m

      This method calculates the given series:
      m(i)=1/3+2/5+3/7+......+i/(2i+1), where i in the given number.
      The output is produced in double format.

      Pre: The integers from 1 to 10 is passed into the method.

      Post: 10 different results are produced for n=1 to n=10 respectively. The desired result is of type double.

    */

    public static double m(int n){
        if (n==1){
            return 1.0/3;
        }
        return m(n-1)+( n/(2.0*n+1));
    }




    //6. Write a recursive method that returns the largest integer in an array.
    // Write a test program that prompts the user to enter a list of eight integers and displays the largest element.


    /* largestInProgram

   This method takes the array of integers of length eight as argument, parses through it recursively and returns the
   largest value of the integers

   Pre: User is prompted to enter the array of integers of length eight.

   Post: The largest value of the given array is returned as the answer.

   */
    public static int largestInArray(int[] myList) {
        int max = myList[0];
        return largestInArrayHelper(myList, max);
    }

    public static int largestInArrayHelper(int[] myList, int max) {
        if (myList[0] >= max) {
            max = myList[0];
        }
        if (myList.length == 1) {
            return max;
        }

        myList = Arrays.copyOfRange(myList, 1, myList.length);
        return largestInArrayHelper(myList, max);
    }


    //7. The “odd/even factorial” of a positive integer n is represented as n!! and is defined recursively as:
    //            a. (n)*(n-2)*(n-4)………*(2) if n is even. For example, 6!! = 6*4*2 = 48
    //            b. (n)*(n-2)*(n-4)*…….*(5)*(3)*(1) if n is odd. For example, 7!! = 7*5*3*1 = 105.
    //    Come up with a recursive definition for n!! and use it to guide you to write a method definition
    //    for a method called “oddevenfact” that recursively calculates the odd/even factorial value
    //    of its single int parameter. The value returned by “oddevenfact” is a long.


    /*oddevenfact

   This method takes in the positive integer as input and calculates the odd/even factorial of it.
   If the given number, n is odd, it returns the product of all the odd numbers from 1 to n. If the number is even,
   it returns the product of all the even numbers from 2 to n.

   Pre: A positive integer is passes as an argument to the method.

   Post: If the given number is even, the even factorial is returned. Else, the off factorial is returned.
  */
    public static long oddevenfact(int number) {
        if (number % 2 == 0) {
            if (number == 2) {
                return 2;
            }
        } else {
            if (number == 1) {
                return 1;
            }
        }
        return oddevenfact(number - 2) * number;

    }


    public static void main(String[] args) {

        System.out.println("The sum is " + sum(10));
        System.out.println();

        System.out.println("The gcd of 99 and 12 is " + gcd(99, 12));
        System.out.println();

        Scanner input = new Scanner(System.in);
        System.out.println("Enter a number to find its binary equivalent: ");
        int number = input.nextInt();
        System.out.println("The binary equivalent of " + number + " is " + binaryEquivalent(number));
        System.out.println();

        for (int i=1; i<=10; i++){
            System.out.println("The harmonic number for n = " + i +" is " + harmonic(i));
        }
        System.out.println();


        for (int i=1; i<=10;i++){
            System.out.println("When n = " + i + ", the value is "+ m(i));
        }
        System.out.println();


        int[] myList = new int[8];
        System.out.println("Enter the list of eight numbers separated by space/enter: ");
        for (int i = 0; i < 8; i++) {
            myList[i] = input.nextInt();
        }
        System.out.println("The largest number in given array is " + largestInArray(myList));
        System.out.println();


        System.out.println("The odd/even fact of " + 8 + " is " + oddevenfact(8));
        System.out.println("The odd/even fact of " + 7 + " is " + oddevenfact(7));
    }

}
