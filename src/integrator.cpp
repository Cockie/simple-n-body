#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "integrator.h"
#define G (8.88711204/10000000000)
using namespace std;

Integrator::Integrator(double timestep_)
{
    timestep=timestep_;
}

Integrator::~Integrator()
{
    //dtor
}

