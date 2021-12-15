How it works?

In order to successfully run cweather.c cURL and JSON libraries dependencies will need to be installed if not already.

sudo apt install libcurl4-openssl-dev
sudo apt install libjson-c-dev

To execute cweather.c run the command gcc -o cweather cweather.c -lcurl -ljson-c

When ran, the menu shown below will be displayed.

Select the number corresponding to the action you would like to take place.

To quit select option 8.

	printf("\n+------------------------+\n");
	printf("|    CTheWeather Menu    |\n");
	printf("+---+--------------------+\n");
	printf("| 1 | Forecast           |\n");
	printf("| 2 | Humidity           |\n");
	printf("| 3 | Temperature        |\n");
	printf("| 4 | Wind               |\n");
	printf("| 5 | Location           |\n");
	printf("| 6 | Precipitation      |\n");
	printf("| 7 | Astronomy          |\n");
	printf("| 8 | Quit               |\n");
	printf("+---+--------------------+\n");
