#  IR Rangefinder

Author: Mario Han

Date: 2020/10/8
-----

## Summary

For the IR Rangefinder, the code is taken from skill 13 again (Skill 13 code is used for 14 and 15 except the conversions are differnt). This time they didn't provide us with a formula so I used desmos to approximate the values based on the data sheet (Output Voltage(v) vs Inverse number of distance (1/cm)) and in doing so used two best lines to calculate distance. Using y = mx+b where y = voltage and x = 1/disantce, I used a best for 150 - 30 cm  and another for 30 - 15 cm. Anything smaller than 15 should be unreadable. In doing so, I solved for x to find distance. 

The IR rangefinder's wires needed to be stripped. Doing so allowed me to correctly wire it up. Black going to ground, Yellow going to ADC, and Red going to 5V. It seems to need more callibration (since I used best fit lines) but otherwise it reads correctly.

## Sketches and Photos

IR wired up:
![IR](https://user-images.githubusercontent.com/45515930/95522153-54a9ea00-0999-11eb-8c1b-eeaaa8f712bc.JPG)

Console during one of my tests. 
I put the IR rangefinder on the table and set it facing the mugar-basement ceiling.Which is about 208 cm away. I put my noteook in between IR sensor and ceiling several times 
and as you can see it gets different readings depending on how far the notebook is. Unfortunately, I couldn't take a picture of me doing that so please use ur imagination
using the following three images below on how I tested it.
![IRscreen](https://user-images.githubusercontent.com/45515930/95522182-64c1c980-0999-11eb-8ded-c6f4a84bbe35.png)

Notebook up to measure readings.
![testIR2](https://user-images.githubusercontent.com/45515930/95522263-a05c9380-0999-11eb-9280-d763fd46844f.JPG)

It should measure to 208 cm if it was left on the table to read ditance from table to ceiling.( Very low ceiling in mugar basement)
![testIR](https://user-images.githubusercontent.com/45515930/95522278-ab172880-0999-11eb-8468-30abc5daa3f0.JPG)

## Modules, Tools, Source Used Including Attribution

[Link to skill 13 code](https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-2/13/code)

## Supporting Artifacts

[Datasheet or Long Range IR sensor](https://www.sparkfun.com/datasheets/Sensors/Infrared/gp2y0a02yk_e.pdf)

[Link to my code](https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-2/15/code)

-----
