//============================================================================
// Name        : siemens_training.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

class LinkedList {
 public:
  LinkedList() { std::cout << "Constructor called" << std::endl; }

  ~LinkedList() { std::cout << "Destructor called" << std::endl; }
  struct sLinkedList {
    int data;
    sLinkedList* nextItem;

    explicit sLinkedList(int item) {
      data = item;
      nextItem = nullptr;
    }
  };

  void Add(int itemVal) {
    sLinkedList* item = new sLinkedList(itemVal);
    if (list == nullptr) {
      list = item;
      current = item;
    } else {
      current->nextItem = item;
      current = item;
    }
  }

  int getItem(int position) {
    int start = 0;
    sLinkedList* itr = list;
    while (start < position - 1) {
      itr = itr->nextItem;
      start++;
    }
    return itr->data;
  }

  void setItem(int position, int item) {
    int start = 0;
    sLinkedList* itr = list;
    while (start < position) {
      itr = itr->nextItem;
      start++;
    }
    itr->data = item;
  }

  void Insert(int position, int itemVal) {
    int start = 0;
    sLinkedList* itr = list;
    while (start < position - 2) {
      itr = itr->nextItem;
      start++;
    }
    sLinkedList* item = new sLinkedList(itemVal);
    item->nextItem = itr->nextItem;
    itr->nextItem = item;
  }

  void Delete(int position) {
    sLinkedList* temp = list;
    sLinkedList* prev = NULL;

    int start = 0;
    if (temp != NULL && position == 1) {
      list = temp->nextItem;  // Changed head
      delete temp;            // free old head
      return;
    } else {
      while (temp != NULL && start != position - 1) {
        prev = temp;
        temp = temp->nextItem;
        start++;
      }

      // Unlink the node from linked list
      prev->nextItem = temp->nextItem;

      // Free memory
      delete temp;
      return;
    }
  }

  void PrintLinkedList() {
    sLinkedList* itr = list;
    while (itr != nullptr) {
      std::cout << itr->data << " - > ";
      itr = itr->nextItem;
    }
    std::cout << "NULL" << std::endl;
  }

 private:
  sLinkedList* current = nullptr;
  sLinkedList* list = nullptr;
};

int main() {
  std::cout << "!!!Hello World!!!" << std::endl;  // prints !!!Hello World!!!

  LinkedList* lList = new LinkedList();
  lList->Add(10);
  lList->Add(20);
  lList->Add(30);
  lList->Add(40);
  lList->Add(50);

  std::cout << "Elelemnt at 1st postition is " << lList->getItem(1)
            << std::endl;
  std::cout << "Elelemnt at 2st  postition is " << lList->getItem(2)
            << std::endl;
  std::cout << "Elelemnt at 3st postition is " << lList->getItem(3)
            << std::endl;
  std::cout << "Elelemnt at 4st postition is " << lList->getItem(4)
            << std::endl;
  std::cout << "Elelemnt at 5st postition is " << lList->getItem(5)
            << std::endl;

  lList->PrintLinkedList();

  lList->Insert(3, 15);
  lList->PrintLinkedList();

  lList->Insert(4, 25);
  lList->PrintLinkedList();

  lList->Delete(3);
  lList->PrintLinkedList();

  return 0;
}
