//
// This file is distributed under the MIT License. See LICENSE for details.
//
#ifndef UCLPRINTER_H
#define UCLPRINTER_H

#include "llvm/Pass.h"

namespace smack {

class UclPrinter : public llvm::ModulePass {

public:
  static char ID; // Pass identification, replacement for typeid

  UclPrinter() : llvm::ModulePass(ID) {}
  virtual bool runOnModule(llvm::Module &m);
  virtual void getAnalysisUsage(llvm::AnalysisUsage &AU) const;
};
} // namespace smack

#endif // UCLPRINTER_H
