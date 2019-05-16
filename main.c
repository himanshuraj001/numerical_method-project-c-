#include <stdio.h>
#include <stdlib.h>
#include<math.h>
float a[10][10],b[10][10],ans[10];
float utd(float a[10][10], int n, int m);
void guass(float a[10][10],int n );
void display(float a[10][10],int n , float ans[10]);
void guasssidel(float a[10][10], int n);
void display1(float a[10][10],int n , float ans[10],int itr);
float dsd(float x[10], float y[10],int n, float input);
int flag=0;
float nfi(float x[10], float y[10],int n, float input);
float h,x[10],y[10];
float nbi(float x[10], float y[10],int n, float input);
float ans[10];
void guassjordan(float a[10][10],int n );
float res(float coe[20],int mp,float val);
float trep(float y[20],int di,float diff);
float simp13(float y[20],int dii,float dif);
float simp38(float y[20],int d,float difff);
float fcalc1(float coe[20],int mp,float val);
float wedd(float y[20],int d6,float di6);
void displayjordan(float a[10][10],int n , float ans[10]);
float coe[20];

int main()
{
int sel,i,j,k;
printf("Select the operation that u want to perform : \n");
printf("1.Basic calculations \n 2.Solution of simultanous equation\n 3.Interpolation \n 4. Integration \n 5.value of root in polynomial \n 0.exit() \n");
printf("Select the one : ");
scanf("%d",&sel);
while(sel!=0)
{
if(sel==1)
{
int sel1;
printf("Select the operation : \n 1. Addition \t 2.Subtraction    3.Transpose       4.determinant\n");
scanf("%d",&sel1);

float c[10][10];
int n,m;
printf("enter the size   ");
scanf("%d%d",&n,&m);

if(sel1<3)

{

for(i=0;i<n;i++)
{
for(j=0;j<m;j++){
scanf("%f",&a[i][j]);

}}
printf("2nd deteerminant : \n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++){
scanf("%f",&b[i][j]);

}}
//add
if(sel1==1)
{
    for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
c[i][j]=a[i][j]+b[i][j];
}}

//sub
else
{
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
c[i][j]=a[i][j]-b[i][j];
}}}

else
{

for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
scanf("%f",&a[i][j]);
}
//transpose
if(sel1==3)
{
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
c[i][j]=a[j][i];
}
printf("outpot is : ");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++){
printf("%f\t",c[i][j]);
}
printf("\n");
}}

//determinamt
else
{
    float dete;
    dete=utd(a,n,m);
    printf("%f\n",dete);
}

}
printf("outpot is : ");
//print output
if(sel1<3)
{
    for(i=0;i<n;i++)
{
for(j=0;j<m;j++){
printf("%f\t",c[i][j]);
}
printf("\n");
}}

}
else if(sel==2)
{
 int sel2;
printf("Select the operation : \n 1.Guass Elimination \t  2.Guass-Sideal Elimination  3. Guass Jordan \n");
scanf("%d",&sel2);
int n;
printf("enter the size   ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    ans[i]=0;
for(j=0;j<n+1;j++)
scanf("%f",&a[i][j]);
}

if(sel2==1)
{
   guass(a,n);
display(a,n,ans);
}

else if(sel2==2)
{
int itr;
printf("enter the no. of iterations : ");
scanf("%d",&itr);


guasssidel(a,n);
if(flag==1)
{
  printf("guass sidel can not be applied so here we are going to verify ur answer  with guass method \n");
     guass(a,n);
display(a,n,ans);

}
else
  display1(a,n, ans, itr);

}
else if(sel2==3)
{
 guassjordan(a,n);
displayjordan(a,n,ans);

}

}
else if(sel==3)
{

  int sel3;
printf("Select the operation : \n 1.Newton forward Interpolation \t  2.Newton backward Interpolation \t   3. Divide and Difference Interpolation  \n");
scanf("%d",&sel3);
int n;
printf("enter no. of number of entries :  ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
 scanf("%f",&x[i]);
scanf("%f",&y[i]);
}
int f;
if(sel3!=3)
{
  h=x[1]-x[0];
  for(i=0;i<n-1;i++)
  {
      f=x[i+1]-x[i];
      if(f!=h)
      {
        printf("this can only be solved by Divide and Difference so we are using it\n");
        sel3=3;
        break;
      }
  }}
  if (sel3==1)
  {
      float input;
    printf("enter the input  : ");
 scanf("%f",&input);

 float out;
 out=nfi(x,y,n,input);
 printf("%f is output \n",out );

  }
  else if(sel3==2)
  {
        float input;
    printf("enter the input  : ");
 scanf("%f",&input);

 float out;
 out=nbi(x,y,n,input);
 printf("%f is output \n",out );
  }

  else if(sel3==3)
  {
    float input;
    printf("enter the input  : ");
 scanf("%f",&input);

 float out;
 out=dsd(x,y,n,input);
 printf("%f is output \n",out );
  }

}

else if(sel==4)
{
int div,mp;
printf("please select the entry form :\n  press 1. POlynomial    2. tabular    :   ");
int flag;
float h;
scanf("%d",&flag);
//start of poly input
if(flag==1)
{
float ul,ll;
printf("enter the maximum value of degree : ");
scanf("%d",&mp);
for(i=0;i<=mp;i++)
{
  printf("enter the cofficent of power %d :",i);
  scanf("%f",&coe[i]);
}
printf("enter the value of upper limit, lower limit and number of divisions :  ");
scanf("%f%f%d",&ul,&ll,&div);


h=(ul-ll)/div;
x[0]=ll;

for(i=1;i<=div;i++)
{
x[i]=x[i-1]+h;
}
for(i=0;i<=div;i++)
{
y[i]=res(coe,mp,x[i]);
}

}
//end of polynomial input start tabular
else
{
    printf("enter the no of divisions : ");
    scanf("%d",&div);
    printf("enter the value of x and y  for no of divisions :");
for(i=0;i<=div;i++)
scanf("%f%f",&x[i],&y[i]);

h= (x[div]-x[0])/div;
}
// end of tabular input
// printing x and y
for(i=0;i<=div;i++)
printf("%f %f \n",x[i],y[i]);
printf("%f\n",h);
//print trepvalue
float simp13value,simp38value;
//print simp13&38value
simp13value=simp13(y,div,h);
simp38value=simp38(y,div,h);
float weddvalue;
weddvalue=wedd(y,div,h);
float trepvalue;
trepvalue=trep(y,div,h);

if(div%6==0)
{
printf("value is  weddle is %f \n",weddvalue);
}


else if(div%3==0)
    printf("value of simp38 is %f \n",simp38value);
else if(div%2==0)
    printf("value of simp13 is %f  \n",simp13value);

else
{
printf("value is %f \n",trepvalue);
}
//print weddle
}
else if(sel==5)
{
	int cou,mp,i,j;
    printf("enter the maximum value of degree : ");
scanf("%d",&mp);
for(i=0;i<=mp;i++)
{
  printf("enter the cofficent of power %d :",i);
  scanf("%f",&coe[i]);
}
printf("do u want to enter the range or want to be found by us  press 1 if want to enter manually or 2 if not \n Enter the option  :");
scanf("%d",&cou);
float ul,ll;
int flag=0;
float root;
if(cou==1)
{
    printf("enter the value of upper limit,  :  ");
scanf("%f%f",&ul,&ll);
}
else
{
    float result,result1;
    result1=res(coe,mp,-100);
    if(result1==0)
    {
        printf("root is %d\n",i);
        root=i;
        flag=0;

    }
else{
    flag=0;
cou=2;
    for(i=-99;i<=100;i++)
    {
        result=res(coe,mp,i);
        if(result==0){
            printf("root is %d \n",i);
            root=i;
            flag=0;
            break;
        }
        else if(result1*result<0)
        {
            ul=i;
            ll=i-1;
            printf("roots lie between %f and %f\n" ,ll,ul);
            flag=1;
            break;

        }
        else if(result1*result>0)
        {
            result1=result;
            flag=2;
        }
}

if(flag==2){
    printf("value of roots exeds so please input the range \n");
    printf("enter the value of upper limit, lower limit  :  ");
scanf("%f%f",&ul,&ll);
}
}
}

	int sel5;
	if(flag==0&&cou==2)
        printf("root is found so no need now\n");
        else{
	printf("1. bisection\t  2. Newton raphson , select one :  \n");
	scanf("%d",&sel5);
	if (sel5==1)
	{
float err,rr,rl,ru;
printf("enter the accpted value of error : ");
scanf("%f",&err);
float diff;
if(ll>ul)
    diff=ll-ul;
else
    diff=ul-ll;

while(diff>err)
{
    printf("roots lie between %f and %f\n" ,ll,ul);
    root=(ll+ul)/2.0;
    rr=res(coe,mp,root);
    rl=res(coe,mp,ll);
    ru=res(coe,mp,ul);
    if(rr*rl>0)
    ll=root;
    else if(rr*ru>0)
    ul=root;
    else{
    printf("root is %f \n",root);
    break;}
if(ll>ul)
    diff=ll-ul;
else
    diff=ul-ll;

    printf("root is %f \n",root);

}
printf("final root is %f \n",root);
}
else if(sel5==2)
{

	float err,rr,rl,ru;
printf("enter the accpted value of error : ");
scanf("%f",&err);
float diff;
if(ll>ul)
    diff=ll-ul;
else
    diff=ul-ll;
int ind=1;
while(diff>err)
{
    printf("roots lie between %f and %f\n" ,ll,ul);
    rl=res(coe,mp,ll);
    ru=res(coe,mp,ul);
    if(ind==1){
    if(root<=ul&&root>=ll)
    {
        rr=fcalc1(coe,mp,ll);
        root=ll-(rl/rr);
         diff=root-ll;
        ll=root;
        ind=1;

        if(diff<0)
            diff=-1*diff;

    }
    else
        ind=0;}
    if(ind==0)
    {
        rr=fcalc1(coe,mp,ul);
        root=ul-(ru/rr);
         diff=ul-root;
        ul=root;

   if(diff<0)
            diff=-1*diff;

    }






    printf("root is %f \n",root);

}
printf("final root is %f \n",root);
}

}
}


printf("Select the operation that u want to perform :");
printf("1.Basic calculations \n 2.Solution of simultanous equation\n 3.Interpolation \n 4. Integration \n 0.exit() \n");
printf("Select the one : ");
scanf("%d",&sel);
return 0;

}}




float utd(float a[10][10], int n, int m)
{int i,j,k ;
float c;
for(k=0;k<n-1;k++)
{
for(i=k+1;i<n;i++)
{
c=a[i][k]/a[k][k];
for(j=0;j<m;j++)
{

a[i][j]=(a[i][j]-(a[k][j]*c));
}}}
float det=1;
for(i=0;i<n;i++)
{
det=det*a[i][i];
}

return det;
}

void guass(float a[10][10],int n )
{

 float temp;
 int i,j,k;
    for(i=0;i<n-1;i++)
    {
        if(a[i][i]==0)
        {
            for(j=0;j<n-1;j++)
            {
                if(a[j][j]!=0)
                {
                  for(k=0;k<=n;k++)
                  {
                      temp=a[j][k];
                      a[j][k]=a[i][k];
                      a[i][k]=temp;
                  }
              }}}}

float c;
for(k=0;k<n-1;k++)
{
for(i=k+1;i<n;i++)
{
c=a[i][k]/a[k][k];
for(j=0;j<n+1;j++)
{
a[i][j]=(a[i][j]-(a[k][j]*c));
}}}}

void guassjordan(float a[10][10],int n )
{

 float temp;
 int i,j,k;
    for(i=0;i<n-1;i++)
    {
        if(a[i][i]==0)
        {
            for(j=0;j<n-1;j++)
            {
                if(a[j][j]!=0)
                {
                  for(k=0;k<=n;k++)
                  {
                      temp=a[j][k];
                      a[j][k]=a[i][k];
                      a[i][k]=temp;
                  }
              }}}}

float c;
for(k=0;k<n-1;k++)
{
for(i=k+1;i<n;i++)
{
c=a[i][k]/a[k][k];
for(j=0;j<n+1;j++)
{
a[i][j]=(a[i][j]-(a[k][j]*c));
}}}

for(k=n-1;k>=0;k--)
{
for(i=k-1;i>=0;i--)
{
c=a[i][k]/a[k][k];
for(j=0;j<n+1;j++)
{
a[i][j]=(a[i][j]-(a[k][j]*c));
}}}

}



void displayjordan(float a[10][10],int n , float ans[10])
{

     int i;
    for(i=n-1;i>=0;i--)
    {
        ans[i]=a[i][n]/a[i][i];
    }

        for(i=1;i<=n;i++)
    {
        printf("Vlaue of x%d is %f \n",i,ans[i-1]);
    }
    printf("\n");
}






void display(float a[10][10],int n , float ans[10])
{
    float g;
    int f=1;
     int i,j,k;
    for(i=n-1;i>=0;i--)
    {
        ans[i]=((a[i][n])-g)/((a[i][i])*1.0);
        g=0;
        if(i>0){
        for(j=0;j<n-i;j++){
            g+=((a[i-1][(n-1)-j])*ans[(n-1)-j]);
        }
    }
 }
        for(i=1;i<=n;i++)
    {
        printf("Vlaue of x%d is %f \n",i,ans[i-1]);
    }
    printf("\n");
}
void guasssidel(float a[10][10], int n)

{
    int i,j,k;
float temp;
for(i=0;i<n;i++)
{
float sum=0;

for(j=0;j<n;j++)
{
sum+=a[i][j];
}
while(a[i][i]<(sum-a[i][i]))
{
float maxi=a[i][0];
int mi=0;
for(j=1;j<n;j++)
{
if(a[i][j]>maxi){
maxi=a[i][j];
mi=j;}}
if(a[i][mi]>=(sum-a[i][mi])&& mi>i)
{
for(k=0;k<n+1;k++)
{
temp=a[i][k];
a[i][k]=a[mi][k];
a[mi][k]=temp;
}}
else
{
flag=1;
break;
}
sum=0;
for(j=0;j<n;j++)
{
sum+=a[i][j];
}
}
if(flag==1)
break;
}}

void display1(float a[10][10],int n , float ans[10],int itr)
{
    float g;
     int i,j,k,m;
     for(m=0;m<itr;m++)
     {
    for(i=0;i<n;i++)
    {
      g=0;
        for(j=0;j<n;j++)
        {
          if(j!=i)
            g+=((a[i][j])*ans[j]);
      }
        ans[i]=((a[i][n])-g)/((a[i][i])*1.0);
}    }
 for(i=1;i<=n;i++)
    {
        printf("Vlaue of x%d is %f \n",i,ans[i-1]);

    }
    printf("\n");

}

float nfi(float x[10], float y[10],int n, float input)
{
    int i,j,k;
float h;
h=x[1]-x[0];
for (i=0;i<n-1;i++)
for(j=n-1;j>=i+1;j--)
{
y[j]=y[j]-y[j-1];
}
float output;
float po[10],p;
p=(input-x[0])/h;
po[0]=p;
for(i=1;i<n;i++)
{
po[i]=(po[i-1]*(input-x[i]))/((i+1)*h*1.00);
}
output=y[0];
for(i=0;i<n-1;i++)
{
output+=po[i]*y[i+1];
}
return output;
}

float nbi(float x[10], float y[10],int n, float input)
{
  int i,j,k;
float h;
h=x[1]-x[0];

for (i=0;i<n-1;i++){
for(j=0;j<n-(i+1);j++)
{
y[j]=y[j+1]-y[j];
}
}
float output;
float po[10],p;
p=(input-x[n-1])/h;
po[0]=p;

for(i=1;i<n-1;i++)
{
po[i]=(po[i-1]*(input-x[n-(1+i)]))/((i+1)*h*1.00);
}


output=y[n-1];
for(i=0;i<n-1;i++)
{
output+=po[i]*y[n-(2+i)];
}
return output;
}

float dsd(float x[10], float y[10],int n, float input)
{
    int i,j,k;
    for (i=0;i<n-1;i++)
for(j=n-1;j>=i+1;j--)
{
y[j]=(y[j]-y[j-1])/(x[j]-x[j-(1+i)]);
}
float po[10],p,output;
p=(input-x[0]);
po[0]=p;

for(i=1;i<n;i++)
{
po[i]=(po[i-1]*(input-x[i]));
}
output=y[0];
for(i=0;i<n-1;i++)
{
output+=po[i]*y[i+1];
}
return output;
}



float res(float coe[20],int p,float val)
{
int i;
float result=0;
for(i=0;i<=p;i++)
{
result+=coe[i]*(pow(val,i));
}
return result;

}

float trep(float y[20],int di,float diff)
{
int i;
float trepres=0;
trepres=y[0]+y[di];
for(i=1;i<di;i++)
{
trepres+=2*y[i];
}
trepres=(trepres*diff)/2.0;
return trepres;
}
float simp13(float y[20],int dii,float dif)
{
int i;
float simp13res=0;
simp13res=y[0]+y[dii];
for(i=1;i<dii;i=i+2)
{
simp13res+=4*y[i];
}
for(i=2;i<dii-1;i=i+2)
{
simp13res+=2*y[i];
}
simp13res=(simp13res*dif)/3.0;
return simp13res;
}

float simp38(float y[20],int d,float difff)
{
int i;
float simp38res=0;
simp38res=y[0]+y[d];
for(i=1;i<d-1;i=i+3)
{
simp38res+=3*y[i];
}
for(i=2;i<d;i=i+3)
{
simp38res+=3*y[i];
}
for(i=3;i<d-2;i=i+3)
{
simp38res+=2*y[i];
}

simp38res=(simp38res*difff*3)/8.0;
return simp38res;
}

float wedd(float y[20],int d6,float di6)
{
int i;
float weddres=0;

for(i=0;i<d6;i=i+6)
{
 weddres+=(y[i]+(5*y[i+1])+(y[i+2])+(6*y[i+3])+(y[i+4])+(5*y[i+5])+(y[i+6]));
}
weddres=(weddres*di6*3)/10.0;
return weddres;
}

float fcalc1(float coe[20],int mp,float val)
{
    int i;
    float total=0;
    for(i=1;i<=mp;i++)
        {
            total+=i*coe[i]*pow(val,i-1);
        }
        return total;

}
