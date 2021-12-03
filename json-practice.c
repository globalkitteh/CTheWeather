#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
#include <json-c/json.h>


void getHumidity();
void getPrecipitation();

int main() 
{
	// getHumidity();
	getPrecipitation();
	return 0;
}


void getHumidity()
{
	int arraylen, i;
	struct json_object *current_condition_obj, *current_condition_array, *current_condition_array_obj, *humidity;
	static const char filename[] = "test.json";
	current_condition_obj = json_object_from_file(filename);
	current_condition_array = json_object_object_get(current_condition_obj, "current_condition");

	// current_condition_array is an array of objects
	arraylen = json_object_array_length(current_condition_array);

	for (i = 0; i < arraylen; i++) {
		// get the i-th object in current_condition_array
		current_condition_array_obj = json_object_array_get_idx(current_condition_array, i);
		// get the humidity attribute in the i-th object
		humidity = json_object_object_get(current_condition_array_obj, "humidity");
		// print out the humidity attribute
		printf("Humidity=%s\n", json_object_get_string(humidity));
	}
}

void getPrecipitation()
{
	int arraylen, i;
	struct json_object *current_condition_obj, *current_condition_array, *current_condition_array_obj, *precipIn, *precipMM;
	static const char filename[] = "test.json";
	current_condition_obj = json_object_from_file(filename);
	current_condition_array = json_object_object_get(current_condition_obj, "current_condition");

	// current_condition_array is an array of objects
	arraylen = json_object_array_length(current_condition_array);

	for (i = 0; i < arraylen; i++) {
		// get the i-th object in current_condition_array
		current_condition_array_obj = json_object_array_get_idx(current_condition_array, i);

		// get the precipitation attribute in the i-th object
		precipIn = json_object_object_get(current_condition_array_obj, "precipInches");
		precipMM = json_object_object_get(current_condition_array_obj, "precipMM");
		// print out the precipitation attributes
		printf("precipInches=%s\n", json_object_get_string(precipIn));
		printf("precipMM=%s\n", json_object_get_string(precipMM));
	}
}
