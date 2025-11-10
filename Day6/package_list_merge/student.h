#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
    for(auto it = ls.begin();it!=ls.end();it++){
      list<T> &sub = *it;
      if(sub.mSize=0) continue;
      node *first = sub.mHeader->next;
      node *last = sub.mHeader->prev;
      node *tail = mHeader->prev;
      tail->next = first;
      first->prev = tail;
      last->next = mHeader;
      mHeader->prev = last;
      mSize += sub.mSize;
      sub.mHeader->next = sub.mHeader;
      sub.mHeader->prev = sub.mHeader;
      sub.mSize = 0;
    }

}

#endif
