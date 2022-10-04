// The file "KeyValue.cpp" contains the definition of KeyValue class

#include <iostream>
#include <cstring>
#include "KeyValue.h"

using namespace std;

//default constructor
KeyValue::KeyValue(){
    keySize = 5;
    key = new char[keySize + 1];

    valueSize = 10;
    value = new char[valueSize + 1];
}

//parametirized constructor
KeyValue::KeyValue(const char* _key, const char* _value){
    int _keySize = strlen(_key);
    keySize = _keySize + 1;
    key = new char[keySize];
    strcpy(key, _key);

    int _valueSize = strlen(_value);
    valueSize = _valueSize + 1;
    value = new char[valueSize];
    strcpy(value, _value);
}

//copy constructor
KeyValue::KeyValue(const KeyValue& kv){
    keySize = kv.keySize;
    key = new char[keySize];
    strcpy(key, kv.key);

    valueSize = kv.valueSize;
    value = new char[valueSize];
    strcpy(value, kv.value);
}

//destructor function 
//deallocates the KeyValue's pointers to its key and value lists
KeyValue::~KeyValue(){
    delete [] key;
    delete [] value;
}

//assignment operator (a member function)
KeyValue& KeyValue::operator=(const KeyValue& kv){
    if (this != &kv){
        delete [] key;
        keySize = kv.keySize;
        key = new char[keySize];
        strcpy(key, kv.key);

        delete [] value;
        valueSize = kv.valueSize;
        value = new char[valueSize];
        strcpy(value, kv.value);
    }
    return *this;
}

//return key
char* KeyValue::GetKey() const{
    return key;
}

//return value
char* KeyValue::GetValue() const{
    return value;
}


