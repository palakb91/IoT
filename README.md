# IoT
This repository contains all IoT practical experiments, including sensor interfacing, cloud integration, and real-time data monitoring 

#HOW TO DEPLOY CODE IN ESP 
1. Install Arduino IDE:
Download the latest version from Arduino’s official website.

Install the IDE.

2. Install ESP Board in Arduino IDE:
Open Arduino IDE → File → Preferences.
In the Additional Boards Manager URLs field, add:
http://arduino.esp8266.com/stable/package_esp8266com_index.json
Then go to Tools → Boards → Boards Manager → Search for ESP8266 or ESP32, and install it.

3. Select the ESP Board:
Go to Tools → Board → Select your ESP board (e.g., ESP8266 or ESP32).

4. Select the Correct Port:
Connect the ESP board to your PC via USB.
Go to Tools → Port → Select the correct COM port for your ESP.

#Real Time Log Register using python 
Go to Google Cloud Console → New Project.
Name the project (e.g., "IoT123").
Go to APIs & Services → Library → Enable "Google Sheets API" and "Google Drive API".
Go to APIs & S
ervices → Credentials → Create Credentials → Service Account.
Assign a name and role (Editor).
Create a Key → Choose JSON → Download JSON file.
Google Sheet Setup:
Go to Google Sheets → Create a new sheet (e.g., "IoT123").
Upload the JSON file to your working folder.
Share the sheet → Add the service account email (from JSON) → Give Editor access.
Colab Setup:
Open Google Colab → New notebook.
Upload the JSON file to Colab.
Paste and run the code → Values will update on the sheet.






