# ESP8266-controlled-by-a-database
The main purpose of this project is to develop an alternate control system that allows devices to be controlled locally rather than using cloud servers or hubs as well as, increase flexibility to change inputs and outputs. In short, the ESP will be used to pull commands from a local database (e.g., MySQL), interpret and send signals to the devices. The data can include the time to perform an action and what it will do at that time. For example, the system can turn a fan on/off at certain time frames. This project is partially finished, so controlling physical devices is not completed yet, however, the concept can be demonstrated with LEDs. 

# Requried Software/Hardware for project:
  * Xampp to run MyPHPadmin, apache, and MySql
  * Arduino IDE
  * a text editor (e.g. notepadd++)
  * Adafruit Feather huzzah ESP8266
  * micro USB data transfer cable
  

# 1st step 
Open up xampp and in the control panel start the apache and MySql applications. From there, you will select the admin button in the MySql row to open up MyPHPadmin.

# 2nd step
Create a simple database that contains one table. I included three columns id, device name, and device status.

# 3rd step
In the file explorer, locate the xampp files and inside the htdocs folder create a new folder (xampp > htdocs > new_folder). Add the connect and get_status.php files inside the newly created folder. 

# 4th step
Follow this link https://learn.adafruit.com/adafruit-feather-huzzah-esp8266/using-arduino-ide in order to have the ESP ready for programming.

# 5th step
Insert your access point credentials into the reading_from_database.ino file and upload it to the board. 

At this point, you can change the device status (turn off/on) in the database and see the built-in LED on the ESP board change in real time, thus, demonstating that a "physical device" has recieved its instructions locally.

A special thanks to my professor Dr. Boonsuk, who helped me a great deal finishing this project.

NOTE -- This project was not tested with Mac operating systems, so it may or may not work.
