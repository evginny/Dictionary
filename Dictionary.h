// The file "Dictionary.h" contains the declaration of Dictionary class


#include <iostream>
#include "KeyValue.h"

using namespace std;

class Dictionary{
    
    public:
        //default constructor
        Dictionary();
        //copy constructor
        Dictionary(const Dictionary& d);
        //destructor
        ~Dictionary();

        //assignment operator
        Dictionary& operator=(const Dictionary& d);

        //returns a list of all the keys in the current Dictionary
        char** Keys();

        //returns a lists of all the values in the current Dictionary
        char** Values();

        //returns the total number of pairs in the Dictionary
        int Count() const; //

        //returns the value for a given key
        char* Get(const char* _key) const; //

        //adds the provided key-value pair or doesn't do anything 
        //if there is already a pair with the given key
        void Add(const char* _key,const char* _value); //
        void Grow();

        //adds the provided key-value pair or replaces the existing pair with
        //the given key
        void Replace(const char* _key,  const char* _value); //

        //removes the key-value pair with the given key
        void Remove(const char* _key); //

    private:
        char** keys;
        char** values;
        KeyValue* pairs;
        int maxSize;
        int currentSize;
};
