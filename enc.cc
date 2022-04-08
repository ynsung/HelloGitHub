#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8	// elements of binary data array 

void Char_To_Int(char ch[], int num[], int len){
	int i=0;
	for(i=0;i<len;i++)
		num[i] = ch[i]-48;
}

void Dec_To_Bin(int decimal, int binary[]){
	int i=0;
	do{
		binary[MAX-1-i] = decimal % 2;
		decimal = decimal / 2;
		i++;
	} while(decimal != 0);
}

/*void Modulo_Two_Division(int div[], int dataword[], int codeword[], int bitNum){
	int i;
	if(bitNum == 4){
		for(i=0;i<bitNum;i++)
		
		


}

int Compute(int div[], int dataword[], int bitNum){
	int num;
	if(dataword[0] != div[0]){
		 
}
*/



int main(int argc, char *argv[]) {

	FILE *i_fp, *o_fp;
	unsigned char temp;
	int i, decData, binData[MAX], *crc, *divisor, dwSize;

	if(argc != 5)
		printf("usage : ./crc_encoder input_file output_file generator dataword_size\n");
	i_fp = fopen(argv[1],"r");
	o_fp = fopen(argv[2],"w");
	if(i_fp == NULL)
		printf("input file open error.\n");
	if(o_fp == NULL)
		printf("output file open error.\n");
	if(*argv[4] != '4' && *argv[4] != '8')
		printf("dataword size must be 4 or 8.\n");
	
	dwSize = atoi(argv[4]);
	divisor = (int *)malloc(dwSize*sizeof(int));
	Char_To_Int(argv[3],divisor,dwSize);
	crc = (int *)malloc((dwSize/4+13)*sizeof(int));	

	while((decData = fgetc(i_fp)) != EOF){
		switch(dwSize){
			case 4 :
				temp = decData; temp >> 4;
				printf("%u\n",temp);
				i = temp; printf("%d\n", i);
				temp = decData; temp << 4; temp >> 4;
				i = temp; printf("%d\n", i);
			default :
				break;	
		//Dec_To_Bin(decData, binData);
				
		//Moudulo_Two_Division(divisor, binData, crc, dwSize);
		

		//memset(binData, 0, MAX*sizeof(int));
		}
	}
	fclose(i_fp);
	fclose(o_fp);
}
