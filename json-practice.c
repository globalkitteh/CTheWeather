// Last edited by: Jon 12/02/2021
// Temperature, humidity, precipitation, and wind work

#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
#include <json-c/json.h>


void getHumidity();
void getPrecipitation();
void getWind();
void getTemp();

int main() 
{
	getTemp();
	getHumidity();
	getPrecipitation();
	getWind();
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

void getWind()
{
	int arraylen, i;
	struct json_object *current_condition_obj, *current_condition_array, *current_condition_array_obj, *windDirDegree, *windSpeedKmph, *windSpeedMiles;
	static const char filename[] = "test.json";
	current_condition_obj = json_object_from_file(filename);
	current_condition_array = json_object_object_get(current_condition_obj, "current_condition");

	// current_condition_array is an array of objects
	arraylen = json_object_array_length(current_condition_array);

	for (i = 0; i < arraylen; i++) {
		// get the i-th object in current_condition_array
		current_condition_array_obj = json_object_array_get_idx(current_condition_array, i);

		// get the wind attributes in the i-th object
		windDirDegree = json_object_object_get(current_condition_array_obj, "winddirDegree");
		windSpeedMiles = json_object_object_get(current_condition_array_obj, "windspeedMiles");
		windSpeedKmph = json_object_object_get(current_condition_array_obj, "windspeedKmph");


		// print out the wind attributes
		printf("winddirDegree=%s\n", json_object_get_string(windDirDegree));
		printf("windspeedMiles=%s\n", json_object_get_string(windSpeedMiles));
		printf("windspeedKmph=%s\n", json_object_get_string(windSpeedKmph));

	}
}

void getTemp()
{
	int arraylen, i;
	struct json_object *current_condition_obj, *current_condition_array, *current_condition_array_obj, *temp_F, *temp_C;
	static const char filename[] = "test.json";
	current_condition_obj = json_object_from_file(filename);
	current_condition_array = json_object_object_get(current_condition_obj, "current_condition");

	// current_condition_array is an array of objects
	arraylen = json_object_array_length(current_condition_array);

	for (i = 0; i < arraylen; i++) {
		// get the i-th object in current_condition_array
		current_condition_array_obj = json_object_array_get_idx(current_condition_array, i);

		// get the precipitation attribute in the i-th object
		temp_F = json_object_object_get(current_condition_array_obj, "temp_F");
		temp_C = json_object_object_get(current_condition_array_obj, "temp_C");
		// print out the precipitation attributes
		printf("temp_F=%s\n", json_object_get_string(temp_F));
		printf("temp_C=%s\n", json_object_get_string(temp_C));
	}

}
