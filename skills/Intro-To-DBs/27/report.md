#  State Models

Author: Mario Han

Date: 2020-11-13
-----

## Summary

For state models, it will look like this as shown on the table:

| States/Event | Click| Hit| Timer | Game_Timer |
|---------------------------------------------|:-----------:|:---------:|:---------:|:---------:|
| Main_State | Game_State |  Main_State     |  Main_State     |Main_State|
| Game_State | Up_State |  Game_State    |   Game_State     |Game_State|
| Up_State | Up_State |  Point_State     |   Stay_State    |Over_State|
| Stay_State | Stay_State |  Point_State      |  Down_State     |Over_State|
| Down_State | Down_State|  Point_State     | Up_State |  Over_State   | 
| Point_State |  Point_State|  Point_State     | Up_State|  Over_State     | 
| Over_State |  Main_State |  Main State     | Main_State |  Main_State  | 

Basically, if the user clicks the main menu it will go to the game menu. 
There the user must click in order to start the game.
Once the game starts moles will be generated in any location.
It will stay up for a certain amount of time and go down later.

The states and functinality are detailed further in my code comments.

## Sketches and Photos


## Modules, Tools, Source Used Including Attribution

[Link to Game](https://www.crazygames.com/game/whack-a-mole)

## Supporting Artifacts

[Code link with comments](https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-4/27/code)

-----
