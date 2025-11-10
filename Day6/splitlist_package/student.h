void splitList(list<T>& list1, list<T>& list2) {
    if(mSize == 0) return;
    size_t mid = (mSize+1)/2;
    node *first = mHeader->next;
    node *last = mHeader->prev;
    node *midNode = first;
    for(int i = 1;i<mid;i++){
        midNode = midNode->next;
    }
    node* sec_h = midNode->next;
    midNode->next = mHeader;
    mHeader->prev = midNode;
    sec_h->prev = mHeader;
    if(mid>0){
        node *a_tail = list1.mHeader->prev;
        a_tail->next = first;
        first->prev = a_tail;
        list1.mHeader->prev = midNode;
        midNode->next = list1.mHeader;
        list1.mSize += mid;
    }
    if(sec_h!=mHeader){
        node *b_tail = list2.mHeader->prev;
        node *b_first = sec_h;
        b_tail->next = b_first;
        b_first->prev = b_tail;
        list2.mHeader->prev = last;
        last->next = list2.mHeader;
        list2.mSize += mSize - mid;
    }
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    mSize = 0;
}
