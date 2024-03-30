/*
 * FILE: f8.cpp
 * PROJECT : focused Assignment 8
 * PROGRAMMER : Aryankumar Jitendrabhai Malaviya (8963030)
 * FIRST VERSION : 2024 - 03 - 29
 * DESCRIPTION : Write a program to give you practice at working with
 *               C-style strings, files, command-line arguments, and structs.
 */

#include <stdio.h>

typedef struct MyData {
    int howMany;
    char theText[21];
    char directoryPath[21];
    char filename[21];
}myArgs;

void main(int argc, char* argv[])
{
    MyData myArgs;

    // making myArgs (also assigning the values to the variable) in the function
    if (!parseArguments(argc, argv, &myArgs)) {
        return 0;
    }
}
int parseArguments(int argc, char* argv[], MyData* data) {

    //  4+1 because 4 argument from the comand line and 1 1 plus the number of arguments,
    // as virtually all implementations will prepend the name of the program to the array.
    // referance https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean
    if (argc != 5) {
        fprintf(stderr, "Incorrect number of argument.\n");
        return 0;
    }

    // atoi -> referance: https://www.geeksforgeeks.org/c-atoi-function/
    data->howMany = atoi(argv[1]); // convertinh the ASCII to integer
    // checking if the howMany is an integer and if yes it is greater than or equal to 0
    if (data->howMany <= 0) {
        fprintf(stderr, "Error: Invalid number of lines\n");
        return 0;
    }
    strncpy(data->theText, argv[2], 20);
    strncpy(data->directoryPath, argv[3], 20);
    strncpy(data->filename, argv[4], 20);
    return 1;
}