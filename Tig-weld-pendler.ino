
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
#include <Stepper.h>


#define CENTER 0
#define STEPPS 100                  // Stepps from one end to the other
#define INITIAL_STEPPS (STEPPS * 2)
#define INITIAL_POSSTEP (-STEPPS/2) // From far left to the center, usually STEPPS/2


#define ON 1
#define OFF 0



Stepper stepper(STEPPS, 6, 4, 5, 7);

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(30); // Initial speed in rpms
  stepper.step(INITIAL_STEPPS); // Move to end stop
  stepper.step(INITIAL_POSSTEP); // Move back to center
  Serial.println("Initiated");
}

void loop() {
 


   // read ADCs
   // set parameters

   stepper.setSpeed(rpms(amplitude(), periode_time()));
   run_cycle(num_of_steps(amplitude()));   
   Serial.println();
   Serial.println();
   
}


void test_run(void)
{
//stepper.setSpeed(120);
  stepper.step(STEPPS/2);
  delay(10);
  stepper.step(-STEPPS);
  delay(10);
  stepper.step(STEPPS/2);
  delay(1000);
}

void run_cycle(int steps)
{
  stepper.step(steps);
  delay(10);
  stepper.step(steps * -2);
  delay(10);
  stepper.step(steps);

}


/// Reads analouge input and returns the amplitude in the interval [0.2, 1.0]
float amplitude(void)
{
  float input;
  input = analogRead( CYCLEAMPLITUDEPIN);
  input = input / ANALOGMAX;
  if(input < 0.2)
    input = 0.2;
  Serial.print("Amplitude: ");
  Serial.println(input);    
  return(input);
}


/// Reads analouge input and returns the frequency in the interval [0.5, 3.0] 
float periode_time(void)
{  
  float input;
  input = analogRead( CYCLETIMEPIN);
  Serial.print("Cycle time: ");
  Serial.println(0.5 + ( (2.5 * input) / ANALOGMAX ));
  return( 0.5 + ( (2.5 * input) / ANALOGMAX ));
}


/// Calculates the RPM of the stepper motor with the given amplitude and periode time.
int rpms(float amplitude, float periode)
{
  float rpms;
  int temp;
  rpms = amplitude * (1/periode) * 60.0;
  Serial.print("rpms: ");
  Serial.println(rpms);
  if(rpms < 4.0)
    rpms = 4.0; // minimum value  
  return((int) rpms);  
}


/// Returns the number of steps from one end to the other with the given amplitude
int num_of_steps(float amplitude)
{
   float steps;
   steps = STEPPS; // Get STEPPS to float)
   steps = steps * amplitude * 0.5;
   Serial.print("Number of steps: ");
   Serial.println(steps);
   return((int)steps);
}
