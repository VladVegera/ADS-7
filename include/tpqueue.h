// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 public:
    TPQueue(): head(nullptr), tail(nullptr) {}
    void push(const T&);
    T pop();
 private:
    struct ITEM {
      T value;
      ITEM *next;
      ITEM *prew;
    };
    TPQueue:: ITEM *creates(const T&);
    ITEM *head;
    ITEM *tail;
};

template<typename T>
typename TPQueue<T>::ITEM *TPQueue<T>::creates(const T& value) {
  ITEM * temp = new ITEM;
  temp->value = value;
  temp->next = nullptr;
  temp->prew = nullptr;
  return temp;
}

template<typename T>
T TPQueue<T>::pop() {
  if (head && tail) {
    ITEM* temp = head->next;
    if (temp) {
      temp->prew = nullptr;
    }
    T result = head->value;
    delete head;
    head = temp;
    if (!head) {
      tail = nullptr;
    }
    return result;
  }
 return 0;
}

template<typename T>
void TPQueue <T>::push(const T& data) {
  ITEM *temp = head;
  ITEM* item = creates(data);
  while (temp && temp->value.prior >= data.prior) {
    temp = temp->next;
  }
  if (!temp && head) {
    tail ->next = item;
    item->prew = tail;
    tail = item;
  } else if (!temp && !head) {
    head = tail = item;
  } else if (!temp->prew) {
    head->prew = item;
    item->next = head;
    head = item;
  } else {
    temp->prew->next = item;
    item->prew = temp->prew;
    item->next = temp;
    temp->prew = item;
  }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
