#ifndef _ONBOARD_H_
#define _ONBOARD_H_

// Onboard library header file.
// This derived class overrides OnboardService base class member functions.
// The AnyConnect Smarter Camera Platform Libraries will call these APIs
// to read and send data to and from Bluetooth or WiFi network interfaces.

#include <thread>
#include "OnboardService.h"

class Onboard: public com::anyconnect::onboard::OnboardService {
public:
  Onboard();
  virtual ~Onboard();

  void getAvailableInterfaces(std::vector<std::string> &interfaceList) override;

  void enableInterface(const std::string& interfaceId) override;

  void disableInterface(const std::string& interfaceId) override;

  void sendData(const std::string& interfaceId, std::string data, const int length) override;

  void setDataReceiveCallback(com::anyconnect::onboard::DataReceiveHandler handler) override;

  com::anyconnect::onboard::WifiStatus connecttoWifi(const std::string& wifiSecurity, const std::string& wifiSSID, const std::string& password) override;

private:
  void dataReceiveThread();

private:
  com::anyconnect::onboard::DataReceiveHandler handler;
  std::thread dataThread;
  bool dataThreadRunning;
};

#endif

