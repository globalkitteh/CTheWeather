//  Last Revision: 12/02/2021 by Jon

// To compiile the code: gcc -o cweather cweather.c -lcurl

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

// ----------------------------------------------------------------------------

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

int main()
{
  // Gathers the weather information and stores it in JSON format to page.out
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
    /* code */
    break;
  
  case 2:
    /* code */
    break;

  case 3:
  /* code */
    break;

  case 4:
  /* code */
    break;

  case 5:
  /* code */
    break;

  case 6:
  /* code */
    break;

  case 7:
  /* code */
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
  printf("| 7 | Moon Phases        |\n");
  printf("|------------------------|\n");
  printf("| 8 | History            |\n");
  printf("+------------------------+\n");
}

void getWeather()
{
  CURL *curl_handle;
  static const char *pagefilename = "page.out";
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
