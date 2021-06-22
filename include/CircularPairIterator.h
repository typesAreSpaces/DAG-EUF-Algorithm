#ifndef _CIRCULAR_PAIR_ITERATOR_
#define _CIRCULAR_PAIR_ITERATOR_

#include "Util.h"

class CircularPairIterator {
  
  public:

  typedef Util::Z3ExprSet Container;

  private:

  void avoidLowerDiagonal();

  Container const & elements;
  Container::iterator first_iterator, second_iterator;

  public:

  CircularPairIterator(Container const &);

  void reset();
  void operator ++();
  Container::iterator const & getSecondIterator() const;
  Container::iterator const & getFirstIterator() const;
};

#endif
