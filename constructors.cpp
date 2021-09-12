#include<iostream.h>
#include "hw1.h"
#include<time.h>
#include<string.h>



RandomLibrary rano;





Patient::Patient(){       
	
	
	char *c=new char[21];
	int i;
	
	
	
	rano.GetRandomPatient(&i, c);
	SetName(c);
	
	
	
	this->age=i;	
}





Patient::~Patient()
{ }






void Patient::SetAge(int i){
   
	
	this->age=i;

}






void Patient::SetName(char c[]){

	
	strcpy (this->name, c);
       
}





int Patient::GetAge() const{
	
	return this->age;

}






const char * Patient::GetName() const{
	
	return this->name;

}


int Patient::operator>(const Patient &r){


        if (this->age==r.age)
               return (strcmp(name, r.name)==1);

	
	return this->age>r.age;
}





	
int Patient::operator<(const Patient &r){
	
	
	if (this->age==r.age)
           return strcmp(this->name,  r.name)==-1;
	
	
	return this->age<r.age;	   
}






int Patient::operator==(const Patient &r){
   
	
	return !(*this<r||*this>r);

}





template<class T>
int LinearSearch(T *g, T x, int n, int &comp){        
	
	comp=0;	     
	
	
	int k=0;
	int basarisiz=-1;
	
	
	while(k<n){      	
	        if ( x>g[k]) comp++; else if (x<g[k]) break; 
	        else 
		       return k; 
                k++;
        }		
        
	
	return basarisiz;
}








template<class T>
int BinarySearch(T h[], T &x, int n, int &comp ){
	
	
	int o;
	comp=0;
	
	
	int fatih=1;
	int basarisiz=-1;
     
	
	
	for(int first=0, last=n-1; first<=last;){
	    
		
	      o=(int)(first+last)/2;
              comp++;

	      
	      (x==h[o]) ? fatih=0 : comp++;
              if (!fatih) break;

	      x>h[o]? first=o+1: last=o-1;
       
       }	
        
	
	if (!fatih) return o;
	return basarisiz;
}









void birdefayapint(int *small, int &comp1, int &comp2, double &t1, double &t2, int z, int fatih){

	
        int searchInt; 
	clock_t ta, tb;
    	
	
	rano.GetIntegerSearchKey(small, z, &searchInt, fatih);
        
	
	ta=clock();	
	LinearSearch(small, searchInt, z,  comp1);
        tb=clock();
        
	double tfarkbir=tb-ta;
	t1=tfarkbir/(CLOCKS_PER_SEC / (double) 1000.0);

	
	
	ta=clock();
       	BinarySearch(small, searchInt,  z,  comp2);
        tb=clock();
       	
	
	double tfarkiki=tb-ta;
	t2=tfarkiki/(CLOCKS_PER_SEC / (double) 1000.0);
        
}








void ondefayapint(int &comp1, int &comp2, double &t1, double &t2, int z, int fatih){   

	
    int fall[z];	
    
    
    t1=0; t2=0;	
    rano.FillIntegerArray(fall, z);
    
    
    int bir=0, iki=0;
    double birt=0, ikit=0;
    
    
    
    for(int j=1; j<=10; j++){
	    
	    
	    birdefayapint(fall,bir, iki, birt, ikit, z, fatih);
	    
	    
	    comp1+=(bir+2);
	    comp2+=(iki+2);
	
	    
	    t1+=birt;  
            t2+=ikit;
    }
}










void averageal(int &comp1, int &comp2, double &t1, double &t2){
    
	
    t1=t1/10;
    t2=t2/10;
    
    
    comp1=comp1/10;
    comp2=comp2/10;
}	









void execute1(){    
     
	
     cout<<"Search on Integers"<<endl<<"Size\tLS(succ)\tBS(succ)\tLS(unsucc)\tBS(unsucc)"<<endl;
 
     
     int comp1=0, comp2=0;
     double t1=0, t2=0;
     
     
     
     
     ondefayapint(comp1, comp2, t1, t2, 1000, SUCCESSFUL);
     averageal(comp1, comp2, t1, t2);	
     cout<<1000<<"\t"<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<"\t";
     
     
     
     
     ondefayapint(comp1, comp2, t1, t2, 1000, UNSUCCESSFUL);
     averageal(comp1, comp2, t1, t2);
     cout<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<endl;
     
     
     
     
     ondefayapint(comp1, comp2, t1, t2, 10000, SUCCESSFUL);
     averageal(comp1, comp2, t1, t2);
     cout<<10000<<"\t"<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<"\t";
     
     
     
     
     ondefayapint(comp1, comp2, t1, t2, 10000, UNSUCCESSFUL);
     averageal(comp1, comp2, t1, t2);
     cout<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<endl;

     
     
     
     ondefayapint(comp1, comp2, t1, t2, 100000, SUCCESSFUL);
     averageal(comp1, comp2, t1, t2);
     cout<<100000<<"\t"<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<"\t";
     
     
     
     
     ondefayapint(comp1, comp2, t1, t2, 100000, UNSUCCESSFUL);
     averageal(comp1, comp2, t1, t2);
     cout<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<endl;

     
     
     
     ondefayapint(comp1, comp2, t1, t2, 500000, SUCCESSFUL);
     averageal(comp1, comp2, t1, t2);
     cout<<500000<<"\t"<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<"\t";
     
     
    
     
     ondefayapint(comp1, comp2, t1, t2, 500000, UNSUCCESSFUL);
     averageal(comp1, comp2, t1, t2);
     cout<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<endl;
			      

}









void birdefayappatient(Patient *dizin2, int &comp1, int &comp2, double &t1, double &t2, int z, int fatih){
    
	
    clock_t ta, tb;
    char  c[30];
    int  f,large=1;
    

    
    Patient p;
    rano.GetPatientSearchKey(dizin2, z, c, &f, fatih);
    
    
    
    p.SetName(c);
    
    
    p.SetAge(f);
    
    
    ta=clock();
    LinearSearch(dizin2, p, z,  comp1);
    tb=clock();
    
    
    
    double tfarkbir=tb-ta;
    t1=(double)tfarkbir/(CLOCKS_PER_SEC / (double) 1000.0);
    ta=clock();
    
    
    
    BinarySearch(dizin2, p,  z,  comp2);
    tb=clock();
    
    
    
    double tfarkiki=tb-ta;
    t2=(double)tfarkiki/(CLOCKS_PER_SEC / (double) 1000.0);
    large*=2;
    
}









void ondefayappatient(int &comp1, int &comp2, double &t1, double &t2, int z, int fatih){  

	
   Patient *dizin2=new Patient[z];
   rano.SortPatientArray(dizin2, z);
   
   
   t1=0; t2=0;
   
   
   int bir=0, iki=0;
   double birt=0, ikit=0;
   
   
   for(int j=1; j<=10; j++){     
	 
	   
	 birdefayappatient(dizin2, bir, iki, birt, ikit, z, fatih);
         
	 
	 comp1+=(bir+2);
         comp2+=(iki+2);
        
	 
	 t1+=birt;
         t2+=ikit;
   }

   
  
}









void execute(){   
    
    execute1();
	
    cout<<"Search on Patients"<<endl<<"Size\tLS(succ)\tBS(succ)\tLS(unsucc)\tBS(unsucc)"<<endl;
    
    
    int comp1=0, comp2=0;
    double t1=0, t2=0;
    
    
    
    ondefayappatient(comp1, comp2, t1, t2, 1000, SUCCESSFUL);
    averageal(comp1, comp2, t1, t2);
    cout<<1000<<"\t"<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<"\t";
    
    
    ondefayappatient(comp1, comp2, t1, t2, 1000, UNSUCCESSFUL);
    averageal(comp1, comp2, t1, t2);
    cout<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<endl;
    
    
    
    ondefayappatient(comp1, comp2, t1, t2, 10000, SUCCESSFUL);
    averageal(comp1, comp2, t1, t2);
    cout<<10000<<"\t"<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<"\t";
    
    
    
    ondefayappatient(comp1, comp2, t1, t2, 10000, UNSUCCESSFUL);
    averageal(comp1, comp2, t1, t2);
    cout<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<endl;
    
    
    
    ondefayappatient(comp1, comp2, t1, t2, 100000, SUCCESSFUL);
    averageal(comp1, comp2, t1, t2);
    cout<<100000<<"\t"<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<"\t";
    
    
    
    ondefayappatient(comp1, comp2, t1, t2, 100000, UNSUCCESSFUL);
    averageal(comp1, comp2, t1, t2);
    cout<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<endl;
    
    
    
    ondefayappatient(comp1, comp2, t1, t2, 500000, SUCCESSFUL);
    averageal(comp1, comp2, t1, t2);
    cout<<500000<<"\t"<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<"\t";
    
    
    
    ondefayappatient(comp1, comp2, t1, t2, 500000, UNSUCCESSFUL);
    averageal(comp1, comp2, t1, t2);
    cout<<comp1<<"\t"<<t1<<"\t"<<comp2<<"\t"<<t2<<endl;

}

    







int main(void){	
	
        execute();
	return 0;

}





























