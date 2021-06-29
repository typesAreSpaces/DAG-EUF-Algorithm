#ifndef _TRIPLET_STATE_
#define _TRIPLET_STATE_

#include <vector>
#include "Preprocessor.h"
#include "CircularPairIterator.h"

#define _DEBUG_CONSTRUCTOR_     0
#define _DEBUG_NORMALIZATION_   0
#define _DEBUG_UNCOMMS_ERASURE_ 0
#define _DEBUG_SPLIT_RULE_      0

#define EXTRACT_PAIR(PAIR_ITERATOR, X, Y)\
  z3::expr const & X = *(PAIR_ITERATOR.getFirstIterator());\
  z3::expr const & Y = *(PAIR_ITERATOR.getSecondIterator());

// We need to reset the circular_pair_iterator because
// if we erase a pointer in uncommon_formulas, this can 
// be also one of the first_iterator or second_iterator 
// in circular_pair_iterator
#define MODIFY_UNCOMMS(CURR_ITERATOR_, EXTRA_CODE)\
  this->uncommon_formulas.erase(CURR_ITERATOR_);\
  EXTRA_CODE;\
  this->circular_pair_iterator.reset();

class TripletState {
  friend class CircularPairIterator;

  private:

  typedef Util::Z3ExprSet               Z3ExprSet;
  typedef Z3ExprSet::iterator           Z3ExprSetIterator;
  typedef std::pair<z3::expr, z3::expr> Z3ExprPair;
  typedef std::set<std::string>         StringSet ;
  typedef std::vector<TripletState*>    StatePointerVec;

  void normalization();

  // Rules
  bool canApplySimplificationRule_1_0();
  bool canApplySimplificationRule_1_0_();
  bool canApplySimplificationRule_1_1();
  bool canApplySimplificationRule_1_2();
  bool canApplyDAGUpdateRule();
  bool canApplyeFreeLiteralRule();

  void addExplicitFormula(z3::expr const &);
  void addCommonFormula(z3::expr const &);
  void addUncommonFormula(z3::expr const &);
  void removeUncommonFormula(z3::expr const &);

  void setupUncommonFormulas(z3::expr_vector const &);
  void setupUncommonFormulas(Z3ExprSet const &);
  z3::expr fresh_constant(z3::sort const &);

  bool            areCompatible(z3::expr const & , z3::expr const &) const;
  z3::expr_vector differenceSet(z3::expr const & , z3::expr const &) const;
  bool            isValidDifferenceSet(z3::expr_vector const &) const;

  z3::context &     ctx;
  unsigned &        fresh_num;
  bool              is_leave;
  StringSet const & uncomms;

  // Input separation
  Z3ExprSet explicit_formulas;
  Z3ExprSet common_formulas;
  Z3ExprSet uncommon_formulas; 

  // Circular Pair Iterator
  CircularPairIterator circular_pair_iterator;

  public:
  TripletState(z3::expr_vector const &, unsigned &, StringSet const &);
  TripletState(TripletState const &, z3::context &, 
      unsigned &, StringSet const &);

  // Rules
  StatePointerVec splittingRule();

  z3::expr getFormula()     const;
  bool     isLeave()        const;
  bool     availablePairs() const;

  friend std::ostream & operator << (std::ostream &, TripletState &);
};

#endif
