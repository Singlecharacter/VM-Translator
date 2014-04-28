#include "Translator.h"

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
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=M+D" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translateSub()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D-M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translateNeg()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "D=-D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translateEq()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=M-D" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@TRUE" << comparisonCounter << std::endl;
    outFile << "D;JEQ" << std::endl;
    outFile << "@FALSE" << comparisonCounter << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(TRUE" << comparisonCounter << ")" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=-1" << std::endl;
    outFile << "@END" << comparisonCounter << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(FALSE" << comparisonCounter << ")"  << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=0" << std::endl;
    outFile << "(END" << comparisonCounter << ")"  << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;

    comparisonCounter++;
}

void Translator::translateGt()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=M-D" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@TRUE" << comparisonCounter << std::endl;
    outFile << "D;JLT" << std::endl;
    outFile << "@FALSE" << comparisonCounter << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(TRUE" << comparisonCounter << ")" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=-1" << std::endl;
    outFile << "@END" << comparisonCounter << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(FALSE" << comparisonCounter << ")"  << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=0" << std::endl;
    outFile << "(END" << comparisonCounter << ")"  << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;

    comparisonCounter++;
}

void Translator::translateLt()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=M-D" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@TRUE" << comparisonCounter << std::endl;
    outFile << "D;JGT" << std::endl;
    outFile << "@FALSE" << comparisonCounter << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(TRUE" << comparisonCounter << ")" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=-1" << std::endl;
    outFile << "@END" << comparisonCounter << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(FALSE" << comparisonCounter << ")"  << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=0" << std::endl;
    outFile << "(END" << comparisonCounter << ")"  << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;

    comparisonCounter++;
}

void Translator::translateAnd()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=M&D" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translateOr()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=M|D" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translateNot()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "D=!D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "A=M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

bool Translator::translatePop(std::string memSegment, std::string offset)
{
    if(memSegment == "local" || memSegment == "this" || memSegment == "argument" || memSegment == "that" || memSegment == "static")
    {
        if(memSegment == "local")
        {
            memSegment = "1";
        }
        else if(memSegment == "this")
        {
            memSegment = "3";
        }
        else if(memSegment == "that")
        {
            memSegment = "4";
        }
        else if(memSegment == "argument")
        {
            memSegment = "2";
        }

        outFile << "@" + offset << std::endl;
        outFile << "D=A" << std::endl;
        if(memSegment != "static")
        {
            outFile << "A=M" << std::endl;
        }
        outFile << "A=A+D" << std::endl;
        outFile << "D=A" << std::endl;
        outFile << "@R13" << std::endl;
        outFile << "M=D" << std::endl;
        outFile << "@SP" << std::endl;
        outFile << "M=M-1" << std::endl;
        outFile << "A=M" << std::endl;
        outFile << "D=M" << std::endl;
        outFile << "@R13" << std::endl;
        outFile << "A=M" << std::endl;
        outFile << "M=D" << std::endl;

    }
    else
    {
        return false;
    }
}

bool Translator::translatePush(std::string memSegment, std::string offset)
{
    if(memSegment == "local" || memSegment == "static" || memSegment == "this" || memSegment == "argument" || memSegment == "that")
    {
        if(memSegment == "local")
        {
            memSegment = "1";
        }
        else if(memSegment == "static")
        {
            memSegment = "16";
        }
        else if(memSegment == "this")
        {
            memSegment = "3";
        }
        else if(memSegment == "that")
        {
            memSegment = "4";
        }
        else if(memSegment == "argument")
        {
            memSegment = "2";
        }

        outFile << "@R13" << std::endl;
        outFile << "M=D" << std::endl;
        outFile << "@" + offset << std::endl;
        outFile << "D=A";
        outFile << "@" + memSegment << std::endl;
        outFile << "A=A+D" << std::endl;

        outFile << "D=M" << std::endl;
        outFile << "@SP" << std::endl;
        outFile << "A=M" << std::endl;
        outFile << "M=D" << std::endl;
        outFile << "@SP" << std::endl;
        outFile << "M=M+1" << std::endl;
    }
    else if(memSegment == "constant")
    {
        outFile << "@" + offset << std::endl;
        outFile << "D=A" << std::endl;
        outFile << "@SP" << std::endl;
        outFile << "A=M" << std::endl;
        outFile << "M=D" << std::endl;
        outFile << "@SP" << std::endl;
        outFile << "M=M+1" << std::endl;
    }
    else
    {
        return false;
    }
}

void Translator::endProgram()
{
    outFile << "(ENDPROGRAM)" << std::endl;
    outFile << "@ENDPROGRAM" << std::endl;
    outFile << "0;JMP" << std::endl;
}

void Translator::printError(int line)
{
    std::cout << "Error at line " << line << "!" << std::endl;
}
