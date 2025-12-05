#include "array.h"

#include <iostream>

struct Node {
  int data;

  Node *next;
  Node *prev;
};

class List
{
public:
  List() : head_(nullptr), tail_(head_), size_(0) {};
  List(const int data) {
    head_ = new Node;
    head_->data = data;
    head_->next = nullptr;
    head_->prev = nullptr;
    tail_ = head_;
    ++size_;
  };

  ~List() 
  {
    Node *node = nullptr;
    for (unsigned int i = 0; i < size_; ++i) {
      node = head_;
      head_ = head_->next;
      delete node;
    }
  }

  void
  push_back(const int data)
  {
    if (size_ == 0) {
      first_add(data);
    }
    else {
      tail_->next = new Node;
      tail_->next->data = data;
      tail_->next->prev = tail_;
      tail_->next->next = nullptr;
      tail_ = tail_->next;
      ++size_;
    }
  }

  void
  insert(const int data, const unsigned int position)
  {
    if(size_ == 0) {
      first_add(data);
    } else if (position == size_) {
      push_back(data);
    }
    else if (position <= size_) {
      Node *node = head_;
      for (unsigned int i = 0; i < size_; ++i) {
        if (i == position) {
          Node *new_node = new Node;
          new_node->data = data;
          new_node->next = node;
          // Если предыдущий элемент не первый в списке
          if (node->prev != nullptr) {
            node->prev->next = new_node;
            new_node->prev = node->prev;
          }
          node->prev = new_node;
          if (tail_ == new_node->prev) {
            tail_ = new_node;
          }
          if (position == 0) {
            head_ = new_node;
          }
          ++size_;
          break;
        } else {
          node = node->next;
        }
      }
    }
  }

  void
  erase(unsigned int position)
  {
    Node *node = head_;
    for (unsigned int i = 0; i < size_; ++i) {
      if (position == i) {
        if (node != tail_) {
          node->next->prev = node->prev;
        } else {
          tail_ = node->prev;
        }
        if (node != head_) {
          node->prev->next = node->next;
        } else {
          head_ = node->next;
        }
        delete node;
        --size_;
        return;
      }
      node = node->next;
    }
  }

  void
  print()
  {
    Node *node = head_;
    for (unsigned int i = 0; i < size_; ++i) {
      std::cout << node->data << " ";
      node = node->next;
    }
    std::cout << "\n";
  }

  unsigned int
  get_size()
  {
    return size_;
  }

  Node *
  operator[](unsigned int position)
  {
    Node *node = head_;
    if (position <= size_) {
      for (unsigned int i = 0; i < size_; ++i) {
        if (position == i) {
          return node;
        } else {
          node = node->next;
        }
      }
    }
    return nullptr;
  }

private:
  Node *head_;
  Node *tail_;

  void
  first_add(unsigned int data)
  {
    head_ = new Node;
    head_->data = data;
    head_->next = nullptr;
    head_->prev = nullptr;
    tail_ = head_;
    ++size_;
  }

  unsigned int size_;
};

int
main()
{
  //array_checks::check_push_back();
  //array_checks::check_erase();
  //array_checks::check_insert();

  //List list(44);
  List list;
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
  Node *n = list[1];
  std::cout << n->data;

  return 0;
}