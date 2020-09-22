#  Use GPIO to Control LEDS

Author: Mario Han

Date: 2020 - 09 - 21
-----

## Summary

I used Pins 12,27,33, and 15 with 330 Ohm resistors for each LED respectively. In doing so, I used the get-started(blink) example as a starting point. 
I just applied int to bin logic using modulo to get the necesssary bin values. I used a for loop in my code that runs from 0 to 15 and uses
i/8%2,i/4%2,i/2%2, and i%2 for the 4th,3rd,2nd, and 1st binary numbers respectively and set level of the LEDS to 1 whenever the function returned a 
1 (since modulo floors fractions I believe).

## Sketches and Photos

[Demo Of LEDS](https://drive.google.com/file/d/1Prw8HIhEM4GhQPIklh9e-DLLmXVWK7DW/view?usp=sharing)

![Screenshot (149)](https://user-images.githubusercontent.com/45515930/93776037-1ff40f80-fbf1-11ea-97b0-19a1c53883f8.png)
Error checking to see if I'm getting the correct binary values.

## Modules, Tools, Source Used Including Attribution

ESP example "blink" from get-started:\
https://github.com/espressif/esp-idf/tree/master/examples/get-started/blink

## Supporting Artifacts

Link to code repo for easier navigation:\
https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-1/07/code


-----
