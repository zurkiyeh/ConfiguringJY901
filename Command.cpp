#include "Command.h"
#include "constants.h"
#include <vector>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;


unsigned char head          = 0xff;
unsigned char head2         = 0xaa;
unsigned char defaultVal    = 0x00;


int findInVector (string item, vector <string> );
int findInVector (int , vector <int> );
string convertToUppercase(string );




Command::Command(string newName)
{
    name = convertToUppercase(newName);
    int index = findInVector(name, commandName);
    if (index >= 0)
    {
        number = index;
        description = commandDescriptoin [index];
        hexAddress = hexArray [index];
        commandFormat [0] =head;
        commandFormat [1] = head2;
        commandFormat [2] = hexAddress;
        commandFormat [3] = defaultVal;
        commandFormat [4] = defaultVal;

        if (findInVector(index,twoParamCommands) >= 0) {isTwoParam = true;}


    }
    else
    {
        cout << "Your Command doesnt exist" << endl;
    }

}




int findInVector (string item, vector <string> listOfItems)
{
    for (int x = 0; x<listOfItems.size(); x++ )
    {
        if (listOfItems.at(x)== item)
        {
            return x;
        }
    }
    return -1;
}

int findInVector (int item, vector <int> listOfItems)
{
    for (int x = 0; x<listOfItems.size(); x++ )
    {
        if (listOfItems.at(x)== item)
        {
            return x;
        }
    }
    return -1;
}


string convertToUppercase(string lowercase)
{
    int i;

    char str[1024];
    strcpy(str, lowercase.c_str());


    for(i=0; str[i]; i++)
        str[i] = toupper(str[i]);
    return str;
}




void Command::printCommand (Command comm)
{
    // cout <<"Name: " <<comm.getName() <<" Description is: "<< " -->" << comm.getDescription()<< " -->" <<" index number is: "<< comm.getNumber() << " -->" <<" Hex Address is: "<< hex << (int) comm.getHexAddress()
    //       << " -->" << endl;

    cout << comm.getNumber() << "   "<< comm.getName()<< "\t" << comm.getDescription()<< "\t\t" << hex << (int) comm.getHexAddress()<< "\t\t";

    for (int i = 0; i <5 ; i++)
    {
        cout<< hex << (int) comm.getCommandFormatIndex(i) <<dec<< " " ;
    }
    cout << endl;

}




/*
void Command::printCommand (Command comm)
{
    cout <<"Name: " <<comm.getName() <<" Description is: "<< " -->" << comm.getDescription()<< " -->" <<" index number is: "<< comm.getNumber() << " -->" <<" Hex Address is: "<< hex << (int) comm.getHexAddress()
         << " -->" << endl;

    for (int i = 0; i <5 ; i++)
    {
        cout<< " Byte"<< i << "is:"<< hex << (int) comm.getCommandFormatIndex(i) << " " ;
    }
    cout << endl;

}

*/

vector<Command> generateCommandList ()
{
    int sizeOfList = commandName.size();
    vector <Command> commandList;

    for (int i =0; i< sizeOfList ;i ++ )
    {
        string tempString = commandName [i];
        Command tempCommand (tempString);
        //cout<< tempCommand.getName()<<endl;

        commandList.push_back(tempCommand);
    }

    return commandList;
}



void Command::printAllCommands ()
{
    vector <Command > allCommands = generateCommandList ();

    cout <<
         setw(7) << std::left <<"Num "<<
         setw(15) << std::left<< "Name "  <<
         setw(10) << "Hex "<<
         setw(30) << "Description"<<endl ;



    for (int x=0; x< allCommands.size(); x ++)
    {
        cout << "------------------------------------------------------------------"<<endl;
        Command temp_command = allCommands[x];
        cout <<
             setw(7) << std::left <<dec<<temp_command.getNumber() <<
             setw(15) << std::left<< temp_command.getName()  <<
             setw(10) << hex << (int) temp_command.getHexAddress()<<
             setw(30) << temp_command.getDescription()<<


             endl;
    }
















}
