How it works?

In order to successfully run cweather.c cURL and JSON libraries dependencies will need to be installed if not already.

sudo apt install libcurl4-openssl-dev
sudo apt install libjson-c-dev

To execute cweather.c run the command gcc -o cweather cweather.c -lcurl -ljson-c

When ran, the menu shown below will be displayed.

Select the number corresponding to the action you would like to take place.

To quit select option 8.

	\n+------------------------+\n");
	|    CTheWeather Menu    |\n");
	+---+--------------------+\n");
	| 1 | Forecast           |\n");
	| 2 | Humidity           |\n");
	| 3 | Temperature        |\n");
	| 4 | Wind               |\n");
	| 5 | Location           |\n");
	| 6 | Precipitation      |\n");
	| 7 | Astronomy          |\n");
	| 8 | Quit               |\n");
	+---+--------------------+\n");
