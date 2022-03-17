/*
  Modbus-Arduino Example - Test Led using callback (Modbus IP ESP8266/ESP32)
  Control a Led on D4 pin using Write Single Coil Modbus Function
  Original library
  Copyright by André Sarmento Barbosa
  http://github.com/andresarmento/modbus-arduino

  Current version
  (c)2017 Alexander Emelianov (a.m.emelianov@gmail.com)
  https://github.com/emelianov/modbus-esp8266
*/
// modified exaplefile for connect LOGO PLC by modbus

#ifdef ESP8266
#include <ESP8266WiFi.h>
#else //ESP32
#include <WiFi.h>
#endif
#include <ModbusIP_ESP8266.h>

//Modbus Registers Offsets
const int LED_COIL = 9; // in LOGO is nr 10
const int LED_COIL2 = 10;// in LOGO is nr 11

//ModbusIP object
ModbusIP mb;

// Callback function for write (set) Coil. Returns value to store.
uint16_t cbLed(TRegister* reg, uint16_t val) {
  //get value from LOGO input 1
  
    //Serial.println(val);

  // send back to relay in LOGO module
  mb.Coil(LED_COIL2, val);

  return val;
}

// Callback function for client connect. Returns true to allow connection.
bool cbConn(IPAddress ip) {
  Serial.println(ip);
  return true;
}

void setup() {
  Serial.begin(115200);
// Set your Static IP address
IPAddress ip(192, 168, 0, 200);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //

WiFi.config(ip, dns, gateway, subnet);

  WiFi.begin("your sid", "your pw");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  mb.onConnect(cbConn);   // Add callback on connection event
  mb.server();

  
  mb.addCoil(LED_COIL);  // Add Coil. input 1 in LOGO
  mb.addCoil(LED_COIL2);// Add Coil. relay 1 in LOGO
  mb.onSetCoil(LED_COIL, cbLed); // Add callback on Coil LED_COIL value set
}

void loop() {
  //Call once inside loop() - all magic here
  mb.task();
  delay(10);
}
