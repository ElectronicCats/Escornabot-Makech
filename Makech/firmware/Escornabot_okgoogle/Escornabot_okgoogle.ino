// Escornabot with Google Assistant
//
// Electronic Cats invests time and resources providing this open source code.
// Please support Electronic Cats and open source hardware by purchasing
// products from Electronic Cats!
//
// Written by Andres Sabas for Electronic cats
// Copyright (c) 2019 Electronic Cats
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

AdafruitIO_Feed *command = io.feed("voice-commands"); // Set up the 'command' feed

// These are used to set the direction of the bridge driver.
#define ENB 3      //ENB
#define MOTORB_1 4 //IN3
#define MOTORB_2 5 //IN4
#define MOTORA_1 7 //IN1
#define MOTORA_2 6 //IN2
#define ENA 8      //ENA

// SETUP
void setup()
{
  // Configure pins
  pinMode(ENA, OUTPUT);
  pinMode(MOTORA_1, OUTPUT);
  pinMode(MOTORA_2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(MOTORB_1, OUTPUT);
  pinMode(MOTORB_2, OUTPUT);

  // disable both motors
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  
  // Start serial communication
  Serial.begin(9600);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'command' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  command->onMessage(handleMessage);  

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(50);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}

// MAIN CODE
void loop()
{
  io.run();
}

// this part of the code runs whenever there's a new message on Adafruit.io feed
void handleMessage(AdafruitIO_Data *data) {
  
  String commandStr = data->toString(); // store the incoming commands in a string
  
  // received message
  Serial.print("received <- ");
  Serial.println(commandStr);

  String cmd;
  int angle;

  // separate text and number ingredients
  for (int i = 0; i < commandStr.length(); i++) {
    if (commandStr.substring(i, i+1) == ":") {
      cmd = commandStr.substring(0, i);
      angle = commandStr.substring(i+1).toInt();
      break;
    }
  }

  // print command
  Serial.println(cmd);
  Serial.println(angle);
  
  // perform movements
  // LEFT
  if (cmd.equalsIgnoreCase("left")){    
    Serial.println("Turning left");
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(MOTORA_1,HIGH);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
    delay(angle*15);
    Serial.println("Stop");
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
  // RIGHT
  if (cmd.equalsIgnoreCase("right")){    
    Serial.println("Turning right");
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,HIGH);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
    delay(angle*15);
    Serial.println("Stop");
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
  // FORWARD
  if (cmd.equalsIgnoreCase("forward")){    
    Serial.println("Moving forward");
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(MOTORA_1,HIGH);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
    delay(angle*15);
    Serial.println("Stop");
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
  // BACK
  if (cmd.equalsIgnoreCase("back")){    
    Serial.println("Moving back");
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,HIGH);
    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
    delay(angle*15);
    Serial.println("Stop");
    digitalWrite(ENA,LOW);
    digitalWrite(ENB,LOW);
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }  
} 
