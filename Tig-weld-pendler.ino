/*
 * 
 * 
 * 
 */



/*
 * 
 * Kjøreplan

- Pendling ±90°

- Pendletid 0,5 – 3 sekunder fra -90° til +90°

- Starter i 0°, går ut til -90° og så fullt frem og tilbake

- Stopp så skal den fullføre pendling og returnere til null før den stopper.

- Kalibrering ut til -90° når strøm slås på 
 */

#include "TimerOne.h"
#include "userinput.h"

#define CENTER 0
#define STEPPS 200                  // Stepps from one end to the other
#define INITIAL_POSSTEP (-STEPPS/2) // From far left to the center, usually STEPPS/2


#define ON 1
#define OFF 0

#define RIGHT 0
#define LEFT  1
#define TURN_RIGHT 2
#define TURN_LEFT 3
#define TURN 2

volatile uint16_t timetostep = 0; 
volatile uint8_t pendel_state = OFF;
uint16_t position_step = INITIAL_POSSTEP;
static volatile uint8_t steppdir = 0;

void set_position(int pos);
void goto_extreem_left(void);
void setup_timer(void);

void setup() {
//  init outputs

   INIT_position();
   Timer1.initialize(10); // 10 us between timer interrupts
   Timer1.attachInterrupt(timerloop);
   pinMode(APIN, OUTPUT);
   pinMode(BPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // input

  while(1)
  {
    stepp();
    delay(100);
    
  }

}
void INIT_position(void)
{

  
}


void goto_extreem_left(void)
{
  int i;

  steppdir = 0;

  for(i=0; i<(STEPPS * 4); i++)
  {
    stepp();
  }
}

/*
 * Timer loop, looptime = 10 us
 * 
 * Minimum number of 10 us counts in one step i approximatly 125
 */
void timerloop()
{

  
  if(--timetostep == 0)
  {
    timetostep = 92;
    stepp();
  }
  
}

/*
 * Updates the direction pin, enables the STEPPIN etc based on position. 
 * 
 */

void update_step(void)
{
  static int16_t position_step = INITIAL_POSSTEP;
}

/**
@brief Calculation the time between steps in micro seconds.
@returns time between each step
@arg pendel-frequency [Hz]
@arg max-travle [steps]
**/
uint32_t timebetweensteps_us(float pendlefrequency, uint16_t steps)
{
  float timebetweensteps = 1250; // default if no valid input
  if(steps > 0)
    timebetweensteps = 1.0 / pendle-frequency * (float)steps;
  return((int)timebetweensteps);
}


void stepp(void)
{
  static int8_t pos=0;
  static uint8_t table[8] = {3,2,6,4,12,8,9,1};

  switch(steppdir)
  {
    case RIGHT:    
      pos++;
      if(pos>=8)
        pos = 0;
      break;
      
    case LEFT:
      pos--;
      if(pos<=0)
        pos = 7;
      break;
      
    case TURN_RIGHT:
      steppdir = RIGHT;
      return; 

    case TURN_LEFT:
      steppdir = LEFT;
      return; 
  }
  
  if(table[pos] & 1)
    digitalWrite(APIN, HIGH);
  else
    digitalWrite(APIN, LOW);

  if(table[pos] & 2)
    digitalWrite(BPIN, HIGH);
  else
    digitalWrite(BPIN, LOW);
}
