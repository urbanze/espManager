#ifndef espManager_H
#define espManager_H

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>


class espManager
{
public:
	void begin();
	

private:
	String name, pass, req;
	long lm;
};

#endif