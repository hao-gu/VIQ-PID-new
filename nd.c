double kp;
double kd;
//integral not useful
double dp; //accounting for drift with encoder values
double gp; //accounting for drift with a gyro
//Universal variables
double lerror;
double rerror;
double terror;

double lPrevError;
double rPrevError;

double lderivative;
double rderivative;

void setconstants(double p,double d,double df,double g)//makes tuning easier in the main document
{
  kp=p;
  kd=d;
  dp=df;
  gp=g;
}
double drift(double l,double r)
{
  return (l-r)*dp;
}
void drive(double target)
{
  resetMotorEncoder(right);
	resetMotorEncoder(left);
  lerror=target;
  rerror=target;
  lPrevError=lerror;
  rPrevError=rerror;
  while(abs(lerror)>2||abs(lderivative)>1)
  {
    sleep(20);
    lerror=target-getMotorEncoder(Left);
    rerror=target-getMotorEncoder(Right);
    lderivative=lerror-lprevError;
    rderivative=rerror-rprevError;
    lprevError=lerror;
    rprevError=rerror;
    terror = angle-getGyroHeadingFloat(gyro);
		if (terror > 180){
			terror = terror - 360;
		}
		else if (terror < -180){
			terror = terror + 360;
		}
    setMotorSpeed(Left,error*kp+lderivative*kd-terror*gp);
    setMotorSpeed(Right,error*kp+rderivative*kd-terror*gp);
  }
  stopMotor(Left);
  stopMotor(Right);
}
