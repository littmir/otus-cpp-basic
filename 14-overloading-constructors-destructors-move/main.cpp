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

  void
  push_back(const int data)
  {
    if (size_ == 0) {
      head_ = new Node;
      head_->data = data;
      head_->next = nullptr;
      head_->prev = nullptr;
      tail_ = head_;
      ++size_;
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
    if(position == 0) {
      head_ = new Node;
      head_->data = data;
      head_->next = nullptr;
      head_->prev = nullptr;
      tail_ = head_;
      ++size_;
    } 
    else if (position <= size_) {
      Node *node = head_;
      for (unsigned int i = 0; i < size_; ++i) {
        if (i == position) {
          Node *new_node = new Node;
          new_node->data = data;
          new_node->next = node->next;
          new_node->prev = node;
          node->next = new_node;
          if (tail_ == new_node->prev) {
            tail_ = new_node;
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
  print()
  {
    Node *node = head_;
    for (unsigned int i = 0; i < size_; ++i) {
      std::cout << node->data << " ";
      node = node->next;
    }
    std::cout << "\n";
  }

private:
  Node *head_;
  Node *tail_;

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
  list.insert(55,0);
  list.push_back(66);
  list.print();
  list.insert(77,1);
  list.print();

  return 0;
}