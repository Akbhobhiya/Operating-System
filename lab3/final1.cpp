
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define endl    '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  10000005

float f, s, r;
void fcfs(vector<pair<int,int> >v,int at[],int bt[],int n)
{
   vector<pair<int,int> >rq;
  int j=0,count=0,left=0,flg=0;
  int et[n],tat[n],wt[n];
   pair<int,int>p;
      for(int i=0;count<n;)
      {
        
        while(j<n && i>=v[j].F)
        {
          rq.pb({bt[v[j].S],v[j].S});
          j++;
        }
        
        if(left<rq.size())
          {
            et[rq[left].S]=rq[left].F+i;
            count++;
            i+=rq[left].F;
            left++;}
        else
          i++;
      }
      int sw=0;
      for(int i=0;i<n;i++)
      {
        tat[i]=et[i]-at[i];
        wt[i]=tat[i]-bt[i];
        sw+=wt[i];
         cout<<"process: "<<i+1<<": "<<tat[i]<<" "<<wt[i]<<'\n';

      }
      cout<<"\navg waiting time: "<<(sw*1.0)/n<<'\n';
      f = (sw*1.0)/n;
}

void sjf(vector<pair<int,int> >v,int at[],int bt[],int n)
{
  vector<pair<int,int> >rq;
  int j=0,count=0,left=0,flg=0;
  int et[n],tat[n],wt[n];
   pair<int,int>p;
  for(int i=0;count<n;i++)
      {
        
        while(j<n && i==v[j].F)
        {
          rq.pb({bt[v[j].S],v[j].S});
          j++;
        }

        sort(rq.begin(),rq.end());
        rq[0].F-=1;
        if(rq[0].F==0)
        {   
          count++;
          et[rq[0].S]=i+1;
          rq[0].F=N;
        }
      }
      int sw=0;
      for(int i=0;i<n;i++)
      {
        tat[i]=et[i]-at[i];
        wt[i]=tat[i]-bt[i];
        sw+=wt[i];
         cout<<"process: "<<i+1<<": "<<tat[i]<<" "<<wt[i]<<'\n';
      }
      cout<<"\navg waiting time: "<<(sw*1.0)/n<<'\n';
      s =(sw*1.0)/n;
}
void rr(vector<pair<int,int> >v,int at[],int bt[],int n,int tq)
{
  vector<pair<int,int> >rq;
  int j=0,count=0,left=0,flg=0;
  int et[n],tat[n],wt[n];
   pair<int,int>p;
      for(int i=0;count<n;)
      {
        
        while(j<n && i>=v[j].F )
        {
          rq.pb({bt[v[j].S],v[j].S});
          j++;
        }
        if(flg)
        {
          rq.pb(p);
          flg=0;
        }
        if(left<rq.size())
        {int jump=min(tq,rq[left].F);
                rq[left].F=max(rq[left].F-tq,0);
                
                if(rq[left].F)
                  { p={rq[left].F,rq[left].S};
                  flg=1;}
                else
                {
                  count++;
                  et[rq[left].S]=i+jump;
                }
                i+=jump;
                left++;}
        else
          i++;
      }
      int sw=0;
      for(int i=0;i<n;i++)
      {
        tat[i]=et[i]-at[i];
        wt[i]=tat[i]-bt[i];
        sw+=wt[i];
        cout<<"process: "<<i+1<<": "<<tat[i]<<" "<<wt[i]<<'\n';
      }
      

      cout<<"\navg waiting time: "<<(sw*1.0)/n<<'\n';
      r = (sw*1.0)/n;
}
int main()
{
  cin.tie(0);
  cout.tie(0);
  int TESTS=1;
//  cin>>TESTS;
  while(TESTS--)
  {
      int n,tq,sum=0;
      cout<<"enter number of processes:";
      cin>>n;
      cout<<"enter time quantum:";
      cin>>tq;
      int at[n],bt[n]; 
      vector<pair<int,int> >v;
      cout<<"enter arrival time and burst time :\n";
      for(int i=0;i<n;i++)
         {
          cin>>at[i]>>bt[i];
          v.pb({at[i],i});
          sum+=bt[i];
         }
      sort(v.begin(),v.end());
      cout<<"\nround robin: turnaround time    waiting time\n";   
      rr(v,at,bt,n,tq);
      cout<<"\nfcfs: turnaround time    waiting time\n"; 
      fcfs(v,at,bt,n);
      cout<<"\nsjf: turnaround time    waiting time\n"; 
      sjf(v,at,bt,n);
      
      float fcfs1 = f;
      float sjf1 = s;
      float rr1 = r;
      if(fcfs1<=rr1 && fcfs1<=sjf1)cout<<"\nFIRST COME FIRST SERVE ALGORITHM\n";
      else if(sjf1<=rr1 && sjf1<=fcfs1)cout<<"\nSHORTEST JOB FIRST ALGORITHM\n";
      else if(rr1<=fcfs1 && rr1<=fcfs1)cout<<"\nROUND ROBIN ALGORITHM IS BEST\n";

  }
  return 0;
}