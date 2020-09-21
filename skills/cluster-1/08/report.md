#  Alphanumeric I2C Display

Author: Mario Han

Date: 2020 - 09 - 21
-----

## Summary

  I used the code from the code examples as a starting point. Moving from there, I used the UART driver from skill 6 to take in the input. In doing so, I copied
  "alphafonttable" from the "bitmap cheat" code in the quest. Putting this together, I took the the input and stored it into a character buffer which finds the
  ASCII value and indexes into alphafonttable to find the unsigned 16 bit associated with it. I put that into displayBuffer which displays it on the I2C display.
  
  Note: I did have trouble with the input and I cannot figure out why. It's a cycle slower? For example, If i put "Hello" it reads it and prompts me to put 
  in 4 or less chracters which I wrote. Then, if I input "OKAY", it still reads as if it's "Hello" but displays "OKAY" on the display. Then, if I put "OK",
  it shows "OK" on the display followed by weird characters in the two remaining spaces and have to input OK again to display two empty spaces after OK.

## Sketches and Photos

![IMG_8564](https://user-images.githubusercontent.com/45515930/93774844-b0c9eb80-fbef-11ea-81e0-06ecb02a1486.JPG)

Asks user for 4 letter characters upon flash.

![IMG_8565](https://user-images.githubusercontent.com/45515930/93774996-e078f380-fbef-11ea-8a83-c1f438b75021.JPG)

Two Letters displayed.

![IMG_8567](https://user-images.githubusercontent.com/45515930/93775062-f7b7e100-fbef-11ea-8255-427a8767c51e.JPG)

Four Letters displayed.

![IMG_8568](https://user-images.githubusercontent.com/45515930/93775145-0f8f6500-fbf0-11ea-936a-47d267fbee8c.JPG)

One Letter Displayed. Note: numbers work as well I just forgot to take pictures.

![IMG_8571](https://user-images.githubusercontent.com/45515930/93775195-1f0eae00-fbf0-11ea-8edc-894feaa120e9.JPG)

If input is larger than 4 characters, reprompts user.

## Modules, Tools, Source Used Including Attribution

I2C example code, Skill6, "Bitmap Cheat" inside debfrief.

## Supporting Artifacts

Link to code for easier navigation:

-----
