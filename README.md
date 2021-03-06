# Balancing_System_2.0Beta (Upcoming)
With the balancing system working application basement.

This system is working the axes transferring along the body, wind and balancing coordinations, which shows the results of displacement and momentum. Meanwhile, it is demonstrating that some errors should still inside the system by applying the average multi-iteration method (AMI) to immerse.

## Nomenclature

### Greek Alphabet
|  Letter  |           Name            |     Words in Scripts    |
|----------|---------------------------|-------------------------|
|    α     |   Angle of Attack (AOA)   |          alpha          |
|    β     |   Angle of Sideslip       |          beta           |
|    γ     |   Angle of Roll           |          gamma          |
|    δx    |   Yaw of Aileron          |          deltax         |
|    δy    |   Yaw of Rudder           |          deltay         |
|    δz    |   Yaw of Elevator         |          deltaz         |
|    δcm   |   Yaw for all flexibility |          delta          |
|    ψ     |   Pitch of slab tail      |          psi            |
|    σ     |   Recovery Pct Index      |          sigma          |
|    φ     |   Flux Index              |          phi            |
|    ρ     |   Air density             |          rho            |
|    μ     |   Viscosity of fluid      |          miu            |

### Latin Alphabet
|  Letter  |           Name            |     Words in Scripts    |
|----------|---------------------------|-------------------------|
|    M     |        Mach number        |            M            |
|    P     |          Pressure         |       P/P0/Pct/Pi       |
|    T     |        Temperature        |           T/T0          |
|    Re    |       Reynold number      |            Re           |
|    q     |      Dynamic Pressure     |            q            |
|  X,Y,Z   |       Displacements       |          x/y/z*         |
| Mx,My,Mz |         Momentums         |         mx/my/mz        |
| Cx,Cy,Cz |    Coefficient of Forces  |         cx/cy/cz        |
|   Cmx    |  Coefficient of Momentum  |       cmx/cmy/cmz       |
|   My_α   |  Aerodynamic derivative   |           mya           |
|  Cmy_α   | Coefficient of Aero_deri  |           cmya          |
|   avgX   |  Average Aerodynamic Char |           avgx          |
|    b     |    Average Chord Length   |            b            |
|    l     |          Wing Span        |            l            |
|   detl   | Center for Axis Alignment |           detl          |

### Notes
* x  mx: the wind coordination       (x)    (mx)
* x1 mx1: the body coordination      (x1)   (mx1)
* x' mx': the balancing coordination (x11)  (mx11)


## Capabilities
At its core, transferring system is a part of wind tunnel running system, which the collected data from the experiements should redefine the contents for the further analysis. For more, based on this system, the best target of future contributions are the aerodynamic analysis through the algorithm, if this system will have the ability to mixture running with the other works.
In short, the balancing transferring calculator could outcome with different axial results in pitching, rolling and yawing motion for tested model. In fact, the continuous way is forming a voltage recieving system to directly output the physical variables.
* Model Analysis, Axial Transfer and Aerodynamic Information Outcome;
* 5-6 DoF Balancing System Alignment Tool;
  + By applying the different balancing equipments to transfer values; (New)
  + Using the input electrical signal value to enhance the experiment simularity; (New)
* Coefficient of aerodynamic variables (upcoming);
* Experimental Diagram Process (upcoming):
  + Static Diagram (Forces with motional angle);
  + Aerodynamic Derivative Diagram;
  + Mach Number Relevants;
  + 'Zero-Point' Alignment (For immersing errors);

* Center Point Definition (Focusing Point, Average Axis, Pressure Center);
* Average Values Fixing;










