//  Last Revision: 12/04/2021 by Jon

// To compiile the code: gcc -o cweather cweather.c -lcurl -ljson-c

// If you are getting an error about #include <curl/curl.h>
// you need to run: sudo apt install libcurl4-openssl-dev

// sudo apt install libjson-c-dev

#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
#include <json-c/json.h>
#include <unistd.h>
#include <string.h>

// ----------------------------------------------------------------------------
// Prototypes
void displayMenu();
void getWeather();
void getHumidity();
void getPrecipitation();
void getWind();
void getTemp();
void getLocation();
void getAstronomy();

// ----------------------------------------------------------------------------

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

int main()
{
  // Gathers the weather information and stores it in JSON format to page.json
  getWeather();

  int repeat = 1;
  while(repeat == 1)
  {
  // Displays the interactive menu.
  displayMenu();

  int decision = 0;
  scanf("%d", &decision);
  switch (decision)
  {
  case 1:
    break;
  
  case 2:
    getLocation();
    getHumidity();
    exit(1);
    break;

  case 3:
    getLocation();
    getTemp();
    exit(1);
    break;

  case 4:
    getLocation();
    getWind();
    exit(1);
    break;

  case 5:
    getLocation();
    exit(1);
    break;

  case 6:
    getLocation();
    getPrecipitation();
    exit(1);
    break;

  case 7:
    getLocation();
    getAstronomy();
    exit(1);
    break;

  case 8:
  /* code */
    break;

  default:
    break;
  }
  }

  return 0;

}


// ----------------------------------------------------------------------------
// Function declarations

// Displays the menu that users will view to make their decision
// on what they want to view.
void displayMenu()
{
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\nWhat would you like to view for **INCLUDE LOCATION SOMEHOW***\n");
  printf("Select the number corresponding to the function you'd like to view.\n");
  printf("For example, 1 would display the Weather Condition, 2 would display Humidity, etc.\n");
  printf("\n+------------------------+\n");
  printf("| 1 | Weather Condition  |\n");
  printf("|------------------------|\n");
  printf("| 2 | Humidity           |\n");
  printf("|------------------------|\n");
  printf("| 3 | Temperature        |\n");
  printf("|------------------------|\n");
  printf("| 4 | Wind               |\n");
  printf("|------------------------|\n");
  printf("| 5 | Location           |\n");
  printf("|------------------------|\n");
  printf("| 6 | Precipitation      |\n");
  printf("|------------------------|\n");
  printf("| 7 | Astronomy          |\n");
  printf("|------------------------|\n");
  printf("| 8 | History            |\n");
  printf("+------------------------+\n");
}

void getWeather()
{
  CURL *curl_handle;
  static const char *pagefilename = "page.json";
  FILE *pagefile;
 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* init the curl session */
  curl_handle = curl_easy_init();
 
  /* set URL to get here */
  curl_easy_setopt(curl_handle, CURLOPT_URL, "https://wttr.in/?format=j1");
 
  /* Switch on full protocol/debug output while testing */
  curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);
 
  /* disable progress meter, set to 0L to enable it */
  curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
 
  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
 
  /* open the file */
  pagefile = fopen(pagefilename, "wb");
  if(pagefile) {
 
    /* write the page body to this file handle */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);
 
    /* get it! */
    curl_easy_perform(curl_handle);
 
    /* close the header file */
    fclose(pagefile);
  }
 
  /* cleanup curl stuff */
  curl_easy_cleanup(curl_handle);
 
  curl_global_cleanup();
}

void getHumidity()
{
	int arraylen, i;
	struct json_object *current_condition_obj, *current_condition_array, *current_condition_array_obj, *humidity;
	static const char filename[] = "page.json";
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
		printf("Humidity: %s%%\n", json_object_get_string(humidity));
	}
}

void getPrecipitation()
{
	int arraylen, i;
	struct json_object *current_condition_obj, *current_condition_array, *current_condition_array_obj, *precipIn, *precipMM;
	static const char filename[] = "page.json";
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
		printf("Precipitation(in): %sin\n", json_object_get_string(precipIn));
		printf("Precipitation(mm): %smm\n", json_object_get_string(precipMM));
	}

}

void getWind()
{
	int arraylen, i;
	struct json_object *current_condition_obj, *current_condition_array, *current_condition_array_obj, *windDirDegree, *windSpeedKmph, *windSpeedMiles;
	static const char filename[] = "page.json";
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
		printf("Wind Direction Degree: %s\n", json_object_get_string(windDirDegree));
		printf("Wind Speed(mph): %smph\n", json_object_get_string(windSpeedMiles));
		printf("Wind Speed(kmph): %s\nkmph", json_object_get_string(windSpeedKmph));

	}
}

void getTemp()  // Add feels like
{
	int arraylen, i;
	struct json_object *current_condition_obj, *current_condition_array, *current_condition_array_obj, *temp_F, *temp_C;
	static const char filename[] = "page.json";
	current_condition_obj = json_object_from_file(filename);
	current_condition_array = json_object_object_get(current_condition_obj, "current_condition");

	// current_condition_array is an array of objects
	arraylen = json_object_array_length(current_condition_array);

	for (i = 0; i < arraylen; i++) {
		// get the i-th object in current_condition_array
		current_condition_array_obj = json_object_array_get_idx(current_condition_array, i);

		// get the temperature attribute in the i-th object
		temp_F = json_object_object_get(current_condition_array_obj, "temp_F");
		temp_C = json_object_object_get(current_condition_array_obj, "temp_C");
		// print out the temperature attributes
		printf("Farenheit Temperature: %s F\n", json_object_get_string(temp_F));
		printf("Celsuis Temperature: %s C\n", json_object_get_string(temp_C));
	}

}

void getLocation()  
{
	int arraylen, i;
	struct json_object *nearest_area_obj, *nearest_area_array, *nearest_area_array_obj, *areaName, *region;
	struct json_object *areaName_obj, *areaNameVal, *region_obj, *regionVal;
	static const char filename[] = "page.json";
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

		// printf("area=%s\n", json_object_get_string(areaNameVal));

	// Gets the value of region
		region_obj = json_object_array_get_idx(region,0);

		regionVal = json_object_object_get(region_obj, "value");

		// printf("region=%s\n", json_object_get_string(regionVal));

    printf("Location: %s, %s\n", json_object_get_string(areaNameVal), json_object_get_string(regionVal));

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

	static const char filename[] = "page.json";
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
	printf("Moon Phase: %s\n", json_object_get_string(moon_phase_Val));

	// Gets the moonrise
	moonrise_obj = json_object_array_get_idx(moon_phase,0);
	moonrise_Val = json_object_object_get(moonrise_obj, "moonrise");
	printf("Moonrise: %s\n", json_object_get_string(moonrise_Val));

	// Gets the moonset
	moonset_obj = json_object_array_get_idx(moon_phase,0);
	moonset_Val = json_object_object_get(moonset_obj, "moonset");
	printf("Moonset: %s\n", json_object_get_string(moonset_Val));

	// Gets the sunrise
	sunrise_obj = json_object_array_get_idx(moon_phase,0);
	sunrise_Val = json_object_object_get(sunrise_obj, "sunrise");
	printf("Sunrise: %s\n", json_object_get_string(sunrise_Val));
	
	// Gets the sunset
	sunset_obj = json_object_array_get_idx(moon_phase,0);
	sunset_Val = json_object_object_get(sunset_obj, "sunset");
	printf("Sunset: %s\n", json_object_get_string(sunset_Val));

}
