#include"ftd2xx.h"
#include"lib_work.h"

#define PROCSTART FT_STATUS rezult=0;if(lib_non_init!=0xabcdef98)init_library();
#define PROCFINISH ;//return rezult;

#define FTD2XX_API
//----------------------------------------------------------------------------
typedef FT_STATUS _stdcall (*ft_h)(FT_HANDLE);
typedef FT_STATUS _stdcall (*ft_i_h)(int,FT_HANDLE);
typedef FT_STATUS _stdcall (*ft_p_d_ph)(PVOID,DWORD,FT_HANDLE*);
typedef FT_STATUS _stdcall (*ft_p_p_d)(PVOID,PVOID,DWORD);

typedef FT_STATUS _stdcall (*ft_h_b)(FT_HANDLE,UCHAR);
typedef FT_STATUS _stdcall (*ft_h_d)(FT_HANDLE,DWORD);
typedef FT_STATUS _stdcall (*ft_h_w)(FT_HANDLE,WORD);
typedef FT_STATUS _stdcall (*ft_h_pb)(FT_HANDLE,UCHAR*);
typedef FT_STATUS _stdcall (*ft_h_pd)(FT_HANDLE,DWORD*);

typedef FT_STATUS _stdcall (*ft_h_b_b)(FT_HANDLE,UCHAR,UCHAR);
typedef FT_STATUS _stdcall (*ft_h_d_w)(FT_HANDLE,DWORD,WORD);
typedef FT_STATUS _stdcall (*ft_h_d_d)(FT_HANDLE,DWORD,DWORD);
typedef FT_STATUS _stdcall (*ft_h_d_p)(FT_HANDLE,DWORD,PVOID);
typedef FT_STATUS _stdcall (*ft_h_d_pw)(FT_HANDLE,DWORD,WORD*);
typedef FT_STATUS _stdcall (*ft_h_pb_d)(FT_HANDLE,BYTE*,DWORD);

typedef FT_STATUS _stdcall (*ft_h_b_b_b)(FT_HANDLE,BYTE,BYTE,BYTE);
typedef FT_STATUS _stdcall (*ft_h_w_b_b)(FT_HANDLE,WORD,BYTE,BYTE);
typedef FT_STATUS _stdcall (*ft_h_p_d_p)(FT_HANDLE,PVOID,DWORD,PVOID);
typedef FT_STATUS _stdcall (*ft_h_pd_pd_pd)(FT_HANDLE,DWORD*,DWORD*,DWORD*);
typedef FT_STATUS _stdcall (*ft_h_pb_d_pd)(FT_HANDLE,BYTE*,DWORD,DWORD*);

typedef FT_STATUS _stdcall (*ft_h_b_b_b_b)(FT_HANDLE,BYTE,BYTE,BYTE,BYTE);
typedef FT_STATUS _stdcall (*ft_h_d_p_d_p_d_pd_po)(FT_HANDLE,DWORD,PVOID,DWORD,PVOID,DWORD,PDWORD,LPOVERLAPPED);
typedef FT_STATUS _stdcall (*ft_h_p_d_pc_pc_pc_pc)(FT_HANDLE,void*,DWORD,char*,char*,char*,char*);
        	

typedef FT_STATUS _stdcall (*ft_h_pftpd)(FT_HANDLE, PFT_PROGRAM_DATA);
typedef FT_STATUS _stdcall (*ft_h_pftpd_pc_pc_pc_pc)(FT_HANDLE, PFT_PROGRAM_DATA,
			char*, char*, char*, char*
		);
typedef FT_STATUS _stdcall (*ft_h_pd_pd_pc_pc_p)(FT_HANDLE, DWORD*, DWORD*,
			char*, char*, void*
		);
		
//-------------WIN32		
typedef FT_HANDLE _stdcall (*fth_pcc_d_d_psa_d_d_h)(
			const char*,DWORD,DWORD,SECURITY_ATTRIBUTES*,
			DWORD,DWORD,HANDLE
		);

typedef BOOL _stdcall (*ftb_fth)(FT_HANDLE);

typedef	BOOL _stdcall (*ftb_fth_d)(
			FT_HANDLE, DWORD
		);

typedef	BOOL _stdcall (*ftb_fth_pd)(
			FT_HANDLE, LPDWORD
		);

typedef	BOOL _stdcall (*ftb_fth_pfdcb)(
			FT_HANDLE, LPFTDCB
		);
typedef	BOOL _stdcall (*ftb_fth_pftimeouts)(
			FT_HANDLE, FTTIMEOUTS*
		);

typedef	BOOL _stdcall (*ftb_fth_d_d)(
			FT_HANDLE, DWORD, DWORD
		);

typedef	BOOL _stdcall (*ftb_fth_d_po)(
			FT_HANDLE, PULONG, LPOVERLAPPED
		);

typedef BOOL _stdcall (*ftb_fth_pd_pcs)(
			FT_HANDLE, LPDWORD,	LPFTCOMSTAT
		);

typedef	BOOL _stdcall (*ftb_fth_p_d_pd_po)(
			FT_HANDLE, void*,DWORD,
			DWORD*, LPOVERLAPPED
		);
		
typedef DWORD _stdcall (*ftd_fth)(FT_HANDLE);

typedef BOOL _stdcall (*ftb_fth_po_pd_b)(
			FT_HANDLE, LPOVERLAPPED, DWORD*, BOOL
		);

//----------------------------------------------------------------------------
/*
    FTD2XX_API
        FT_STATUS WINAPI FT_Initialise(
        void
        ){
        	PROCSTART;
        	PROCFINISH;
        }

    FTD2XX_API
        void WINAPI FT_Finalise(
        void
        ){
        	PROCSTART;
        	PROCFINISH;
        }
*/
	FTD2XX_API
		FT_STATUS WINAPI FT_Open(
		int deviceNumber,
		FT_HANDLE *pHandle
		){
        	PROCSTART;
        	ft_i_h a = (ft_i_h)procedures[1];
        	rezult = a(deviceNumber, pHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_OpenEx(
		PVOID pArg1,
		DWORD Flags,
		FT_HANDLE *pHandle
		){
        	PROCSTART;
        	ft_p_d_ph a = (ft_p_d_ph)procedures[27];
        	rezult = a(pArg1, Flags, pHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API 
		FT_STATUS WINAPI FT_ListDevices(
		PVOID pArg1,
		PVOID pArg2,
		DWORD Flags
		){
        	PROCSTART;
        	ft_p_p_d a = (ft_p_p_d)procedures[28];
        	rezult = a(pArg1, pArg2, Flags);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_Close(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[2];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_Read(
		FT_HANDLE ftHandle,
		LPVOID lpBuffer,
		DWORD dwBytesToRead,
		LPDWORD lpBytesReturned
		){
        	PROCSTART;
        	ft_h_p_d_p a = (ft_h_p_d_p)procedures[3];
        	rezult = a(ftHandle,lpBuffer,dwBytesToRead,
				lpBytesReturned);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API 
		FT_STATUS WINAPI FT_Write(
		FT_HANDLE ftHandle,
		LPVOID lpBuffer,
		DWORD dwBytesToWrite,
		LPDWORD lpBytesWritten
		){
        	PROCSTART;
        	ft_h_p_d_p a = (ft_h_p_d_p)procedures[4];
        	rezult = a(
				ftHandle, lpBuffer, dwBytesToWrite,
				lpBytesWritten
			);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API 
		FT_STATUS WINAPI FT_IoCtl(
		FT_HANDLE ftHandle,
		DWORD dwIoControlCode,
		LPVOID lpInBuf,
		DWORD nInBufSize,
		LPVOID lpOutBuf,
		DWORD nOutBufSize,
		LPDWORD lpBytesReturned,
		LPOVERLAPPED lpOverlapped
		){
        	PROCSTART;
        	ft_h_d_p_d_p_d_pd_po a = (ft_h_d_p_d_p_d_pd_po)procedures[5];
        	rezult = a(
        		ftHandle, dwIoControlCode, lpInBuf,
				nInBufSize, lpOutBuf, nOutBufSize,
				lpBytesReturned, lpOverlapped
			);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetBaudRate(
		FT_HANDLE ftHandle,
		ULONG BaudRate
		){
        	PROCSTART;
        	ft_h_d a = (ft_h_d)procedures[7];
        	rezult = a(ftHandle, BaudRate);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetDivisor(
		FT_HANDLE ftHandle,
		USHORT Divisor
		){
        	PROCSTART;
        	ft_h_w a = (ft_h_w)procedures[26];
        	rezult = a(ftHandle, Divisor);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetDataCharacteristics(
		FT_HANDLE ftHandle,
		UCHAR WordLength,
		UCHAR StopBits,
		UCHAR Parity
		){
        	PROCSTART;
        	ft_h_b_b_b a = (ft_h_b_b_b)procedures[8];
        	rezult = a(ftHandle, WordLength,
				StopBits, Parity
			);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetFlowControl(
		FT_HANDLE ftHandle,
		USHORT FlowControl,
		UCHAR XonChar,
		UCHAR XoffChar
		){
        	PROCSTART;
        	ft_h_w_b_b a = (ft_h_w_b_b)procedures[9];
        	rezult = a(ftHandle, FlowControl,
				XonChar, XoffChar
			);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_ResetDevice(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[6];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetDtr(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[10];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_ClrDtr(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[11];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetRts(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[12];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_ClrRts(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[13];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetModemStatus(
		FT_HANDLE ftHandle,
		ULONG *pModemStatus
		){
        	PROCSTART;
        	ft_h_pd a = (ft_h_pd)procedures[14];
        	rezult = a(ftHandle,pModemStatus);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetChars(
		FT_HANDLE ftHandle,
		UCHAR EventChar,
		UCHAR EventCharEnabled,
		UCHAR ErrorChar,
		UCHAR ErrorCharEnabled
		){
        	PROCSTART;
        	ft_h_b_b_b_b a = (ft_h_b_b_b_b)procedures[15];
        	rezult = a(ftHandle, EventChar, EventCharEnabled,
				ErrorChar, ErrorCharEnabled
			);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_Purge(
		FT_HANDLE ftHandle,
		ULONG Mask
		){
        	PROCSTART;
        	ft_h_d a = (ft_h_d)procedures[16];
        	rezult = a(ftHandle, Mask);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetTimeouts(
		FT_HANDLE ftHandle,
		ULONG ReadTimeout,
		ULONG WriteTimeout
		){
        	PROCSTART;
        	ft_h_d_d a = (ft_h_d_d)procedures[17];
        	rezult = a(ftHandle, ReadTimeout, WriteTimeout);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetQueueStatus(
		FT_HANDLE ftHandle,
		DWORD *dwRxBytes
		){
        	PROCSTART;
        	ft_h_pd a = (ft_h_pd)procedures[18];
        	rezult = a(ftHandle,dwRxBytes);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetEventNotification(
		FT_HANDLE ftHandle,
		DWORD Mask,
		PVOID Param
		){
        	PROCSTART;
        	ft_h_d_p a = (ft_h_d_p)procedures[19];
        	rezult = a(ftHandle,Mask,Param);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetStatus(
		FT_HANDLE ftHandle,
		DWORD *dwRxBytes,
		DWORD *dwTxBytes,
		DWORD *dwEventDWord
		){
        	PROCSTART;
        	ft_h_pd_pd_pd a = (ft_h_pd_pd_pd)procedures[21];
        	rezult = a(ftHandle, dwRxBytes, dwTxBytes,
				dwEventDWord
			);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetBreakOn(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[22];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetBreakOff(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[23];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetWaitMask(
		FT_HANDLE ftHandle,
		DWORD Mask
		){
        	PROCSTART;
        	ft_h_d a = (ft_h_d)procedures[24];
        	rezult = a(ftHandle,Mask);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_WaitOnMask(
		FT_HANDLE ftHandle,
		DWORD *Mask
		){
        	PROCSTART;
        	ft_h_pd a = (ft_h_pd)procedures[25];
        	rezult = a(ftHandle,Mask);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetEventStatus(
		FT_HANDLE ftHandle,
		DWORD *dwEventDWord
		){
        	PROCSTART;
        	ft_h_pd a = (ft_h_pd)procedures[20];
        	rezult = a(ftHandle,dwEventDWord);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_ReadEE(
		FT_HANDLE ftHandle,
		DWORD dwWordOffset,
		LPWORD lpwValue
		){
        	PROCSTART;
        	ft_h_d_pw a = (ft_h_d_pw)procedures[35];
        	rezult = a(ftHandle,dwWordOffset,lpwValue);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_WriteEE(
		FT_HANDLE ftHandle,
		DWORD dwWordOffset,
		WORD wValue
		){
        	PROCSTART;
        	ft_h_d_w a = (ft_h_d_w)procedures[36];
        	rezult = a(ftHandle,dwWordOffset,wValue);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_EraseEE(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[34];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_Program(
		FT_HANDLE ftHandle,
		PFT_PROGRAM_DATA pData
		){
        	PROCSTART;
        	ft_h_pftpd a = (ft_h_pftpd)procedures[37];
        	rezult = a(ftHandle, pData);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_ProgramEx(
		FT_HANDLE ftHandle,
		PFT_PROGRAM_DATA pData,
		char *Manufacturer,
		char *ManufacturerId,
		char *Description,
		char *SerialNumber
		){
        	PROCSTART;
        	ft_h_pftpd_pc_pc_pc_pc a = (ft_h_pftpd_pc_pc_pc_pc)procedures[67];
        	rezult = a(ftHandle, pData,Manufacturer,
				ManufacturerId, Description, SerialNumber
			);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_Read(
		FT_HANDLE ftHandle,
		PFT_PROGRAM_DATA pData
		){
        	PROCSTART;
        	ft_h_pftpd a = (ft_h_pftpd)procedures[38];
        	rezult = a(ftHandle, pData);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_ReadEx(
		FT_HANDLE ftHandle,
		PFT_PROGRAM_DATA pData,
		char *Manufacturer,
		char *ManufacturerId,
		char *Description,
		char *SerialNumber
		){
        	PROCSTART;
        	ft_h_pftpd_pc_pc_pc_pc a = (ft_h_pftpd_pc_pc_pc_pc)procedures[68];
        	rezult = a(ftHandle, pData,Manufacturer,
				ManufacturerId, Description, SerialNumber
			);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_UASize(
		FT_HANDLE ftHandle,
		LPDWORD lpdwSize
		){
        	PROCSTART;
        	ft_h_pd a = (ft_h_pd)procedures[40];
        	rezult = a(ftHandle,lpdwSize);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_UAWrite(
		FT_HANDLE ftHandle,
		PUCHAR pucData,
		DWORD dwDataLen
		){
        	PROCSTART;
        	ft_h_pb_d a = (ft_h_pb_d)procedures[41];
        	rezult = a(ftHandle,pucData,dwDataLen);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_UARead(
		FT_HANDLE ftHandle,
		PUCHAR pucData,
		DWORD dwDataLen,
		LPDWORD lpdwBytesRead
		){
        	PROCSTART;
        	ft_h_pb_d_pd a = (ft_h_pb_d_pd)procedures[39];
        	rezult = a(ftHandle,pucData,dwDataLen,lpdwBytesRead);
        	PROCFINISH;
        	return rezult;
        }


	FTD2XX_API
		FT_STATUS WINAPI FT_EEPROM_Read(
		FT_HANDLE ftHandle,
		void *eepromData,
		DWORD eepromDataSize,
		char *Manufacturer,
		char *ManufacturerId,
		char *Description,
		char *SerialNumber
		){
        	PROCSTART;
        	ft_h_p_d_pc_pc_pc_pc a = (ft_h_p_d_pc_pc_pc_pc)procedures[85];
        	rezult = a(ftHandle,eepromData,eepromDataSize,Manufacturer,
				ManufacturerId,Description,SerialNumber
			);
        	PROCFINISH;
        	return rezult;
        }


	FTD2XX_API
		FT_STATUS WINAPI FT_EEPROM_Program(
		FT_HANDLE ftHandle,
		void *eepromData,
		DWORD eepromDataSize,
		char *Manufacturer,
		char *ManufacturerId,
		char *Description,
		char *SerialNumber
		){
        	PROCSTART;
        	ft_h_p_d_pc_pc_pc_pc a = (ft_h_p_d_pc_pc_pc_pc)procedures[86];
        	rezult = a(ftHandle,eepromData,eepromDataSize,Manufacturer,
				ManufacturerId,Description,SerialNumber
			);
        	PROCFINISH;
        	return rezult;
        }


	FTD2XX_API
		FT_STATUS WINAPI FT_SetLatencyTimer(
		FT_HANDLE ftHandle,
		UCHAR ucLatency
		){
        	PROCSTART;
        	ft_h_b a = (ft_h_b)procedures[29];
        	rezult = a(ftHandle, ucLatency)
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetLatencyTimer(
		FT_HANDLE ftHandle,
		PUCHAR pucLatency
		){
        	PROCSTART;
        	ft_h_pb a = (ft_h_pb)procedures[30];
        	rezult = a(ftHandle, pucLatency)
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetBitMode(
		FT_HANDLE ftHandle,
		UCHAR ucMask,
		UCHAR ucEnable
		){
        	PROCSTART;
        	ft_h_b_b a = (ft_h_b_b)procedures[31];
        	rezult = a(ftHandle, ucMask, ucEnable)
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetBitMode(
		FT_HANDLE ftHandle,
		PUCHAR pucMode
		){
        	PROCSTART;
        	ft_h_pb a = (ft_h_pb)procedures[32];
        	rezult = a(ftHandle, pucMode)
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetUSBParameters(
		FT_HANDLE ftHandle,
		ULONG ulInTransferSize,
		ULONG ulOutTransferSize
		){
        	PROCSTART;
        	ft_h_d_d a = (ft_h_d_d)procedures[33];
        	rezult = a(ftHandle, ulInTransferSize,
				ulOutTransferSize
			);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetDeadmanTimeout(
		FT_HANDLE ftHandle,
		ULONG ulDeadmanTimeout
		){
        	PROCSTART;
        	ft_h_d a = (ft_h_d)procedures[73];
        	rezult = a(ftHandle,ulDeadmanTimeout);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetDeviceInfo(
		FT_HANDLE ftHandle,
		FT_DEVICE *lpftDevice,
		LPDWORD lpdwID,
		PCHAR SerialNumber,
		PCHAR Description,
		LPVOID Dummy
		){
        	PROCSTART;
        	ft_h_pd_pd_pc_pc_p a = (ft_h_pd_pd_pc_pc_p)procedures[61];
        	rezult = a(
        		ftHandle,lpftDevice,lpdwID,
				SerialNumber,Description,Dummy
			);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_StopInTask(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[63];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_RestartInTask(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[64];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_SetResetPipeRetryCount(
		FT_HANDLE ftHandle,
		DWORD dwCount
		){
        	PROCSTART;
        	ft_h_d a = (ft_h_d)procedures[65];
        	rezult = a(ftHandle,dwCount);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_ResetPort(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[66];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_CyclePort(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ft_h a = (ft_h)procedures[69];
        	rezult = a(ftHandle);
        	PROCFINISH;
        	return rezult;
        }


	//
	// Win32-type functions
	//

	FTD2XX_API
		FT_HANDLE WINAPI FT_W32_CreateFile(
		LPCTSTR					lpszName,
		DWORD					dwAccess,
		DWORD					dwShareMode,
		LPSECURITY_ATTRIBUTES	lpSecurityAttributes,
		DWORD					dwCreate,
		DWORD					dwAttrsAndFlags,
		HANDLE					hTemplate
		){
        	PROCSTART;
        	fth_pcc_d_d_psa_d_d_h a = (fth_pcc_d_d_psa_d_d_h)procedures[42];
        	FT_HANDLE rez2 = a(
				lpszName, dwAccess, dwShareMode,
				lpSecurityAttributes, dwCreate,
				dwAttrsAndFlags, hTemplate
			);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_CloseHandle(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ftb_fth a = (ftb_fth)procedures[43];
        	BOOL rez2 = a(ftHandle);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_ReadFile(
		FT_HANDLE ftHandle,
		LPVOID lpBuffer,
		DWORD nBufferSize,
		LPDWORD lpBytesReturned,
		LPOVERLAPPED lpOverlapped
		){
        	PROCSTART;
        	ftb_fth_p_d_pd_po a = (ftb_fth_p_d_pd_po)procedures[44];
        	BOOL rez2 = a(
				ftHandle,lpBuffer,nBufferSize,
				lpBytesReturned,lpOverlapped
			);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_WriteFile(
		FT_HANDLE ftHandle,
		LPVOID lpBuffer,
		DWORD nBufferSize,
		LPDWORD lpBytesWritten,
		LPOVERLAPPED lpOverlapped
		){
        	PROCSTART;
        	ftb_fth_p_d_pd_po a = (ftb_fth_p_d_pd_po)procedures[45];
        	BOOL rez2 = a(
				ftHandle,lpBuffer,nBufferSize,
				lpBytesWritten,lpOverlapped
			);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		DWORD WINAPI FT_W32_GetLastError(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ftd_fth a = (ftd_fth)procedures[53];
        	DWORD rez2 = a(ftHandle);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_GetOverlappedResult(
		FT_HANDLE ftHandle,
		LPOVERLAPPED lpOverlapped,
		LPDWORD lpdwBytesTransferred,
		BOOL bWait
		){
        	PROCSTART;
        	ftb_fth_po_pd_b a = (ftb_fth_po_pd_b)procedures[46];
        	BOOL rez2 = a(
				ftHandle,lpOverlapped,
				lpdwBytesTransferred,bWait
			);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_CancelIo(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ftb_fth a = (ftb_fth)procedures[62];
        	BOOL rez2 = a(ftHandle);
        	PROCFINISH;
        	return rez2;
        }


	//
	// Win32 COMM API type functions
	//


	FTD2XX_API
		BOOL WINAPI FT_W32_ClearCommBreak(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ftb_fth a = (ftb_fth)procedures[47];
        	BOOL rez2 = a(ftHandle);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_ClearCommError(
		FT_HANDLE ftHandle,
		LPDWORD lpdwErrors,
		LPFTCOMSTAT lpftComstat
		){
        	PROCSTART;
        	ftb_fth_pd_pcs a = (ftb_fth_pd_pcs)procedures[48];
        	BOOL rez2 = a(ftHandle,lpdwErrors,lpftComstat);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_EscapeCommFunction(
		FT_HANDLE ftHandle,
		DWORD dwFunc
		){
        	PROCSTART;
        	ftb_fth a = (ftb_fth)procedures[49];
        	BOOL rez2 = a(ftHandle);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_GetCommModemStatus(
		FT_HANDLE ftHandle,
		LPDWORD lpdwModemStatus
		){
        	PROCSTART;
        	ftb_fth_pd a = (ftb_fth_pd)procedures[50];
        	BOOL rez2 = a(ftHandle, lpdwModemStatus);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_GetCommState(
		FT_HANDLE ftHandle,
		LPFTDCB lpftDcb
		){
        	PROCSTART;
        	ftb_fth_pfdcb a = (ftb_fth_pfdcb)procedures[51];
        	BOOL rez2 = a(ftHandle, lpftDcb);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_GetCommTimeouts(
		FT_HANDLE ftHandle,
		FTTIMEOUTS *pTimeouts
		){
        	PROCSTART;
        	ftb_fth_pftimeouts a = (ftb_fth_pftimeouts)procedures[52];
        	BOOL rez2 = a(ftHandle, pTimeouts);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_PurgeComm(
		FT_HANDLE ftHandle,
		DWORD dwMask
		){
        	PROCSTART;
        	ftb_fth_d a = (ftb_fth_d)procedures[54];
        	BOOL rez2 = a(ftHandle, dwMask);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_SetCommBreak(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	ftb_fth a = (ftb_fth)procedures[55];
        	BOOL rez2 = a(ftHandle);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_SetCommMask(
		FT_HANDLE ftHandle,
		ULONG ulEventMask
		){
        	PROCSTART;
        	ftb_fth_d a = (ftb_fth_d)procedures[56];
        	BOOL rez2 = a(ftHandle, ulEventMask);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_GetCommMask(
		FT_HANDLE ftHandle,
		LPDWORD lpdwEventMask
		){
        	PROCSTART;
        	ftb_fth_pd a = (ftb_fth_pd)procedures[77];
        	BOOL rez2 = a(ftHandle, lpdwEventMask);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_SetCommState(
		FT_HANDLE ftHandle,
		LPFTDCB lpftDcb
		){
        	PROCSTART;
        	ftb_fth_pfdcb a = (ftb_fth_pfdcb)procedures[57];
        	BOOL rez2 = a(ftHandle, lpftDcb);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_SetCommTimeouts(
		FT_HANDLE ftHandle,
		FTTIMEOUTS *pTimeouts
		){
        	PROCSTART;
        	ftb_fth_pftimeouts a = (ftb_fth_pftimeouts)procedures[58];
        	BOOL rez2 = a(ftHandle, pTimeouts);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_SetupComm(
		FT_HANDLE ftHandle,
		DWORD dwReadBufferSize,
		DWORD dwWriteBufferSize
		){
        	PROCSTART;
        	ftb_fth_d_d a = (ftb_fth_d_d)procedures[59];
        	BOOL rez2 = a(ftHandle, dwReadBufferSize, dwWriteBufferSize);
        	PROCFINISH;
        	return rez2;
        }

	FTD2XX_API
		BOOL WINAPI FT_W32_WaitCommEvent(
		FT_HANDLE ftHandle,
		PULONG pulEvent,
		LPOVERLAPPED lpOverlapped
		){
        	PROCSTART;
        	ftb_fth_d_po a = (ftb_fth_d_po)procedures[60];
        	BOOL rez2 = a(ftHandle, pulEvent, lpOverlapped);
        	PROCFINISH;
        	return rez2;
        }


	//
	// Device information
	//


	FTD2XX_API
		FT_STATUS WINAPI FT_CreateDeviceInfoList(
		LPDWORD lpdwNumDevs
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetDeviceInfoList(
		FT_DEVICE_LIST_INFO_NODE *pDest,
		LPDWORD lpdwNumDevs
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetDeviceInfoDetail(
		DWORD dwIndex,
		LPDWORD lpdwFlags,
		LPDWORD lpdwType,
		LPDWORD lpdwID,
		LPDWORD lpdwLocId,
		LPVOID lpSerialNumber,
		LPVOID lpDescription,
		FT_HANDLE *pftHandle
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }


	//
	// Version information
	//

	FTD2XX_API
		FT_STATUS WINAPI FT_GetDriverVersion(
		FT_HANDLE ftHandle,
		LPDWORD lpdwVersion
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetLibraryVersion(
		LPDWORD lpdwVersion
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }


	FTD2XX_API
		FT_STATUS WINAPI FT_Rescan(
		void
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_Reload(
		WORD wVid,
		WORD wPid
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetComPortNumber(
		FT_HANDLE ftHandle,
		LPLONG	lpdwComPortNumber
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }


	//
	// FT232H additional EEPROM functions
	//

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_ReadConfig(
		FT_HANDLE ftHandle,
		UCHAR ucAddress,
		PUCHAR pucValue
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_WriteConfig(
		FT_HANDLE ftHandle,
		UCHAR ucAddress,
		UCHAR ucValue
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_EE_ReadECC(
		FT_HANDLE ftHandle,
		UCHAR ucOption,
		LPWORD lpwValue
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_GetQueueStatusEx(
		FT_HANDLE ftHandle,
		DWORD *dwRxBytes
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_ComPortIdle(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_ComPortCancelIdle(
		FT_HANDLE ftHandle
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_VendorCmdGet(
		FT_HANDLE ftHandle,
		UCHAR Request,
		UCHAR *Buf,
		USHORT Len
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_VendorCmdSet(
		FT_HANDLE ftHandle,
		UCHAR Request,
		UCHAR *Buf,
		USHORT Len
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_VendorCmdGetEx(
		FT_HANDLE ftHandle,
		USHORT wValue,
		UCHAR *Buf,
		USHORT Len
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

	FTD2XX_API
		FT_STATUS WINAPI FT_VendorCmdSetEx(
		FT_HANDLE ftHandle,
		USHORT wValue,
		UCHAR *Buf,
		USHORT Len
		){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
        }

//---

	FTD2XX_API
		FT_STATUS WINAPI _FT_Initialise(void){
        	PROCSTART;
        	PROCFINISH;
        	return rezult;
		}

	FTD2XX_API
		void WINAPI _FT_Finalise(void){
        	PROCSTART;
        	PROCFINISH;
        	return;
		}

#undef FTD2XX_API
