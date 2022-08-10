from rest_framework_filters import FilterSet

from backend.measures.models import Measure


class MeasureFilter(FilterSet):
    class Meta:
        model = Measure
        fields = [
            "room_id",
            "room_name",
        ]
