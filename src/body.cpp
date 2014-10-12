#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

#include "body.h"
inline string to_string(double x){
    ostringstream sstream;
    sstream << x;
    string result = sstream.str();
    return result;
}

Body::Body(double x_, double y_, double z_, double vx_, double vy_, double vz_, double mass_, string name_)
{
    x=x_;
    y=y_;
    z=z_;
    vx=vx_;
    vy=vy_;
    vz=vz_;
    mass=mass_;
    name=name_;
    x1=0;
    y1=0;
    z1=0;
    vx1=0;
    vy1=0;
    vz1=0;
}

Body::~Body()
{
    //dtor
}
//updates current speed and position to next speed and position
void Body::update()
{
    x=x1;
    y=y1;
    z=z1;
    vx=vx1;
    vy=vy1;
    vz=vz1;
    x1=0;
    y1=0;
    z1=0;
    vx1=0;
    vy1=0;
    vz1=0;
}
//only updates speed
void Body::updatev()
{
    vx=vx1;
    vy=vy1;
    vz=vz1;
    vx1=0;
    vy1=0;
    vz1=0;
}
//only updates position
void Body::updater()
{
    x=x1;
    y=y1;
    z=z1;
    x1=0;
    y1=0;
    z1=0;
}

string Body::Print(){
    return name+' '+to_string(x)+' '+to_string(y)+' '+to_string(z)+' ';
}

