/*******************************************************************
    A sketch for controlling a Small Blimp with using a web page
    hosted on a ESP12
    Code by:
    /* Eduardo Chamorro Martin - eduardochamorromartin@gmail.com - http://eduardochamorro.github.io/beansreels/index.html
    Based on the code developped by Brian Lough

 *******************************************************************/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>


// These are the pins used to control the motor shield

#define MOTOR_DIRECTION2 D2 // Motor Right
#define MOTOR_DIRECTION1 D5 // Motor Left
#define MOTOR_LIFT D1 // Motor Up
#define CONNECTION D4 // Motor Up

// drivePower sets how fast the car goes
// Can be set between 0 and 1023 (although car problaly wont move if values are too low)
int LiftPower = 1023;

// steeringPower sets how fast the car turns
// Can be set between 0 and 1023 (again, car probably won't steer if the value is too low)
int TurningPower = 1023;


// ----------------
// Set your WiFi SSID and Password here
// ----------------
const char* ssid = "FABBLIMP";
const char* password = "12345678";



/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

const char *webpage =
#include "index.h"
  ;

void handleRoot() {
  server.send(200, "text/html", webpage);
}



void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {

  pinMode(MOTOR_DIRECTION2, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(MOTOR_DIRECTION1, OUTPUT);
  pinMode(MOTOR_LIFT, OUTPUT);
  pinMode(CONNECTION, OUTPUT);




  Serial.begin(115200);
  
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  

  server.on("/", handleRoot);
  
  server.begin();
  Serial.println("HTTP server started");




  server.on("/up", []() {
    Serial.println("up");
    analogWrite(MOTOR_LIFT, LiftPower);
    server.send(200, "text/plain", "up");
  });

  server.on("/driveStop", []() {
    Serial.println("driveStop");
    analogWrite(MOTOR_LIFT, 0);
    server.send(200, "text/plain", "driveStop");
  });
  server.on("/back", []() {
    Serial.println("back");
    analogWrite(MOTOR_DIRECTION1, TurningPower);
    analogWrite(MOTOR_DIRECTION2, TurningPower);
    server.send(200, "text/plain", "back");
  });

  server.on("/right", []() {
    Serial.println("right");
    analogWrite(MOTOR_DIRECTION1, TurningPower);
    server.send(200, "text/plain", "right");
  });

  server.on("/left", []() {
    Serial.println("left");
    analogWrite(MOTOR_DIRECTION2, TurningPower);
    server.send(200, "text/plain", "left");
  });

  server.on("/steerStop", []() {
    Serial.println("steerStop");
    analogWrite(MOTOR_DIRECTION2, 0);
    analogWrite(MOTOR_DIRECTION1, 0);
    server.send(200, "text/plain", "steerStop");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP Server Started");
}

void loop(void) {
  server.handleClient();
}
