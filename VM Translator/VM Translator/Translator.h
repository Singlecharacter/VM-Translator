#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <fstream>
#include <string>
#include <cstring>

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
    void translatePop(std::string);
    void translatePush(std::string);

private:

    std::ofstream outFile;
};

#endif // TRANSLATOR_H
