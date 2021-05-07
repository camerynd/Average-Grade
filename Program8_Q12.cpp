#include<iostream>
#include<string>
using namespace std;
void get_names_and_scores(string names[], double oneScores[], double twoScores[], double threeScores[], 
double fourScores[], double fiveScores[], double totals[]);//function prototypes
void average_and_letter_grade(double totals[], double averages[], char grades[]);
void display_results(string names[], char grades[], double averages[]);
const int STRING_CHAR_SIZE = 5;//global constants for array sizes
const int DOUBLE_SIZE = 4;
int main()
{
    string studentNames[STRING_CHAR_SIZE];//array to hold 5 student names
    char letterGrades[STRING_CHAR_SIZE];//array to hold a letter grade for each student
    double studentOneScores[DOUBLE_SIZE], studentTwoScores[DOUBLE_SIZE], studentThreeScores[DOUBLE_SIZE], 
    studentFourScores[DOUBLE_SIZE], studentFiveScores[DOUBLE_SIZE], scoreTotals[STRING_CHAR_SIZE],//array for each student, holds four
    averageScores[STRING_CHAR_SIZE];                                                             //scores per array
    get_names_and_scores(studentNames, studentOneScores, studentTwoScores, studentThreeScores, 
    studentFourScores, studentFiveScores, scoreTotals);//function calls
    average_and_letter_grade(scoreTotals, averageScores, letterGrades);
    display_results(studentNames, letterGrades, averageScores);
    return 0;
}
void get_names_and_scores(string names[], double oneScores[], double twoScores[], double threeScores[], 
double fourScores[], double fiveScores[], double totals[])//function to gather user input
{
    cout << "Please enter the first name of student one: ";
    cin >> names[0];//gets name of a student and stores in names array
    cout << "Please enter " << names[0] << "'s four test scores: " << endl;
    for(int i = 0; i < DOUBLE_SIZE; i++)//loop iterates four times to get four different scores for student 
    {   cout << "SCORE #" << i + 1 << ": ";// i + 1 because array spots start with 0 and starting with 1 makes it easier for the user
        cin >> oneScores[i];               //to understand the program
        while(oneScores[i] > 100 || oneScores[i] < 0)//input validation, only accepts scpres between 0 and 100
        {   cout << "ERROR: ONLY SCORES BETWEEN 0 AND 100 ARE VALID." << endl;
            cout << "SCORE #" << i + 1 << ": ";
            cin >> oneScores[i];
        }
    totals[0] += oneScores[i];//totals up all of student's scores to be used later
    }
    cout << endl;
    cout << "Please enter the first name of student two: ";
    cin >> names[1];
    cout << "Please enter " << names[1] << "'s four test scores: " << endl;
    for(int i = 0; i < DOUBLE_SIZE; i++)
    {   cout << "SCORE #" << i + 1 << ": ";
        cin >> twoScores[i];
        while(twoScores[i] > 100 || twoScores[i] < 0)
        {   cout << "ERROR: ONLY SCORES BETWEEN 0 AND 100 ARE VALID." << endl;
            cout << "SCORE #" << i + 1 << ": ";
            cin >> twoScores[i];
        }
    totals[1] += twoScores[i];
    }
    cout << endl;
    cout << "Please enter the first name of student three: ";
    cin >> names[2];
    cout << "Please enter " << names[2] << "'s four test scores: " << endl;
    for(int i = 0; i < DOUBLE_SIZE; i++)
    {   cout << "SCORE #" << i + 1 << ": ";
        cin >> threeScores[i];
        while(threeScores[i] > 100 || threeScores[i] < 0)
        {   cout << "ERROR: ONLY SCORES BETWEEN 0 AND 100 ARE VALID." << endl;
            cout << "SCORE #" << i + 1 << ": ";
            cin >> threeScores[i];
        }
    totals[2] += threeScores[i];
    }
    cout << endl;
    cout << "Please enter the first name of student four: ";
    cin >> names[3];
    cout << "Please enter " << names[3] << "'s four test scores: " << endl;
    for(int i = 0; i < DOUBLE_SIZE; i++)
    {   cout << "SCORE #" << i + 1 << ": ";
        cin >> fourScores[i];
        while(fourScores[i] > 100 || fourScores[i] < 0)
        {   cout << "ERROR: ONLY SCORES BETWEEN 0 AND 100 ARE VALID." << endl;
            cout << "SCORE #" << i + 1 << ": ";
            cin >> fourScores[i];
        }
    totals[3] += fourScores[i];
    }
    cout << endl;
    cout << "Please enter the first name of student five: ";
    cin >> names[4];
    cout << "Please enter " << names[4] << "'s four test scores: " << endl;
    for(int i = 0; i < DOUBLE_SIZE; i++)
    {   cout << "SCORE #" << i + 1 << ": ";
        cin >> fiveScores[i];
        while(fiveScores[i] > 100 || fiveScores[i] < 0)
        {   cout << "ERROR: ONLY SCORES BETWEEN 0 AND 100 ARE VALID." << endl;
            cout << "SCORE #" << i + 1 << ": ";
            cin >> fiveScores[i];
        }
    totals[4] += fiveScores[i];
    }
    cout << endl << endl;
}
void average_and_letter_grade(double totals[], double averages[], char grades[])//function to determine letter grade and averge score
{                                                                                //for each student
    for(int i = 0; i < STRING_CHAR_SIZE; i++)//determines the average score and letter grade for each student
    {   averages[i] = totals[i] / DOUBLE_SIZE;
        if(averages[i] >= 90 && averages[i] <= 100)
        {   grades[i] = 'A';
        }
        if(averages[i] >= 80 && averages[i] <= 89)
        { grades[i] = 'B';
        }
        if(averages[i] >= 70 && averages[i] <= 79)
        { grades[i] = 'C';
        }
        if(averages[i] >= 60 && averages[i] <= 69)
        { grades[i] = 'D';
        }
        if(averages[i] <= 59)
        { grades[i] = 'F';
        }
    }
}
void display_results(string names[], char grades[], double averages[])//function to display results
{
    for(int i = 0; i < STRING_CHAR_SIZE; i++)//for loop that displays the contents of different corresponding array elements for 
    {   cout <<  "STUDENT: " << names[i] << "  |  AVERAGE SCORE: ";  //each student
        cout << averages[i] << "  |  LETTER GRADE: " << grades[i] << endl;
    }
    cout << endl;
}