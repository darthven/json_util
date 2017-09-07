#include <stdlib.h>
#include <stdio.h>

#ifndef __cplusplus
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif

typedef struct TypeDefinition
{
	enum {INT = 1, FLOAT = 2, DOUBLE = 3, BOOL = 4, CHAR = 5, STRING = 6} tag;  
	union
	{
		int int_value;
		float float_value;
		double double_value;
		bool bool_value;
		char char_value;
		const char* string_value;	
	} storage;
	
} Type;

typedef struct EntryDefinition
{
	const char* key;
	Type value;
} Entry;

typedef struct JSONDefinition
{
	Entry entries[256];	
	const int (*get_free_index) (struct JSONDefinition json);
	void (*put_int) (struct JSONDefinition json, const char* key, 
	 const int value);
	void (*put_float) (struct JSONDefinition json, const char* key, 
	 const float value);
	void (*put_double) (struct JSONDefinition json, const char* key,
	 const double value);
	void (*put_bool) (struct JSONDefinition json, const char* key, 
	 const bool value);
	void (*put_char) (struct JSONDefinition json, const char* key,
	 const char value);
	void (*put_string) (struct JSONDefinition json, const char* key, 
	 const char* value);
	int (*get_int) (struct JSONDefinition json, const char* key);	
} JSON;

const int get_free_index(JSON *json) 
{
	Entry *entry = json->entries;
	int index = 0;	
	while(entry) {		
		if(entry->value.tag == 0) {
			return index;
		}
		index++;
		entry++;
	}
	return -1;
 }

void put_int(JSON *json, const char* key, const int value)
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.int_value = value;
	entry.value.tag = INT;
	json->entries[get_free_index(json)] = entry;
}

void put_float(JSON *json, const char* key, const float value)
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.float_value = value;
	entry.value.tag = FLOAT;	
	json->entries[get_free_index(json)] = entry;
}

void put_double(JSON *json, const char* key, const double value) 
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.double_value = value;
	entry.value.tag = DOUBLE;
	json->entries[get_free_index(json)] = entry;
}

void put_char(JSON *json, const char* key, const char value)
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.char_value = value;
	entry.value.tag = CHAR;
	json->entries[get_free_index(json)] = entry;
}

void put_string(JSON *json, const char* key, const char* value) 
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.string_value = value;
	entry.value.tag = STRING;	
	json->entries[get_free_index(json)] = entry;
}

int get_int(JSON *json, const char* key) 
{
	Entry *entries = json->entries;
	while(entries->value.tag != 0)
	{		
		if(entries->key == key && entries->value.tag == 1) 
		{			
			return entries->value.storage.int_value;
		}
		entries++;
	}	
	return -1;
}	

