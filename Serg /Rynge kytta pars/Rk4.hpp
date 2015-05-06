#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void RK4_step(          // replaces x(t) by x(t + dt)
    vector<double>& x,  // solution vector
    double dt,          // fixed time step
    vector<double> flow(vector<double>&))   // derivative vector function
{
    int n = x.size();
    vector<double> f(n), k1(n), k2(n), k3(n), k4(n), x_temp(n);
    f = flow(x);
    for (int i = 0; i < n; i++) {
        k1[i] = dt * f[i];
        x_temp[i] = x[i] + k1[i] / 2;
    }
    f = flow(x_temp);
    for (int i = 0; i < n; i++) {
        k2[i] = dt * f[i];
        x_temp[i] = x[i] + k2[i] / 2;
    }
    f = flow(x_temp);
    for (int i = 0; i < n; i++) {
        k3[i] = dt * f[i];
        x_temp[i] = x[i] + k3[i];
    }
    f = flow(x_temp);
    for (int i = 0; i < n; i++)
        k4[i] = dt * f[i];
    for (int i = 0; i < n; i++)
        x[i] += (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6;
}

double RK4_adaptive_step(   // returns adapted time step
    vector<double>& x,      // solution vector
    double dt,              // initial time step
    vector<double> flow(vector<double>&),  // derivative vector function
    double accuracy=1e-6)   // desired accuracy = default value
{
    // from Numerical Recipes
    const double SAFETY = 0.9, PGROW = -0.2, PSHRINK = -0.25,
        ERRCON = 1.89E-4, TINY = 1.0E-30;
    int n = x.size();
    vector<double> scale = flow(x), x_half(n), Delta(n);
    for (int i = 0; i < n; i++)
        scale[i] = abs(x[i]) + abs(scale[i] * dt) + TINY;
    double error = 0;
    while (true) {
        dt /= 2;
        x_half = x;
        RK4_step(x_half, dt, flow);
        RK4_step(x_half, dt, flow);
        dt *= 2;
        vector<double> x_full = x;
        RK4_step(x_full, dt, flow);
        for (int i = 0; i < n; i++)
            Delta[i] = x_half[i] - x_full[i];
        error = 0;
        for (int i = 0; i < n; i++)
            error = max(abs(Delta[i] / scale[i]), error);
        error /= accuracy;
        if (error <= 1)
            break;
        double dt_temp = SAFETY * dt * pow(error, PSHRINK);
        if (dt >= 0)
            dt = max(dt_temp, 0.1 * dt);
        else
            dt = min(dt_temp, 0.1 * dt);
        if (abs(dt) == 0.0) {
            cerr << " step size underflow" << endl;
            exit(1);
        }
    }
    if (error > ERRCON)
        dt *= SAFETY * pow(error, PGROW);
    else
        dt *= 5;
    for (int i = 0; i < n; i++)
        x[i] = x_half[i] + Delta[i] / 15;
    return dt;
}
