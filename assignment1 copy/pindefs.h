// a1839619

// Digital input/output pin definitions based on TABLE I

// Define logic levels for clarity
#define HIGH 												1  // Represents a logic HIGH or "1"
#define LOW  												0  // Represents a logic LOW or "0"

// Servomotors
#define SERVOMOTOR_1    						0   // P2.0 - Digital pin for the first servomotor, controls the initial gate
#define SERVOMOTOR_2    						1   // P2.1 - Digital pin for the second servomotor, controls the gate for reflective items
#define SERVOMOTOR_3    						2   // P2.2 - Digital pin for the third servomotor, controls the gate for metallic items

// Conveyor belts
#define CONVEYOR_BELT_1 						4   // P2.4 - Digital pin for the first conveyor belt
#define CONVEYOR_BELT_2 						5   // P2.5 - Digital pin for the second conveyor belt

// Through-beam sensors
#define THROUGH_BEAM_SENSOR_1 			8   // P2.8 - Sensor to detect items at the start of the sorting process
#define THROUGH_BEAM_SENSOR_2 			9   // P2.9 - Sensor to detect items at the middle of the sorting process
#define THROUGH_BEAM_SENSOR_3 			10  // P2.10 - Sensor to detect items at the end of the sorting process

// Other sensors
#define INDUCTIVE_PROXIMITY_SENSOR  12  // P2.12 - Sensor to detect if the item is metallic
#define DIFFUSE_SENSOR              13  // P2.13 - Sensor to detect if the item is reflective

// Emergency stop
#define EMERGENCY_STOP 							15  // P2.15 - Digital pin for the emergency stop button
