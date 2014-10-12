#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "seuler1.h"
#define GRAVC (8.88711204/10000000000)

/*********************************************
Implementation of the first order symplectic Euler algorithm
*********************************************/

//returns x^2
inline double squ(double x){
    return (x*x);
}

sEuler1::sEuler1(double timestep_):Integrator(timestep_)
{
    //ctor
}

sEuler1::~sEuler1()
{
    //dtor
}

void sEuler1::tick(vector<Body*> &bodies){
    double vx1, vy1, vz1, x, y, z;
    for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
        //save coordinates of body for easy reference
        x=(*it)->Getx();
        y=(*it)->Gety();
        z=(*it)->Getz();
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

        //update positions based on current speed: x1 = x + v*t
        (*it)->Setx1( x + vx1*timestep );
        (*it)->Sety1( y + vy1*timestep );
        (*it)->Setz1( z + vz1*timestep );
    }
    //erase old positions and speed and replace them with the new ones
    for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
        (*it)->update();
    }
}

void sEuler1::start(vector<Body*> &bodies) {
    return;
}
