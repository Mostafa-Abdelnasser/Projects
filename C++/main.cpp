#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
class StudentDataClass
{
public:
    char * code;
    string name;
    char * age;
    char * gender;
};

class StudentGradeClass
{
public:
    char * code;
    int Math;
    int Physics;
    int Drawing;
    int Computer;
    int Chemistry;
};

class StudentGradesympoleClass
{
public:
    char * code;
    char * math;
    char * physics;
    char * drawing;
    char * computer;
    char * chemistry;
};
//part1
void Part1();
//part2
void part2();
//part3
void part3();
//part4
void part4();
//part5
void part5();
void displayData(string p);
void displayGrades(string p);
void displayGradessympole(string p);
string getID();

int main()
{
    int x = 0;
    int z=0;
    Part1();
    part2();
    part3();
    part4();

    cout<<"Search for a student?    1: YES \n\t\t\t 2: NO"<<endl ;
    cin>>z;
if (z==1)
{
 do{

    string num = getID();
    cout<<endl;
    displayData(num);
    cout << endl;
    displayGrades(num);
    displayGradessympole(num);
    cout<< "Search for a new student?    1: YES \n\t\t\t     2: NO"<<endl ;
    cin>>x;

  }while(x == 1);

}

   return 0;
}


void Part1 ()
{
      // ifstream constructor opens the file, ios::in open mode as input only */
    ifstream StudentDataFile("studentsData.csv", ios::in);

    //exit program if ifstream couldn't open the file
    if( !StudentDataFile )
    {
        cerr<<"File could not be found" <<endl;
        exit(EXIT_FAILURE);
    }
    // array to line of data taken from csv file
    char StudentDataBuffer[80];
    int i = 0;
    cout<<"ID  \t\tName\t\tAge\tGender\n";
    //loop to count number of lines
    do
    {
        StudentDataFile.getline(StudentDataBuffer,80);
        i++;

    }while(!StudentDataFile.eof());
    //clear file stream to start again
    StudentDataFile.clear();
    //create number of objects based on number of lines in the file
    StudentDataClass StudentDataObj[i];
    //start from the begining of the file again
    StudentDataFile.seekg(0, ios::beg);
    //reinitialize iterator again
    i=0;

    while(!StudentDataFile.eof())
    {
        StudentDataFile.getline(StudentDataBuffer,80);
        if (StudentDataFile.eof()) break;
        //separate line into token based on ',' delimiter
        StudentDataObj[i].code = strtok(StudentDataBuffer,",");
        //continue from where it left in previous invocation
        StudentDataObj[i].name = strtok(NULL,",");
        //continue from where it left in previous invocation
        StudentDataObj[i].age = strtok(NULL,",");
        //continue from where it left in previous invocation
        StudentDataObj[i].gender = strtok(NULL,",");

        cout<<StudentDataObj[i].code<<" \t"<<StudentDataObj[i].name<<"\t"<<StudentDataObj[i].age<<"\t "<<StudentDataObj[i].gender<<"\n";

        i++;

    }


}


void part2 ()
{

     // ifstream constructor opens the file, ios::in open mode as input only */
    ifstream StudentGradeFile("studentsGrade.csv", ios::in);

    //exit program if ifstream couldn't open the file
    if( !StudentGradeFile )
    {
        cerr<<"File could not be found" <<endl;
        exit(EXIT_FAILURE);
    }
    // array to line of data taken from csv file
    char StudentGradeBuffer[80];
    int MathSum = 0;
    int PhysicsSum = 0;
    int DrawingSum = 0;
    int ChemistrySum = 0;
    int ComputerSum = 0;

    double MathMean = 0;
    double PhysicsMean = 0;
    double DrawingMean = 0;
    double ChemistryMean = 0;
    double ComputerMean = 0;

    double MathDeviation = 0;
    double PhysicsDeviation = 0;
    double DrawingDeviation = 0;
    double ChemistryDeviation = 0;
    double ComputerDeviation = 0;

    double MathNormalize = 0;
    double PhysicsNormalize = 0;
    double DrawingNormalize = 0;
    double ChemistryNormalize = 0;
    double ComputerNormalize = 0;

    int j,i = 0;

          //loop to count number of lines
    do
    {
        StudentGradeFile.getline(StudentGradeBuffer,80);
        i++;

    }while(!StudentGradeFile.eof());
    //clear file stream to start again
    StudentGradeFile.clear();
    //create number of objects based on number of lines in the file
    StudentGradeClass StudentGradeObj[i];
    //start from the begining of the file again
    StudentGradeFile.seekg(0, ios::beg);
    //reinitialize iterator again
    i=0;
    //First line will be ignored by next getline
    StudentGradeFile.getline(StudentGradeBuffer,80);
     cout<< "ID" << "\t\t"<< "Math" << "\t\t" << "Physics" << "\t\t"<< "Drawing" << "\t\t" << "Computer" << "\t" <<"Chemistry" <<endl;

    do
    {
        StudentGradeFile.getline(StudentGradeBuffer,80);
        if (StudentGradeFile.eof()) break;
        //separate line into token based on ',' delimiter
        StudentGradeObj[i].code = strtok(StudentGradeBuffer,",");
        //The atoi() function takes a character array or string literal as an argument and returns its value
        StudentGradeObj[i].Math = atoi(strtok(NULL,","));
        //continue from where it left in previous invocation
        StudentGradeObj[i].Physics = atoi(strtok(NULL,","));
        //continue from where it left in previous invocation
        StudentGradeObj[i].Drawing = atoi(strtok(NULL,","));
        //continue from where it left in previous invocation
        StudentGradeObj[i].Computer = atoi(strtok(NULL,","));
        //continue from where it left in previous invocation
        StudentGradeObj[i].Chemistry = atoi(strtok(NULL,","));
        cout<<StudentGradeObj[i].code<<"\t\t"<<StudentGradeObj[i].Math<<"\t\t"<<StudentGradeObj[i].Physics<<"\t\t"<<"  "<<StudentGradeObj[i].Drawing<<"\t\t"<<StudentGradeObj[i].Computer<<"\t\t"<<StudentGradeObj[i].Chemistry<<"\n";
        //calculate sum for each course
        MathSum += StudentGradeObj[i].Math;
        PhysicsSum += StudentGradeObj[i].Physics;
        ChemistrySum += StudentGradeObj[i].Chemistry;
        DrawingSum += StudentGradeObj[i].Drawing;
        ComputerSum += StudentGradeObj[i].Computer;

        i++;

    }while(!StudentGradeFile.eof());
    // Calculate mean for each course
     MathMean = static_cast<double>(MathSum)/i ;
     PhysicsMean = static_cast<double>(PhysicsSum)/i ;
     ChemistryMean = static_cast<double>(ChemistrySum)/i ;
     DrawingMean = static_cast<double>(DrawingSum)/i ;
     ComputerMean = static_cast<double>(ComputerSum)/i;
     cout << endl << endl;
     //calculate Deviation for each course
     for(j = 0; j < i; ++j)
     {
         MathDeviation += pow(StudentGradeObj[j].Math - MathMean, 2);
         PhysicsDeviation += pow(StudentGradeObj[j].Physics - PhysicsMean, 2);
         ChemistryDeviation += pow(StudentGradeObj[j].Chemistry - ChemistryMean, 2);
         DrawingDeviation += pow(StudentGradeObj[j].Drawing - DrawingMean, 2);
         ComputerDeviation += pow(StudentGradeObj[j].Computer - ComputerMean, 2);
     }

     MathDeviation=MathDeviation/i;
     PhysicsDeviation=PhysicsDeviation/i;
     ChemistryDeviation=ChemistryDeviation/i;
     DrawingDeviation=DrawingDeviation/i;
     ComputerDeviation=ComputerDeviation/i;

     MathDeviation = sqrt(MathDeviation);
     PhysicsDeviation = sqrt(PhysicsDeviation);
     ChemistryDeviation = sqrt(ChemistryDeviation);
     DrawingDeviation = sqrt(DrawingDeviation);
     ComputerDeviation = sqrt(ComputerDeviation);

     cout << "Math Mean ="<<MathMean<<"\n"<< "Physics Mean ="<< PhysicsMean << "\n"<< "Chemistry Mean =" << ChemistryMean <<"\n"<< "Drawing Mean =" << DrawingMean<<"\n"<< "Computer Mean =" << ComputerMean<<endl  ;
     cout << endl << endl;
     cout << "Math Deviation ="<<MathDeviation<<"\n"<< "Physics Deviation ="<< PhysicsDeviation << "\n"<< "Chemistry Deviation =" << ChemistryDeviation <<"\n"<< "Drawing Deviation =" << DrawingDeviation<<"\n"<< "Computer Deviation =" << ComputerDeviation<<endl  ;
     cout << endl << endl;

     MathNormalize = (100-MathMean)/MathDeviation;
     PhysicsNormalize = (100-PhysicsMean)/PhysicsDeviation;
     ChemistryNormalize = (100-ChemistryMean)/ChemistryDeviation;
     DrawingNormalize = (100-DrawingMean)/DrawingDeviation;
     ComputerNormalize = (100-ComputerMean)/ComputerDeviation;
     cout<< "Math Normalize =" << MathNormalize << "\n" << "Physics Normalize =" << PhysicsNormalize << "\n" << "Chemistry Normalize =" << ChemistryNormalize << "\n"<< "Drawing Normalize =" << DrawingNormalize<<"\n" << "Computer Normalize =" << ComputerNormalize<< endl;
     cout<<endl<<endl;

}

void part3 ()
{


        // ifstream constructor opens the file, ios::in open mode as input only */
    ifstream StudentGradeFile("studentsGrade.csv", ios::in);
    ofstream StudentGradeSympoleFile("studentsGradeSympole.csv");
    //exit program if ifstream couldn't open the file
    if( !StudentGradeFile )
    {
        cerr<<"File could not be found" <<endl;
        exit(EXIT_FAILURE);
    }
    // array to line of data taken from csv file
    char StudentGradeBuffer[100];
    int i = 0;



    StudentGradesympoleClass GradesymboleObj [8];
    cout<< "ID" << "\t\t"<< "Math" << "\t\t" << "Physics" << "\t\t"<< "Drawing" << "\t\t" << "Computer" << "\t" << "Chemistry" << endl ;
    //StudentGradeSympoleFile<< "ID" << ","<< "Math" << "," << "Physics" << ","<< "Drawing" << "," << "Computer" << "," << "Chemistry" << endl ;
    StudentGradeSympoleFile<<StudentGradeBuffer<<endl;
    //cout<<StudentGradeBuffer;
   do
    {
        StudentGradeFile.getline(StudentGradeBuffer,80);
        i++;

    }while(!StudentGradeFile.eof());
    //clear file stream to start again
    StudentGradeFile.clear();
    //create number of objects based on number of lines in the file
    StudentGradeClass StudentGradeObj[i];
    //start from the begining of the file again
    StudentGradeFile.seekg(0, ios::beg);
    //reinitialize iterator again
    i=0;
    //First line will be ignored by next getline
    StudentGradeFile.getline(StudentGradeBuffer,80);

    do
    {
        StudentGradeFile.getline(StudentGradeBuffer,80);
        if (StudentGradeFile.eof()) break;
        //separate line into token based on ',' delimiter
        StudentGradeObj[i].code = strtok(StudentGradeBuffer,",");
        //The atoi() function takes a character array or string literal as an argument and returns its value
        StudentGradeObj[i].Math = atoi(strtok(NULL,","));
        //continue from where it left in previous invocation
        StudentGradeObj[i].Physics = atoi(strtok(NULL,","));
        //continue from where it left in previous invocation
        StudentGradeObj[i].Drawing = atoi(strtok(NULL,","));
        //continue from where it left in previous invocation
        StudentGradeObj[i].Computer = atoi(strtok(NULL,","));
        //continue from where it left in previous invocation
        StudentGradeObj[i].Chemistry = atoi(strtok(NULL,","));//cout<<StudentGradeObj[i].code<<"\t\t"<<StudentGradeObj[i].Math<<"\t\t"<<StudentGradeObj[i].Physics<<"\t\t"<<"  "<<StudentGradeObj[i].Drawing<<"\t\t"<<StudentGradeObj[i].Computer<<"\t\t"<<StudentGradeObj[i].Chemistry<<"\n";

        cout<<StudentGradeObj[i].code;
        StudentGradeSympoleFile<<StudentGradeObj[i].code<<",";

                            /*________________________________FOR MATH______________________________________*/

         if (StudentGradeObj[i].Math>=90 )
         {
             GradesymboleObj[i].math= "A";
             cout<<"\t\t"<<GradesymboleObj[i].math;
             StudentGradeSympoleFile<<GradesymboleObj[i].math<< ",";
         }

         else if (StudentGradeObj[i].Math>85)
         {
          GradesymboleObj[i].math= "B+";
             cout<<"\t\t"<<GradesymboleObj[i].math;
             StudentGradeSympoleFile<<GradesymboleObj[i].math<<",";
         }

         else if (StudentGradeObj[i].Math>80)
         {
          GradesymboleObj[i].math= "B";
             cout<<"\t\t"<<GradesymboleObj[i].math;
             StudentGradeSympoleFile<<GradesymboleObj[i].math<<",";
         }
         else if (StudentGradeObj[i].Math >75)
         {
          GradesymboleObj[i].math= "C+";
             cout<<"\t\t"<<GradesymboleObj[i].math;
             StudentGradeSympoleFile<<GradesymboleObj[i].math<<",";
         }
         else if (StudentGradeObj[i].Math>70)
         {
          GradesymboleObj[i].math= "C";
             cout<<"\t\t"<<GradesymboleObj[i].math;
             StudentGradeSympoleFile<<GradesymboleObj[i].math<<",";
         }
         else if ( StudentGradeObj[i].Math >65)
         {
          GradesymboleObj[i].math= "D+";
             cout<<"\t\t"<<GradesymboleObj[i].math;
             StudentGradeSympoleFile<<GradesymboleObj[i].math<<",";
         }
         else if ( StudentGradeObj[i].Math >60)
         {
          GradesymboleObj[i].math= "D";
             cout<<"\t\t"<<GradesymboleObj[i].math;
             StudentGradeSympoleFile<<GradesymboleObj[i].math<<",";
         }
          else if (60>=StudentGradeObj[i].Math)
         {
          GradesymboleObj[i].math= "F";
             cout<<"\t\t"<<GradesymboleObj[i].math;
             StudentGradeSympoleFile<<GradesymboleObj[i].math<<",";
         }
                 /*________________________________FOR PHYSICS______________________________________*/

          if (StudentGradeObj[i].Physics>=90 )
         {
             GradesymboleObj[i].physics= "A";
             cout<<"\t\t"<<GradesymboleObj[i].physics;
             StudentGradeSympoleFile<<GradesymboleObj[i].physics<<",";
         }
          else if (StudentGradeObj[i].Physics> 85 )
         {
             GradesymboleObj[i].physics= "B+";
             cout<<"\t\t"<<GradesymboleObj[i].physics;
             StudentGradeSympoleFile<<GradesymboleObj[i].physics<<",";
         }
         else if (StudentGradeObj[i].Physics> 80 )
         {
             GradesymboleObj[i].physics= "B";
             cout<<"\t\t"<<GradesymboleObj[i].physics;
             StudentGradeSympoleFile<<GradesymboleObj[i].physics<<",";
         }
         else if (StudentGradeObj[i].Physics> 75 )
         {
             GradesymboleObj[i].physics= "C+";
             cout<<"\t\t"<<GradesymboleObj[i].physics;
             StudentGradeSympoleFile<<GradesymboleObj[i].physics<<",";
         }
         else if (StudentGradeObj[i].Physics> 70 )
         {
             GradesymboleObj[i].physics= "C";
             cout<<"\t\t"<<GradesymboleObj[i].physics;
             StudentGradeSympoleFile<<GradesymboleObj[i].physics<<",";
         }
         else if (StudentGradeObj[i].Physics> 65 )
         {
             GradesymboleObj[i].physics= "D+";
             cout<<"\t\t"<<GradesymboleObj[i].physics;
             StudentGradeSympoleFile<<GradesymboleObj[i].physics<<",";
         }
         else if (StudentGradeObj[i].Physics> 60 )
         {
             GradesymboleObj[i].physics= "D";
             cout<<"\t\t"<<GradesymboleObj[i].physics;
             StudentGradeSympoleFile<<GradesymboleObj[i].physics<<",";
         }
         else if (StudentGradeObj[i].Physics<60 )
         {
             GradesymboleObj[i].physics= "F";
             cout<<"\t\t"<<GradesymboleObj[i].physics;
             StudentGradeSympoleFile<<GradesymboleObj[i].physics<<",";
         }
                          /*________________________________FOR DRAWING______________________________________*/

         if (StudentGradeObj[i].Drawing>=90 )
         {
             GradesymboleObj[i].drawing= "A";
             cout<<"\t\t"<<GradesymboleObj[i].drawing;
             StudentGradeSympoleFile<<GradesymboleObj[i].drawing<<",";
         }
          else if (StudentGradeObj[i].Drawing> 85 )
         {
             GradesymboleObj[i].drawing= "B+";
             cout<<"\t\t"<<GradesymboleObj[i].drawing;
             StudentGradeSympoleFile<<GradesymboleObj[i].drawing<<",";
         }
         else if (StudentGradeObj[i].Drawing> 80 )
         {
             GradesymboleObj[i].drawing= "B";
             cout<<"\t\t"<<GradesymboleObj[i].drawing;
             StudentGradeSympoleFile<<GradesymboleObj[i].drawing<<",";
         }
         else if (StudentGradeObj[i].Drawing> 75 )
         {
             GradesymboleObj[i].drawing= "C+";
             cout<<"\t\t"<<GradesymboleObj[i].drawing;
             StudentGradeSympoleFile<<GradesymboleObj[i].drawing<<",";
         }
         else if (StudentGradeObj[i].Drawing> 70 )
         {
             GradesymboleObj[i].drawing= "C";
             cout<<"\t\t"<<GradesymboleObj[i].drawing;
             StudentGradeSympoleFile<<GradesymboleObj[i].drawing<<",";
         }
         else if (StudentGradeObj[i].Drawing> 65 )
         {
             GradesymboleObj[i].drawing= "D+";
             cout<<"\t\t"<<GradesymboleObj[i].drawing;
             StudentGradeSympoleFile<<GradesymboleObj[i].drawing<<",";
         }
         else if (StudentGradeObj[i].Drawing> 60 )
         {
             GradesymboleObj[i].drawing= "D";
             cout<<"\t\t"<<GradesymboleObj[i].drawing;
             StudentGradeSympoleFile<<GradesymboleObj[i].drawing<<",";
         }
         else if (StudentGradeObj[i].Drawing<60 )
         {
             GradesymboleObj[i].drawing= "F";
             cout<<"\t\t"<<GradesymboleObj[i].drawing;
             StudentGradeSympoleFile<<GradesymboleObj[i].drawing<<",";
                      }
                                   /*________________________________FOR COMPUTER______________________________________*/

         if (StudentGradeObj[i].Computer>90 )
         {
             GradesymboleObj[i].computer= "A";
             cout<<"\t\t"<<GradesymboleObj[i].computer;
             StudentGradeSympoleFile<<GradesymboleObj[i].computer<<",";

         }
         else if (StudentGradeObj[i].Computer>85 )
         {
             GradesymboleObj[i].computer= "B+";
             cout<<"\t\t"<<GradesymboleObj[i].computer;
             StudentGradeSympoleFile<<GradesymboleObj[i].computer<<",";

         }
         else if (StudentGradeObj[i].Computer>80 )
         {
             GradesymboleObj[i].computer= "B";
             cout<<"\t\t"<<GradesymboleObj[i].computer;
             StudentGradeSympoleFile<<GradesymboleObj[i].computer<<",";

         }
         else if (StudentGradeObj[i].Computer>75 )
         {
             GradesymboleObj[i].computer= "C+";
             cout<<"\t\t"<<GradesymboleObj[i].computer;
             StudentGradeSympoleFile<<GradesymboleObj[i].computer<<",";

         }
         else if (StudentGradeObj[i].Computer>70 )
         {
             GradesymboleObj[i].computer= "C";
             cout<<"\t\t"<<GradesymboleObj[i].computer;
             StudentGradeSympoleFile<<GradesymboleObj[i].computer<<",";

         }
         else if (StudentGradeObj[i].Computer>65 )
         {
             GradesymboleObj[i].computer= "D+";
             cout<<"\t\t"<<GradesymboleObj[i].computer;
             StudentGradeSympoleFile<<GradesymboleObj[i].computer<<",";

         }
         else if (StudentGradeObj[i].Computer>60 )
         {
             GradesymboleObj[i].computer= "D";
             cout<<"\t\t"<<GradesymboleObj[i].computer;
             StudentGradeSympoleFile<<GradesymboleObj[i].computer<<",";

         }
         else if (StudentGradeObj[i].Computer<60)
         {
             GradesymboleObj[i].computer= "F";
             cout<<"\t\t"<<GradesymboleObj[i].computer;
             StudentGradeSympoleFile<<GradesymboleObj[i].computer<<",";

         }
                                   /*________________________________FOR CHEMISTRY______________________________________*/

         if (StudentGradeObj[i].Chemistry>90 )
         {
             GradesymboleObj[i].chemistry= "A";
             cout<<"\t\t"<<GradesymboleObj[i].chemistry;
             StudentGradeSympoleFile<<GradesymboleObj[i].chemistry<<",";

         }
         else if (StudentGradeObj[i].Chemistry>85 )
         {
             GradesymboleObj[i].chemistry= "B+";
             cout<<"\t\t"<<GradesymboleObj[i].chemistry;
             StudentGradeSympoleFile<<GradesymboleObj[i].chemistry<<",";

         }
          else if (StudentGradeObj[i].Chemistry>80 )
         {
             GradesymboleObj[i].chemistry= "B";
             cout<<"\t\t"<<GradesymboleObj[i].chemistry;
             StudentGradeSympoleFile<<GradesymboleObj[i].chemistry<<",";

         }
          else if (StudentGradeObj[i].Chemistry>75 )
         {
             GradesymboleObj[i].chemistry= "C+";
             cout<<"\t\t"<<GradesymboleObj[i].chemistry;
             StudentGradeSympoleFile<<GradesymboleObj[i].chemistry<<",";

         }
          else if (StudentGradeObj[i].Chemistry>75 )
         {
             GradesymboleObj[i].chemistry= "C";
             cout<<"\t\t"<<GradesymboleObj[i].chemistry;
             StudentGradeSympoleFile<<GradesymboleObj[i].chemistry<<",";

         }
          else if (StudentGradeObj[i].Chemistry>70 )
         {
             GradesymboleObj[i].chemistry= "D+";
             cout<<"\t\t"<<GradesymboleObj[i].chemistry;
             StudentGradeSympoleFile<<GradesymboleObj[i].chemistry<<",";

         }
          else if (StudentGradeObj[i].Chemistry>65 )
         {
             GradesymboleObj[i].chemistry= "D";
             cout<<"\t\t"<<GradesymboleObj[i].chemistry;
             StudentGradeSympoleFile<<GradesymboleObj[i].chemistry<<",";

         }
          else if (StudentGradeObj[i].Chemistry>60 )
         {
             GradesymboleObj[i].chemistry= "D";
             cout<<"\t\t"<<GradesymboleObj[i].chemistry;
             StudentGradeSympoleFile<<GradesymboleObj[i].chemistry<<",";

         }
          else if (StudentGradeObj[i].Chemistry<60 )
         {
             GradesymboleObj[i].chemistry= "F";
             cout<<"\t\t"<<GradesymboleObj[i].chemistry;
             StudentGradeSympoleFile<<GradesymboleObj[i].chemistry<<",";

         }
         cout<<endl;
         StudentGradeSympoleFile<<endl;
        i++;
    }while( !StudentGradeFile.eof());

}


// percentage of each grade
void part4()
{

     //open the file
  ifstream ip;
  ip.open("studentsGradeSympole.csv");

  if(!ip.is_open()){
    cout << "ERROR: File Open" << "\n";
    exit(1);

           }


 // variables for string
  string code;
  string math;
  string physics;
  string drawing;
  string computer;
  string chemistry;



  // counter
  int i = 1 ;



// skip the first row
  while(ip.good() && i == 1 ){

    getline(ip,code,',');
    getline(ip,math,',');
    getline(ip,physics,',');
    getline(ip,drawing,',');
    getline(ip,computer,',');
    getline(ip,chemistry,'\n');



    i++;

  }

  // variables for strings
  string math1 ="a" ;
  string physics1="c";
  string drawing1="h" ;
  string computer1="u" ;
  string chemistry1="y";
  //variables for the counters
  float a = 0 , b = 0 ,c =0 ,d =0 ,f =0 ,b_plus =0 ,c_plus =0,d_plus =0,z =0 ;
  float a1 = 0 , b1 = 0 ,c1 =0 ,d1 =0 ,f1 =0,b_plus1 =0 ,c_plus1 =0,d_plus1 =0  ;
  float a2 = 0 , b2 = 0 ,c2 =0 ,d2 =0 ,f2 =0,b_plus2 =0 ,c_plus2 =0,d_plus2 =0  ;
  float a3 = 0 , b3 = 0 ,c3 =0 ,d3 =0 ,f3 =0,b_plus3 =0 ,c_plus3 =0,d_plus3 =0  ;
  float a4 = 0 , b4 = 0 ,c4 =0 ,d4 =0 ,f4 =0,b_plus4 =0 ,c_plus4 =0,d_plus4 =0  ;


//cout <<"code\t"<<"math\t"<<"physics\t"<<"drawing\t"<<"computer "<<"chemistry"<<"\n";


  while(ip.good()&& i>1){


    //each element stored in varaible



    getline(ip,code,',');
    getline(ip,math,',');
    getline(ip,physics,',');
    getline(ip,drawing,',');
    getline(ip,computer,',');
    getline(ip,chemistry,'\n');

    //cout<<chemistry<<endl;



    if( math1 == math && physics1 == physics && drawing1 == drawing && computer1 == computer && chemistry1 == chemistry  ){

        break;

    }

   // assignment of each element in other variable to apply the previous conditions
    math1 = math;
    physics1 = physics;
    drawing1 = drawing ;
    computer1 = computer;
    chemistry1 = chemistry ;



    /* printing the every element
    cout<<code<< '\t';
    cout<<" " <<math<< '\t';
    cout<<"  "<<physics << '\t';
    cout<<"  "<<drawing << '\t';
    cout<<"   "<<computer << '\t';
    cout<<"    "<<chemistry << '\n';*/


 //math %


    if(math =="A")
        a++;
    else if(math =="B+")
        b_plus++;
    else if(math =="B")
        b++;
     else if(math=="C+" )
        c_plus++;
    else if(math =="C")
        c++;
     else if( math=="D+")
        d_plus++;
    else if(math =="D")
        d++;
    else
        f++;


 //physics %


    if(physics =="A")
        a1++;
    else if(physics =="B+")
        b_plus1++;
    else if(physics =="B")
        b1++;
     else if(physics=="C+" )
        c_plus1++;
    else if(physics =="C")
        c1++;
     else if( physics=="D+")
        d_plus1++;
    else if(physics =="D")
        d1++;
    else
        f1++;



//drawing %


    if(drawing =="A")
        a2++;
    else if(drawing =="B+")
        b_plus2++;
    else if(drawing =="B")
        b2++;
     else if(drawing=="C+" )
        c_plus2++;
    else if(drawing =="C")
        c2++;
     else if( drawing=="D+")
        d_plus2++;
    else if(drawing =="D")
        d2++;
    else
        f2++;





//computer %



    if(computer =="A")
        a3++;
    else if(computer =="B+")
        b_plus3++;
    else if(computer =="B")
        b3++;
     else if(computer=="C+" )
        c_plus3++;
    else if(computer =="C")
        c3++;
     else if( computer=="D+")
        d_plus3++;
    else if(computer =="D")
        d3++;
    else
        f3++;





//chemistry %



    if(chemistry =="A,")
        a4++;
    else if(chemistry =="B+,")
        b_plus4++;
    else if(chemistry =="B,")
        b4++;
     else if(chemistry=="C+," )
        c_plus4++;
    else if(chemistry =="C,")
        c4++;
     else if( chemistry=="D+,")
        d_plus4++;
    else if(chemistry =="D")
        d4++;
    else
        f4++;


    //population number
    z++;
    //counter
    i++;

  }





  //cout<<"\n";

    cout<<"\n\n ##Students percentages in each course:\n\n"  ;





cout<<"MATH % : \n\t"<<(a/z)*100<<"% of student got"<< "A\t\n\t"<<(b_plus/z)*100<<"% of student got"<<" B+\t\n\t"<<(b/z)*100<<"% of student got"<<" B\t\n\t"<<(c_plus/z)*100<<"% of student got"<<" C+\t\n\t"<<(c/z)*100<<"% of student got"<<" C\t\n\t"<<(d_plus/z)*100<<"% of student got"<<" D+\t\n\t"<<(d/z)*100<<"% of student got"<<" D\t\n\t"<<(f/z)*100<<"% of student got"<<" F\t\n\n";

cout<<"PHYSICS % : \n\t"<<(a1/z)*100<<"% of student got"<<" A\t\n\t"<<(b_plus1/z)*100<<"% of student got"<<" B+\t\n\t"<<(b1/z)*100<<"% of student got"<<" B\t\n\t"<<(c_plus1/z)*100<<"% of student got"<<" C+\t\n\t"<<(c1/z)*100<<"% of student got"<<" C\t\n\t"<<(d_plus1/z)*100<<"% of student got"<<" D+\t\n\t"<<(d1/z)*100<<"% of student got"<<" D\t\n\t"<<(f1/z)*100<<"% of student got"<<" F\t\n\n";

cout<<"DRAWING % : \n\t"<<(a2/z)*100<<"% of student got"<<" A\t\n\t"<<(b_plus2/z)*100<<"% of student got"<<" B+\t\n\t"<<(b2/z)*100<<"% of student got"<<" B\t\n\t"<<(c_plus2/z)*100<<"% of student got"<<" C+\t\n\t"<<(c2/z)*100<<"% of student got"<<" C\t\n\t"<<(d_plus2/z)*100<<"% of student got"<<" D+\t\n\t"<<(d2/z)*100<<"% of student got"<<" D\t\n\t"<<(f2/z)*100<<"% of student got"<<" F\t\n\n";

cout<<"COMPUTER % : \n\t"<<(a3/z)*100<<"% of student got"<<" A\t\n\t"<<(b_plus3/z)*100<<"% of student got"<<" B+\t\n\t"<<(b3/z)*100<<"% of student got"<<" B\t\n\t"<<(c_plus3/z)*100<<"% of student got"<<" C+\t\n\t"<<(c3/z)*100<<"% of student got C\t\n\t"<<(d_plus3/z)*100<<"% of student got D+\t\n\t"<<(d3/z)*100<<"% of student got D\t\n\t"<<(f3/z)*100<<"% of student got F\t\n\n";

cout<<"CHEMISTRY % : \n\t"<<(a4/z)*100<<"% of student got A\t\n\t"<<(b_plus4/z)*100<<"% of student got B+\t\n\t"<<(b4/z)*100<<"% of student got B\t\n\t"<<(c_plus4/z)*100<<"% of student got C+\t\n\t"<<(c4/z)*100<<"% of student got C\t\n\t"<<(d_plus4/z)*100<<"% of student got D+\t\n\t"<<(d4/z)*100<<"% of student got D\t\n\t"<<(f4/z)*100<<"% of student got F\t\n\n";

   ip.close();

}




//part5

//function to get the student's ID
string getID(){
    cout << "Please enter a student's ID\n";
    string id;
    cin >> id;
    return id;
}

//function which displays the student's Data
void displayData(string p) {

    ifstream myFile("studentsData.csv");
    string c, n, a, g, nxt; //c for code, n for name, a for age, g for gender
    //skipping the first row
    getline(myFile, nxt, ','); //reads the student's code which is then used in the if statements.
    if (p == nxt) {

    getline(myFile, n, ',');
    getline(myFile, a, ',');
    getline(myFile, g, '\n');
    cout <<"Name\t\t\tAge\t\tGender\n"<< n << "\t\t" << a << "\t\t" << g << endl;
    }
    else{
        getline(myFile, nxt, '\n'); //its purpose is to indent a line in the file being read
        getline(myFile, nxt, ','); //reads the student's code on the new line
    if (p == nxt) {
        getline(myFile, n, ',');
        getline(myFile, a, ',');
        getline(myFile, g, '\n');
        cout <<"Name\t\t\tAge\t\tGender\n"<< n << "\t\t" << a << "\t\t" << g << endl;
}
    else {
        getline(myFile, nxt, '\n'); //its purpose is to indent a line in the file being read
        getline(myFile, nxt, ','); //reads the student's code on the new line
        if (p == nxt) {
            getline(myFile, n, ',');
            getline(myFile, a, ',');
            getline(myFile, g, '\n');
    cout <<"Name\t\t\tAge\t\tGender\n"<< n << "\t\t" << a << "\t\t" << g << endl;
        }
        else {
            getline(myFile, nxt, '\n'); //indents a line in the file
            getline(myFile, nxt, ','); //reads the code on the new line [line #3 in which case]
            if (p == nxt) {
                getline(myFile, n, ',');
                getline(myFile, a, ',');
                getline(myFile, g, '\n');
    cout <<"Name\t\t\tAge\t\tGender\n"<< n << "\t\t" << a << "\t\t" << g << endl;
            }
            else {
                getline(myFile, nxt, '\n');
                getline(myFile, nxt, ','); //[line #4 in which case]
                if (p == nxt) {
                    getline(myFile, n, ',');
                    getline(myFile, a, ',');
                    getline(myFile, g, '\n');
    cout <<"Name\t\t\tAge\t\tGender\n"<< n << "\t\t" << a << "\t\t" << g << endl;
                }
                else {
                    getline(myFile, nxt, '\n');
                    getline(myFile, nxt, ','); //[line #5 in which case]
                    if (p == nxt) {
                        getline(myFile, n, ',');
                        getline(myFile, a, ',');
                        getline(myFile, g, '\n');
    cout <<"Name\t\t\tAge\t\tGender\n"<< n << "\t\t" << a << "\t\t" << g << endl;
                    }
                    else {
                        getline(myFile, nxt, '\n');
                        getline(myFile, nxt, ','); //[line #6 in which case]
                        if (p == nxt) {
                            getline(myFile, n, ',');
                            getline(myFile, a, ',');
                            getline(myFile, g, '\n');
    cout <<"Name\t\t\tAge\t\tGender\n"<< n << "\t\t" << a << "\t\t" << g << endl;
                        }
                        else {
                            getline(myFile, nxt, '\n');
                            getline(myFile, nxt, ','); //[line #7 in which case]
                            if (p == nxt) {
                                getline(myFile, n, ',');
                                getline(myFile, a, ',');
                                getline(myFile, g, '\n');
    cout <<"Name\t\t\tAge\t\tGender\n"<< n << "\t\t" << a << "\t\t" << g << endl;
                            }
                            else {
                                getline(myFile, nxt, '\n');
                                getline(myFile, nxt, ','); //[line #8 in which case]
                                if (p == nxt) {
                                    getline(myFile, n, ',');
                                    getline(myFile, a, ',');
                                    getline(myFile, g, '\n');
    cout <<"Name\t\t\tAge\t\tGender\n"<< n << "\t\t" << a << "\t\t" << g << endl;
                                }
                                else {
                                    getline(myFile, nxt, '\n');
                                    getline(myFile, nxt, ','); //[line #9 and the last]
                                    if (p == nxt) {
                                        getline(myFile, n, ',');
                                        getline(myFile, a, ',');
                                        getline(myFile, g, '\n');
    cout <<"Name\t\t\tAge\t\tGender\n"<< n << "\t\t" << a << "\t\t" << g << endl;
                                    }
                                    /*else{
                                        while(p!=nxt){
                                            cout << "Wrong ID.\n";
                                            getID();
                                           }*/
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

void displayGrades(string p) {
    ifstream myFile("studentsGrade.csv");
    string code, math, physics, drawing, computer, chemistry, nxt;
    //skipping the first row
    getline(myFile, code, ',');
    getline(myFile, math, ',');
    getline(myFile, physics, ',');
    getline(myFile, drawing, ',');
    getline(myFile, computer, ',');
    getline(myFile, chemistry, '\n');
    getline(myFile, nxt, ',');   //reads the student's code which is then used in the if statements.
    cout << math << "\t\t" << physics << "\t" << drawing << "\t\t" << computer << "\t" << chemistry << endl;

    if (p == nxt) {
        getline(myFile, math, ',');
        getline(myFile, physics, ',');
        getline(myFile, drawing, ',');
        getline(myFile, computer, ',');
        getline(myFile, chemistry, '\n');
        cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t" << chemistry << endl;
    } else {
        getline(myFile, nxt, '\n'); //its purpose is to indent a line in the file being read
        getline(myFile, nxt, ','); //reads the student's code on the new line
        if (p == nxt) {
            getline(myFile, math, ',');
            getline(myFile, physics, ',');
            getline(myFile, drawing, ',');
            getline(myFile, computer, ',');
            getline(myFile, chemistry, '\n');
            cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t" << chemistry << endl;
        } else {
            getline(myFile, nxt, '\n'); //indents a line in the file
            getline(myFile, nxt, ','); //reads the code on the new line [line #3 in which case]
            if (p == nxt) {
                getline(myFile, math, ',');
                getline(myFile, physics, ',');
                getline(myFile, drawing, ',');
                getline(myFile, computer, ',');
                getline(myFile, chemistry, '\n');
                cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t" << chemistry
                     << endl;
            } else {
                getline(myFile, nxt, '\n');
                getline(myFile, nxt, ','); //[line #4 in which case]
                if (p == nxt) {
                    getline(myFile, math, ',');
                    getline(myFile, physics, ',');
                    getline(myFile, drawing, ',');
                    getline(myFile, computer, ',');
                    getline(myFile, chemistry, '\n');
                    cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t" << chemistry
                         << endl;
                } else {
                    getline(myFile, nxt, '\n');
                    getline(myFile, nxt, ','); //[line #5 in which case]
                    if (p == nxt) {
                        getline(myFile, math, ',');
                        getline(myFile, physics, ',');
                        getline(myFile, drawing, ',');
                        getline(myFile, computer, ',');
                        getline(myFile, chemistry, '\n');
                        cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t"
                             << chemistry << endl;
                    } else {
                        getline(myFile, nxt, '\n');
                        getline(myFile, nxt, ','); //[line #6 in which case]
                        if (p == nxt) {
                            getline(myFile, math, ',');
                            getline(myFile, physics, ',');
                            getline(myFile, drawing, ',');
                            getline(myFile, computer, ',');
                            getline(myFile, chemistry, '\n');
                            cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t"
                                 << chemistry << endl;
                        } else {
                            getline(myFile, nxt, '\n');
                            getline(myFile, nxt, ','); //[line #7 in which case]
                            if (p == nxt) {
                                getline(myFile, math, ',');
                                getline(myFile, physics, ',');
                                getline(myFile, drawing, ',');
                                getline(myFile, computer, ',');
                                getline(myFile, chemistry, '\n');
                                cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t"
                                     << chemistry << endl;
                            } else {
                                getline(myFile, nxt, '\n');
                                getline(myFile, nxt, ','); //[line #8 in which case]
                                if (p == nxt) {
                                    getline(myFile, math, ',');
                                    getline(myFile, physics, ',');
                                    getline(myFile, drawing, ',');
                                    getline(myFile, computer, ',');
                                    getline(myFile, chemistry, '\n');
                                    cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer
                                         << "\t\t" << chemistry << endl;
                                } else {
                                    getline(myFile, nxt, '\n');
                                    getline(myFile, nxt, ','); //[line #9 in which case]
                                    if (p == nxt) {
                                        getline(myFile, math, ',');
                                        getline(myFile, physics, ',');
                                        getline(myFile, drawing, ',');
                                        getline(myFile, computer, ',');
                                        getline(myFile, chemistry, '\n');
                                        cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer
                                             << "\t\t" << chemistry << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void displayGradessympole(string p) {
    ifstream myFile("studentsGradeSympole.csv");
   string code, math, physics, drawing, computer, chemistry, nxt;
    //skipping the first row
    getline(myFile, code, ',');
    getline(myFile, math, ',');
    getline(myFile, physics, ',');
    getline(myFile, drawing, ',');
    getline(myFile, computer, ',');
    getline(myFile, chemistry, '\n');
    getline(myFile, nxt, ',');   //reads the student's code which is then used in the if statements.
    //cout << math << "\t\t" << physics << "\t" << drawing << "\t\t" << computer << "\t" << chemistry << endl;

    if (p == nxt) {
        getline(myFile, math, ',');
        getline(myFile, physics, ',');
        getline(myFile, drawing, ',');
        getline(myFile, computer, ',');
        getline(myFile, chemistry, '\n');
        cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t" << chemistry << endl;
    } else {
        getline(myFile, nxt, '\n'); //its purpose is to indent a line in the file being read
        getline(myFile, nxt, ','); //reads the student's code on the new line
        if (p == nxt) {
            getline(myFile, math, ',');
            getline(myFile, physics, ',');
            getline(myFile, drawing, ',');
            getline(myFile, computer, ',');
            getline(myFile, chemistry, '\n');
            cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t" << chemistry << endl;
        } else {
            getline(myFile, nxt, '\n'); //indents a line in the file
            getline(myFile, nxt, ','); //reads the code on the new line [line #3 in which case]
            if (p == nxt) {
                getline(myFile, math, ',');
                getline(myFile, physics, ',');
                getline(myFile, drawing, ',');
                getline(myFile, computer, ',');
                getline(myFile, chemistry, '\n');
                cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t" << chemistry
                     << endl;
            } else {
                getline(myFile, nxt, '\n');
                getline(myFile, nxt, ','); //[line #4 in which case]
                if (p == nxt) {
                    getline(myFile, math, ',');
                    getline(myFile, physics, ',');
                    getline(myFile, drawing, ',');
                    getline(myFile, computer, ',');
                    getline(myFile, chemistry, '\n');
                    cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t" << chemistry
                         << endl;
                } else {
                    getline(myFile, nxt, '\n');
                    getline(myFile, nxt, ','); //[line #5 in which case]
                    if (p == nxt) {
                        getline(myFile, math, ',');
                        getline(myFile, physics, ',');
                        getline(myFile, drawing, ',');
                        getline(myFile, computer, ',');
                        getline(myFile, chemistry, '\n');
                        cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t"
                             << chemistry << endl;
                    } else {
                        getline(myFile, nxt, '\n');
                        getline(myFile, nxt, ','); //[line #6 in which case]
                        if (p == nxt) {
                            getline(myFile, math, ',');
                            getline(myFile, physics, ',');
                            getline(myFile, drawing, ',');
                            getline(myFile, computer, ',');
                            getline(myFile, chemistry, '\n');
                            cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t"
                                 << chemistry << endl;
                        } else {
                            getline(myFile, nxt, '\n');
                            getline(myFile, nxt, ','); //[line #7 in which case]
                            if (p == nxt) {
                                getline(myFile, math, ',');
                                getline(myFile, physics, ',');
                                getline(myFile, drawing, ',');
                                getline(myFile, computer, ',');
                                getline(myFile, chemistry, '\n');
                                cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer << "\t\t"
                                     << chemistry << endl;
                            } else {
                                getline(myFile, nxt, '\n');
                                getline(myFile, nxt, ','); //[line #8 in which case]
                                if (p == nxt) {
                                    getline(myFile, math, ',');
                                    getline(myFile, physics, ',');
                                    getline(myFile, drawing, ',');
                                    getline(myFile, computer, ',');
                                    getline(myFile, chemistry, '\n');
                                    cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer
                                         << "\t\t" << chemistry << endl;
                                } else {
                                    getline(myFile, nxt, '\n');
                                    getline(myFile, nxt, ','); //[line #9 in which case]
                                    if (p == nxt) {
                                        getline(myFile, math, ',');
                                        getline(myFile, physics, ',');
                                        getline(myFile, drawing, ',');
                                        getline(myFile, computer, ',');
                                        getline(myFile, chemistry, '\n');
                                        cout << math << "\t\t" << physics << "\t\t" << drawing << "\t\t" << computer
                                             << "\t\t" << chemistry << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
