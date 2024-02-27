/* https://www.nyebarilmu.com */

const int input_sensor = A0; // nama lain dari A0 yaitu input_sensor
const int output_pwm = 2; // nama lain dari 2 yaitu output_pwm
 
//nilai default variabel data
int nilai_adc= 00;    
int nilai_pwm = 00;    
float voltageOut= 00;
float voltage= 00;
 
void setup() {
  // inisialisasi komunikasi serial pada 960bps
  Serial.begin(9600); 
}
 
void loop() {
  nilai_adc = analogRead(input_sensor); // Prosedur pembacaan analog pin           
  // mapping pembacaan resolusi sensor
  nilai_pwm = map(nilai_adc, 0, 1023, 0, 255);  
  // mengubah nilai analog out
  analogWrite(output_pwm, nilai_pwm);    
 voltageOut = nilai_adc * (5.0 / 1023.0);  
 
  // Mencetak hasil ke monitor serial:
  Serial.print("sensor = " );                       
  Serial.println(nilai_adc);      
  Serial.print("output pwm= ");      
  Serial.println(nilai_pwm);   
  Serial.print("Voltage ADC = ");      
  Serial.println(voltageOut);
  delay(1500);  //jeda 2ms   
  Serial.println();                
}