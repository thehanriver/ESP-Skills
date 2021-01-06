#  Accelerometer

Author: Mario Han

Date: 2020-10-23
-----

## Summary

For this, I used the I2C brief and example codes as guidance. By learning how the I2C communicates. I created 4 functions:

writeRegister: simply writes data to register
readRegister: read a byte from data at register address
read16: reads 2 bytes from data at register address
getAccel: The ADXL343.h provides register addresses for all X,Y,Z values. So, I called readRegister and read at each values needed. Combine the 2 bytes to a 16 bit unsigned integer which will be casted to a float. Print pitch and roll with the X,Y,Z values on one line (printing is in calcRP).

The values are bit off by a very small margin but generally shows ~10 m/s^2 because of gravity. Sometimes the values are positive since it is facing the other way, but if I flip the board upon a certain axis, they turn the opposite sign.

## Sketches and Photos

Leaving on the table untouched for Z-axis:
![IMG_8871](https://user-images.githubusercontent.com/45515930/97054434-c7e35c80-1552-11eb-9cec-05a1be683443.JPG)

Console for Z-axis:
![Screenshot (179)](https://user-images.githubusercontent.com/45515930/97054447-d03b9780-1552-11eb-8fd5-a96755d2946e.png)

Testing X-axis:
![IMG_8872](https://user-images.githubusercontent.com/45515930/97054479-dd588680-1552-11eb-974d-b799e1c3b41c.JPG)

Console for X-axis:
![Screenshot (180)](https://user-images.githubusercontent.com/45515930/97054514-e77a8500-1552-11eb-8195-0e25f197f427.png)

Testing Y-axis:
![IMG_8873](https://user-images.githubusercontent.com/45515930/97054526-eea19300-1552-11eb-8efe-bc38dd09583a.JPG)

Console for Y-axis:
![Screenshot (181)](https://user-images.githubusercontent.com/45515930/97054547-f6613780-1552-11eb-9146-31ccc0799ea3.png)


## Modules, Tools, Source Used Including Attribution

[Link to example code I used](https://github.com/BU-EC444/code-examples/tree/master/i2c-accel)

[ADXL343 datasheet](https://cdn-learn.adafruit.com/assets/assets/000/070/556/original/adxl343.pdf?1549287964)

[Calculating pitch and roll](https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing)

## Supporting Artifacts

[Link to my code](https://github.com/BU-EC444/Han-Mario-1/tree/master/skills/cluster-3/23/code)

-----
