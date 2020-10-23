#  Pi as WiFi AP

Author: Mario Han

Date: 2020-10-23
-----

## Summary

I reflashed my SD because even with the wpa_supplicant.conf file gone, it wouldn't work. I set up my pi as a ethernet gadget and shared my network with it following the tutorials.
I also download the XRDP package and used the remote desktop app to manually connect to "Group_2" wifi network which is ours. After a long time debugging, I managed to connect to it. Also added my MAC address for port forwarding as well as static DHCP.

## Sketches and Photos

Enabled network sharing for internet:
![Screenshot (168)](https://user-images.githubusercontent.com/45515930/97044840-b4c89080-1542-11eb-9265-1239e630f3a9.png)

Pinging from PuTTy to show it's connected:
![Screenshot (169)](https://user-images.githubusercontent.com/45515930/97044890-ca3dba80-1542-11eb-9e84-6eedc732fd9a.png)

Remote Desktop App for Manual connect:
![Screenshot (171)](https://user-images.githubusercontent.com/45515930/97056542-3cb89580-1557-11eb-85bd-fd2abccf54d4.png)

"Marioppi" is my pi:
![Screenshot (170)](https://user-images.githubusercontent.com/45515930/97044928-dd508a80-1542-11eb-9dc2-7eba4faad203.png)

Port Forwarding:
![Screenshot (176)](https://user-images.githubusercontent.com/45515930/97056481-1dba0380-1557-11eb-9276-68e098987f02.png)

Static DHCP:
![Screenshot (174)](https://user-images.githubusercontent.com/45515930/97056503-2ad6f280-1557-11eb-8aba-e4af42926387.png)


## Modules, Tools, Source Used Including Attribution

[Link to the tutorial I followed](https://www.circuitbasics.com/raspberry-pi-zero-ethernet-gadget/)

## Supporting Artifacts


-----
