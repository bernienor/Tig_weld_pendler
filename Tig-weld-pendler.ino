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

#include "userinput.h"

#define CENTER 0
#define STEPPS 200 // Stepps from one end to the other
#define FAR_LEFT (-STEPPS/2) // From faar left to the center, usually STEPPS/2

#define ON 1
#define OFF 0

volatile uint16_t timetostep = 0; 
volatile uint8_t pendel_state = OFF;
uint16_t sposition = 0;

void set_position(int pos);
void   goto_extreem_left(void);

void setup() {
//  init outputs

  goto_extreem_left();

  //goto_pos(CENTER);
  setup_timer();
  
}

void loop() {
  // put your main code here, to run repeatedly:



//init()
//Go_to_extreem_left()
//Go_to_center()

  while(1)
  {
    if(digitalRead(ONOFF_PIN))
      pendel_state=ON;
    //Update_pendle(speed(analoginput_1),ampliture(analoginput_2));
  }

}
void set_position(int pos)
{
  sposition = pos;
}


void goto_extreem_left(void)
{
  int i;

  digitalWrite(DIRPIN, HIGH);

  for(i=0; i<(STEPPS * 2); i++)
  {
    digitalWrite(STEPPIN, HIGH);
    delay(5);
    digitalWrite(STEPPIN, LOW);
    delay(5);    
  }
  set_position(FAR_LEFT);  
}

/*
 * Timer loop, looptime = 10 us
 * 
 * Minimum number of 10 us counts in one step i approximatly 125
 */
void timerloop()
{

  if(timetostep < 10)
  {
    digitalWrite(STEPPIN, HIGH);
  }
  else
  {
    digitalWrite(STEPPIN, LOW);
  }
  
  if(--timetostep == 0)
  {
    timetostep = 125;
  }
  

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
//    timebetweensteps = pendle-frequency / (float)steps;
  return((int)timebetweensteps);
}

void   setup_timer(void)
{

  
}
