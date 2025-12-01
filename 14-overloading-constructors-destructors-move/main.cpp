#include <iostream>

class Array
{
public:
  Array() : elements_(nullptr), size_(0), capacity_(0) {};
  Array(const int new_element) : elements_(nullptr), size_(0), capacity_(0)
  {
    push_back(new_element);
  };
  
  unsigned int
  get_size() const
  {
    return size_;
  };

  unsigned int
  get_capacity() const
  {
    return capacity_;
  };

  void
  push_back(const int &new_element)
  {
    // Выделение памяти на первое добавление в контейнер
    if (capacity_ == 0) {
      elements_ = new int[1];
      ++capacity_;
      elements_[0] = new_element;
      ++size_;
    }
    // Выделение памяти на последующие добавления в контейнер
    else if (size_ == capacity_) {
      capacity_++;
      int *new_elements = new int[capacity_];
      for (unsigned int i = 0; i < size_; ++i) {
        new_elements[i] = elements_[i];
      }
      new_elements[size_] = new_element;
      size_++;
      delete[] elements_;
      elements_ = new_elements;
    }
    else {
      elements_[size_ + 1] = new_element;
      size_++;
    }
  }

  void
  insert(const int &new_element, const unsigned int position)
  {
    // Если position > capacity контейнера, то контейнер расширяется до position
    if (position > capacity_) {
      capacity_ = position;
      int *new_elements = new int[capacity_];
      for (unsigned int i = 0; i < size_; ++i) {
        new_elements[i] = elements_[i];
      }
      new_elements[position] = new_element;
      size_ = position;
      delete [] elements_;
      elements_ = new_elements;
    }
    // Вставка нового элемента между элементами
    else {
      capacity_++;
      int *new_elements = new int[capacity_];
      int shift = 0;
      for (unsigned int i = 0; i < capacity_; ++i) {
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

  void
  erase(const unsigned int position)
  {

  }

  int
  operator[](const unsigned int index)
  {
    if (index <= size_)
      return elements_[index];
  }

private:
  int *elements_;
  unsigned int size_;
  unsigned int capacity_;
};

int
main()
{
  Array array;
  std::cout << array.get_size();


  Array array_2(2);
  for (unsigned int i = 0; i < array_2.get_size(); ++i) {
    std::cout << array_2[i] << " ";
  }

  array.push_back(1);
  array.push_back(2);
  array.push_back(3);
  array.push_back(4);

  array.insert(55, 4);
  array.insert(66, 0);
  for (unsigned int i = 0; i < array.get_size(); ++i) {
    std::cout << array[i] << " ";
  }

  return 0;
}