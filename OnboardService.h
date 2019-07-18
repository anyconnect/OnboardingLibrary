#ifndef _ONBOARD_SERVICE_H_
#define _ONBOARD_SERVICE_H_

// Onboard Service library header file.
// The AnyConnect Smarter Camera Platform Libraries will call these APIs
// to read and send data to and from Bluetooth or WiFi network interfaces.
// These base class member functions are overridden by Onboard derived class.

#include <string>
#include <vector>
#include <functional>
#include <stdint.h>

// Sample interface Ids
#define INTERAFCE_ID_BLE          "BLE"
#define INTERAFCE_ID_WIFI_AP      "WiFi-AP"
#define INTERAFCE_ID_WIFI_CLIENT  "WiFi-CLIENT"

namespace com {
namespace anyconnect {
namespace onboard {

///
/// Handler for data received on a network interface.
///
/// \param[out] interfaceId - Network interface that has data.
/// \param[out] receivedData - Data received on the interface.
/// \param[out] length - Length of the received data.
///
typedef std::function<void(const std::string &interfaceId, std::string &receivedData, int &length)> DataReceiveHandler;

///
/// Error types for WiFi configuration.
///
enum WifiStatus {
  SUCCESS,
  AUTH_FAIL,
  UNAVAILABLE,
  FAIL
};

class OnboardService {
public:
  OnboardService() {
  ;
  }

  ///
  /// Returns all available Bluetooth or WiFi AP network interfaces.
  /// e.g., WiFi-AP, Wifi-Client, BLE
  ///
  /// \param[out] interfaceList - List of available Bluetooth or WiFi AP network interfaces for onboarding.
  ///
  virtual void getAvailableInterfaces(std::vector<std::string> &interfaceList) = 0;

  ///
  /// Enables a Bluetooth or WiFi AP network interface for onboarding.
  ///
  /// \param[in] interfaceId - The identifier of the network interface.
  ///
  virtual void enableInterface(std::string interfaceId) = 0;

  ///
  /// Disable a Bluetooth or WiFi AP network interface,
  /// generally after onboarding is complete.
  ///
  /// \param[in] interfaceId - the identifier of the interface.
  ///
  virtual void disableInterface(std::string interfaceId) = 0;

  ///
  /// Set a callback for receiving data from a network interface.
  ///
  /// \param[in] DataReceiveHandler - Handler function for the received data.
  ///
  virtual void setDataReceiveCallback(DataReceiveHandler handler) = 0;

  ///
  /// Send data using a network interface.
  ///
  /// \param[in] interfaceId - The ID of the network interface to be used.
  /// \param[in] data - Data be sent.
  /// \param[in] length - Length of the data.
  ///
  virtual void sendData(std::string interfaceId, std::string data, int length) = 0;

  ///
  /// Set the Wifi SSID and password and connect to a WiFi network.
  ///
  /// \param[in] wifiSecurity - Security mechanism of the WiFi network, e.g., NONE, WPA/WPA2.
  /// \param[in] wifiSSID - SSID of the WiFi network received from your AnyConnect Smarter Camera App.
  /// \param[in] password - Password of the WiFi network received from your AnyConnect Smarter Camera App.
  /// \param[out] WifiStatus - Status of the WiFi connection.
  ///
  virtual WifiStatus connecttoWifi(std::string wifiSecurity, std::string wifiSSID, std::string password) = 0;
};

} //< onboard
} //< anyconnect
} //< com

#endif
