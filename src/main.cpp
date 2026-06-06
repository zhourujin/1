#include <Arduino.h>
// 定义LED引脚数组
const int ledPins[] = {33,26,14,13};  // 使用GPIO2,4,5,18
const int ledCount = 4;                // LED数量

// 延时时间（毫秒），可以修改这个值来改变流水速度
const int delayTime = 200;             // 200ms，可改为100（更快）或500（更慢）

void setup() {
  // 初始化所有LED引脚为输出模式
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);     // 初始状态：所有LED熄灭
  }
}

void loop() {
  // 阶段1：从左到右依次点亮
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);    // 点亮当前LED
    delay(delayTime);                  // 保持点亮状态
  }
  
  // 阶段2：从左到右依次熄灭
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);     // 熄灭当前LED
    delay(delayTime);                  // 保持熄灭状态
  }
}