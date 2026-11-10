#include <Arduino.h>

#define BUTTON_PIN  4
#define LED_PIN     2
#define DEBOUNCE_MS 50

volatile uint32_t debouncedCount = 0;
volatile uint32_t rawEdgeCount = 0;
volatile unsigned long lastInterruptTime = 0;

void IRAM_ATTR handleInterrupt() {
  rawEdgeCount++;

  unsigned long now = millis();
  if (now - lastInterruptTime >= DEBOUNCE_MS) {
    debouncedCount++;
    lastInterruptTime = now;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleInterrupt, FALLING);
  Serial.printf("Debounce %d ms - rawEdgeCount / debouncedCount\n", DEBOUNCE_MS);
}

void loop() {
  static uint32_t lastRaw = 0, lastDeb = 0;
  uint32_t raw = rawEdgeCount;
  uint32_t deb = debouncedCount;
  if (deb != lastDeb) {
    digitalWrite(LED_PIN, deb % 2);
    lastDeb = deb;
  }
  if (raw != lastRaw) {
    Serial.printf("raw = %lu  debounced = %lu  (bo qua %lu)\n", raw, deb, raw - deb);
    lastRaw = raw;
  }
}
