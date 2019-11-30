from django.shortcuts import render,redirect
from django.http import HttpResponse
from .models import Time
from django.views import View
import serial
import struct
from django import forms

ser = serial.Serial('com3', 9600)

# Create your views here.
def home(request):
    return render(request,'base.html')
def LogIn(request):
    if request.method == 'POST':
        form = AuthenticationForm(data=request.POST)
        if form.is_valid():
            #log in the user
            return redirect('/')
    else:
        form = AuthenticationForm()
    return render(request,'accounts/LogIn.html',{'form':form})
def SignUp(request):
    if request.method == 'POST':
        form = UserCreationForm(request.POST)
        if form.is_valid():
            form.save()
            #Log the user in
            return redirect('/')
    else:
        form = UserCreationForm()
    return render(request,'accounts/SignUp.html',{'form':form})
def Time(request):
    valH = 0
    valM = 0
    if request.method == 'POST' :
        valH = int(request.POST.get('Hours'))
        valM = int(request.POST.get('Minutes'))
        valT = valH*60 + valM
        l1 = [i*5 for i in range(0,52)]
        l2 = [chr(i) for i in range(65,91)] + [chr(i) for i in range(97,123)]
        if(0<valT < 2):
            final = 5
        elif (valT%5 > 2):
            final = valT + (5-(valT%5))
        else:
            final = valT - (valT%5)
        indexVal = l1.index(final)
        k = l2[indexVal].encode()
        print("k" , k)
        print("indexVal" , indexVal)
        ser.write(k)
        return redirect('/polls/Terminate')
    else:
        pass
    #varT = varH*60 + varM
    return render(request, "polls/Time.html")
def Terminate(request):
    if request.method == 'POST' :
        ser.write(b'A')
        return redirect('/')
    else:
        print(ser.write(b'A'))

    return render(request, "polls/Terminate.html")
def TerminateProgram(request):
    pass
