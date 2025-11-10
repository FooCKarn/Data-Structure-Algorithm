#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  std::vector<T> tmp;
  size_t num = (mSize<7)? mSize:7;
  for(size_t i = 0;i<num;i++){
    tmp.push_back(mData[i]);
  }
  std::sort(tmp.begin(), tmp.end(), mLess);
  return tmp[tmp.size()-k];
}

#endif
