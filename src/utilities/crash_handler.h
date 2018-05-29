#ifndef CRASH_HANDLER_H
#define CRASH_HANDLER_H

#include <QtCore/QString>

#ifdef Q_OS_WIN

namespace Breakpad {
class CrashHandlerPrivate;
class CrashHandler {
 public:
  static CrashHandler* instance();
  void Init(const QString& reportPath);

  void setReportCrashesToSystem(bool report);
  bool writeMinidump();

 private:
  CrashHandler();
  ~CrashHandler();
  Q_DISABLE_COPY(CrashHandler)
  CrashHandlerPrivate* d;
};
}  // namespace Breakpad
#endif

#endif
