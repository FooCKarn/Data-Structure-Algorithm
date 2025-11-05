#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if(m==0) return false;
  if(!(a>=begin()&&a<end())) return false;
  if(!(b>=begin()&&b<end())) return false;
  size_t la = a - begin();
  size_t lb = b - begin();
  if(la+m-1>=mSize) return false;
  if(lb+m-1>=mSize) return false;
  if(la==lb) return false;
  size_t l = la<lb? la:lb;
  size_t r = la<lb? lb:la;
  if(l+m>r) return false;
  for (size_t i = 0; i < m; i++) {
    std::swap(mData[la + i], mData[lb + i]);
  }
  return true;
}

#endif
