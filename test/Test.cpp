#include "Test.h"
#include "OnboardService.h"
#include <assert.h>
#include <dlfcn.h>
#include <cstdio>
#include <iostream>
#include <unistd.h>

Test::Test()
{

}

void Test::loadLib(std::string name)
{
  instance = NULL;
  handle = dlopen(name.c_str(), RTLD_LAZY);

  if (!handle) {
    printf("%s\n", dlerror());
    return;
  }

  create = (OnboardService* (*)()) dlsym(handle, "create");
  destroy = (void(*)(OnboardService*)) dlsym(handle, "destroy");

  char* error;
  if ((error = dlerror()) != NULL) {
    printf("%s\n", error);
    return;
  }

  instance = create();
}

bool Test::isLoaded()
{
  return instance != NULL;
}

void Test::setDataCallback()
{
  instance->setDataReceiveCallback([this](std::string interfaceId, std::string data, int len) {
    std::cout<<"Received: "<<interfaceId<<" data: "<<data<<std::endl;
  });
}

Test::~Test() {
  destroy(instance);
  dlclose(handle);
  handle = NULL;
}

Test *pTest = new Test();

int main()
{
  pTest->loadLib("./libonboard.so");

  if(pTest->isLoaded()) {
    printf("Your AnyConnect Onboarding Library is loaded!\n");
  }
  else {
    printf("Your AnyConnect Onboarding Library is not loaded!\n");
  }
  pTest->setDataCallback();
  while(1) {
    sleep(3);
  }
  return 0;
}
