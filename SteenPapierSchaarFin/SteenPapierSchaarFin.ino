#include <Wire.h>   //opent de Wire bibliotheek
#include <LiquidCrystal_I2C.h> // opent de LiquidCrystal_I2C bibliotheek die je kan downloaden via hulpmiddelen -> bibliotheken beheren. Dan vervolgens LiquidCrystal I2C op te zoeken en de bibliothee die gemaakt is door Frank de Brabander te installeren.
char *SPS[]={"Steen", "Papier", "Schaar"}; // dit is een lijst met de 3 verschillende mogelijkheden.
long SPS1; // hier wordt het willekeurige antwoord opgeslagen.

LiquidCrystal_I2C lcd(0x27,16,2);  // zet het adress van de lcd op 0x27 met 16 characters en 2 lijnen.

void setup()
{
  pinMode(2, INPUT); // zet pin 2 als input.
  pinMode(3, OUTPUT); // zet pin 3 als output.
  pinMode(4, OUTPUT); // zet pin 4 als output.
  pinMode(5, OUTPUT); // zet pin 5 als output.
  lcd.init(); // zet het lcd schermpje aan.
  lcd.backlight(); // zet de backlight van het lcd schermpje aan.
  lcd.setCursor(0,0); // zorgt ervoor dat hij bovenaan begint met typen.
  randomSeed(analogRead(A0)); // zorgt ervoor dat het gekozen woord daadwerkelijk willekeurig is
}


void loop()
{

 
  lcd.clear(); // maakt het schermpje leeg
  if (digitalRead(2) == 1) // dit wordt geactiveert als de knop wordt ingedrukt.
  {
   delay(500); // wacht 0,5 seconden.
   lcd.print("3"); //laat 3 zien op het schermpje.
   digitalWrite(3, HIGH); // zet pin 3 aan.
   lcd.setCursor(0,0); // zorgt ervoor dat hij bovenaan begint met typen.
   delay(500); // wacht 0,5 seconden.
   digitalWrite(3, LOW); // zet pin 3 uit.
   digitalWrite(4, HIGH); // zet pin 4 aan.
   lcd.print("2"); //laat 2 zien op het schermpje.
   lcd.setCursor(0,0); // zorgt ervoor dat hij bovenaan begint met typen.
   delay(500); // wacht 0,5 seconden.
   digitalWrite(4, LOW); // zet pin 4 uit.
   digitalWrite(5, HIGH); // zet pin 5 aan.
   lcd.setCursor(0,0); // zorgt ervoor dat hij bovenaan begint met typen.
   lcd.print("1"); //laat 1 zien op het schermpje.
   delay(500); // wacht 0,5 seconden.
   digitalWrite(3, HIGH); // zet pin 3 aan.
   digitalWrite(4, HIGH); // zet pin 4 aan.
   delay(200); // wacht 0,2 seconden.

   
   SPS1 = random(sizeof(SPS)/sizeof(char*)); // kiest een willekeurig woord
   lcd.setCursor(0,0); // zorgt ervoor dat het woord op de goede plek verschijnt.
   lcd.print(SPS[SPS1]); // laat het willekeurig woord zien
   delay(1500); // wacht 1,5 seconden.
   digitalWrite(3, LOW); // zet pin 3 uit.
   digitalWrite(4, LOW); // zet pin 4 uit.
   digitalWrite(5, LOW); // zet pin 5 uit.
  }
  }
