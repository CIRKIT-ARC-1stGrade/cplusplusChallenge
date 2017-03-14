#include <algorithm>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  std::string myname {"DOI YUSUKE"};

  std::cout << myname << std::endl; // display before sorting

  myname.erase(myname.find(' '), 1); // erase space on name
  std::sort(myname.begin(), myname.end()); // sort by number of a element.

  std::cout << myname << std::endl; // display after sorting
  return 0;
}
