/*  eeprom_read_byte(0) - Red          (0 - 255)
 *  eeprom_read_byte(1) - Green        (0 - 255)          ---   xxx(R)xxx(G)xxx(B)                  = 9 символов
 *  eeprom_read_byte(2) - Blue         (0 - 255)
 *  
 *  eeprom_read_byte(3) - Brightness   (0 - 255)          ---   xxx(3)                              = 3 символа
 */
 
#include <FastLED.h>
#include <avr/io.h> 
#include <avr/EEPROM.h>

#define LED_PIN        7              // Номер пина, куда подключена лента
#define LED_COUNT      30             // Количество пикселей в ленте 

CRGB leds[LED_COUNT];

String input = "";
byte data = 0;

void setup() 
{
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, LED_COUNT).setCorrection( TypicalLEDStrip );
  Serial.begin(9600);
  Serial.setTimeout(100);        // Время ожидания на получение данных из Serial-порта, чем меньше - тем быстрее принимаются данные
  StaticMode();
}

void loop() 
{ 
  if (Serial.available()) 
  {
   input = Serial.readString();
   data = 1;
  }
  
  if(data == 1) 
  {
    eeprom_update_byte(0, input.substring(0, 3).toInt()); // Здесь мы сохраняем в энергонезависимую память значения цветов, чтобы при последующем
    eeprom_update_byte(1, input.substring(3, 6).toInt()); // включении ардуины, лента "загорелась" теми же цветами, корторые мы выбрали
    eeprom_update_byte(2, input.substring(6, 9).toInt());
    StaticMode();
    data = 0;
  }
}

void StaticMode()  // Метод, который передает данные в ленту и "зажигает светодиоды"
{
  fill_solid( leds, LED_COUNT, CRGB(eeprom_read_byte(0), eeprom_read_byte(1), eeprom_read_byte(2)));
  FastLED.show();
  return;
}
