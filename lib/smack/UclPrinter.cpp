//
// This file is distributed under the MIT License. See LICENSE for details.
//
#include "smack/UclPrinter.h"
#include "smack/UclidAst.h"
#include "smack/SmackModuleGenerator.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/GraphWriter.h"
#include <sstream>

namespace smack {

using llvm::errs;

llvm::RegisterPass<BplPrinter> Y("ucl_print", "UCLID5 printer pass");
char UclPrinter::ID = 0;

void UclPrinter::getAnalysisUsage(llvm::AnalysisUsage &AU) const {
  AU.setPreservesAll();
  AU.addRequired<SmackModuleGenerator>();
}

bool UclPrinter::runOnModule(llvm::Module &m) {
  SmackModuleGenerator &smackGenerator = getAnalysis<SmackModuleGenerator>();
  Program *program = smackGenerator.getProgram();
  std::ostringstream s;
  program->print(s);
  DEBUG_WITH_TYPE("ucl", errs() << "" << s.str());
  return false;
}
} // namespace smack
