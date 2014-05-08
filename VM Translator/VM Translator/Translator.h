#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include "strToInt.h"

class Translator
{
public:

    Translator(std::string);
    ~Translator();

    void translateAdd();
    void translateSub();
    void translateNeg();
    void translateEq();
    void translateGt();
    void translateLt();
    void translateAnd();
    void translateOr();
    void translateNot();
    bool translatePop(std::string, std::string);
    bool translatePush(std::string, std::string);
    void translateLabel(std::string);
    void translateGoto(std::string);
    void translateIfGoto(std::string);
    void translateCall(std::string,std::string);
    void translateReturn();
    void addFunction(std::string,std::string);
    void translateFunctions();

    void endProgram();

    void printError(int);

private:

    std::ofstream outFile;

    std::ifstream inFile;

    char *mainName;

    int comparisonCounter, returnCounter;

};

#endif // TRANSLATOR_H
