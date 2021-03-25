// Mbed CMake Template
// Copyright 2020 Ladislas de Toldi (ladislas [at] detoldi.me)
// SPDX-License-Identifier: Apache-2.0

#include "mbed.h"

#include "HelloWorld.h"

HelloWorld hello;

static BufferedSerial serial(USBTX, USBRX, 115200);

constexpr uint8_t buff_size = 80;
char buff[buff_size] {};

void foo(int x)
{
	int buf[10];
	if (x == 1000) buf[x] = 0;	 // <- ERROR
}

void bar(int x)
{
	int buf[10];
	buf[x] = 0;	  // <- ERROR
	if (x == 1000) {
	}
}

uint8_t BSP_SDRAM_ReadData_DMA(uint32_t uwStartAddress, uint32_t *pData, uint32_t uwDataSize)
{
	if (true) {
		return 1;
	} else {
		return 0;
	}
}

int main(void)
{
	auto start = Kernel::Clock::now();

	hello.start();

	while (true) {
		auto t = Kernel::Clock::now() - start;

		bar(11);
		foo(2);

		int c_size =
			sprintf(buff, "A message from your board --> \"%s\" at %i s\n", hello.world, int(t.count() / 1000));

		serial.write(buff, c_size);
		rtos::ThisThread::sleep_for(1s);
	}

	return 0;
}
