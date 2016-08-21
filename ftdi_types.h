//=================================================================
/// \file       ftdi_types.h
/// \brief      Standard short/long definirions of FTDI types
/// \author     David Kharabadze
/// \version    16273a
/// \copyright  GNU General Public License v.3
//=================================================================
//   ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ?
// @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _
// ' a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~
//=================================================================


#pragma once
//--------------------------------------ftdi-----------------------
typedef void *	FT_HANDLE;


//--- Device status
typedef unsigned long FT_STATUS;
enum {
	FT_OK,
	FT_INVALID_HANDLE,
	FT_DEVICE_NOT_FOUND,
	FT_DEVICE_NOT_OPENED,
	FT_IO_ERROR,
	FT_INSUFFICIENT_RESOURCES,
	FT_INVALID_PARAMETER,
	FT_INVALID_BAUD_RATE,

	FT_DEVICE_NOT_OPENED_FOR_ERASE,
	FT_DEVICE_NOT_OPENED_FOR_WRITE,
	FT_FAILED_TO_WRITE_DEVICE,
	FT_EEPROM_READ_FAILED,
	FT_EEPROM_WRITE_FAILED,
	FT_EEPROM_ERASE_FAILED,
	FT_EEPROM_NOT_PRESENT,
	FT_EEPROM_NOT_PROGRAMMED,
	FT_INVALID_ARGS,
	FT_NOT_SUPPORTED,
	FT_OTHER_ERROR,
	FT_DEVICE_LIST_NOT_READY,
};

//--- Device types
typedef unsigned long FT_DEVICE;
enum {
	FT_DEVICE_BM,
	FT_DEVICE_AM,
	FT_DEVICE_100AX,
	FT_DEVICE_UNKNOWN,
	FT_DEVICE_2232C,
	FT_DEVICE_232R,
	FT_DEVICE_2232H,
	FT_DEVICE_4232H,
	FT_DEVICE_232H,
	FT_DEVICE_X_SERIES,
	FT_DEVICE_4222H_0,
	FT_DEVICE_4222H_1_2,
	FT_DEVICE_4222H_3,
    FT_DEVICE_4222_PROG,
    FT_DEVICE_900,
};
typedef struct _ft_device_list_info_node {
	unsigned long Flags;
	unsigned long Type;
	unsigned long ID;
	unsigned long LocId;
	char SerialNumber[16];
	char Description[64];
	FT_HANDLE ftHandle;
} FT_DEVICE_LIST_INFO_NODE;

// Device information flags
enum {
	FT_FLAGS_OPENED = 1,
	FT_FLAGS_HISPEED = 2
};

//-----------------------------------------------------------------

#define FT_BAUD_300			300
#define FT_BAUD_600			600
#define FT_BAUD_1200		1200
#define FT_BAUD_2400		2400
#define FT_BAUD_4800		4800
#define FT_BAUD_9600		9600
#define FT_BAUD_14400		14400
#define FT_BAUD_19200		19200
#define FT_BAUD_38400		38400
#define FT_BAUD_57600		57600
#define FT_BAUD_115200		115200
#define FT_BAUD_230400		230400
#define FT_BAUD_460800		460800
#define FT_BAUD_921600		921600

#define FT_BITS_8			(unsigned char) 8
#define FT_BITS_7			(unsigned char) 7
#define FT_STOP_BITS_1		(unsigned char) 0
#define FT_STOP_BITS_2		(unsigned char) 2
#define FT_PARITY_NONE		(unsigned char) 0
#define FT_PARITY_ODD		(unsigned char) 1
#define FT_PARITY_EVEN		(unsigned char) 2
#define FT_PARITY_MARK		(unsigned char) 3
#define FT_PARITY_SPACE		(unsigned char) 4

#define FT_FLOW_NONE		0x0000
#define FT_FLOW_RTS_CTS		0x0100
#define FT_FLOW_DTR_DSR		0x0200
#define FT_FLOW_XON_XOFF	0x0400



//
// Purge rx and tx buffers
//
#define FT_PURGE_RX			1
#define FT_PURGE_TX			2


#define FT_OPEN_BY_SERIAL_NUMBER	1
#define FT_OPEN_BY_DESCRIPTION		2
#define FT_OPEN_BY_LOCATION			4
#define FT_OPEN_MASK (FT_OPEN_BY_SERIAL_NUMBER | \
                      FT_OPEN_BY_DESCRIPTION | \
                      FT_OPEN_BY_LOCATION)

//
// FT_OpenEx Flags
//

#define FT_OPEN_BY_SERIAL_NUMBER	1
#define FT_OPEN_BY_DESCRIPTION		2
#define FT_OPEN_BY_LOCATION			4

#define FT_OPEN_MASK (FT_OPEN_BY_SERIAL_NUMBER | \
                      FT_OPEN_BY_DESCRIPTION | \
                      FT_OPEN_BY_LOCATION)

//
// FT_ListDevices Flags (used in conjunction with FT_OpenEx Flags
//

#define FT_LIST_NUMBER_ONLY			0x80000000
#define FT_LIST_BY_INDEX			0x40000000
#define FT_LIST_ALL					0x20000000

#define FT_LIST_MASK (FT_LIST_NUMBER_ONLY|FT_LIST_BY_INDEX|FT_LIST_ALL)

#define FT_BITMODE_RESET					0x00
#define FT_BITMODE_ASYNC_BITBANG			0x01
#define FT_BITMODE_MPSSE					0x02
#define FT_BITMODE_SYNC_BITBANG				0x04
#define FT_BITMODE_MCU_HOST					0x08
#define FT_BITMODE_FAST_SERIAL				0x10
#define FT_BITMODE_CBUS_BITBANG				0x20
#define FT_BITMODE_SYNC_FIFO				0x40

