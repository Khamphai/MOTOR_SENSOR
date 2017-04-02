
// POWER MOTOR------------------------------------------
int ENA_PW_L = 10;
int ENB_PW_R = 9;

//MOTOR------------------------------------------------
int IN_L_1 = 4;
int IN_L_2 = 5;
int IN_R_1 = 6;
int IN_R_2 = 7;

// SENSOR TRACKING--------------------------------------
int SENSOR_L_1 = 22;
int SENSOR_L_2 = 26;
int SENSOR_R_1 = 24;
int SENSOR_R_2 = 25;

// RECIEVE VALUE FROM SENSOR-------------------------------
int VALUE_SENSOR_L_1, VALUE_SENSOR_L_2;
int VALUE_SENSOR_R_1, VALUE_SENSOR_R_2;

void setup() {
  Serial.begin(9600);
  // MOTOR LEFT
  pinMode(ENA_PW_L, OUTPUT); // USE PIN 10
  pinMode(IN_L_1,OUTPUT); // USE PIN 4
  pinMode(IN_L_2,OUTPUT); //  USE PIN 5
  // MOTOR RIGHT
  pinMode(ENB_PW_R, OUTPUT); // USE PIN 9
  pinMode(IN_R_1,OUTPUT); // USE PIN 6
  pinMode(IN_R_2,OUTPUT); // USE PIN 7

  // SENSOR DETECT VALUE
  pinMode(SENSOR_L_1,INPUT); // USE PIN 22
  pinMode(SENSOR_L_2,INPUT); // USE PIN 23
  pinMode(SENSOR_R_1,INPUT); // USE PIN 24
  pinMode(SENSOR_R_2,INPUT); // USE PIN 25
  
}// end of setup-------------------------------------------------

void loop() {

 // READ VALUE FROM SENSOR AND KEEP IN VARIABLE
 VALUE_SENSOR_L_1 = digitalRead(SENSOR_L_1);
 VALUE_SENSOR_L_2 = digitalRead(SENSOR_L_2);
 VALUE_SENSOR_R_1 = digitalRead(SENSOR_R_1);
 VALUE_SENSOR_R_2 = digitalRead(SENSOR_R_2);
 
 // CHECK STATUS FROM VALUE SENSOR 
// Serial.print("VALUE_SENSOR_L_1 ");
// Serial.println(VALUE_SENSOR_L_1);
 Serial.print("VALUE_SENSOR_L_2 ");
 Serial.println(VALUE_SENSOR_L_2);
 Serial.print("VALUE_SENSOR_R_1 ");
 Serial.println(VALUE_SENSOR_R_1);
// Serial.print("VALUE_SENSOR_R_2 ");
// Serial.println(VALUE_SENSOR_R_2);
 Serial.println("-----------------------------------------------------");
 //delay(1000);
  // MOTOR DO SOMETHING BY CONDITION FROM SENSOR
//  if(VALUE_SENSOR_L_1 == 0 && VALUE_SENSOR_L_2 == 0 && VALUE_SENSOR_R_1 == 0 && VALUE_SENSOR_R_2 == 0){
//    forward();
//  }else if(VALUE_SENSOR_L_1 == 0 && VALUE_SENSOR_L_2 == 1 && VALUE_SENSOR_R_1 == 0 && VALUE_SENSOR_R_2 == 0){
//    turnRight();
//  }else if(VALUE_SENSOR_L_1 == 0 && VALUE_SENSOR_L_2 == 0 && VALUE_SENSOR_R_1 == 1 && VALUE_SENSOR_R_2 == 0){
//    turnLeft();
//  }else if (VALUE_SENSOR_L_1 == 1 && VALUE_SENSOR_L_2 == 1 && VALUE_SENSOR_R_1 == 0 && VALUE_SENSOR_R_2 == 0){
//    turnRight();
//  }else if(VALUE_SENSOR_L_1 == 0 && VALUE_SENSOR_L_2 == 0 && VALUE_SENSOR_R_1 == 1 && VALUE_SENSOR_R_2 == 1){
//    turnLeft();
//  }else if (VALUE_SENSOR_L_1 == 1 && VALUE_SENSOR_L_2 == 1 && VALUE_SENSOR_R_1 == 1 && VALUE_SENSOR_R_2 == 0){
//    turnRight();
//  }else if (VALUE_SENSOR_L_1 == 0 && VALUE_SENSOR_L_2 == 1 && VALUE_SENSOR_R_1 == 1 && VALUE_SENSOR_R_2 == 1){
//    turnLeft();
//  }else if (VALUE_SENSOR_L_1 == 0 && VALUE_SENSOR_L_2 == 0 && VALUE_SENSOR_R_1 == 0 && VALUE_SENSOR_R_2 == 0){
//    
////  }else if (VALUE_SENSOR_L_1 == 0 && VALUE_SENSOR_L_2 == 0 && VALUE_SENSOR_R_1 == 0 && VALUE_SENSOR_R_2 == 0){
////    
////  }else if (VALUE_SENSOR_L_1 == 0 && VALUE_SENSOR_L_2 == 0 && VALUE_SENSOR_R_1 == 0 && VALUE_SENSOR_R_2 == 0){
////    
////  }else if (VALUE_SENSOR_L_1 == 0 && VALUE_SENSOR_L_2 == 0 && VALUE_SENSOR_R_1 == 0 && VALUE_SENSOR_R_2 == 0){
////    
//  }else{
//    
//  }

  if(VALUE_SENSOR_L_2 == 0 && VALUE_SENSOR_R_1 == 0){
    forward();
  }else if(VALUE_SENSOR_L_2 == 1 && VALUE_SENSOR_R_1 == 0){
    turnRight();
  }else if(VALUE_SENSOR_L_2 == 0 && VALUE_SENSOR_R_1 == 1){
    turnLeft();
  }else{

  }

}// end of loop-----------------------------------------------------------

// FUNCTION TO DO SOMETHING WITH MORTOR

void forward(){
  // MOTOR LEFT
  digitalWrite(IN_L_1,HIGH); // USE PIN 4
  digitalWrite(IN_L_2,LOW); // USE PIN 5
  analogWrite(ENA_PW_L,100); //VUSE PIN 10
  
  // MOTOR RIGHT
  digitalWrite(IN_R_1,LOW); // USE PIN 6
  digitalWrite(IN_R_2,HIGH); // USE PIN 7
  analogWrite(ENB_PW_R,100); //VUSE PIN 9
}// end of function forward---------------------------------

void turnRight(){
  // MOTOR LEFT
  digitalWrite(IN_L_1,HIGH); // USE PIN 4
  digitalWrite(IN_L_2,LOW); // USE PIN 5
  analogWrite(ENA_PW_L,100); //VUSE PIN 10

  // MOTOR RIGHT
  digitalWrite(IN_R_1,LOW); // USE PIN 6
  digitalWrite(IN_R_2,LOW); // USE PIN 7
  analogWrite(ENB_PW_R,100); //VUSE PIN 9
}// end of function turnRight---------------------------------

void turnLeft(){
  // MOTOR LEFT
  digitalWrite(IN_L_1,LOW); // USE PIN 4
  digitalWrite(IN_L_2,LOW); // USE PIN 5
  analogWrite(ENA_PW_L,100); //VUSE PIN 10

  // MOTOR RIGHT
  digitalWrite(IN_R_1,LOW); // USE PIN 6
  digitalWrite(IN_R_2,HIGH); // USE PIN 7
  analogWrite(ENB_PW_R,100); //VUSE PIN 9
}// end of function turnLeft---------------------------------

void stopped(){
  // MOTOR LEFT
  digitalWrite(IN_L_1,LOW); // USE PIN 4
  digitalWrite(IN_L_2,LOW); // USE PIN 5
  analogWrite(ENA_PW_L,100); //VUSE PIN 10

  // MOTOR RIGHT
  digitalWrite(IN_R_1,LOW); // USE PIN 6
  digitalWrite(IN_R_2,LOW); // USE PIN 7
  analogWrite(ENB_PW_R,100); //VUSE PIN 9
}// end of function stopped---------------------------------








    
