#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
int backlight = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(backlight, OUTPUT);
  digitalWrite(backlight, HIGH);
  lcd.begin(16, 2);
  lcd.print("ready");
  delay(500);
  lcd.clear();
}

void msg(String h) {
  int r;
  if(h.length()%16>0){
    r = (h.length()/16) +1;
  }
  else{
    r = h.length() / 16;
  }
  for(int i = 0; i < r;i++) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(h.substring(i*16,(i+1)*16));
    lcd.setCursor(0,1);
    lcd.print(h.substring((i+1)*16,(i+2)*16));
    delay(3000);
    lcd.clear();
  }
  digitalWrite(backlight, LOW);
  delay(3000);
  digitalWrite(backlight, HIGH);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  msg("Ever since the day I was born, I've always been based.");  
  msg("One who cannot abandon his humanity, cannot overcome monsters.");
  msg("Demon Slayer is better than Seven Deadly Sins");
  msg("Mikasa is literally female perfection");
}
