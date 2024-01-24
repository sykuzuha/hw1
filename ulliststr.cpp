#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  if(head_ == NULL)
  {
    Item* temp = new Item;
    head_ = temp;
    tail_ = temp;
  }
  else if (tail_->last == ARRSIZE)
  {
    Item* temp = new Item;
    tail_->next = temp;
    temp->prev = tail_;
    tail_= temp;
  }
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::pop_back()
{
  if(head_ == NULL)
  {
    return;
  }
  else if (tail_->last == 1)
  {
    if(head_->next == NULL)
    {
      delete head_;
      head_ = NULL;
      tail_ = NULL;
    }
    else 
    {
      Item* temp = tail_;
      tail_ = temp->prev;
      tail_->next = NULL;
      delete temp;
    }
  }
  else
  {
    tail_->last--;
  }
  size_--;

}

void ULListStr::push_front(const std::string& val)
{
  if(head_ == NULL)
  {
    Item* temp = new Item;
    head_ = temp;
    tail_ = temp;
    temp->first = ARRSIZE;
    temp->last = ARRSIZE;
    
  }
  else if (head_->first == 0)
  {
    Item* temp = new Item;
    head_->prev = temp;
    temp->next = head_;
    temp->first = ARRSIZE;
    temp->last = ARRSIZE;
    head_= temp;
  }
  
  head_->first--;
  head_->val[head_->first] = val;
  size_++;


}

void ULListStr::pop_front()
{
  if(head_ == NULL)
  {
    return;
  }
  else if (head_->first == (ARRSIZE-1))
  {
    if(head_->next == NULL)
    {
      delete head_;
      head_ = NULL;
    }
    else 
    {
      Item* temp = head_;
      head_ = temp->next;
      head_->prev = NULL;
      delete temp;
    }
  }
  else
  {
    head_->first++;
  }
  size_--;

}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_)
  {
    return NULL;
  }
  Item* temp = head_;
  size_t curr = temp->first;
  for(unsigned int i = 0; i < loc; i++)
  {
    curr++;
    if(curr >= (ARRSIZE))
    {
      temp = temp->next;
      curr = temp->first;
    }
  }
  return &temp->val[curr];

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
