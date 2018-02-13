# Arduino_ParkingSensor
Arduino code for a garage parking sensor

## Intended Function
The function of the device is to notify the user when they have pulled in to the garage sufficiently to be completely within the garage while not hitting any inside walls.  The current mode of notification is LEDs, although future development could include a digital screen depicting the remaining distance or some other metric.

## Intended Hardware
This code is intended to run an Arduino Pro Mini 328 (5V) connected to 3 LEDs and the HC-SR04 proximity sensor.  Minimal adjustments would need to be made to use an alternative Arduino product.

[Arduino Pro Mini 328 - 5V/16MHz](https://www.sparkfun.com/products/11113)  
[Ultrasonic Sensor](https://www.sparkfun.com/products/13959)  
[LED Kit](https://www.sparkfun.com/products/13234)  
[Jumper Wires](https://www.amazon.com/gp/product/B073X7P6N2/ref=oh_aui_detailpage_o02_s00?ie=UTF8&psc=1)  
[Barrel Jack Converter](https://www.amazon.com/OdiySurveil-5Pairs-Terminal-Adapter-Cameras/dp/B00W058HHQ/ref=sr_1_8?s=electronics&ie=UTF8&qid=1518488058&sr=1-8&keywords=dc+barrel+connector)  
[5V Power Supply](https://www.amazon.com/iMBAPrice-Adapter-Listed-Supply-5-Feet/dp/B00GUO5WUI/ref=sr_1_3?ie=UTF8&qid=1518488211&sr=8-3&keywords=5v+power+supply)  
3D Printed Housing

## Possible Improvements
1. BLE Connectivity
  Provide notifications via a Raspberry Pi (or other central hub) if the vehicle is moved at unusual times
2. Digital Screen
  As described above, can be used to display remaining space or any other useful metric
3. Integrated Garage Sensor
  Using multiple (or a single) sensor to determine either if the garage door is open and if the car is sufficiently in the garage.
