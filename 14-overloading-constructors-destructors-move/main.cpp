#include "array.h"
#include "list.h"

#include <iostream>

int
main()
{
  //array_checks::check_push_back();
  //array_checks::check_erase();
  //array_checks::check_insert();

  //List list(44);
  List <int>list;
  //list.insert(55,0);
  list.insert(1, 0);
  list.print();
  list.insert(2, 1);
  list.print();
  list.insert(3, 2);
  list.print();
  list.insert(4, 0);
  list.print();
  list.insert(5, 1);
  list.print();
  List<int>::Node *n = list[1];
  std::cout << n->data;

  return 0;
}