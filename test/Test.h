#include "OnboardService.h"
#include <functional>

using namespace com::anyconnect::onboard;

class Test {
void* handle;
OnboardService* instance;
OnboardService* (*create)();
void (*destroy)(OnboardService*);

public:
  Test();
  ~Test();
void loadLib(std::string name);
bool isLoaded();
void setDataCallback();
 
};

