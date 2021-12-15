How it works?

In order to successfully run cweather.c cURL and JSON libraries dependencies will need to be installed if not already.

sudo apt install libcurl4-openssl-dev
sudo apt install libjson-c-dev

To execute cweather.c run the command gcc -o cweather cweather.c -lcurl -ljson-c

When ran, the menu shown below will be displayed.

Select the number corresponding to the action you would like to take place.

To quit select option 8.

	\n+------------------------+
	|    CTheWeather Menu    
	+---+--------------------
	| 1 | Forecast           
	| 2 | Humidity           
	| 3 | Temperature        
	| 4 | Wind               
	| 5 | Location           
	| 6 | Precipitation      
	| 7 | Astronomy          
	| 8 | Quit               
	+---+--------------------+
