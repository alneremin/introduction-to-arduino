#include <ros.h>
#include <std_msgs/Float32.h>

ros::NodeHandle nh;

std_msgs::Float32 temperature;
ros::Publisher temperPub("/temperature", &temperature);

std_msgs::Float32 noise;
ros::Publisher noisePub("/noise", &noise);

const int temperPin = A0;
const int noisePin = A1;

void setup() {
  nh.initNode();
  pinMode(temperPin, INPUT);
  pinMode(noisePin, INPUT);
  Serial.begin(57600);
  nh.advertise(temperPub);
  nh.advertise(noisePub);
}

void loop() {
  temperature.data = detectTemperature();
  temperPub.publish(&temperature);

  noise.data = analogRead(noisePin);
  noisePub.publish(&noise);
  nh.spinOnce();
  
}

/* --- Получение и калибровка данных с датчика температуры ---*/
/* Взято из https://arduino-tex.ru/news/48/ky-013-modul-analogovogo-datchika-temperatury.html */

int Vo;
float R1 = 10000; // значение R1 на модуле
float logR2, R2, T;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //коэффициенты Штейнхарта-Харта для термистора

float detectTemperature(){
  Vo = analogRead(temperPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //вычислите сопротивление на термисторе
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // температура в Кельвине
  T = T - 273.15; //преобразование Кельвина в Цельсия

  return T;
}
