#include <iostream>
#include <fstream>
#include <string>
#include "huffman.h"
using namespace std;

/*
TASKS:
x -fix path to zero, missing one path
-implement and debug checkLeader and validate
-add cases to swap node
-create and implement characterAgain
*/

//remember*: to output path to character, start from the character node all the way up

//Adaptive Huffman Prep

//./huff.exe encode alpha.txt message.txt.encoded - message.txt.encoded
//./huff.exe decode alpha.txt message.txt.decoded - message.txt.decoded

// const int NUM_OF_CHARACTERS=256; //number of ascii characters
const int VALID_NUM_OF_ARGUMENTS=4; //# of arguments


        //# of args   //arg strings or char array
int main(int argc, char const *argv[]){
    // fstream alphabetFile;
    // fstream textFile;
    // string alphabet="";
    // string message="";
    // string encoded="";
    // string decoded="";

    // if (argc != VALID_NUM_OF_ARGUMENTS){
    //     cout << "Invalid number of arguments" << endl;
    //     return -1; 
    // }


    // if (argv[1]="encode"){
    //     //OPEN ALPHABET FILE AND PUT INTO STRING
    //     alphabetFile.open(argv[2], ios::in);
    //     while (alphabetFile.is_open()){
    //        getline(alphabetFile, alphabet); //get single line in file to get alphabet
    //     }
    //     alphabetFile.close(); //remember to close the file

    //     //OPEN MESSAGE AND PUT INTO STRING
    //     textFile.open(argv[2], ios::in); //open file
    //     while (alphabetFile.is_open()){ 
    //         while (getline(textFile, message)){
    //             message+=message; //append each line to the message string
    //         }
    //     }
    //     textFile.close();

    //     AdaptiveHuffman e(alphabet);
    //     encoded=e.encode(message);

    //     //OUTPUT ENCODED FILE
    //     textFile.open(argv[3], ios::out); //open outgoing file
    //     while (textFile.is_open()){
    //         textFile << encoded;
    //     }
    //     textFile.close();
    // }
    // else if (argv[1]="decode"){//else if decode command
    //     //OPEN ALPHABET FILE AND PUT INTO STRING
    //     alphabetFile.open(argv[2], ios::in);
    //     while (alphabetFile.is_open()){
    //        getline(alphabetFile, alphabet); //get single line in file to get alphabet
    //     }
    //     alphabetFile.close(); //remember to close the file

    //     //OPEN ENCODED FILE AND PUT INTO STRING
    //     textFile.open(argv[2], ios::in); //open file
    //     while (textFile.is_open()){ 
    //         while (getline(textFile, message)){
    //             message+=message; //append each line to the message string
    //         }
    //     }
    //     textFile.close();

    //     AdaptiveHuffman d(alphabet);
    //     decoded=d.decode(message);

    //     //OUTPUT DECODED FILE
    //     textFile.open(argv[3], ios::out); //open outgoing file
    //     while (textFile.is_open()){
    //         textFile << decoded;
    //     }
    //     textFile.close();
    // }
    // else{
    //     cout << "Wrong command given, enter encode OR decode as 2nd arguemnt!!" << endl;
    //     return -1;
    // }






    //check for correct # of arguments
    //if too little OR too many arguments, prompt user to enter again
    //indicate input is wrong with the program

    //identify commands given
    //if encode command
    //else if decode command
    //else incorrect command

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


    string encoded;
    string decoded;

    AdaptiveHuffman e("abc");
    AdaptiveHuffman d("abc");
    encoded=e.encode("abcccabb");
    
    //decoded=d.decode(encoded);

    //cout << decoded << endl;


    
    char a='a';
    cout << (unsigned int)a << endl;
    return 0;
}

