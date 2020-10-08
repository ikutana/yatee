#include <stdio.h>
#include <stdlib.h>
#define	FILE_OPEN_ERROR	1

void usage()
{
	printf("usage: yetee [-a|-h] FileName\n");
	exit(0);
}

int main(int argc, char* argv[])
{
	int	tmp;
	FILE	*fp;

	int argp=1;
	int appendMode = false;
	int teeMode = false;
	char *FileName;
	while (argp < argc)
	{
		if (argv[argp][0]=='-')
		{
			if (argv[argp][1]=='a')
				appendMode = true;
			if (argv[argp][1]=='h')
				usage();
		}
		else
		{
			FileName = argv[argp];
			teeMode = true;
		}
		if (FileName != NULL)
			break;
		argp++;
	}

	if (FileName != NULL)
	{
		fp = fopen(FileName, appendMode?"a":"w");
		if (fp == NULL)
		{
			fprintf(stderr, "File Open Error¥n");
			return FILE_OPEN_ERROR;
		}
	}

	while(!feof(stdin))
	{
		tmp=fgetc(stdin);
		fputc(tmp,stdout);
		if(fp != NULL) fputc(tmp,fp);
	}
	return 0;
}
