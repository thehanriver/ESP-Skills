#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define Main_State 0		// Main Menu state
#define Game_State 1		// Game state
#define Up_State 2		// Pop up state for moles
#define Stay_State 3		// Stay up state for moles
#define Down_State 4		// Pop down state for moles
#define Point_State 5		// Point state
#define Over_State 6		// Game over state


//events: click, hit, timer

void StateMachine(){
     int state = Main_State; 
     while (1)
     {
     	switch (state)
	{
		Main_State:
			if (CLICK_EVENT) {state = Game_State}
			if (HIT_EVENT) {state = Main_State}
			if (TIMER_EVENT) {state = Main_State}
			// Main Menu. If user clicks it starts the game otherwise it just stays.
			break;
		Game_State:
			if (CLICK_EVENT) {state = Up_State}
			if (HIT_EVENT) {state = Game_State}
			if (TIMER_EVENT) {state = Game_State}
			//When user clicks again, it will start the game otherwise it will initialize
			// first mole and location through a random number
			break;
		Up_State:
			if (CLICK_EVENT) {state = Up_State}
			if (HIT_EVENT) {state = Point_State}
			if (TIMER_EVENT) {state = Stay_State}
			if (GAME_TIMER_EVENT) {state = Over_State}
			// Starts a timer for overall game as well as how long it takes for the mole goes up.
			// initialize random number of moles and location for moles
			// If timer for going up runs out, it will move onto stay state when the mole is fully up.
			// If User misses it stays in the state but if user clicks the mole, it goes to a point state
			// If timer for overall game runs out (e.g 3 mins) we will move to game over
			break;
		Stay_State:
			if (CLICK_EVENT) {state = Stay_State}
			if (HIT_EVENT) {state = Point_State}
			if (TIMER_EVENT) {state = Down_State}
			if (GAME_TIMER_EVENT) {state = Over_State}
			// This is similar to up state
			// Doesn't reinitialize moles and location but starts a timer that tells how long the mole
			// will stay up.
			// If user misses the mole, it will stay on the same state but if user clicks the mole
			// it will move onto point state
			// If timer for mole runs out it will go to move down state 
			// If game timer runs out it will move to game over.
			break;
		Down_State:
			if (CLICK_EVENT) {state = Down_State}
			if (HIT_EVENT) {state = Point_State}
			if (TIMER_EVENT) {state = Up_State}
			if (GAME_TIMER_EVENT) {state = Over_State}
			// The mole will start moving down depending on how long the timer is
			// If at any point the user hits the mole, it will move to point state
			// Otherwise, it will continue to go down till timer is 0 which will go back to
			// up state in popping up a new mole.
			// If game timer runs out, it goes to over state
			break;
		Point_State:
			if (CLICK_EVENT) {state = Point_State}
			if (HIT_EVENT) {state = Point_State}
			if (TIMER_EVENT) {state = Up_State}
			if (GAME_TIMER_EVENT) {state = Over_State}
			// This just raises the point counter in which the mole will disappear or go down
			// It will go back to up state to pop up a new mole
			// If the game timer is over it will game over
			break;
		Over_State:
			if (CLICK_EVENT) {state = Main_State}
			if (HIT_EVENT) {state = Main_State}
			if (TIMER_EVENT) {state = Main_State}
			// Mainly, if anything happens, the user will go back to main menu (via click)
			// Timer will make it so that it will automatically go back to main menu after a certain
			// period of time.
			break;

	}
     }
}