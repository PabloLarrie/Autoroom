from django.urls import path, include
from rest_framework import routers

from backend.measures.views import MeasureViewSet, MeasuresViews

app_name = "measures"

router = routers.SimpleRouter()
router.register(r'measures', MeasureViewSet, basename='measure')


urlpatterns = [
    path('', include(router.urls)),
    path('test-api/', MeasuresViews.as_view())
]
