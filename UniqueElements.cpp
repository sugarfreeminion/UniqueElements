/*************************************************************
 *
 * Author:      sugarfreeoh
 * Date:        2016 Feb 23
 * Description: You are given a sorted list of numbers with
 *              duplicates. Print out the sorted list with 
 *              duplicates removed.
 ************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int StringToInt(string val);
string IntToString(int val);

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string temp;
        string uniqueList;
        string line;

        int prevVal = 9999;
        int tempVal;

        while(getline(inputFile,line))
        {
            stringstream lineStream(line);

            while(getline(lineStream,temp,','))
            {
                tempVal = StringToInt(temp);
                //cout << temp << endl;
            

                if(tempVal != prevVal)
                {
                    uniqueList = uniqueList + temp + ',';
                    prevVal = tempVal;
                }
            }

            uniqueList = uniqueList.substr(0,uniqueList.size()-1);

            cout << uniqueList << endl;

            uniqueList = "";
        }
    }

    return 0;
}

int StringToInt(string val)
{
    int result;

    stringstream valStream(val);

    valStream >> result;

    return result;
}
