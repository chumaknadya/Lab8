#include <iostream>
#include <progbase-cpp/net.h>
#include "../include/repositories.h"
#include "../include/responce.h"
#include "../include/https_server.h"
#include "../include/inputParse.h"
#include <vector>
#define BUFFER_LEN 1000
using namespace std;
using namespace progbase::net;

vector < Repository*> create_elements(void) {
    vector <Repository*> repository;
    repository.push_back(new Repository(1,"progbase","C","this repository for student"));
    repository.push_back(new Repository(2,"libprogbase-cpp","C++","help student to programm"));
    repository.push_back(new Repository(3,"god","Ruby","Ruby process monitor"));
    repository.push_back(new Repository(4,"markaby","Rails","Markaby patched to run on rails 2.0.2"));
    repository.push_back(new Repository(5,"javascript","JavaScript","JavaScript Style Guide"));
    return repository;
}

int http_server() {
    vector <Repository*> repository = create_elements();
	const int serverPort = 3328;
    TcpListener listener;
    NetMessage message(1000);
   
    try {
        listener.bind(IpAddress("127.0.0.1", serverPort));
        listener.start();
        while (true) {
            cout << ">> Waiting for clients at " << serverPort << "..." << endl;
            TcpClient * client = listener.accept();
            client->receive(message);
            cout << ">> Received: " << endl << message.dataAsString() << endl;
            Parse * parse = new Parse(message.dataAsString());
            if(parse->get_path() == "/") {
                message.setDataString(information_about_server());
            }
            else if(parse->get_path() == "/favorites") {
                 message.setDataString(FavouriteRepository(repository));
            }
            else if(parse->get_path().find("/favorites/") != string::npos) {
              
               message.setDataString(findWhereIdIs(repository, message.dataAsString(),parse->get_value()));
            }
            else if(parse->get_path() == "/file/data" && parse->get_value() == "data") {
                message.setDataString(getFileLetter());
            }
            else if(parse->get_path().find("/file") != string::npos) {
                    message.setDataString(getFile());
            }
            else if(parse->get_path().find("/favorites?language=") != string::npos) {
               
                 message.setDataString(findKeyValue(repository,message.dataAsString(),parse->get_value()));
            } else {
                message.setDataString("BAD REQUEST.TRY AGAIN");
            } 
            client->send(message);
            cout << ">> Response sent." << endl;
            delete client;
        } 
    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }

	return 0;
}
