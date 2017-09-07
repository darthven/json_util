#include <stdlib.h>
#include <stdio.h>

#ifndef __cplusplus
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif

typedef struct TypeDefinition
{
	enum {INT = 1, FLOAT = 2, DOUBLE = 3, BOOL = 4, CHAR = 5,
		 STRING = 6, ARRAY = 7, OBJECT = 8} tag;
	union
	{
		int int_value;
		float float_value;
		double double_value;
		bool bool_value;
		char char_value;
		const char* string_value;	
		void** array_value;
		struct JSONDefinition *object_value;
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
} JSON;


const int get_free_index(JSON *json, const char* key) 
{
	Entry *entry = json->entries;
	int index = 0;	
	while(entry) {		
		if(entry->value.tag == 0 || entry->key == key) {
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
	json->entries[get_free_index(json, key)] = entry;	
}

void put_float(JSON *json, const char* key, const float value)
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.float_value = value;
	entry.value.tag = FLOAT;	
	json->entries[get_free_index(json, key)] = entry;
}

void put_double(JSON *json, const char* key, const double value) 
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.double_value = value;
	entry.value.tag = DOUBLE;
	json->entries[get_free_index(json, key)] = entry;
}

void put_bool(JSON *json, const char* key, const bool value)
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.bool_value = value;
	entry.value.tag = BOOL;
	json->entries[get_free_index(json, key)] = entry;
}

void put_char(JSON *json, const char* key, const char value)
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.char_value = value;
	entry.value.tag = CHAR;
	json->entries[get_free_index(json, key)] = entry;
}

void put_string(JSON *json, const char* key, const char* value) 
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.string_value = value;
	entry.value.tag = STRING;	
	json->entries[get_free_index(json, key)] = entry;
}

void put_array(JSON *json, const char* key, void** value) 
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.array_value = value;
	entry.value.tag = ARRAY;	
	json->entries[get_free_index(json, key)] = entry;
}

void put_object(JSON *json, const char* key, JSON *value) 
{
	Entry entry;	
	entry.key = key;
	entry.value.storage.object_value = value;
	entry.value.tag = OBJECT;	
	json->entries[get_free_index(json, key)] = entry;
}


const int get_int(JSON *json, const char* key) 
{
	Entry *entries = json->entries;
	while(entries->value.tag != 0)
	{		
		if(entries->key == key && entries->value.tag == INT) 
		{			
			return entries->value.storage.int_value;
		}
		entries++;
	}	
	return -1;
}	

const float get_float(JSON *json, const char* key) 
{
	Entry *entries = json->entries;
	while(entries->value.tag != 0)
	{		
		if(entries->key == key && entries->value.tag == FLOAT) 
		{			
			return entries->value.storage.float_value;
		}
		entries++;
	}	
	return -1.0f;
}	


const double get_double(JSON *json, const char* key) 
{
	Entry *entries = json->entries;
	while(entries->value.tag != 0)
	{		
		if(entries->key == key && entries->value.tag == DOUBLE) 
		{			
			return entries->value.storage.double_value;
		}
		entries++;
	}	
	return -1.0;
}	

const bool get_bool(JSON *json, const char* key) 
{
	Entry *entries = json->entries;
	while(entries->value.tag != 0)
	{		
		if(entries->key == key && entries->value.tag == BOOL) 
		{			
			return entries->value.storage.bool_value;
		}
		entries++;
	}	
	return -1;
}	

const char get_char(JSON *json, const char* key) 
{
	Entry *entries = json->entries;
	while(entries->value.tag != 0)
	{		
		if(entries->key == key && entries->value.tag == CHAR) 
		{			
			return entries->value.storage.char_value;
		}
		entries++;
	}	
	return '\0';
}	

const char* get_string(JSON *json, const char* key) 
{
	Entry *entries = json->entries;
	while(entries->value.tag != 0)
	{		
		if(entries->key == key && entries->value.tag == STRING) 
		{			
			return entries->value.storage.string_value;
		}
		entries++;
	}	
	return "\0";
}

void** get_array(JSON *json, const char* key) 
{
	Entry *entries = json->entries;
	while(entries->value.tag != 0)
	{		
		if(entries->key == key && entries->value.tag == ARRAY) 
		{			
			return entries->value.storage.array_value;
		}
		entries++;
	}	
	return NULL;
}

JSON* get_object(JSON *json, const char* key) 
{
	Entry *entries = json->entries;
	while(entries->value.tag != 0)
	{		
		if(entries->key == key && entries->value.tag == OBJECT) 
		{			
			return entries->value.storage.object_value;
		}
		entries++;
	}	
	return NULL;
}