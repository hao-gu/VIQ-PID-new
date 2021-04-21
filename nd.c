double kp;
double kd;
//integral not useful
double dp; //accounting for drift with encoder values
double gp; //accounting for drift with a gyro

//Universal variables
double error;
double terror;
double PrevError;
double derivative;

void setconstants(double p,double d,double df,double g)//makes tuning easier in the main document
{
  kp=p;
  kd=d;
  dp=df;
  gp=g;
}
double drift(double l,double r) //drift correction with encoders. still working on this
{
  return (l-r)*dp;
}
void drive(double target, double heading)
{
  resetMotorEncoder(right);
  resetMotorEncoder(left);
  error=target;
  PrevError=error;
  while(abs(error)>2||abs(derivative)>1)
  {
    sleep(20);
    error=target-(getMotorEncoder(Left)+getMotorEncoder(Right))/2;
    derivative=error-prevError;
    prevError=error;
    terror = heading-getGyroHeadingFloat(gyro);
    if (terror > 180){
    	terror = terror - 360;
    }
    else if (terror < -180){
	terror = terror + 360;
    }
    setMotorSpeed(Left,error*kp+derivative*kd-terror*gp);
    setMotorSpeed(Right,error*kp+derivative*kd+terror*gp);
  }
  stopMotor(Left);
  stopMotor(Right);
}

void Turn(double heading)
{
		
}







//
