#include "EUFInterpolator.h"
#include <cstdlib>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>

#define _ENABLE_CORRECTNESS_TEST_ 1

typedef std::set<std::string> StringSet;

z3::expr_vector setupQuickTest(z3::context &);
z3::expr_vector readInputFormula(z3::context &, int, char * argv[]);
StringSet       readUncommsSymbols(int, char * argv[]);
inline bool     existsFile (std::string const &);

int main(int argc, char * argv[]){

  z3::context ctx;
  ctx.set(":pp-min-alias-size", 1000000);
  ctx.set(":pp-max-depth",      1000000);

  StringSet uncomms = readUncommsSymbols(argc, argv);
  //z3::expr_vector input = setupQuickTest(ctx);
  z3::expr_vector input = readInputFormula(ctx, argc, argv);
  
  try {
    EUFInterpolator eufi(input, uncomms);
    z3::expr result = eufi.getInterpolant(); 

    std::cout << "Input:" << std::endl;
    std::cout << z3::mk_and(input) << std::endl;
    std::cout << "Interpolant:" << std::endl;
    std::cout << result << std::endl;

#if _ENABLE_CORRECTNESS_TEST_
    z3::solver s(ctx);
    s.add(not(z3::implies(z3::mk_and(input), result)));
    std::cout << "Correctness test: ";
    switch (s.check()) {
      case z3::unsat:
        std::cout << "Ok" << std::endl;
        break;
      case z3::sat:
      case z3::unknown:
        std::cout << "Not ok" << std::endl;
        break;
    }
#endif
  }
  catch(char const * e){
    std::cout << e << std::endl;
  }

  return 0;
}

inline bool existsFile(std::string const & name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

z3::expr_vector readInputFormula(
    z3::context & ctx, 
    int argc, char * argv[]) {

  if (!argc) throw "Invalid number of arguments.";
  if (!existsFile(argv[1])) throw "File not found";

  z3::solver input_parser(ctx);
  input_parser.from_file(argv[1]);
  return input_parser.assertions();
}

StringSet readUncommsSymbols(
    int argc, char * argv[]) {
  if (!argc) throw "Invalid number of arguments.";
  if (!existsFile(argv[1])) throw "File not found";

  StringSet result({});
  for (int i = 2; i < argc; i++)
    result.insert(argv[i]);
  return result;
}

z3::expr_vector setupQuickTest(z3::context & ctx) {

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
  z3::expr t1 = ctx.constant("t1", my_sort);
  z3::expr v1 = ctx.constant("v1", my_sort);
  z3::expr v2 = ctx.constant("v2", my_sort);

  z3::expr_vector input(ctx); 
  input.push_back(s1 == f(z3, e));
  input.push_back(s2 == f(z4, e));
  input.push_back(e1 == f(z1, e));
  input.push_back(e2 == f(z2, e));
  input.push_back(f(e1, e2) == t);
  input.push_back(v1 == f(e1, a));
  input.push_back(v2 == f(e2, b));

  return input;
}
