Autoroom
=========================================================

* Part 1 - Installation
* Part 2 - About the Backend
* Part 3 - About the Frontend
* Part 4 - Running the code




## Part 1 - Installation

1st Way:

I've created a Makefile, where I added the most common commands that we'll be using. There, you will be able to see that 
there is a command named `setup`. You will need to use it if is the first time that you run this project. So, in terminal,
simply run:

> make setup

(If there's any trouble, you can try by rerunning this command. Otherwise, try with the second way.)

2nd Way:

Once in terminal, just use next instructions:

> docker-compose build

> docker-compose run autoroom python manage.py migrate

> docker-compose run autoroom python manage.py loaddata backend/measures/fixtures/*


This should be enough. Keep in mind that when you have dependencies issues, you can run: 
> sudo chown `whoami` -R .


## Part 2 - About backend

* **Models:** This project has only one model (for now): Measure.
* **Serializers:** Regarding serializers, it will have one for each endpoint. Only Measure for now.
* **Views:** There will be one view to show all the measures in the DB. 


## Part 3 - About Frontend

There's a landing page called 'Main.vue', where all measures from the DB are shown to the user. These measures show it's 
respective room's id, name, temperature and humidity; with a timestamp. The data is displayed by a table.


## Part 4 - Running the code
To run this code it is enough to use:
> docker-compose up

After that, you can simply check that everything works perfectly by visiting the following links:

(For Django-Rest-Framework view)

http://0.0.0.0:8000/measures/  
http://0.0.0.0:8000/measures/2/  

(Keep in mind that the integer value can be switched for another one)

(For Frontend view)

http://localhost:8080/


