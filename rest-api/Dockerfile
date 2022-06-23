FROM python:3
ENV PYTHONUNBUFFERED 1

RUN apt-get update 

WORKDIR /app

RUN pip3 install pip-tools
COPY requirements.in .

COPY requirements.txt .
RUN pip3 install -r requirements.txt

COPY . /app

CMD ["python", "manage.py", "runserver", "0.0.0.0:8000"]
