//  Last Revision: 12/02/2021 by Jon

// To compiile the code: gcc -o cweather cweather.c -lcurl

// If you are getting an error about #include <curl/curl.h>
// you need to run: sudo apt install libcurl4-openssl-dev

#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>

// ----------------------------------------------------------------------------
// Prototypes
void displayMenu();

// ----------------------------------------------------------------------------

int main()
{
    displayMenu();


    // Testing out curl function
    // https://www.devdungeon.com/content/curl-tutorial
    CURL *curl;
    CURLcode result;
    curl = curl_easy_init();

    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, "https://wttr.in/?T");

    // Perform the request which prints to stdout.
    result = curl_easy_perform(curl);


    curl_easy_cleanup(curl);
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

