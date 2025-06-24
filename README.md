**Coordinated Autonomous Vehicle System**

KHALID Jan Sher Islam \| 3035468603 \| jansher@connect.hku.hk\
The University of Hong Kong

## Abstract

Developing a coordinated autonomous vehicle system provides a good way
to understand automation, which is increasingly needed in an engineer's
toolbox. This project uses basic electronics and a microcontroller
(Arduino UNO), alongside its subsequent programming language, on a 5x5
grid to develop the vehicle system. Many functions such as vehicle
traversal, wireless charging, et cetera, were successfully developed --
which are explained in further sections of the paper. Room for future
development is apparent such as developing real on-road traversal and
real-time collision avoidance.

## *Keywords* - Arduino; automation; autonomous; vehicle system; microcontroller; wireless charging; location traversal; safety signalling

## I. INTRODUCTION

### A. Background

As the world becomes increasingly more automated, it is imperative for
engineers in the modern world to understand the basics of automation. An
indicator of the rise of automation is the prevalence of self-driving
cars, whose global industry is growing by 16% annually \[1\]. This
project provides an opportunity to understand autonomous systems at an
introductory level in a practical manner -- by developing a rudimentary
coordinated autonomous vehicle system.

### *B. Scope and deliverables*

It is self-evident that autonomous vehicles are complex systems. In
order to develop such a system from scratch in its initial stage,
certain simplifications are to be made -- from which potential future
projects may build upon to implement additional complex layers. As such,
the scope of the project will be limited to working with a simplified
coordinate system using a 5x5 square grid of 14 cm gaps, with stipulated
deliverables as 8 functions of the autonomous vehicle comprising: going
to a coordinate, then going to one with an obstacle along the way,
braking at a point of interest, multi-point location traversal, charging
wirelessly, light tracking, route optimization, and safety signalling
for traffic. These are expounded upon in further sections of the paper.

![Figure 1: 5x5 Grid](https://drive.google.com/uc?id=16VsBIpmmS2ZkoTbm-FzRvof4Wr3_QHSV)

## II. Methodology

### A. Components

Different functions require the use of different components in different
ways. Therefore, it is sensible to be familiar with the components given
for use in this project before getting into the details of how the
functions were implemented. Please refer to the component list below:

| Component       | Description |
|-----------------|-------------|
| **Component 1** | <figure style="margin:0;text-align:center"><img src="https://drive.google.com/uc?id=118TEAeUvNCsF4TVjg4kttbjW6Ix1c4GP" width="110px" height="78px"><figcaption style="text-align:center">Figure 2: Arduino Uno</figcaption></figure><p>Microcontroller (MIC) board:</p><ul><li>14 digital input/output pins</li><li>6 PWM-supported output pins</li><li>6 analog input pins</li><li>USB connection</li><li>Power jack [2]</li></ul> |
| **Component 2** | <figure style="margin:0;text-align:center"><img src="https://drive.google.com/uc?id=1FYyZ2DlzrN_P1PdUb55zT65jjyhkj4kh" width="70px" height="128px"><figcaption style="text-align:center">Figure 3: Servo motors and wheels</figcaption></figure><ul><li>Servo motors control wheel speed for vehicle motion</li><li>Difference in wheel speed leads to turning</li></ul> |
| **Component 3** | <figure style="margin:0;text-align:center"><img src="https://drive.google.com/uc?id=1dCglXeIbOtbaShyn0qj69nz8WdPN-aq4" width="153px" height="70px"><figcaption style="text-align:center">Figure 4: Breadboard (top and back view) [3]</figcaption></figure><ul><li>Allows for impermanent, solderless, reusable circuit connections</li><li>Upper and lower 2 rows are horizontally connected to power supply</li><li>Columns are vertically connected with a horizontal middle gap for component connection</li></ul> |
| **Component 4** | <figure style="margin:0;text-align:center"><img src="https://drive.google.com/uc?id=1Z_yldZ-BVVMl_QOZEkbTgGLMChFdRzB7" width="96px" height="62px"><figcaption style="text-align:center">Figure 5: QTI (Charge-Transfer-Infrared) Sensors</figcaption></figure><ul><li>Close-proximity-infrared emitter/receiver</li><li>Used to detect the black grid lines</li><li>Darker the color, higher the raw value</li><li>White color detection raw value ~100</li><li>Black color detection raw value ~900</li><li>Critical value for white detection set to &lt;100</li><li>Critical value for black detection set to &gt;700</li></ul> |
| **Component 5** | <figure style="margin:0;text-align:center"><img src="https://drive.google.com/uc?id=1dTLgiFMncumrsplaNH9nInJmex8phKXU" width="102px" height="61px"><figcaption style="text-align:center">Figure 6: Ultrasonic Sensor</figcaption></figure><p><strong>Principle:</strong></p><ul><li>Ultrasonic waves emitted by the sensor are rebounded after hitting an object in front of it</li><li>The time it takes for the wave to be received by the sensor is the travelling time</li><li>Multiplying the speed of sound with half the travelling time gives the object distance</li></ul><p><strong>Application:</strong></p><p>A command can be set to allow the machine to be stopped in front of the object at a specific distance, in this case 4 cm before the object is chosen.</p><figure style="margin:0;text-align:center"><img src="https://drive.google.com/uc?id=14dTANm-hBEZKRvG2LJvE4W_1B6SBWvuQ" width="148px" height="84px"><figcaption style="text-align:center">Figure 7: Ultrasonic sensor working principle [4]</figcaption></figure> |
| **Component 6** | <figure style="margin:0;text-align:center"><img src="https://drive.google.com/uc?id=1NF92FzxPr3rEQtqQLV1sXrRPJAeINmlu" width="81px" height="81px"><figcaption style="text-align:center">Figure 8: Photoresistor</figcaption></figure><p>Detects light intensity</p><figure style="margin:0;text-align:center"><img src="https://drive.google.com/uc?id=15fsUP3MU1duzVdhRyLyZxI9ozETNZ617" width="180px" height="25px"></figure><ul><li>Constant 1 & 2 obtained by calibration</li><li>Calibration should be carried out in stable environment</li></ul> |
| **Component 7** | <figure style="margin:0;text-align:center"><img src="https://drive.google.com/uc?id=1jW8HM2Sy-0RnYXwAkTAOOf9JwDM4IB5T" width="154px" height="93px"><figcaption style="text-align:center">Figure 9: Color Sensor</figcaption></figure><ul><li>All colors come from 3 basic color combinations:<ul><li>red, blue, and green.</li></ul></li><li>Photodiode sensor detects color</li><li>The color sensor has an 8×8 array of photodiodes with 3 different color filters<ul><li>Each of the red, blue, green, and clear color filters have 16 photodiode sensors each.</li></ul></li><li>Every set of photodiode sensors are connected in parallel; we can read data from S2 and S3 pins, the logic is shown in Table 1.</li></ul><table><thead><tr><th>S2</th><th>S3</th><th>Color</th></tr></thead><tbody><tr><td>LOW</td><td>LOW</td><td>Red</td></tr><tr><td>LOW</td><td>HIGH</td><td>Blue</td></tr><tr><td>HIGH</td><td>LOW</td><td>Clear</td></tr><tr><td>HIGH</td><td>HIGH</td><td>Green</td></tr></tbody></table><p><em>Table 1: Color recognition logic</em></p> |
| **Component 8** | <figure style="margin:0;text-align:center"><img src="https://drive.google.com/uc?id=1AOd8ESvP3s61vNr7g-RnZea-8evAmHN5" width="120px" height="90px"><figcaption style="text-align:center">Figure 10: Transmitter/receiver inductive resonant coils</figcaption></figure><p><strong>Function:</strong></p><ul><li>To induce a current via a time-varying magnetic field</li></ul><p><strong>Operating principle:</strong></p><ul><li>Main voltage changes into high frequency alternating current (AC)<ul><li>Transfers to transmitter coil, initiating an alternative field</li><li>Field reaches out to receiver coil, generating a current</li></ul></li><li>Known as magnetic (or full) coupling</li></ul> |

The vehicle is assembled as follows:

### ![Figure 11: Assembled vehicle](https://drive.google.com/uc?id=1xs8ykPkw4vE1f4nf8OvFp5Honr8VoC_x)


### B. Arduino programming

Microcontrollers (MICs) are small computers on a single integrated
circuit (IC). The chips possess a small memory, low processing power,
timer interrupts, and general-purpose input/output (GPIO) pins --
designed to perform specific tasks \[5\].

The key features of the Arduino UNO MIC are stated in the component list
above. These features are programmable using the Arduino IDE (Integrated
Development Environment) software. The IDE software uses a C-like
language, and created programs are flashed to the MIC attached to the
vehicle via USB.

<img src="https://drive.google.com/uc?id=1BioXmV5anK26FspSsU_1gXlOY780uIsM" width="500px" alt="Figure description">

The above code *fade.ino* was one of many created to be familiarized
with Arduino. It uses the MIC to cause a red LED on the breadboard to
gradually fade between off and full brightness and vice versa
continuously. The structure of the code is typical for Arduino
programming, in that it contains 2 main parts: void setup() -- which is
executed in only once in the beginning and is used to declare which pins
are to be used and whether they are to be input or output pins; and void
loop() -- which is executed afterwards and repeats forever, comprising
the function and task of the main program.

RUNS CONTINUOUSLY

## III. Implementation

The stipulated functions were mostly implemented with numerous
difficulties encountered. For detailed explanations on the coding and
logical flows, please refer to the Appendix.

### A. Functions 

**_Function 1: Going to a particular coordinate without obstacles_** requires QTI sensors as its main sensors. There are four QTI sensors installed at the bottom of the vehicle, as shown in Figure 12. The front two QTI sensors are combined to detect the straight black line on the ground, ensuring the vehicle moves on a straight line. The QTI sensors installed under the motors are used to count the number of black lines passed in relation to a specific coordinate of the grid.

![Figure 12: QTI Sensors on the
vehicle](https://drive.google.com/uc?id=1FJKUIaAnn5IztIYPLIugyGx5l2bZAYDu)

For example, to get from A(0, 0) to B(3, 2) as shown in Figure 13, the
forward moving subroutine forwardCar() is called and counts the number
of intersections until 3. Then turnCarOnsiteL() is called to make a
right-angled left turn on (3, 0) and counts the number of intersections.
Once 3 intersections are counted, stop() is called to brake the car.

<p align="center">
  <img src="https://drive.google.com/uc?id=1cIlL0nmPykt9AdBE6WPjhxRsGCEVJXQ8" width="350" alt="Figure 13: A(0, 0) to B(3, 2) path">
  <br>
  <em>Figure 13: A(0, 0) to B(3, 2) path</em>
</p>

[Function 2: Going to a particular coordinate with
obstacles]{.underline} is an expansion of Function 1. The extra
component involved is the ultrasonic sensor. By placing the ultrasonic
sensor at the front of the vehicle, any obstacle in front can be
detected.

If a car detects a small obstacle (within 14 cm), depending on its
position on the grid, the car executes either the move around left() or
move round right() subroutine on the nearest gridline -- ensuring the
car avoids the obstacle while staying on the grid

For example, to get from A(0, 0) to B(4, 5) as shown in Figure 14, the
car first detects an obstacle right right after (1, 0). Once the car is
directly on (1, 0) and since the car is on 'y = 0', it executes move
around left(), which, since the car is travelling in the 'x' direction,
tells the car to increase its 'y' value by 1, then 'x' value by 1, then
finally decrease its 'y' value by 1 -- landing on (2, 0) and continuing
its remaining journey. The logic for the rest of the trip is similar to
that of the aforementioned and that of Function 1.

<figure>
<img src="https://drive.google.com/uc?id=1YKLMIoTtdlC180a4CBUeaXogFfJytDwN" style="width:1.52703in;height:1.57065in"
alt="" />
<figcaption><p>Figure 14: A(0, 0) to B(4, 5) path</p></figcaption>
</figure>

[Function 3: Braking at a point of interest]{.underline} searches for a
specific-color spot and returns the coordinate of the spot. The color
sensor is thus required for this function. In order to guarantee that
the car reaches the point of interest, all possible locations must be
traversed. Hence, a line-by-line sweep is implemented until the color
sensor detects a red-colored spot. The path taken is recorded, and the
coordinate can therefore be displayed. The information exchange process
is achieved by the MQTT system. ^{see\ Appendix}^

The line-by-line sweep uses a volatile int called counter to count the
number of black lines. If the value of counter is both a multiple of 5
and 10, then the go right() subroutine. If the value of counter is a
multiple of 5 but not of 10, then go left()is executed instead.

Figure 8: braking at 'b'

For example, a red spot as shown in Figure 15 is detected and the car
stops at (4, 3). The value of counter == 19 is then converted to its
corresponding coordinate (4, 3) to be displayed on the car's OLED.

<figure>
<img src="https://drive.google.com/uc?id=16-qapQKrXp7apQwC-uhDD6zAYU-3aJGS" style="width:1.52014in;height:1.57292in"
alt="Chart Description automatically generated" />
<figcaption><p>Figure 15: Red spot at (4, 3)</p></figcaption>
</figure>

[Function 4: Multi-point location traversal]{.underline} allows the car
to visit a set of coordinates. The sets coordinates of coordinates are
initialized in an array. The OLED would light up in green and pause for
2 seconds when the car visits one of the coordinates.

The QTI sensors are used to count the number of black lines which
correspond to coordinates. Initially, the car is at (0, 0) and faces
'east'. Any time a turn of 90 degrees is made, the state of 'car facing'
is changed. This can be done by going forward or backward in an array
consisting of the 4 cardinal directions. The difference between the next
coordinate and current coordinate dictates which cardinal direction to
face.

The pins for motor controls, QTI sensors, and OLED are initialized. Then
the variables for counting black lines, the color definitions, and the
initial cardinal direction that the car is facing - are set up. The
arrays for the 4 cardinal directions, and sets of coordinates are also
set up. The array for the cardinal directions if clockwise is positive
is \[N, E, S, W\].

Referring to the path shown in Figure 16 for example, the car starts
from A(4, 1) and is expected to go 'west'. Thus, int dir = 4 is set to
corresponds to the 4^th^ element of the array, which is 'W'. Since the
car is facing 'west', the value of 'x' of the car should decrease with
every increase of counter of x (the integer in the program that counts
the number of black lines passed on the x-direction).

Once counter of x equals the difference of starting coord (i.e. A) and
landing coord (i.e. B), the car turns north and dir is incremented by 1.
The car then moves north until counter of y is equal to the magnitude of
difference between the y-coordinates of A and B. Once the car reaches B,
it stops for 2 seconds and emits green via its OLED. B is set as
starting coord and C is set as landing coord -- continuing the journey.

Once the counter of sets of coords passed reaches the length of the
array of coordinates, i.e., 3, the car stops.

<figure>
<img src="https://drive.google.com/uc?id=10WSB2Tkh0uMhLk8pda-pRHAY1G3_HEKI" style="width:1.95764in;height:1.84861in"
alt="" />
<figcaption><p>Figure 16: A(4, 1)&gt;B(2, 5)&gt;C(1, 3)
path</p></figcaption>
</figure>

[Function 5: Wireless charging]{.underline} requires the use of
inductive resonant coils. As shown in Figure 17, the transmitter coil is
connected to a battery bank to provide power and acts as a charging
station, while the receiver coil is attached to the front of the car to
receive power. The goal of this function is for a car moving in a
straight line to stop right in front of a charging station and for their
coils to touch each other without knocking over the charging station.

<p align="center">
  <img src="https://drive.google.com/uc?id=16A_YyLbM927ICsms7_yF05D2loEJsDFT" width="350" style="display: inline-block; margin: 0 10px;">
  <img src="https://drive.google.com/uc?id=16wZ1H6y1hT7rVKauJhier4mZsKpn_GoU" width="350" style="display: inline-block; margin: 0 10px;">
</p>

Figure 17: Receiver coil (car) and transmitter coil (charging station)

In order to control the speed of the servo motor, analogWrite() should
be used to write the PWM to the continuous servo motors. The ultrasonic
sensor is used to detect the obstacle in front of the car.

By trial and error, it was found that stopping the car once
distance_in_cm was less than 20 resulted in enough deceleration such
that the transmitter and receiver coils touch, but does not cause the
charging station to tip over.

In order to display the voltage to the OLED, the analogRead() value of
pin A0 is first multiplied by 5, then divided by 1024 to get vin. "INPUT
V= vin" is then continuously printed on the OLED display as shown in
Figure 18 below.

![Figure 18: Voltage displayed on
OLED](https://drive.google.com/uc?id=1DBQjFN1bjgvArRRwdoKlgfWlUmyniNyJ = 331x467)

In order to get distance_in_cm, a LOW-HIGH-LOW pulse is firstly sent
using trigPin. Then using echoPin, the duration of the pulse is
obtained. By dividing the duration by 2 (to account for sound
refletion), then dividing by 29.1 (pace of sound), the distance_in_cm is
calculated.

[Function 6: Light tracking]{.underline} requires the use of
photoresistors. Two photoresistors are installed at the front of the
vehicle: one to the left and one to the right as shown in Figure 19.

<p align="center">
  <img src="https://drive.google.com/uc?id=12eVXvhA-AHGWhs0XRHkqfw-r8SIoimR3" width="533" height="346" alt="Photoresistor placement">
  <br>
  <em>Figure 19: Photoresistor placement</em>
</p>

The two photoresistors are installed at a 45-degree offset to better
detect light sources to the side of the car. Difference in light
intensity detected between the left and right sensor leads to steering
until the difference is nought -- allowing for the vehicle to track the
light source.

<p align="center">
  <img src="https://drive.google.com/uc?id=1nMhRHJwGWH9NcqZxMj7I53CuT9cVQHnr" width="533" height="346" alt="Light tracking">
  <br>
  <em>Figure 20: Light tracking</em>
</p>

[Function 7: Route optimization]{.underline} is an advancement of
Functions 1 & 3 in that it allows for diagonal movement which saves
time.For the programming part, two kinds of cases should be considered:

Firstly, when the x or y coordinate of the starting point and
destination are the same, the car will go straight along the x-direction
and y-direction. It has no optimized route, the stand route is equals to
the optimized route, e.g. from A to D as shown in Figure 21.

Secondly, when the (x, y) coordinates of initial point and final point
are totally different. And it has two cases.

For case 1, the points are also located on the same diagonal line, e.g.
from A to C. The standard route is in red, the car goes from A to D then
D to C. It contains 10 lines of movement. For an optimized route which
is green in colour, goes diagonally. It is only 5 \* sqrt(2) lines
movement, the movement is reduced by 29%.

For case 2, the points are not located on the same diagonal line, e.g.
from A to B. The standard route is in red, the car goes down for 3 lines
of movements and two lines of movement to the left. It contains 5 lines
of movement. For an optimized route which is green in colour, goes
vertically and diagonally. It is only 1 + 2 \* sqrt(2) lines movement,
the movement is reduced by 23%.

The programme is summarized into two main parts. Part 1: the next point
chosen is the one closest to the destination among all 8 options. And
part 2: if the new x, y coordinates are both larger than the x,y
coordinates, the new point chosen will be the point that both x,y
coordinates increments by 1.

<figure>
<img src="https://drive.google.com/uc?id=1oh-x9J0Xd4Kk0O0VoJNwnGKlh8AI8K6q" style="width:1.70767in;height:1.85454in"
alt="" />
<figcaption><p>Figure 21: Diagonal pathing</p></figcaption>
</figure>

[Function 8: Safety signalling]{.underline} was not completed. However,
the proposed method of implementation is as followed:

Traffic safety signalling simulates actual traffic conditions to test
the functionality of the car and the traffic light if they can prevent
the occurrence of traffic accidents.

The use of infrared (IR) distance sensors were proposed to detect the
distance from the car to the object. And it has two types of LEDs:
Emitter, for emitting light, and the receiver which is an IR photodiode.
The mechanism is triangulation. The distance is calculated by the angle
of a reflected IR off a surface.

<p align="center">
  <img src="https://drive.google.com/uc?id=1axNJ62H6PXatO20segMoIbVsJM5k6DAk" width="300" height="300" alt="IR distance sensor">
  <br>
  <em>Figure 22: IR distance sensor</em>
</p>

Two distance sensors were proposed to be used in this project, the
ultrasonic sensor and the IR sensor. The justification in choosing the
sensors have been done in order to fit the proposed function. The
simulation requires fast reaction speed. Compared to ultrasonic sensor,
IR sensor has fast reaction speed (due to difference in speed of light
vs sound) and has less error compared to the detection errors found in
the ultrasonic sensor. The errors will be discussed in later parts of
the paper.

The IR has three ports (Signal, Vcc and ground). They are connected with
the MIC as shown in Figure 23. The IR sensors detect road condition and
send the signals to the vehicle and control the car movement.

<figure>
<img src="https://drive.google.com/uc?id=1LEBDIcC9I4IQpNHVfBscIGi5sGGpuX7d" style="width:2.19771in;height:1.2987in"
alt="" />
<figcaption><p>Figure 23: Schematic Diagram for Funtion
8</p></figcaption>
</figure>

The road status can be divided into 4 situations:

00 -- Road is full\
01 -- Road is empty\
02 -- Road has some vacancies\
03 -- Cross section of road is blocked

Two IR sensors that can represent four combinations (00/01/10/11) are
installed in one traffic light. 00 and 03 are also the situations that
are not allowing the car to enter the road or make a turn. 01 and 02 are
also the situations that are allowing the car to pass through.

<p align="center">
  <img src="https://drive.google.com/uc?id=1aW6_9zIVSRKh4fPjHjbYH11O8teZC9ye" width="300" style="display: inline-block; margin: 0 10px;" alt="Image 1">
  <img src="https://drive.google.com/uc?id=1eMj3kc0Qn-L3YyR11ZdHq_dhicPRJtIz" width="300" style="display: inline-block; margin: 0 10px;" alt="Image 2">
</p>

Figure 24: Traffic conditions

Figure 24 above shows how the system works. From the figure on the left,
car one has three options which are turning left, turning right and
going straight. The first road is full of cars, therefore the IR sensors
send signals to the arduino and turn the LED into red showing that the
road is full (00). And the car is available to turn right because the
LED of the traffic light is green showing that the road is empty (01).
Going straight is also the available option as the road is empty (01).
For car 2, turning left is the available option as the road is empty
(01).

Another figure shows the coming future of the car, the story continues
and Car 1 meets Car 2, the traffic lights at both of the roads detect
the car, therefore, the traffic status is updated and turns red showing
the road is full (00). So now, Car 2 was told to stop and car 1 has two
options left either go back or go straight.

### B. Reflections on implementation

As stated previously, there were multiple difficulties faced during the
project. There were potential hardware and coding issues that
contributed to the difficulties faced.

[One of the motors was found to not function properly.]{.underline}
Different debugging methods were used. It was not a software issue as
the software worked for other motors. Therefore, it had to be a hardware
issue. The issue was not with the motor itself as placing the motor on
the other side of the car made it work. Wiring was not an issue as
replacing the wires with known working wires did not solve the problem.
Nor was motor driver breakout (LM298) the issue. After replacing each
component one-by-one, the error was still not found. It was only after
changing the pins used did the motor on one side of the car work, hence
the issue was found to be a broken pin.

[Initially, the car had difficulty moving in line with the
grid.]{.underline} This problem might have been caused by the position
of the QTI sensor. By observing the monitoring window of the Arduino
IDE, it was found that the reading of black lines would increase
significantly in effectiveness only if the QTI sensor were placed very
close to the black line. However, the QTI sensor was initially installed
at a relatively high position -- level with the photo-diode sensor. The
QTI sensor was therefore installed at a lower position, as shown in
Figure 25, which improved its sensitivity.

<p align="center">
  <img src="https://drive.google.com/uc?id=1F-_M9iCeVY6ljVtr9MR5od5a5qbKeM58" width="650" alt="Updated QTI sensor position">
  <br>
  <em>Figure 25: Updated QTI sensor position</em>
</p>

[Function 2: Going to a particular coordinate with
obstacles]{.underline} experienced ultrasonic sensor detection error
issues possibly caused by the internal noise of the sensor. When the
loop is executing, the returned value of '0' would be recorded and the
function of the program would recognize it as an obstacle. Therefore, in
order to solve this issue, a delay time (i.e. 'delay(10)') was added
inside the loop. If there was no delaying time, resultant impedance
would be high, therefore the accuracy would be lower.

[Function 3: Wireless charging]{.underline} occured without the grid and
had pathing error likely due to differences in internal resistances of
the servo motors. The outcome of this situation would be causing the
path of the car to be bent. Therefore, the speed of the two motors
needed to be balanced via software aid. In the code shown below, the
speed would be balanced by using the actual speed to plus or minus the
input speed.

<p align="center">
  <img src="https://drive.google.com/uc?id=1_rxsUqJH6nXka6eaLRRCICCoU4nsd5ou" height="800" alt="SERVO CORRECTION">
  <br>
  <strong>CODE 2: SERVO CORRECTION</strong>
</p>

[Function 6: Light tracking]{.underline} varies in how functional it was
based on the calibration process. Initially, the car was not following
the flashlight from a smartphone well. This was possibly due to the fact
that the calibration of the photodiode was carried out outdoors with
many light sources present. After recalibrating the photodiodes indoors
with stable and unchanging ambient light intensity, more accurate values
for 'Constant 1' and 'Constant 2' of the equation below were obtained --
leading to better light tracking.

<figure>
<img src="https://drive.google.com/uc?id=15fsUP3MU1duzVdhRyLyZxI9ozETNZ617" width="400"
alt="" />
<figcaption><p>Equation 1: Photodiode Calibration
Equation</p></figcaption>
</figure>

[Function 7: Route optimization]{.underline} required a new 5x5 grid
with diagonal options. The intersection in the grid was made by four
lines of black tape. The car could not move comfortably since the
thickness of intersection was different with different grid lines. The
car was not able to go to some specific point and the more intersections
it needed to travel, the higher the likelihood it would steer
off-course.

[Function 8: Safety signalling]{.underline} was not implemented due to
time and material constraint.

## iV. conclusion

### A. Work done

The aim of this project was to understand automation at an introductory
level as it is increasingly important for engineers to meet the global
trend of increasing automation. This was done by developing a
coordinated autonomous vehicle using Arduino microcontroller and program
on a 5x5 grid. Though many difficulties were faced, all but one of the
initially agreed-upon functions to be developed were successfully
implemented. The vehicle was able to perform multi-point location
traversal, obstacle avoidance, light tracking, wireless charging, and
colored-point coordinate locating.

### B. Future work

[GPS sensors]{.underline} as an upgraded replacement to the grid system
seems like the next logical step to take in the future. The ability for
a vehicle system to implement GPS data in order to move from one point
to another would be a huge increase in versatility.

The current 5x5 grid system was useful to understand vehicle movement
and basic point-to-point travel. However, it cannot be transferred
immediately to upscaled and roadside application. Therefore, it is
important to be familiarized with GPS implementation.

[Real-time collision avoidance]{.underline} is another logical
development to make. An autonomous vehicle in the real world should not
only be able to avoid static obstacles, but also dynamic obstacles such
as pedestrians and other vehicles in motion.

The project only dealt with stationary small obstacles. While useful in
understand very basic collision avoidance, is not immediately
transferable to a real-life system.

## Acknowledgement

I would like to thank Dr. W.Y. Cheung for his assistance throughout the
project.

## References

[1] Mordor Intelligence, "United States Autonomous Car Market - Growth, Trends, Covid-19 Impact, and Forecasts (2022 - 2027)," 2022.  

[2] Arduino, "UNO R3 Datasheet," [Online]. Available: [https://docs.arduino.cc/static/e7bd0e090ada1e27cf2c4a63d3096cbc/A000066-datasheet.pdf](https://docs.arduino.cc/static/e7bd0e090ada1e27cf2c4a63d3096cbc/A000066-datasheet.pdf) [Accessed 2023].  

[3] "BioBuilder: Synthetic Biology in the Lab," Publicism, 2015. [Online]. Available: [https://publicism.info/science/biobuilder/8.html](https://publicism.info/science/biobuilder/8.html).  

[4] microsonic, "Ultrasonic technology," [Online]. Available: [https://www.microsonic.de/en/support/ultrasonic-technology/principle.htm](https://www.microsonic.de/en/support/ultrasonic-technology/principle.htm).  

[5] Wikipedia, "Microcontroller," [Online]. Available: [https://en.wikipedia.org/wiki/Microcontroller](https://en.wikipedia.org/wiki/Microcontroller).  

## Appendix

### Function 1: Going to a particular coordinate without obstacles

<table>
  <tr>
    <th width="50%">Situation 1</th>
    <th width="50%">Situation 2</th>
  </tr>
  <tr>
    <td>
      When the left and right QTI sensors detect a value smaller than 100 and the middle two sensors detect a value larger than 700, the car would move straight on the grid.
    </td>
    <td>
      When all of the four sensors detect a number larger than 700, it indicates the car is at the intersections of the two lines. An instruction can be given to control the car to turn left or turn right.
    </td>
  </tr>
  <tr>
    <td align="center">
      <img src="https://drive.google.com/uc?id=1bK-X87u7bcSnTaC74WTx9nVi6_2OVmq2" width="300" alt="Situation 1">
    </td>
    <td align="center">
      <img src="https://drive.google.com/uc?id=1XFXTVUuw8oCGRtcjvlW3Jnc0OAEEIQXr" width="300" alt="Situation 2">
    </td>
  </tr>
</table>

The general idea of the function is to count the number of intersections
came across. Theoretically, the value we set is 700. When QTI detects
black line, it will give the values \> 500 instead of 700, as the QTI
keeps detecting the ground and in the view of QTI, black and white are
switching, therefore the range of the value will be between 500 to 700
for the black surface. We used digitalRead(qtiPinL) to get a boolean
reading of the QTI sensors which worked once we adjusted the sensitivity
of the sensor using a screwdriver.

<figure>
<img src="https://drive.google.com/uc?id=1h-dnO2nWdPAhW_oKSP1UoakEzR4Dt0UH" style="width:2.19989in;height:2.31553in"
alt="" />
<figcaption><p>APPX 3: FUNCTION 1 MAIN CODE</p></figcaption>
</figure>

If, for instance, the destination is (3, 2) with dhe initial point (0,
0) at the left top corner, forwardCar() is called and counts the number
of intersections by 3, then turnCarOnsiteL() and count for two
intersections and stop().

## Function 2: Going to a particular coordinate with obstacles

### Programme Flow

<table>
  <tr>
    <td colspan="2">
      The logic is very similar to Task 1.1. However, we also consider obstacles and assume an obstacle no more than 15 cm wide.
      <br><br>
      We initialize the program for the QTI pins, motor pins, and ultrasonic pins. We initialize the variables for counting black lines. And we initialize the constants for the destination coordinates 'x' and 'y'.
      <br><br>
      The car moves along the positive direction of the x-axis until 'counter of x' is equal to 'x'. Then the car turns left. Then the car goes forward in the positive y direction until 'counter of y' equals 'y'.
    </td>
  </tr>
  <tr>
    <td width="60%">
      <strong>How the car alters its route if obstacles within specified dimensions are detected by the ultrasonic sensor.</strong>
      <br><br>
      If wider obstacles are used, the forwardCar duration can be altered, and the increment of 'x' or 'y' can be greater than one.
    </td>
    <td width="40%">
      <strong>'move around left' subroutine</strong> on the nearest gridline<br>
      (turnCarOnsiteL → forwardCar → turnCarOnsiteR → forwardCar → turnCarOnsiteR → forwardCar → turnCarOnsiteL). The 'counter of x' is incremented by 1, and the car continues forward in the x-axis until 'counter of x' equals 'x'.
      <br><br>
      However, if the car is moving along the y-axis, the car would instead execute 'move around right' subroutine. This is to ensure the car stays within the grid.
    </td>
  </tr>
  <tr>
    <td align="center" colspan="2">
      <img src="https://drive.google.com/uc?id=1s0saxPuTelqDpoydWcpWgfgfpdjvtHRw" width="400" alt="Appx 4: Breadboard connection for Function 2">
      <br>
      <em>Appx 4: Breadboard connection for Function 2</em>
    </td>
  </tr>
</table>

[Function 3: Braking at a point of interest]{.underline}

<figure>
<img src="https://drive.google.com/uc?id=1BvhxHVeFPb_Ojr-5uuJ5NDiDwjtN_svF" style="width:1.18889in;height:1.33056in"
alt="" />
<figcaption><p>Appx 5: Color sensor-MIC interface</p></figcaption>
</figure>

The car starts from (0,0) and goes along the positive direction of the
x-axis. The car then performs a scanning action by counting 5 black
lines (i.e from 0,0 to 5,0), then turning to (5,1), then counting
another 5 black lines, then turning, etc until the car reaches (5,5)
which then stops.

go right() subroutine (turnCarOnsiteR \> forwardCar \> turnCarOnsiteR).

If no red spot is detected, the car stops at (5, 5) i.e. when counter ==
25, then "no red spot" is to be displayed on the OLED. The connection is
shown as below: 

<figure>
<img src="https://drive.google.com/uc?id=1uwq1s3cdtwQnMsg25BbubFQk-7Lb891Y" height="350"
alt="" />
<figcaption><p>Appx 6: Interface of OLED with Arduino</p></figcaption>
</figure>

The connection of the pins is shown in the table below:

  -----------------------------------------------------------------------
             **Pin on OLED**                **Pin number on Arduino**
  -------------------------------------- --------------------------------
                 DIN pin\                               49
              (Serial Data)              

                 CLK pin                                50

             Chip Select pin                            48

                 D/C pin                                46

                 RES pin                                47
  -----------------------------------------------------------------------

  : Appx 7: OLED pin connection

[Function 5: Wireless charging]{.underline}

Different servo motors might have a slightly different turning speed.
Therefore, the speed should be balanced.

Besides, the car should get the most efficient charging by having the
optimum charging distance and location, which means the transmitter coil
and the receiver coil should be aligned and touched with each other. It
requires the ultrasonic sensor to work precisely.

A good way to increase the straightness of the path which the car moves,
is to make the car to run at a relatively high speed to prevent bending
of the path.

We initially set-up the pins of the OLED, motor controls, ultrasonic,
and voltage (pin A0). We also initialize the values of the variables we
need to use as zero. We also define the colors for the OLED to display.

In the loop, we carry out the calculation of 'vin', we print 'vin' with
white text and black background, and we carry out calculation of
distance_in_cm. Then we set up two conditionals, one for distance_in_cm
less than 20, the other is for otherwise.

| Appendix | Content |
|----------|---------|
| **Appendix 8: Conditional 1** | <img src="https://drive.google.com/uc?id=1fOV58OdbssxVX9HHle1cPfC8GAiBGpBq" width="226" alt="Conditional 1"><br><br>In the first conditional, the car should stop once distance_in_cm is less than 20. This ensures the car decelerates properly so the transistor and resistor coils make contact without tipping over the charging station.<br><br>Furthermore, 'vin' continues to be displayed. |
| **Appendix 9: Conditional 2** | <img src="https://drive.google.com/uc?id=1w4YUp7Nhc4yZHk_FdSeWeMkttGbalh6K" width="250" alt="Conditional 2"><br><br>If distance_in_cm is not less than 20, the car continues going forward.<br><br>Furthermore, 'vin' continues to be displayed. |
| **Appendix 10: Car movement subroutines** | <img src="https://drive.google.com/uc?id=1HHJKGWaBPtKx9q65sKplrN5O7oEuydIN" width="280" alt="Car movement subroutines"> |
