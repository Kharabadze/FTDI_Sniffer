//=================================================================
/// \file       out_file.cpp
/// \brief      Output file for sniffer of FTDI FTD2XX
/// \author     David Kharabadze
/// \version    16354a
/// \copyright  GNU General Public License v.3
//=================================================================
//   ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ?
// @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _
// ' a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~
//=================================================================

#include"out_file.h"

#include<stdio.h>

FILE *f;

void file_open(void){
	char file_name[1024]="";
	f=fopen("snifconf.txt","rb");
	int i=0;
	while(1){
		char c =0;
		file_name[i]=0;
		if((i+1)==sizeof(file_name))break;
		if(fread(&c,1,1,f)==0)break;
		if(c<' ')break;
		file_name[i]=c;
		i++;
	}
	fclose(f);
	f=fopen(file_name,"wt");
	fprintf(f,"FTDI Sniffer (x%i)\n",8*sizeof(void*));
	fprintf(f,"Build: %s, %s\n", __DATE__,__TIME__);
	fprintf(f,"-----------------------------\n");
	return;
}

void file_finish(void){
	if(f==0)return;
	fclose(f);
	return;
}

void file_process_func(const char *func_name, bool start){
	if(f==0)return;
	if(start)
		fprintf(f,"Start of function: %s\n",func_name);
	else
		fprintf(f,"Finish of function: %s\n",func_name);
	fflush(f);
	return;
}

void file_process_data10(const char *func_name,const char *string,int value){
	if(f==0)return;
	fprintf(f,"  <%s>: ",func_name);
	fprintf(f,string,value);
	fflush(f);
	return;
}

void file_process_buffer16(const char *func_name, unsigned int data_size, unsigned char *data_value){
	if(f==0)return;
	for(int i=0,j=0;i<data_size;i++){
		if(j==0)fprintf(f,"  <%s>:",func_name);
		fprintf(f," %02x",data_value[i]);
		if((j==15)||(i==(data_size-1)))fprintf(f,"\n");
		(j+=1)&=0xf;
	}
	fflush(f);
	return;
}


