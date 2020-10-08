#include <stdio.h>

int main(int argc, char* argv[])
{
	int	tmp;
	FILE	*fp;
	if (argc==2) {
		if((fp=fopen(argv[1],"w"))==NULL)
		{
			fprintf(stderr,"File Open Error");
			return 1;
		}
	}

	if (argc>2)
	{
		if	(argv[1][1]=='a')
			fp=fopen(argv[2],"a+");
		else
			fp=fopen(argv[2],"c");
	}
	while(!feof(stdin))
	{
		tmp=fgetc(stdin);
		fputc(tmp,stdout);
		if(argc!=1) fputc(tmp,fp);
	}
	return 0;
}
