//Flap trigger connected to pin 2
int inner_flap_pin = 6;
int outer_flap_pin = 10;

void setup() {
  Serial.begin(9600);           
  pinMode(inner_flap_pin, INPUT);
  pinMode(outer_flap_pin, INPUT);
}

int last_read_inner = 0;
int last_read_outer = 0;

void loop() {
  int inner_read = digitalRead(inner_flap_pin);
  if (inner_read == HIGH) {
    // Cat flap open
    if (last_read_inner == LOW) {
      // The cat flap was closed between reads.
      // This prevents mutlitple posts if the flap 
      // is held open
      last_read_inner = HIGH;
      Serial.print("1");
    }
  } else {
    // Closed again, so reset last_read
    //Serial.println("inner is 0");
    last_read_inner = LOW;
  }
  
  // Same for the other flap
  int outer_read = digitalRead(outer_flap_pin);
  if (outer_read == HIGH) {
    if (last_read_outer == LOW) {
      last_read_outer = HIGH;
      Serial.print("2");
    }
  } else {
    //Serial.println("Outer is 0");
    last_read_outer = LOW;
  }
  // Small delay before next loop
  delay(500);
}
