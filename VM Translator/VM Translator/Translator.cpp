#include "Translator.h"

Translator::Translator(std::string fname)
{
    char *outName = new char[fname.length() + 5];

    strcpy(outName,(fname+".asm").c_str());

    outFile.open(outName,std::ofstream::app);
}

Translator::~Translator()
{
    outFile.close();
}

void Translator::translateAdd()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=M+D" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translateSub()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D-M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translateNeg()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "D=-D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translateEq()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=M-D" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@TRUE" << std::endl;
    outFile << "D;JEQ" << std::endl;
    outFile << "@FALSE" << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(TRUE)" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "M=1" << std::endl;
    outFile << "@END" << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(FALSE)" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "(END)" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translateGt()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=M-D" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@TRUE" << std::endl;
    outFile << "D;JLT" << std::endl;
    outFile << "@FALSE" << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(TRUE)" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "M=1" << std::endl;
    outFile << "@END" << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(FALSE)" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "(END)" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translateLt()
{
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M-1" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@R13" << std::endl;
    outFile << "M=M-D" << std::endl;
    outFile << "D=M" << std::endl;
    outFile << "@TRUE" << std::endl;
    outFile << "D;JGT" << std::endl;
    outFile << "@FALSE" << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(TRUE)" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "M=1" << std::endl;
    outFile << "@END" << std::endl;
    outFile << "0;JMP" << std::endl;
    outFile << "(FALSE)" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "@M" << std::endl;
    outFile << "M=D" << std::endl;
    outFile << "(END)" << std::endl;
    outFile << "@SP" << std::endl;
    outFile << "M=M+1" << std::endl;
}

void Translator::translatePop(std::string memSegment)
{
    if(memSegment == "constant")
    {
        memSegment = "";
    }
}
