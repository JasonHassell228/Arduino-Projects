# RC Car Conversion

Known internally as Slappbot, this is a joke project from a while ago, designed to drive around, play some sound effects and wave a robotic arm around.  

![slappbot - labelled](https://user-images.githubusercontent.com/49383382/160388326-86e504b4-23ea-4456-9717-45dfe4853178.png)

## Why
The main goal of this project was to create an RC car that can "slap like", a popular saying from a Youtuber (Davie504) I watched at the time. 

## The Hardware
I started with a cheap RC car, removed its existing electronics and soldered new wires to the motor connections. I then attached these wires to an Arduino motor shield to control the motors, using the RC car's batteries to power the motors through the motor shield, that way the motors would in theory be getting the same power as they usually would. Unfortunately, the motor shield was not designed to handle this much power and with the added weight of the electronics was only able to output a trickle of movement. Nevertheless, it still technically worked and for the purposes of playing around it was enough for the time being.  

Next was interfacing this with a computer. I wanted to control it from my laptop wirelessly, but getting a wifi module working with the Arduino as well as a sound module to play sound effects was increasing the scope of this project. Luckily I had a Raspberry Pi lying around and figured it would be perfect for the job. I would have used the Pi for the motors as well but my motor shield was designed to sit ontop of an Arduino Uno. The Arduino is connected to the Pi with an ethernet cable, and they communicate via the serial port. 

## The Software
![Py_GUI](https://user-images.githubusercontent.com/49383382/160392189-291711c3-f1a1-4d3c-9fb2-34797b29ef9b.png)
For the soundboard I downloaded a bunch of videos from the Youtuber this project is about, and cut out some popular audio clips in Audacity. I then created a simple Python GUI to play these sounds, and to read any arrow key presses, which were used to control the car's movement. The Pi send characters to the serial port which is then read by the Arduino to control the motors accordingly. Originally I was considering separate apps to communicate between the computer and the car, but ended up using remote VNC to remotely access the Pi's GUI and control the car from my laptop remotely. 

## The Legacy
I spent about a week or two on this project, then university got busy, life happened and Slappbot ended up forgotten under my bed. Unfortunately, while the code for the Arduino was on my laptop, I never backed up the Python GUI from my Pi, which perished in the February 2022 Brisbane floods. The only surviving media about this project is from this joke Youtube video I made to accompany the project, so if you're curious, you can view it in all it's poorly edited glory here: 
https://www.youtube.com/watch?v=OxjGu_-XibI
