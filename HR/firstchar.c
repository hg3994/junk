//First non-repeating character in a string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i,j,k,l,n,change;
	char s[50];
	printf("Enter a string\n");
	gets(s);
	n=strlen(s);
	for(i=0;i<n;i++){
		change=0;
		for(j=i+1;j<n;j++){
			while(s[j]==s[i]){
				change=1;
				for(k=j+1;k<n;k++)
					s[k-1]=s[k];
				s[k-1]='\0';
				n--;
			}
		}
		if(change==0){
			printf("%c",s[i]);
			break;
		}
	}
	printf("\n");
}

