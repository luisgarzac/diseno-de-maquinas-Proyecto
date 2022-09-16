// autor: Luis Antonio Garza
// prueba v2
#include <SoftwareSerial.h> // TX RX software library for bluetooth
#include <Servo.h> // servo library 
Servo myservo; // servo name
SoftwareSerial BT(10,11); // Pin 10 sera el Rx y el pin 11 sera TX
int estado=0; //datos enviados al bluetooth, valores enteros para servo
//int estado1; // datos enviados al bluetooth, valores letra para cd
//Variables motor 1 driver
int IN1=4; //adelante
int IN2=5; //atras
//Variables motor 2 driver
int IN3=6; //ATRAS
int IN4=7; //ADELANTE

// put your setup code here, to run once:
void setup()
{
Serial.begin(9600);
BT.begin(9600); 
pinMode(IN1,OUTPUT); //Definimos cada pin como una salida
pinMode(IN2,OUTPUT); //Definimos cada pin como una salida
pinMode(IN3,OUTPUT); //Definimos cada pin como una salida
pinMode(IN4,OUTPUT); //Definimos cada pin como una salida
myservo.attach(8); // definimos donde esta la señal del servo
}

void loop() 
{
if(BT.available()>0)
{
  //int estado=BT.read(); //Leer lo escrito por bluetooth
  estado=BT.read(); //Leer lo escrito por bluetooth
  //Serial.print("Bluetooth encendido");
  //Serial.print('\n');
  //Serial.print(estado);
  Serial.println(estado);
// Esta parte del codigo es para los motores de corriente directa
  //Si se presiona adelante
  if(estado==52)
  {
   digitalWrite(IN1,HIGH); // mover motor
   digitalWrite(IN4,HIGH); // mover motor
   digitalWrite(IN2,LOW); // mover motor
   digitalWrite(IN3,LOW); // mover motor
  }
  //si se presiona atras
  if(estado==54)
  {
   digitalWrite(IN2,HIGH); // mover motor
   digitalWrite(IN3,HIGH); // mover motor
   digitalWrite(IN1,LOW); // mover motor
   digitalWrite(IN4,LOW); // mover motor
  }
  // si se presiona stop
  if(estado==53)
  {
   digitalWrite(IN1,LOW); // mover motor
   digitalWrite(IN2,LOW); // mover motor
   digitalWrite(IN3,LOW); // mover motor
   digitalWrite(IN4,LOW); // mover motor
  }
  //////////////////////////////////////////////////////////////
  // programación servomotor
  
  //Si se presiona 
  if(estado==49)
  {            
    //Serial.println(145); // serial print servopos current number received from bluetooth
    myservo.write(145); // roate the servo the angle received from the android app derecha
  }
  if(estado==50)
  {            
    //Serial.println(90); // serial print servopos current number received from bluetooth
    myservo.write(90); // roate the servo the angle received from the android app recto
  }
  if(estado==51)
  {            
    //Serial.println(45); // serial print servopos current number received from bluetooth
    myservo.write(45); // roate the servo the angle received from the android app izquierda
  }










  
}
delay(100);  
}
