void replace(const T& x, list<T>& y) {
  node* it = mHeader->next;
  while(it != mHeader){
    node* nextNode = it->next;
    if(it->data==x){
      node* last_ins = it->prev;
      for(node* y_it= y.mHeader->next;y_it!=y.mHeader;y_it = y_it->next){
        node* newNode = new node(y_it->data,last_ins,it);
        last_ins->next = newNode;
        it->prev = newNode;
        last_ins = newNode;
        mSize++;
      }
      last_ins->next = nextNode;
      nextNode->prev = last_ins;
      delete it;
      mSize--;

    }
    it = nextNode;
  }

}
