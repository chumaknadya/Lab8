/** 
    @file
    @brief  describes a Parse
*/
#pragma once
#include <iostream>
using namespace std;
/**
    @class Parse
    @brief defines a client request
*/
class Parse
{
private:
    string path;
    string key;
    string value;
public:
    /**
        @brief default public constructor for Parse
    */ 
    Parse();
     /**
        @brief public constructor for Parse that fill all fields in Parse
        @param string - string that is defines client request

    */
    Parse(string data);
    /**
        @brief gets specified path from client request
        @return string that defines specified path
    */
    string get_path();
    /**
        @brief gets specified value from client request
        @return string that defines specified value 
    */
    string get_value();
    /**
        @brief gets specified key from client request
        @return string that defines specified key 
    */
    string get_key();
    /**
        @brief default public destructor for Parse
    */
    ~Parse();
 
};
