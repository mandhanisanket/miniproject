#include<stdio.h>
#include<string.h>
#include"conversion.h"

int dec_bin(int x){
	int b=0,pcs=1,r;
	while(x>0)
	{
		r=x%2;
		b=b+r*pcs;
		pcs=pcs*10;
		x=x/2;
	}
	return (b);
}		

void dec_hex(int x){
	int q,i,j;
	int y[10];	
	for(j=0;x>0;j++)
	{
		q=x%16;
		y[j]=q;
		x=x/16;
	}
	printf("The hexa value is :");
	for(i=j-1;i>=0;i--)
	{
		if(y[i]==10)
			printf("A");
		else if(y[i]==11)
			printf("B");
		else if(y[i]==12)
        		printf("C");
		else if(y[i]==13)
        		printf("D");
		else if(y[i]==14)
        		printf("E");
		else if(y[i]==15)
        		printf("F");
        	else 
			printf("%d",y[i]);
	}
}
int dec_oct(int x){
	int s=0,p=1;
	while(x>0)
	{
		s=s+(x%8)*p;
		p=p*10;
		x=x/8;
	}
	return(s);
}
int bin_dec(int x){
	int b,pos=1,sum=0;
	while(x>0)
	{
		b=x%10;
		sum=sum+(pos*b);
		pos=pos*2;
		x=x/10;
	}
	return (sum);
}

int oct_dec(int x){
	int d=0,pos=1,r;
	while(x>0)
	{
		r=x%10;
		if(r==8||r==9)
		{
			printf("Syntax Error");
			break;
		}
		else
		{
			d=d+r*pos;
			pos=pos*8;
			x=x/10;
		}
	}
	return(d);
}
int hex_dec(){
	char q[20];
	int d=0,pos=1,y,ans,i;
	printf("enter the num hexadecimal number \n");
	scanf("%s",q);
	y=strlen(q);
	for(i=y-1;i>=0;i--)
	{
		if(q[i]=='a')
        	{
		ans=10;
		d=d+(ans*pos);
		}
        	else if(q[i]=='b')
        	{
		ans=11;
		d=d+(ans*pos);
		}
		else if(q[i]=='c')
                {
		ans=12; 
                d=d+(ans*pos);
		}
		else if(q[i]=='d')
                {
		ans=13; 
                d=d+(ans*pos);
		}
		else if(q[i]=='e')
                {
		ans=14; 
                d=d+(ans*pos);
		}
		else if(q[i]=='f')
                {
		ans=15; 
                d=d+(ans*pos);
		}
		else
		{
		ans=(q[i]-'0');
		d=d+(ans*pos);
		}
	pos=pos*16;
	}
	
	return(d);
}
void bin_hex(int x){
	int i;
	i=bin_dec(x);
	dec_hex(i);
}
int bin_oct(int x){
	int i,j;
	i=bin_dec(x);
	j=dec_oct(i);
	return(j);
}
int hex_bin(){
	int i,j;
	i=hex_dec();
	j=dec_bin(i);
	return(j);
}
int hex_oct(){
	int i,j;
	i=hex_dec();
	j=dec_oct(i);
	return(j);
}
int oct_bin(int x){
	int i,j;
	i=oct_dec(x);
	j=dec_bin(i);
	return(j);	
}

void oct_hex(int x){
	int i;
	i=oct_dec(x);	
	dec_hex(i);
}
