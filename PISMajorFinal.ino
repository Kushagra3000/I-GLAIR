int trigPin2=4;
int echoPin2=5;

int trigPin3=2;
int echoPin3=3;

int flag=0;

unsigned long currentMillis=0;
long previousMillis=0;

long interval = 2000;

long previous2=0;
int i=0;

int t=0;

int t2=0;

const byte blinkPin = 12;
byte oldBlinkState = HIGH;         // assume eye open (or supply init/calibrate routine)
const unsigned long debounceTime = 10;  // milliseconds
unsigned long blinkStartAt;        // when the blink started
unsigned long oldBlinkStartAt;  // when the previous blink started
unsigned long unBlinkStartAt;   // when blink ended
unsigned long tweenTime;          // time since last blink
unsigned long blinkTime;         
unsigned long blinkChange;
int sleep;

int buz = 13;

int received;
int time_received;
int val_t[52];

char abcd[52] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','o','p','q','r','s','t','u','v','w','x','y','z'};
String readString;



void setup() {
  Serial.begin (9600);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  pinMode (blinkPin, INPUT_PULLUP);
  pinMode(buz, OUTPUT);
  //pinMode(buz,OUTPUT);
  
}



void loop()

{


   if (Serial.available() > 0) {

        received = Serial.read();
        for(int i= 0 ;i<53;i++)
  {
   val_t[i] = i*5;
  }

for(int j = 0; j<53;j++)
{
  if (abcd[j]==received)
  {
    time_received = val_t[j];
  }
  else
  {
    time_received = 5 ;
  }
  
}

   }   

if ((5*60*1000)>millis())
{
  
 //delay(500);
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= microsecondsToCentimeters(duration2);
  Serial.print("dis2:");
  Serial.println(distance2);
  Serial.print("\n");
 
  long duration3, distance3;
  digitalWrite(trigPin3, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3= microsecondsToCentimeters(duration3);
  Serial.println("dis3:");
  Serial.println(distance3);
  Serial.print("\n");

if (distance2<35 & distance3<35)
{
   currentMillis = millis();
   flag=1;
    if (distance3-distance2>=3)
     { 
        if (currentMillis-previousMillis>interval)
        {

          digitalWrite(buz,HIGH);
        }
    
       else 
       {
          digitalWrite(buz, LOW); 
       }
 
     }
  
   else{
         digitalWrite(buz,LOW);
         //Serial.print("low");
         previousMillis=currentMillis;
       }
}

else
{
  if (flag==1)
  {
   i=i+1;
   Serial.print(i);
   Serial.print(":::");
   Serial.print((currentMillis-previous2)/1000);
   Serial.print("\n");
   previous2=currentMillis;
   flag=0; 
    }
  
  }





 
  bool blinkState = digitalRead (blinkPin);

  if (blinkState != oldBlinkState)
  {Serial.print("hello");
    digitalWrite(buz,LOW);
    if (millis () - blinkChange >= debounceTime)
    {
      blinkChange = millis ();  // when blink state changed
      oldBlinkState =  blinkState;  // remember for next time
      if (blinkState == LOW) {
        blinkStartAt = blinkChange;
        tweenTime = blinkChange - oldBlinkStartAt;
        oldBlinkStartAt = blinkStartAt;
      }
      else  {
        unBlinkStartAt = blinkChange;
        //Serial.println((unBlinkStartAt - blinkStartAt)/1000);// length of blink
        sleep=(unBlinkStartAt - blinkStartAt)/1000;
        if (tweenTime/1000>3){
         
          }
        //Serial.print(tweenTime);
        Serial.print("\n");}
      
    }
  }
  if (blinkState== LOW  and millis () - blinkStartAt>3000){
         Serial.print("sleep");
          digitalWrite(buz, HIGH);
          }




 }
 
 else if (millis()>=time_received and time_received != 0)
 {t2=millis();
  digitalWrite(buz,HIGH);
  delay(5000);
  digitalWrite(buz,LOW);
  delay(20000);
  }

  
 
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
