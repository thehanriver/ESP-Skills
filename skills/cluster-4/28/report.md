#  Leader Election

Author: Mario Han , Hussain Valiuddin, Vivek Cherian

Date: 2020-11-13
-----

## Summary

This skill uses the bully algorithm to decide a leader when there are multiple ESPs online. The ESPs communicate via UDP packets with one another. The skill does not require discovery of new ESPs therefore each ESP already knows the IP address of all other ESPs which may connect to the network. 

The Algorithm uses an FSM with 5 states and 3 signals:
LEADER: An ESP in this state is the leader and it sends data to the other esps.
NOT_LEADER: AN ESP in this state is not the leader and receives signals from the leader. If the not leader does not receive any new signals from the leader for some time, it times out and goes into the ELECTION state. 
ELECTION: During this state, the ESP sends an election signal to any ESP with a higher ID and a OKIE signal to any ESP with a lower ID and then moves on to the WAIT_OK state
WAIT_OK: in this state, the ESP is waiting for a higher ESP to send an OKIE signal. If it does not receive an OKIE signal, that means there were no higher ID esps online and hence the ESP becomes a leader. If it does recieve an OKIE, that means that atleast one of the ESPs above it got its signal and is also checking ESPs above it. The ESP when it receives an OKIE signal moves to state WAIT_WIN.
WAIT_WIN: IN this state, the ESP waits for a win signal form one of the higher esps. If it does recieve a WIN signal, it moves to the NOT_LEADER state. If the ESP times out in this state, that means one of the higher ESPs which sent a OKIE signal got disconnected, and hence the election is started again.

In our implementation, higher ID ESP becomes the leader. The LEDs show which esp is in what state, with green being the leader, blue being a non-leader, and red meaning there is an election happening. The ESPs internal LEDS blink to chow what their ID is. 

## Sketches and Photos

DEMO:
![Screenshot (207)](https://drive.google.com/file/d/1UvzbS3z5qoa0E0G9s29EnY_lNSTwYcPf/view?usp=sharing)

## Modules, Tools, Source Used Including Attribution


## Supporting Artifacts

[Bully Algorithm Wiki](https://en.wikipedia.org/wiki/Bully_algorithm)
-----
