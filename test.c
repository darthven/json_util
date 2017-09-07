#include "json.h"

int main() 
{	
	//Create json object
	JSON *json = malloc(sizeof(JSON));

	//Fill json with values
	put_int(json, "key5", 23);
	put_float(json,"key2", 5.43f);
	put_char(json,"key3", 'A');
	put_double(json, "key6", 6.431);
	put_bool(json, "key7", true);
	put_string(json, "key4", "string");

	//Retrieve entries of json-object
	int i1 = get_int(json, "key5");
	printf("Result: %d\n", i1);	
	int i2 = get_int(json, "key2");
	printf("Result: %d\n", i2);
	float f = get_float(json, "key2");
	printf("Result: %f\n", f);	
	char c = get_char(json, "key3");
	printf("Result: %c\n", c);	
	bool b = get_bool(json, "key7");
	printf("Result: %d\n", b);
	const char* str = get_string(json, "key4");
	printf("Result: %s\n", str);
	put_float(json, "key4", 22.22f);
	float f2 = get_float(json, "key4");
	printf("Result: %f\n", f2);


	//Define array's length
	int array_size = 5;
	//Init pointer to array of pointers (for all types of variables)
	void** array = malloc(array_size * sizeof(void*));
	printf("Init array address: %p\n", array);

	//Set addresses of the variables to the array of pointers
	array[0] = &i1;
	array[1] = &f;
	array[2] = &c;
	array[3] = &b;
	array[4] = &str;

	//Add entry with array to the json
	put_array(json, "key10", array);

	//Retrieve the pointer to the array of pointers to the defined variables
	void** res = get_array(json, "key10");	

	//Get the pointer to the string (const char *)
	const char** res_str_ptr = *(res + 4);	
	//Get the string from the pointer
	const char* res_str = *res_str_ptr;
	printf("Element[4]: %s\n", res_str);
	printf("Result array address: %p\n", res);
	
	//Init another json-object
	JSON *innerJson = malloc(sizeof(JSON));	
	printf("Init child object address: %p\n", innerJson);

	//Fill this object with new data
	put_int(json, "inner1", 10);
	put_float(json,"inner2", 3.22f);
	put_char(json,"inner3", 'I');
	put_double(json, "inner4", 1.253);
	put_bool(json, "inner5", false);
	put_string(json, "inner6", "innerString");

	//Add entry with this object to the parent object
	put_object(json, "object", innerJson);

	//Retrieve child-object from parent
	JSON *result = get_object(json, "object");
	printf("Result child object address: %p\n", result);

	//Retrieve entries of child-object
	int ii = get_int(json, "inner1");
	printf("Result: %d\n", ii);
	float fi = get_float(json, "inner2");
	printf("Result: %f\n", fi);
	char ci = get_char(json, "inner3");
	printf("Result: %c\n", ci);
	bool bi = get_bool(json, "inner5");
	printf("Result: %d\n", bi);
	const char* stri = get_string(json, "inner6");
	printf("Result: %s\n", stri);

	free(innerJson);
	innerJson = NULL;
	free(json);
	json = NULL;
	return 0;
}
