#ifndef _ONBOARD_H_
#define _ONBOARD_H_

// Onboard library header file.
// This derived class overrides OnboardService base class member functions.
// The AnyConnect Smarter Camera Platform Libraries will call these APIs
// to read and send data to and from Bluetooth or WiFi network interfaces.

#include <functional>
#include <thread>
#include "OnboardService.h"

using namespace com::anyconnect::onboard;

class Onboard: public OnboardService {
public:
  Onboard();
  virtual ~Onboard();

  void getAvailableInterfaces(std::vector<std::string> &interfaceList);

  void enableInterface(std::string interfaceId);

  void disableInterface(std::string interfaceId);

  void sendData(std::string interfaceId, std::string data, int length);

  void setDataReceiveCallback(DataReceiveHandler handler);

  WifiStatus connecttoWifi(std::string wifiSecurity, std::string wifiSSID, std::string password);

private:
  void dataReceiveThread();

private:
  DataReceiveHandler handler;
  std::thread dataThread;
  bool dataThreadRunning;
};

#endif

