// Last edited by: Jon 12/04/2021
// Temperature, humidity, precipitation, wind, and location work

#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
#include <json-c/json.h>

// Command to compile: gcc -o json json.c -ljson-c

void getHumidity();
void getPrecipitation();
void getWind();
void getTemp();
void getLocation();

int main() 
{
	// getTemp();
	// getHumidity();
	// getPrecipitation();
	// getWind();
	getLocation();
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

void getTemp()  // Add feels like
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

void getLocation()  
{
	int arraylen, i;
	struct json_object *nearest_area_obj, *nearest_area_array, *nearest_area_array_obj, *areaName, *region;
	struct json_object *areaName_obj, *areaNameVal, *region_obj, *regionVal;
	static const char filename[] = "test.json";
	nearest_area_obj = json_object_from_file(filename);
	nearest_area_array = json_object_object_get(nearest_area_obj, "nearest_area");

	// nearest_area_array is an array of objects
	arraylen = json_object_array_length(nearest_area_array);

	for (i = 0; i < arraylen; i++) {
		// get the i-th object in nearest_area_array
		nearest_area_array_obj = json_object_array_get_idx(nearest_area_array, i);

		// get the areaName and region attributes in the i-th object
		areaName = json_object_object_get(nearest_area_array_obj, "areaName");
		region = json_object_object_get(nearest_area_array_obj, "region");

		// print out the areaName and region attributes.
		// printf("areaName=%s\n", json_object_get_string(areaName));
		// printf("region=%s\n", json_object_get_string(region));
	}
	
	// Gets the value of area Name

		areaName_obj = json_object_array_get_idx(areaName,0);

		areaNameVal = json_object_object_get(areaName_obj, "value");

		printf("value=%s\n", json_object_get_string(areaNameVal));

	// Gets the value of region
		region_obj = json_object_array_get_idx(region,0);

		regionVal = json_object_object_get(region_obj, "value");

		printf("value=%s\n", json_object_get_string(regionVal));

}
