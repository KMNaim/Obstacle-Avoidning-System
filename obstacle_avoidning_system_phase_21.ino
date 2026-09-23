
#define ePin 12 
#define tPin 13

#include<LiquidCrystal.h> 
LiquidCrystal lcd(8,7,5,4,3,2) ;

unsigned long duration , distance ; 
int fwd1 = 9 , rev1 = 6 , fwd2 = 10 , rev2 = 11 ; 
const int RS = 8 , EN = 7 , D4 = 5 , D5 = 4 , D6 = 3 , D7 = 2 ; 

void setup(){

	pinMode(ePin,INPUT); 
	pinMode(tPin,OUTPUT); 

	pinMode(fwd1,OUTPUT); 
	pinMode(fwd2,OUTPUT); 
	pinMode(rev1,OUTPUT); 
	pinMode(rev2,OUTPUT); 

	Serial.begin(9600); 
	lcd.begin(16,2); 

}

void loop(){
    digitalWrite(tPin,LOW); 
	delayMicroseconds(2); 
	digitalWrite(tPin,HIGH); 
	delayMicroseconds(10); 
  	digitalWrite(tPin,LOW); 
 	
	
	duration = pulseIn(ePin,HIGH); 
    distance = duration*0.034/2 ; 

	Serial.print(" Distance: ");  
  	Serial.print(distance);  
  	Serial.println(" cm"); 
  
  if ( distance < 20 ) {
		stop_there() ; 
        go_back() ; 
     	break_again(); 
        turn_right() ;
  }
  else   move_forward(); 

}

void move_forward() {
	digitalWrite(fwd1,HIGH); 
	digitalWrite(fwd2,HIGH); 
	digitalWrite(rev1,LOW); 
	digitalWrite(rev2,LOW); 

	lcd.setCursor(0,0); 
	lcd.print("Nothing Ahead"); 
	lcd.setCursor(0,1); 
	lcd.print("Moving Forward");
	delay(3000) ; 
	lcd.clear();  
}

void  stop_there(){
	digitalWrite(fwd1,LOW); 
	digitalWrite(fwd2,LOW); 
	digitalWrite(rev1,LOW); 
	digitalWrite(rev2,LOW);
 
	lcd.setCursor(0,0); 
	lcd.print("Something Ahead"); 
	lcd.setCursor(0,1); 
	lcd.print("Stop Here");
	delay(4000) ; 
	lcd.clear();  
}

void  go_back(){

	digitalWrite(fwd1,LOW); 
	digitalWrite(fwd2,LOW); 
	digitalWrite(rev1,HIGH); 
	digitalWrite(rev2,HIGH);

	lcd.setCursor(0,0); 
	lcd.print("Going Back"); 
	lcd.setCursor(0,1); 
	lcd.print("Go more...");
	delay(3000) ; 
	lcd.clear(); 
 
}
void  break_again(){
	digitalWrite(fwd1,LOW); 
	digitalWrite(fwd2,LOW); 
	digitalWrite(rev1,LOW); 
	digitalWrite(rev2,LOW);

	lcd.setCursor(0,0); 
	lcd.print("Break Here..."); 
	delay(3000) ; 
	lcd.clear(); 
 
}
void  turn_right(){
	digitalWrite(fwd1,HIGH); 
	digitalWrite(fwd2,LOW); 
	digitalWrite(rev1,LOW); 
	digitalWrite(rev2,LOW);

	lcd.setCursor(0,0); 
	lcd.print("Turning Right"); 
	delay(4000) ; 
	lcd.clear(); 
 
}


