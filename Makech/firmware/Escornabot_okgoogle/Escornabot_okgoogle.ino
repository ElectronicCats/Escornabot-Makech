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

AdafruitIO_Feed *command = io.feed("escornabot"); // Set up the 'command' feed

////////////////////////
// DEBUG DEFINITIONS ////               
/////////////////////////
//#define DEBUG

// SETUP
void setup()
{
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
  
  #ifdef DEBUG
  // received message
  Serial.print("received <- ");
  Serial.println(commandStr);
  #endif
  
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

  #ifdef DEBUG
  // print command
  Serial.println(cmd);
  Serial.println(angle);
  #endif
  
  // perform movements
  // LEFT
  if (cmd.equalsIgnoreCase("izquierda")){    
    #ifdef DEBUG
    Serial.println("Girando a la izquierda");
    #endif
    delay(250);
    #ifdef DEBUG
    Serial.println("Alto");
    #endif
    delay(250);
  }
  // RIGHT
  if (cmd.equalsIgnoreCase("derecha")){ 
    #ifdef DEBUG   
    Serial.println("Girando a la derecha");
    #endif
    delay(250);
    #ifdef DEBUG
    Serial.println("Alto");
    #endif
    delay(250);
  }
  // FORWARD
  if (cmd.equalsIgnoreCase("adelante")){ 
    #ifdef DEBUG   
    Serial.println("Moviendose adelante");
    #endif
    delay(250);
    #ifdef DEBUG
    Serial.println("Alto");
    #endif
    delay(250);
  }
  // BACK
  if (cmd.equalsIgnoreCase("atras")){ 
    #ifdef DEBUG   
    Serial.println("Moviendose atras");
    #endif
    delay(250);
    #ifdef DEBUG
    Serial.println("Alto");
    #endif
    delay(250);
  }  
} 
