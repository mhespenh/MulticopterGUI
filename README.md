MulticopterGUI
==============

MulticoperGUI - Example application for testing the Multicopter Simulation Library.

Usage:

  Make sure you have already compiled SimMotor and MulticopterSimulator (follow the
    instructions in the MulticopterSimulator repo)
    
  Run MulticopterSimulator from the commandline to start the simulation
  
  Run MulticopterGUI to view the simulation in progress.
  
  You can click anywhere on the map to change the destination of the craft at any
    time.  It shouldn't let you run it into walls.
  
  Try playing around with different mass/armlength/gravity/motor number combinations
    (these changes need to be made at compile time for now (in MulticopterSimulator)
    If the craft is unstable, it is likely just a bad choice of options above.
  
  More cool things to come in v2, including obstacle avoidance and simulated sensor
   noise.
  Currently the simulation map doesn't take armlength into account when "drawing" 
    the craft, but the values do affect the flight dynamics.