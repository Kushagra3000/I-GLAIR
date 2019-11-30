

# Create your models here.
from django.db import models
from django.utils import timezone
import datetime


class Time(models.Model):                 #it will accept the total time user wants to use the chair and the glasses
    time_text = models.CharField(max_length=200)
    def __str__(self):
        return self.time_text
