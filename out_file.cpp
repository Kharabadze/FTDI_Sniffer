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
	fprintf(f,"<%s>:",func_name);
	fprintf(f,string,value);
	fflush(f);
	return;
}

void file_process_byte16(const char *string,unsigned char value){
	if(f==0)return;
	fflush(f);
	return;
}


