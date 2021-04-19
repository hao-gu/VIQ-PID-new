double kp;
double kd;
//integral not useful

//Universal variables
double lerror;
double rerror;
double terror;

double lPrevError;
double rPrevError;

double lproportional;
double rporportional;
double lderivative;
double rderivative;

void drive(double target)
{
  lerror=target;
  rerror=target;
  lPrevError=lerror;
  rPrevError=rerror;
  
  while(abs(lerror)>2||abs(lderivative)>1)
  {
    sleep(20);
    lerror=target-getMotorEncoder(Left);
    rerror=target-getMotorEncoder(Right);
    
    
    
  }
  
}
