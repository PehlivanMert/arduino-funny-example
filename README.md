# Arduino LED Dans Efekti Projesi

Bu proje, Arduino kullanarak 6 adet LED ile çeşitli dans efektleri oluşturur.

## Malzemeler
- Arduino (Uno, Nano veya benzeri)
- 6 adet LED
- 6 adet 220 ohm direnç
- Breadboard
- Jumper kablolar

## Bağlantılar
LED'ler tersten şu pinlere bağlanmalıdır:
- LED 1 -> Pin 8
- LED 2 -> Pin 7
- LED 3 -> Pin 6
- LED 4 -> Pin 4
- LED 5 -> Pin 3
- LED 6 -> Pin 2

Her LED'in uzun bacağı (anot) Arduino pinine, kısa bacağı (katot) 220 ohm direnç üzerinden GND'ye bağlanmalıdır.

## Efektler
Projede bulunan efektler:
1. **Hızlı Dalga**: LED'ler sırayla hızlıca yanıp söner
2. **Parlaklık Değişimi**: LED'ler farklı parlaklık seviyelerinde yanar
3. **Kaleidoskop Dansı**: Merkezden dışa doğru yayılan efekt
4. **Spiral Dansı**: LED'ler sırayla dönerek yanar
5. **Çapraz Dans**: Karşılıklı LED'ler birlikte yanıp söner
6. **Titreme Dansı**: LED'ler rastgele parlaklıklarda titrer
7. **Polis Efekti**: LED'ler polis arabası gibi yanıp söner

## Kurulum
1. Arduino IDE'yi açın
2. `src/main.cpp` dosyasını yükleyin
3. Arduino'ya yükleyin
4. LED'lerin bağlantılarını kontrol edin
5. Arduino'yu çalıştırın

## Özelleştirme
- Efektlerin hızını değiştirmek için `delay()` değerlerini ayarlayabilirsiniz
- Yeni efektler eklemek için `loop()` fonksiyonuna yeni kodlar ekleyebilirsiniz
- LED pinlerini değiştirmek için `ledPins` dizisini düzenleyebilirsiniz

## Notlar
- LED'lerin doğru yönde bağlandığından emin olun
- Dirençlerin LED'lerin yanmasını önlemek için gerekli olduğunu unutmayın
- Arduino'nun 5V çıkışından güç alındığından emin olun 