#include <iostream>
#include "huffman.h"
#include <vector>
using namespace std;

//remember*: to output path to character, start from the character node all the way up

//Adaptive Huffman Prep

//./huff.exe encode alpha.txt message.txt.encoded - message.txt.encoded
//./huff.exe decode alpha.txt message.txt.decoded - message.txt.decoded

// const int NUM_OF_CHARACTERS=256; //number of ascii characters
// const int NUM_OF_ARGUMENTS=4; //# of arguments


        //# of args   //arg strings or char array
int main(int argc, char const *argv[]){
    //check for correct # of arguments
    //if too little OR too many arguments, prompt user to enter again

    //identify commands given
    //if encode command
    //else if decode command
    //else incorrect command
    //  return -1;

    //get alphabet from alphabet.txt
    //open alphabet file
    //read single line into string variable (alphabet.txt only has one string)
    //*remember: close file

    //get message from message.txt
    //open message file
    //read each line and append to a string
    //*remember: close file

    //create AdaptiveHuffmanTree object and take in alphabet string as an argument
    //if encode command
    //  call encode method
    //else if decode command
    //  call decode method
    char a='a';
    cout << (unsigned int)a << endl;
    return 0;
}

