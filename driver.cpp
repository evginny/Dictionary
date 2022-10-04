// The file "driver.cpp" demonstrates all possible operations that users can 
// perform with the dictionary
#include <iostream>
#include <cstring>
#include "Dictionary.h"

using namespace std;

int main(){
     Dictionary d;

     cout << endl << endl
          << "Test Dictionary functions." << endl << endl;
    
     cout << "Add new pairs to the Dictionary." << endl;
     d.Add("key1", "value1");
     d.Add("key2", "value2");
     d.Add("key3", "value3");
     d.Add("key4", "value4");
     d.Add("key5", "value5");
    

     cout << endl
          << "The total number of pairs in the Dictionary is "
          << d.Count() << "." << endl << endl;
     
     cout  << "Key List:" << endl;
     for (int i = 0; i < d.Count(); i++){
          cout << "Key " << i + 1 << ": " 
               << d.Keys()[i] << endl;
     }    
     cout << endl;

     cout  << "Value List:" << endl;
     for (int i = 0; i < d.Count(); i++){
          cout << "Vlaue " << i + 1 << ": " 
               << d.Values()[i] << endl;
     } 
    
     cout << endl << endl
         << "Print out the value for the key \"key2\"." << endl;
     cout << "The value is \"" << d.Get("key2") << "\".";

     cout << endl << endl
          << "Replace the value for the key \"key3\"." << endl;

     d.Replace("key3", "replace value3");

     cout << endl
          << "Print out the value for the key \"key3\"." << endl;
     cout << "The value is \"" << d.Get("key3") << "\"." << endl;

     cout << endl << endl
          << "Replace function with key that does not exist just adds new pair."
          << endl;
     d.Replace("key6", "value6");

     cout << endl
          << "The total number of pairs in the Dictionary is "
          << d.Count() << "." << endl << endl;
     
     cout  << "Key List:" << endl;
     for (int i = 0; i < d.Count(); i++){
          cout << "Key " << i + 1 << ": " 
               << d.Keys()[i] << endl;
     }    
     cout << endl;

     cout  << "Value List:" << endl;
     for (int i = 0; i < d.Count(); i++){
          cout << "Vlaue " << i + 1 << ": " 
               << d.Values()[i] << endl;
     } 

     cout << endl << endl
          << "Remove the pair with the key \"key1\" from the Dictionary."
          << endl;
     d.Remove("key1");
     cout << endl << endl
          << "The total number of pairs in the Dictionary is "
          << d.Count() << "." << endl << endl;
    
     cout  << "Key List:" << endl;
     for (int i = 0; i < d.Count(); i++){
          cout << "Key " << i + 1 << ": " 
               << d.Keys()[i] << endl;
     }    
     cout << endl;

     cout  << "Value List:" << endl;
     for (int i = 0; i < d.Count(); i++){
          cout << "Vlaue " << i + 1 << ": " 
               << d.Values()[i] << endl;
     } 
     
}

    