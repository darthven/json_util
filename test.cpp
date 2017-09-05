#include "json/json.h"
#include <iostream>

int main() {

    std::vector<int> array = {1, 5, 2};

    JSONBuilder *builder = new JSONBuilder();

    JSON *json = builder->createPair("number", 4)->build();


    std::cout << json->numberSection->integerEntries.at(0).getKey() << std::endl;
    std::cout << json->numberSection->integerEntries.at(0).getValue() << std::endl;
  
    return 0;
}