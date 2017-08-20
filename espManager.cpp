#include <espManager.h>
#ifdef  ARDUINO_ESP8266_ESP01
#define LED 1
#elif ARDUINO_ESP8266_NODEMCU
#define LED D4         
#endif 


WiFiUDP udp;



void espManager::begin()
{
	pinMode(LED, OUTPUT);
	name = ""; pass = ""; req = "";
	WiFi.mode(WIFI_AP_STA);
	WiFi.disconnect();
	WiFi.softAP("WiFi_Manager", "");
	udp.begin(555);

	while (WiFi.status() != WL_CONNECTED)
	{
		if (millis() - lm > 500)
		{
			GPO ^= 1 << LED;
			lm = millis();
		}

		if (udp.parsePacket() > 0) 
		{
			req = "";
			while (udp.available() > 0)
			{
				char z = udp.read();
				req += z;
			}

			if (req.equals("SCAN") == true)
			{
				String a = "";

				byte x = WiFi.scanNetworks();

				a += "@"; a += x; a += ";";
				for (byte i = 0; i < x; i++)
				{
					a += "#";
					a += WiFi.SSID(i);
					a += ";";
				}
				

				udp.beginPacket(udp.remoteIP(), 1200);
				udp.print(a);
				udp.endPacket();
			}

			else if (req.equals("CONNECT") == true)
			{
				int x = 0;
				
				
				if		(pass.length() > 5 && name.length() > 5)
				{
					WiFi.begin(name.c_str(), pass.c_str());
				}
				else if (pass.length() < 6 && name.length() > 5)
				{
					WiFi.begin(name.c_str(), NULL);
				}
				else if (name.length() < 6 && pass.length() > 5)
				{
					WiFi.begin(NULL, pass.c_str());
				}
				
				

				while (WiFi.status() != WL_CONNECTED)
				{
					x++;
					GPO ^= 1 << LED;
					delay(100);

					if (x > 49)
					{
						break;
					}

				}
			}

			else if (req.indexOf("NAME=") > -1)
			{
				if (req.length() > 5)
				{
					name = req.substring(5);
				}
				else
				{
					name = "";
				}
			}
			else if (req.indexOf("PASS=") > -1)
			{
				pass = req.substring(5);
			}

			else
			{
				udp.beginPacket(udp.remoteIP(), 1200);
				udp.print("??" + req);
				udp.endPacket();
			}
		}
		yield();
	}
	udp.stop();
	WiFi.softAPdisconnect();
	WiFi.mode(WIFI_STA);
	digitalWrite(LED, 0);
}