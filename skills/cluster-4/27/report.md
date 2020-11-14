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

## Sketches and Photos


## Modules, Tools, Source Used Including Attribution


## Supporting Artifacts


-----
