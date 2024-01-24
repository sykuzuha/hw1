#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

	list.push_front("1");
  cout << "head first: " << list.head_->first << endl;
  list.push_front("2");
  cout << "head first: " << list.head_->first << endl;
  list.push_front("4");
  list.push_front("5");
  list.push_front("6");
  list.push_front("7");
  list.push_front("8");
  list.push_front("9");
  list.push_front("10");
  list.push_front("11");
  list.pop_front();
  
  
  

  for(unsigned int i = 0; i < list.size_; i++)
  {
    cout << "get " << i << ": " << list.get(i) << endl;
  }

}
