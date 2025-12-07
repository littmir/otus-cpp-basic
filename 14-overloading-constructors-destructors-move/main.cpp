#include "array.h"
#include "list.h"

#include <iostream>

int
main()
{
  // 1.создание объекта контейнера для хранения объектов типа int
  Array<int> array;
  List<int> list;

  // 2. добавление в контейнер десяти элементов (0, 1 … 9)
  for (unsigned int i = 0; i < 10; ++i) {
    array.push_back(i);
    list.push_back(i);
  }

  // 3. вывод содержимого контейнера на экран
  // ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  array.print();
  list.print();

  for (unsigned int i = 0; i < array.get_size(); ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";

  for (unsigned int i = 0; i < list.get_size(); ++i) {
    std::cout << list[i] << " ";
  }
  std::cout << "\n";

  //  4. вывод размера контейнера на экран
  // ожидаемый результат: 10
  std::cout << array.get_size() << "\n";
  std::cout << list.get_size() << "\n";
  
  // 5. удаление третьего (по счёту), пятого и седьмого элементов
  array.erase(3);
  array.erase(4); // После удаления третьего элемента, пятый становится четвертым
  array.erase(5); // После удаления третьего и четвертого элемента, седьмой становится пятым
  list.erase(3);
  list.erase(4);
  list.erase(5);

  // 6. вывод содержимого контейнера на экран
  // ожидаемый результат: 0, 1, 3, 5, 7, 8, 9
  array.print();
  list.print();

  // 7. добавление элемента 10 в начало контейнера
  array.insert(10, 0);
  list.insert(10, 0);

  // 8. вывод содержимого контейнера на экран
  // ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9
  array.print();
  list.print();
  
  // 9. добавление элемента 20 в середину контейнера
  array.insert(20, array.get_size() / 2);
  list.insert(20, list.get_size() / 2);
  
  // 10. вывод содержимого контейнера на экран
  // ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9
  array.print();
  list.print();
  
  // 11. добавление элемента 30 в конец контейнера

  array.push_back(30);
  list.push_back(30);

  // 12. вывод содержимого контейнера на экран
  //ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30
  array.print();
  list.print();

  return 0;
}