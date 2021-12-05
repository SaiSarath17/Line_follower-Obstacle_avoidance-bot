
int in1 = 9;  // Left motor
int in2 = 10;

int in4 = 6; //right motor
int in3 = 5;

int lsonartrig=7; //ultrasonic sensor
int  lsonarecho=4;
int rsonartrig=3;
int rsonarecho=2;
int cm=0;
int time=0;
int cm1=0;
int irL=13;
int irR=12;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup(){
 pinMode(in1, HIGH);
  pinMode(in2, HIGH);
  pinMode(in3, HIGH);
  pinMode(in4, HIGH);
 pinMode(irL, INPUT);
 pinMode(irR, INPUT);
 Serial.begin(9600);
 }

 void linefollower()
 {
    //Line Follower code
 int s=digitalRead(irL);
  Serial.print(s);
  Serial.println("-irL");
  int k=digitalRead(irR);
  Serial.print(s);
  Serial.println("-irR");
  if(s==1 && k==1)
  {
    forward();
  }
  else if(s==0 && k==1)
  {
    turnRight();
  }
  else if(s==1 && k==0)
  {
    turnLeft();
  }
 /* else if(s==0 && k==0)
  {
    stop();
  }*/
 }

void loop(){

  
 //measure Ultrasonic time
 time = readUltrasonicDistance(lsonartrig, lsonarecho);
  // convert to cm
  cm = 0.01723 * time;
 Serial.print("cml=");
  Serial.println(cm);
  delay(1000);
  time = readUltrasonicDistance(rsonartrig, rsonarecho);
  // convert to cm
 cm1 = 0.01723 * time;
 Serial.print("cmr=");
 Serial.println(cm1);
 
  if(cm<=30)
  {
    stop();
    delay(1000);
    turnRight();
  }
  else
    if(cm1<=30)
    {
      stop();
      delay(1000);
      turnLeft();
    }
  else
    if(cm>30 && cm1>30)
    {
      forward();
    }
  
  delay(250); // Wait for 250 millisecond(s)
}

int checkArea(int radar)
{
  turnRight();
  Serial.println("right-checkArea");
  delay(radar);
   Serial.print(radar);
      Serial.print(" checkArea");
      Serial.println("");
  stop();
  Serial.println("1stop-checkArea");
  time = readUltrasonicDistance(lsonartrig, lsonarecho);
  cm = 0.01723 * time;
  Serial.print(cm);
      Serial.print("dist-checkArea");
      Serial.print("");
  if(cm<=30)
    {
      turnLeft();
      Serial.println("left-checkArea");
      delay(radar+radar);
      Serial.print(radar+radar);
      Serial.print(" checkArea");
      Serial.println("");
      stop();
      Serial.println("2stop-checkArea");
      time = readUltrasonicDistance(lsonartrig, lsonarecho);
      cm = 0.01723 * time;
      if(cm<30)
      {
      turnRight();
      Serial.println("2right-checkArea");
      delay(radar);  
      Serial.print(radar);
      Serial.print("checkArea");
      Serial.print("");
      checkArea(radar+radar);  
      }
      else return 2;
    }
    else return 1;
    
    
    
}
void evadeRight(int radar)
  {
    Serial.println("executing evadeRight protocol");
    forward();
    delay(radar);
    stop();
    turnLeft();
    delay(radar);
    forward();
    delay(radar);
    turnRight();
    delay(radar);
    stop();
  }
void evadeLeft(int radar)
  {
    Serial.println("executing evadeLef=t protocol");
    forward();
    delay(radar);
    stop();
    turnRight();
    delay(radar);
    forward();
    delay(radar);
    turnLeft();
    delay(radar);
    stop();
  }
 void stop(){
 digitalWrite(in1, LOW);  // Turn off motors
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
}

void forward(){
 digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  
}

void backward(){
 digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
}


void turnRight(){
digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
}

void turnLeft(){
digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);   
}
