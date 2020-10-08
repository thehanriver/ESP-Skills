#  Battery Monitor

Author: Mario Han

Date: 2020/10/8
-----

## Summary

To show the voltage in from esp to I2C display, I used the code from previous skills such as skill 8 to use as a template. After doing so, I used the code example and combined it with the template in order to show only numbers. 

Then it was just a matter of finding the correct resistors for the voltage divider. I used 660 ohms and 990 ohms in order to reduce 5V to about 3V. For some reason, when there is no voltage going through the ADC pin, I get 142 mV. So in my calculations in displaying the Voltage (mV is shown on I2C), we subtract 142 from voltage. From there, it was just a matter of showing Voltages on the I2c as mV.

## Sketches and Photos

I removed the 330 Ohm resistor from 5V source but still displays 142 mV:
![noresist](https://user-images.githubusercontent.com/45515930/95516693-a2b8f080-098d-11eb-8ba8-85f5bf1c1c1b.JPG)

Console of that weird bug:
![ground](https://user-images.githubusercontent.com/45515930/95516861-df84e780-098d-11eb-9c9f-2a78f9d0d69f.JPG)

When everything is connected, all good:
![voltdiv](https://user-images.githubusercontent.com/45515930/95516883-f0355d80-098d-11eb-82f4-33dcf8266446.JPG)

## Modules, Tools, Source Used Including Attribution

[I2C display example code](https://github.com/BU-EC444/code-examples/tree/master/i2c-display)

[ESP reading volts example code](https://github.com/espressif/esp-idf/tree/39f090a4f1dee4e325f8109d880bf3627034d839/examples/peripherals/adc)

## Supporting Artifacts


-----
