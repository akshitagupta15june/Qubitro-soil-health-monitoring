
https://www.hackster.io/akshitagupta15june/soil-moisture-monitoring-using-esp8266-and-qubitro-c6986a (Visit this for detailed information)
# Introduction
Soil is the base of agriculture. Soil provides nutrients that increase the growth of a crop. Some chemical and physical properties of soil, such as its moisture, temperature and its pH, heavily affect the yield of a crop. These properties can be sensed by the open-source hardware, and they can be used in the field. In this chapter, a soil health monitoring system is proposed in which farmer will be able to monitor soil moisture, soil temperature and soil pH in his android smart-phone. The farmer will also get the recommendations of lime and sulphur on the basis of pH of the soil. The area of study is Jaipur, Rajasthan (26.9124° N, 75.7873° E). The proposed system is tested with the results taken from authorized laboratories. The proposed system is validated with t-test having no significance difference between calibrated values and laboratory-recorded values. The proposed system is implemented on android smart-phone so it is useful for farmers, agriculture scientists, agriculture professionals and IoT experts.
# Inspiration

Soil moisture is a measure of soil health, the water content present in a certain area of the ground. In my previous project Self Greenery, I build a Micro: bit Automated Self Watering Plant, so in this project, we will send the real-time soil moisture sensor data to qubitro for visualization.

# What it does

For this project, we will be using a node MCU ESP8266 WiFi module and a soil moisture sensor that measures the volumetric content of water inside the soil and we will send this sensor data for visualization in the Qubitro platform.

# Hardware Requirements

NodeMCU ESP8266

FC-28 Soil moisture sensor

Breadboard, M-F Jumper wires

# Steps to follow 

Connect the soil moisture sensor FC-28 to the ESP8266 in analog mode.

VCC of FC-28 to 3.3V of ESP8266

GND of FC-28 to GND of ESP8266

A0 of FC-28 to A0 of ESP8266

Connect the two pins from the probe to the two pins on the Amplifier circuit via jumper wires.

<img src="https://github.com/akshitagupta15june/Qubitro-soil-health-monitoring/blob/main/Images/data-chart.png">

# Connecting to Qubitro Platform

SignUp/Login on the Qubitro Portal

Create a new project with a description

Create a new device with details and a description

