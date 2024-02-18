#include "vex.h"

float Odom::calculate_x(float angle, float pos){
  return cos(to_rad(angle))*pos;
};

float Odom::calculate_y(float angle, float pos){
  return sin(to_rad(angle))*pos;
};

float Odom::calculate_theta(float x, float y){

  return x/acos(to_rad(sqrt((x*x)+(y*y))));
};

float Odom::calculate_distance(float x, float y){
  return sqrt((x*x)+(y*y));
};
