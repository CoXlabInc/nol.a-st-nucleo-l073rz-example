#include <cox.h>

Timer timerHello;

#define LD2  D13
extern uint32_t SystemCoreClock;


static void taskHello(void *) {
  printf("Hello World!\n");
  digitalToggle(LD2);
}

void setup() {
  Serial.begin(115200);
  Serial.printf("\n*** [ST Nucleo-L073RZ] Basic Functions ***\n");

  if (SystemCoreClock == 32000000ul) {
    pinMode(LD2, OUTPUT);
    digitalWrite(LD2, HIGH);
  }

  timerHello.onFired(taskHello, NULL);
  timerHello.startPeriodic(1000);
}
