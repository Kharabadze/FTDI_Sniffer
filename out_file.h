#pragma once

void file_open(void);
void file_finish(void);
void file_process_func(const char *func_name,bool start);
void file_process_data10(const char *func_name,const char *string,int value);
void file_process_byte16(const char *func_name,const char *string,int value);

