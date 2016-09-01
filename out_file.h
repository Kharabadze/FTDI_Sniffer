//=================================================================
/// \file       out_file.h
/// \brief      Output file for sniffer of FTDI FTD2XX
/// \author     David Kharabadze
/// \version    16354a
/// \copyright  GNU General Public License v.3
//=================================================================
//   ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ?
// @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _
// ' a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~
//=================================================================

#pragma once

void file_open(void);
void file_finish(void);
void file_process_func(const char *func_name,bool start);
void file_process_data10(const char *func_name,const char *string,int value);
void file_process_buffer16(const char *func_name, unsigned int data_size, unsigned char *data_value);

