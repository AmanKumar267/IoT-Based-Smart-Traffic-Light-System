/*
==========================================================
 IoT Based Smart Traffic Light Control System
----------------------------------------------------------
 Hardware:
 • Arduino Uno
 • 4 IR Sensors
 • 6 LEDs (2 Roads)
 • ESP8266 (Optional for future IoT)

 Developed By: Aman Kumar
==========================================================
*/

// ==========================
// IR Sensor Pins
// ==========================

const int IR_A1 = 2;
const int IR_A2 = 3;

const int IR_B1 = 4;
const int IR_B2 = 5;


// ==========================
// Road A LEDs
// ==========================

const int RED_A = 6;
const int YELLOW_A = 7;
const int GREEN_A = 8;


// ==========================
// Road B LEDs
// ==========================

const int RED_B = 9;
const int YELLOW_B = 10;
const int GREEN_B = 11;


// ==========================
// Timing
// ==========================

int LOW_TRAFFIC = 5000;
int MEDIUM_TRAFFIC = 8000;
int HIGH_TRAFFIC = 12000;


// ==========================
// Setup
// ==========================

void setup()
{

  Serial.begin(9600);

  pinMode(IR_A1, INPUT);
  pinMode(IR_A2, INPUT);

  pinMode(IR_B1, INPUT);
  pinMode(IR_B2, INPUT);

  pinMode(RED_A, OUTPUT);
  pinMode(YELLOW_A, OUTPUT);
  pinMode(GREEN_A, OUTPUT);

  pinMode(RED_B, OUTPUT);
  pinMode(YELLOW_B, OUTPUT);
  pinMode(GREEN_B, OUTPUT);

  allRed();

  Serial.println("Smart Traffic System Started");

}


// ==========================
// Main Loop
// ==========================

void loop()
{

  int trafficA = vehicleDensityA();
  int trafficB = vehicleDensityB();

  Serial.print("Road A Density : ");
  Serial.println(trafficA);

  Serial.print("Road B Density : ");
  Serial.println(trafficB);

  int greenTimeA = calculateTime(trafficA);
  int greenTimeB = calculateTime(trafficB);

  roadAGreen(greenTimeA);

  roadBGreen(greenTimeB);

}


// ==========================
// Vehicle Density Road A
// ==========================

int vehicleDensityA()
{

  int count = 0;

  if(digitalRead(IR_A1)==LOW)
      count++;

  if(digitalRead(IR_A2)==LOW)
      count++;

  return count;

}



// ==========================
// Vehicle Density Road B
// ==========================

int vehicleDensityB()
{

  int count = 0;

  if(digitalRead(IR_B1)==LOW)
      count++;

  if(digitalRead(IR_B2)==LOW)
      count++;

  return count;

}



// ==========================
// Calculate Green Time
// ==========================

int calculateTime(int density)
{

  if(density==0)
      return LOW_TRAFFIC;

  if(density==1)
      return MEDIUM_TRAFFIC;

  return HIGH_TRAFFIC;

}



// ==========================
// Road A Green
// ==========================

void roadAGreen(int duration)
{

  digitalWrite(RED_B,HIGH);
  digitalWrite(GREEN_B,LOW);
  digitalWrite(YELLOW_B,LOW);

  digitalWrite(RED_A,LOW);
  digitalWrite(YELLOW_A,LOW);
  digitalWrite(GREEN_A,HIGH);

  countdown(duration);

  digitalWrite(GREEN_A,LOW);

  digitalWrite(YELLOW_A,HIGH);

  delay(2000);

  digitalWrite(YELLOW_A,LOW);

  digitalWrite(RED_A,HIGH);

}



// ==========================
// Road B Green
// ==========================

void roadBGreen(int duration)
{

  digitalWrite(RED_A,HIGH);
  digitalWrite(GREEN_A,LOW);
  digitalWrite(YELLOW_A,LOW);

  digitalWrite(RED_B,LOW);
  digitalWrite(YELLOW_B,LOW);
  digitalWrite(GREEN_B,HIGH);

  countdown(duration);

  digitalWrite(GREEN_B,LOW);

  digitalWrite(YELLOW_B,HIGH);

  delay(2000);

  digitalWrite(YELLOW_B,LOW);

  digitalWrite(RED_B,HIGH);

}



// ==========================
// Countdown
// ==========================

void countdown(int t)
{

  unsigned long start = millis();

  while(millis()-start<t)
  {

      Serial.print("Remaining : ");

      Serial.print((t-(millis()-start))/1000);

      Serial.println(" sec");

      delay(1000);

  }

}



// ==========================
// All Red
// ==========================

void allRed()
{

  digitalWrite(RED_A,HIGH);
  digitalWrite(RED_B,HIGH);

  digitalWrite(YELLOW_A,LOW);
  digitalWrite(YELLOW_B,LOW);

  digitalWrite(GREEN_A,LOW);
  digitalWrite(GREEN_B,LOW);

}
