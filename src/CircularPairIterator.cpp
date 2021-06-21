#include "../include/CircularPairIterator.h"

CircularPairIterator::CircularPairIterator(
    Container const & elements) : 
  elements(elements),
  first_iterator(elements.begin()), second_iterator(elements.begin())
{ 
  avoidLowerDiagonal(); 
}

void CircularPairIterator::operator ++(){
  second_iterator++;

  if (second_iterator == elements.end()) {
    first_iterator++;
    second_iterator = elements.begin();
  }

  if (first_iterator == elements.end()) {
    first_iterator = elements.begin();
    assert(second_iterator == elements.begin());
  }

  avoidLowerDiagonal();
}

CircularPairIterator::Value CircularPairIterator::operator *() const {
  return std::make_pair(*first_iterator, *second_iterator);
}

void CircularPairIterator::avoidLowerDiagonal(){
  while (first_iterator->id() >= second_iterator->id())
    this->operator ++();
}

void CircularPairIterator::reset(){
  first_iterator = elements.begin(), second_iterator = elements.begin();
  return;
}
