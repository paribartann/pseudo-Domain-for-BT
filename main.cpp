#include "pseudoDomain.h"
#include <iostream>

using namespace std;
//using namespace pseudo;

int main(int argc, char const *argv[])
{
    pseudoDomain pd;
    pseudoDomain::STATUS_FLAG return_GA;
    pseudoDomain::STATUS_FLAG return_GB;
    pseudoDomain::STATUS_FLAG return_GC;
    pseudoDomain::STATUS_FLAG return_DC;
    int index = 202;

    while (index > 0)
    {
        index--;
        cout<<"Checking if battery is low or not!\n\n";
        if (pd.battery_low())
        {
            cout<<"going to C\n";
            cout<<"Battery is low\n\n";            
            return_GC = pd.GC();
            if(return_GC == pseudoDomain::SUCCESS)
            {
                cout<<"Reached C\n";
                cout<<"Now Docking Charger\n";
                return_DC = pd.DC();
                if(return_DC == pseudoDomain::SUCCESS)
                    cout<<"DC returned success and the battery is fully charged again!\n\n";
            }
        }
        
        else
        {
            cout<<"Battery is not low!\n\n";
            if(pd.not_carrying_packageTP())
            {
                cout<<"going to A\n";
                return_GA = pd.GA();
            }
        }
        if(return_GA == pseudoDomain::SUCCESS)
        {
            cout<<"going to B to drop stuff\n";
            return_GB = pd.GB();     
        }

    } 
    cout<<"\n\n******All the packages have now been dropped*******\n\n";
    return 0;
}


