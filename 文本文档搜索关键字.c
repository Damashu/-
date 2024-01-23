#include<stdio.h>
#include<string.h>
int main()
{
	FILE*fp,*fp2;
	char a[100],b[100],c[3]="1",j[100] ;
	int n,flag=0,k;
	if((fp=fopen("使命与担当.txt","r"))==NULL)
		printf("没打开");
	if((fp2=fopen("学习笔记1.txt","w"))==NULL)
		printf("没打开");

	printf("输入你要查找的关键词\n");
	gets(a);
	n=strlen(a);
	

	while(1)
	{
		fgets(b,n+1,fp);
        k=strlen(b)-1;
			
		if(b[k]=='\n')
		{    /*读到\n   fgets会停止读，然后下面回退指针再读还会读到\n造成死循环，现在遇到\n就继续读,
			并且b里得到的字符串数量并不满足要求，于是用另一字符串接收剩下的，然后组合起来。*/
            b[k]='\0';
			
            fgets(j,n-k+1,fp);
			if(strcmp(j,"\n")==0)  //结束循环的条件，在最后读到换行符
				return 0;
			
			
            strcat(b,j);
	
		}
		
		
		if(strcmp(a,b)==0)
		{
			while(strcmp(c,"。")!=0 && strcmp(c,"  ")!=0)/*往前抓2个字节大小内容遇到
				                                           句号或者两个英文空格就停下来*/
			{
				
				fseek(fp,-3,SEEK_CUR);
				fgets(c,3,fp);
				
				
				
			} 

			//到此文件指针指到了“  ”前面，或者句号前面
			

			fgets(c,3,fp);//读句号后面一个。
			while(strcmp(c,"。")!=0)
			{
				printf("%s",c);	
				fprintf(fp2,"%s",c);//输出结果
				fgets(c,3,fp);
				if(c[0]<='9' && c[0]>='0'&&(c[1]>'9'||c[1]<'0') )
				{
					fseek(fp,-1,SEEK_CUR);
					printf("%c",c[0]);
					fgets(c,3,fp);


				}
	
			}
			fprintf(fp2,"。");
			fprintf(fp2,"\n");
			printf("。");
			printf("\n");
			strcpy(c,"00");  //为了下一次进循环，重置c
		}
		
		else
		{   		  //往后移动一个字节大小。
			fseek(fp,-n+1,SEEK_CUR);
		}
	}
	
		
	return 0;
}