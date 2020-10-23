#  Use PWM to Control Power to an LED

Author: Mario Han

Date: 2020-10-23
-----

## Summary

I used the fade LED code from the ESP examples as a base code. Since it was mostly for 4 LEDs, I decided to use the on board LED instead. I changed the code to use only one LED and used ledc_set_fade_step_and_start so that each step has 250 ms. Otherwise, I changed the define statements to better fit the onboard LED and got rid of alot of unnecessary things.

## Sketches and Photos

Picture of light:
![IMG_8876](https://user-images.githubusercontent.com/45515930/97055822-928c3e00-1555-11eb-9094-c5bf6cc90ae2.JPG)

Picture of light dimming (kind of hard to tell):
![IMG_8879](https://user-images.githubusercontent.com/45515930/97055846-9f109680-1555-11eb-9b47-5bb375adf01f.JPG)

Picture of light out wait a little then fade in and out again:
![IMG_8878](https://user-images.githubusercontent.com/45515930/97055877-aa63c200-1555-11eb-8fac-566b13de5ff4.JPG)

Console to show when it is stepping in and out:
![Screenshot (182)](https://user-images.githubusercontent.com/45515930/97055964-daab6080-1555-11eb-91ae-8158705929f0.png)


[Link to Video of fade in and out](https://drive.google.com/file/d/1tS9BKep251H9M232fgNTiYPOap8BtMRf/view?usp=sharing)

## Modules, Tools, Source Used Including Attribution

[Link to ESP example code](https://github.com/espressif/esp-idf/tree/master/examples/peripherals/ledc)

[LED Control API](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/ledc.html)

## Supporting Artifacts

[My code](https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-3/24/code)
-----
