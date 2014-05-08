#include "Translator.h"

using std::endl;

Translator::Translator(std::string fname) : comparisonCounter(0), returnCounter(0)
{
    mainName = new char[fname.length() + 5];

    strcpy(mainName,(fname+".asm").c_str());

    outFile.open(mainName);
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

void Translator::translateLabel(std::string label)
{
    outFile << "(" << label << ")" << endl;
}

void Translator::translateGoto(std::string label)
{
    outFile << "//goto " << label << endl;

    outFile << "@" << label << endl;
    outFile << "0;JMP" << endl;
}

void Translator::translateIfGoto(std::string label)
{
    outFile << "//if-goto " << label << endl;

    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@" << label << endl;
    outFile << "D;JNE" << endl;
}

void Translator::addFunction(std::string name,std::string args)
{
    outFile.close();
    outFile.open("functions.temp",std::ofstream::app);

    outFile << "(" << name << ")" << endl;
    for(int i = 0;i < strToInt(args); i++)
    {
        translatePush("constant","0");
    }
}

void Translator::translateCall(std::string name, std::string args)
{
    //push return address
    outFile << "@RET" << returnCounter << endl;;
    outFile << "D=A" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;

    //push LCL
    outFile << "@LCL" << endl;
    outFile << "D=M" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;

    //push ARG
    outFile << "@ARG" << endl;
    outFile << "D=M" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;

    //push THIS
    outFile << "@THIS" << endl;
    outFile << "D=M" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;

    //push THAT
    outFile << "@THAT" << endl;
    outFile << "D=M" << endl;
    outFile << "@SP" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;
    outFile << "@SP" << endl;
    outFile << "M=M+1" << endl;

    //ARG = SP-args-5
    outFile << "@" << args << endl;
    outFile << "D=A" << endl;
    outFile << "@5" << endl;
    outFile << "D=D+A" << endl;
    outFile << "@SP" << endl;
    outFile << "D=M-D" << endl;
    outFile << "@ARG" << endl;
    outFile << "M=D" << endl;

    //LCL = SP
    outFile << "@SP" << endl;
    outFile << "D=M" << endl;
    outFile << "@LCL" << endl;
    outFile << "M=D" << endl;

    translateGoto(name);

    outFile << "(RET" << returnCounter << ")" << endl;

    returnCounter++;
}

void Translator::translateReturn()
{
    //FRAME = LCL
    outFile << "@LCL" << endl;
    outFile << "D=M" << endl;
    outFile << "@R13" << endl;
    outFile << "M=D" << endl;

    //RET = *(FRAME-5)
    outFile << "@5" << endl;
    outFile << "D=A" << endl;
    outFile << "@R13" << endl;
    outFile << "A=M" << endl;
    outFile << "A=A-D" << endl;
    outFile << "D=M" << endl;
    outFile << "@R14" << endl;
    outFile << "M=D" << endl;

    //*ARG = pop()
    outFile << "@SP" << endl;
    outFile << "M=M-1" << endl;
    outFile << "A=M" << endl;
    outFile << "D=M" << endl;
    outFile << "@ARG" << endl;
    outFile << "A=M" << endl;
    outFile << "M=D" << endl;


    //SP = ARG + 1
    outFile << "@ARG" << endl;
    outFile << "D=M" << endl;
    outFile << "@SP" << endl;
    outFile << "M=D" << endl;
    outFile << "M=M+1" << endl;

    //THAT = *(FRAME-1)
    outFile << "@1" << endl;
    outFile << "D=A" << endl;
    outFile << "@R13" << endl;
    outFile << "A=M" << endl;
    outFile << "A=A-D" << endl;
    outFile << "D=M" << endl;
    outFile << "@THAT" << endl;
    outFile << "M=D" << endl;

    //THIS = *(FRAME-2)
    outFile << "@2" << endl;
    outFile << "D=A" << endl;
    outFile << "@R13" << endl;
    outFile << "A=M" << endl;
    outFile << "A=A-D" << endl;
    outFile << "D=M" << endl;
    outFile << "@THIS" << endl;
    outFile << "M=D" << endl;

    //ARG = *(FRAME-3)
    outFile << "@3" << endl;
    outFile << "D=A" << endl;
    outFile << "@R13" << endl;
    outFile << "A=M" << endl;
    outFile << "A=A-D" << endl;
    outFile << "D=M" << endl;
    outFile << "@ARG" << endl;
    outFile << "M=D" << endl;

    //LCL = *(FRAME-4)
    outFile << "@4" << endl;
    outFile << "D=A" << endl;
    outFile << "@R13" << endl;
    outFile << "A=M" << endl;
    outFile << "A=A-D" << endl;
    outFile << "D=M" << endl;
    outFile << "@LCL" << endl;
    outFile << "M=D" << endl;

    //goto RET
    outFile << "@R14" << endl;
    outFile << "D=M" << endl;
    outFile << "A=D" << endl;
    outFile << "0;JMP" << endl;

    outFile.close();
    outFile.open(mainName,std::ofstream::app);
}

void Translator::translateFunctions()
{
    std::vector<std::string> functions;

    char inChar;

    std::string temp = "";

    inFile.open("functions.temp");

    inChar = inFile.get();

    while(inFile.good())
    {
        while(inChar != '\n')
        {
            temp += inChar;
            inChar = inFile.get();
        }

        functions.push_back(temp);
        temp = "";
    }

    inFile.close();

    if(!outFile.is_open())
    {
        outFile.open(mainName,std::ofstream::app);
    }

    outFile << endl;
    outFile << "//FUNCTIONS" << endl;
    outFile << endl;

    for(int i = 0; i < functions.size(); i++)
    {
        outFile << functions.at(i) << endl;
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
