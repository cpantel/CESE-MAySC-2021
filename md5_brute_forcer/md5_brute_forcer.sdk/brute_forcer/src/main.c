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

void setHash00000100() {
	// 2ab4b906fabd1c154d3d8fd77942028e
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG3_OFFSET, 0x2ab4b906);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG2_OFFSET, 0xfabd1c15);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG1_OFFSET, 0x4d3d8fd7);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG0_OFFSET, 0x7942028e);
}

void setHash00000200() {
	// 33eba1e7a037d9c4bb54e60d39d0c869
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG3_OFFSET, 0x33eba1e7);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG2_OFFSET, 0xa037d9c4);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG1_OFFSET, 0xbb54e60d);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG0_OFFSET, 0x39d0c869);
}

void setHash00000201() {
        // e551bba285ac1be5eb49d8030c49a274
        //
        MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG3_OFFSET, 0xe551bba2);
        MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG2_OFFSET, 0x85ac1be5);
        MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG1_OFFSET, 0xeb49d803);
        MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG0_OFFSET, 0x0c49a274);
}

void setHash00010000() {
	// 03bf3e510fa084f991c7a5e607d9712b
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG3_OFFSET, 0x03bf3e51);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG2_OFFSET, 0x0fa084f9);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG1_OFFSET, 0x91c7a5e6);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG0_OFFSET, 0x07d9712b);
}

void setHash01020304() {
	// 08d6c05a21512a79a1dfeb9d2a8f262f
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG3_OFFSET, 0x08d6c05a);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG2_OFFSET, 0x21512a79);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG1_OFFSET, 0xa1dfeb9d);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG0_OFFSET, 0x2a8f262f);
}


void setHashffffffff() {
	// a54f0041a9e15b050f25c463f1db7449
	//
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG3_OFFSET, 0xa54f0041);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG2_OFFSET, 0xa9e15b05);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG1_OFFSET, 0x0f25c463);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG0_OFFSET, 0xf1db7449);
}

void setHashf0000000() {
	// 0290a09d67739bb3a69914532acfaf2d
	//
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG3_OFFSET, 0x0290a09d);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG2_OFFSET, 0x67739bb3);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG1_OFFSET, 0xa6991453);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG0_OFFSET, 0x2acfaf2d);
}

/*
void setHash() {
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG3_OFFSET, 0x);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG2_OFFSET, 0x);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG1_OFFSET, 0x);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG0_OFFSET, 0x);
}
*/

void selfTest() {
	printf("MD5 Brute Forcer SelfTest\r\n");
	MD5_ACCELERATOR_Reg_SelfTest(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR);
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
        if (status & 0xffffffc0) printf("errorExtraBits ");
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
    	printf("  found %x\r\n\r\n", readTarget());
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
        selfTest();


        printf("searching for 00000200...\r\n");
        disable();
        setHash00000200();
        printStatus("  status:");
        enable();
        printStatus("  status:");
        wait();
        printStatus("  status:");
        printResults();
        disable();

        printf("searching for 00000201...\r\n");
        disable();
        setHash00000201();
        printStatus("  status:");
        enable();
        printStatus("  status:");
        wait();
        printStatus("  status:");
        printResults();
        disable();

        printf("searching for 00010000...\r\n");
        disable();
        setHash00010000();
        printStatus("  status:");
        enable();
        printStatus("  status:");
        wait();
        printStatus("  status:");
        printResults();
        disable();

        printf("searching for 01020304...\r\n");
        disable();
        setHash01020304();
        printStatus("  status:");
        enable();
        printStatus("  status:");
        wait();
        printStatus("  status:");
        printResults();
        disable();


        printf("searching for f0000000...\r\n");
        disable();
        setHashf0000000();
        printStatus("  status:");
        enable();
        printStatus("  status:");
        wait();
        printStatus("  status:");
        printResults();
        disable();

        printf("searching for ffffffff...\r\n");
        disable();
        setHashffffffff();
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
