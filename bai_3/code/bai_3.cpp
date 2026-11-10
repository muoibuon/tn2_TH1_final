#include <Arduino.h>

#define ADC 34
#define LED 18
#define N 8
int buf[N]; int idx = 0;

void setup() {
  Serial.begin(115200);
  ledcAttach(LED, 5000, 8);
}

int loc(int m) {
  buf[idx] = m; idx = (idx + 1) % N;
  long t = 0; for (int i = 0; i < N; i++) t += buf[i];
  return t / N;
}

void loop() {
  int tho = analogRead(ADC);
  int l = loc(tho);
  ledcWrite(LED, map(l, 0, 4095, 0, 255));
  Serial.print(">tho:"); Serial.println(tho);
  Serial.print(">loc:"); Serial.println(l);
  delay(20);
}
