from django.db import models


class Measure(models.Model):
    room_id = models.PositiveIntegerField()
    room_name = models.CharField(max_length=30)
    temperature = models.IntegerField()
    humidity = models.IntegerField()
    time = models.DateTimeField(auto_now_add=True)
