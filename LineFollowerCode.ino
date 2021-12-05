
int in1 = 9;  // Left motor
int in2 = 10;

int in4 = 6; //right motor
int in3 = 5;

int lsonartrig=7; //ultrasonic sensor
int  lsonarecho=4;
int cm=0;
int time=0;
int irL=13;
int irR=12;

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
  Serial.print(k);
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
  else
  {stop();}
 }

void loop(){

  linefollower();
  delay(250); // Wait for 250 millisecond(s)
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
