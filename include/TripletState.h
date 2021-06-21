#ifndef _TRIPLET_STATE_
#define _TRIPLET_STATE_

#include "Preprocessor.h"
#include "CircularPairIterator.h"

class TripletState {

  private:

  typedef Util::Z3ExprSet Z3ExprSet;

  // Rules
  bool canSimplificationRule_1_0();
  bool canSimplificationRule_1_1();
  bool canSimplificationRule_1_2();
  bool canDAGUpdateRule();
  bool caneFreeLiteralRule();
  bool canSplittingRule();
  
  void addExplicit(z3::expr const &);
  void addCommon(z3::expr const &);

  // Split
  TripletState * split(z3::expr const &) const;

  // Z3 Context
  z3::context & ctx;

  // Input separation
  Z3ExprSet explicit_formulas;
  Z3ExprSet common_formulas;
  Z3ExprSet uncommon_formulas; 

  void setupUncommonFormulas(z3::expr_vector const &);
  void setupUncommonFormulas(Z3ExprSet const &);

  // Circular Pair Iterator
  CircularPairIterator circular_pair_iterator;
  //circular_pair_iterator((initialSplit(vec_input), uncommon_formulas))

  public:
  TripletState(z3::expr_vector const &);
  TripletState(
      Z3ExprSet const &, 
      Z3ExprSet const &, 
      Z3ExprSet const &, 
      z3::context &);
  TripletState(TripletState const &, z3::context &);

  z3::expr getFormula() const;
  
  friend std::ostream & operator << (std::ostream &, TripletState const &);
};

#endif
