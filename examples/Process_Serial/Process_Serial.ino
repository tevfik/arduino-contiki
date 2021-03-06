#include <contiki.h>

PROCESS(blink_process, "Blink Process");
PROCESS_THREAD(blink_process, ev, data)
{
  static struct etimer tick;
  PROCESS_BEGIN();

  etimer_set(&tick, CLOCK_SECOND);

  while (1) {
    PROCESS_WAIT_EVENT();
    if (ev == PROCESS_EVENT_TIMER && etimer_expired(&tick)) {
      Serial.println("1 second loop");
      etimer_reset(&tick);
    }
  }

  PROCESS_END();
}
 
void setup(){
  Serial.begin(9600);
  Serial.println("");
  Serial.println("kernel setup");
  kernel_setup();
  Serial.println("Blink process init");
  process_start(&blink_process, NULL);
}


void loop(){
  run_kernel();
}
