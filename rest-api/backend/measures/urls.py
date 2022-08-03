from django.urls import path, include
from rest_framework import routers

from backend.measures.views import MeasuresViews, MeasureViewSet

app_name = "measures"

router = routers.SimpleRouter()
router.register(r'measures', MeasureViewSet, basename='measure')


urlpatterns = [
    path('', include(router.urls)),
    path('measurement/', MeasuresViews.as_view(), name='measurement'),
    # path('test-api/', MeasuresViews.as_view())
]
