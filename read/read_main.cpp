#include<iostream>
#include "test_comm.pb.h"
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	tutorial::Person myP;
    fstream input("tt", ios::in | ios::binary);
    if (!input) {
      cout << argv[1] << ": File not found.  Creating a new file." << endl;
    } else if (!myP.ParseFromIstream(&input)) {
      cerr << "Failed to parse person." << endl;
      return -1;
    }
    cout << "Person ID: " << myP.id() << endl;
    cout << "  Name: " << myP.name() << endl;
    if(myP.has_email()){
    	cout << "  E-mail address: " << myP.email() << endl;
    }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}