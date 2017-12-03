#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int N = 300; // Numero total de datos 
float bb = 0.2497;
float bd = 5.16;
float ad = 0.3105;
float ah = 64.3;
float Mg = 2.325e7;
int G = 1;
int iteraciones = 10000;

int main(){
FILE *in;
int i,j,k;
in = fopen("radialVelocities1.dat","r");


//Estimación bayesiana
float*r = malloc(N*sizeof(float));
float*Vel = malloc(N*sizeof(float));
float*Vmodelo = malloc(N*sizeof(float));

for(i=0;i<N;i++){
fscanf(in,"%f %f\n", &r[i], &Vel[i]);

	}


FILE* solucion = fopen("Rotacion.txt","w");

	float Mb = 1000*drand48()+1000;// Estimación inicial de la masas 
	float Md = 1000*drand48()+1000;
	float Mh = 1000*drand48()+1000;

for (i = 0;i<N;i++){
	
	Vmodelo[i]= (pow(Mb,1.0/2.0)*r[i])/(pow((pow(r[i],2)+pow(bb,2)),3.0/4.0))+(pow(Md,1.0/2.0)*r[i])/(pow((pow(r[i],2)+pow((bd+ad),2)),3.0/4.0))+(pow(Mh,1.0/2.0))/(pow((pow(r[i],2)+pow(ah,2)),1.0/4.0));

}
float likelihood = 0;

for (i = 0;i<N;i++){

 	likelihood = fabs(Vmodelo[i]-Vel[i]) + likelihood;
 }

//Variables nuevas 

float Mb1;
float Md1;
float Mh1;
float likelihood1;

for(k = 0;k<iteraciones;k++){

    Mb1 = Mb + 30*drand48()-15;// masas aleatorias
	Md1 = Md + 30*drand48()-15;
	Mh1 = Mh + 30*drand48()-15;
	for(i=0;i<N;i++){
	Vmodelo[i]= (pow(Mb1,1.0/2.0)*r[i])/(pow((pow(r[i],2)+pow(bb,2)),3.0/4.0))+(pow(Md1,1.0/2.0)*r[i])/(pow((pow(r[i],2)+pow((bd+ad),2)),3.0/4.0))+(pow(Mh1,1.0/2.0))/(pow((pow(r[i],2)+pow(ah,2)),1.0/4.0));
		}	

likelihood1 = 0;

for (i = 0;i<N;i++){

 	likelihood1 = fabs(Vmodelo[i]-Vel[i]) + likelihood1;
 }

if (likelihood1<likelihood){
	Mb = Mb1;
	Md = Md1;
	Mh = Mh1;
	likelihood = likelihood1;
}
else{
	Mb = Mb;
	Md = Md;
	Mh = Mh;
	likelihood = likelihood;
}
}
	printf("Mb = %f Md = %f Mh = %f", Mb, Md, Mh);

for(i=0;i<N;i++){
		fprintf(solucion,"%f %f \n",r[i],Vmodelo[i]);
			}
		fprintf(solucion,"\n");	
		
	fclose(solucion);	
	


	return 0;

}


