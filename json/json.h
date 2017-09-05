#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

template<class Type>
class Entry {
    private:
        std::string key;
        Type value;
    public:
        Entry(std::string key, Type value) 
        {
            this->key = key;     
            this->value = value;
        };              
        std::string getKey() {
            return this->key;    
        };
        Type getValue() {
            return this->value;
        };    
};


class NumberSection {
  
    public:
        std::vector<Entry<int>> integerEntries;
        std::vector<Entry<float>> floatEntries;
        std::vector<Entry<double>> doubleEntries;
        NumberSection() {};    
        ~NumberSection() {};

        std::vector<Entry<int>> getIntegerEntries() {
            return this->integerEntries;
        };

        std::vector<Entry<float>> getFloatEntries() {
            return this->floatEntries;
        };

        std::vector<Entry<double>> getDoubleEntries() {
            return this->doubleEntries;
        };

        void initSection(std::vector<Entry<int>> integerEntries) {
            this->integerEntries = integerEntries;
        };
        void initSection(std::vector<Entry<float>> floatEntries) {
            this->floatEntries = floatEntries;
        };
        void initSection(std::vector<Entry<double>> doubleEntries) {
            this->doubleEntries = doubleEntries;
        };        
};

class StringSection {
    private:
        std::vector<Entry<char>> charEntries;
        std::vector<Entry<std::string>> stringEntries;     
    public:
        StringSection() {};    
        ~StringSection() {};      
        
        std::vector<Entry<char>> getCharEntries() {
            return this->charEntries;
        };

        std::vector<Entry<std::string>> getStringEntries() {
            return this->stringEntries;
        };
     
        void initSection(std::vector<Entry<char>> charEntries) {
            this->charEntries = charEntries;
        };
        void initSection(std::vector<Entry<std::string>> stringEntries) {
            this->stringEntries = stringEntries;
        };     
};

class BooleanSection {
    private:
        std::vector<Entry<bool>> booleanEntries;     
    public:
        BooleanSection() {};    
        ~BooleanSection() {};

        std::vector<Entry<bool>> getBooleanEntries() {
            return this->booleanEntries;
        };

        void initSection(std::vector<Entry<bool>> booleanEntries) {
            this->booleanEntries = booleanEntries;
        };       
};

class ArraySection {
    private:
        std::vector<Entry<std::string>> arrayEntries;        
    public:
        ArraySection() {};    
        ~ArraySection() {};

        std::vector<Entry<std::string>> getArrayEntries() {
            return this->arrayEntries;
        };

        void initSection(std::vector<Entry<std::string>> arrayEntries) {
            this->arrayEntries = arrayEntries;
        };        
};


class JSON {
  
    public:       
        NumberSection *numberSection;
        StringSection *stringSection;
        BooleanSection *booleanSection;
        ArraySection *arraySection;     
        JSON() {};
        ~JSON() {};

        void initNumberSection(NumberSection *numberSection) {
            this->numberSection = numberSection;
        };

        void initStringSection(StringSection *stringSection) {
            this->stringSection = stringSection;
        };   

        void initBooleanSection(BooleanSection *booleanSection) {
            this->booleanSection = booleanSection;
        };

        void initArraySection(ArraySection *arraySection) {
            this->arraySection = arraySection;
        };

        std::string keys() {
            return NULL;
        };
        
        std::string values() {
            return NULL;
        }

        std::string stringify() {
            return NULL;
        };   
};


class JSONBuilder {

    private:
        JSON *json;

    public:
        JSONBuilder() {
            this->json = new JSON();
        };
        JSONBuilder* createPair(std::string key, int value) {
            Entry<int> entry(key, value);           
            this->json->numberSection->integerEntries.push_back(entry);            
            return this;
        };
        JSONBuilder* createPair(std::string key, float value) {
            Entry<float> entry(key, value);
            this->json->numberSection->getFloatEntries().push_back(entry);
            return this;          
        };
        JSONBuilder* createPair(std::string key, double value) {
            Entry<double> entry(key, value);
            this->json->numberSection->getDoubleEntries().push_back(entry);
            return this;
        };
        JSONBuilder* createPair(std::string key, bool value) {
            Entry<bool> entry(key, value);
            this->json->booleanSection->getBooleanEntries().push_back(entry);           
            return this;
        };
        JSONBuilder* createPair(std::string key, char value) {
            Entry<char> entry(key, value);
            this->json->stringSection->getCharEntries().push_back(entry);     
            return this;
        };
        JSONBuilder* createPair(std::string key, std::string value) {
            Entry<std::string> entry(key, value);
            this->json->stringSection->getStringEntries().push_back(entry);    
            return this;
        };
        JSONBuilder* createPairOfArray(std::string key, std::string value) {
            Entry<std::string> entry(key, value);
            this->json->arraySection->getArrayEntries().push_back(entry);    
            return this;
        };   
        JSONBuilder* createPairOfObject(std::string key) {  
            return this;
        };      
        JSON* build() {
            return this->json;
        };
};

class JSONParser {

};

