//=================================================================
/// \file       lib_work.cpp
/// \brief      Functions for loading FTD2XX
/// \author     David Kharabadze
/// \version    16273a
/// \copyright  GNU General Public License v.3
//=================================================================
//   ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ?
// @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _
// ' a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~
//=================================================================

#include"lib_work.h"

#include<windows.h>
#ifdef MAKE_DEF_FILE
#include<stdio.h>
#endif

#define SIZE_OF_DLL 94

unsigned int lib_non_init=0x12345678;
void *procedures[SIZE_OF_DLL];

struct tDllInfo{
	const char *func_name;
	int bytes_in_stack;
};

tDllInfo DllInfo[SIZE_OF_DLL]={
	{"SPECIAL_TABLE",-1},//0
	{"FT_Open",8},//1
	{"FT_Close",4},//2
	{"FT_Read",16},//3
	{"FT_Write",16},//4
	{"FT_IoCtl",32},//5
	{"FT_ResetDevice",4},//6
	{"FT_SetBaudRate",8},//7
	{"FT_SetDataCharacteristics",16},//8
	{"FT_SetFlowControl",16},//9
	
	{"FT_SetDtr",4},//10
	{"FT_ClrDtr",4},//11
	{"FT_SetRts",4},//12
	{"FT_ClrRts",4},//13
	{"FT_GetModemStatus",8},//14
	{"FT_SetChars",20},//15
	{"FT_Purge",8},//16
	{"FT_SetTimeouts",12},//17
	{"FT_GetQueueStatus",8},//18
	{"FT_SetEventNotification",12},//19
	
	{"FT_GetEventStatus",8},//20
	{"FT_GetStatus",16},//21
	{"FT_SetBreakOn",4},//22
	{"FT_SetBreakOff",4},//23
	{"FT_SetWaitMask",8},//24
	{"FT_WaitOnMask",8},//25
	{"FT_SetDivisor",8},//26
	{"FT_OpenEx",12},//27
	{"FT_ListDevices",12},//28
	{"FT_SetLatencyTimer",8},//29
	
	{"FT_GetLatencyTimer",8},//30
	{"FT_SetBitMode",12},//31
	{"FT_GetBitMode",8},//32
	{"FT_SetUSBParameters",12},//33
	{"FT_EraseEE",4},//34
	{"FT_ReadEE",12},//35
	{"FT_WriteEE",12},//36
	{"FT_EE_Program",8},//37
	{"FT_EE_Read",8},//38
	{"FT_EE_UARead",16},//39
	
	{"FT_EE_UASize",8},//40
	{"FT_EE_UAWrite",12},//41
	{"FT_W32_CreateFile",28},//42
	{"FT_W32_CloseHandle",4},//43
	{"FT_W32_ReadFile",20},//44
	{"FT_W32_WriteFile",20},//45
	{"FT_W32_GetOverlappedResult",16},//46
	{"FT_W32_ClearCommBreak",4},//47
	{"FT_W32_ClearCommError",12},//48
	{"FT_W32_EscapeCommFunction",8},//49

	{"FT_W32_GetCommModemStatus",8},//50
	{"FT_W32_GetCommState",8},//51
	{"FT_W32_GetCommTimeouts",8},//52
	{"FT_W32_GetLastError",4},//53
	{"FT_W32_PurgeComm",8},//54
	{"FT_W32_SetCommBreak",4},//55
	{"FT_W32_SetCommMask",8},//56
	{"FT_W32_SetCommState",8},//57
	{"FT_W32_SetCommTimeouts",8},//58
	{"FT_W32_SetupComm",12},//59

	{"FT_W32_WaitCommEvent",12},//60
	{"FT_GetDeviceInfo",24},//61
	{"FT_W32_CancelIo",4},//62
	{"FT_StopInTask",4},//63
	{"FT_RestartInTask",4},//64
	{"FT_SetResetPipeRetryCount",8},//65
	{"FT_ResetPort",4},//66
	{"FT_EE_ProgramEx",24},//67
	{"FT_EE_ReadEx",24},//68
	{"FT_CyclePort",4},//69

	{"FT_CreateDeviceInfoList",4},//70
	{"FT_GetDeviceInfoList",8},//71
	{"FT_GetDeviceInfoDetail",32},//72
	{"FT_SetDeadmanTimeout",8},//73
	{"_FT_Finalise@0",0},//74
	{"FT_GetDriverVersion",8},//75
	{"FT_GetLibraryVersion",4},//76
	{"FT_W32_GetCommMask",8},//77
	{"FT_Rescan",0},//78
	{"FT_Reload",8},//79

	{"FT_GetComPortNumber",8},//80
	{"FT_EE_ReadConfig",12},//81
	{"FT_EE_WriteConfig",12},//82
	{"FT_EE_ReadECC",12},//83
	{"FT_GetQueueStatusEx",8},//84
	{"FT_EEPROM_Read",28},//85
	{"FT_EEPROM_Program",28},//86
	{"FT_ComPortIdle",4},//87
	{"FT_ComPortCancelIdle",4},//88
	{"FT_VendorCmdGet",16},//89

	{"FT_VendorCmdSet",16},//90
	{"FT_VendorCmdGetEx",16},//91
	{"FT_VendorCmdSetEx",16},//92
	{"_FT_Initialise@0",0}//93

};
//------------------------------------------- Process library
int make_def_file(void){
#ifdef MAKE_DEF_FILE
	FILE *f86 =fopen("Sniffer_x86.def","wt");
	FILE *f64 =fopen("Sniffer_x64.def","wt");
	fprintf(f86,"EXPORTS\n");fprintf(f64,"EXPORTS\n");
	for(int i=1;i<SIZE_OF_DLL;i++){
		if((i==74)||(i==93)){
			fprintf(f86,"    %s = %s @%i\n",DllInfo[i].func_name, DllInfo[i].func_name, i);
			fprintf(f64,"    %s @%i\n",DllInfo[i].func_name, i);
		}else{
			fprintf(f86,"    %s = %s@%i @%i\n",DllInfo[i].func_name,DllInfo[i].func_name,DllInfo[i].bytes_in_stack, i);
			fprintf(f64,"    %s @%i\n",DllInfo[i].func_name, i);
		}
	}
	fclose(f86);
	fclose(f64);
#endif
	return 0;
}

int init_library(void){
	if(lib_non_init==0xabcdef98) return 0;//skip if initialized
	lib_non_init=0xabcdef98;
	
#ifdef MAKE_DEF_FILE
	make_def_file();
#endif
	
	//procedures=new(void*[SIZE_OF_DLL]);
	procedures[0]=(void*)new(HMODULE);
	HMODULE &hModule=*(HMODULE*)procedures[0];
	
	hModule=LoadLibrary("ftd2xx_orig.dll");
#ifdef _WIN64
	long long i;
#else
#ifdef _WIN32
	long i;
#else
	;//Unknown system
#endif
#endif
	for(i=1;i<SIZE_OF_DLL;i++){
		procedures[i]=0;
		void*p1=0,*p2=0;
		p1=(void*)GetProcAddress(hModule,DllInfo[i].func_name);
		if(p1==0)continue;
		p2=(void*)GetProcAddress(hModule,(LPCSTR)i);
		if(p1!=p2)continue;
		procedures[i]=p1;
		//printf("%i) %08x\n",i,procedures[i]);
	}
	//test important procedures
	int imp[]={1,2,3,4,7,8};
	for(int i=0;i<(sizeof(imp)/sizeof(int));i++)
		if(procedures[imp[i]]==0)return 1;
	return 0;
}

int free_library(void){
	HMODULE &hModule=*(HMODULE*)procedures[0];
	if(hModule)FreeLibrary(hModule);
	delete[] ((HMODULE*)procedures[0]);
	//if(procedures)delete[](procedures);
	return 0;
}


