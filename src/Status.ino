const int pinLDR = 2; 
String comando = "";   // Aquí guardaremos lo que escribe el usuario

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("=== MENU DE COMANDES ===");
  Serial.println("Escriu STATUS per veure el valor del LDR");
  Serial.println("==========================");
}

void loop() {

  // Si hi ha text disponible al port sèrie...
  if (Serial.available() > 0) {
    comando = Serial.readStringUntil('\n');  // Llegim la línia
    comando.trim();                          // Eliminem espais i salts

    // Comprovem el comandament
    if (comando.equalsIgnoreCase("STATUS")) {
      int valor = analogRead(pinLDR);
      Serial.print("Llum detectada: ");
      Serial.println(valor);
    }
    else {
      Serial.println("Comanda no reconeguda. Escriu STATUS.");
    }
  }

  delay(50); // Petita pausa per estabilitat
}
