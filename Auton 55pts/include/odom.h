#pragma once
#include"vex.h"

class Odom {
  public:
    

    float calculate_x(float angle, float pos);
    float calculate_y(float angle, float pos);
    float calculate_theta(float x, float y);
    float calculate_distance(float x, float y);
    


};