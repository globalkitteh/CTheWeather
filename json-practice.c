// Last edited by: Jon 12/04/2021
// Temperature, humidity, precipitation, wind, location, and astronomy work

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
void getAstronomy();

int main() 
{
	getTemp();
	getHumidity();
	getPrecipitation();
	getWind();
	getLocation();
	getAstronomy();
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

		printf("area=%s\n", json_object_get_string(areaNameVal));

	// Gets the value of region
		region_obj = json_object_array_get_idx(region,0);

		regionVal = json_object_object_get(region_obj, "value");

		printf("region=%s\n", json_object_get_string(regionVal));

}

void getAstronomy()  
{
	int arraylen, i;
	struct json_object *weather_obj, *weather_array, *weather_array_obj, *moon_phase, *moonrise, *moonset, *sunrise, *sunset;
	struct json_object *moon_phase_obj, *moon_phase_Val;
	struct json_object *moonrise_obj, *moonrise_Val;
	struct json_object *moonset_obj, *moonset_Val;
	struct json_object *sunrise_obj, *sunrise_Val;
	struct json_object *sunset_obj, *sunset_Val;

	static const char filename[] = "test.json";
	weather_obj = json_object_from_file(filename);
	weather_array = json_object_object_get(weather_obj, "weather");

	// weather_array is an array of objects
	// arraylen = json_object_array_length(weather_array);

	for (i = 0; i < 1; i++) {
		// get the i-th object in weather_array
		weather_array_obj = json_object_array_get_idx(weather_array, i);

		// get the astronomy attributes in the i-th object
		moon_phase = json_object_object_get(weather_array_obj, "astronomy");

		// print out the areaName and region attributes.
		// printf("astronomy=%s\n", json_object_get_string(areaName));
		// printf("region=%s\n", json_object_get_string(region));
	}
	
	// Gets the moon_phase
	moon_phase_obj = json_object_array_get_idx(moon_phase,0);
	moon_phase_Val = json_object_object_get(moon_phase_obj, "moon_phase");
	printf("moon phase=%s\n", json_object_get_string(moon_phase_Val));

	// Gets the moonrise
	moonrise_obj = json_object_array_get_idx(moon_phase,0);
	moonrise_Val = json_object_object_get(moonrise_obj, "moonrise");
	printf("moonrise=%s\n", json_object_get_string(moonrise_Val));

	// Gets the moonset
	moonset_obj = json_object_array_get_idx(moon_phase,0);
	moonset_Val = json_object_object_get(moonset_obj, "moonset");
	printf("moonset=%s\n", json_object_get_string(moonset_Val));

	// Gets the sunrise
	sunrise_obj = json_object_array_get_idx(moon_phase,0);
	sunrise_Val = json_object_object_get(sunrise_obj, "sunrise");
	printf("sunrise=%s\n", json_object_get_string(sunrise_Val));
	
	// Gets the sunset
	sunset_obj = json_object_array_get_idx(moon_phase,0);
	sunset_Val = json_object_object_get(sunset_obj, "sunset");
	printf("susnet=%s\n", json_object_get_string(sunset_Val));

}
