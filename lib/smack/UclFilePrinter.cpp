//
// This file is distributed under the MIT License. See LICENSE for details.
//
#include "smack/UclFilePrinter.h"
#include "smack/UclidAst.h"
#include "smack/SmackModuleGenerator.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/GraphWriter.h"
#include <sstream>

namespace smack {

using llvm::errs;

char UclFilePrinter::ID = 0;

void UclFilePrinter::getAnalysisUsage(llvm::AnalysisUsage &AU) const {
  AU.setPreservesAll();
  AU.addRequired<SmackModuleGenerator>();
}

bool UclFilePrinter::runOnModule(llvm::Module &m) {
  SmackModuleGenerator &smackGenerator = getAnalysis<SmackModuleGenerator>();
  Program *program = smackGenerator.getProgram();
  std::ostringstream s;
  program->print(s);
  out << s.str();
  // DEBUG_WITH_TYPE("bpl", errs() << "" << s.str());
  return false;
}
} // namespace smack
