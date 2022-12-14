#include <iostream>
#include <fstream>
#include <string>
#include "huffman.h"
using namespace std;

/*
TASKS:
x -fix path to zero, missing one path
x-implement and debug checkLeader and validate
x-add cases to swap node
x-create and implement characterAgain
*/

//remember*: to output path to character, start from the character node all the way up

//./huff.exe encode alpha.txt message.txt.encoded - message.txt.encoded
//./huff.exe decode alpha.txt message.txt.decoded - message.txt.decoded

// const int NUM_OF_CHARACTERS=256; //number of ascii characters
const int VALID_NUM_OF_ARGUMENTS=4; //# of arguments


        //# of args   //arg strings or char array
int main(int argc, char const *argv[]){
    fstream alphabetFile;
    fstream textFile;
    string alphabet="";
    string message="";
    string encoded="";
    string decoded="";

    string commandArg; //command argument
    string alphabetArg; //alphabet argument
    string messageArg; //message argument
    string encodedArg; //encoded argument

    if (argc != VALID_NUM_OF_ARGUMENTS){
        cout << "Invalid number of arguments" << endl;
        return -1; 
    }

    cout << "what is in arg[1]: " << argv[1] << endl;
    cout << "what is in arg[2]: " << argv[2] << endl;
    cout << "what is in arg[3]: " << argv[3] << endl;
    
    commandArg=argv[1];
    alphabetArg=argv[2];
    if (commandArg=="encode"){ //if encode, set messageArg = argv[3]
        messageArg=argv[3];
    }
    else if (commandArg=="decode"){ //if decode, set encodedArg = argv[3]
        encodedArg=argv[3];
    }

    cout << "alphabet: " <<  alphabetArg << endl;

    if (commandArg == "encode"){
        //OPEN ALPHABET FILE AND PUT INTO STRING
        alphabetFile.open(alphabetArg, ios::in);
        if (alphabetFile.is_open()){
           getline(alphabetFile, alphabet); //get single line in file to get alphabet
        }
        else{
            cout << "FILE NOT OPEN!! alphabet" << endl;
        }
        alphabetFile.close(); //remember to close the file

        //OPEN MESSAGE AND PUT INTO STRING
        textFile.open(messageArg, ios::in); //open file
        if (textFile.is_open()){ 
            while (getline(textFile, message)){
                //message+=message; //append each line to the message string
            } 
        }
        else{
            cout << "FILE NOT OPEN!! message" << endl;
        }
        textFile.close();
        AdaptiveHuffman e(alphabet);
        encoded=e.encode(message);
        cout << encoded << endl;

        //OUTPUT encoded.txt FILE
        messageArg+=".encoded"; //append encoded file onto message.txt
        textFile.open(messageArg, ios::out); //open outgoing file
        if (textFile.is_open()){
           textFile << encoded;
        }
        textFile.close();
    }
    else if (commandArg == "decode"){//else if decode command
        //OPEN ALPHABET FILE AND PUT INTO STRING
        alphabetFile.open(alphabetArg, ios::in);
        if (alphabetFile.is_open()){
           getline(alphabetFile, alphabet); //get single line in file to get alphabet
        }
        alphabetFile.close(); //remember to close the file

        //OPEN ENCODED FILE AND PUT INTO STRING
        textFile.open(encodedArg, ios::in); //open file
        if(textFile.is_open()){ 
            while (getline(textFile, message)){
                //message+=message; //append each line to the message string
            }
        }
        textFile.close();

        AdaptiveHuffman d(alphabet);
        decoded=d.decode(message);
        cout << decoded << endl;

        //OUTPUT decoded.txt FILE
        int extensionLen = 8;
        encodedArg.erase(encodedArg.end()-extensionLen, encodedArg.end()); //detach .encoded from end -8 of arg to end
        encodedArg+=".decoded"; //append .decoded to encoded.txt file
        textFile.open(encodedArg, ios::out); //open outgoing file
        if (textFile.is_open()){
           textFile << decoded;
        }
        textFile.close();
    }
    else{
        cout << "Wrong command given, enter encode OR decode as 2nd arguemnt!!" << endl;
        return -1;
    }






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


    // AdaptiveHuffman e("abcde");
    // AdaptiveHuffman d("abcde");
    // encoded=e.encode("aabbbabcde");
    
    // decoded=d.decode(encoded);

    //cout << encoded << endl;
    //cout << decoded << endl;

    return 0;
}

