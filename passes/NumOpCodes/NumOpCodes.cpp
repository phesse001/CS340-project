#define DEBUG_TYPE "opCounter"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include <map>

using namespace llvm;
namespace {
    struct CountOp : public FunctionPass {
    // map to hold key value pairs of opcode name:numOccurences
    std::map<std::string, int> opCounter;
    static char ID;
    CountOp() : FunctionPass(ID) {}
    virtual bool runOnFunction(Function &F) {
         // for each function, print the name
         errs() << "Function " << F.getName() << '\n';
         // initialize bb (referring to the first basic block of the function)
         // and e (the last basic block of the function) and loop till the last bb
         for (Function::iterator bb = F.begin(), e = F.end(); bb != e; ++bb) {
             // loop through instructions of basic block
            for (BasicBlock::iterator i = bb->begin(), e = bb->end(); i != e; ++i) {
                 // the map end() function returns the "past the end" element of the map
                 // so this is a way of saying if the opcode isn't in the map, set it's
                 // frequency to 1, otherwise it is so increment it by 1
                 if(opCounter.find(i->getOpcodeName()) == opCounter.end()) {
                    opCounter[i->getOpcodeName()] = 1;
                 }
                 else {
                    opCounter[i->getOpcodeName()] += 1;
                 }
            }
         }
         // get iterators for the beginning and end of map
         std::map <std::string, int>::iterator i = opCounter.begin();
         std::map <std::string, int>::iterator e = opCounter.end();
         // print out key value pairs
         while (i != e) {
             errs() << i->first << ": " << i->second << "\n";
             i++;
         }
         // clear it since we want a fresh map for each function
         opCounter.clear();
         return false;
        }
    };
}
char CountOp::ID = 0;
static RegisterPass<CountOp> X("opCounter", "Counts opcodes per functions");
