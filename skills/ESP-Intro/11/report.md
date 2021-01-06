#  Stopwatch

Author: Mario Han

Date: 2020-09-04
-----

## Summary

I copied my code from skill 10 and switched out the task 1 which was the binary LED with the timer example. I coped some code from the timer example in the stopwatch debrief and used the timer with reload parts only. In doing so, my global variable count will go to 100 and 0 but if the button is pressed it will reset to 0. Global variable clock which is shown on the I2C is always set to 0 if the press flag has not been raised. On the first press, it will raise the flag and the button will now reset the timer.

## Sketches and Photos

First button press and reset:\
[Link to Demo](https://drive.google.com/file/d/1SMoEi5SnF56CMUrSUhX6_Ja1kkg8JFaE/view?usp=sharing)

Wraps around back to 0 after reaching 99:\
[Link to Demo](https://drive.google.com/file/d/1nKIDKK7bwZA6Vr_1zDXuty9Qdo_bbQZD/view?usp=sharing)

## Modules, Tools, Source Used Including Attribution

My module for skill 10:\
https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-1/10/code

ESP-IDF example:\
https://github.com/espressif/esp-idf/tree/17ac4ba/examples/peripherals/timer_group

## Supporting Artifacts

My code repo for easier nav:\
https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-1/11/code

-----
