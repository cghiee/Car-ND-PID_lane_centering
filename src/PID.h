#ifndef PID_H
#define PID_H

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update each term in the PID error variables given the current error
   * @param error The current error
   */
  void UpdateErrorTerms(double error);

  /**
   * Calculate the each term of the PID error
   * @output the total command to the actuator
   */
  double OutputToActuator(double d_limit);

 private:
  /**
   * PID Error terms
   */
  double p_error;
  double i_error;
  double d_error;

  /**
   * PID Gain coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
};

#endif  // PID_H