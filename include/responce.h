/**
    @file
	@brief creates information about response
	
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "repositories.h"
using namespace std;
/**
	@brief creates information about server
	@return response to "/"
*/
string information_about_server();
/**
	@brief creates information about favorite repositories
	@param repository - my favorite repositories
	@return response on "/favorites"
*/
string FavouriteRepository(vector < Repository*> repository);
/**
	@brief creates information about some repositories, by field id
	@param repository - my favorite repositories
	@param dataAsString - input string 
	@param key name of field
	@return response on "/favorites/"
*/
string findWhereIdIs(vector < Repository*> repository, string dataAsString,string key);
/**
	@brief creates information about file "data.txt"
	@return response to "/file"
*/
string getFile();
/**
	@brief creates information about some repositories, by field key = value
	@param repository - my favorite repositories
	@param dataAsString - input string 
	@param key name of field
	@return response on "/favorites?somefield=value"
*/
string findKeyValue(vector < Repository*> repository, string dataAsString,string key);
/**
	@brief creates information about letters in file "data.txt"
	@return response to "/file/data"
*/
string getFileLetter();
