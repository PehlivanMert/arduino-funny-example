#include <Arduino.h>

// LED pinleri
const int ledPins[] = {6, 8, 2, 3, 4, 7};  // Güncellenmiş LED pinleri
const int ledCount = 6;  // LED sayısı

// PWM değerleri
const int brightnessLevels[] = {0, 64, 128, 192, 255};  // Daha az seviye, daha hızlı geçiş
const int levelCount = 5;

// Polis efekti için LED grupları
const int group1[] = {0, 2, 4};  // İlk grup LED'ler (6, 2, 4 pinleri)
const int group2[] = {1, 3, 5};  // İkinci grup LED'ler (8, 3, 7 pinleri)
const int groupSize = 3;  // Her gruptaki LED sayısı

void setup() {
  // Tüm LED pinlerini çıkış olarak ayarla
  for(int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("LED Dans Efekti Başladı!");
}

// Hızlı soluklaşma efekti
void quickFade(int pin, int startBrightness, int endBrightness) {
  if (startBrightness < endBrightness) {
    for(int i = startBrightness; i <= endBrightness; i += 5) {
      analogWrite(pin, i);
      delay(1);
    }
  } else {
    for(int i = startBrightness; i >= endBrightness; i -= 5) {
      analogWrite(pin, i);
      delay(1);
    }
  }
}

// Kaleidoskop dans efekti
void kaleidoscopeDance() {
  // Merkezden dışa doğru yayılan efekt
  for(int i = 0; i < 3; i++) {
    analogWrite(ledPins[2], 255);  // Merkez LED
    analogWrite(ledPins[3], 255);
    delay(50);
    
    analogWrite(ledPins[1], 255);  // İkinci halka
    analogWrite(ledPins[4], 255);
    delay(50);
    
    analogWrite(ledPins[0], 255);  // Dış halka
    analogWrite(ledPins[5], 255);
    delay(50);
    
    // Hepsini söndür
    for(int j = 0; j < ledCount; j++) {
      analogWrite(ledPins[j], 0);
    }
    delay(50);
  }
}

// Spiral dans efekti
void spiralDance() {
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < ledCount; j++) {
      analogWrite(ledPins[j], 255);
      delay(30);
      analogWrite(ledPins[j], 0);
    }
    for(int j = ledCount-1; j >= 0; j--) {
      analogWrite(ledPins[j], 255);
      delay(30);
      analogWrite(ledPins[j], 0);
    }
  }
}

// Polis arabası efekti
void policeEffect() {
  // Hızlı yanıp sönme (10 kez)
  for(int i = 0; i < 10; i++) {
    // İlk grup yanık, ikinci grup sönük
    for(int j = 0; j < groupSize; j++) {
      digitalWrite(ledPins[group1[j]], HIGH);
      digitalWrite(ledPins[group2[j]], LOW);
    }
    delay(50);  // Çok hızlı
    
    // İlk grup sönük, ikinci grup yanık
    for(int j = 0; j < groupSize; j++) {
      digitalWrite(ledPins[group1[j]], LOW);
      digitalWrite(ledPins[group2[j]], HIGH);
    }
    delay(50);
  }
  
  // Yavaş yanıp sönme (5 kez)
  for(int i = 0; i < 5; i++) {
    // İlk grup yanık, ikinci grup sönük
    for(int j = 0; j < groupSize; j++) {
      digitalWrite(ledPins[group1[j]], HIGH);
      digitalWrite(ledPins[group2[j]], LOW);
    }
    delay(200);
    
    // İlk grup sönük, ikinci grup yanık
    for(int j = 0; j < groupSize; j++) {
      digitalWrite(ledPins[group1[j]], LOW);
      digitalWrite(ledPins[group2[j]], HIGH);
    }
    delay(200);
  }
  
  // Çok hızlı titreme (20 kez)
  for(int i = 0; i < 20; i++) {
    // İlk grup yanık, ikinci grup sönük
    for(int j = 0; j < groupSize; j++) {
      digitalWrite(ledPins[group1[j]], HIGH);
      digitalWrite(ledPins[group2[j]], LOW);
    }
    delay(25);
    
    // İlk grup sönük, ikinci grup yanık
    for(int j = 0; j < groupSize; j++) {
      digitalWrite(ledPins[group1[j]], LOW);
      digitalWrite(ledPins[group2[j]], HIGH);
    }
    delay(25);
  }
}

void loop() {
  // Hızlı dalga efekti
  for(int i = 0; i < ledCount; i++) {
    quickFade(ledPins[i], 0, 255);
    quickFade(ledPins[i], 255, 0);
  }
  
  // Hızlı parlaklık değişimi
  for(int i = 0; i < 3; i++) {
    for(int level = 0; level < levelCount; level++) {
      for(int j = 0; j < ledCount; j++) {
        analogWrite(ledPins[j], brightnessLevels[level]);
      }
      delay(30);
    }
  }
  
  // Kaleidoskop dans efekti
  kaleidoscopeDance();
  
  // Spiral dans efekti
  spiralDance();
  
  // Hızlı çapraz dans
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < ledCount/2; j++) {
      quickFade(ledPins[j], 0, 255);
      quickFade(ledPins[ledCount-1-j], 0, 255);
      quickFade(ledPins[j], 255, 0);
      quickFade(ledPins[ledCount-1-j], 255, 0);
    }
  }
  
  // Hızlı titreme dansı
  for(int i = 0; i < 50; i++) {
    for(int j = 0; j < ledCount; j++) {
      analogWrite(ledPins[j], random(0, 256));
    }
    delay(10);
  }
  
  // Hızlı sıralı dans
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < ledCount; j++) {
      quickFade(ledPins[j], 0, 255);
    }
    for(int j = 0; j < ledCount; j++) {
      quickFade(ledPins[j], 255, 0);
    }
  }
  
  // Hızlı yanıp sönme dansı
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < ledCount; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(5);
    for(int j = 0; j < ledCount; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    delay(5);
  }
  
  // Kısa bir mola
  delay(200);

  policeEffect();
  delay(500);  // Kısa bir mola
}
