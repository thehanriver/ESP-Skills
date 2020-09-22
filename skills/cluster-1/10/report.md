#  RTOS-Hardware Interrupt

Author: MArio Han

Date: 2020-09-21
-----

## Summary

  For the coding process, I looked at two of the previous skills to help me. I used my LED code from skill 7 and my alphanumeric display
  code from skill 8. However, trying to figure out what code to use was difficult since there was no place to start. However, realizing 
  that I can just get the GPIO level when its high as an input that led me to start on coding which was not too difficult.
  
  Using google, I found a way to wire the button while I looked at previous examples from Skill 7 and 8 to wire everthing together.
  Using global variable direction and count, I wrote what would determine the flow of the tasks. If direction is 0, L2C display shows up and count
  counts up but is modulo 16 so only goes in the range of 0-15 and the opposite is true (direction is 1 it shows DOWN and counts down).
  
  DisplayBuffer is hardcoded to be either UP or DOWN and will change depending on the if the button is pressed. Otherwise, it would be UP as default.
  
## Sketches and Photos


## Modules, Tools, Source Used Including Attribution

LED binary count

https://github.com/BU-EC444/Han-Mario-1/blob/master/skills/cluster-1/07/code/main/Skill7.c

Alphanumeric Display from Skill 8

https://github.com/BU-EC444/Han-Mario-1/blob/master/skills/cluster-1/08/code/main/Skill8.c
 
Learning GPIO input and how to wire button

https://microcontrollerslab.com/push-button-esp32-gpio-digital-input/


## Supporting Artifacts


-----
