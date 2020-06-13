***As I work on a computer lend by my friend, the First Commt messages appear to be in that person's name. However this repository work was done by Git User: LakshmiPrasannan***
# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

A link to the car making it around the track is posted below.
https://youtu.be/qfA8V237iEw

The parameters for the controller were chosen according to trial and error method. As suggested in the lesson by Sebastian I tried impletting a twiddle implementation. However, the twiddle was very slow to train. Twiddle cost function was looking for minimum error, which meant that the car was unstable when at the middle of the road and just swayed. Though it was smoother at the sides, it did veer off at sides. 
 The parameters also were greatly affected by the speed of the car. When higher speed like a 40MPH there was a lot of disturbance in the route followed. Note the speed portion was also governed by a pid controller. The steer PID controller used the P,I,D parameters, -.1, -0.0005, -.5. The I term turned out to be pretty insignificant even though the simulated car had a baised steering angle. The baised steering angle meant that if the car drove with zero steer turning then it would veer off to the right. The speed PID had P,I,D parameters of 0.3, 0.002, 0.0, so it was just a PI controller.

The P term greatly impacted the amount of sway that the car had, the larger the value the larger distance it would osscillate. A high P value was important for the car to do tight turns, but too large and it would sway when going stright. The D term was very important for dampening the sway factor, and was set just by experimentation. The I term although not having a large impact to the overall system was being used to help offset the steering biasis.

Although the car could go up to 30 MPH with the parameters chosen, it was set back down to 20 MPH just to be safe.

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/aca605f8-8219-465d-9c5d-ca72c699561d/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

