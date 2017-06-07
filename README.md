# Feedback Tracker


## Synopsis

This project was implemented to wirelessly configure a set of gyroscopes of type JY901. The JY901 sensors are mounted on a UAV to aid in navigation however, configuring JY901s requires physically removing them and connecting them serially to a device through UART. This method is not only impractical, but it can affect the life-time of the JY901s as delicate electronics are not made for constant switching on and off.

## Motivation

This application was developed for [Romaeris Corporation](https://www.linkedin.com/company/romaeris-corporation). Romaeris Corporation is a privately owned aerospace technology company headquartered in Ottawa, Canada. The company is developing unmanned aerial vehicles (UAVs) and aircraft telemetry and health monitoring systems. Romaeris integrated this API into their test model to help them expirement easily with various settings and configrations. 

## Installation

Before using this API, JY901 sensors must be connected to a bluetooth/WIFI chip such as the [USR-C322](http://www.usriot.com/p/ti-cc3200-wifi-modules/). Which will allow it to wirelessly recieve data.

Clone the repo to a Raspberry pi, navigate to ConfiguringJY901/build/bin then run the executable JY by following these instructions:
..* You can show a list of all available instructions by executing ``` ./JY 0 help``` 


then run the [tracking code](https://github.com/zurkiyeh/FeedbackTracker/tree/master/Tracker/build) by running the executable "mainProject". That will initiate the tracking process. Meanwhile run the [Transmission application](https://github.com/zurkiyeh/FeedbackTracker/tree/master/Transmission/onebyte/trans) on a seperate Raspberry pi. Finally, to recieve the data, run the [receiving application](https://github.com/zurkiyeh/FeedbackTracker/tree/master/Transmission/onebyte/rec) on a third RPi. 


## Tests

Tests and simulations were conducted on the project report which can be provided seperetly. Please contact me for more information.

## Contributors

This project was developed with the help of [Zachary (Tsa) Liu ](https://www.linkedin.com/in/tsaliu)



## Detailed Description


The transmission subsystem consists of a servo-controlled target that rotates along two axes in a spherical fashion. The tracking is done using a feedback camera, fixed infront of the target, and controlled by a Raspberry Pi. The Raspberry Pi also, directs a servo-controlled optical mirror that rotates along two axes based on the feedback it recieves from the camera. This ensures real-time transmission and recieving of data.The transmission and recieving of data is done using another two seperate Raspberry Pis.


The Raspicam captures the video stream then passes it to the Raspberry Pi, which in turn applies Haar Cascade classefiers that detect and track the target. This process is repeated constintly and an updated coordinate of the target is always captured. After the new coordinate has been captured, a camera transformation is then used to obtain the coordinates in real-life dimensions (milimeters) using the pinhole camera model. Coordinate transformation is then applied and the coordinate in milimeter is used to
calculate both angles of inclination of the mirror using predeveloped mathmatical model.

The transmitssion and recieving subsystem handles the modulation and demodulation of data. Data can be any encoded binary data (i.e. modulated audio/video data). In this project, the transmitted data is a integer sequence that runs from 0-255.

