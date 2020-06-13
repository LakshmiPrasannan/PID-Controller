#include "PID.h"
using namespace std;

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  i_error = 0.0;
  p_error = 0.0;
  
  total_error = 0.0;
  cycle_n = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
	d_error = (cte - p_error);
  	p_error = cte;
  	i_error = cte;
  
  	total_error += (cte * cte);
  	cycle_n++;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return total_error;  // TODO: Add your total error calc here!
}