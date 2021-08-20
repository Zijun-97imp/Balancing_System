//
//  main.c
//  angle_transfer
//
//  Created by mac on 18/08/2021.
//

#define _CRT_NO_SECURE_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

double Aerodynamic (double rho, double v)
{
    double q;
    q = 0.5 * rho * (v*v);
    return q;
}

double DRotate (double x11, double y11, double z11, double gamma, double val)
{
    double y1, z1;
    y1 = y11 * cosf(gamma*val) + z11 * sinf(gamma*val);
    z1 = z11 * cosf(gamma*val) - y11 * sinf(gamma*val);
    return y1;
    return z1;
}

double MRotate (double mx11, double my11, double mz11, double gamma, double z11, double dl, double y, double val)
{
    double mz1, my1, mx1;
    mz1 = mz11 * cosf(gamma*val) - my11 * sinf(gamma*val);
    my1 = my11 * cosf(gamma*val) + mz11 * sinf(gamma*val);
    mx1 = mx11 + z11 * dl * y;
    return mz1;
    return my1;
    return mx1;
}



int main()
{
    // Coordination System Values
    double alpha, gamma, theta;                               // spining angles
    double x, x1, x11, y, y1, y11, z, z1, z11;                // displacements
    double mx, mx1, mx11, my, my1, my11, mz, mz1, mz11;       // momentums
    double dl;
    
    // Aerodynamic System Values
    double rho, v, q = 0.0;                                         // properties of aerodynamics
    
    // Angle transfer (from radius to angle)
    double val = PI / 180.0;
    
    
    // air properties
    printf("Please define the density of wind: ");
    scanf("%lf", &rho);
    printf("Please define the velocity of wind: ");
    scanf("%lf", &v);
    
    // rotational angle of different coordinations
    printf("enter the angles alpha, gamma and theta: \n");
    printf("angle alpha: ");
    scanf("%lf", &alpha);
    printf("angle gamma: ");
    scanf("%lf", &gamma);
    printf("angle theta: ");
    scanf("%lf", &theta);
     
    // the displacements on different coordinations
    printf("enter the values from Wind Coordination (x,y,z): \n");
    printf("displacement x: ");
    scanf("%lf", &x);
    printf("displacement y: ");
    scanf("%lf", &y);
    printf("displacement z: ");
    scanf("%lf", &z);

    printf("enter the values from Body Coordination (x1,y1,z1): \n");
    printf("displacement x1: ");
    scanf("%lf", &x1);
    printf("displacement y1: ");
    scanf("%lf", &y1);
    printf("displacement z1: ");
    scanf("%lf", &z1);

    printf("enter the values from Balancing Coordination (x11,y11,z11): \n");
    printf("displacement x11: ");
    scanf("%lf", &x11);
    printf("displacement y11: ");
    scanf("%lf", &y11);
    printf("displacement z11: ");
    scanf("%lf", &z11);
    

    // the momentums on different coordinations
    printf("enter the momentum from Wind Coordination (mx,my,mz): \n");
    printf("momentum mx: ");
    scanf("%lf\n", &mx);
    printf("momentum my: ");
    scanf("%lf\n", &my);
    printf("momentum mz: ");
    scanf("%lf\n", &mz);

    printf("enter the momentum from Body Coordination (mx1,my1,mz1): \n");
    printf("momentum mx1: ");
    scanf("%lf\n", &mx1);
    printf("momentum my1: ");
    scanf("%lf\n", &my1);
    printf("momentum mz1: ");
    scanf("%lf\n", &mz1);

    printf("enter the momentum from Balancing Coordination (mx11,my11,mz11): \n");
    printf("momentum mx11: ");
    scanf("%lf\n", &mx11);
    printf("momentum my11: ");
    scanf("%lf\n", &my11);
    printf("momentum mz11: ");
    scanf("%lf\n", &mz11);



    printf("enter the value for momentum misalignment: \n");
    scanf("%lf\n", &dl);

    
    // calculation of results
    Aerodynamic(rho, v);
    printf("the dynamic pressure: \nq = %lf\n", q);
    
    DRotate(x11, y11, z11, gamma, val);
    printf("the displacement after axis transferring: \nY1 = %lf\nZ1 = %lf\n", y1, z1);

    MRotate(mx11, my11, mz11, gamma, z11, dl, y, val);
    printf("the momentum after axis transferring: \nMY1 = %lf\nMZ1 = %lf\nMX1 = %lf\n", my1, mz1, mx1);
    
    return 0;
}
