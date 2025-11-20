#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "list.h"
template <typename T>
void CP::list<T>::implant(CP::list<T> &other,int pos1,int pos2,int count){
    if(count == 0) return ;
    node *it1 = mHeader->next;
    for(int i = 0;i<pos1;i++){
        it1 = it1->next;
    }
    node *first = other.mHeader->next;
    for(int i = 0;i<pos2;i++){
        first = first->next;
    }
    node *last = first;
    for(int i = 0;i<count-1;i++){
        last = last->next;
    }
    node *before_first = first->prev;
    node *after_last = last->next;
    before_first->next = after_last;
    after_last->prev = before_first;
    other.mSize -= count;
    node *after_it1 = it1->next;
    it1->next = first;
    first->prev = it1;
    last->next = after_it1;
    after_it1->prev = last;
    mSize += count;
}
#endif