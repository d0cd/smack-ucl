//
// This file is distributed under the MIT License. See LICENSE for details.
//
#ifndef UCLFILEPRINTER_H
#define UCLFILEPRINTER_H

#include "llvm/Pass.h"

namespace smack {

class UclFilePrinter : public llvm::ModulePass {
private:
  llvm::raw_ostream &out;

public:
  static char ID; // Pass identification, replacement for typeid

  UclFilePrinter(llvm::raw_ostream &out) : llvm::ModulePass(ID), out(out) {}

  virtual bool runOnModule(llvm::Module &m);

  virtual llvm::StringRef getPassName() const { return "UCLID5 file printing"; }

  virtual void getAnalysisUsage(llvm::AnalysisUsage &AU) const;
};
} // namespace smack

#endif // UCLPRINTER_H
