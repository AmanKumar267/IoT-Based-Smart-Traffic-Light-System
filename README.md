* IoT-Based Smart Traffic Light Control System

An IoT-based Smart Traffic Light Control System developed using **Arduino Uno**, **ESP8266**, and **IR Sensors** to optimize traffic flow by dynamically adjusting traffic signal timing based on vehicle density.


* Overview

Traditional traffic lights operate on fixed time intervals, which often leads to unnecessary waiting during low traffic and congestion during peak hours. This project addresses the problem by detecting vehicle density using IR sensors and automatically adjusting the green signal duration.

The system can also be extended with **ESP8266 Wi-Fi** for remote traffic monitoring and future smart city applications.


* Objectives

- Detect vehicle density using IR sensors.
- Automatically adjust traffic signal timing.
- Reduce unnecessary waiting time.
- Improve traffic flow efficiency.
- Provide a foundation for IoT-based traffic management.


* Hardware Components

| Component               Quantity |
|-----------|             ---------:|
| Arduino Uno |              1 |
| ESP8266 Wi-Fi Module|      1 |
| IR Sensors |               4 |
| Red LEDs |                 2 |
| Yellow LEDs |              2 |
| Green LEDs |               2 |
| 220Ω Resistors |           6 |
| Breadboard |               1 |
| Jumper Wires |        As required |
| USB Cable |                1 |


* Software Requirements

- Arduino IDE
- C++
- ESP8266 Board Package *(Optional)*
- Serial Monitor


* Working Principle

1. IR sensors detect the presence of vehicles.
2. Arduino reads sensor inputs.
3. Vehicle density is calculated.
4. Green signal duration is adjusted automatically.
5. Traffic lights switch based on calculated priority.
6. Traffic data can be sent over Wi-Fi using ESP8266 (future enhancement).


* Pin Configuration

| Arduino Pin |                 Connected Device |
|-------------|                 ------------------|
| D2 |                          IR Sensor A1 |
| D3 |                          IR Sensor A2 |
| D4 |                          IR Sensor B1 |
| D5 |                          IR Sensor B2 |
| D6 |                          Road A Red LED |
| D7 |                          Road A Yellow LED |
| D8 |                          Road A Green LED |
| D9 |                          Road B Red LED |
| D10 |                         Road B Yellow LED |
| D11 |                         Road B Green LED |


* Algorithm

1. Start the system.
2. Initialize all sensors and LEDs.
3. Read vehicle data from IR sensors.
4. Calculate traffic density.
5. Assign green signal time:
   - Low Density → 5 seconds
   - Medium Density → 8 seconds
   - High Density → 12 seconds
6. Switch traffic lights.
7. Repeat continuously.


* Features

- Automatic traffic signal control
- Vehicle density detection
- Dynamic signal timing
- Low-cost implementation
- Easy to modify and expand
- IoT-ready architecture
- Arduino-based design


* Advantages

- Reduces traffic congestion
- Minimizes waiting time
- Saves fuel
- Reduces air pollution
- Improves traffic efficiency
- Suitable for smart city projects

---

* Limitations

- Depends on proper sensor placement.
- IR sensors can be affected by environmental conditions.
- Designed for a two-road intersection.
- Does not prioritize emergency vehicles.


* Future Enhancements

- AI-based vehicle detection using cameras.
- Emergency vehicle priority system.
- Cloud database integration.
- Mobile application for traffic monitoring.
- MQTT communication.
- Real-time analytics dashboard.
- Smart city integration.


* Circuit Diagram
                     IoT Based Smart Traffic Light Control System

  ┌─────────────────────────┐
  │      Arduino UNO        
                         │                         │
        IR Sensor A1 ----│ D2                  5V │----- +5V
        IR Sensor A2 ----│ D3                 GND │----- GND
        IR Sensor B1 ----│ D4                     │
        IR Sensor B2 ----│ D5                     │
                         │                        │
 Road A Red LED ---------│ D6                     │
 Road A Yellow LED ------│ D7                     │
 Road A Green LED -------│ D8                     │
                         │                        │
 Road B Red LED ---------│ D9                     │
 Road B Yellow LED ------│ D10                    │
 Road B Green LED -------│ D11                    │
                         └─────────────────────────┘

* Testing

The project was tested for:

- Vehicle detection
- LED switching
- Signal timing
- Continuous operation
- Sensor response


* Learning Outcomes

Through this project, I learned:

- Arduino Programming
- Embedded Systems
- Sensor Interfacing
- IoT Fundamentals
- Traffic Signal Automation
- Problem Solving
- Hardware Integration


* Author

**Aman Kumar**

B.Tech – Robotics and Automation Engineering

Government Engineering College Arwal

📧 Email: amankr1611kr@gmail.com



## ⭐ Support

If you found this project useful, consider giving it a ⭐ on GitHub.
