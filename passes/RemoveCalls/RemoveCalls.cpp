# define DEBUG_TYPE "RemoveCalls"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/ADT/SmallVector.h"
using namespace llvm;

namespace {
  class RemoveCalls : public FunctionPass {
    public:
    static char ID; // Pass identification, replacement for typeid
    RemoveCalls() : FunctionPass(ID) {}
    
    virtual bool runOnFunction(Function &F) {
        SmallVector<Instruction*, 128> insts;

        // loop through instructions in a function and remove them based on the type
        for(inst_iterator i = inst_begin(F), e = inst_end(F); i != e; ++i)
        {
            // isa is like instanceof in java, we can give it a type and call it on the value of the instruction
            if(isa<CallInst>(*i))
            {
                insts.push_back(&*i);
                errs() << "Removing call: " << *i << "\n";
            }
        }

        while(!insts.empty())
        {
            Instruction* i = insts.pop_back_val();
            i->eraseFromParent();
        }
        return false;
    }
  };

  char RemoveCalls::ID = 0;
  static RegisterPass<RemoveCalls> X("remCalls", "Removes all calls from a function");
}
