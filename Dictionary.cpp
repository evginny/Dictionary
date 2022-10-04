// The file "Dictionary.cpp" contains the definition of Dictionary class

#include <iostream>
#include <cstring>
#include "Dictionary.h"

using namespace std;

//default constructor
Dictionary::Dictionary(){
    currentSize = 0;
    maxSize = 2;
    pairs = new KeyValue[maxSize];
    keys = new char*[maxSize];
    values = new char*[maxSize];
}

//copy constructor
Dictionary::Dictionary(const Dictionary& d){
    currentSize = d.currentSize;
    maxSize = d.maxSize;

    pairs = new KeyValue[maxSize];
    for (int i = 0; i < currentSize; i++){
        pairs[i] = d.pairs[i];
    }
}

//destructor function 
//deallocates the dictionary's pointers to its pairs, keys, and values lists
Dictionary::~Dictionary(){
    delete [] pairs;
    for (int i = 0; i < currentSize; i++){  //deallocates all heap space 
                                            //associated with each key cstring
        delete [] keys[i];
    }
    delete [] keys;
    for (int i = 0; i < currentSize; i++){
        delete [] values[i];    //deallocates all heap space associated with 
                                //each value cstring
    }
    delete [] values;
}

//assignment operator (member function)
Dictionary& Dictionary::operator=(const Dictionary& d){
    if (this != &d){
        for (int i = 0; i < currentSize; i++){  //deallocates all heap space 
                                            //associated with each key cstring
        delete [] keys[i];
    }
        delete [] keys;
        for (int i = 0; i < currentSize; i++){  //deallocates all heap space 
                                            //associated with each value cstring
        delete [] values[i];
    }
        delete [] values;
        
        delete [] pairs;

        currentSize = d.currentSize;
        maxSize = d.maxSize;

        pairs = new KeyValue[maxSize];

        for (int i = 0; i < currentSize; i++){
            pairs[i] = d.pairs[i];
            strcpy(keys[i], d.pairs[i].GetKey());
            strcpy(values[i], d.pairs[i].GetValue());
        }
        keys = new char*[maxSize];
        values = new char*[maxSize];
    }
    return *this;
}

//returns a list of all the keys in the current Dictionary 
char** Dictionary::Keys() {
    if (currentSize != 0){
        delete [] keys;
        keys = new char*[currentSize];
        //i is an index of each pointer in the pairs array
        for (int i = 0; i < currentSize; i++){ 
            //size of key cstring of the pair with index i
            //+1 for the null termination character 
            int size = strlen(pairs[i].GetKey()) + 1;
            //every i pointer in the keys array points to corresponding 
            //dynamically allocated cstring
            keys[i] = new char[size];
            //j is an index of the each char in the key array of pair i
            for (int j = 0; j < size; j++){
                //copies key cstring of pair i to the keys with index i
                keys[i][j] = pairs[i].GetKey()[j];
            }
        }   
    }
    else {  //if current size is 0, notifies that list is empty
        cout << endl << "The key list is empty." << endl;
    }
    return keys;

}

//returns a lists of all the values in the current Dictionary
char** Dictionary::Values(){
   if (currentSize != 0){
        delete [] values;
        values = new char*[currentSize];
        ////i is an index of each pointer in the pairs array
        for (int i = 0; i < currentSize; i++){
            //size of value cstring of the pair with index i
            //+1 for the null termination character 
            int size = strlen(pairs[i].GetValue()) + 1;
            //every i pointer in the values array points to corresponding 
            //dynamically allocated cstring
            values[i] = new char[size];
            //j is an index of the each char in the value array of pair i
            for (int j = 0; j < size; j++){
                //copies value cstring of pair i to the keys with index i
                values[i][j] = pairs[i].GetValue()[j];
            }
        }   
    }
    else {  //if current size is 0, notifies that list is empty
        cout << endl << "The value list is empty." << endl;
    }
    return values;
}

//returns the total number of pairs in the Dictionary
//so returns the current number
int Dictionary::Count() const{
    return currentSize;
}

//returns the value for a given key
char* Dictionary::Get(const char* _key) const{
    char none[] = "value is not found";
    char* ptr = none;
    bool isFound = false;   //indicates if the provided key is presented in the
                            //Dictionary or not
    int index;  //to hold an index of the found key
    for (int i = 0; i < currentSize; i++){
        //compares all keys in the Dictionary with the provided key
        if (strcmp(pairs[i].GetKey(), _key) == 0){  
            index = i;
            isFound = true; //the provided key corresponds with the key 
                            //from the Dictionary
        }

    }
    if (isFound == false){  //if the provided key does not correspond with the
                            //key from the Dictionary, notifies that the key
                            //was not found
        cout << endl << "The key is not found" << endl;
    }
    return pairs[index].GetValue(); //return value cstring
}

//adds the provided key-value pair or doesn't do anything 
//if there is already a pair with the given key
void Dictionary::Add(const char* _key, const char* _value){
    bool isFound = false;   //indicates if the provided key is presented in the
                            //Dictionary or not
    for (int i = 0; i < currentSize; i++){
        //compares all keys in the Dictionary with the provided key
        if (strcmp(pairs[i].GetKey(), _key) == 0){
            isFound = true; //the provided key corresponds with the key 
                            //from the Dictionary 
        }
    }
    if (isFound == false){  //if the provided key does not correspond with the
                            //key from the Dictionary, add the provided 
                            //key-value pair to the Dictionary
        //if there are no more free space in the pair array, grow it by 3
        if (currentSize == maxSize){    
            Grow();
        }
        //creates a new object of type KeyValue with the provided key and value
        //values, and deep copies its values to the pairs list as a pair
        //with the index that corresponds to the number of current number
        //of pairs
        KeyValue kv(_key, _value);
        pairs[currentSize] = kv;
        
        //increment current number of pairs by one
        currentSize++;
    }
}

//increases the size of the Dictionary's pairs list by 3
//by creating a new, larger array of KeyValue
//and changing the Dictionary's pointer to refer to
//this new array.
void Dictionary::Grow(){
    maxSize = currentSize + 3;

    KeyValue* newList = new KeyValue[maxSize];
    for (int i = 0; i < currentSize; i++){
        newList[i] = pairs[i];
    }

    delete [] pairs;
    pairs = newList;
}

//adds the provided key-value pair or replaces the existing pair
//with the given key
void Dictionary::Replace(const char* _key,  const char* _value){
    for (int i = 0; i < currentSize; i ++){
        //checks if the provided key is already presented in the Dictionary
        //if it does, return from this member function
        if (strcmp(pairs[i].GetKey(), _key) == 0){
            KeyValue _kv(_key, _value);
            pairs[i] = _kv;
            return;
        }
    }
    //if the provided key is not presented in the Dictionary, 
    //adds the provided keey-value pair
    Add(_key, _value);
}

//removes the key-value pair with the given key
void Dictionary::Remove(const char* _key){
    bool isFound = false;   //indicates if the provided key is presented in the
                            //Dictionary or not
    int index;  //to hold an index of the found key

    for (int i = 0; i < currentSize; i++){
        if (strcmp(pairs[i].GetKey(), _key) == 0){
            isFound = true;
            index = i;
        }
    }
    if (isFound){   //if the key is found in the Dictionary,
                    //removes the correcponding key-valuepair 
        for (int j = index + 1; j < currentSize; j++){
            pairs[j - 1] = pairs[j];
        }
        currentSize--;
    }
    else {  //if the key is not found
        cout << endl << "The key is not found." << endl;
    }
}