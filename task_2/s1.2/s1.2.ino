#include <ros.h>
#include <std_msgs/UInt8.h>
#include  <LiquidCrystal.h>

ros::NodeHandle  nh;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7 );

byte pixel[8] = {
  0b00001,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
};

int cellXSize = 5; // кол-во пикселей в клетке по горизонтали
int cellYSize = 8;// кол-во пикселей в клетке по вертикали

int pixelPos[2] = {cellXSize * 8 - 1, cellYSize * 1}; // текущий пиксель по Х и по Y
int linePos[2] = {7, 1};

void commandCollback(std_msgs::UInt8 value) {
    // Serial.println(value.data);
    char symbol = value.data;
    switch (symbol)
    {
        case 'W': case 'w':
            calcNewPosition(0);
            break;
        case 'S': case 's':
            calcNewPosition(1);
            break;
        case 'A': case 'a':
            calcNewPosition(2);
            break;
        case 'D': case 'd':
            calcNewPosition(3);
            break;
        default:
            break;
    }
}

// 0 - up, 1 - down, 2 - left, 3 - right
void calcNewPosition(int direction) {
  // ставим ограничения, чтобы пиксель упирался в лимиты по X и Y
  switch (direction) {
    case 0: 
      pixelPos[1] = pixelPos[1] > 0 ? pixelPos[1] - 1 : pixelPos[1];
      break;
    case 1: 
      pixelPos[1] = pixelPos[1] < cellYSize * 2 - 1 ? pixelPos[1] + 1: pixelPos[1];
      break;
    case 2: 
      pixelPos[0] = pixelPos[0] > 0 ? pixelPos[0] - 1 : pixelPos[0];
      break;
    case 3: 
      pixelPos[0] = pixelPos[0] < cellXSize * 16 - 1 ? pixelPos[0] + 1 : pixelPos[0];
      break;
  }
  recalcPixel();
}

int pow2(int deg) {
  int res = 1;
  for (size_t i = 0; i < deg; ++i) {
    res *= 2;
  }
  return res;
}

// пересчет позиции пикселя
void recalcPixel() {
  linePos[0] = pixelPos[0] / cellXSize; // вычисляем, в какой мы клетке по X (0..7)
  linePos[1] = pixelPos[1] / cellYSize; // вычисляем, в какой мы клетке по Y (0..1)
  clearPixel();
  /* индекс - это значение внутри клетки по оси Y (значение, которое мы заполняем)
     значение - степень двойки в байтах в зависимости от положения X */
  pixel[pixelPos[1] % cellYSize] = byte(pow2(4 - (pixelPos[0] % cellXSize)) );
}



// для публикации команд используем led_commandor пакет
// принимаем команды из топика /command
ros::Subscriber<std_msgs::UInt8> command_sub("/command", commandCollback);

void clearPixel() {
  for (size_t i = 0; i < 8; ++i) {
    pixel[i] = 0b00000;
  }
}

void writePixel() {
  lcd.clear();
  lcd.createChar(0, pixel); // каждый раз пересоздаем пиксель
  lcd.setCursor(linePos[0], linePos[1]);
  lcd.write(byte(0));
}

void setup() {

  lcd.begin(16, 2); //Инициализируем дисплей: 2 строки по 16 символов
  writePixel();
  
  nh.initNode();
  nh.subscribe(command_sub);
}

void loop() {
  writePixel();
  nh.spinOnce();
  delay(100);
}
