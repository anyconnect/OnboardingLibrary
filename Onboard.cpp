#include <string>
#include <vector>
#include <unistd.h>

#include "Onboard.h"

Onboard::Onboard()
{
  dataThreadRunning = false;
  // Write your initialization code.
}

Onboard::~Onboard()
{
  dataThread.join();
  dataThreadRunning = false;
  // Write your de-initialization code.
}

void Onboard::getAvailableInterfaces(std::vector<std::string> &interfaceList)
{
  // Complete the interfaceList vector with all available Bluetooth and WiFi AP network interfaces.
  // For example: 
  // interfaceList.push_back("BLE");
  // interfaceList.push_back("WiFi-AP");
  // interfaceList.push_back("WiFi-Client");
}

void Onboard::enableInterface(std::string interfaceId)
{
  // Enables a Bluetooth or WiFi AP network interface. 
  // For example:
  // if(interfaceId == "WiFi-AP") {
  //   enable WiFi AP mode. 
  // }
  // else if(interfaceId == "WiFi-Client") {
  //  enable WiFi Client mode.
  // }
  // else if(interfaceId == "BLE") {
  //  enable Bluetooth mode.
  // } 
}

void Onboard::disableInterface(std::string interfaceId)
{
  // Disables a Bluetooth or WiFi AP network interface.
  // For example:
  // if(interfaceId == "WiFi-AP") {
  //   disable WiFi AP mode. 
  // }
  // else if(interfaceId == "WiFi-Client") {
  //  disable WiFi Client mode.
  // }
  // else if(interfaceId == "BLE") {
  //  disable Bluetooth mode.
  // } 
}

void Onboard::sendData(std::string interfaceId, std::string data, int length)
{
  // Sends data to a connected Smarter Camera App using a Bluetooth or WiFi AP network interface.
  // For example:
  // if(interfaceId == "WiFi-AP") {
  //  send data using WiFi AP interface
  // }
  // else if(interfaceId == "BLE") {
  //  send data using Bluetooth interface
  // }
}

void Onboard::setDataReceiveCallback(DataReceiveHandler handler)
{
  // Returns data received from a connected Smarter Camera App via a Bluetooth or WiFi AP network interface.
  // This function must be non-blocking, so we created dataReceiveThread(),
  // which must call your interface library's Read() API.

  this->handler = handler; 
  if(dataThreadRunning == false) {
    dataReceiveThread();
    dataThreadRunning = true;
  }
}

void Onboard::dataReceiveThread() 
{
 dataThread = std::thread([this] {

  // Reads data from a Bluetooth or WiFi AP network interface.
  // This function spans a thread to execute a non-blocking read.
  // Mechanism for receiving and reading needs to be completed by you.
  //
  // The received data may contain the WiFi-credential, user Id and keys.
  // The key-value string needs to be separated by a newline('\n')
  // if it has multiple entity on it.
  // 
  //
  // For example:
  // if data is received on WiFi-AP 
  // then:
  //   std::string interface = "WiFi-AP";
  //   std::string recvData = "SSID=wifi_ssid"+"\n"+"PASS=wifi_password"+"\n"+"UID=userID"+"\n"+"KEY=deviceLeaseToken";
  //   int size = recvData.length();
  //   this->handler(interface, recvData, size);
  // else if data is received on Bluetooth
  // then,
  //   std::string interface = "BLE";
  //   std::string recvData = "SSID=wifi_ssid"+"\n"+"PASS=wifi_password"+"\n"+"UID=userID"+"\n"+"KEY=deviceLeaseToken";
  //   int size = recvData.length();
  //   this->handler(interface, recvData, size);
 });
}

WifiStatus Onboard::connecttoWifi(std::string wifiSecurity, std::string wifiSSID, std::string password)
{
  // Connects to a WiFi network in Client Mode using the SSID and password received from a connected Smarter Camera App.
  // Before connecting to a WiFi network in Client Mode, make sure to disable WiFI AP Mode.
  // For example:
  // disableInterface("WiFi-AP");
  // enableInterface("WiFi-Client");
  // Connect to a WiFi network using the SSID, password and security mode.
}

// Create and deletes the camera's Onboarding Library instance.
extern "C" {
Onboard* create() {
	return new Onboard();
}
void destroy(Onboard* onboard) {
	delete onboard;
}
}
