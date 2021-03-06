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
typedef std::function<void(const std::string interfaceId, std::string receivedData, int length)> DataReceiveHandler;

///
/// Error types for WiFi configuration.
///
enum WifiStatus {
  SUCCESS,
  INVALID_INPUT,
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
  /// Returns all available Bluetooth, Ethernet or WiFi AP network interfaces used for onboarding.
  /// e.g., WiFi-AP, Wifi-Client, BLE, Ethernet
  ///
  /// \param[out] interfaceList - List of available Bluetooth or WiFi AP network interfaces for onboarding.
  ///
  virtual void getAvailableInterfaces(std::vector<std::string> &interfaceList) = 0;

  ///
  /// Enables a Bluetooth, Ethernet or WiFi AP network interface for onboarding.
  /// Upon getting invocation, camera should listen for connection on some IP address
  /// and port and exchange data when peer is connected.
  ///
  /// \param[in] interfaceId - The identifier of the network interface.
  ///
  virtual void enableInterface(const std::string& interfaceId) = 0;

  ///
  /// Disable a Bluetooth or WiFi AP network interface,
  /// generally after onboarding is complete. Camera should
  /// stop listening at this point.
  ///
  /// \param[in] interfaceId - the identifier of the interface.
  ///
  virtual void disableInterface(const std::string& interfaceId) = 0;

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
  virtual void sendData(const std::string& interfaceId, std::string data, const int length) = 0;

  ///
  /// Set the Wifi SSID and password and connect to a WiFi network.
  ///
  /// \param[in] wifiSecurity - Security mechanism of the WiFi network, e.g., NONE, WPA/WPA2.
  /// \param[in] wifiSSID - SSID of the WiFi network received from your AnyConnect Smarter Camera App.
  /// \param[in] password - Password of the WiFi network received from your AnyConnect Smarter Camera App.
  /// \param[out] WifiStatus - Status of the WiFi connection.
  ///
  virtual WifiStatus connecttoWifi(const std::string& wifiSecurity, const std::string& wifiSSID, const std::string& password) = 0;
};

} //< onboard
} //< anyconnect
} //< com

#endif
