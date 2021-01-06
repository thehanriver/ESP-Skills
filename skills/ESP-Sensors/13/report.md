# Thermistor

Author: Mario Han

Date: 2020/10/8
-----

## Summary

For the thermistor, I used the voltage divider to drop 5V to an acceptable range in which esp will get a reading. Since, the thermistor acts like a resistor, I replaced R1 from the previous skill with the thermistor and R2 with 1k Ohm. Based on a piazza posting, I followed a guide on how to convert resistance and voltages into temperature. I first used a 15k ohm instead of a 1k but it puts the readings out of range since it gives more than 3V. So looking at the datasheet and solving for Thermistor resistance at 1k , it seemed to give a voltage not too small and not too big. So I chose to use that one, since it can allow the thermistor close to max and min temperatures before it gives more than 3V.

The code is from skill 12 except it's stripped of all I2C-related code and added the calculations.

Also I used the ambient thermistor instead of the thermistor probe even though they are identical just because the ambient thermistor had a datasheet I could find.

## Sketches and Photos

Thermistor:
![thermistor](https://user-images.githubusercontent.com/45515930/95518042-3b507000-0990-11eb-8910-a721480a7cdb.JPG)

Console when not touching it:
![temp2](https://user-images.githubusercontent.com/45515930/95517972-1825c080-0990-11eb-98f5-150440a754fc.png)

You can see the temperature and voltage going up as I hold onto the thermistor:
![tempup](https://user-images.githubusercontent.com/45515930/95518071-4acfb900-0990-11eb-9dac-f41e00e83a4a.JPG)

## Modules, Tools, Source Used Including Attribution

[Link from post on piazza](https://www.jameco.com/Jameco/workshop/TechTip/temperature-measurement-ntc-thermistors.html)

[Link to Skill 12 code](https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-2/12/code)

## Supporting Artifacts

[Thermistor datasheet](https://eaa.net.au/PDF/Hitech/MF52type.pdf)

[Code for this skill](https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-2/13/code)

-----
