#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

class expsys {
    public:
        vector<string> dir;
        vector<fs::path> pathvec;
        int selected = 0;
        void getDirInfo() {
            dir.clear();
            pathvec.clear();
            for (const auto& entry : fs::directory_iterator(fs::current_path())) {
                dir.push_back(entry.path().filename().string());
                pathvec.push_back(entry.path());
            }
        }
        void print() {
            system("cls");
            int i=0;
            while(i < dir.size()) {
                if(i == selected) {cout << " " << dir[i] << endl;}
                else { cout << dir[i] << endl; }
                i++;
            }
        }
        void changeSelected(int code) {
            if(code == 0) {
                selected--;
                if(selected < 0) {
                    selected=0;
                }
            } else if (code == 1) {
                selected++;
                if(selected >= dir.size()) {
                    selected=dir.size()-1;
                }
            } else if (code == 2) {
                if(fs::is_directory(pathvec[selected])) {
                    fs::current_path(pathvec[selected]);
                    getDirInfo();
                    selected=0;
                }
            } else if (code == 3) {
                fs::current_path(fs::current_path().parent_path());
                getDirInfo();
                selected=0;
            }
        }
        void find(std::string fS) {
            bool findOn=true;
            string findString;
            system("cls");
            if(fS == "fdsajdhgfafdsytherwnhfggrdygmhjaqdegvbnjtgemdasbfdzr") {
                while (findOn) {
                    char a = _getch();
                    if (a == '\b' && findString.length() != 0) {
                        findString.pop_back();
                        system("cls");
                        cout << findString << endl;
                    } else if (a == '\r') {
                        findOn=!findOn;
                    } else {
                        findString.push_back(a);
                        system("cls");
                        cout << findString << endl;
                    }
                }
            }else {
                findString = fS;
            }
            system("cls");
            int i=0;
            while(i < dir.size()) {
                if(dir[i].starts_with(findString)) {
                    cout << dir[i] << endl;
                }
                i++;
            }
            _getch();
        }
        void cmdlMode() {
            string d;
            system("cls");
            cout << "TAB MODE :" << endl;
            while(true) {// console shit
                char a = _getch();
                    if (a == '\b' && d.length() != 0) {
                        d.pop_back();
                        system("cls");
                        cout << "TAB MODE :" << endl;
                        cout << d << "_" << endl;
                    } else if (a == '\r') {
                        break;
                    } else {
                        d.push_back(a);
                        system("cls");
                        cout << "TAB MODE :" << endl;
                        cout << d << "_" << endl;
                    }
            }
            if(d.starts_with("find.")) {//find
                d.erase(0, 5);
                find(d);
            }else if(d.starts_with("go ")) {//go dir
                d.erase(0, 3);
                fs::path p = d;
                if (p.is_relative()) p = fs::current_path() / p;
                std::error_code ec;
                fs::current_path(p, ec);
                if (!ec) {
                    getDirInfo();
                    selected = 0;
                }else {
                    cout << "error: " << ec.message() << endl;
                    _getch();
                }
            }else if (d == "quit") {//quit
                exit(1);
            }else if (d.starts_with("view.")) {//view
                d.erase(0,5);
                fs::path p=d;
                system("cls");
                if(p.is_relative()){
                    ifstream fl(d);
                    string a;
                    while(getline(fl, a)) {
                        cout << a << endl;
                    }
                    _getch();
                }else {
                    cout << "File Couldn't be found.";
                    _getch();
                }
            }
    }
};