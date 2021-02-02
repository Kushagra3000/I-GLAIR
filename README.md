# I-GLAIR

## Setup
To run the Python code, follow this order : 
  1. upload the code in Arduino, and then check for the port and baud rate.
  2. In a code editor, open the  following file saved in the djangoCode folder in the master folder :
     polls/views.py
  3. In this file, edit line no. 9 to :
        ser = serial.Serial('your Arduino port number', 'your baud rate')
  4. Using local host, you can run the code in the following manner:
     1. open the master folder in command prompt, and run the following command : 
          py manage.py runserver
     2. This will generate a development server at a url ( say , 'http://127.0.0.1:8000/' ) :
  5. Use this url to see the final deployment of the code in the web server.
## Features
The server allows :
  1. creation of new user using SignUp.
  2. accessing the features using LogIn.
  3. user can enter the total time they would like to work, by specifying the time in Hours and Minutes.
  4. if they want to terminate the program, they can click the terminate button to completely stop the process.
