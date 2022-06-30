from rest_framework.filters import SearchFilter, OrderingFilter
from rest_framework.permissions import IsAuthenticatedOrReadOnly
from rest_framework.viewsets import ModelViewSet

from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status

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
    def post(self, request):
        serializer = MeasureSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response({"status": "success", "data": serializer.data}, status=status.HTTP_200_OK)
        else:
            return Response({"status": "error", "data": serializer.errors}, status=status.HTTP_400_BAD_REQUEST)