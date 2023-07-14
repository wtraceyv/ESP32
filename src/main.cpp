#include <Arduino.h>
#include <U8g2lib.h>
#include <led.h>
#include <helper.h>

#define OLED_WIDTH    128
#define OLED_HEIGHT   64
#define OLED_SDA      GPIO_NUM_17
#define OLED_SCL      GPIO_NUM_18
#define OLED_RST      GPIO_NUM_21

U8G2_SSD1306_128X64_NONAME_F_SW_I2C g_OLED(U8G2_R2, OLED_SCL, OLED_SDA, OLED_RST);
int g_lineHeight = 0;

// init
void setup() {
  printf("Setup GPIO...\n");
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  printf("Setup LCD...\n");
  g_OLED.begin();
  g_OLED.clear();
  g_OLED.setFont(u8g2_font_profont15_tf);
  g_lineHeight = g_OLED.getFontAscent() + g_OLED.getFontAscent();

  g_OLED.setCursor(0, g_lineHeight);
  g_OLED.print(testMessage());
  g_OLED.sendBuffer();
}

// tick
void loop() {
  // LED blinking
  blink(1500, 600);
}

