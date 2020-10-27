The AnyConnect Onboarding Plugin Library enables camera onboarding, in conjunction with the AnyConnect Smarter Camera Platform, via Bluetooth, Ethernet, or WiFi AP.  The steps to build and deploy your Onboarding Library are:

# Procedure

1. Complete the stub functions in libonboard.cpp.
2. Compile your libonboard.so.
3. Dynamically link your libonboard.so with your AnyConnect Encoder library (libencoder.so), AnyConnect Smarter Camera Platform libraries (libaccess.so. libconnect.so, libstream.so, and libvision.so), and your Smarter Camera application.


# What’s Included

- README		Instructions to complete the libonboard.cpp stub functions and compile and use libonboard.so.
- Onboard.h		Onboard library header file.  This derived class overrides OnboardService base class member functions.
- Onboard.cpp		Onboard library source file.  You must complete the stub functions.
- OnboardService.h	These base class member functions are overridden by Onboard derived class.
- Makefile		Compiles libonboard.so.
- test/Test.h		Test application for libonboard.so.
- test/Test.cpp		Test application for libonboard.so.
- test/Makefile		Compiles the test application.


# What’s Required

Software packages:
- Linux
- dl library
- pthreads library 
- gcc/g++ version 7.x or higher

Network features:
- Bluetooth, Ethernet, or WiFi AP Mode
- WiFi Client Mode

Bluetooth interfaces to programmatically:
- Enable and disable Bluetooth
- Advertise Bluetooth
- Read and write data

WiFi AP mode interfaces to programmatically:
- Switch between WiFi AP and WiFi Client Modes
- Act as a TCP server with a static IP address
- Read and write data

WiFi Client mode interfaces to programmatically:
- Switch between WiFi AP and WiFi Client Modes
- Enable and disable WiFi Client Mode
- Configure SSID and password
- Connect to a WiFi access point


# How to complete the libonboard.cpp stub functions

- getAvailableInterfaces() // Returns all available Bluetooth or WiFi AP network interfaces.
- enableInterface() // Enables a Bluetooth or WiFi AP network interface.
- disableInterface() // Disable a Bluetooth or WiFi AP network interface.
- sendData() // Sends data to a connected Smarter Camera App using a Bluetooth or WiFi AP network interface.
- setDataReceiveCallback() // Returns data received from a connected Smarter Camera App via a Bluetooth or WiFi AP network interface.
- dataReceiveThread() // Reads data from a Bluetooth or WiFi AP network interface.
- connecttoWifi() // Connects to a WiFi network in Client Mode using the SSID and password received from a connected Smarter Camera App.


# How to compile your Onboarding Library.

Compile your libonboard.so by typing “make all”.


# How to test your Onboarding Library.

Compile the test application by typing “test/make all”.  This will generate a test application called “onboardtest”.  Run the test application by typing “test/onboardtest”.  

If successful, the test application will print “Your AnyConnect Onboarding Library works!”.  If not successful, the test application will print “Your AnyConnect Onboarding Library does not work.”.
