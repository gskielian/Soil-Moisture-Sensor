Soil-Moisture-Sensor Voltage Divider
====================================

There were two major challenges we faced when creating a robust sensor:
* **hysteresis**  and
* **probe corrosion**


### Hysteresis
The voltage divider had it's initial difficulties with hysteresis.  Apparently measuring water's resistance changed the resistance of the water measured (I speculate this may be due to the ion redistribution effects from the metal probe's electric fields), one of the consequences of this is our readout would never setlle -- the resistance was coupled to the previous state.

To remedy this, I reset the pinmodes and then wait around 500ms between measurements to both "drain" excess charge from each pin and to allow the water to return to it's initial state.


After implementing this we definitively removed readout drift! 


### Probe Corrosion

To keep our measurements in the linear range of the voltage divider, we first match our soil's resistance with a metal-film resistor (which usually turns out to be around 30kOhms, but varies with your probe setup).

#### Hardware Innovation 


Typical current-based soil moisture sensors tend to corrode fairly quicky if their metals are exposed to the elements.  Some groups attempt to reduce corrosion of their sensor through electroplating with less corrosion prone metals like gold. 

As per our mission to make this technology accessible, our strategy was to find corrosion resistant materials which are available in common hardware stores and inexpensive -- which is why we experimented (successfully!) with galvanized nails.*  So far this has worked like a charm!

*Whole of the credit for this critical innovation goes to [treeherder](https://github.com/treeherder).


#### Software Innovation

The second innovation for addressing probe corrosion was to to minimize the time when electricity is flowing from one probe to the other.  This is the second awesome feature of our solution for the hysteresis problem, as all pins are in the ground state between measurements!


### Future directions

In order to ensure greater reliability, we could switch to a current sensing method an employ an op-amp.  This would allow us to ramp the overall resistance of the circuit, and minimize the amount of electricity which flows through the water during measurements.  However, I doubt that anything will beat the simplicty of this method.





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


