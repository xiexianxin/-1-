#include <iostream>
#include <fstream> //文件读取
#include <sstream> //数据类型转换 
#include <iostream>
#include <cassert>
#include<cstring>
#include<string>
#include <vector>
#include <iomanip>
#include<cmath>
using namespace std;

//模板函数：将string类型变量转换为常用的数值类型  
template <class Type>  
Type stringToNum(const string& str)  
{  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
} 


//存储数据的结构体 
struct student
{
	string id;
	string name;
	string city;
	string gender;
	string height;
	float data[10];
	string constitution;	
}datab[10000], datatxt[10000], data[10000];
int databasecnt = 0, datatxtcnt = 0;
int allcnt = 0;
//读取数据库
void readdatabase(string file) {
	//读取文件 
	ifstream inFile("data.xlsx", ios::in);
	
	//文件不存在 
    if (!inFile)
    {
        cout << "打开文件失败！" << endl;
        return ; 
    }
    
    //文件存在 
    string content; 
    
    //先读取一行不做处理，剔除表格第一行列名 
    getline(inFile, content);
    string s;
	string tmp;
	int cnt = 0;
	int len=16;
	int stringturn(string s);
	for (int i = 0; i <len ; i++) {
		if (s[i] == ' ') {
			tmp = "";
			if (cnt == 0) {
				datab[cnt].id = cnt + 1;
			}
			else if (cnt == 1) {
				datab[cnt].name = tmp;
			}
			else if (cnt == 2) {
				datab[cnt].city= tmp;
			}
			else if (cnt == 3) {
				datab[cnt].constitution = tmp;
			}
			else if (cnt == 4) {
				datab[cnt].height = stringturn(tmp);
			}
			else if (cnt >= 5 && cnt <= 16) {
				datab[cnt].data;
			}
		}
		else if (i == len - 1) {
			tmp += s[i];
			datab[cnt++].name= tmp;
			break;
		}
		else {
			tmp += s[i];
		}
	}
	
	databasecnt = cnt;
	
}

int pw(int x) {
	int ans = 1, t = 10;
	while (x) {
		if (x & 1) ans *= t;
		t *= t;
		x >>= 1;
	}
	return ans;
}

//string转int
int stringturn(string s) {
	int ans = 0;
	for (int i = s.length(); i >= 0; i--) {
		ans += (s[i] - '0')*pw(s.length() - i - 1);
	}
	return ans;
}

//读取txt
void readtxt(string file) {
	//读取文件 
	ifstream inFile("txt.txt", ios::in);
	
	//文件不存在 
    if (!inFile)
    {
        cout << "打开文件失败！" << endl;
        return ; 
    }
    
    //文件存在 
    string content; 
    
    //先读取一行不做处理，剔除表格第一行列名 
    getline(inFile, content);
    string s;
	string tmp;
	int cnt = 0;
	int len=16;
	int stringturn(string s);
	for (int i = 0; i <len ; i++) {
		if (s[i] == ' ') {
			tmp = "";
			if (cnt == 0) {
				datab[cnt].id = cnt + 1;
			}
			else if (cnt == 1) {
				datab[cnt].name = tmp;
			}
			else if (cnt == 2) {
				datab[cnt].city= tmp;
			}
			else if (cnt == 3) {
				datab[cnt].constitution = tmp;
			}
			else if (cnt == 4) {
				datab[cnt].height = stringturn(tmp);
			}
			else if (cnt >= 5 && cnt <= 16) {
				datab[cnt].data;
			}
		}
		else if (i == len - 1) {
			tmp += s[i];
			datab[cnt++].name= tmp;
			break;
		}
		else {
			tmp += s[i];
		}
	}
	
	databasecnt = cnt;
	
	return;
}

//合成数据库与txt
void compose() {
	allcnt = 0;
	for (int i = 0; i < databasecnt; i++) {
		data[allcnt++] = datab[i];
	}
	for (int i = 0; i < datatxtcnt; i++) {
		data[allcnt++] = datatxt[i];
	}
	
}

//将数据读取到内存中read() 
void read(vector<student*> &arr)
{
	//读取文件 
	ifstream inFile("dataall.csv", ios::in);
	
	//文件不存在 
    if (!inFile)
    {
        cout << "打开文件失败！" << endl;
        return ; 
    }
    
    //文件存在 
    string content; 
    
    //先读取一行不做处理，剔除表格第一行列名 
    getline(inFile, content);
    
    //按行读取文件内容，保留到数组中 
    while (getline(inFile, content))
    { 
		//对数据行进行切割处理
        student *node=new student;
		int pos;
		
        //ID
		 pos=content.find(",");
		 node->id=content.substr(0,pos);
		 content=content.substr(pos+1,content.size());
		 
		 //Name
		 pos=content.find(",");
		 node->name=content.substr(0,pos);
		 content=content.substr(pos+1,content.size());
		 
		 //City
		 pos=content.find(",");
		 node->city=content.substr(0,pos);
		 content=content.substr(pos+1,content.size());
		 
		 //Gender
		 pos=content.find(",");
		 node->gender=content.substr(0,pos);
		 content=content.substr(pos+1,content.size());
		 
		 //Height
		 pos=content.find(",");
		 node->height=content.substr(0,pos);
		 content=content.substr(pos+1,content.size());
		 
		 //class
		 for(int t=0;t<10;t++)
		 {
		 	pos=content.find(",");
		 	node->data[t]=stringToNum<float>(content.substr(0,pos)); 
		 	content=content.substr(pos+1,content.size());
		 }
		 
		 //Constitution
		 pos=content.find(",");
		 node->constitution=content.substr(0,pos);
		 content=content.substr(pos+1,content.size());
		 
		 arr.push_back(node);
    }
    inFile.close();
} 

//输出内存中的数据show() 
void show(vector<student*> &arr)
{
	cout<<"\t\t\t<<<输出整理好的数据如下:>>>\t\t\t"<<endl;
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]->id<<" ";
		cout<<arr[i]->city<<" ";
		cout<<arr[i]->name<<" ";
		cout<<arr[i]->city<<" ";
		cout<<arr[i]->gender<<" ";
		cout<<arr[i]->height<<" ";
		for(int j=0;j<10;j++)
		{
			cout<<arr[i]->data[j]<<" ";
		}
		cout<<arr[i]->constitution<<endl;
	}
	cout<<endl;
}

void solve1(vector<student*> &arr)
{
	int total=0;
	float c[10]={0};
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]->city!="Beijing") continue;
		for(int j=0;j<10;j++)
		{
			c[j]+=arr[i]->data[j];
		}
		total++;
	}
	cout<<"\t\t\t<<<1,学生中家乡在Beijing的所有课程的平均成绩是多少？>>>\t\t\t"<<endl;
	cout<<"答：\n学生中家乡在Beijing的所有课程的平均成绩是:"<<endl;
	for(int i=1;i<=10;i++)
	cout<<"课程"<<i<<"    ";
	cout<<endl;
	for(int i=0;i<10;i++)
	cout<<left<<setw(7)<<setiosflags(ios::fixed)<<setprecision(2)<<c[i]/total<<"  ";
	cout<<endl<<endl;
} 
void solve2(vector<student*> &arr)
{
	int total=0;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]->city!="Guangzhou"||arr[i]->data[0]<=80||arr[i]->data[8]<=9||arr[i]->gender!="boy") continue;
		total++;
	}
cout<<"\t\t\t<<<2,学生中家乡在广州，课程1在80分以上，且课程9在9分以上的男同学的数量为?>>>\t\t\t"<<endl;
	cout<<"答：\n学生中家乡在广州，课程1在80分以上，且课程9在9分以上的男同学的数量为： "<<total<<endl;
	cout<<endl<<endl;
} 
void solve3(vector<student*> &arr)
{
	/*
		给四个体测成绩等级设置权重 
		bad=60;
		general=70;
		good=80;
		excellent=90; 
	*/ 
	float score_Guangzhou=0,score_Shanghai=0;
	int num1=0,num2=0;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]->gender!="girl") continue;
		if(arr[i]->city=="Guangzhou") 
		{
			if(arr[i]->constitution=="excellent") score_Guangzhou+=90;
			if(arr[i]->constitution=="good") score_Guangzhou+=80;
			if(arr[i]->constitution=="general") score_Guangzhou+=70;
			if(arr[i]->constitution=="bad") score_Guangzhou+=60;
			num1++;
		}
		if(arr[i]->city=="Shanghai") 
		{
			if(arr[i]->constitution=="excellent") score_Shanghai+=90;
			if(arr[i]->constitution=="good") score_Shanghai+=80;
			if(arr[i]->constitution=="general") score_Shanghai+=70;
			if(arr[i]->constitution=="bad") score_Shanghai+=60;
			num2++;
		}
	}
	score_Guangzhou/=num1;
	score_Shanghai/=num2;
	cout<<"\t\t\t<<<3,比较广州和上海两地女生的平均体能测试成绩，哪个地区的更强些？>>>\t\t\t"<<endl;
	if(score_Guangzhou>score_Shanghai) cout<<"答：\n广州地区女生的平均体能测试成绩更好"<<endl; 
	if(score_Guangzhou<score_Shanghai) cout<<"答：\n上海地区女生的平均体能测试成绩更好"<<endl;
	if(score_Guangzhou==score_Shanghai) cout<<"答：\n两地区女生的平均体能测试成绩一致"<<endl;
	cout<<endl; 
} 

//计算均值 
float mean(float *&ai,int ai_len)
{
	int len=ai_len;
	if(len==0) return 0;
	float sum=ai[0];
	for(int i=1;i<len;i++)
	{
		sum+=ai[i];
	}
	return sum/len;
}
//计算相关性 
float correlation(float *&ai,float *&bi,int len)
{
	float s1=0,s2=0,s3=0;
	float avg_a=mean(ai,len);
	float avg_b=mean(bi,len);
	for(int i=0;i<len;i++)
	{
		s1+=(ai[i]-avg_a)*(bi[i]-avg_b);
		s2+=(ai[i]-avg_a)*(ai[i]-avg_a);
		s3+=(bi[i]-avg_b)*(bi[i]-avg_b);
	}
	return s1/sqrt(s2*s3);
}
void solve4(vector<student*> &arr)
{
	int len=arr.size();
	float arr_correlation[9];//记录相关性的数组 
	float *grade_constitution=new float[len];//记录体测成绩 
	float *grade_course=new float[len];//记录课程成绩 
	 //体测成绩 
	for(int i=0;i<len;i++)
	{
		if(arr[i]->constitution=="excellent") grade_constitution[i]=90;
		if(arr[i]->constitution=="good") grade_constitution[i]=80;
		if(arr[i]->constitution=="general") grade_constitution[i]=70;
		if(arr[i]->constitution=="bad") grade_constitution[i]=60;
	}
	
	//分别计算9门成绩相关性 
	for(int j=0;j<9;j++)
	{
		for(int p=0;p<len;p++)
		{
			grade_course[p]=arr[p]->data[j];
		} 
		arr_correlation[j]=correlation(grade_course,grade_constitution,len);//相关性 
	} 
	
	//各科相关性
	cout<<"\t\t\t<<<4,九门课的成绩分别与体能成绩的相关性是多少？>>>\t\t\t"<<endl;
	cout<<"答：\n各科相关性如下："<<endl; 
	for(int i=1;i<=9;i++)
	cout<<"课程"<<i<<"    ";
	cout<<endl;
	for(int i=0;i<9;i++)
	cout<<left<<setw(7)<<setiosflags(ios::fixed)<<setprecision(4)<<arr_correlation[i]<<"  ";
	cout<<endl<<endl;
	
	delete []grade_constitution;
	delete []grade_course; 
} 
//收尾工作，回收内存 
void clean(vector<student*> &arr)
{
	vector<student *>::iterator it;
	for(it=arr.begin();it!=arr.end();it++)
	{
		delete *it;
		*it=NULL;
	}
} 
int main()
{
	vector<student *>arr; 
	read(arr);
	//输出所有数据 
	show(arr);
	//1.学生中家乡在Beijing的所有课程的平均成绩。
	solve1(arr);
	//2.学生中家乡在广州，课程1在80分以上，且课程9在9分以上的男同学的数量。
	solve2(arr);
	//3.比较广州和上海两地女生的平均体能测试成绩，哪个地区的更强些？
 	solve3(arr);
 	//4.学习成绩和体能测试成绩，两者的相关性是多少？
 	solve4(arr);
 	//内存回收 
 	clean(arr);
}
