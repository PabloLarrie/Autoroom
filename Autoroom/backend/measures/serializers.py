from rest_framework import serializers

from backend.measures.models import Measure


class MeasureSerializer(serializers.ModelSerializer):

    class Meta:
        model = Measure
        fields = [
            "room_id",
            "room_name",
            "temperature",
            "humidity",
            "time",
        ]
