#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using std::cout, std::cin, std::string;

void createDataMem(string outFile)
{
    std::ofstream addrStream(outFile);
    for (int addr = 0; addr < 128; addr += 4)
        addrStream << "0x" << std::setw(4) << std::setfill('0') << std::uppercase << std::hex << addr << ": 0\n";
    addrStream.close();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        cout << "Incorrect Format\n";

    else
    {
        string dataMem = argv[1];
        createDataMem(dataMem);
    }
    return 0;
}