#include <iostream>
#include <utility>
#include<cmath>
#include<vector>
#include<list>
#include<bits/stdc++.h> 
using namespace std;


//int gd = 0;
pair<double,double>cd[20];

vector< vector<int> > v1(5);

int valuearray[100]={0};

int totalnodes=0;

int non;
double RTSR = 0.9;
long   np = 1;//Global count of the no of path

void initvec()
{
  for(int i=0;i<5;i++)
  {
    v1[i] = vector<int>(9);
     for(int j=0;j<9;j++)
      {
        v1[i][j] = -1;
      }
  } 


   for (int i = 0; i <5; i++) { 
        for (int j = 0; j < v1[i].size(); j++) 
            cout << v1[i][j] << " "; 
        cout << endl; }

 
}



void input()
{ 
  
cd[0].first = 80;     cd[0].second =140;
cd[1].first = 111.74; cd[1].second =178.64;
cd[2].first =105.28;  cd[2].second =96.86;
cd[3].first = 131.06; cd[3].second =224.75;
cd[4].first = 159.83; cd[4].second =164.95;
cd[5].first = 154.33; cd[5].second =106.61;
cd[6].first= 134.85; cd[6].second =56.54;
cd[7].first = 180.25; cd[7].second =215.79;
cd[8].first = 209.75; cd[8].second =167.65;
cd[9].first =203.82; cd[9].second =113.68;
cd[10].first =184.35; cd[10].second =63.58;
cd[11].first = 230.19; cd[11].second =213.28;
cd[12].first =233.38; cd[12].second =73.36;
cd[13].first = 272.3;  cd[13].second =186.33;
cd[14].first = 267.6; cd[14].second =109.81;
cd[15].first = 302;   cd[15].second =146.1;

totalnodes=16;
/*
cout<<"enter the number of nodes\n";
cin>>non;

for(int i=0;i<non;i++)
{
  cout<<"enter the "<<i<<" node: ";
  cin>>cd[i].first>>cd[i].second;
}


*/
} 

float path_range(double d)
{
 
  float h;
  float w;
  float h1;
  int   r = 50;
 // double d = 222.08;
  h1 = (2*d*d -r*r)/ (2*d*d);
  h  = d* sqrt(1 - pow(h1,2) );
  w  = 2*h;
  return w;
}

void Algo(pair<double,double>source)
{
cout<<"\n\nThe source node is "<<source.first<<"\n\n";

  long pn = 1; //no of paths in the iteration
  int c = 0,ct = 0;
  pair<double,double>tem[4];
  vector<int>tem1;
  int sindex;

double dis = sqrt(pow(cd[non-1].first - source.first, 2) + pow(cd[non-1].second - source.second, 2)*1.0);
cout<<"The path range for this source node is: "<<path_range(dis)<<"\n";




for(int i = 0;i<16;i++)
  {
    if(cd[i].first == source.first)
      sindex = i;

    
    if(cd[i].first > source.first)
    {  //cout<<"\nyp\n";
      int dis = (int)sqrt(pow(cd[i].first - source.first, 2) + pow(cd[i].second - source.second, 2)*1.0);
      if(dis == 50 || dis==49){
        tem[c].first = cd[i].first;
        tem[c].second = cd[i].second;
        cout<<"values ";
        cout<<tem[c].first<<" "<<tem[c].second<<"\n";
        
        tem1.push_back(i);    
        
        
        c+=1;
    }
     }
       }
       ct = c;




int y[10],y1=0;
for(int i = 0;i<5; i++)
 {
     vector<int>:: iterator it = v1[i].end()-1 ; 
     if(*it == sindex)
      { y[y1] = i;
        y1++;
      }
 }

if(y1 == 0)
 {  
 for(int i = 0;i<c;i++)
   {
     vector<int> t;
     
     t.push_back(sindex);
     t.push_back(tem1[i]);
     v1[i]=t;
    }    
 }


 
 else{
 
   for(int i=0;i<y1;i++)
   {  
     int k  = tem1[ tem1.size() - c];
     v1[y[i]].push_back(k);
     tem1.erase(tem1.begin(),tem1.begin()+1);
     c-=1;
   }
while(c){
  vector<int>tr;
  tr.insert(tr.end(),v1[y[0]].begin(),v1[y[0]].end()-1);
  
  int r = 0;
  for(;r<v1.size();r++)
    if(v1[r][0] ==-1 )
      break;

  v1[r] = tr;
  v1[r].push_back(tem1[0]);
  tem1.erase(tem1.begin(),tem1.begin()+1);
  c--;
}

}
 
 
 for (int i = 0; i <5; i++) { 
        for (int j = 0; j < v1[i].size(); j++) 
            cout << v1[i][j] << " "; 
        cout << endl; }
 
 
 
 
  cout<<"\n\n";
 

float ESHTSR = 0.92;
float ESPTSR = ESHTSR / ct;
float temp = ESPTSR; 

while(ESPTSR < RTSR)
{ pn+=1;
  np+=1;
  ESPTSR+=temp;  
}

for(int i = 0;i< ct ;i++)
{ 
  if (tem[i].first==cd[totalnodes-1].first && tem[i].second==cd[totalnodes-1].second)
    continue;
  
  Algo(tem[i]); 
}


}


int datadelivery(int data, int source, int path){
int s=v1[path][source];
cout<<"\n"<<s<<" ";
if (valuearray[s]==data && s==totalnodes-1){return 0;}
else
valuearray[s]=data;
if (s==totalnodes-1){return 0;}
datadelivery(data,source+1,path);
}

int main() {
  input();
  initvec();
  
  pair<double,double>source;
  source.first = cd[0].first;
  source.second = cd[0].second;
  Algo(source);
  
  cout<<"The number of paths: "<<np<<"\n";
srand(time(0));
vector <int> order;
for(int i=0;i<50;i++){
int r = rand()%4;

int x=0;
for(int j=0;j<order.size();j++){
if(order.at(j)==r){x=1;break;}
}
if(x==0){order.push_back(r);}
}  

  for(int i=0;i<order.size();i++){
  cout<<"\n Path "<<order.at(i);
datadelivery(101010, 0, i );
cout<<"\n";
for(int i=0;i<16;i++){
cout<<" "<<valuearray[i];}


}

 
  return 0;
   
}
