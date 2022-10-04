// The file "KeyValue.h" contains the declaration of KeyValue class

using namespace std;

class KeyValue {
    public:
        //default constructor
        KeyValue();
        //parameterized constructor
        KeyValue(const char* _key, const char* _value);
        //copy constructor
        KeyValue(const KeyValue& kv);
        //destructor
        ~KeyValue();

        //assignment operator
        KeyValue& operator=(const KeyValue& kv);
        //return key
        char* GetKey() const;
        //return value
        char* GetValue() const;

    private:
        char* key;      //cstring to hold a key
        int keySize;    //number of characters in the key cstring
        char* value;    //cstring to hold a value
        int valueSize;  //number of characters in the value cstring
};