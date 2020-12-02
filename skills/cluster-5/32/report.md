#  Wheel Speed - Crawler

Author: Mario Han

Date: 2020-12-1
-----

## Summary

I used the voltage read from the thermistor skill (analog read) and in doing so, I wired according to the Sparkfun guide. I printed out the 12 pattern encoder and attached it to the inside of the wheel. Instead of caluclating RPM, I measured how many times it passed by the black part of the encoder in a second and divded that by 6 (rotations per second). Then I multipied it by the wheel circumference (24.0 cm) in meters to get the speed. The speed was displayed in the console.

## Sketches and Photos

Console
![Screenshot (212)](https://user-images.githubusercontent.com/45515930/100808101-866f8800-3401-11eb-9b09-dbf2d0580d63.png)

Attached to the bottom (speed sensor)
![IMG_9358](https://user-images.githubusercontent.com/45515930/100808142-97b89480-3401-11eb-929b-3a5f6f757a17.JPG)

Better picture of board
![IMG_9359](https://user-images.githubusercontent.com/45515930/100808143-98512b00-3401-11eb-8eb0-712af0ce77c6.JPG)

## Modules, Tools, Source Used Including Attribution

[Link to Sparkfun](https://learn.sparkfun.com/tutorials/qrd1114-optical-detector-hookup-guide#example-circuit)

## Supporting Artifacts

[Link to my code](https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-5/32/code)

-----
