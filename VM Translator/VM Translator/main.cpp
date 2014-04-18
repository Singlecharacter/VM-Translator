#include "Translator.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::ifstream inFile;
    std::string temp;
    char *ctemp;
    while(true)
    {
        std::cout << "Enter a filename: " << std::endl;
        std::cin >> temp;
        ctemp = new char[temp.length()+6];

        strcpy(ctemp,(temp + ".jack").c_str());
        inFile.open(ctemp);
        if(inFile.is_open())
        {
            break;
        }
    }

    Translator translator(temp);

    return 0;
}
