#include "json.h"
#include <string.h>

typedef struct JSONUtilDefinition {    
    JSON* (*read_file) (const char* filename, size_t buffer_size);   
    JSON* (*read_object) ();
    void (*write_file) ();
    void (*write_object);
} JSONUtil;


JSON* read_file(const char* filename, size_t buffer_size) {
    FILE *file;
    JSON *json = malloc(sizeof(JSON));
    char buffer[buffer_size];    
    file = fopen(filename, "r");
    char* read_data;
    do {
        //TODO provide parsing mechanism for creating entries of the json-object
        read_data = fgets(buffer, buffer_size, file);
        //printf("READ: %s", read_data);
    } while(*read_data != EOF);  
    fclose(file);
    return json;
}

JSON* read_object() {
    FILE *file;
    JSON *json = malloc(sizeof(JSON));
    //TODO provide main logic
    return json;
}

void write_file() {
    //TODO provide main logic
}

void write_object() {
    //TODO provide main logic
}