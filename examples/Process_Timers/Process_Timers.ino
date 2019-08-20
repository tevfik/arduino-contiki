#include <contiki.h>

PROCESS(process1, "ETimer x Timer Process");
PROCESS(process2, "CTimer Process 2");

static int counter_etimer;
static int counter_timer;
static int counter_ctimer;
static struct timer timer_timer;
static struct ctimer timer_ctimer;

void
do_timeout1()
{
  counter_etimer++;
  if(timer_expired(&timer_timer)) {
    counter_timer++;
  }

  Serial.print("\nProcess 1: ");
  Serial.print((counter_timer == counter_etimer) ? "SUCCESS" : "FAIL");
}
/*---------------------------------------------------------------------------*/
void
do_timeout2(void *)
{
  ctimer_reset(&timer_ctimer);
  Serial.println("\nProcess 2: CTimer callback called");
  counter_ctimer++;
}
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(process1, ev, data)
{
  static struct etimer timer_etimer;

  PROCESS_BEGIN();

  while(1) {
    timer_set(&timer_timer, 3 * CLOCK_SECOND);
    etimer_set(&timer_etimer, 3 * CLOCK_SECOND);
    PROCESS_WAIT_EVENT_UNTIL(ev == PROCESS_EVENT_TIMER);
    do_timeout1();
  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(process2, ev, data)
{
  PROCESS_BEGIN();

  while(1) {
    ctimer_set(&timer_ctimer, 5 * CLOCK_SECOND, do_timeout2, NULL);
    PROCESS_YIELD();
  }

  PROCESS_END();
}

void setup(){
  Serial.begin(9600);
  Serial.println("");
  Serial.println("Process init");
  process_init();
  Serial.println("etimer process start");
  process_start(&etimer_process, NULL);
  Serial.println("ctimer init");
  ctimer_init();
  Serial.println("process-1 init");
  process_start(&process1, NULL);
  Serial.println("process-2 init");
  process_start(&process2, NULL);  
}


void loop(){
  run_kernel();
}
