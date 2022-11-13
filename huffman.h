#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <cstring>
using namespace std;

//remember*: to output path to character, start from the character node all the way up
//default all characters point to 0 node

//Adaptive Huffman Prep

//./huff.exe encode alpha.txt message.txt.encoded - message.txt.encoded
//./huff.exe decode alpha.txt message.txt.decoded - message.txt.decoded

const int NUM_OF_CHARACTERS=256; //number of ascii characters
const int NUM_OF_ARGUMENTS=4; //# of arguments

class AdaptiveHuffmanNode{
private:
    AdaptiveHuffmanNode* parent; //pointer to parent
    AdaptiveHuffmanNode* left; //pointer to left node
    AdaptiveHuffmanNode* right; //pointer to right node
    AdaptiveHuffmanNode* prev; //pointer to prev node in thread
    AdaptiveHuffmanNode* next; //pointer to next node in thread
    int count;
    char character;
public:
    AdaptiveHuffmanNode();
        //defualt constructor
        //set all attributes to nullptr, NULL, or 0;
    char getCharacter(){
        return character;
    }
    void setCharacter(char character){
        this->character=character;
    }
};


class AdaptiveHuffman{
private:
    AdaptiveHuffmanNode* root;
    AdaptiveHuffmanNode* zero;
    AdaptiveHuffmanNode* alphabet_arr[NUM_OF_CHARACTERS]; //array of AdaptiveHuffman node pointers
    string alphabet;
    char alphabetValid[NUM_OF_CHARACTERS];
    string message; 
    string encoded;

public:
    AdaptiveHuffman();
        //defualt constructor
    AdaptiveHuffman(string);
        //convert string into char of array using strcpy
        //copy into string into alphabet_arr
        //root node default 0 node
    AdaptiveHuffmanNode* newCharacter();
    string encode(string);
        //message string as a parameter and returns encoded message
        //vector<char> message; //use char vector (we dont know how long the message is, use push_back())
        //
        //copy message into char array (vector)
        //
        //for loop through message char vector (int i=0; i<message_arr.size(); i++)
        //
        //  message_arr[i];
        //  if (encounter a new character)
        //      make a sibling node, a new root node
        //      make element character pointer point to sibling node
        //      append path to root node then ascii value of character in binary
        //      
        //  else if (encounter a character again)
        //      call check sibling
        //      append path to root node (0's and 1's) and 1
        //
        //end loop
        //
        //convert encode vector into string 
        //
        //return encode string
    string decode(string);
        //encoded string as parameter and returns decoded message
        //vector<char> encoded
        //
        //convert encoded string into char array
        //
        //for loop through encoded char array 
        //
        //  if (encounter a new character a.k.a hit 0 node)
        //      make 2 new nodes, a new sibing and a new parent (both with count 1)
        //      make element character point to sibling node
        //      get next 8 elements and convert binary value to ascii character then append
        //  else if (encounter character again)
        //      increment parent node
        //      call check sibling
        //      when node is found, append character to message
        //
        //end loop 
        //
        //return message
    AdaptiveHuffmanNode* checkSibling(AdaptiveHuffmanNode*);
        //takes 0 node as input and returns huffman
        //if huffman violates sibling property
        //  rearrange nodes ADD HERE
        //  if (leader is parent of count)
        //      JUST increment parent count by one, up to the root node
        //  else if
        //      swap position with leader 
        //else (if no violation)
        //  return node 
    char* createAlphabetArray(string);
    bool validateAlphabet(int);
};

//TREE METHODS:
AdaptiveHuffman::AdaptiveHuffman(){
    this->root=this->zero=nullptr;
    this->alphabet_arr[NUM_OF_CHARACTERS]={0};
    this->alphabetValid[NUM_OF_CHARACTERS]={0};
    this->message=this->encoded="";
}
AdaptiveHuffman::AdaptiveHuffman(string alphabet){
    this->root= new AdaptiveHuffmanNode(); //create default zero node which is also root
    this->alphabet=alphabet;
    for (int i = 0; i < NUM_OF_CHARACTERS; i++){ //all pointers in alphabet array point to zero node
        alphabet_arr[i]=zero;
    }
    this->message=this->encoded="";
}
char* AdaptiveHuffman::createAlphabetArray(string alphabet){
    char* c = new char[alphabet.length()+1];
    strcpy(c, alphabet.c_str());
    for (int i=0; i<alphabet.length(); i++){
        int asciiVal=(unsigned int)c[i]; //get ascii value from 1st character in alphabet
        alphabetValid[asciiVal];
    }
}
bool AdaptiveHuffman::validateAlphabet(int asciiVal){
    if (alphabetValid[asciiVal]==0) //if character not found in element, return false
        return false;
    return true; //else true
}
string AdaptiveHuffman::encode(string message){
    char* msg = new char[message.length()+1]; //+1 for null terminated character
    strcpy(msg, message.c_str()); //convert string into char array
    for (int i=0; i < message.length(); i++){
        int asciiVal=(unsigned int)msg[i];
        while(validateAlphabet(asciiVal)){ //while character is in alphabet
            if (alphabet_arr[asciiVal]==zero){ //if alphabet char pointer points to zero, new character!!

            }
            else if (alphabet_arr[asciiVal]!=zero){

            }
        }
    }

}
string AdaptiveHuffman::decode(string encoded){

}

//can use .length to get amount of char in string

//NODE METHODS:
AdaptiveHuffmanNode::AdaptiveHuffmanNode(){
    this->parent=left=right=prev=next=nullptr;
    this->count=0;
    this->character=0;
}

#endif