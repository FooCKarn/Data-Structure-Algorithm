void shift(int k) {
	int n = 0;
	node *cur = mHeader->next;
	while(cur!=mHeader){
		n++;
		cur = cur->next;
	}
	k%=n;
	if(k<0) k += n;
	if(n<=1||k==0) return ;
	node *new_fi = mHeader->next;
	for(int i = 0;i<k;i++) new_fi = new_fi->next;
	node *new_la = new_fi->prev;
	node *old_fi = mHeader->next;
	node *old_la = mHeader->prev;
	old_la->next = old_fi;
	old_fi->prev = old_la;
	mHeader->next = new_fi;
	new_fi->prev = mHeader;
	mHeader->prev = new_la;
	new_la->next = mHeader;
}
