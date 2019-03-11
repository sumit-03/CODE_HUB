#include<stdio.h>
typedef struct point
{
	int x;
	int y;
}pt;

pt min(pt a[],int n)
{
	int i;
	pt minimum;
	minimum=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i].y<minimum.y)
		{
			minimum=a[i];
		}
		if(a[i].y==minimum.y)
		{
			if(a[i].x<minimum.x){ minimum=a[i];}
		}	
	}
	return minimum;	
}
float slope(pt a,pt b)
{
	float angle;
	angle=(b.y-a.y)/(b.x-a.x);
	return angle;
}

void sort(pt*a,int n)
{
	int i,angle,k;
	pt key;
	for(i=2;i<n;i++)
	{
		k=i-1;
		angle=slope(a[i],a[0]);	
		key=a[i];
		while(k>0)
		{
			if((angle>0 && slope(a[k],a[0])>0) || (angle<0 && slope(a[k],a[0])<0))
			{
			if((slope(a[k],a[0])<angle)){
			a[k+1]=a[k];
			k--;}else{break;}
			}
			if(angle>0 && slope(a[k],a[0])<0)
			{
			a[k+1]=a[k];
			k--;
			}else{break;}
		}
		a[k+1]=key;
		for(i=0;i<n;i++)
	{
		printf("%d,%d ",a[i].x,a[i].y);		
	}
}
}
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	pt a[n],minPoint;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		a[i].x=x;a[i].y=y;	
	}
	minPoint=min(a,n);
	//printf("%d->%d ",minPoint.x,minPoint.y);
	sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d,%d ",a[i].x,a[i].y);		
	}
	
}

