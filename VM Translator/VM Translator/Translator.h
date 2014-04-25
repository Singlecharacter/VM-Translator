#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <fstream>
#include <string>
#include <cstring>
#include <iostream>

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

    void endProgram();

    void printError(int);

private:

    std::ofstream outFile;

    int comparisonCounter;
};

#endif // TRANSLATOR_H
