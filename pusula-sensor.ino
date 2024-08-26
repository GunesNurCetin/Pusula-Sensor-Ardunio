#include <Wire.h>
#include <QMC5883LCompass.h>

QMC5883LCompass compass;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  compass.init();  // QMC5883L sensörünü başlat

  // Sensörün kalibrasyonunu yapıyoruz (örnek değerler verilmiştir)
  compass.setCalibration(-1000, 1000, -1000, 1000, -1000, 1000);
}

void loop() {
  int x, y, z;
  
  compass.read(); // Sensör verilerini oku
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  // Seri monitörde koordinatları göster
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" Y: ");
  Serial.print(y);
  Serial.print(" Z: ");
  Serial.println(z);

  delay(100); // Kısa bir gecikme
}
