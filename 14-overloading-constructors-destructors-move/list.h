#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
class List
{
public:
  struct Node {
    T data;

    Node *next;
    Node *prev;
  };

  List() : head_(nullptr), tail_(head_), size_(0) {};
  List(const T data) : head_(nullptr), tail_(head_), size_(0)
  {
    first_add(data);
  };

  ~List() 
  {
    Node *node = nullptr;
    for (size_t i = 0; i < size_; ++i) {
      node = head_;
      head_ = head_->next;
      delete node;
    }
  }

  void
  push_back(const T data)
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
  insert(const T data, const  size_t position)
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
  erase(size_t position)
  {
    Node *node = head_;
    for (size_t i = 0; i < size_; ++i) {
      if (position - 1 == i) {
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
    for (size_t i = 0; i < size_; ++i) {
      std::cout << node->data << " ";
      node = node->next;
    }
    std::cout << "\n";
  }

  size_t
  get_size() const
  {
    return size_;
  }

  T &
  operator[](size_t position)
  {
    Node *node = head_;
    for (size_t i = 0; i < size_; ++i) {
      if (position == i) {
        return node->data;
      } else {
        node = node->next;
      }
    }
  }

private:
  Node *head_;
  Node *tail_;

  void
  first_add(const T data)
  {
    head_ = new Node;
    head_->data = data;
    head_->next = nullptr;
    head_->prev = nullptr;
    tail_ = head_;
    ++size_;
  }

  size_t size_;
};