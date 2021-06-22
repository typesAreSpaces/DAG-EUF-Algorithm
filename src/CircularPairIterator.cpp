#include "CircularPairIterator.h"

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

CircularPairIterator::Value const CircularPairIterator::operator *() const {
  std::cout << "@CircularPairIterator::operator *" << std::endl;
  return std::make_pair(*first_iterator, *second_iterator);
}

CircularPairIterator::Container::iterator const & CircularPairIterator::getFirstIterator() const {
  return first_iterator;
};

CircularPairIterator::Container::iterator const & CircularPairIterator::getSecondIterator() const {
  return second_iterator;
};

void CircularPairIterator::avoidLowerDiagonal(){
  while (first_iterator->id() >= second_iterator->id())
    this->operator ++();
}

void CircularPairIterator::reset(){
  first_iterator = elements.begin();
  second_iterator = elements.begin();
  return;
}
