#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<cmath>
#include<iostream>
#define SIZE 10000 //we can define the size of the arrays that holds hashing tables
using namespace std;

int argctmp; //temporary variables for argc and argv in the main function,they are used in printing function.
char argvtmp[2];

class hashing
{
	public:
		char h1linear[SIZE][21]; //4 arrays for each hashing function and for each probing method
		char h1quadratic[SIZE][21];
		char h2linear[SIZE][21];
		char h2quadratic[SIZE][21];
		
		char input[SIZE][21]; //array that holds the given inputs
		
		int fsh_lph1; //8 variables for free slot hits and average probing length outputs.
		int fsh_lph2; //for each probing method and for each hashing function.
		int fsh_qph1;
		int fsh_qph2;
		double apl_lph1;
		double apl_lph2;
		double apl_qph1;
		double apl_qph2;
		
		int inputsize; //variable that holds the number of inputs given
		int arraysize; //variable that holds the array size specified in inputs
		
		unsigned int hash1(char *v, int M); //given hash function 1
		unsigned int hash2 (char *v, int M); //given hash function 2
		void uppercase(void); //function that converts the all letters to uppercase	
		void inputreading(void); //function for reading input
		void hashing_linear_h1(void); //hashing function 1 that uses linear probing
		void hashing_quadratic_h1(void); //hashing function 1 that uses quadratic probing
		void hashing_linear_h2(void); //hashing function 2 that uses linear probing
		void hashing_quadratic_h2(void); //hashing function 2 that uses quadratic probing
		void printing(void); //function for printing the output according to the specification
};

//given hash function 1
unsigned int hashing::hash1(char *v, int M)
{
	unsigned int h;
	
	for(h=0; *v != '\0'; v++)
		h = (64*h + *v) % M;
	
	return h; 
}

//given hash function 2
unsigned int hashing::hash2 (char *v, int M)
{

	     unsigned int h, i;

	          for(h=0, i=0; i<sizeof(int)&& *v != '\0'; i++, v++)

			            h += (*v - 'A') * ((int)(pow(26.0,(double)i)+0.1));

		       return h % M;

}

//function that converts all letters to upeercase form,if necessary
void hashing::uppercase(void)
{
	int i;
	int j;
	
	for(i=0;i<inputsize;i++)
	{
		for(j=0;j<21;j++)
		{
			if(input[i][j]!=0 && input[i][j]>96 && input[i][j]<123)
				input[i][j]-=32;
		}
	}
}

//function that reads the inputs
void hashing::inputreading(void)
{
	int i;
	int j;
	char ch;
	
	scanf("%d ",&arraysize);
	
	i=0;
	j=0;
	
	while((ch=getchar())!=EOF)
	{
		if(ch!='\n')
		{
			input[i][j]=ch;
			j++;
		}
		else
		{
			input[i][j]=0;
			i++;
			j=0;
		}
	}
	
	inputsize=i;
	
	uppercase();
}

//function that inserts the given input according to hash function 1 and linear probing method
void hashing::hashing_linear_h1(void)
{
	int i;
	unsigned int keyh1;
	int fshlph1=0;
	double apllph1;
	
	fsh_lph1=0;
	apl_lph1=0;
	
	for(i=0;i<inputsize;i++)
	{
		keyh1=hash1(input[i],arraysize);
		
		apllph1=0;
		
		while(h1linear[keyh1%arraysize][0]!=0)
		{
			keyh1++;
			apllph1++;
		}
		
		if(keyh1==hash1(input[i],arraysize))
			fshlph1=1;
		else fshlph1=0;
		
		fsh_lph1+=fshlph1;
		apl_lph1+=apllph1;
		
		strcpy(h1linear[keyh1%arraysize],input[i]);
	}
	
	apl_lph1=apl_lph1/(double)inputsize;
}

//function that inserts the given input according to hash function 1 and quadratic probing method
void hashing::hashing_quadratic_h1(void)
{
	int i;
	int j;
	unsigned int keyh1;
	unsigned int keynewh1;
	int fshqph1=0;
	double aplqph1;
	
	fsh_qph1=0;
	apl_qph1=0;
	 
	for(i=0;i<inputsize;i++)
	{
		keyh1=hash1(input[i],arraysize);
		
		j=1;
		aplqph1=0;
		keynewh1=keyh1;
		
		while(h1quadratic[keynewh1%arraysize][0]!=0)
		{
			keynewh1=keyh1+(unsigned int)pow((double)j,(double)2);
			aplqph1++;
			j++;
		}
		keyh1=keynewh1;
		
		if(keyh1==hash1(input[i],arraysize))
			fshqph1=1;
		else fshqph1=0;
		
		fsh_qph1+=fshqph1;
		apl_qph1+=aplqph1;
		
		strcpy(h1quadratic[keyh1%arraysize],input[i]);
	}
	
	apl_qph1=apl_qph1/(double)inputsize;
}

//function that inserts the given input according to hash function 2 and linear probing method
void hashing::hashing_linear_h2(void)
{
	int i;
	unsigned int keyh2;
	int fshlph2=0;
	double apllph2;
	
	fsh_lph2=0;
	apl_lph2=0;
	
	for(i=0;i<inputsize;i++)
	{
		keyh2=hash2(input[i],arraysize);
		
		apllph2=0;
		
		while(h2linear[keyh2%arraysize][0]!=0)
		{
			keyh2++;
			apllph2++;
		}
		
		if(keyh2==hash2(input[i],arraysize))
			fshlph2=1;
		else fshlph2=0;
		
		fsh_lph2+=fshlph2;
		apl_lph2+=apllph2;
		
		strcpy(h2linear[keyh2%arraysize],input[i]);
	}
	
	apl_lph2=apl_lph2/(double)inputsize;
}

//function that inserts the given input according to hash function 2 and quadratic probing method
void hashing::hashing_quadratic_h2(void)
{
	int i;
	int j;
	unsigned int keyh2;
	unsigned int keynewh2;
	int fshqph2=0;
	double aplqph2;
	
	fsh_qph2=0;
	apl_qph2=0;
	
	for(i=0;i<inputsize;i++)
	{
		keyh2=hash2(input[i],arraysize);
		
		j=1;
		aplqph2=0;
		keynewh2=keyh2;
		
		while(h2quadratic[keynewh2%arraysize][0]!=0)
		{
			keynewh2=keyh2+(unsigned int)pow((double)j,(double)2);
			aplqph2++;
			j++;
		}
		keyh2=keynewh2;
		
		if(keyh2==hash2(input[i],arraysize))
			fshqph2=1;
		else fshqph2=0;
		
		fsh_qph2+=fshqph2;
		apl_qph2+=aplqph2;
		
		strcpy(h2quadratic[keyh2%arraysize],input[i]);
	}
	
	apl_qph2=apl_qph2/(double)inputsize;
}

//function that prints the contents of arrays,and prints the calculated results of apl and fsh 
//according to given option
void hashing::printing(void)
{
	int i;
	
	if(argctmp==2 && argvtmp[0]=='-' && argvtmp[1]=='p')
	{
		cout<<fsh_lph1<<'\t'<<(int)(apl_lph1 + 0.001)<<endl;
		for(i=0;i<arraysize;i++)
		{
			cout<<h1linear[i];
			if(i<arraysize-1)
				cout<<",";
		}
		cout<<endl;
		
		cout<<fsh_lph2<<'\t'<<(int)(apl_lph2 + 0.001)<<endl;
		for(i=0;i<arraysize;i++)
		{
			cout<<h2linear[i];
			if(i<arraysize-1)
				cout<<",";
		}
		cout<<endl;
		
		cout<<fsh_qph1<<'\t'<<(int)(apl_qph1 + 0.001)<<endl;
		for(i=0;i<arraysize;i++)
		{
			cout<<h1quadratic[i];
			if(i<arraysize-1)
				cout<<",";
		}
		cout<<endl;
		
		cout<<fsh_qph2<<'\t'<<(int)(apl_qph2 + 0.001)<<endl;
		for(i=0;i<arraysize;i++)
		{
			cout<<h2quadratic[i];
			if(i<arraysize-1)
				cout<<",";
		}
		cout<<endl;
	}
	
	if(argctmp==1)
	{
		cout<<fsh_lph1<<'\t'<<(int)(apl_lph1 + 0.001)<<endl;
		cout<<fsh_lph2<<'\t'<<(int)(apl_lph2 + 0.001)<<endl;
		cout<<fsh_qph1<<'\t'<<(int)(apl_qph1 + 0.001)<<endl;
		cout<<fsh_qph2<<'\t'<<(int)(apl_qph2 + 0.001)<<endl;
	}
}

//main function, gets the arguments from the standard input and executes the functions 
int main(int argc,char *argv[])
{
	hashing fatih;
	
	argctmp=argc;

	if(argc==2)
	{
		argvtmp[0]=argv[1][0];
		argvtmp[1]=argv[1][1];
	}
	
	fatih.inputreading();
	
	fatih.hashing_linear_h1();
	fatih.hashing_linear_h2();
	fatih.hashing_quadratic_h1();
	fatih.hashing_quadratic_h2();
	
	fatih.printing();
	
	return 0;
}
