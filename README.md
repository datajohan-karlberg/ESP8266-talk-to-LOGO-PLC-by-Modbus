# ESP8266-talk-to-LOGO-PLC-by-Modbus
Here is a sample how to ESP8266 communicate with Siemens LOGO PLC by MODBUS 
  
 ### Description  
 The sample show how to read input signal in LOGO and send to ESP8266 and also sent boolean value from ESP8266 to relay output in LOGO PLC. That is send by modbus protocoll by WIFI.  
  ESP8266 act as a slave/server (listen) and LOGO is master/client (sending). It is ESP8266 that have the list of "coils". It is LOGO that contact ESP8266 and read/write coils. I try it on EPS32, but it not work there.
  
  ![P2](https://user-images.githubusercontent.com/33222123/158785202-bf5052ea-0f37-49c7-bac1-4345cc040581.png)  

    
  ### LOGO PLC from Siemens  
  ![Pict 2022-03-15 12-48-14 007](https://user-images.githubusercontent.com/33222123/158779894-762ebea4-df29-4cb7-b21e-b003c357471c.jpg)  
This little PLC have 8 inputs and 4 relay outputs.  
    
### LOGO Programming  
![Pict 2022-03-17 10-13-45 001](https://user-images.githubusercontent.com/33222123/158780216-3f94da20-7d3e-4242-a830-c63c51adb4f1.jpg)  
This is the program in LOGO PLC. In top is sender that sends coil 10 evry seconds. Next section test coil 11 and connect it to relay 1 in LOGO.
LOGO have IP 192.168.0.3 in this case but it not important. Coilnumbers are not same in Arduino-world and LOGO-world. Coil 9 in Arduino is coil 10 in LOGO-world. (Little bit confusing)  

![Pict 2022-03-17 10-13-45 004](https://user-images.githubusercontent.com/33222123/158785687-c8f41781-ab36-4a94-8fc2-a26f8471da5d.jpg)  
LOGO!Soft Comfort is the program for LOGO PLC  


### Used Library  


modbus-esp8266  
https://github.com/emelianov/modbus-esp8266  
