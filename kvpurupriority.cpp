#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int id,arrtime,btime,ct,tat,wt;
};

struct Process2
{
    int p,id2,arrtime2,btime2,ct2,tat2,wt2;
};
bool cmp2(Process2 a,Process2 b)
{
    return (a.p<b.p);
}
bool cmp(Process a,Process b)
{
    return (a.btime<b.btime);
}
int main()
{
    int n;
    cout<<"Enter no of Process\n";
    cin>>n;
    Process shilpa[n];
    vector<Process> puru,ks;
    int f=0,goku;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cout<<"Enter arrival time of "<<i<<" Process\n";
        cin>>x;
        cout<<"Enter burst time of "<<i<<" Process\n";
        cin>>y;
        if(x==0){
        f=1;
        goku=i;
        }
        shilpa[i].arrtime=x;
        shilpa[i].btime=y;
        shilpa[i].id=i;
    }
    int i;
    if(f==1)
    {
        Process av;
        av.arrtime=shilpa[goku].arrtime;
        av.btime=shilpa[goku].btime;
        av.ct=shilpa[goku].btime;
        av.tat=av.ct-av.arrtime;
        av.wt=av.tat-av.btime;
        av.id=shilpa[goku].id;
        puru.push_back(av);
    }
    sort(shilpa,shilpa+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(shilpa[i].arrtime==0)
        continue;
        else
        ks.push_back(shilpa[i]);
    }
    for(auto i : ks)
    {
        Process av;
        av.arrtime=i.arrtime;
        av.btime=i.btime;
        av.ct=puru[puru.size()-1].ct+av.btime;
        av.tat=av.ct-av.arrtime;
        av.wt=av.tat-av.btime;
        av.id=i.id;
        puru.push_back(av);
    }
    cout<<"ID "<<" AT "<<" BT "<<" CT "<<" TAT "<<" WT "<<endl;
    vector<Process2> yi;
    for(auto i : puru)
    {
        Process2 u;
        u.p=1+(i.wt/i.btime);
        u.id2=i.id;
        u.arrtime2=i.arrtime;
        u.btime2=i.btime;
        u.ct2=0;
        u.tat2=0;
        u.wt2=0;
        yi.push_back(u);
    }
    sort(yi.begin(),yi.end(),cmp2);
    vector<Process2> d,yiu;
    yi[0].ct2=yi[0].btime2;
    yi[0].tat2=yi[0].ct2-yi[0].arrtime2;
    yi[0].wt2=yi[0].tat2-yi[0].btime2;
    d.push_back(yi[0]);
    for(int j=1;j<yi.size();j++)
    {
    	yiu.push_back(yi[j]);
	}
	sort(yiu.begin(),yiu.end(),cmp2);
	reverse(yiu.begin(),yiu.end());
    for(int i=0;i<yiu.size();i++)
    {
        Process2 av;
        av.arrtime2=yiu[i].arrtime2;
        av.btime2=yiu[i].btime2;
        av.ct2=d[d.size()-1].ct2+av.btime2;
        av.tat2=av.ct2-av.arrtime2;
        av.wt2=av.tat2-av.btime2;
        av.id2=yiu[i].id2;
        d.push_back(av);
    }
    int avgwat=0,avgtat=0;
    cout<<"ID "<<" AT "<<" BT "<<" CT "<<" TAT "<<" WT "<<endl;
    for(auto i : d)
    {
    	avgwat+=i.wt2;
    	avgtat+=i.tat2;
        cout<<i.id2<<"  "<<i.arrtime2<<"   "<<i.btime2<<"   "<<i.ct2<<"   "<<i.tat2<<"   "<<i.wt2<<endl;
    }
    cout<<"Average Waiting Time is "<<(avgwat/n)<<endl;
    cout<<"Average Turn Around Time is "<<(avgtat/n)<<endl;



}
