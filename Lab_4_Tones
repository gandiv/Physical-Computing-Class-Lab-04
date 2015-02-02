/*
Lab 4 - Music Studio X5
Parth Soni
CDIGF 2B03 Physical Computing S01
OCAD University
Created on [Feb 1 2015]
 
Based on:
Previous exp.
*/

/*The purpose of this code and device is, that a user can record
different tones using the IR and the flex sensor. The IR sensor controls
the frequency and the flex sensor controls the duration */

/* For smoothing out distance sensor, The flex sensor behaved in a controlled fashion
so this is only done for the IR */
const int totalReadings = 10;
int sensorValues[totalReadings];
int index = 0;
int total = 0;
int average = 0;
// For recording Tones
const int noteValues = 200;
int musicPlay[noteValues]; // Controlled by IR sensor
int intervals[noteValues]; // Controlled by Flex sensor

//Assigned Pins
int ledPin = 9;
int recordButton = 8;
int speakerPin = 11;
int playButton =2;
int sensorPin = A0;
int flexPin = A1;

// Index Vars for the Music
int musicIndex = 0;
int musicPlayIndex = 0;

void setup() {
  
  Serial.begin (9600);
  
  //Setting all values to 0
  for (int i = 0; i < totalReadings; i++){
    sensorValues[i]=0;
  }
  for (int i =0; i < noteValues; i++){
     musicPlay[i] = 0;
     intervals[i] = 0;
  }
  pinMode (ledPin, OUTPUT);
  pinMode (recordButton, INPUT);
  pinMode (playButton, INPUT);
  pinMode (speakerPin, OUTPUT);
}

void loop () {

  int buttonState = digitalRead (recordButton);// record button
  int playButton = digitalRead (playButton); // play buttong
  
  // if Play button is high, play recorded tunes
  if (playButton == HIGH ){
    playRecording ();
  }
  
  // if Record Button is pressed, record a new tune
  if (buttonState == HIGH ){
    digitalWrite (ledPin, HIGH);
    startRecording ();
  }
  else {
      digitalWrite (ledPin, LOW); // LED on/off to signify recording
  }

}
//records the tune
void startRecording () {
  
    int flexValue = analogRead(flexPin);
    total = total-sensorValues[index];
    sensorValues[index] = analogRead(sensorPin);
    total = total + sensorValues[index];
    index++;

    if (index >= totalReadings){
      index = 0;
    }
    musicIndex++;
    average = total / totalReadings;

    musicPlay[musicIndex] = average; 
    intervals[musicIndex] = flexValue/4;
    tone (speakerPin,musicPlay[musicIndex], intervals[musicIndex]);
    
    if (musicIndex == noteValues) {
      musicIndex = 0;
  
  }
    delay (100);

}

//plays recorded tunes
void playRecording () {
  
  /* This is done in an "if" fashion rather than for, so, if there is a
  long tune the user doesn't have to wait for the whole thing to finish */
  
    if (musicPlayIndex < noteValues){
     tone (speakerPin, musicPlay[musicPlayIndex], intervals[musicPlayIndex]);
     musicPlayIndex++;
     if (musicPlayIndex == noteValues){
     musicPlayIndex = 0;
     }
     delay(100);
    }
    

}
