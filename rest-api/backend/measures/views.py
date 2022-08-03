import json

from django.http import JsonResponse
from rest_framework.filters import SearchFilter, OrderingFilter
from rest_framework.permissions import IsAuthenticatedOrReadOnly
from rest_framework.viewsets import ModelViewSet

from rest_framework.views import APIView

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


class MeasuresViews(APIView):

    def get(self, request):
        measures = list(Measure.objects.values())
        if len(measures) > 0:
            measure_data = {"message": "success", "measures": measures}
        else:
            measure_data = {"message": "measures not found"}
        return JsonResponse(measure_data)

    def post(self, request):
        jd = json.loads(request.body)
        Measure.objects.create(
            room_id=jd['room_id'],
            room_name=jd['room_name'],
            temperature=jd['temperature'],
            humidity=jd['humidity'],
        )
        measure_data = {'message': "Success"}
        return JsonResponse(measure_data)
