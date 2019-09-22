# WeavingMeSoftly
A project for Geekcon 2019 - a loom operated by a bow and arrow.
The player shoots an arrow with a thread tied to it through the loom, as weft.

Key textile terms you may wish to catch up on: loom, warp, weft, shuttle, warp-weighted loom.

## Parts of the project
1. A loom, to be documented later. A variation on the traditional warp-weighted loom, with an extra sawbuck-like construction for the warp to go over. That way the fabric is created on the bottom.

2. A motor circuit, consisting of a button (which can be inside of the targets for the arrow) and 2 endstops.
	The circuit moves the warp after each successful shot, as part of the weaving process.

	The warp is tied to a horizontal frame on the top part of the loom, the motor moves that horizontal frame.

3. A bow and an arrow. Strings attached - the arrow should have a weft string attached to it, because it behaves like a shuttle. We used loops from zip ties in the original projects, and then we could use a few arrows and several threads.

We rolled the threads in a way that they will smoothly unroll when shot, but in retrospect the weft isn't long enough to get tangled. Do tie the end to the loom so that the weft doesn't fully pass through it...

## Arduino files
* loom_motor.ino : operates the motor circuit which moves the frame holding the warp strings.
* motor_speed_test : our motor received a PWM signal that controlled its speed, this is how we tested for the speed we liked. Use that for MOTOR_SPEED in loom_motor.ino.

## Credits
* Amit El-Ad
* Yair Reshef
* Galia Bahat

## Notes and thoughts
We're hoping to bring the loom back to life for EMFcamp 2020, a maker weekend in the UK. 
Possibly only on the mechanical aspect as we won't have a motor and won't be around it enough for it to be safe.
We will rebuild the entire thing since we'll be flying in from abroad so if you can help out with materials or ways to drivev it there it will be appreciated. (Either bring materials from wherever you live and we'll build it during setup, or drive it from London and we'll build it in LHS)