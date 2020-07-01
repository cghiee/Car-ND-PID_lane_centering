#include "PID.h"
#include <math.h>       /* used for power */


/** 
 * Simple PID without integral anti-windup. 
 */

PID::PID() {} /* Constructor */

PID::~PID() {} /* Destructor */

void PID::Init(double Kp_, double Ki_, double Kd_) {

  /* initialize PID gains and error signals */
  this->Kp=Kp_;
  this->Ki=Ki_;
  this->Kd=Kd_;

  this->p_error=0;
  this->i_error=0;
  this->d_error=0;

}

void PID::UpdateErrorTerms(double error) {

  this->d_error = error - this->p_error;  
  this->i_error += error;
  this->p_error = error;  

}

double PID::OutputToActuator(double d_limit=1000.0) {

/* optional limit on derivative term */
if (Kd * d_error>d_limit) return Kp * p_error + Ki * i_error + d_limit;  
if (Kd * d_error<-d_limit) return Kp * p_error + Ki * i_error - d_limit; 

return Kp * p_error + Ki * i_error + Kd * d_error;  
}
