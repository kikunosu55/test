/*
 * func_.h
 *
 *  Created on: 2014/04/28
 *      Author: katsufujiseigo
 */

#ifndef FUNC__H_
#define FUNC__H_

struct data_tag
{
	int (*func)(struct element_tag *ele);
};

typedef struct data_tag *PELEM,ELEM;

void Fanalyze(char** buffer);
int get_digit(char* str,int *icnt,PELEM ret);
int get_string(char* str,int *icnt,PELEM ret);
void check_string(char* str,int *icnt,PELEM ret);
void file_input(const char *filepath,char **buffer);
int get_filebuffer(FILE *pfp,char **buffer);
void *get_memory(const int size);
int get_buffer_size(const FILE *pfp);
FILE *file_open(const char *filepath,const char *mode);
int file_read(char **buff,const int size,const int count,FILE *pfp);
void file_output(char *filepath,char *buff);
void file_close(FILE *pfp);
void display(char **buffer);

#endif /* FUNC__H_ */
