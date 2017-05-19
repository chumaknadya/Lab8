#include <iostream>
#include "../include/inputParse.h"
using namespace std;


Parse::Parse(){
    path = "";
    key = "";
    value = "";
}
Parse::Parse(string data){
    int endMethod = data.find(" ");
    int endPath = data.find(" HTTP/1.1");
    string path_data = string(data, endMethod + 1, endPath - endMethod - 1);
    path = path_data;
    int firstRequest = path.find("?");
    int secondRequest = path.find("=");
    if(firstRequest != string::npos){
        key = string(path, firstRequest + 1, secondRequest - firstRequest - 1);
    } 
    if(secondRequest != string::npos){
        value = string(path, secondRequest + 1, path.length() - secondRequest);
    } else {
        int findslash = path.find("/", 1);
        value = string(path, findslash + 1, path_data.length() - findslash);
    }
	
}

Parse::~Parse(){}

string Parse::get_path() {
     return path; 
}
string Parse::get_key() {
     return key;
}
string Parse::get_value() {
     return value; 
}
