#include "PlayList.h"
#include <iostream>
#include "LinkedSet.cpp"
#include "Node.cpp"
#include "Song.cpp"

using namespace std;

PlayList::PlayList(): tail_ptr_(nullptr) {}

PlayList::PlayList(const Song& a_song){
	tail_ptr_ = new new_node_ptr<ItemType>();
	tail_ptr_->setItem(a_song);	
	tail_ptr_->setNext(nullptr);
}


PlayList::PlayList(const PlayList& a_play_list){


}

bool PLaylist::remove(const Song& a_song) override{
	Node<ItemType> * pointer_to_that_node = getpointerto(a_song);
	if pointer_to_that_node == NULL:
	    return false;
	else if (item_count_ == 0)
	    return false;
	else if (item_count_ ==1)
	    head_ptr_ = NULL;
	    return true;
	else :
	    //bool can_remove_item = !isEmpty() ///&& (entry_node_ptr != nullptr);
        {
    
    // Copy data from first node to located node
    //this part copies head to that node
            pointer_to_that_node->setItem(head_ptr_->getItem());
    // Delete first node
    //temp node 
            Node<ItemType>* node_to_delete_ptr = head_ptr_;
    
            head_ptr_ = head_ptr_->getNext();
    
    // Return node to the system
    
            node_to_delete_ptr->setNext(nullptr);
    
            delete node_to_delete_ptr;
    
            node_to_delete_ptr = nullptr;  
    //item count decrease
            item_count_--;
        } // end if

    return true;
	
	

}



bool PlayList::add(const Song& new_song) override{
	if(!contains(new_song)){
		 Node<ItemType>* next_node_ptr = new Node<ItemType>();
       next_node_ptr->setItem(new_entry);
       tail_ptr_->setNext(next_node_ptr);

       tail_ptr_ = next_node_ptr;          
       item_count_++;
	
	return true;
	}
	return false;
}

Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const{
	bool found = false;
   Node<ItemType>* cur_ptr = head_ptr_;
   previous_ptr = NULL;
   
   while (!found && (cur_ptr != nullptr))
   {
      if (target == cur_ptr->getItem())
         found = true;
     	return true;
      else
      	previous_ptr = cur_ptr;
         cur_ptr = cur_ptr->getNext();
   } // end while
   
   return NULL;
  
}

Node<Song>* PlayList::getPointerToLastNode() const{
	bool found = true;
	Node<ItemType>* ptr = new Node<ItemType>;
	while (!found){
		if(ptr = nullptr){
			found = true;
			return nullptr;
		}
		else{
			ptr->setItem();
		ptr->setNext();
		}
	}
	return ptr;
}
void PLaylist::loop(){
	Node * last = getPointerToLastNode();
    last->next = tail_ptr_;
}
void PLaylist::unloop(){
	Node * temp = tail_ptr_ -> next;
    tail_ptr_ -> next = NULL;
    tail_ptr_ = temp;
}


void PlayList::displayPlayList(){
	vector<ItemType> song_vector = this->toVector();
    for(int i=0;i<LinkedSet<ItemType>::item_count_;i++) {
       cout<<song_vector[i]<<"\n";
}



PLaylist::~PlayList(){
	clear();
}


