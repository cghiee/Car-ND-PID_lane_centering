#include "PID.h"
#include <math.h>       /* pow */

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  this->Kp=Kp_;
  this->Ki=Ki_;
  this->Kd=Kd_;

  this->p_error=0;
  this->i_error=0;
  this->d_error=0;

}

void PID::UpdateError(double cte) {

  /**
   * TODO: Update PID errors based on cte.
   */
  this->d_error=cte-this->p_error;  
  this->i_error+=cte;
  this->p_error=cte;  

}

double PID::TotalError(double speed) {
  /**
   * TODO: Calculate and return the total error
   */
  double d_limit=0.15;
  double limited_d_term=0;
          if (Kd*d_error>d_limit) limited_d_term=d_limit;
          if (Kd*d_error<-d_limit) limited_d_term=-d_limit;

  //return Kp*p_error*(speed/pow(speed+.1,0.5)) + Ki*i_error + Kd*d_error*(speed/15);  // TODO: Add your total error calc here!
  return Kp*p_error + Ki*i_error + limited_d_term;  // TODO: Add your total error calc here!
}
