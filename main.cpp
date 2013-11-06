
#include <iostream>
#include <cstring>
#include <sstream>
#include "quash.h"
using namespace std;


int main() {

  quash quash1;
  string line;
  while(getline(cin,line)) {
    //string cmd;
    //cin >> cmd;
    int i;
    size_t pos = line.find(" ");
    string cmd, value;
    if(pos == std::string::npos){
      cmd = line;
    }

    else{
      cmd = line.substr(0, pos);
      value = line.substr(pos+1, line.length() - pos -1);
      istringstream buffer(value);
      buffer >> i;
    }

    if(cmd.compare("insert") == 0) {
      //int i;
      //cin >> i;
      
      if(quash1.contains(i))
	cout << "item " << "already present" << endl;
      else {
        quash1.insert(i);
	cout << "item " << "successfully inserted" << endl; 
      }
    } 
    else if(cmd.compare("lookup") == 0) {
      //int i;
      //cin >> i;

      if(quash1.contains(i))
	cout << "item " << "found" << endl;
      else
	cout << "item " << "not found" << endl;
    } 
    else if(cmd.compare("deleteMin") == 0) {
        if(quash1.isEmpty()) {
	  cout << "min item not present since table is empty!" << endl;
        } 
	else {
          int i = quash1.getMinValue();
          quash1.deleteMin();
	  cout << "min item " << i << " deleted" << endl;
        }
        
    } 
    else if(cmd.compare("delete") == 0) {
      //int i;
      //cin >> i;

      if(quash1.erase(i))
	cout << "item " << i << " successfully deleted" << endl;
      else
	cout << "item " << "not present in the table" << endl;
    } 
    else if(cmd.compare("print") == 0) {
      quash1.print();
    }
  }
}
