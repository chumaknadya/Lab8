/**
    @file
    @brief general information about class Repository
*/
#pragma once
#include <iostream>
using namespace std;
/**
    @class Repository
    @brief defines  fields of  repositories
*/
class Repository
{
private:
    int  _id ;
    std::string  _name;
    std::string  _language;
    std::string  _description ;
public:
    /**
        @brief default public constructor for Repository
    */
    Repository();
    /**
        @brief public constructor for Repository that fill all fields in Repository
        @param id - unique key of repository
        @param name - name of repository
        @param language - a programming language
        @param description - general information about repository
    */
    Repository(int id,std::string name,std::string language,std::string description);
    /**
        @brief default public destructor for Repository
    */
    ~Repository();
     /** 
        @brief sets name of repository
        @param name - name of repository 
    */
    void set_name(std::string  name);
    /** 
        @brief sets programming language of repository
        @param language - programming language of repository 
    */
    void set_language(std::string  language);
     /** 
        @brief sets general information about repository
        @param description - description of repository 
    */
    void set_description(std::string description);
    /** 
        @brief sets unique id of repository
        @param id - unique key
    */
    void set_id(int id);
    /**
        @brief get name of repository
        @return string that represents name of repository
    */
    std::string name();
    /**
        @brief get programming language of repository
        @return string that represents programming language of repository
    */
    std::string language();
    /**
        @brief get id of repository
        @return string that represents id of repository
    */
    int id();
    /**
        @brief get description of repository
        @return string that represents description of repository
    */
    std::string description();
    /**
        @briefoutput data to the screen
       
    */
    void print();
};
