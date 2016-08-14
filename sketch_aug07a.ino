#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Genotronex(10, 11); // RX, TX
int lm1 = 6;
int lm2 = 7;
int rm1 = 4;
int rm2 = 5;
int e1 = 2;
int e2 = 3;
char* Randoutputs[12] = {"Hello, How are you?", "Thats good", "Yes... I can do many things.", "I am doing something.", "Search for google." , "huh", "what did you just say", "I need to reconsider that", "may be", " I guess", "Whats your name"};
char* nameouput[4] = {"My name is Baby" , " I told you I am baby" , " I dont need an intro", " I thought we were over this" };
String BluetoothData;
void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(9600);
  Genotronex.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(e1, HIGH);
  digitalWrite(e2, HIGH);
  digitalWrite(12, LOW);
  Serial.begin(9600);
  // digitalWrite(h1, HIGH);
  // digitalWrite(h2, HIGH);
}
void loop()
{
  // put your main code here, to run repeatedly:
  while (Genotronex.available())
  { delay(10);
    char c = Genotronex.read();
    if ( c == '#') {
      break;
    }
    BluetoothData = BluetoothData + c;

  }

  if (BluetoothData.length() > 0 )
  {

    for ( int i = 0 ; i <= BluetoothData.length() ; i++)
    {
      if (BluetoothData.substring(i, i + 1) == "w")
      { digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);
        Serial.println("moving forward ");
        delay(2000);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        break;

      }
      if (BluetoothData.substring(i, i + 1) == "a")
      {
        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(400);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        Serial.println("moving left");
        break;
      }

      if (BluetoothData.substring(i, i + 1) == "s")
      {
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(2000);

        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        Serial.println("moving backward");
        break;
        
      }

      if (BluetoothData.substring(i, i + 1) == "d")
      { digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm2, HIGH);
        digitalWrite(rm1, LOW);
        delay(400);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        Serial.println("moving right");
        break;

      }

      if (BluetoothData.substring(i, i + 8) == "the time")
      {
        Serial.println(Randoutputs[random(3)]);
        break;
      }
      if (BluetoothData.substring(i, i + 4) == "name" or BluetoothData.substring(i, i + 13) == "call yourself")
      {
        Serial.println(nameouput[random(4)]);
        break;
      }
      if (BluetoothData.substring(i, i + 6) == "you do")
      {
        /* / Serial.println(Randoutputs[random(10)];*/
        Serial.println(Randoutputs[random(12)]);
        break;
      }

      if (BluetoothData.substring(i, i + 4) == "f***" or BluetoothData.substring(i, i + 5) == "b****" or BluetoothData.substring(i, i + 4) == "ugly" or BluetoothData.substring(i, i + 8) == "terrible" or BluetoothData.substring(i, i + 6) == "stupid" or BluetoothData.substring(i, i + 4) == "dumb" or BluetoothData.substring(i, i + 3 ) == "ass" or BluetoothData.substring(i, i + 4) == "crap" or BluetoothData.substring(i, i + 4) == "shit" or BluetoothData.substring(i, i + 8) == "fuckface" or BluetoothData.substring(i, i + 5) == "thing" or BluetoothData.substring(i, i + 23 ) == "if you know what I mean")
      {
        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);

        delay(400);

        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm2, HIGH);
        digitalWrite(rm1, LOW);

        delay(400);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);

        delay(400);

        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm2, HIGH);
        digitalWrite(rm1, LOW);

        delay(400);

        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm2, LOW);
        digitalWrite(rm1, LOW);
        Serial.println("Hell NO!");
        break;
      }
      if (BluetoothData.substring(i, i + 4 ) == "stop" or BluetoothData.substring(i, i + 4) == "wait" or BluetoothData.substring(i, i + 4) == "hold" or BluetoothData.substring(i, i + 9) == "dont move")
      { // if number 0 pressed ....
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        break;
      }
      if (BluetoothData.substring(i, i + 7) == "forward" || BluetoothData.substring(i, i + 5) == "front" or BluetoothData.substring(i, i + 8) == "straight")
      {

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);
        Serial.println("moving forward ");
        delay(2000);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        break;
      }
      if (BluetoothData.substring(i, i + 4 ) == "back" or BluetoothData.substring(i, i + 8) == "backward")
      {
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(2000);

        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        Serial.println("moving backward");
        break;
      }
      if (BluetoothData.substring(i, i + 4 ) == "left" or BluetoothData.substring(i, i + 9) == "9 o'clock")
      {
        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(400);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        Serial.println("moving left");
        break;
      }
      if (BluetoothData.substring(i, i + 5 ) == "right" or BluetoothData.substring(i, i + 9) == "3 o'clock")
      {
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm2, HIGH);
        digitalWrite(rm1, LOW);
        delay(400);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        Serial.println("moving right");
        break;
      }

      if (BluetoothData.substring(i, i + 4) == "test" or BluetoothData.substring(i, i + 4) == "check" )
      {
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        Genotronex.write("Bluetooth Working");
        break;
      }

      if (BluetoothData.substring(i, i + 5) == "hello" or BluetoothData.substring(i, i + 2) == "hi" or BluetoothData.substring(i, i + 8 ) == "hey baby" or BluetoothData.substring(i, i + 3) == "hey")
      {
        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm2, HIGH);
        digitalWrite(rm1, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);


        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm2, HIGH);
        digitalWrite(rm1, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);


        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);


        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm2, HIGH);
        digitalWrite(rm1, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);



        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);
        Serial.println("moving forward ");
        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm2, HIGH);
        digitalWrite(rm1, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);



        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);


        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm2, HIGH);
        digitalWrite(rm1, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);



        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);



        digitalWrite(lm2, LOW);
        digitalWrite(lm1, HIGH);
        digitalWrite(rm2, HIGH);
        digitalWrite(rm1, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);



        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(1000);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);



        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);



        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);

        delay(500);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(300);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        break;

      }

      if (BluetoothData.substring(i, i + 1) == "" or BluetoothData.substring(i, i + 4) == "play" or BluetoothData.substring(i, i + 6) == "please" or BluetoothData.substring(i, i + 5) == "party" or BluetoothData.substring(i, i + 3) == "fun")
      { digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);
        Serial.println("moving forward ");
        delay(500);



        digitalWrite(lm1, HIGH);
        digitalWrite(lm2, LOW);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);

        delay(500);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, HIGH);
        Serial.println("moving forward ");
        delay(500);



        digitalWrite(lm1, HIGH);
        digitalWrite(lm2, LOW);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);


        delay(500);

        digitalWrite(lm1, LOW);
        digitalWrite(lm2, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);

        break;
      }

      if (BluetoothData.substring(i, i + 1) == " ")
      {
        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        delay(1000);
        digitalWrite(lm2, LOW);
        digitalWrite(lm1, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        Serial.print(BluetoothData);
        break;
      }


      Serial.println(BluetoothData);
    }

    BluetoothData = "";
  }

}

