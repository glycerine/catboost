#include "name_guard.h"

#include <util/system/progname.h>
#include <util/system/thread.h>

NThreading::TThreadNameGuard::TThreadNameGuard(const TStringBuf name) {
    if (auto currentThreadName = TThread::CurrentThreadGetName()) {
        PreviousThreadName_ = std::move(currentThreadName);
    } else {
        // On some platforms `TThread::CurrentThreadGetName()` may return empty string, because
        // either util doesn't support this platform yet or there is no api to get thread name. By
        // default on most systems thread is named after a program, so we'll fallback to this
        // default.
        PreviousThreadName_ = GetProgramName();
    }


    const TString nameToSet(name);
    TThread::CurrentThreadSetName(nameToSet.c_str());
}

NThreading::TThreadNameGuard::~TThreadNameGuard() {
    TThread::CurrentThreadSetName(PreviousThreadName_.c_str());
}

NThreading::TThreadNameGuard NThreading::TThreadNameGuard::Make(const TStringBuf name) {
    return TThreadNameGuard(name);
}
