 //WOMWN SAFETY
/*Flex sensor:
Thin strip of flex sensor=ground
Thick strip of flex sensor=A0
Thick strip of flex sensor is also connected to 47K ohm resistor. The other terminal of resistor is connected 5V()
Bluetooth module:
RX bluetooth= TX arduino
TX bluetooth= RX arduino
+5V bluetooth= +5V arduino
Ground bluetooth= ground arduino
*/ 

int value=0;
int resistance=0;

void setup() {
Serial.begin(9600); //9600 is baudrate
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
resistance=analogRead(A0);
delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
char x='0';
if(Serial.available())
{
  x=Serial.read();
  if(x=='1')
  {while(x!='0')
  {
    digitalWrite(13,HIGH);
    value=analogRead(A0);
    if((value-resistance)>=10||(resistance-value)>=10)
  {
    Serial.println(1);
    delay(10);
    }
    else
    {
      Serial.println(0);
      delay(10);
      }
    delay(2000);
    }
    }
  if(x=='0')
  digitalWrite(13,LOW);
  }
  delay(100);
}
