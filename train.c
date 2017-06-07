#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "train.h"
//#define debug
//git
int main (){
	//input
	scanf("%d\n",&tsta);
#ifdef debug
	printf("%d\n",tsta);
#endif
	scanf("-");
	for(i=0;i<tsta;i++){
		scanf(" %c",&sta[i].name);
	}
	scanf("\n");
	for(i=tsta-1,j=tsta;j<tsta*2;i--,j++){
		sta[j].name=sta[i].name;		
	}	
#ifdef debug
	printf("-");
	for(i=0;i<tsta*2;i++){
		printf(" %c",sta[i].name);
	}
	printf("\n");
#endif
	for(i=0;i<tsta;i++){
		scanf("%*c");
		for(j=0;j<tsta;j++){
			scanf(" %d",&sta[i].price[j]);
		}
		scanf("\n");
	}
	for(i=tsta-1,j=tsta;j<tsta*2;i--,j++){
		for(k=0;k<tsta;k++){
			sta[j].price[k]=sta[i].price[k];
		}
	}
#ifdef debug
	for(i=0;i<tsta*2;i++){
		printf("%c",sta[i].name);
		for(j=0;j<tsta;j++){
			printf(" %d",sta[i].price[j]);
		}
		printf("\n");
	}
#endif
	scanf("%d\n",&ttra);
	scanf("%d %d\n",&trow,&tcol);
	scanf("%d\n",&tcus);
#ifdef debug
	printf("%d\n",ttra);
	printf("%d %d\n",trow,tcol);
	printf("%d\n",tcus);
#endif
	//end of train
	while(scanf("%s %c %c %c%d",
				name,&from,&to,&type,&tiks)!=EOF){
		//printf("%s %c %c %c%d\n",name,from,to,type,tiks);
		//find sta.num
		for(i=0;i<tsta;i++){
			if(from==sta[i].name){
				m=i;//#from
			}
			if(to==sta[i].name){	
				n=i;//#to
			}
		}	
		p=sta[m].price[n];
		if(m>n){
			for(i=tsta;i<tsta*2;i++){
				if(from==sta[i].name){
					m=i;//#from
				}
				if(to==sta[i].name){
					n=i;//#to
				}		
			}	
		}
		//printf("sta:%d to %d\n",m,n);
		//end num
		t=total;
		//check sell
		if(type=='-'){
			count=0;
			for(i=0;i<tcol;i++)
			for(j=0;j<ttra;j++)
			for(k=0;k<trow;k++)
			for(o=m;o<n;o++){
				if(train[j][o][k][i])break;
				if(!train[j][o][k][i]&&o==n-1)count++;
				if(count==tiks){
					//TO BE UPDATED: Make prior to fill in the least seated column left
					for(i=0;i<tcol;i++)
					for(j=0;j<ttra;j++)
					for(k=0;k<trow;k++)
					for(o=m;o<n;o++){
						if(train[j][o][k][i])break;
						if(!train[j][o][k][i]&&o==n-1){
							train[j][o][k][i]=1;
							printf("%s %d %d-%d %d\n",
								name,j+1,k+1,i+1,p);
							total+=p;
							count--;
							if(count==0)i=j=k=o=9487;
						}
					}
				}		
			}
		}
		else{
			for(i=0;i<ttra;i++)
			for(j=0;j<trow;j++)
			for(k=count=0;k<tcol;k++)
			for(o=m;o<n;o++){
				if(train[i][o][j][k])break;
				if(!train[i][o][j][k]&&o==n-1)count++;	
				if(count==tiks){	
					for(k=k-count+1;k<tcol;k++){
						for(o=m;o<n;o++)train[i][o][j][k]=1;
						printf("%s %d %d-%d %d\n",
							name,i+1,j+1,k+1,p);
						total+=p;
						count--;
						if(count==0)i=j=k=o=9487;
					}
				}
			}
		}
		//end check sell
		if(t==total){
			printf("We don't want to sell you.\n");
		}		
		for(i=0;i<21;i++)name[i]='\0';//clear name
		tcus--;//remain
		if(!tcus)break;
	}
	printf("Total Money: %d\n",total);
	return 0;
}
