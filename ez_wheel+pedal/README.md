# ez_wheel+pedal
This aim of this project was to use an Arduino to create an (extremely) budget racing wheel + pedals for PC gaming. It uses a gyroscope attached to a steering wheel, a separate python program to monitor the serial port, a piece of cardboard for the steering wheel, and some pedals I salvaged and repurposed from a $10 RC car from Kmart. 

# Project Explanation
When the gyroscope detects a certain amount of rotation left or right it sends an L or R character to serial. The Arduino is connected to the target PC, and the python program reads from serial, simulating the appropriate (A/D) keys. If the game is in focus, this turns the car left or right, simulating an actual racing wheel. The pedals I salvaged work in a similar way; they have buttons to signal activated/not activated, so I connected those to a breadboard and then the W/D keys for forward/backward. 

While it does work, it would be a much smoother experience if I simulated controller inputs for dynamic turning and acceleration, rather than all-or-nothing. I tried to look into controller inputs, however it turned out to be a lengthy process, and was beyond the scope of this project. 

[VIDEO PENDING]

# Directories
ez_wheel_keyboard is the Arduino sketch for the gyroscope steering wheel itself, it gets the gyro data and sends it to the serial port. 

ez_wheel_python is for monitoring the serial port of the computer (with the Arduino connected) and simulating the necessary keys (WASD) when the Arduino steering wheel/pedals are used. 

Everything else is experimentation/me trying to figure out controller simulation to no avail. 