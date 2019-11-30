from django.urls import path
from . import views
app_name = 'mainfile'
urlpatterns = [
    #this path will take us to the home page which is created in the base.html file.
    path('', views.home, name='home'),#yahan par iglair.com aa sakta hai.
    path('LogIn', views.LogIn, name='LogIn'),
    path('SignUp', views.SignUp, name='SignUp'),
    path('Time', views.Time, name="Time"),
    path('Terminate', views.Terminate, name="Terminate"),
]
