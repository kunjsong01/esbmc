#include <iostream>
#include <cassert>
#include <set>
using namespace std;

int main ()
{
  multiset<int> myset;
  multiset<int>::value_compare mycomp;
  multiset<int>::iterator it,it2;
  int i,highest;

  mycomp = myset.value_comp();
  it = myset.begin();
  it2 = myset.begin();
  assert(mycomp(*it,*it2));


  return 0;
}
