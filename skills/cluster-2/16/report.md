#  Node.js

Author: Mario Han

Date: 2020/10/8
-----

## Summary

For this , I did all the modules and followed the tutorials (pretty straightword). After doing so, I used serialport's website to see how to implement this. Changing path to my serialport seemed to allow me to get the data from the serial port attached to my esp32 (refer to the image below from serialport's site). It dispalyed correctly after I didn't use idf.py monitor. I picked skill 13 to test this out.

## Sketches and Photos

Code from serialport's site:
![Screenshot (164)](https://user-images.githubusercontent.com/45515930/95523011-93d93a80-099b-11eb-98ca-f7a1c54cbdcf.png)

Flashing but not monitoring my Skill 13 for the thermistor:
![portflash](https://user-images.githubusercontent.com/45515930/95522877-45c43700-099b-11eb-8fe0-703449dd31f1.png)

Seeing readings after running node:
![Readingfromnode](https://user-images.githubusercontent.com/45515930/95522903-5379bc80-099b-11eb-8441-2d3eb1923c6d.png)

## Modules, Tools, Source Used Including Attribution

[Link to node serialport](https://serialport.io/)

[Link to module tutorials](https://www.w3schools.com/nodejs/default.asp)

## Supporting Artifacts

[Link to my code](https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-2/16/code)

-----
