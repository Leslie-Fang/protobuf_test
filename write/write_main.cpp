#include<iostream>
#include "test_comm.pb.h"
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	tutorial::Person myP;
	myP.set_name("leslie");
	myP.set_id(1);
	myP.set_email("leslie.fang@intel.com");
	fstream output("tt", ios::out | ios::trunc | ios::binary);
    if (!myP.SerializeToOstream(&output)) {
      cerr << "Failed to write person." << endl;
      return -1;
    }
    google::protobuf::ShutdownProtobufLibrary();
	return 0;
}