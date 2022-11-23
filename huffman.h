#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <cstring>
#include <algorithm> //contains reverse function
using namespace std;

//remember*: to output path to character, start from the character node all the way up
//default all characters point to 0 node

//Adaptive Huffman Prep

//./huff.exe encode alpha.txt message.txt.encoded - message.txt.encoded
//./huff.exe decode alpha.txt message.txt.decoded - message.txt.decoded

const int NUM_OF_CHARACTERS=256; //number of ascii characters
const int NUM_OF_ARGUMENTS=4; //# of arguments

class AdaptiveHuffmanNode{
public:
    AdaptiveHuffmanNode* parent; //pointer to parent
    AdaptiveHuffmanNode* left; //pointer to left node
    AdaptiveHuffmanNode* right; //pointer to right node
    AdaptiveHuffmanNode* prev; //pointer to prev node in thread
    AdaptiveHuffmanNode* next; //pointer to next node in thread
    int count;
    char character;
    AdaptiveHuffmanNode(int);
        //defualt constructor
        //set all attributes to nullptr, NULL, or 0;
    AdaptiveHuffmanNode(int, char);
        //overloaded constructor that takes in count and character to put in node
    char getCharacter(){
        return character;
    }
    void setCharacter(char character){
        this->character=character;
    }
    void setNext(AdaptiveHuffmanNode* node){
        this->next=node;
    }
    void increment(){
        count+=1;
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
    string decoded;
    string pathZero;

public:
    AdaptiveHuffman();
        //defualt constructor
    AdaptiveHuffman(string);
        //convert string into char of array using strcpy
        //copy into string into alphabet_arr
        //root node default 0 node
    AdaptiveHuffmanNode* newCharacter(AdaptiveHuffmanNode*, char);
    string encode(string);
        //message string as a parameter and returns encoded message
        //copy message into char array
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
    void createAlphabetArray();
    bool validateAlphabet(int);
    bool checkLeader();
    string decimalToBinary(int);
    void pathToZeroNode(AdaptiveHuffmanNode*);
        //start from zero node and work your way up to the root node
    string reverseString(string);
    void incrementParent(AdaptiveHuffmanNode*);
    AdaptiveHuffmanNode* checkLeader(AdaptiveHuffmanNode*);
    AdaptiveHuffmanNode* getLeader(AdaptiveHuffmanNode*);
        //gets leader that is in front
    void swapNodes(AdaptiveHuffmanNode*, AdaptiveHuffmanNode*);
    void characterAgain(int);

};

//TREE METHODS:
AdaptiveHuffman::AdaptiveHuffman(){
    this->root=this->zero=nullptr;
    this->alphabet_arr[NUM_OF_CHARACTERS];
    this->alphabetValid[NUM_OF_CHARACTERS];
    this->message=this->encoded="";
}
AdaptiveHuffman::AdaptiveHuffman(string alphabet){
    this->zero= new AdaptiveHuffmanNode(0); //create default zero node which is also root
    this->root=zero;
    this->alphabet=alphabet;
    for (int i = 0; i < NUM_OF_CHARACTERS; i++){ //all pointers in alphabet array point to zero node
        alphabet_arr[i]=zero;
    }
    this->message=this->encoded="";
}
void AdaptiveHuffman::characterAgain(int asciiVal){
    AdaptiveHuffmanNode* temp=alphabet_arr[asciiVal];
    temp->increment();
    incrementParent(temp);
}
void AdaptiveHuffman::swapNodes(AdaptiveHuffmanNode*n1, AdaptiveHuffmanNode*n2){
    AdaptiveHuffmanNode* temp;
    if (n1->parent->left==n1 && n2->parent->right==n2){ //case 1: left and right children
        temp=n1->parent;
        temp->left=n2; //swap nodes
        temp->right=n1;
        n2->parent->next=n1; //parent now points to n1
        n1->next=n2; //n1 now points to left child
        n1->prev=n2->parent; //n1 prev now points to parent
        n2->next=n1->right; //n2 next now points to n1 right child
        n2->prev=n1; //n2 prev now points to n1
    }
    else if(n1->parent->right==n1 && n2->parent->left==n2){//case 2: right and left child
        n1->parent->right=n2;
        n2->parent->left=n1;
        n1->parent->next=n2;
        n2->prev=n2->parent;
        n2->next=n1;
        n1->prev=n2;
        n1->next=n2->right;
        n2->right->prev=n1;
    }
    //if (n2->parent->left==n2){//if node 1 is a left child
    //    n2->parent->left=n1;
    //}
    //else if(n1->parent->right==n1){//if node 1 is a right child
    //    n2->parent->right=n1;
    //}   
}
AdaptiveHuffmanNode* AdaptiveHuffman::getLeader(AdaptiveHuffmanNode* leadNum){
    while (leadNum->count==leadNum->prev->count){ //while node count is still the same
        leadNum=leadNum->prev; //leadNum now points to next 
    }
    return leadNum;
}
AdaptiveHuffmanNode* AdaptiveHuffman::checkLeader(AdaptiveHuffmanNode* node){ //from zero up to root
    AdaptiveHuffmanNode* leader;
    if (node->prev==nullptr){
        return node;
    }
    else if (node->count > node->prev->count){ //2 cases (checking from bottom to root, instead of root to zero, so use >)
        leader=getLeader(node->prev);
        if(node->parent == leader){ //if leader is parent just increment
            node->parent->increment();
        }
        else if (node->parent != leader){//if leader is not parent, swap nodes
            swapNodes(node, leader);
            node->parent->increment();
        }
    }
    return node;
}
string reverseString(string s){
    reverse(s.begin(), s.end());
    return s;
}
void AdaptiveHuffman::incrementParent(AdaptiveHuffmanNode* node){
    if (node->parent!=nullptr){ //increment all the way up to the root
        node=checkLeader(node);
        incrementParent(node->parent);
    }
    return;
}
void AdaptiveHuffman::pathToZeroNode(AdaptiveHuffmanNode* zero){
    pathZero=""; //reset path to zero;
    if (zero==root){
        return;
    }
    else if (zero==zero->parent->left){ //if left child
        pathToZeroNode(zero->parent);
        pathZero+="0"; //put it after recurseive def to get correct order (otherwise reversed)
    }
    else if (zero==zero->parent->right){ //if right child
        pathToZeroNode(zero->parent);
        pathZero+="1";
    }
}
string AdaptiveHuffman::decimalToBinary(int ascii){ //from: Program for decimal to binary conversion. GeeksforGeeks. (2022, July 17). Retrieved November 13, 2022, from https://www.geeksforgeeks.org/program-decimal-binary-conversion/ 
    string binary= "";
    for (int i=7; i>=0; i--){ //8 bit representation
        int k = ascii >> i;
        if (k & 1)
            binary+="1";
        else
            binary+="0";
    }
    return binary;
}
AdaptiveHuffmanNode* AdaptiveHuffman::newCharacter(AdaptiveHuffmanNode* parent, char c){
    int asciiVal=(unsigned int)c;
    AdaptiveHuffmanNode* temp;
    if (parent==zero){ //base case: root points to zero node
        parent= new AdaptiveHuffmanNode(1);   //new root node
        parent->left=zero;                    //left points to zero node
        parent->right= new AdaptiveHuffmanNode(1, c); //right child with character
        zero->parent=parent;                  //zero parent now points to root
        parent->next=parent->right;             //next is set to the right child
        parent->right->next=zero;       //right child next set to zero
        zero->prev=parent->right;             //zero prev points to right child
        parent->right->prev=parent;             //right child prev to parent;
        alphabet_arr[asciiVal]=parent->right; //ascii value array element will point to character node
        alphabet_arr[asciiVal]->parent=parent;
        encoded += "0" + decimalToBinary(asciiVal);
    }
    else if (parent!=zero){ //start from the bottom
        //parent->left=newCharacter(parent->left, c);
        temp = zero->parent; //temp pointer to zero parent
        zero->parent=new AdaptiveHuffmanNode(1);
        zero->parent->right=new AdaptiveHuffmanNode(1, c);
        zero->parent->parent=temp; //new node parent is original parent no
        zero->parent->right->parent=zero->parent; //right child is now has a parent
        temp->left=zero->parent; //original parent now points to new parent
        temp->left->left=zero; //left child points to zero node
        temp->right->next=zero->parent;
        zero->parent->next=zero->parent->right;
        zero->parent->prev=temp->right; //new parent node prev points to right child
        alphabet_arr[asciiVal]->next=zero;
        alphabet_arr[asciiVal]=zero->parent->right; //alphabet_arr element pointer points to character
        alphabet_arr[asciiVal]->prev=zero->parent;
        zero->prev=alphabet_arr[asciiVal]; //zero prev points to 0 parent child
        //parent=temp; //make parent point to top node
        zero->parent->parent->increment(); 
        incrementParent(zero->parent->parent); //just increment parent if new character, no need to worry about leader
        pathToZeroNode(zero);
        encoded += pathZero + decimalToBinary(asciiVal); //REMEBER* add 
    }
    return parent;
}
void AdaptiveHuffman::createAlphabetArray(){
    char* c = new char[alphabet.length()+1];
    strcpy(c, alphabet.c_str());
    for (int i=0; i<alphabet.length(); i++){
        int asciiVal=(unsigned int)c[i]; //get ascii value from 1st character in alphabet (type cast character)
        alphabetValid[asciiVal]=c[i];
    }
}
bool AdaptiveHuffman::validateAlphabet(int asciiVal){
    createAlphabetArray();
    if (alphabetValid[asciiVal]==0) //if character not found in element, return false
        return false;
    return true; //else true
}
string AdaptiveHuffman::encode(string message){
    char* msg = new char[message.length()];
    strcpy(msg, message.c_str()); //convert string into char array
    for (int i=0; i < message.length(); i++){
        int asciiVal=(unsigned int)msg[i];
        if(validateAlphabet(asciiVal)){ //while character is in alphabet
            if (alphabet_arr[asciiVal]==zero){ //if alphabet char pointer points to zero, new character!!
                root=newCharacter(root, msg[i]);
            }
            else if (alphabet_arr[asciiVal]!=zero){//if character is encoutner again
                characterAgain(asciiVal);
            }
        }
        else{
            cout << "not in alphabet!" << endl;
        }
    }
    return this->encoded;
}
string AdaptiveHuffman::decode(string encoded){
    char* enc = new char[message.length()];
    strcpy(enc, encoded.c_str()); //convert string to char array
    for (int i=0; i<encoded.length(); i++){
        
    }
    return this->decoded;
}

//can use .length to get amount of char in string

//NODE METHODS:
AdaptiveHuffmanNode::AdaptiveHuffmanNode(int count){
    this->parent=left=right=prev=next=nullptr;
    this->count=count;
    this->character=0;
}
AdaptiveHuffmanNode::AdaptiveHuffmanNode(int count, char character){
    this->parent=left=right=prev=next=nullptr;
    this->count=count;
    this->character=character;
}

#endif