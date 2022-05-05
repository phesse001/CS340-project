//===--------------- printCode.cpp - Project 1 for CS 701 ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a skeleton of an implementation for the printCode
// pass of Univ. Wisconsin-Madison's CS 701 Project 1.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "printCode"
#include "llvm/Pass.h"
#include "llvm/Module.h"
#include "llvm/Function.h"
#include "llvm/BasicBlock.h"
#include "llvm/User.h"
#include "llvm/Instruction.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Support/InstIterator.h"
#include <iostream>
#include <vector>
#include <map>
using namespace llvm;

namespace {
  class printCode : public FunctionPass {
    public:
    static char ID; // Pass identification, replacement for typeid
    printCode() : FunctionPass(&ID) {}
    
    //**********************************************************************
    // runOnFunction
    //**********************************************************************
    virtual bool runOnFunction(Function &F) {
      // create an instruction map
      static int curInstruction = 1;
      std::map<Instruction*, int> instructionMap;
      for (inst_iterator i = inst_begin(F), e = inst_end(F); i != e; i++){
        instructionMap[&*i] = curInstruction++;
      }
      
      // print function name
      cerr << "FUNCTION " << F.getName() << std::endl;
      
      // print basic blocks, containing their instructions
      BasicBlock* currentBlock = NULL;
      for(std::map<Instruction*, int>::const_iterator i = instructionMap.begin(), e = instructionMap.end(); i != e; i++){
        // if this is the first instruction in this block, print the block
        if(i->first->getParent() != currentBlock){
          currentBlock = i->first->getParent();
          cerr << std::endl << "BASIC BLOCK " << currentBlock->getName() << std::endl;
        }
        // print instruction number
        cerr << "%" << i->second << ": ";
        // print operator name
        cerr << i->first->getOpcodeName();
        // print operands
        for (User::op_iterator j = i->first->op_begin(), e = i->first->op_end(); j != e; j++){
          if(isa<Instruction>(j))
            cerr << " %" << instructionMap[(Instruction*)j->get()];
          else if(j->get()->hasName())
            cerr << " " << j->get()->getName() << " ";
          else
            cerr << " XXX";
        }
        cerr << std::endl;
      }
      cerr << std::endl;

      return false;  // because we have NOT changed this function
    }

    //**********************************************************************
    // print (do not change this method)
    //
    // If this pass is run with -f -analyze, this method will be called
    // after each call to runOnFunction.
    //**********************************************************************
    virtual void print(std::ostream &O, const Module *M) const {
        O << "This is printCode.\n";
    }

    //**********************************************************************
    // getAnalysisUsage
    //**********************************************************************

    // We don't modify the program, so we preserve all analyses
    virtual void getAnalysisUsage(AnalysisUsage &AU) const {
      AU.setPreservesAll();
    };

  };
  char printCode::ID = 0;

  // register the printCode class: 
  //  - give it a command-line argument (printCode)
  //  - a name ("print code")
  //  - a flag saying that we don't modify the CFG
  //  - a flag saying this is not an analysis pass
  RegisterPass<printCode> X("printCode", "print code",
			   true, false);
}
