//include required libraries
#include<PID_v1.h>
#include<Servo.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

//define our variables
//our servo will begin from 90 degrees 

// imu related 

double Setpoint ; // will be 0 value of desired position of imu
double Input ; // imu readings
double Output ; //servo angle
int ServoOutput, val1;
float mpu_z;

//PID parameters 
double Kp =1.2995 , Ki =0.01  , Kd =0.1151  ;

// create PID instance
PID myPID(&Input , &Output , &Setpoint , Kp ,Ki , Kd , DIRECT);

//Intialize servo object 
Servo s1 ;

//intialize imu
MPU6050 mpu6050(Wire);

//prototype of function 
int imu_reading();

//motor related

//define our pins
#define in3 7
#define in4 8
#define enb 6

//encoder related

// diameter of wheel 2.9cm covered distance per revolution = pi*D =9.106
//12 pulses per revolution

//define our variables & pins

#define enc 4
float distance = 0;
int counter =0 ,current_state=0 ,previous_state=0 ;
//function prototype
int encoder();



void setup() 
{

  Serial.begin(9600);

  //servo related
  
  s1.attach(3);
  s1.write(90);
  delay(1000);

  //PID related
  
  //define the setpoint 
  Setpoint = 0 ;
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  //set the output limits (-60,60)
  myPID.SetOutputLimits(0,180);
  //adjust PID values 
  myPID.SetTunings(Kp,Ki,Kd); 

  //imu related 
  
  Wire.begin();
  mpu6050.begin();
  //calibration 
  mpu6050.setGyroOffsets(-1.90,0.13,-4.41);
  mpu6050.update();
  //get the angle around z
  mpu_z = mpu6050.getAngleZ();

  //motor related
  
  //define inputs & outputs
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enb,OUTPUT);
  //define motor direction
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

  //encoder related
  
   pinMode (encoder,INPUT);



}

void loop() 
{
 // calculating angle around z
 imu_reading();

//read the value of imu and maping it to servo angles
Input = val1 ;

//PID calculation 
myPID.Compute();

//write the output as calculated by pid function
s1.write(ceil(Output));

//get distance
encoder();

//assign speed
analogWrite(enb,130);






/*
//send data for observation 
Serial.print(Input);
Serial.print("  ");
Serial.print(Output);
Serial.print("  ");
Serial.print(Setpoint);
Serial.print("  ");
Serial.println(val1);
//delay(1000);
*/

}

//imu reading function 
int imu_reading()
{
   mpu6050.update();

 int val = (mpu_z-mpu6050.getAngleZ())-3;

 if (val > 0)
 {
  val=val+6;
  
  }

 val1= -val;

 return val1;
  
  
  }



//encoder function

  int encoder()
{
  /*  
//print outputs for observation
  Serial.print(counter);
  Serial.print("  ");
  Serial.print(distance);
  Serial.print("  ");
  Serial.println(digitalRead(enc));
  */

// next bunch of lines determine the positive edge and negative edge 
  current_state= digitalRead(enc) ;

  if(current_state!=previous_state)
  {
    
    if(current_state==HIGH)
    {
    //Serial.println("rising edge detected");
    counter++;
    }

    /*
   if(current_state==LOW)
   {
   //Serial.println("falling edge detected");
   }
   */
   previous_state=current_state;
    
    }



// after one rotation make counter = 0 again & add 9.106 to total distance
  if (counter==12 ) 
  {
    counter = 0 ;

    distance  = distance + 9.106 ;
 
    }

//stop codition
     if (310<distance&&distance<330) // 3 meter coverd  
  {
    //stoping motor
    analogWrite(enb,0);
    delay(100000);
 
   }

  
  }
