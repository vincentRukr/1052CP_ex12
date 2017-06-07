//git
struct station{
	char name;
	int price[21];//[tsta]
};
struct station sta[22];//[tsta]

int train[11][22][101][101]={{{{0}}}};
//   [ttra][tsta*2][tcol][trow] bool
int i,j,k,m,n,o,p,t;
int tcol,trow,tcus,tsta,ttra,total=0,count;
char name[21],from,to,type,tiks;
