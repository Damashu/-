#include<stdio.h>
#include<string.h>
int main()
{
	FILE*fp,*fp2;
	char a[100],b[100],c[3]="1",j[100] ;
	int n,flag=0,k;
	if((fp=fopen("ʹ���뵣��.txt","r"))==NULL)
		printf("û��");
	if((fp2=fopen("ѧϰ�ʼ�1.txt","w"))==NULL)
		printf("û��");

	printf("������Ҫ���ҵĹؼ���\n");
	gets(a);
	n=strlen(a);
	

	while(1)
	{
		fgets(b,n+1,fp);
        k=strlen(b)-1;
			
		if(b[k]=='\n')
		{    /*����\n   fgets��ֹͣ����Ȼ���������ָ���ٶ��������\n�����ѭ������������\n�ͼ�����,
			����b��õ����ַ���������������Ҫ����������һ�ַ�������ʣ�µģ�Ȼ�����������*/
            b[k]='\0';
			
            fgets(j,n-k+1,fp);
			if(strcmp(j,"\n")==0)  //����ѭ���������������������з�
				return 0;
			
			
            strcat(b,j);
	
		}
		
		
		if(strcmp(a,b)==0)
		{
			while(strcmp(c,"��")!=0 && strcmp(c,"  ")!=0)/*��ǰץ2���ֽڴ�С��������
				                                           ��Ż�������Ӣ�Ŀո��ͣ����*/
			{
				
				fseek(fp,-3,SEEK_CUR);
				fgets(c,3,fp);
				
				
				
			} 

			//�����ļ�ָ��ָ���ˡ�  ��ǰ�棬���߾��ǰ��
			

			fgets(c,3,fp);//����ź���һ����
			while(strcmp(c,"��")!=0)
			{
				printf("%s",c);	
				fprintf(fp2,"%s",c);//������
				fgets(c,3,fp);
				if(c[0]<='9' && c[0]>='0'&&(c[1]>'9'||c[1]<'0') )
				{
					fseek(fp,-1,SEEK_CUR);
					printf("%c",c[0]);
					fgets(c,3,fp);


				}
	
			}
			fprintf(fp2,"��");
			fprintf(fp2,"\n");
			printf("��");
			printf("\n");
			strcpy(c,"00");  //Ϊ����һ�ν�ѭ��������c
		}
		
		else
		{   		  //�����ƶ�һ���ֽڴ�С��
			fseek(fp,-n+1,SEEK_CUR);
		}
	}
	
		
	return 0;
}