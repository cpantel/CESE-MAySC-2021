#include "stdio.h"
#include "xgpio.h"
#include "MD5_Accelerator.h"

void enable() {
        MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG4_OFFSET, 1);
}

void disable() {
        MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG4_OFFSET, 0);
}

unsigned int readStatus() {
        return MD5_ACCELERATOR_mReadReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG6_OFFSET );
}

unsigned int readTarget() {
        return MD5_ACCELERATOR_mReadReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG5_OFFSET );
}

unsigned int readPipelineCount() {
	unsigned int status = readStatus();
	return ( status & 0x0000f000 ) >>12;

}

unsigned int readPipelineHit() {
	unsigned int status = readStatus();
	return status >> 16;
}

unsigned int getVersion() {
	unsigned int status = readStatus();
	return ( status & 0x00000f00 ) >>8;
}

void setHash(unsigned int r3, unsigned int r2, unsigned int r1,unsigned int r0) {
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG3_OFFSET, r3);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG2_OFFSET, r2);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG1_OFFSET, r1);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG0_OFFSET, r0);
}

void selfTest() {
	printf("MD5 Brute Forcer SelfTest\r\n");
	MD5_ACCELERATOR_Reg_SelfTest(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR);
}
void dumpStatus() {
	printf("Status: %x\r\n",readStatus());
}

void printStatus(const char * tab) {
	unsigned int status = readStatus();
	printf("%s",tab);
	if (status & 0x1)  printf("paused ");
	if (status & 0x2)  printf("running ");
	if (status & 0x4)  printf("warming ");
	if (status & 0x8)  printf("found ");
	if (status & 0x10) printf("done ");
	if (status & 0x20) printf("enabled ");
	if (status == 0) printf("errorNoStatus ");

	printf("\r\n");
}

int isDone() {
	unsigned int status = readStatus();
	return (status & 0x10);
}

int isFound() {
	unsigned int status = readStatus();
	return (status & 0x8);
}

void printFullStatus(const char * title, const char * tab) {
	printf("%s ",title);
	printStatus(tab);
}

void delay() {
    for (int i=0; i<59999999; i++);
}

void longDelay() {
    for (int i=0; i<599999999; i++);
}

void printResults() {
    if (isFound()) {
    	printf("  found %x at pipeline %d of %d\r\n\r\n", readTarget(), readPipelineHit(), readPipelineCount());
    } else {
    	printf("  not found\r\n\r\n");
    }
}

void wait() {
	int count = 0;
    while ( ! isDone()) {
        delay();
        ++count;
    }
	printf("  waited %d\r\n", count);
 }

int main(void) {

	// setHash(0x2ab4b906, 0xfabd1c15, 0x4d3d8fd7, 0x7942028e); // 00000100
	selfTest();

	printf("\r\n\r\n");
	printf("Hardware Version %d\r\n", getVersion());
	printf("\r\n\r\n");

	printf("searching for 00000200...\r\n");
	disable();
	setHash(0x33eba1e7, 0xa037d9c4, 0xbb54e60d, 0x39d0c869); // 00000200
	printStatus("  status:");
	enable();
	printStatus("  status:");
	wait();
	printStatus("  status:");
	printResults();
	disable();

	printf("searching for 00000201...\r\n");
	disable();
	setHash(0xe551bba2, 0x85ac1be5, 0xeb49d803, 0x0c49a274); // 00000201
	printStatus("  status:");
	enable();
	printStatus("  status:");
	wait();
	printStatus("  status:");
	printResults();
	disable();

	printf("searching for 00000202...\r\n");
	disable();
	setHash(0x99aabd57, 0x4bed99e3, 0x8ef83748, 0x1e090d19); // 00000202
	printStatus("  status:");
	enable();
	printStatus("  status:");
	wait();
	printStatus("  status:");
	printResults();
	disable();

	printf("searching for 00000203...\r\n");
	disable();
	setHash(0xa1fc98e2, 0x9a2e11af, 0x5c327fad, 0x943b4766); // 00000203
	printStatus("  status:");
	enable();
	printStatus("  status:");
	wait();
	printStatus("  status:");
	printResults();
	disable();

	printf("searching for 00010000...\r\n");
	disable();
	setHash(0x03bf3e51, 0x0fa084f9, 0x91c7a5e6, 0x07d9712b); //h00010000
	printStatus("  status:");
	enable();
	printStatus("  status:");
	wait();
	printStatus("  status:");
	printResults();
	disable();

	printf("searching for 01020304...\r\n");
	disable();
	setHash(0x08d6c05a, 0x21512a79, 0xa1dfeb9d, 0x2a8f262f); //01020304
	printStatus("  status:");
	enable();
	printStatus("  status:");
	wait();
	printStatus("  status:");
	printResults();
	disable();


	printf("searching for f0000000...\r\n");
	disable();
	setHash(0x0290a09d, 0x67739bb3, 0xa6991453, 0x2acfaf2d); //f0000000
	printStatus("  status:");
	enable();
	printStatus("  status:");
	wait();
	printStatus("  status:");
	printResults();
	disable();

	printf("searching for ffffffff...\r\n");
	disable();
	setHash(0xa54f0041, 0xa9e15b05, 0x0f25c463, 0xf1db7449); //ffffffff
	printStatus("  status:");
	enable();
	printStatus("  status:");
	wait();
	printStatus("  status:");
	printResults();
	disable();


	printf("idle\r\n");
	while (1) {}


	return 0;
}
