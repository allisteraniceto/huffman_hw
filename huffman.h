#pragma once 
#include <iostream>
#include <cstring>
#include <vector>
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
    AdaptiveHuffmanNode(){
        //defualt constructor
        //set all attributes to nullptr, NULL, or 0;
    }
    
};


class AdaptiveHuffman{
private:
    AdaptiveHuffmanNode* root;
    AdaptiveHuffmanNode* zero;
    char* alphabet_arr[NUM_OF_CHARACTERS]; //array of character pointers
    string message; 
    string encoded;

public:
    AdaptiveHuffman(){};
        //defualt constructor
    AdaptiveHuffman(string alphabet){};
        //convert string into char of array using strcpy
        //copy into string into alphabet_arr
        //root node default 0 node
    string encode(string message){};
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
    string decode(string encoded){};
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
    void newCharacter(){};
    AdaptiveHuffmanNode* checkSibling(AdaptiveHuffmanNode* node){};
        //takes 0 node as input and returns huffman
        //if huffman violates sibling property
        //  rearrange nodes ADD HERE
        //  if (leader is parent of count)
        //      JUST increment parent count by one, up to the root node
        //  else if
        //      swap position with leader 
        //else (if no violation)
        //  return node 
};

//TREE METHODS:
AdaptiveHuffman::AdaptiveHuffman(){
    this->root=zero=nullptr;
    this->alphabet_arr[NUM_OF_CHARACTERS]={0};
    this->message=encoded="";
}
AdaptiveHuffman::AdaptiveHuffman(string message){
    this->root= new AdaptiveHuffmanNode(); //create default zero node which is also root
    this->message=message;
    for (int i = 0; i < NUM_OF_CHARACTERS; i++){
        alphabet_arr[0]->zero;
    } 
}

//can use .length to get amount of char in string

//NODE METHODS:
AdaptiveHuffmanNode::AdaptiveHuffmanNode(){
    this->parent=left=right=prev=next=nullptr;
    this->count=0;
    this->character=NULL;
}
