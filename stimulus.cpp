// Project 2
// COVID  Stimulus Check Calculator

#include <iostream>
#include <string>
using namespace std;


int main ( )
{
    
    // initializing variables
    
    int StimCheck = 0;
    string FilingStatus;
    int Income = 0;
    int NumberOfChildren = 0;
    int StimDeductionSingle = 0;
    int StimDeductionMarried = 0;
    int StimDeductionHoH = 0;
    int ChildMoney = 0;
    
    // Calling Questions
    
    cout << "What is your filing status? ";
    getline (cin, FilingStatus);
    
    // error message for filing status
    if (FilingStatus != "Single" && FilingStatus != "Married" && FilingStatus != "Head of Household")
    {
        cout << "Error - Invalid filing status." << endl;
        return 0;
    }
  
    cout << "What is you adjusted gross income? ";
    cin >> Income;
    
    
    //error message for Income
    if (Income < 0)
    {
        cout << "Error - Invalid income." << endl;
        return 0;
    }
    
    cout << "How many children under the age of 17 did you claim as a dependent? ";
    cin >> NumberOfChildren;
    
    //error message for Number of Children
    if (NumberOfChildren < 0)
    {
        cout << "Error - Invalid number of dependents." << endl;
        return 0;
    }
    
    // Determining StimCheck
    
    
    // Additional money from each child
    ChildMoney = 500 * NumberOfChildren;
    
    
    // if single and income less than or equal to 75000
    if (FilingStatus == "Single" and Income <= 75000)
       {
           StimCheck = 1200 + ChildMoney;
       }
    
    // if single with income greater than 75000
    if (FilingStatus == "Single" and Income > 75000)
    {
        StimCheck = 1200 + ChildMoney;
        StimDeductionSingle = (Income - 75000)/100;
        StimCheck = StimCheck - 5*StimDeductionSingle;
    }
    
    // if married and income less than or equal to 150000
    if (FilingStatus == "Married" and Income <= 150000)
    {
        StimCheck = 2400 + ChildMoney;
    }
    
    // if married and income greater than 150000
    if (FilingStatus == "Married" and Income > 150000)
    {
        StimCheck = 2400 + ChildMoney;
        StimDeductionMarried = (Income - 150000)/100;
        StimCheck = StimCheck - 5*StimDeductionMarried;
    }
    
    // if Head of Household and income less than or equal to 112500
    if (FilingStatus == "Head of Household" and Income <= 112500)
    {
        StimCheck = 1200 + ChildMoney;
    }
    
    // if Head of Household and income greater than 112500
    if (FilingStatus == "Head of Household" and Income > 112500)
    {
        StimCheck = 1200 + ChildMoney;
        StimDeductionHoH = (Income - 112500)/100;
        StimCheck = StimCheck - 5*StimDeductionHoH;
    }
    
    
    // statement that prevents StimCheck from being negative
    if (StimCheck < 0)
       {
           StimCheck = 0;
       }
    
    
    cout << "Your stimulus check is $" << StimCheck << "." << endl;
    
    return 0;
}
