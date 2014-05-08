#include "Translator.h"
#include <iostream>
#include <vector>
#include <string>

int strToInt(std::string);

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

    std::string command, memSegment, offset;
    bool gotCommand, gotSegment;

    for(int i = 0;i<lines.size();i++)
    {
        command = "";
        memSegment = "";
        offset = "";
        gotCommand = false;
        gotSegment = false;

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
                if(!gotSegment)
                {
                    gotSegment = true;
                    memSegment = currentLine.substr(0,j);
                    currentLine.erase(0,j);
                }
            }
            else if(gotSegment)
            {
                break;
            }
        }

        stripWhiteSpace(currentLine);

        if(!gotSegment && (command == "push" || command == "pop"))
        {
            translator.printError(i+1);
        }

        offset = currentLine;

        if(offset == "" && (command != "push" || command != "pop"))
        {
            translator.printError(i+1);
        }

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
            translator.translatePush(memSegment,offset);
        }
        else if(command == "pop")
        {
            translator.translatePop(memSegment,offset);
        }
        else if(command[0] != '/' && command.length() > 1)
        {
            translator.printError(i+1);
        }
    }

    translator.endProgram();

    std::cin.sync();
    std::cin.get();

    return 0;
}

int strToInt(std::string str)
{
    int digit, num = 0;
    for(int i = 0;i<str.length();i++)
    {
        digit = str[i] - 48;
        num = num * 10;
        num += digit;
    }

    return num;
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
