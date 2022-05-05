//===--------------- optLoads.cpp - Project 1 for CS 701 ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a skeleton of an implementation for the optLoads
// pass of Univ. Wisconsin-Madison's CS 701 Project 1.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "optLoads"
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
  class optLoads : public FunctionPass {
    public:
    static char ID; // Pass identification, replacement for typeid
    optLoads() : FunctionPass(&ID) {}
    
    //**********************************************************************
    // runOnFunction
    //**********************************************************************
    virtual bool runOnFunction(Function &F) {
      // has the function been changed?
      bool functionChanged = false;
      
      // store instructions to be deleted
      std::vector<Instruction*> deleteList;
      
      // create an instruction map
      static int curInstruction = 1;
      std::map<Instruction*, int> instructionMap;
      for (inst_iterator i = inst_begin(F), e = inst_end(F); i != e; i++){
        instructionMap[&*i] = curInstruction++;
      }
      
      // check for useless loads
      BasicBlock* currentBlock = NULL;
      Instruction* previousInstruction = NULL;
      for(std::map<Instruction*, int>::const_iterator i = instructionMap.begin(), e = instructionMap.end(); i != e; i++){
        // check for useless load,
        // unless this is the first instruction in this block
        if(i->first->getParent() != currentBlock){
          currentBlock = i->first->getParent();
        }
        else if(previousInstruction->getOpcode() == Instruction::Store &&
                i->first->getOpcode() == Instruction::Load &&
                previousInstruction->getOperand(1) == i->first->getOperand(0)){
          cerr << "%" << i->second << " is a useless load" << std::endl;
          i->first->replaceAllUsesWith(previousInstruction->getOperand(0));
          deleteList.push_back(i->first);
          functionChanged = true;
        }
        previousInstruction = i->first;
      }
      
      // delete all the unncessary load instructions found
      for(unsigned int i = 0; i < deleteList.size(); i++){
        deleteList[i]->eraseFromParent();
      }

      return functionChanged;  // return whether we have changed the function
    }

    //**********************************************************************
    // print (do not change this method)
    //
    // If this pass is run with -f -analyze, this method will be called
    // after each call to runOnFunction.
    //**********************************************************************
    virtual void print(std::ostream &O, const Module *M) const {
        O << "This is optLoads.\n";
    }

    //**********************************************************************
    // getAnalysisUsage
    //**********************************************************************

    // We may modify the program, so we don't preserve analyses
    virtual void getAnalysisUsage(AnalysisUsage &AU) const {
      
    };

  };
  char optLoads::ID = 0;

  // register the optLoads class: 
  //  - give it a command-line argument (optLoads)
  //  - a name ("optimize loads")
  //  - a flag saying that we modify the CFG
  //  - a flag saying this is not an analysis pass
  RegisterPass<optLoads> X("optLoads", "optimize unnecessary loads",
			   false, false);
}
