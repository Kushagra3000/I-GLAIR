from django.urls import path
from . import views

urlpatterns = [
    #this path will take us to the home page which is created in the base.html file.
    path('', views.home, name='home'),#yahan par iglair.com aa sakta hai.

    path('index/', views.index, name='index'),
]