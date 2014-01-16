Soil-Moisture-Sensors
=====================

I'll be designing a lot of these it seems.

##Description of Circuits

```bash
.
├── 555_Astable_SMS
│   ├── 555_resistance_sensor.fzz
│   ├── 555_resistance_sensor.png
│   ├── README.md
│   └── Soil_Moisture_Sensor.ino
└── Voltage_Divider_SMS
    ├── dataFile.txt
    ├── soil_moisture_poll.ino
    └── soil_moisture_poll.py

```
### Voltage Divider Circuit
So far my favorite is the Voltage Divider, as it is simple to wire, and straightforward to measure (simple analogRead).

### The 555-Astable circuit

This circuit measures using the hardware-interrupt.
we are also seemingly limited by the size of a volatile int (best to set it at the negative end and then count up from that to get the full range -- unsigned int doesn't seem to change anything even though it compiles)

### The 555-One Shot circuit

The Equation is `1.1 * R * C = pulse duration`.  This can be easily measured using the pulseIn() function in Arduino, and also yields a convenient method for calculating the precise resistance and capacitance.

I think this circuit will become my favorite after building it.
