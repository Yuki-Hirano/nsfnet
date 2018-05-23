#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "SA_head2.h"
#define N 14
#define INF 10000
//#define LIMIT1 25000
//#define LIMIT2 5000
#define T_initial 10000
//#define rho 0.99
#define SEED 2
//#define PROBABILITY 0.1
//#define EPSILON 0.05
#define SIGMA 0.25
#define MU 0.5
#define K 2
#define ERROR 1e-15


typedef struct {
        int cap;
        double prob;
} topology;
void swap_topology(topology *x, topology *y);
void sort_by_cap(topology a[],int length);
void combine(topology a[]);
int define_cap(topology a[],double EPSILON);



int main(int argc,char *argv[]){
  double PROBABILITY=atof(argv[1]);
  double EPSILON=atof(argv[2]);
  //int model=atof(argv[3]);
        double T;
	//double T_initial=atof(argv[3]);
	int LIMIT1=10000;
	int LIMIT2=atof(argv[4]);
	double rho=atof(argv[3]);
        int loop;
        int route[N];
        int temp_route[N];
        int cnt2,i,j,a,b,q;
        int gamma[N][N];
        int PATH[N][N][N];
        int fixedtemp[N][N][N];
        int cb_total=0;
        int cb_prime_total=0;
        int src,dst;
        int cb_min=INF;
	int cb_min_temp=INF;
        int sum;
        double start,end,time=0.0;
        int cnt[N][N];
        int cnt_k[N][N][K];
        int cap_list[K]={1,10};
        int input[K];
        int num[K];
	//double flag1,flag2,flag3,flag4;
        //double normal;
	// printf("At p=%f, epsilon=%f\n",PROBABILITY,EPSILON);




	// topology p_link[N][N];
	srand(K);
        srand48(SEED);
        for(i=0; i<N; i++) {
                for(j=0; j<N; j++) {
                        cnt[i][j]=0;

			/*

                        if(i==j) {
                                p_link[i][j].cap=0;
                                p_link[i][j].prob=0.000;
                        }else{

                                   normal=rand_normal(MU,SIGMA);
                                   while(normal<0){
                                   normal=rand_normal(MU,SIGMA);
                                   }

                                   p_link[i][j].cap=(int)(normal*100);


                                //p_link[i][j].cap=(int)(drand48()*100);

                                p_link[i][j].cap=cap_list[rand_K(K)];
                                p_link[i][j].prob=PROBABILITY;
                        }
			*/
			// printf("%d&",p_link[i][j].cap);
                }
		// printf("\n");
        }

	/*
	  //MODEL=A

	    topology p_link[N][N]=
	      {{{0,0.0},{1,PROBABILITY},{1,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
	       {{1,PROBABILITY},{0,0.0},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
	       {{1,PROBABILITY},{1,PROBABILITY},{0,0.0},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
	       {{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,0.0},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
	       {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,0.0},{1,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
	       {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,0.0},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
	       {{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,0.0},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY}},
	       {{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,0.0},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
	       {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,0.0},{0,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY}},
	       {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,0.0},{10,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
	       {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,0.0},{10,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY}},
	       {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,0.0},{10,PROBABILITY},{0,PROBABILITY}},
	       {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,0.0},{10,PROBABILITY}},
	       {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,0.0}},
	      };
	*/


	  //MODEL=B

	      topology p_link[N][N]=
		{{{0,0.0},{10,PROBABILITY},{1,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
		 {{1,PROBABILITY},{0,0.0},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
		 {{1,PROBABILITY},{10,PROBABILITY},{0,0.0},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
		 {{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,0.0},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
		 {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,0.0},{1,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
		 {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,0.0},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
		 {{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,0.0},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY}},
		 {{0,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY},{0,0.0},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
		 {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,0.0},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY}},
		 {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,0.0},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY}},
		 {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,0.0},{1,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY}},
		 {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,0.0},{1,PROBABILITY},{0,PROBABILITY}},
		 {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,0.0},{1,PROBABILITY}},
		 {{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{1,PROBABILITY},{0,PROBABILITY},{10,PROBABILITY},{0,0.0}},};







        topology info[N][N][N*N-N];
        topology *p_density;


        //FILE *fp;
        //start=time(NULL);
	//flag1=clock();

        for(q=0; q<LIMIT1; q++) {
	  start=clock();
	  T=T_initial;
                srand(q);

                cb_total=0;



                for(i=0; i<N; i++) {
                        for(j=0; j<N; j++) {
                                gamma[i][j]=0;
                                cnt[i][j]=0;
                                for(a=0; a<N*N-N; a++) {
                                        info[i][j][a].cap=0;
                                        info[i][j][a].prob=0;
                                }
                        }
                }


                for(i=0; i<N; i++) {
                        for(j=0; j<N; j++) {
                                for(a=0; a<N; a++) {
                                        PATH[i][j][a]=INF;
                                        fixedtemp[i][j][a]=INF;
                                }
				for(a=0; a<K; a++) {
				  cnt_k[i][j][a]=0;
				}

                        }
                }


                //初期ルーティングと容量・確率情報の保存
                for(i=0; i<N; i++) {
                        for(j=0; j<N; j++) {
                                if(i!=j) {
                                        RandomSerch(i,j,route);
                                        for(b=0; b<N; b++) {
                                                PATH[i][j][b]=route[b];
                                        }

                                        for(a=0; a<N-1; a++) {
                                                if(route[a]!=INF) {
                                                        if(p_link[i][j].cap!=0) {
                                                                info[route[a]][route[a+1]][cnt[route[a]][route[a+1]]].cap=p_link[i][j].cap;
                                                                info[route[a]][route[a+1]][cnt[route[a]][route[a+1]]].prob=p_link[i][j].prob;
                                                                cnt[route[a]][route[a+1]]++;

                                                        }
                                                }
                                        }
                                }
                        }
                }

		/*
		flag2=clock();
		printf("初期ルーティング...%f\n",(flag2-flag1)/CLOCKS_PER_SEC);
		*/
		/*
//経路の表示
                for(i=0; i<N; i++) {
                        for(j=0; j<N; j++) {
                                if(i!=j) {
                                        printf("(%d,%d)---",i,j);
                                        for(a=0; a<N; a++) {
                                                if(PATH[i][j][a]!=INF) {
                                                        printf("%d-",PATH[i][j][a]);
                                                }
                                        }
                                        printf("\n");
                                }
                        }
                }

		*/
                for(i=0; i<N; i++) {
                        for(j=0; j<N; j++) {
                                if(i!=j) {
                                        for(a=0; a<cnt[i][j]; a++) {
                                                for(b=0; b<K; b++) {
                                                        if(info[i][j][a].cap==cap_list[b]) {
                                                                cnt_k[i][j][b]++;
                                                        }
                                                }
                                        }
                                }
                        }
                }



                sum=0;
                for(i=0; i<N; i++) {
                        for(j=0; j<N; j++) {
                                cnt2=1;
                                if(i!=j) {
				  /*
                                        //経過の出力
                                        for(b=0; b<K; b++) {
                                                printf("number of %d is %d\n",cap_list[b],cnt_k[i][j][b] );
                                        }
				  */

                                        //probability
                                        for(a=0; a<K; a++) {
                                                cnt2*=(1+cnt_k[i][j][a]);
                                        }

                                        //printf("cnt=%d\n",cnt2);


					//mallocのエラー？
                                        p_density = (topology*)malloc(sizeof(topology)*(cnt2+1));
                                        if(p_density==NULL) {
                                                printf("memory error\n");
                                                exit(0);
                                        }

                                        for(a=0; a<cnt2+1; a++) {
                                                p_density[a].cap=0;
                                                p_density[a].prob=0;
                                        }
                                        b=0;
                                        for(num[0]=0; num[0]<cnt_k[i][j][0]+1; num[0]++) {
                                                for(num[1]=0; num[1]<cnt_k[i][j][1]+1; num[1]++) {

                                                                for(a=0; a<K; a++) {
                                                                        input[a]=num[a];
                                                                }
                                                                p_density[b].cap=calc_cap(cap_list,input);
                                                                p_density[b].prob=calc_prob(cap_list,cnt_k[i][j],input,PROBABILITY);
                                                                b++;

                                                }
                                        }

                                        combine(p_density);
                                        sort_by_cap(p_density,cnt2);
					/*
                                        for(a=0; a<cnt2; a++) {
                                                printf("%f--",p_density[a].prob);
                                        }
                                        printf("\n");
					*/
                                        gamma[i][j]=define_cap(p_density,EPSILON);
                                        sum+=gamma[i][j];

                                        free(p_density);

                                }
                        }
                }
                cb_total=sum;
		/*
		flag3=clock();
		printf("初期容量算出...%f\n",(flag3-flag2)/CLOCKS_PER_SEC);
		*/
                //printf("initial CB_total = %d\n",cb_total);



                for(loop=0; loop<LIMIT2; loop++) {
                        for(i=0; i<N; i++) {
                                for(j=0; j<N; j++) {
                                        for(a=0; a<K; a++) {
                                                cnt_k[i][j][a]=0;
                                        }
                                        for(a=0; a<N; a++) {
                                                fixedtemp[i][j][a]=PATH[i][j][a];
                                        }
                                }
                        }

                        src=rand()%N;
                        dst=rand()%N;
                        while(dst==src) {
                                dst=rand()%N;
                        }
                        //printf("s=%d,d=%d,  ",src,dst);

                        RandomSerch(src,dst,temp_route);

                        while(same_ch(temp_route,fixedtemp[src][dst])) {
                                RandomSerch(src,dst,temp_route);
                        }

                        for(a=0; a<N; a++) {
                                fixedtemp[src][dst][a]=temp_route[a];
                        }

                        for(i=0; i<N; i++) {
                                for(j=0; j<N; j++) {
                                        gamma[i][j]=0;
                                        cnt[i][j]=0;
                                        for(a=0; a<N*N-N; a++) {
                                                info[i][j][a].cap=0;
                                        }
                                }
                        }

/*
                        //従来手法の経路
                        int fixedtemp[N][N][N]=
                        {
                                {{INF,INF,INF,INF,INF},
                                 {INF,INF,INF,0,1},
                                 {INF,0,3,4,2},
                                 {INF,INF,INF,0,3},
                                 {INF,INF,0,1,4}},

                                {{INF,INF,1,3,0},
                                 {INF,INF,INF,INF,INF},
                                 {INF,1,3,4,2},
                                 {INF,INF,INF,1,3},
                                 {INF,INF,INF,1,4}},

                                {{INF,INF,INF,2,0},
                                 {INF,INF,INF,2,1},
                                 {INF,INF,INF,INF,INF},
                                 {INF,INF,2,0,3},
                                 {INF,INF,2,1,4}},

                                {{INF,INF,INF,3,0},
                                 {INF,INF,3,0,1},
                                 {INF,INF,3,4,2},
                                 {INF,INF,INF,INF,INF},
                                 {INF,INF,INF,3,4}},

                                {{INF,INF,4,2,0},
                                 {INF,INF,4,2,1},
                                 {INF,INF,INF,4,2},
                                 {INF,4,2,1,3},
                                 {INF,INF,INF,INF,INF}}
                        };
 */

                        for(i=0; i<N; i++) {
                                for(j=0; j<N; j++) {
                                        if(i!=j) {

                                                for(b=0; b<N; b++) {
                                                        temp_route[b]=fixedtemp[i][j][b];
                                                }


                                                for(a=0; a<N-1; a++) {
                                                        if(temp_route[a]!=INF) {
                                                                if(p_link[i][j].cap!=0) {
                                                                        info[temp_route[a]][temp_route[a+1]][cnt[temp_route[a]][temp_route[a+1]]].cap=p_link[i][j].cap;
                                                                        info[temp_route[a]][temp_route[a+1]][cnt[temp_route[a]][temp_route[a+1]]].prob=p_link[i][j].prob;
                                                                        cnt[temp_route[a]][temp_route[a+1]]++;
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }

                        for(i=0; i<N; i++) {
                                for(j=0; j<N; j++) {
                                        if(i!=j) {
                                                for(a=0; a<cnt[i][j]; a++) {
                                                        for(b=0; b<K; b++) {
                                                                if(info[i][j][a].cap==cap_list[b]) {
                                                                        cnt_k[i][j][b]++;
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }

                        /*
                           for(i=0;i<N;i++){
                           for( j=0;j<N;j++){
                           printf("(%d,%d)---",i,j);
                           for(a=0;a<N;a++){
                           if(fixedtemp[i][j][a]!=INF){
                            printf("%d",fixedtemp[i][j][a]);
                           }
                           }
                           printf("\n");
                           }
                           }

                           printf("gamma\n");
                           for(i=0;i<N;i++){
                           for(j=0;j<N;j++){
                           printf("(%d,%d)・・・",i,j);
                           for(a=0;a<10;a++){
                           printf("%d,",info[i][j][a].cap);
                           }
                           printf("\n");
                           }
                           }
                         */


                        sum=0;
                        for(i=0; i<N; i++) {
                                for(j=0; j<N; j++) {
                                        cnt2=1;
                                        if(i!=j) {

                                                //probability
                                                for(a=0; a<K; a++) {
                                                        cnt2*=(1+cnt_k[i][j][a]);
                                                }

                                                p_density = (topology*)malloc(sizeof(topology)*(cnt2+1));
                                                if(p_density==NULL) {
                                                        printf("memory error\n");
                                                        exit(0);
                                                }

                                                for(a=0; a<cnt2+1; a++) {
                                                        p_density[a].cap=0;
                                                        p_density[a].prob=0;
                                                }
                                                b=0;
                                                for(num[0]=0; num[0]<cnt_k[i][j][0]+1; num[0]++) {
                                                        for(num[1]=0; num[1]<cnt_k[i][j][1]+1; num[1]++) {

                                                                        for(a=0; a<K; a++) {
                                                                                input[a]=num[a];
                                                                        }
                                                                        p_density[b].cap=calc_cap(cap_list,input);
                                                                        p_density[b].prob=calc_prob(cap_list,cnt_k[i][j],input,PROBABILITY);
                                                                        b++;

                                                        }
                                                }

                                                combine(p_density);
                                                sort_by_cap(p_density,cnt2);


                                                gamma[i][j]=define_cap(p_density,EPSILON);
                                                sum+=gamma[i][j];

                                                free(p_density);

                                        }
                                }
                        }
                        cb_prime_total=sum;



                        if((cb_total>cb_prime_total) || ((rand()/(1.0+RAND_MAX))<exp((cb_total-cb_prime_total)/T))) {
                                cb_total=cb_prime_total;
                                for(i=0; i<N; i++) {
                                        for(j=0; j<N; j++) {
                                                for(a=0; a<N; a++) {
                                                        PATH[i][j][a]=fixedtemp[i][j][a];
                                                }
                                        }
                                }

                        }

                        if(cb_total<cb_min) {
                                cb_min=cb_total;
                        }



                        /*
                           if(loop==0){
                           if((fp=fopen("result.txt","w"))==NULL){
                           printf("error\n");
                           return -1;
                           }
                           fprintf(fp,"%d,%d\n",loop,cb_total);
                           fclose(fp);
                           }else{
                           if((fp=fopen("result.txt","a"))==NULL){
                           printf("error\n");
                           return -1;
                           }
                           fprintf(fp,"%d %d\n",loop,cb_total);
                           fclose(fp);
                           }
                         */
                        //printf("CB_total=%d\n",cb_total);


                        T=T*rho;

		      
			  /*
			flag4=clock();
			printf("ループ終了...%f\n",(flag4-flag3)/CLOCKS_PER_SEC);*/
                }
                //printf("%d\n",cb_total)
		/*
                if(q==0) {
                        if((fp=fopen("result_discrete3.txt","w"))==NULL) {
                                printf("error\n");
                                return -1;
                        }
                        fprintf(fp,"%d %d\n",q,cb_total);
                        fclose(fp);
                }else{
                        if((fp=fopen("result_discrete3.txt","a"))==NULL) {
                                printf("error\n");
                                return -1;
                        }
                        fprintf(fp,"%d %d\n",q,cb_total);
                        fclose(fp);
                }
		*/


		if(cb_min_temp>cb_min){
		  cb_min_temp=cb_min;
		  // printf("seed=%d, CB=%d\n",q,cb_min_temp);
		}
		end=clock();
		time+=(end-start)/CLOCKS_PER_SEC;
        }

        //end=time(NULL);
        //printf("SA  CB_total=%d\n",cb_total);
        //printf("proposal  CB_total=%d\n",cb_total);
	/*
	if((fp=fopen("result_discrete3.txt","a"))==NULL) {
	    printf("error\n");
	    return -1;
	  }
	fprintf(fp,"%f,%f %d,%f\n",PROBABILITY,EPSILON,cb_min,end-strart);
	  fclose(fp);
	*/
	  //printf("minimum CB=%d\n",cb_min);
	  //printf("time %d[s]\n",end-start);
	printf("B,%d,%f,%f,%d,%d,%d,%f\n",T_initial,PROBABILITY,EPSILON,cb_min_temp,LIMIT1,LIMIT2,time);

        return 0;
}

void swap_topology(topology *x, topology *y){
        topology temp=*x;
        *x=*y;
        *y=temp;
}

void sort_by_cap(topology a[],int length){
        int i,j;

        for(i=0; i<length-1; i++) {
                for(j=length-1; j>i; j--) {
                        if(a[j-1].cap < a[j].cap) {
                                swap_topology(&a[j-1],&a[j]);
                        }
                }
        }
}


void combine(topology a[]){
        int i,len=0,temp,cnt;


        while(a[len].cap!=0) {
                len++;
        }

        for(i=0; i<len+1; i++) {
                temp=a[i].cap;
                cnt=i+1;
                while(a[cnt].cap!=0) {
                        if(a[cnt].cap==temp) {
                                a[i].prob=a[i].prob+a[cnt].prob;
                                a[cnt].prob=0;
                        }
                        cnt++;
                }
        }
}



 int define_cap(topology a[],double EPSILON){
        double sum_prob=0;
        int i,c=0,cnt=0;
        while(1) {
                if(a[cnt].cap==0&&fabs(a[cnt].prob)<ERROR) {
                        break;
                }
                cnt++;
        }

        for(i=0; i<cnt; i++) {
                if(((a[i].cap!=0)&&(fabs(a[i].prob)>ERROR)) ||((a[i].cap==0)&&(fabs(a[i].prob-1)<ERROR))) {
                        if((fabs(EPSILON-(sum_prob+a[i].prob))>ERROR) && (EPSILON<sum_prob+a[i].prob)) {
                                c=a[i].cap;
                                break;
                        }
                        sum_prob+=a[i].prob;
                }
        }

        return c;
}
/*
   double rand_normal( double mu, double sigma ){
        double z=sqrt( -2.0*log(drand48()) ) * sin( 2.0*M_PI*drand48() );
        return mu + sigma*z;
   }
 */
