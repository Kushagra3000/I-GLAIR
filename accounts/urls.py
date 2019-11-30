from django.urls import path
from.import views

app_name='accounts'

urlpatterns=[
    path('LogIn', views.LogIn, name='LogIn'),
    path('SignUp', views.SignUp, name='SignUp'),
]
