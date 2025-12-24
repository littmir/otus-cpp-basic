#pragma once
#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public:
  Array() : elements_(nullptr), size_(0), capacity_(0) {};
  Array(const T new_element) : elements_(nullptr), size_(0), capacity_(0)
  {
    push_back(new_element);
  };
  ~Array()
  {
    delete [] elements_;
  }
  
 size_t
  get_size() const
  {
    return size_;
  };

  size_t
  get_capacity() const
  {
    return capacity_;
  };

  void
  push_back(const T &new_element)
  {
    // Выделение памяти на первое добавление в контейнер
    if (capacity_ == 0) {
      elements_ = new T;;
      ++capacity_;
      elements_[0] = new_element;
      ++size_;
    }
    // Выделение памяти на последующие добавления в контейнер
    else if (size_ == capacity_) {
      capacity_++;
      T *new_elements = new T[capacity_];
      for (size_t i = 0; i < size_; ++i) {
        new_elements[i] = elements_[i];
      }
      new_elements[size_] = new_element;
      size_++;
      delete[] elements_;
      elements_ = new_elements;
    }
    else {
      elements_[size_] = new_element;
      size_++;
    }
  }

  void
  insert(const T &new_element, const size_t position)
  {
    if (position > size_) {
      push_back(new_element);
    }
    // Вставка нового элемента между элементами
    else {
      capacity_++;
      T *new_elements = new T[capacity_];
      int shift = 0;
      for (size_t i = 0; i < capacity_; ++i) {
        if(i == position) {
          shift++;
          continue;
        }
        new_elements[i] = elements_[i - shift];
      }
      new_elements[position] = new_element;
      size_++;
      delete [] elements_;
      elements_ = new_elements;
    }
  }

  // Удаление без перераспределения памяти для возможных
  // новых вставок
  void
  erase(const size_t position)
  {
    if (position <= size_ && size_ > 0) {
      for (size_t i = position - 1; i < size_ - 1; ++i) {
        elements_[i] = elements_[i + 1];
      }
      --size_;
    }
  }

  T &operator[](const size_t index)
  {
    return elements_[index];
  }

  void
  print()
  {
    for (size_t i = 0; i <  size_; ++i) {
      std::cout << elements_[i] << " ";
    }
    std::cout << "\n";
  }

private:
  T *elements_;
  size_t size_;
  size_t capacity_;
};

namespace array_checks {

inline void check_erase()
{
  Array<int> arr;

  arr.erase(0);

  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);

  arr.erase(1); // Удаление двойки

  // {1, 3}
  arr.print();

  arr.erase(2);
  arr.erase(2);

  arr.erase(1);
  arr.erase(0);
  arr.erase(1);
  ;
}

inline void check_push_back()
{
  Array<double> arr;

  arr.push_back(1.2);
  arr.push_back(2);
  arr.push_back(3);

  // {1, 2, 3}
  arr.print();

  arr.erase(1); // Удаление двойки

  // {1, 3}
  arr.print();

  arr.push_back(4);

  // {1, 3, 4}
  arr.print();

  arr.insert(5, 3);

  arr.push_back(6);

  // {1, 3, 4, 5, 6}
  arr.print();
}

inline void check_insert()
{
  Array<std::string> arr;

  arr.insert("1", 0);
  arr.insert("2", 0);
  arr.insert("3", 0);

  // {3, 2, 1}
  arr.print();

  arr.erase(2);
  arr.insert("1", 2);

  // {3, 2, 1}
  arr.print();
}
} // namespace Array