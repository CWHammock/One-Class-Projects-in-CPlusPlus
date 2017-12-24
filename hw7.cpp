#include <iostream>
#include <cstdlib>
#include <iterator>
#include "lklist.h"

using std::cout;
using std::endl;



int main()
{
  // initialize lists
  cout << "create, populate(10 num) and print list" << endl;
  cout << "---------------------------------------" << endl;
  lklist<int> newlist;
  srand(time(0));
  for (int i = 0; i < 10; i++){newlist.push_front(rand()%99+1);}
  cout << endl;
  lklist<int>::iterator itr_b = newlist.begin();
  lklist<int>::iterator itr_e = newlist.end();
  cout << "the distance is " << newlist.size(itr_b, itr_e);
  cout << endl;
  for(lklist<int>::iterator itr = newlist.begin(); itr != newlist.end(); itr++)
  cout << *itr << endl; cout << endl;
  cout << "---------------------------------------" << endl;
  cout << "test == and !=" << endl;
  cout << "---------------------------------------" << endl;
  lklist<int>::iterator a = newlist.begin();
  lklist<int>::iterator b = --(newlist.end());
  lklist<int>::iterator c = newlist.begin();
  cout << "a = newlist.begin(); " << *a << endl;
  cout << "b = --(newlist.end()); " << *b << endl;
  cout << "c = newlist.begin(); " << *c <<endl;
  cout << "1. a == b? ";
  if (a==b){cout << "true" << endl;} else if (a!=b) {cout << "false" << endl;}
  cout << "2. b == c? ";
  if (b==c){cout << "true" << endl;} else if (b!=c) {cout << "false" << endl;}
  cout << "3. a == c? ";
  if (a==c){cout << "true" << endl;} else if (a!=c) {cout << "false" << endl;}
  lklist<int> list;
  cout << "---------------------------------------" << endl;
  cout << "create, populate(10 num) and print list" << endl;
  cout << "---------------------------------------" << endl;
  srand(time(0));
  for (int i = 0; i < 10; i++){list.push_front(rand()%99+1);}
  for(lklist<int>::iterator itr = list.begin(); itr != list.end(); itr++)
  cout << *itr << endl;
  cout << "---------------------------------------" << endl;
  cout << "test ++" << endl;
  cout << "---------------------------------------" << endl;
  lklist<int>::iterator first = list.begin();
  cout << *first << " " << "print num at beginning" << endl;
  cout << *first++ << " " << "num++" << endl;
  cout << *first << " " << "print num" << endl;
  cout << *++first << " " << "++num" <<endl;
  cout << *first << " " << "print num" << endl;
  cout << "---------------------------------------" << endl;
  cout << "test --" << endl;
  cout << "---------------------------------------" << endl;
  lklist<int>::iterator last = list.end();
  cout << *last << " " << "print num/head value" << endl;
  cout << *last-- << " " << "num--" << endl;
  cout << *last << " " << "print num" << endl;
  cout << *--last << " " << "--num" <<endl;
  cout << *last << " " << "print num" << endl;

}
