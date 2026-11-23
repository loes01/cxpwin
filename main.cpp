#include <iostream>
#include <windows.h>
#include <string>
#include "includes/explorersys.hpp"
#include "includes/inputsys.hpp"

int main() {
        expsys eSys;
        eSys.getDirInfo();
        eSys.print();
        while(true) {
                char input = getInput();
                if (input == 'q') { system("cls"); break; }
                else if (input == 'w') eSys.changeSelected(0);
                else if (input == 's') eSys.changeSelected(1);
                else if (input == 72) eSys.changeSelected(0);
                else if (input == 80) eSys.changeSelected(1);
                else if (input == '\r') eSys.changeSelected(2);
                else if (input == '\b') eSys.changeSelected(3);
                else if (input == 'f') eSys.find("fdsajdhgfafdsytherwnhfggrdygmhjaqdegvbnjtgemdasbfdzr");
                else if (input == '\t') eSys.cmdlMode();
                eSys.print();
        }
}