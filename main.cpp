/*
program to set number of students and course
then menu appear to handel them
*/
#include <iostream>
#include<conio.h>
#include<windows.h>
void display();
using namespace std;
int main()
{
    int highGradstudent;
    int entryPoint=5;
    int numberOfStudents,numberOfCourses;
    cout<<"plz enter number of students"<<endl;
    cin>>numberOfStudents;
    cout<<"plz enter number of Courses"<<endl;
    cin>>numberOfCourses;
    int StudCoursArray [numberOfStudents][numberOfCourses];
    int totalMarks[numberOfStudents];
    int avergeArray[numberOfCourses];
    int sortedArray[numberOfStudents];
    system("CLS");
    do{
        switch(entryPoint){
        case 1:
            for(int i=0;i<numberOfStudents;i++){
            cout<<"student number total "<<i+1<<"\t"<<totalMarks[i]<<endl;
            }
            cout<<"press any key to continue";
            getch();
            display();
            break;
         case 2:
                for (int i = 0; i < numberOfStudents; i++) {            //intialize sorted array by total marks array
                    sortedArray[i] = totalMarks[i];
                }
                //sort sorted array
                for (int i = 0; i<numberOfStudents ; i++)
                {
                    int temp;
                    int max = i;
                    for (int j = 0; j < numberOfStudents - 1; j++) {
                        if (sortedArray[j] < sortedArray[j + 1]) {
                            max = j;
                            temp = sortedArray[j];
                            sortedArray[max] = sortedArray[j + 1];
                            sortedArray[j + 1] = temp;
                        }
                    }

                }
                    //display sorted array
                for (int i = 0; i <numberOfStudents ; i++)
                {		//display index of student from total marksarray
                    for (int j = 0; j < numberOfStudents; j++) {
                        if (sortedArray[i] == totalMarks[j]) {
                            cout << "student number " << j + 1;
                        }
                    }

                    cout <<" total grade \t" <<sortedArray[i]<<endl;
                }
                cout << "continue >>" << endl;
                getch();
                display();
                break;
        case 3:
            for(int i=0;i<numberOfStudents;i++){
                for(int j=0;j<numberOfCourses;j++){
                    avergeArray[i]+=StudCoursArray[j][i];
                }
            avergeArray[i]/=numberOfCourses;
            }
            for(int i=0;i<numberOfCourses;i++)
                cout<<"average of course number "<<i+1<<" "<<avergeArray[i]<<endl;
                cout<<"press any key to continue";
                getch();
                display();
            break;
        case 4:
            for(int i=0;i<numberOfCourses;i++){
                for(int j=0;j<numberOfCourses;j++)
                if(StudCoursArray[i][j] >=90 && StudCoursArray[i][j] <=100)
                    cout<<"student "<<i+1 <<" course "<<j+1 <<" Grad \t"<<"A"<<endl;
               else if(StudCoursArray[i][j] >=80 && StudCoursArray[i][j] <=89)
                    cout<<"student "<<i+1 <<" course "<<j+1 <<" Grad \t"<<"B"<<endl;
               else if(StudCoursArray[i][j] >=70 && StudCoursArray[i][j] <=79)
                    cout<<"student "<<i+1 <<" course "<<j+1 <<" Grad \t"<<"C"<<endl;
                  else  if(StudCoursArray[i][j] >=60 && StudCoursArray[i][j] <=69)
                    cout<<"student "<<i +1<<" course "<<j+1 <<" Grad \t"<<"D"<<endl;
                  else  if(StudCoursArray[i][j] >=0&& StudCoursArray[i][j] <=59)
                    cout<<"student "<<i+1<<" course "<<j+1 <<" Grad \t"<<"F"<<endl;
                  else
                    cout<<"student "<<i+1<<" course "<<j+1 <<" Grad \t"<<"Not Defined"<<endl;
            }
            cout<<"press any key to continue";
            getch();
            display();
            break;
        case 5:
            for(int i=0;i<numberOfStudents;i++){ totalMarks[i]=0;}
            for(int i=0;i<numberOfCourses;i++){ avergeArray[i]=0;}
             for(int i=0;i<numberOfStudents; i++){
                 cout<<"Enter student number "<<i+1<<endl;
                for(int j=0;j<numberOfCourses;j++){
                    cout<<"course "<<j+1<<")";
                   cin>>StudCoursArray[i][j];
                    totalMarks[i]+=StudCoursArray[i][j];
             }
             cout<<"Next >>";
             getch();
             system("CLS");
             }
    display();
        break;
    default: cout<<"please Enter A valid number from menu \n";
            getch();
            display();
        }
        cin>> entryPoint;
        }
    while(entryPoint !=6);
    return 0;
}
void display(){
   system("CLS");
    cout<<"1) get total marks of students"<<endl<<"2) print students sorted based in total marks"<<endl
         <<"3) Get Average of each Subject"<<endl<<"4) get grads of students and print"<<endl
         <<"5) refile"<<endl<<"6) Exit"<<endl;
}
