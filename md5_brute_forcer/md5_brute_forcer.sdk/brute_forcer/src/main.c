<<<<<<< HEAD
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

/*
void setHash() {
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG3_OFFSET, 0x);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG2_OFFSET, 0x);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG1_OFFSET, 0x);
	MD5_ACCELERATOR_mWriteReg(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR, MD5_ACCELERATOR_S_AXI_SLV_REG0_OFFSET, 0x);
=======
#include "xgpio.h"
#include "stdio.h"

#include "ip_md5.h"


void enable() {
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG4_OFFSET, 1);
}

void disable() {
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG4_OFFSET, 0);
}

unsigned int readStatus() {
	return IP_MD5_mReadReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG6_OFFSET );
}

unsigned int readTarget() {
	return IP_MD5_mReadReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG5_OFFSET );
}

void setHash00000000() {
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG0_OFFSET, 0xf1d3ff84);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG1_OFFSET, 0x43297732);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG2_OFFSET, 0x862df21d);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG3_OFFSET, 0xc4e57262);
}

void setHash00000100() {
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG0_OFFSET, 0x7942028e);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG1_OFFSET, 0x4d3d8fd7);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG2_OFFSET, 0xfabd1c15);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG3_OFFSET, 0x2ab4b906);
}

void setHash00000200() {
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG0_OFFSET, 0x39d0c869);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG1_OFFSET, 0xbb54e60d);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG2_OFFSET, 0xa037d9c4);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG3_OFFSET, 0x33eba1e7);
}
/*
void setHash() {
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG0_OFFSET, 0x);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG1_OFFSET, 0x);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG2_OFFSET, 0x);
	IP_MD5_mWriteReg(XPAR_IP_MD5_0_S_AXI_BASEADDR, IP_MD5_S_AXI_SLV_REG3_OFFSET, 0x);
>>>>>>> 9d536f1d62625c2791b9121b6974ca83f5266249
}
*/

void selfTest() {
	printf("MD5 Brute Forcer SelfTest\r\n");
<<<<<<< HEAD
	MD5_ACCELERATOR_Reg_SelfTest(XPAR_MD5_ACCELERATOR_0_S_AXI_BASEADDR);
}

void printStatus(const char * tab) {
        unsigned int status = readStatus();
        printf("status %s: ",tab);
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
=======
	IP_MD5_Reg_SelfTest(XPAR_IP_MD5_0_S_AXI_BASEADDR);
}

void printStatus(const char * title, const char * tab) {
	unsigned int status = readStatus();
	printf("%s%sstatus: ",title,tab);
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

void delay() {
	for (int i=0; i<59999999; i++);
>>>>>>> 9d536f1d62625c2791b9121b6974ca83f5266249
}

void checkOne(const char* msg, void * f) {
	printf(msg);
    delay();
	f;
	enable();
<<<<<<< HEAD
	printFullStatus("just enabled\r\n","   ");
	disable();
	printFullStatus("just disabled\r\n","   ");
=======
	printStatus("just enabled\r\n","   ");
	disable();
	printStatus("just disabled\r\n","   ");
>>>>>>> 9d536f1d62625c2791b9121b6974ca83f5266249
	printf("   target %x\r\n",readTarget());

}

<<<<<<< HEAD

int main(void) {
        selfTest();
        disable();
        printStatus(" - ");
        setHash00000200();
        printStatus(" ");
        while ( ! isDone()) {
                delay();
                enable();
                printf("waiting...\r\n");
                printStatus("  ");
        }
        if (isFound()) {
        	printf("target value %x\r\n", readTarget());
        } else {
        	printf("not found\r\n");
        }
        disable();

        printStatus(" - ");
        setHash00010000();
        printStatus(" ");
        while ( ! isDone()) {
                delay();
                enable();
                printf("waiting...\r\n");
                printStatus("  ");
        }
        if (isFound()) {
        	printf("target value %x\r\n", readTarget());
        } else {
        	printf("not found\r\n");
        }
        disable();

        printStatus(" - ");
        setHash01020304();
        printStatus(" ");
        while ( ! isDone()) {
                delay();
                enable();
                printf("waiting...\r\n");
                printStatus("  ");
        }
        if (isFound()) {
        	printf("target value %x\r\n", readTarget());
        } else {
        	printf("not found\r\n");
        }
        disable();


        return 0;
=======
int main (void) {


	delay();

	selfTest();

	checkOne("\r\nHash: 100\r\n", setHash00000100);
	enable();
	printStatus("should've finished...\r\n","");
	disable();

	printStatus("not running yet\r\n","");
	printf("       counter %x\r\n",readTarget());

	printStatus("about to enabled\r\n","");
	printf("       counter %x\r\n",readTarget());
	enable();
	printStatus("just enabled\r\n","   ");
	printf("       counter %x\r\n",readTarget());
	disable();

	printStatus("just disabled\r\n","");
	printf("       counter %x\r\n",readTarget());
	printStatus("expected no change\r\n","   ");
	printf("       counter %x\r\n",readTarget());
	printStatus("expected no change\r\n","   ");
	printf("       counter %x\r\n",readTarget());
	printStatus("expected no change\r\n","   ");
	printf("       counter %x\r\n",readTarget());
	enable();
	printStatus("just enabled\r\n","   ");
	printf("       counter %x\r\n",readTarget());
	disable();

	printStatus("just disabled\r\n","");
	printf("       counter %x\r\n",readTarget());
	printStatus("expected no change\r\n","   ");
	printf("       counter %x\r\n",readTarget());
	printStatus("expected no change\r\n","   ");
	printf("       counter %x\r\n",readTarget());
	printStatus("expected no change\r\n","   ");
	printf("       counter %x\r\n",readTarget());



	enable();
	printStatus("just enabled\r\n","   ");
	disable();
	printStatus("just disabled\r\n","");
	printStatus("expected no change\r\n","   ");
	printStatus("expected no change\r\n","   ");
	printStatus("expected no change\r\n","   ");


	checkOne("\r\nHash: 100\r\n", setHash00000100);
	checkOne("\r\nHash: 200\r\n", setHash00000200);

    delay();




    printf("input: %c\r\n", getchar());

    while(1) {


    }


    return 0;
/*
    printf("   status %d  alive %d\r\n",status, ++idx);
	for (i=0; i<59999999; i++);


	printf("   writing hash for 00000000...\r\n");

	printf("   hash wrote\r\n");

	for (i=0; i<59999999; i++);

	printf("   status %d  alive %d\r\n",status, ++idx);
    setHash00000100();
	printf("   about to start...\r\n");
    enable();


	for  (j=0; j< 5; j++) {
		target = readTarget();
		status = readStatus();
        printf("   status %d  alive %d target %d\r\n",status, ++idx, target);
        for (i=0; i<59999999; i++);

	}

    disable();
	while  (1) {
		target = readTarget();
		status = readStatus();
        printf("   status %d  alive %d target %d\r\n",status, ++idx, target);
        for (i=0; i<59999999; i++);

	}



	return 0;
	*/
>>>>>>> 9d536f1d62625c2791b9121b6974ca83f5266249
}
