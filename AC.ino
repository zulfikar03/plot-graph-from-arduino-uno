#include <Filters.h>

float testFrequency = 50;                     // signal frequency (Hz)
float windowLength = 40.0/testFrequency;     // how long to average the signal, for statistist

int Sensor = 0;                 

float intercept = -0.25;  // adjust untuk kalibrasi
float slope = 0.0964;   // adjust untuk kalibrasi
float current_Volts;      

unsigned long printPeriod = 100;     //Refresh rate
unsigned long previousMillis = 0;

void setup() {
  Serial.begin( 9600 );
  //Serial.println("AC Voltmeter");
  //delay(5000);
}

void loop() {
  
  RunningStatistics inputStats;               
  inputStats.setWindowSecs( windowLength );
   
  while( true ) {   
    Sensor = analogRead(A0);                // read the analog in value:
    inputStats.input(Sensor);                   // log to Stats function
        
    if((unsigned long)(millis() - previousMillis) >= printPeriod) {
      previousMillis = millis();                // update time every second
      
      current_Volts = intercept + slope * inputStats.sigma(); //Calibartions for offset and amplitude
      //current_Volts= current_Volts*(49.3231);                //Further calibrations for the amplitude     
      
      //Serial.print( "Voltage: " );
      Serial.println( current_Volts );      
    }
  }

}
