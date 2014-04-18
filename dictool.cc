#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;
int  main(){
  ifstream infile;
  ofstream outfile;
  string infilename = "type.txt";
  string outfilename = "tdt.dic";
  string adminfn = "admin.txt";
  infile.open(infilename.c_str());
  outfile.open(outfilename.c_str());
  set<int> hs;
  int tt;
  while(infile>>tt){
    hs.insert(tt);
    cout<<tt<<endl;
  }
  

  ifstream data;
  data.open(adminfn.c_str());
  string line;
  stringstream iss;
  while(getline(data,line)){  
    //  cout<<line<<endl;
  iss.clear();
  iss.str(line);
  string token,name,type;
  getline(iss,token,',');
  getline(iss,name,',');
  getline(iss,type,',');
  // name =  name.replace(0,name.length(),"\"","");
  //replace(type,"\"","");
   name = name.substr(1,name.length()-2);
   type = type.substr(1,type.length()-2);
   int i_type = atoi(type.c_str());
   set<int>::iterator iter;
   iter = hs.find(i_type);
   if(iter!=hs.end())
     //    cout<<name<<" "<<type <<endl;
    outfile<<name<<type<<endl;
  }
  outfile.close();
  data.close();
  return 0;
}
