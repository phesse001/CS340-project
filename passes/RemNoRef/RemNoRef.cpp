# define DEBUG_TYPE "RemoveCalls"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/ADT/SmallVector.h"
using namespace llvm;

namespace {
  class RemoveNoRef : public FunctionPass {
    public:
    static char ID; // Pass identification, replacement for typeid
    RemoveNoRef() : FunctionPass(ID) {}
    
    virtual bool runOnFunction(Function &F) {
        SmallVector<Instruction*> insts;

        // loop through instructions in a function 
        for(inst_iterator i = inst_begin(F), e = inst_end(F); i != e; ++i)
        {
            // for every instruction, check if it is used
            Value *v = dyn_cast<Value>(&*i);

            if(v->getNumUses() < 1)
            {
                // now we need to make sure we don't mess up the control flow or remove stores
                if(!isa<ReturnInst>(*i) && !isa<SwitchInst>(*i) && !isa<BranchInst>(*i) && !isa<IndirectBrInst>(*i) && !isa<CallInst>(*i) && !isa<StoreInst>(*i) )
                {
                    insts.push_back(&*i);    
                    errs() << "Removing instruction " << *i << "\n";
                }
            }
        }

        while(!insts.empty())
        {
            Instruction* i = insts.pop_back_val();
            i->eraseFromParent();
        }
        return true;
    }
  };

  char RemoveNoRef::ID = 0;
  static RegisterPass<RemoveNoRef> X("rem-no-ref", "Removes all instructions that have no references in the function");
}
