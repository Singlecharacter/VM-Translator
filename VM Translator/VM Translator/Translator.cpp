#include "Translator.h"

using std::endl;

Translator::Translator(std::string fname) : comparisonCounter(0)
{
    char *outName = new char[fname.length() + 5];

    strcpy(outName,(fname+".asm").c_str());

    outFile.open(outName);
}

Translator::~Translator()
{
    outFile.close();
}

void Translator::translateAdd()
{
    outFile << "//add" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=M+D" << endl;
    outFile << "D=M" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;
}

void Translator::translateSub()
{
    outFile << "//sub" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=D-M" << endl;
    outFile << "D=M" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;
}

void Translator::translateNeg()
{
    outFile << "//neg" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "D=-D" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;
}

void Translator::translateEq()
{
    outFile << "//eq" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=M-D" << endl;
    outFile << "D=M" << endl;
    outFile << "@TRUE" << comparisonCounter << endl;
    outFile << "D;JEQ" << endl;
    outFile << "@FALSE" << comparisonCounter << endl;
    outFile << "0;JMP" << endl;
    outFile << "(TRUE" << comparisonCounter << ")" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=-1" << endl;
    outFile << "@END" << comparisonCounter << endl;
    outFile << "0;JMP" << endl;
    outFile << "(FALSE" << comparisonCounter << ")"  << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=0" << endl;
    outFile << "(END" << comparisonCounter << ")"  << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;

    comparisonCounter++;
}

void Translator::translateGt()
{
    outFile << "//gt" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=M-D" << endl;
    outFile << "D=M" << endl;
    outFile << "@TRUE" << comparisonCounter << endl;
    outFile << "D;JLT" << endl;
    outFile << "@FALSE" << comparisonCounter << endl;
    outFile << "0;JMP" << endl;
    outFile << "(TRUE" << comparisonCounter << ")" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=-1" << endl;
    outFile << "@END" << comparisonCounter << endl;
    outFile << "0;JMP" << endl;
    outFile << "(FALSE" << comparisonCounter << ")"  << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=0" << endl;
    outFile << "(END" << comparisonCounter << ")"  << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;

    comparisonCounter++;
}

void Translator::translateLt()
{
    outFile << "//lt" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=M-D" << endl;
    outFile << "D=M" << endl;
    outFile << "@TRUE" << comparisonCounter << endl;
    outFile << "D;JGT" << endl;
    outFile << "@FALSE" << comparisonCounter << endl;
    outFile << "0;JMP" << endl;
    outFile << "(TRUE" << comparisonCounter << ")" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=-1" << endl;
    outFile << "@END" << comparisonCounter << endl;
    outFile << "0;JMP" << endl;
    outFile << "(FALSE" << comparisonCounter << ")"  << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=0" << endl;
    outFile << "(END" << comparisonCounter << ")"  << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;

    comparisonCounter++;
}

void Translator::translateAnd()
{
    outFile << "//and" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=M&D" << endl;
    outFile << "D=M" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;
}

void Translator::translateOr()
{
    outFile << "//or" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=M|D" << endl;
    outFile << "D=M" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;
}

void Translator::translateNot()
{
    outFile << "//not" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "D=!D" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;
}

bool Translator::translatePop(std::string memSegment, std::string offset)
{
    outFile << "//pop " + memSegment + " " + offset << endl;

    std::string memNumber = "";

    if(memSegment == "local" || memSegment == "this" || memSegment == "argument" || memSegment == "that" ||
       memSegment == "static" || memSegment == "temp" || memSegment == "pointer")
    {
        if(memSegment == "local")
        {
            memNumber = "1";
        }
        else if(memSegment == "this" || memSegment == "pointer")
        {
            memNumber = "3";
        }
        else if(memSegment == "that")
        {
            memNumber = "4";
        }
        else if(memSegment == "argument")
        {
            memNumber = "2";
        }
        else if(memSegment == "temp")
        {
            memNumber = "5";
        }
        else if(memSegment == "static")
        {
            memNumber = "16";
        }

        outFile << "@" + offset << endl;
        outFile << "D=A" << endl;
        outFile << "@" + memNumber << endl;
        if(!(memSegment == "temp" || memSegment == "static" || memSegment == "pointer"))
        {
            outFile << "A=M" << endl;
        }
        outFile << "D=A+D" << endl;
        outFile << "@R13" << endl;
        outFile << "M=D" << endl;
        outFile << "@SP" << endl;
        outFile << "M=M-1" << endl;
        outFile << "A=M" << endl;
        outFile << "D=M" << endl;
        outFile << "@R13" << endl;
        outFile << "A=M" << endl;
        outFile << "M=D" << endl;
    }
    else
    {
        return false;
    }
}

bool Translator::translatePush(std::string memSegment, std::string offset)
{
    outFile << "//push " + memSegment + " " + offset << endl;

    std::string memNumber = "";

    if(memSegment == "local" || memSegment == "static" || memSegment == "this" ||
       memSegment == "argument" || memSegment == "that" || memSegment == "temp" ||
       memSegment == "pointer")
    {
        if(memSegment == "local")
        {
            memNumber = "1";
        }
        else if(memSegment == "static")
        {
            memNumber = "16";
        }
        else if(memSegment == "this" || memSegment == "pointer")
        {
            memNumber = "3";
        }
        else if(memSegment == "that")
        {
            memNumber = "4";
        }
        else if(memSegment == "argument")
        {
            memNumber = "2";
        }
        else if(memSegment == "temp")
        {
            memNumber = "5";
        }

        outFile << "@R13" << endl;
        outFile << "M=D" << endl;
        outFile << "@" + offset << endl;
        outFile << "D=A" << endl;
        outFile << "@" + memNumber << endl;
        if(!(memSegment == "temp" || memSegment == "static" || memSegment == "pointer"))
        {
            outFile << "A=M" << endl;
        }
        outFile << "A=A+D" << endl;
        outFile << "D=M" << endl;
        outFile << "@SP" << endl;
        outFile << "A=M" << endl;
        outFile << "M=D" << endl;
        outFile << "@SP" << endl;
        outFile << "M=M+1" << endl;
    }
    else if(memSegment == "constant")
    {
        outFile << "@" + offset << endl;
        outFile << "D=A" << endl;
        outFile << "@SP" << endl;
        outFile << "A=M" << endl;
        outFile << "M=D" << endl;
        outFile << "@SP" << endl;
        outFile << "M=M+1" << endl;
    }
    else
    {
        return false;
    }
}

void Translator::endProgram()
{
    outFile << "(ENDPROGRAM)" << endl;
    outFile << "@ENDPROGRAM" << endl;
    outFile << "0;JMP" << endl;
}

void Translator::printError(int line)
{
    std::cout << "Error at line " << line << "!" << endl;
}
