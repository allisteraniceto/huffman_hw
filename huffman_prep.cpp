#include <iostream>
#include <vector>
using namespace std;
//Adaptive Huffman Prep

//./huff.exe encode alpha.txt message.txt.encoded - message.txt.encoded
//./huff.exe decode alpha.txt message.txt.decoded - message.txt.decoded

const int NUM_OF_CHARACTERS=256; //number of ascii characters
const int NUM_OF_ARGUMENTS=4; //# of arguments

class AdaptiveHuffmanTree{
private:
    AdaptiveHuffmanNode* root;
    char* alphabet_arr[NUM_OF_CHARACTERS]; //array of character pointers
    string message; 
    string encode;
    string decode;

public:
    AdaptiveHuffmanTree(){ //defualt constructor
        this->root=nullptr;
    }
    AdaptiveHuffmanTree(string alphabet){
        //convert string into char of array using strcpy
        //copy into string into alphabet_arr
        //root node default 0 node
    }
    string encode(string message){
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
    }
    string decode(string encoded){
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
    }
    void newCharacter(){

    }
    AdaptiveHuffmanNode* checkSibling(AdaptiveHuffmanNode* node){
        //takes 0 node as input and returns huffman
        //if huffman violates sibling property
        //  rearrange nodes ADD HERE
        //  if (leader is parent of count)
        //      JUST increment parent count by one, up to the root node
        //  else if
        //      swap position with leader 
        //else (if no violation)
        //  return node 
    }

};
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
    return 0;
}

/*
-largest value (# of characters) on top
-create array of characters (0's or 1's) from right to left
-nodes have counter and character attributes

0 node will always be at the bottom
-0 node contains characters that havent been used yet
-backbone like structure
-when you encounter zero node, next 8 bits are ascii value of character

how array (thread) is enconded:
-path to 0 node or a character
    0 left, 1 right
-if (first encounter)
    path to 0 node, then ascii value of character 
-else if (encounter again)
    path to character, then 1

huffman tree:
    encoding
    -when encountering a new character, pull character from zero node and create 2 new nodes on top of 0 node
        -first encounter will be ascii value in binary
        -new nodes will have value of 1 by default
    -sibling property
        if (leader is parent of count)
            just increment parent node
        else if (leader is NOT parent)
            swap position with sibling
    -when a character is encountered again, increment character's parent count by 1
    -after every encounter, increment parent count by 1 up along the tree.

    decoding
    -start with zero node
    -first few bits are the path to the root node
    -when you encounter 0 node, next 8 bits is ascii value character
    -make 2 new nodes on top with default value one 1, output character
        if new node
            path to root node starts at 0
        else if character is encountered again
            path to character
    -after every character decode, check sibling property for any violations
        if (sibling violation)
            swap positions with the leader
        else if (NO sibling violations)
            increment parent count by 1, up along the tree 
*/