# Project Overview
In this project, we will be researching and implementing basic optimization passses in LLVM.

# Commands
- `clang file.c` - compile c file
- `clang -S -emit-llvm -Xclang -disable-O0-optnone *.c` - emit-llvm tells llvm to compile to bitcode istead of object file or exe, -S for human-readable format (.ll), need disable-O0-optnone because when compiled without optimizations, functions are annotated with optnone
- `llvm-as file.ll` - convert to bitcode
- `llvm-dis file.bc` - convert to human-readable bc
- `opt -S -O3 -aa -basicaaa -tbaa -licm single.ll -o optimised.ll` - apply optimizations to IR
- `opt -enable-new-pm=0 -load ~/llvm-project/build/lib/LLVMHello.so -hello file.bc` - apply defined opt pass to bc

# Resources
- Writing an LLVM Pass - https://llvm.org/docs/WritingAnLLVMPass.html
- LLVM IR Reference - https://llvm.org/docs/LangRef.html#module-structure
- LLVM Anaylysis and Transformations Passes - https://llvm.org/docs/Passes.html#mem2reg-promote-memory-to-register
- .ll vs .bc, llvm compile process - https://stackoverflow.com/questions/14107743/llvm-and-compiler-nomenclature
- Explanation of basic LLVM IR - https://stackoverflow.com/questions/27447865/understanding-the-simplest-llvm-ir#:~:text=The%20align%204%20ensures%20that,C%2B%2B%20ret%20i32%200

