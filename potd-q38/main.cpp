#include "func.h"

// .h and .cpp files seperate the declarations of the functions from the implementations. 
// we could let the client see the .h file and they would be able to use the functions without knowing how they were implemented.

/* The Problem

Create a file func.h that declares two functions

The first is a function secretKey that takes in no parameters, 
prints the secret key to stdout, and returns the secret key as a string

The secret key can be whatever you want with the restriction that it must 
only be made up of upper and lowercase letters

The second is a void function encrypt which takes in a string of letters and 
prints an encrypted version of the string to stdout

You can encrypt the string however you would like with three rules:

the encrypted string cannot be exactly the same as the original string
the encryption must be deterministic
the encryption must be unique(only one string maps to one output)

Implement these functions in a file func.cpp
Write a program main.cpp that utilizes these two functions to print out the encryption of the secret key
main.cpp can only include one file (there is no limit on how many files the other files can include)
We have provided a Makefile that will compile your main program as long as you named your files func.h, func.cpp, and main.cpp .
Run make to compile
In a comment in your main.cpp file explain why it might be important to break the code up into a .h and .cpp file

Sample output:

The secret key is purplerocks
The encryption of the secret key is sxusohurfnv
*/

int main(){
	string original = secretKey();
	encrypt(original);
}

