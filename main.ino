const int LED_PIN = 3; //PWM~

const int LED_DELAY = 30000; //ms per 1/256th step to full brightness
const int DELAY_PER_LOOP = 990; //ms

long startHour = 21;
long startMinute = 13;
long startSecond = 8;

long alarmHour = 7 + 24; //+24 for the next day
long alarmMinute = 30;
long alarmSecond = 0;

long startTime = startHour * 3600 + startMinute * 60 + startSecond;
long alarmTime = alarmHour * 3600 + alarmMinute * 60 + alarmSecond;
long time = startTime; //seconds

bool alarmStarted = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  time = startTime + millis() / 1000;

  Serial.println(String((time / 3600) % 24) + ":" + String((time / 60) % 60) + ":" + String(time % 60));

  if (alarmStarted) {
    analogWrite(LED_PIN, 255);

  } else if (time > alarmTime) {
    Serial.println("Starting alarm...");
    alarmStarted = true;

    for (int i = 0; i < 255; i++) {
      analogWrite(LED_PIN, i); //0-255
      Serial.println(i);
      delay(LED_DELAY);
    }
  }

  delay(DELAY_PER_LOOP);
}
