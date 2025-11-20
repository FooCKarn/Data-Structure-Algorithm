#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T> void CP::queue<T>::merge_greater(CP::queue<T> &other) {
  if(this == &other) return;
  size_t new_cap = mSize + other.mSize;
  T* tmp_data = new T[new_cap];
  size_t tmp_size = 0;
  size_t b_idx = 0;
  size_t limit = other.mSize;
  for(int i = 0;i<limit;i++){
    T valA = mData[(mFront+i)%mCap];
    T valB = other.mData[(other.mFront+i)%other.mCap];
    tmp_data[tmp_size++] = valA;
    if(valB>valA) tmp_data[tmp_size++] = valB;
    else{
      if(b_idx != i){
        other.mData[(other.mFront+b_idx)%other.mCap] = valB;
      }
      b_idx++;
    }
  }
  for(int i = limit;i<mSize;i++){
    tmp_data[tmp_size++] = mData[(mFront+i)%mCap];
  }
  delete [] mData;
  mData = tmp_data;
  mSize = tmp_size;
  mCap  = new_cap;
  mFront = 0;
  other.mSize = b_idx;
}

#endif