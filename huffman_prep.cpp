#include <iostream>
using namespace std;
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
    char* alphabet_arr[NUM_OF_CHARACTERS]; //array of character poitners
public:
    AdaptiveHuffmanNode(){
        //defualt constructor
        //set all attributes to nullptr, NULL, or 0;
    }
    AdaptiveHuffmanNode(string alphabet){
        //take alphabet string as an argument
        //
    }
    void encode(){

    }
    void decode(){

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

    //create AdaptiveHuffman object and take in alphabet string as an argument
    //if encode command
    //  call encode method
    //else if decode command
    //  call decode method
    return 0;
}

/*max heap: 
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