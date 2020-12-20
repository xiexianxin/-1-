#include <iostream>
#include <fstream> //�ļ���ȡ
#include <sstream> //��������ת�� 
#include <iostream>
#include <cassert>
#include<cstring>
#include<string>
#include <vector>
#include <iomanip>
#include<cmath>
using namespace std;

//ģ�庯������string���ͱ���ת��Ϊ���õ���ֵ����  
template <class Type>  
Type stringToNum(const string& str)  
{  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
} 


//�洢���ݵĽṹ�� 
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
//��ȡ���ݿ�
void readdatabase(string file) {
	//��ȡ�ļ� 
	ifstream inFile("data.xlsx", ios::in);
	
	//�ļ������� 
    if (!inFile)
    {
        cout << "���ļ�ʧ�ܣ�" << endl;
        return ; 
    }
    
    //�ļ����� 
    string content; 
    
    //�ȶ�ȡһ�в��������޳�����һ������ 
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

//stringתint
int stringturn(string s) {
	int ans = 0;
	for (int i = s.length(); i >= 0; i--) {
		ans += (s[i] - '0')*pw(s.length() - i - 1);
	}
	return ans;
}

//��ȡtxt
void readtxt(string file) {
	//��ȡ�ļ� 
	ifstream inFile("txt.txt", ios::in);
	
	//�ļ������� 
    if (!inFile)
    {
        cout << "���ļ�ʧ�ܣ�" << endl;
        return ; 
    }
    
    //�ļ����� 
    string content; 
    
    //�ȶ�ȡһ�в��������޳�����һ������ 
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

//�ϳ����ݿ���txt
void compose() {
	allcnt = 0;
	for (int i = 0; i < databasecnt; i++) {
		data[allcnt++] = datab[i];
	}
	for (int i = 0; i < datatxtcnt; i++) {
		data[allcnt++] = datatxt[i];
	}
	
}

//�����ݶ�ȡ���ڴ���read() 
void read(vector<student*> &arr)
{
	//��ȡ�ļ� 
	ifstream inFile("dataall.csv", ios::in);
	
	//�ļ������� 
    if (!inFile)
    {
        cout << "���ļ�ʧ�ܣ�" << endl;
        return ; 
    }
    
    //�ļ����� 
    string content; 
    
    //�ȶ�ȡһ�в��������޳�����һ������ 
    getline(inFile, content);
    
    //���ж�ȡ�ļ����ݣ������������� 
    while (getline(inFile, content))
    { 
		//�������н����и��
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

//����ڴ��е�����show() 
void show(vector<student*> &arr)
{
	cout<<"\t\t\t<<<�������õ���������:>>>\t\t\t"<<endl;
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
	cout<<"\t\t\t<<<1,ѧ���м�����Beijing�����пγ̵�ƽ���ɼ��Ƕ��٣�>>>\t\t\t"<<endl;
	cout<<"��\nѧ���м�����Beijing�����пγ̵�ƽ���ɼ���:"<<endl;
	for(int i=1;i<=10;i++)
	cout<<"�γ�"<<i<<"    ";
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
cout<<"\t\t\t<<<2,ѧ���м����ڹ��ݣ��γ�1��80�����ϣ��ҿγ�9��9�����ϵ���ͬѧ������Ϊ?>>>\t\t\t"<<endl;
	cout<<"��\nѧ���м����ڹ��ݣ��γ�1��80�����ϣ��ҿγ�9��9�����ϵ���ͬѧ������Ϊ�� "<<total<<endl;
	cout<<endl<<endl;
} 
void solve3(vector<student*> &arr)
{
	/*
		���ĸ����ɼ��ȼ�����Ȩ�� 
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
	cout<<"\t\t\t<<<3,�ȽϹ��ݺ��Ϻ�����Ů����ƽ�����ܲ��Գɼ����ĸ������ĸ�ǿЩ��>>>\t\t\t"<<endl;
	if(score_Guangzhou>score_Shanghai) cout<<"��\n���ݵ���Ů����ƽ�����ܲ��Գɼ�����"<<endl; 
	if(score_Guangzhou<score_Shanghai) cout<<"��\n�Ϻ�����Ů����ƽ�����ܲ��Գɼ�����"<<endl;
	if(score_Guangzhou==score_Shanghai) cout<<"��\n������Ů����ƽ�����ܲ��Գɼ�һ��"<<endl;
	cout<<endl; 
} 

//�����ֵ 
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
//��������� 
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
	float arr_correlation[9];//��¼����Ե����� 
	float *grade_constitution=new float[len];//��¼���ɼ� 
	float *grade_course=new float[len];//��¼�γ̳ɼ� 
	 //���ɼ� 
	for(int i=0;i<len;i++)
	{
		if(arr[i]->constitution=="excellent") grade_constitution[i]=90;
		if(arr[i]->constitution=="good") grade_constitution[i]=80;
		if(arr[i]->constitution=="general") grade_constitution[i]=70;
		if(arr[i]->constitution=="bad") grade_constitution[i]=60;
	}
	
	//�ֱ����9�ųɼ������ 
	for(int j=0;j<9;j++)
	{
		for(int p=0;p<len;p++)
		{
			grade_course[p]=arr[p]->data[j];
		} 
		arr_correlation[j]=correlation(grade_course,grade_constitution,len);//����� 
	} 
	
	//���������
	cout<<"\t\t\t<<<4,���ſεĳɼ��ֱ������ܳɼ���������Ƕ��٣�>>>\t\t\t"<<endl;
	cout<<"��\n������������£�"<<endl; 
	for(int i=1;i<=9;i++)
	cout<<"�γ�"<<i<<"    ";
	cout<<endl;
	for(int i=0;i<9;i++)
	cout<<left<<setw(7)<<setiosflags(ios::fixed)<<setprecision(4)<<arr_correlation[i]<<"  ";
	cout<<endl<<endl;
	
	delete []grade_constitution;
	delete []grade_course; 
} 
//��β�����������ڴ� 
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
	//����������� 
	show(arr);
	//1.ѧ���м�����Beijing�����пγ̵�ƽ���ɼ���
	solve1(arr);
	//2.ѧ���м����ڹ��ݣ��γ�1��80�����ϣ��ҿγ�9��9�����ϵ���ͬѧ��������
	solve2(arr);
	//3.�ȽϹ��ݺ��Ϻ�����Ů����ƽ�����ܲ��Գɼ����ĸ������ĸ�ǿЩ��
 	solve3(arr);
 	//4.ѧϰ�ɼ������ܲ��Գɼ������ߵ�������Ƕ��٣�
 	solve4(arr);
 	//�ڴ���� 
 	clean(arr);
}
