import processing.serial.*;
 
Serial myPort;
 
void setup(){
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
}
 
void draw(){
  myPort.write('x');
  delay(1000);
  myPort.write('o');
  delay(1000);
}
