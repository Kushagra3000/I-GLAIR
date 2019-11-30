from django.shortcuts import render,redirect
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
# Create your views here.
def LogIn(request):
    if request.method == 'POST':
        form = AuthenticationForm(data=request.POST)
        if form.is_valid():
            #log in the user
            return redirect('/Time')
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
