from rest_framework.filters import SearchFilter, OrderingFilter
from rest_framework.permissions import IsAuthenticatedOrReadOnly
from rest_framework.viewsets import ModelViewSet

from backend.measures.models import Measure
from backend.measures.serializers import MeasureSerializer


class MeasureViewSet(ModelViewSet):
    permission_classes = (IsAuthenticatedOrReadOnly,)
    queryset = Measure.objects.all()
    filter_backends = (SearchFilter, OrderingFilter)
    search_fields = ["room_id", "room_name"]
    ordering = ("id",)
    filterset_fields = ['is_online']

    def get_serializer_class(self):
        return MeasureSerializer
