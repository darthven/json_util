#include "json.h"

int main() 
{	
	JSON *json = malloc(sizeof(JSON));
	put_int(json, "key5", 23);
	put_float(json,"key2", 5.43f);
	put_char(json,"key3", 'A');
	put_string(json, "key4", "adsd");

	//Expected 23
	int res1 = get_int(json, "key5");
	printf("Result: %d\n", res1);
	//Expected -1
	int res2 = get_int(json, "key2");
	printf("Result: %d\n", res2);
	free(json);
	return 0;
}
