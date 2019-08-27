
#include <iostream>
#include <unistd.h>
#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"DHT/dht_read.h"
#include "i2c-exp-driver/onion-i2c.h"
#include "i2c-exp-driver/relay-exp.h"



const uint8_t LED_PIN = 0;

int main() {
	// LED blynk
	//=========================================================================
	/*Gpio::initialize();
	// set the pin mode to output, so that we can digitalWrite() it

	Gpio::pinMode(LED_PIN, 1);

	// by the default our led is set to be on
	bool ledStatus = true;

	while (true) {
		// toggle the pin
		Gpio::digitalWrite(LED_PIN, ledStatus);

		// and wait 500 ms
		usleep(500 * 1000);

		ledStatus = !ledStatus;vg
	}*/

	//===============================================================
	//Getting temperature and humidity from DHT11
	
	/*int maxRetry = 3;
	float humidity = 0.0f, temperature = 0.0f;
	int result = 0;
	do
	{
		
		
		result = dht_read(DHT11, 0, &humidity, &temperature);
		
		
		maxRetry--;
	} while (result != 0 && maxRetry > 0);

	//printf("%f\n%f\n", humidity, temperature);
	
	//system("relay-exp -i");
	//system("relay-exp 0 0");
	while (1)
	{
		result = dht_read(DHT11, 0, &humidity, &temperature);
		if (temperature > 29)
		{
			system("relay-exp 0 1"); //using relay exp by console commands
		}
		else system("relay-exp 0 0");
		usleep(1000000);
	}*/
	//===================================================================

	//led blynk by using the Relay Expansion
	relayDriverInit(7);
	for (int i = 0; i < 10; i++)
	{
		relaySetChannel(7, 0, 1);
		usleep(500000);
		relaySetChannel(7, 0, 0);
		usleep(500000);
	}
}
