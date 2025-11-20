#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::jenga(char c, int a)
{
    if(c=='p'){
        int tmp = mData[mSize-1-a];
        for(int i = mSize - 1 -a ;i<mSize;i++){
            mData[i] = mData[i+1];
        }
        mData[mSize-1] = tmp;
    }
    if(c=='c'){
        mSize = mSize - a;
    }
}

#endif