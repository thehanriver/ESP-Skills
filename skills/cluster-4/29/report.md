#  Security In Connected Systems

Author: Mario Han

Date: 2020-11-13
-----

## Summary

The overall flow would generally look like this:

This is the local network:

|Raspberry Pi/Node server| <==> |Router| <==> |ESP| <==> |Car|
                                  ||
                                  
                                  ||
                                  
                                  ||
                                  
                                Internet Cloud
                                
                                  ||
                                  
                                  ||
                                  
                                 Website
                                 
Some weaknesses:  
  ESP can read whenever and whatever since no security on UDP server
  Anyone can control the car on the website
  People can listen in on the UDP protocol

Ways that a bad guy can attack:
  Anyone can access a site to control the car
  UDP port has privacy issue and can be used by anonymous attackers
  Send UDP packets to gain control of the car
  Block/Intercept UDP response from the car
  Someone can flood the memory of the ESP

Solutions:
  Encrypt communication
  Create a login to the website
  Prevent any connection accessing the local router
  Check the device sent the udp server side
  Get rid of any data from unknown devices
  Cover exposed ESP parts.
                                  
## Sketches and Photos


## Modules, Tools, Source Used Including Attribution


## Supporting Artifacts


-----
