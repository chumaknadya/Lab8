#include "../include/responce.h"
#include <jansson.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <string.h>
#include "../include/repositories.h"
#include <iostream>
#include <string>
using namespace std;

string information_about_server() {
	char buf[1000];
    time_t now = time(0);
    struct tm tm = *gmtime(&now);
    strftime(buf, sizeof buf, "%a, %d %b %Y %H:%M:%S %Z", &tm);
    string tittle("HTTP server ");
	string developer("Chumak Nadia");
    json_t * json = json_object();               
    json_object_set_new(json, "title", json_string(tittle.c_str()));
    json_object_set_new(json, "developer", json_string(developer.c_str()));
    json_object_set_new(json, "time", json_string(buf));
    string jsonString = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
	cout << jsonString << endl;
    return jsonString;
}

string FavouriteRepository(vector < Repository*> repository) {
    json_t * array = json_array(); 
    for(int i = 0; i < repository.size(); i++){
        json_t * json = json_object();
        json_object_set_new(json, "id", json_integer(repository[i]->id()));
        json_object_set_new(json, "name", json_string(repository[i]->name().c_str()));
	    json_object_set_new(json, "language", json_string(repository[i]->language().c_str()));
		json_object_set_new(json, "description", json_string(repository[i]->description().c_str()));
        json_array_append(array, json);
        json_decref(json);
    }
    string jsonString = json_dumps(array, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
	cout << jsonString << endl;
    return jsonString;
}

string findWhereIdIs(vector < Repository*> repository, string dataAsString,string key) {
	 string jsonString;

    bool flag = true;
    json_t * array = json_array();
    for(int i = 0; i < repository.size();i++){
        if(repository[i]->id() == atoi(key.c_str())){
            json_t * json = json_object();
          	json_object_set_new(json, "id", json_integer(repository[i]->id()));
        	json_object_set_new(json, "name", json_string(repository[i]->name().c_str()));
        	json_object_set_new(json, "language", json_string(repository[i]->language().c_str()));
			json_object_set_new(json, "description", json_string(repository[i]->description().c_str()));
            json_array_append(array, json);
            json_decref(json);
            flag = false;

        }
	}
    if(flag) {
        jsonString = "404 Not found";
        return jsonString;
    }
    char * jsonStr =  json_dumps(array, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    string toReturnStr(jsonStr);
    free((void *)jsonStr);
    return toReturnStr;

}
string findKeyValue(vector < Repository*> repository, string dataAsString,string key) {

	bool flag = true;
    json_t * array = json_array();
	string jsonString;
	for(int i = 0; i < repository.size();i++){
        if(repository[i]->language() == key){
            json_t * json = json_object();
          	json_object_set_new(json, "id", json_integer(repository[i]->id()));
        	json_object_set_new(json, "name", json_string(repository[i]->name().c_str()));
        	json_object_set_new(json, "language", json_string(repository[i]->language().c_str()));
			json_object_set_new(json, "description", json_string(repository[i]->description().c_str()));
            json_array_append(array, json);
            json_decref(json);
            flag = false;

        }
	}
    if(flag) {
        jsonString = "404 Not found";
        return jsonString;
    }
    char * jsonStr =  json_dumps(array, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    string toReturnStr(jsonStr);
    free((void *)jsonStr);
    return toReturnStr;
}
string getFile() {
	string line;
    string text;
    ifstream myfile ("/home/ziom/progbase2/labs/lab8/data.txt");
    if (myfile.is_open()){
        while (! myfile.eof() ){
        getline (myfile,line);
        text += line;
    }
    myfile.close();
    }
	int size = text.length();
    json_t * json = json_object();
	json_object_set_new(json, "name", json_string("data.txt"));
	json_object_set_new(json, "size", json_integer(size));
    json_object_set_new(json, "data", json_string(text.c_str()));
    string jsonString = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
	cout << jsonString << endl;
	return jsonString;
}
string getFileLetter() {
    string line;
    string text;
    ifstream myfile ("/home/ziom/progbase2/labs/lab8/data.txt");
    if (myfile.is_open()){
        while (! myfile.eof() ){
        getline (myfile,line);
        text += line;
    }
    myfile.close();
    }
	vector <char> letter;
	for (int i = 0; i < text.length();i++) {
		if(isalpha(text[i])) {
			letter.push_back(text[i]);
		}
	}
    string jsonString;
	vector <string>  str;
	for(int i = 0; i < letter.size();i++) {
		str.push_back(string(1,letter[i]));
	}
	json_t * letterObj = json_array();
    for (int i = 0; i < str.size(); i++) {
		json_t * letter = json_object();
	    json_object_set_new(letter, "letter", json_string(str[i].c_str()));
        json_array_append(letterObj,letter);
		json_decref(letter);
		
	}
	jsonString = json_dumps(letterObj, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
	cout << jsonString << endl;
	return jsonString;
}