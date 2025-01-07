#ifndef UTILS_H
#define UTILS_H

void printUsage(){
	printf("MultiScan Version 1.0 Usage:\n\n"
		   "--tcp - Does a sipmle TCP Connection Request."\n"
	   	   "--tcp <Host> <Port or Port Range>\n"
		   "Example: --tcp 192.168.1.1 1-80\n\n"

		   "--udp - Sends a UDP packet.\n"
		   "--udp <Host> <Port or Port Rnage>\n"
		   "Example: --udp 192.168.1.1 1-80\n"
			
			"--cust - Sends a packet with user defined flags.\n"	   
			"Flags are separated by '/'"
			"--raw <Host> <Port or Port Range> <URG/ACK/PSH/RST/SYN/FIN>\n"
			"Example: --raw 192.168.1.1 1-80 SYN/ACK\n\n");
}


#endif
