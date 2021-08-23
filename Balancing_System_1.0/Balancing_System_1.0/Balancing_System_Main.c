//
//  Balancing_System_Main.c
//  Balancing_System_1.0
//
//  Created by mac on 23/08/2021.
//

#define _CRT_NO_SECURE_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void Aerodynamic (double rho, double v, double *q)
{
    *q = 0.5 * rho * (v*v);
}

void DRotate (double y11, double z11, double gamma, double val, double *y1, double *z1)
{
    *y1 = y11 * cosf(gamma*val) + z11 * sinf(gamma*val);
    *z1 = z11 * cosf(gamma*val) - y11 * sinf(gamma*val);
}

void MRotate (double mx11, double my11, double mz11, double gamma, double z11, double dl, double y, double val, double *mz1, double *my1, double *mx1){
    *mz1 = mz11 * cosf(gamma*val) - my11 * sinf(gamma*val);
    *my1 = my11 * cosf(gamma*val) + mz11 * sinf(gamma*val);
    *mx1 = mx11 + z11 * dl * y;
}


int main()
{
    // Coordination System Values
    double alpha, gamma, theta;                               // spining angles
    double x, x1, x11, y, y1, y11, z, z1, z11;                // displacements
    double mx, mx1, mx11, my, my1, my11, mz, mz1, mz11;       // momentums
    double dl;
    
    // Aerodynamic System Values
    double rho, v, q;                                         // properties of aerodynamics
    
    // Angle transfer (from radius to angle)
    double val = PI / 180.0;
    
    
    // air properties
    printf("Please define the density of wind (kg/m3): ");
    scanf("%lf", &rho);
    printf("Please define the velocity of wind (m/s): ");
    scanf("%lf", &v);
    
    // rotational angle of different coordinations
    printf("enter the angles alpha, gamma and theta (o): \n");
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

    printf("enter the values from Balancing Coordination (x',y',z'): \n");
    printf("displacement x': ");
    scanf("%lf", &x11);
    printf("displacement y': ");
    scanf("%lf", &y11);
    printf("displacement z': ");
    scanf("%lf", &z11);
    

    // the momentums on different coordinations
    printf("enter the momentum from Wind Coordination (mx,my,mz): \n");
    printf("momentum mx: ");
    scanf("%lf", &mx);
    printf("momentum my: ");
    scanf("%lf", &my);
    printf("momentum mz: ");
    scanf("%lf", &mz);

    printf("enter the momentum from Body Coordination (mx1,my1,mz1): \n");
    printf("momentum mx1: ");
    scanf("%lf", &mx1);
    printf("momentum my1: ");
    scanf("%lf", &my1);
    printf("momentum mz1: ");
    scanf("%lf", &mz1);

    printf("enter the momentum from Balancing Coordination (mx11,my11,mz11): \n");
    printf("momentum mx': ");
    scanf("%lf", &mx11);
    printf("momentum my': ");
    scanf("%lf", &my11);
    printf("momentum mz': ");
    scanf("%lf", &mz11);



    printf("enter the value for momentum misalignment: \n");
    scanf("%lf", &dl);

    
    // calculation of results
    Aerodynamic(rho, v, &q);
    printf("the dynamic pressure: \nQ = %lf\n", q);
    
    DRotate (y11, z11, gamma, val, &y1, &z1);
    printf("the displacement after axis transferring: \nY1 = %lf\nZ1 = %lf\n", y1, z1);

    MRotate (mx11, my11, mz11, gamma, z11, dl, y, val, &mz1, &my1, &mx1);
    printf("the momentum after axis transferring: \nMY1 = %lf\nMZ1 = %lf\nMX1 = %lf\n", my1, mz1, mx1);
    
    return 0;
}
