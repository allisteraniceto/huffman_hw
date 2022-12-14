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
const int CHARACTER_SIZE=8; //size of character in 8 bit notation

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
    string pathChar;

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
        //creates alphabet array from alphabet given
        //makes alphabet elements point to zero node by defualt
    bool validateAlphabet(int);
        //validates if character is in alphabet
        //returns true if in alphabet array
        //otherwise false
    string decimalToBinary(int);
        //converts decimal value to 8 bit binary number as a string
    void pathToZeroNode(AdaptiveHuffmanNode*);
        //start from zero node and work your way up to the root node
    string reverseString(string);
        //reverse order of string
    void incrementParent(AdaptiveHuffmanNode*);
        //increments parent all the way up to the root
        //checks leader and sibiling property before incrementing
    AdaptiveHuffmanNode* checkLeader(AdaptiveHuffmanNode*);
        //checks if leader is parent or not
        //if leader is parent, just increment
        //if leader is not parent, swap nodes
    AdaptiveHuffmanNode* getLeader(AdaptiveHuffmanNode*);
        //gets leader that is in front
    void swapNodes(AdaptiveHuffmanNode*, AdaptiveHuffmanNode*);
        //swap nodes if leader is not parent
        //5 cases:
        // -siblings
        // -right right
        // -left left
        // -right left
        // -left right
    void characterAgain(int);
        //if character is encountered again, increment character node
        //use alphabet_arr pointer array to get to character node
        //check sibling property
        //then increment parent
    void pathToCharacterAgain(AdaptiveHuffmanNode*);
        //int binaryToInt(string); //can use stoi() - string to int function

};

//TREE METHODS:
AdaptiveHuffman::AdaptiveHuffman(){
    this->root=this->zero=nullptr;
    this->alphabet_arr[NUM_OF_CHARACTERS-1];
    this->alphabetValid[NUM_OF_CHARACTERS-1];
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
    pathToCharacterAgain(alphabet_arr[asciiVal]); //path to character first
    temp->increment();
    incrementParent(temp);
    //pathToCharacterAgain(alphabet_arr[asciiVal]);
    encoded+=pathChar;
}
void AdaptiveHuffman::swapNodes(AdaptiveHuffmanNode*n1, AdaptiveHuffmanNode*n2){
    AdaptiveHuffmanNode* temp;
    AdaptiveHuffmanNode* temp2;
    AdaptiveHuffmanNode* n1Prev;
    AdaptiveHuffmanNode* n1Next;
    AdaptiveHuffmanNode* n1Parent;
    AdaptiveHuffmanNode* n2Prev;
    AdaptiveHuffmanNode* n2Next;
    AdaptiveHuffmanNode* n2Parent;

    temp=n1->parent; //points to parents of n1 and n2 nodes
    temp2=n2->parent;

    n1Prev=n1->prev;
    n1Next=n1->next;
    n1Parent=n1->parent;

    n2Prev=n2->prev;
    n2Next=n2->next;
    n2Parent=n2->parent;    
    
    if (n1->parent->left==n1 && n2->parent->right==n2 && n1->parent==n2->parent){ //case 1: left and right children
        temp->left=n2; //swap nodes
        temp->right=n1;

        temp->next=n1; //parent now points to n1
        n1->next=n2; //n1 now points to left child
        n1->prev=temp; //n1 prev now points to parent
        n2->next=n1Next; //n2 next now points to n1 right child
        n2->prev=n1; //n2 prev now points to n1
        n1Next->prev=n2; //former n1 next now points to n2
    }
    else if(n1->parent->right==n1 && n2->parent->left==n2 && n1->parent==n2->parent){//case 2: right and left children
        temp->right=n2;
        temp->left=n1;
        
        temp->next=n2;
        n2->prev=temp;
        n2->next=n1;
        n1->prev=n2;
        n1->next=n2Next;
        n2Next->prev=n1;
    }
    else if (n1->parent->left==n1 && n2->parent->right==n2 && n1->parent!=n2->parent){//case 3: n1 left child, n2 right child swap
        temp->left=n2;
        n2->prev=n1Prev;
        n2->next=n1Next;
        n2->parent=n1Parent;

        n1Prev->next=n2;
        n1Next->prev=n2;

        temp2->right=n1;
        temp2->next=n1;
        n1->prev=n2Prev;
        n1->next=n2Next;
        n1->parent=n2Parent;
    }
    else if (n1->parent->right==n1 && n2->parent->left==n2 && n1->parent!=n2->parent){//case 4: n1 right child, n2 left child swap
        temp->right=n2; //n2 pointers changing
        temp->next=n2;
        n2->prev=n1Prev;
        n2->next=n1Next;
        n2->parent=n1Parent;

        n1Prev->next=n2;
        n1Next->prev=n2;

        temp2->left=n1; //n1 pointers changing
        n1->prev=n2Prev;
        n1->next=n2Next;
        n1->parent=n2Parent;

        n2Prev->next=n1;
        n2Next->prev=n1;
    }
    else if(n1->parent->left==n1 && n2->parent->left==n2){ //case: left left
        temp->left=n2;
        n2->prev=n1Prev;
        n2->next=n1Next;
        n2->parent=n1Parent;

        n1Prev->next=n2;
        n1Next->prev=n2;

        temp2->left=n1;
        n1->prev=n2Prev;
        n1->next=n2Next;
        n1->parent=n2Parent;

        n2Prev->next=n1;
        n2Next->prev=n1;        
    }
    else if(n1->parent->right==n1 && n2->parent->right==n2){ //case: right right
        temp->right=n2;
        temp->next=n2;
        n2->prev=n1Prev;
        n2->next=n1Next;
        n2->parent=n1Parent;

        n1Prev->next=n2;
        n1Next->prev=n2;

        temp2->right=n1;
        temp2->next=n1;
        n1->prev=n2Prev;
        n1->next=n2Next;
        n1->parent=n2Parent;

        n2Prev->next=n1;
        n2Next->prev=n1;
    }
}
AdaptiveHuffmanNode* AdaptiveHuffman::getLeader(AdaptiveHuffmanNode* leadNum){
    while (leadNum->prev != nullptr && leadNum->count == leadNum->prev->count) { //while node count is still the same
        leadNum=leadNum->prev; //leadNum now points to next 
    }
    return leadNum;
}
AdaptiveHuffmanNode* AdaptiveHuffman::checkLeader(AdaptiveHuffmanNode* node){ //from zero up to root
    AdaptiveHuffmanNode* leader;
    if (node->prev==nullptr){ //root node
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
    else {
        node->parent->increment();
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
void AdaptiveHuffman::pathToCharacterAgain(AdaptiveHuffmanNode* charNode){
    pathChar=""; //resets path to character
    AdaptiveHuffmanNode* temp = charNode;
    if (temp==root){
        return;
    }
    else if (temp==temp->parent->left){ //if left child
        pathToCharacterAgain(temp->parent);
        pathChar+="0";
    }
    else if (temp==temp->parent->right){
        pathToCharacterAgain(temp->parent);
        pathChar+="1";
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
        alphabet_arr[asciiVal]->next=zero;
        encoded += decimalToBinary(asciiVal);
    }
    else if (parent!=zero){ //start from the bottom
        //parent->left=newCharacter(parent->left, c);
        pathToZeroNode(zero); //get path to zero node first
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
        alphabet_arr[asciiVal]=zero->parent->right; //alphabet_arr element pointer points to character
        alphabet_arr[asciiVal]->prev=zero->parent;
        alphabet_arr[asciiVal]->next=zero;
        zero->prev=alphabet_arr[asciiVal]; //zero prev points to 0 parent child
        //parent=temp; //make parent point to top node
        zero->parent->parent->increment(); 
        incrementParent(zero->parent->parent); //just increment parent if new character, no need to worry about leader
        encoded += pathZero + decimalToBinary(asciiVal); //REMEBER* add 
    }
    return parent;
}
void AdaptiveHuffman::createAlphabetArray(){
    char* c = new char[alphabet.length()+1];
    //strcpy_s(c,alphabet.length()+1, alphabet.c_str());
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
    //strcpy_s(msg, message.length()+1, message.c_str()); //convert string into char array
    strcpy(msg, message.c_str());
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
    AdaptiveHuffmanNode* temp = root;
    int asciiVal=0;
    char c;
    char* enc = new char[encoded.length()];
    //strcpy_s(enc, encoded.length()+1, encoded.c_str()); //convert string to char array
    strcpy(enc, encoded.c_str());
    for (int i=0; i<encoded.length(); i++){
        string binary="";
        if (temp==zero){ //if temp hits zero node
            for (int j=i; j<(i+CHARACTER_SIZE); j++){ //get next 8 bits
                binary+=enc[j];
            }
            asciiVal=stoi(binary, 0, 2);
            c=asciiVal; //convert ascii to char using assignment operator
            root=newCharacter(root, c);
            decoded+=c; //add character to decoded
            i+=7; //skip next 8 bits
            temp=root; //go back to root
        }
        else if (temp->character != 0){ //if temp hits a character node
            asciiVal=temp->character;
            characterAgain(asciiVal);
            c=asciiVal;
            decoded+=c;
            temp=root; //go back to root
            i -= 1; 
        }
        else{
            if (enc[i]=='0'){
                temp=temp->left;
            }
            else if (enc[i]=='1'){
                temp=temp->right;
            }
        }
    }
    return decoded;
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