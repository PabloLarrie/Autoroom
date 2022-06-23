up:
	docker-compose up

down:
	docker-compose down

pip-compile:
	docker-compose run autoroom pip-compile requirements.in > requirements.txt

shell:
	docker-compose run autoroom python manage.py shell

chown:
	sudo chown `whoami` -R .

build:
	docker-compose build

migrate:
	docker-compose run autoroom python manage.py migrate

migrations:
	docker-compose run autoroom python manage.py makemigrations

dumpdata:
	docker-compose run autoroom python manage.py dumpdata measures.Measure -o backend/measures/fixtures/measures.json --indent 4

loaddata:
	docker-compose run autoroom python manage.py loaddata backend/measures/fixtures/*

setup: build migrate loaddata