#include "EUFInterpolator.h"
#include <cstdlib>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>

inline bool exists_file (std::string const &);
void        read_input();

int main(int argc, char * argv[]){

  z3::context ctx;
  ctx.set(":pp-min-alias-size", 1000000);
  ctx.set(":pp-max-depth",      1000000);

  // ------------------------------------------------------------
  // Test
  z3::sort my_sort = ctx.uninterpreted_sort("A");

  z3::expr s1 = ctx.constant("s1", my_sort);
  z3::expr s2 = ctx.constant("s2", my_sort);

  z3::func_decl f = ctx.function("f", my_sort, my_sort, my_sort);

  z3::expr z1 = ctx.constant("z1", my_sort);
  z3::expr z2 = ctx.constant("z2", my_sort);
  z3::expr z3 = ctx.constant("z3", my_sort);
  z3::expr z4 = ctx.constant("z4", my_sort);

  z3::expr a = ctx.constant("a", my_sort);
  z3::expr b = ctx.constant("b", my_sort);

  z3::expr e = ctx.constant("e", my_sort);
  z3::expr e1 = ctx.constant("e1", my_sort);
  z3::expr e2 = ctx.constant("e2", my_sort);

  z3::expr t = ctx.constant("t", my_sort);
  z3::expr v1 = ctx.constant("v1", my_sort);
  z3::expr v2 = ctx.constant("v2", my_sort);

  std::set<std::string> uncomms({"e", "e1", "e2"});
  // ------------------------------------------------------------

  z3::expr_vector input(ctx); 
  input.push_back(s1 == f(z3, e));
  input.push_back(s2 == f(z4, e));
  input.push_back(e1 == f(z1, e));
  input.push_back(e2 == f(z2, e));
  input.push_back(f(e1, e2) == t);
  input.push_back(v1 == f(e1, a));
  input.push_back(v2 == f(e2, b));
  try {
    EUFInterpolator eufi(input, uncomms);
    //std::cout << eufi.removePrefix(eufi.getInterpolant()) << std::endl;
  }
  catch(char const * e){
    std::cout << e << std::endl;
  }

  return 0;
}

inline bool exists_file(std::string const & name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

void read_input() {
  //switch(argc){
  //case 5:
  //{
  //z3::solver input_parser(ctx);
  //if(!exists_file(argv[2])){
  //std::cout
  //<< "File not found." 
  //<< std::endl;
  //return 1;
  //}

  //input_parser.from_file(argv[2]);
  //std::string decls = input_parser.to_smt2_decls_only();
  //AXDSignature sig(ctx, argv[1], decls);

  //auto const & to_cnf_tactic = 
  //z3::tactic(ctx, "tseitin-cnf");
  //auto const & to_dnf_tactic = 
  //z3::repeat(
  //z3::tactic(ctx, "split-clause") 
  //| z3::tactic(ctx, "skip"));
  //auto const & my_tactic = 
  //to_cnf_tactic & to_dnf_tactic;

  //auto const & input_formula
  //= input_parser.assertions();
  //if(input_formula.size() == 0){
  //std::cout 
  //<< "No assertions in input file" 
  //<< std::endl;
  //return 2;
  //}
  //assert(input_formula.size() == 2);
  //z3::goal goal_a(ctx);
  //z3::goal goal_b(ctx);
  //goal_a.add(input_formula[0]);
  //goal_b.add(input_formula[1]);
  //auto const & part_a = my_tactic(goal_a);
  //auto const & part_b = my_tactic(goal_b);

  //try {
  //for(unsigned i = 0; i < part_a.size(); i++){
  //for(unsigned j = 0; j < part_b.size(); j++){
  //AXDInterpolant axd(
  //sig,
  //// Input formulas
  //part_a[i].as_expr(),
  //part_b[j].as_expr(),
  //// Smt2 file name
  //argv[2], 
  //// Number of allowed attemps
  //strtoul(argv[4], NULL, 0));
  //switch(*argv[3]){
  //case '0':
  //axd.z3OutputFile();
  //break;
  //case '1':
  //axd.mathsatOutputFile();
  //break;
  //case '2':
  //axd.smtInterpolOutputFile();
  //break;
  //default:
  //std::cout
  //<< "Not valid SMT solver option."
  //<< std::endl;
  //return 3;
  //}
  //std::cout << axd << std::endl;
  //}
  //}
  //return 0;
  //}
  //catch(char const * e){
  //std::cout << e << std::endl;
  //return 4;
  //}
  //}

  //default:
  //std::cout
  //<< "Invalid number of arguments." 
  //<< std::endl;
  //return 5;
  //}

}
