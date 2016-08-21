//=================================================================
/// \file       dllmain.cpp
/// \brief      DLL for sniffer of FTDI FTD2XX
/// \author     David Kharabadze
/// \version    16273a
/// \copyright  GNU General Public License v.3
//=================================================================
//   ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ?
// @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _
// ' a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~
//=================================================================


#include "dll.h"

#include"lib_work.h"

#include <windows.h>
#include <stdio.h>





BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			//printf("INIT MY LIB\n");
			//make_def_file();
			//init_library();
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			//free_library();
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}
