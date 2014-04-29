/*
 * display.c
 *
 *  Created on: 2014/04/20
 *      Author: kikunosu
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "func_.h"

//define
#define ARGUMENT_ERROR	10
#define MEMORY_ERROR	20

#define FILE_READ_BYNARY "rb"
#define FILE_WRITE_BYNARY "wb"

/**/
#define FILEPATH "out.txt"
//
//
//struct data_tag
//{
//	int (*func)(struct element_tag *ele);
//};
//
//typedef struct data_tag *PELEM,ELEM;

//make data
/* スクリプト言語
 * 0〜F
 * */
//4,5 /*1000〜9999 5*/
//3,5 /*100から999  5*/
//
//1,100,5
//[1-100]
//200,300,5
//[200-300]
//4,5
//[1000-9999]
//
void Fanalyze(char** buffer)
{
	printf("Fanalyze start\n");

	int icnt = 0;
	int len = strlen(buffer);
	int flag = 0;

	printf("Fanalyze end\n");

}
/*
 * int check_word
 * 	get_digit
 * 	get_string
 */
int check_word(char* str,PELEM ret)
{
	int icnt = 0;
	char* lstr = str;

	//check
	icnt = get_digit(str,&icnt,ret);

	if(icnt == -1)
	{
		printf("check_digit() error\n");
		return -1;
	}

	str = lstr;

	icnt = get_string(str,&icnt,ret);

	if(icnt == -1)
	{
		printf("check_string() error\n");
		return -1;
	}
}
//
int get_digit(char* str,int *icnt,PELEM ret)
{
	printf("get_digit start\n");
	char *buff;

	if(str == NULL)
	{
		printf("argument 1 NULL error\n");
		return -1;
	}
	if(ret == NULL)
	{
		printf("argument 2 NULL error\n");
		return -1;
	}

	buff = &str[*icnt];

	int flag = 0;
	int start = *icnt;
	int end = 0;

	while(*buff != EOF)
	{
		//space,cr+lf
		if(!isprint(buff[*icnt]))
		{
			printf("unprintable\n");
			break;
		}
		if(!isdigit(buff[*icnt]))
		{
			printf("");
			break;
		}
		if(flag == 0 && isdigit(buff[*icnt]))
		{
			start = *icnt;
			flag = 1;
		}
		else if(flag == 1 && !isdigit(buff[*icnt]))
		{
			end = *icnt;
			start = *icnt;
			//store
		}

		*icnt++;
	}

	printf("get_digit[%d] end\n",*icnt);


	return *icnt;
}
//
int get_string(char* str,int *icnt,PELEM ret)
{

}

//
unsigned char search_word;

// parameter: str[I],ret[IO]
// return: error[-1],endposition
void check_string(char* str,int *icnt,PELEM ret)
{
	printf("check_string start\n");

}
/*
 * void file_input
 * 	file_open()
 * 	get_filebuffer()
 * 	file_close()
 */
void file_input(const char *filepath,char **buffer)
{
	printf("file_input start\n");
	printf("buffer[%x]\n",buffer);

	FILE *lfp;

	lfp = file_open(filepath,FILE_READ_BYNARY);
	if(lfp == NULL)
	{
		printf("file_open error\n");
		return;
	}

	get_filebuffer(lfp,buffer);

	file_close(lfp);

	printf("file_input end\n");
}
/*
 * int get_filebuffer()
 * 	get_buffer_size
 * 	get_memory
 * 	file_read
 */
int get_filebuffer(FILE *pfp,char **buffer)
{
	printf("get_filebuffer start\n");

	printf("&buffer[%x]\n",&buffer);
	printf("buffer[%x]\n",buffer);

	if(buffer == NULL)
		return -1;

	int buffsize = 0;
	int retsize = 0;
	int ret = 0;

	buffsize = get_buffer_size(pfp);

	buffer = (char *)get_memory(buffsize);
	if(buffer == NULL)
		return -1;

	printf("malloc &buffer[%x]\n",&buffer);
	printf("malloc buffer[%x]\n",buffer);

	//retsize = file_read(buffer,sizeof(char),buffsize,pfp);
	retsize = fread(buffer,sizeof(char),buffsize,pfp);
	printf("retsize[%d];buffsize[%d]\n",retsize,buffsize);
	printf("buffer[%s]\n",buffer);

	printf("get_filebuffer end\n");
}

/*
 * void get_memory
 */
void *get_memory(const int size)
{
	return malloc(size);
}

/*
 * int get_buffer_size
 */
int get_buffer_size(const FILE *pfp)
{
	printf("get_buffer_size start\n");
	printf("pfp[%x]\n",pfp);

	FILE *lfp;
	int icnt = 0;

	lfp = pfp;

	while(fgetc(lfp) != EOF)
	{
		icnt++;
	};

	printf("pfp[%x]\n",pfp);
	printf("get_buffer_size end\n");

	return icnt;
}
/*
 * FILE *file_open
 */
FILE *file_open(const char *filepath,const char *mode)
{
	printf("file_open start\n");

	FILE *fp;

	//
	fp = fopen(filepath,mode);
	if(fp == NULL)
		printf("fopen error \n");

	printf("file_open end\n");

	return fp;
}
/*
 * int file_read
 */
int file_read(char **buff,const int size,const int count,FILE *pfp)
{
	printf("file_read start\n");
	printf("buff[%x]\n",buff);
	printf("FILE pfp[%x]\n",pfp);

	int cnt = 0;
	int ret = 0;

	cnt = fread(buff,size,count,pfp);	//buff,size,count,FILE *

	if( (ret = ferror(pfp)) != 0)
	{
		printf("fread error\n");
		printf("ret = [%d]\n",ret);
	}

	if(count != cnt)
		printf("file_read retsize[%d] != buffsize[%d] error\n",cnt,count);

	printf("file_read end\n");

	return cnt;
}

/*
 * void file_close
 */
void file_close(FILE *pfp)
{
	printf("file_close start\n");
	close(pfp);
	printf("file_close end\n");

}
/*
 * void display
 */
void display(char** buffer)
{
}

int main(int argc,char** argv)
{
	printf("display test\n");

	int icnt = 0;
	char *buffer;
	char *outbuf = "test";
	char *filepath = FILEPATH;

	printf("argc:[%d]\n",argc);

	for(icnt = 0; icnt < argc;icnt++)
	{
		//Fanalyze(argv);
		printf("argv[%d]:str[%s]:count[%d]\n",icnt,argv[icnt],strlen(argv[icnt]));
	}

	printf("buffer[%x]\n",&buffer);

	//file_output(filepath,outbuf);
	file_input(filepath,&buffer);

	return 0;
}

void file_output(char *filepath,char *buff)
{
	printf("file_output start\n");
	printf("filepath:[%s]buf[%s]\n",filepath,buff);

	FILE *pfp;
	int len = sizeof(buff);
	int ret = 0;

	printf("out buffer length[%d]\n",len);

	//
	pfp = file_open(filepath,"wb+");
	if(pfp == NULL)
	{
		printf("file_open error\n");
		return;
	}

	//write
	fwrite(buff,sizeof(char),len,pfp);

	if((ret = ferror(pfp)) != 0)
	{
		printf("ret[%d]\n",ret);
		printf("write error\n");
	}

	file_close(pfp);

	printf("file_output end\n");
}
