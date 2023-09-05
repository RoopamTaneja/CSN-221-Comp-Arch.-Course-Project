
#include <iostream>
using std::cout, std::cin, std::string;

class Controller
{
public:
    bool op1Sel, op2Sel;
    string immGen, ALUop;
    bool regRead, regWrite;
    bool memRead, memWrite, mem2Reg;
    string branch, jump;

    void setImmGen_n_ALUop(string op5) // done
    {
        if (op5 == "01100")
            immGen = "000", ALUop = "00";
        else if (op5 == "00100")
            immGen = "001", ALUop = "01";
        else if (op5 == "00000" || op5 == "11001")
            immGen = "001", ALUop = "10";
        else if (op5 == "01000")
            immGen = "010";
        else if (op5 == "11000")
            immGen = "011", ALUop = "11";
        else if (op5 == "11011")
            immGen = "100", ALUop = "10";
        else
            immGen = "101", ALUop = "10";
    }

    Controller(string op5, string f3)
    {
        if (op5 == "11011" || op5 == "11001" || op5 == "00101")
            op1Sel = 1;
        else
            op1Sel = 0;

        if (op5 == "01100")
            op2Sel = 0;
        else
            op2Sel = 1;

        setImmGen_n_ALUop(op5);

        if (op5 == "11011" || op5 == "01101" || op5 == "00101")
            regRead = 0;
        else
            regRead = 1;

        if (op5 == "01000" || op5 == "11000")
            regWrite = 0;
        else
            regWrite = 1;

        if (op5 == "00000")
            memRead = 1, mem2Reg = 1;
        else
            memRead = 0, mem2Reg = 0;

        if (op5 == "01000")
            memWrite = 1;
        else
            memWrite = 0;

        if (op5 == "11000")
        {
            if (f3 == "000")
                branch = "01";
            else if (f3 == "100")
                branch = "10";
        }
        else
            branch = "00";

        if (op5 == "11011")
            jump = "01";
        else if (op5 == "11001")
            jump = "10";
        else
            jump = "00";
    }

    void checkCtrlWord()
    {
        cout << op1Sel << op2Sel << immGen << ALUop << regRead << regWrite << memRead
             << memWrite << mem2Reg << branch << jump << "\n";
    }
};

int dec_sign_imm(string s)
{
    int dec_val = 0, base = 1;
    bool neg = (s[0] == '1');
    if (neg)
    {
        int k = s.find_last_of('1');
        for (int i = k - 1; i >= 0; i--)
            s[i] == '0' ? s[i] = '1' : s[i] = '0';
    }
    int len = s.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            dec_val += base;
        base = base * 2;
    }
    if (neg)
        return -1 * dec_val;
    return dec_val;
}

int main()
{
    string instr = "00000011000001111110010110110011";
    Controller ControlWord(instr.substr(25, 5), instr.substr(17, 3));
    ControlWord.checkCtrlWord();
    // instr[6]
    return 0;
}