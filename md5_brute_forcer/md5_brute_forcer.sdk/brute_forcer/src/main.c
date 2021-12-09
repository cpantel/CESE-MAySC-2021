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
}
*/

void selfTest() {
	printf("MD5 Brute Forcer SelfTest\r\n");
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
}

void checkOne(const char* msg, void * f) {
	printf(msg);
    delay();
	f;
	enable();
	printStatus("just enabled\r\n","   ");
	disable();
	printStatus("just disabled\r\n","   ");
	printf("   target %x\r\n",readTarget());

}

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
}
