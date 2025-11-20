#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "map_bst.h"

//this is the modify() function to be submitted
template <typename KeyT,
          typename MappedT,
          typename CompareT >
void CP::map_bst<KeyT,MappedT,CompareT>::modify(
	CP::map_bst<KeyT,MappedT,CompareT> &other
) {
	
	node* p = mRoot;
	node* key = other.mRoot;
	if(other.mSize==0) return;
	while(p!=NULL){
		if(mLess(key->data.first,p->data.first)){
			if(p->left==NULL){
				p->left = key;
				key->parent = p;
				mSize += other.mSize;
				other.mSize = 0;
				other.mRoot = NULL;
				return ;
			}
			p = p->left;
		}
		else if(mLess(p->data.first,key->data.first)){
			if(p->right==NULL){
				p->right = key;
				key->parent = p;
				mSize += other.mSize;
				other.mSize = 0;
				other.mRoot = NULL;
				return ;
			}
			p = p->right;
		}
		else{
			if(p->left == NULL && p->right==NULL){
				if(p->parent==NULL){
					mRoot = key;
					key->parent = NULL;
				}
				else{
				if(p->parent->left==p){
					p->parent->left = key;
				}
				else{
					p->parent->right = key;
				}

				key->parent = p->parent;
			}
			mSize += other.mSize - 1;
			delete p;
			other.mSize = 0;
			other.mRoot = NULL;
			return ;
			}
			else return;
			
		}


	}
	
	return;
}

//you may use this function to traverse and graft
template <typename KeyT,
          typename MappedT,
          typename CompareT >
void CP::map_bst<KeyT,MappedT,CompareT>::graft(
	CP::map_bst<KeyT,MappedT,CompareT>::node* n, CP::map_bst<KeyT,MappedT,CompareT>::node* m, size_t otherSize
) {
	
	//your code here
	
	return;
}

#endif
