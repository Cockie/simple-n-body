#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "euler.h"
#define GRAVC (8.88711204/10000000000)
//returns x^2
inline double squ(double x){
    return (x*x);
}

Euler::Euler(double timestep_):Integrator(timestep_)
{
    //ctor
}

Euler::~Euler()
{
    //dtor
}

void Euler::tick(vector<Body*> &bodies){
    double vx1, vy1, vz1, x, y, z;
    for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
        //save coordinates of body for easy reference
        x=(*it)->Getx();
        y=(*it)->Gety();
        z=(*it)->Getz();
        //update positions based on current speed: x1 = x + v*t
        (*it)->Setx1( x + timestep*(*it)->Getvx() );
        (*it)->Sety1( y + timestep*(*it)->Getvy() );
        (*it)->Setz1( z + timestep*(*it)->Getvz() );
        //save current speed for calculation of new speed
        vx1=(*it)->Getvx();
        vy1=(*it)->Getvy();
        vz1=(*it)->Getvz();
        //calculate new speed altered by gravity of all other bodies
        for(vector<Body*>::iterator it2 = bodies.begin(); it2 != bodies.end(); ++it2) {
            if((*it2)->Getname()!=(*it)->Getname()){
                vx1 -= timestep*GRAVC*(*it2)->Getmass()*pow(( squ(x-(*it2)->Getx()) + squ(y-(*it2)->Gety()) + squ(z-(*it2)->Getz()) ),-1.5)*(x-(*it2)->Getx());
                vy1 -= timestep*GRAVC*(*it2)->Getmass()*pow(( squ(x-(*it2)->Getx()) + squ(y-(*it2)->Gety()) + squ(z-(*it2)->Getz()) ),-1.5)*(y-(*it2)->Gety());
                vz1 -= timestep*GRAVC*(*it2)->Getmass()*pow(( squ(x-(*it2)->Getx()) + squ(y-(*it2)->Gety()) + squ(z-(*it2)->Getz()) ),-1.5)*(z-(*it2)->Getz());
            }
        }
        //update speeds
        (*it)->Setvx1(vx1);
        (*it)->Setvy1(vy1);
        (*it)->Setvz1(vz1);
    }
    //erase old positions and speed and replace them with the new ones
    for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
        (*it)->update();
    }
}

void Euler::start(vector<Body*> &bodies) {
    return;
}
