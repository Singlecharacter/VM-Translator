#include "Translator.h"
#include <iostream>
#include <vector>
#include <string>

void stripWhiteSpace(std::string&);

int main()
{
    std::ifstream inFile;
    std::string temp;
    char *ctemp;
    while(true)
    {
        std::cout << "Enter a filename: " << std::endl;
        std::cin >> temp;
        ctemp = new char[temp.length()+4];

        strcpy(ctemp,(temp + ".vm").c_str());
        inFile.open(ctemp);
        if(inFile.is_open())
        {
            break;
        }
    }

    Translator translator(temp);

    std::vector<std::string> lines;

    std::string currentLine;

    char ch;

    while(true)
    {
        currentLine = "";
        ch = inFile.get();
        while(ch != '\n' && inFile.good())
        {
            currentLine += ch;
            ch = inFile.get();
        }

        lines.push_back(currentLine);

        if(!inFile.good())
        {
            break;
        }
    }

    inFile.close();

    std::string command, arg1, arg2;
    bool gotCommand, gotArg1;

    for(int i = 0;i<lines.size();i++)
    {
        command = "";
        arg1 = "";
        arg2 = "";
        gotCommand = false;
        gotArg1 = false;

        currentLine = lines.at(i);

        //Strip any leading whitespace
        stripWhiteSpace(currentLine);

        for(int j = 0;j<currentLine.length();j++)
        {
            if(currentLine[j] == ' ')
            {
                if(!gotCommand)
                {
                    gotCommand = true;
                    command = currentLine.substr(0,j);
                    currentLine.erase(0,j);
                    j=-1;
                }
            }
            else
            {
                if(gotCommand)
                {
                    break;
                }
            }
        }

        if(!gotCommand)
        {
            command = currentLine;
        }

        stripWhiteSpace(currentLine);

        for(int j = 0;j<currentLine.length();j++)
        {
            if(currentLine[j] == ' ')
            {
                if(!gotArg1)
                {
                    gotArg1 = true;
                    arg1 = currentLine.substr(0,j);
                    currentLine.erase(0,j);
                }
            }
            else if(gotArg1)
            {
                break;
            }
        }

        stripWhiteSpace(currentLine);

        if(!gotArg1 && (command == "push" || command == "pop" || command == "label" || command == "goto" || command == "if-goto"))
        {
            translator.printError(i+1);
        }

        arg2 = currentLine;

        if(arg2 == "" && (command == "push" || command == "pop"))
        {
            translator.printError(i+1);
        }

        /*std::cout << "COMMAND: " << command << std::endl;
        std::cout << "ARG 1: " << arg1 << std::endl;
        std::cout << "ARG 2: " << arg2 << std::endl;
        std::cin.sync();
        std::cin.get();*/

        if(command == "add")
        {
            translator.translateAdd();
        }
        else if(command == "sub")
        {
            translator.translateSub();
        }
        else if(command == "neg")
        {
            translator.translateNeg();
        }
        else if(command == "eq")
        {
            translator.translateEq();
        }
        else if(command == "gt")
        {
            translator.translateGt();
        }
        else if(command == "lt")
        {
            translator.translateLt();
        }
        else if(command == "and")
        {
            translator.translateAnd();
        }
        else if(command == "or")
        {
            translator.translateOr();
        }
        else if(command == "not")
        {
            translator.translateNot();
        }
        else if(command == "push")
        {
            translator.translatePush(arg1,arg2);
        }
        else if(command == "pop")
        {
            translator.translatePop(arg1,arg2);
        }
        else if(command == "label")
        {
            translator.translateLabel(arg2);
        }
        else if(command == "goto")
        {
            translator.translateGoto(arg2);
        }
        else if(command == "if-goto")
        {
            translator.translateIfGoto(arg2);
        }
        else if(command == "function")
        {
            translator.addFunction(arg1,arg2);
        }
        else if(command == "call")
        {
            translator.translateCall(arg1,arg2);
        }
        else if(command == "return")
        {
            translator.translateReturn();
        }
        else if(command[0] != '/' && command.length() > 1)
        {
            translator.printError(i+1);
        }
    }

    translator.endProgram();

    translator.translateFunctions();

    //std::cin.sync();
    //std::cin.get();

    return 0;
}

void stripWhiteSpace(std::string& str)
{
    while(true)
    {
        if(str[0] == ' ')
        {
            str.erase(0,1);
        }
        else
        {
            break;
        }
    }
}
