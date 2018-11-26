#include <cox.h>

Timer timerHello;

#define LD2    PA5
#define BUTTON PC13

void setup() {
  Serial.begin(115200);
  Serial.printf("\n*** [ST Nucleo-L073RZ] Basic Functions ***\n");

  pinMode(LD2, OUTPUT);

  timerHello.onFired(
    [](void *) {
      printf("Hello World!\n");
      digitalToggle(LD2);
    },
    NULL
  );
  timerHello.startPeriodic(1000);

  attachInterrupt(
    PC13,
    []() {
      printf("Button pressed!\n");
    },
    FALLING
  );
}
