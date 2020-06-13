/*
 * Definitions for user inputs
 * 
 * 
 */


/*
 * En knapp, 3 posisjoner, 1: automatisk pendling ved start. 2: ingen pendling ved sveising. 3: starter pendling uten sveising (for å se hvordan pendlingen går)

- En knapp, 2 posisjoner, nødstopp/hovedbryter

- En knapp, 2 posisjoner med retur til senterposisjon. aktuator 1: høydejustering opp. 2: høydejustering ned.

- 1 stk potmeter 10kohm for å stille pendletid.

- 1 stk potmeter 10kohm for å stille pendlelengde.
- Pendling ±90°

- Pendletid 0,5 – 3 sekunder fra -90° til +90°
 */

#ifndef USERINPUT_H
#define USERINPUT_H

 // Analog input pins:

#define CYCLETIMEPIN A0
#define CYCLEAMPLITUDEPIN  A1

#define ANALOGMAX 840.0
#define ANALOGMIN 0.0

 // Limits

#define MINCYCLETIME 0.5
#define MAXCYCLETIME 3.0

#define MINCYCLELENGTH 5.0  // defines the treashold for stopping the cyclic movement 
#define MAXCYCLELENGTH 90.0

// Stepper motor interface

#define APIN   5
#define BPIN   6

// user input buttons 
#define ONOFF_PIN   3

#endif
