### ARM Assembly Programming

In this project you are going to write some ARM assembly functions by hand.
In order to facilitate testing, we will use a C program to call out to the ARM assembly functions.
I provide an example of the C driver program.
All of your ARM assembly functions should follow the ARM Procedure Call Conventions as described in the book and in class.
Please do not use the compiler to generate ARM assembly output and then turn in this output. It will be pretty obvious if the code you submit appears to be compiler generated. You will get zero points for any program in which you do this.
I provide some guidelines for testing below. You should provide testing output that makes it clear the inputs and resulting outputs so that we can easily see that the tests are working.
You also need to include  Makefile that can both build and test your code.
All of your ARM programs should use the ARMv7 instruction set and they should run on your Raspberry Pi.

**Program 1: sum_array**

Sum the elements of an integer array. Assume the elements can be 2's complement signed values.

Here is a C implementation:
~~~~
int sum_array(int *array, int n)
{
    int i;
    int sum = 0;

    for (i = 0; i < n; i++) {
        sum = sum + array[i]; 
    }

    return sum;
}
~~~~
Construct 4 different tests with positive, negative, and zero values. You should have a test that sums at least 1000 elements.
Compare the output of the C version to your version.

**Program 2: find_max**

Find the maximum value in a an array of signed integer values. You can assume this function is called with an array that has at least one element.

Here is a C implementation:
~~~~
int find_max(int *array, int n)
{
    int i;
    int max = array[0];

    for (i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max; 
}
~~~~
Construct 4 different tests with positive, negative, and zero values. You should have a test that has an input array of at least 1000 elements.
Compare the output of the C version to your version.

**Program 3: fib_iter**

Implement the fibonacci sequence function iteratively. Given a value n, find the nth fibonacci sequence value. Assume the sequence starts with 0.
I will leave it to you to find or implement the iterative version in C.
Your test should display the first 20 fibonacci numbers. You should compare your Assembly output to the C output.

**Program 4: fib_rec**

Implement the fibonacci sequence function recursively. Given a value n, find the nth fibonacci sequence value. Assume the sequence starts with 0.

Here is a C implementation:
~~~~
int fib_rec(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
}
~~~~
Your test should display the first 20 fibonacci numbers. You should compare your Assembly output to the C output.


**Program 5: find_str**

Write a function that will determine the location of a substring with in a given string. Here is the C prototype:

int find_str(char * s, char *sub);

If the sub string is located in s, then find_str() will return the index where sub starts in s. If sub is not found in s, then find_str() will return -1.

First, write a C version of find_str(), then implement an ARM assembly version. Try to simplify your C version version so that it makes it easier to write your assembly version.

Please provide tests were sub is present and not present in the given string s.
