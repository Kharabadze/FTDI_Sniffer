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

#pragma once

#define SIZE_OF_DLL 94

extern unsigned int lib_non_init;
extern void *procedures[SIZE_OF_DLL];

int init_library(void);
int free_library(void);

//#define MAKE_DEF_FILE //uncomment to generate .def

