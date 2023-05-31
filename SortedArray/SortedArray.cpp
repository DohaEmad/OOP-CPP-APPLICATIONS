#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class FloatArray
{
public:
    int size;
    float *arr;
    int cnt;
public:
    FloatArray(int s)
    {
        size=s;
        arr=new float[size];
        cnt=0;
    }
    virtual void add(float e)
    {
        arr[cnt]=e;
        cnt++;
    }
    friend ifstream &operator>>(ifstream &in,FloatArray &obj)
    {
        float element;
        in>>element;
        obj.add(element);
        return in;
    }
    friend ofstream &operator<<(ofstream &out,FloatArray &obj)
    {
        out<<obj.cnt<<left<<setw(7)<<"|";
        for(int i=0;i<obj.cnt;i++)
        {
            out<<left<<setw(7)<<obj.arr[i];
        }
        return out;
    }

    virtual ~FloatArray()
    {
        delete []arr;
    }

};
class SortedArray:public FloatArray
{
public:
    SortedArray(int s):FloatArray(s){}
     void add(float e)
    {
         int temp_cnt= cnt;
        while(temp_cnt > 0 && arr[temp_cnt-1]>e)
        {
            arr[temp_cnt] = arr[temp_cnt-1];
            temp_cnt--;
        }
        arr[temp_cnt]=e;
        cnt++;
    }

};

class FrontArray:public FloatArray
{
public:
    FrontArray(int s):FloatArray(s){}
    void add(float e)
    {
        if(cnt==0) arr[cnt]=e;
        for(int i=cnt-1;i>=0;i--)
        {
            arr[i+1]=arr[i];

        }
        arr[0]=e;
        cnt++;
    }
};

class PositiveArray:public SortedArray
{
public:
    PositiveArray(int s):SortedArray(s){}
    void add(float e)
    {
        if(e>0)
        {
            SortedArray::add(e);

        }
    }

};

class NegativeArray:public SortedArray
{
public:
    NegativeArray(int s):SortedArray(s){}
    void add(float e)
    {
        if(e<0)
        {
            SortedArray::add(e);

        }
    }

};


int main()
{
    string file_name;
    cout<<"Enter the name of the input file:"<<endl;
    cin>>file_name;
    ifstream input_file;
    input_file.open(file_name.c_str());
    if(input_file)
    {
        FloatArray* object[10];
        FloatArray* ptr;
        for(int i=0;i<10;i++)
        {
            string choice;
            int n;
            input_file>>choice>>n;
                if(choice=="Sorted") ptr=new SortedArray(n);
                else if(choice== "Front")  ptr=new FrontArray(n);
                else if(choice=="Positive")  ptr=new PositiveArray(n);
                else if(choice=="Negative")  ptr=new NegativeArray(n);
                else  ptr=new FloatArray(n);
                object[i]=ptr;
                for(int i=0;i<n;i++)
                {
                    input_file>>*ptr ;
                }
        }
        string output_name;
        cout<<"Enter the name of the output file:"<<endl;
        cin>>output_name;
        ofstream output_file;
        output_file.open(output_name.c_str());
        for(int i=0;i<10;i++)
        {
            output_file<<*object[i]<<endl;
            delete object[i];
        }
        output_file.close();
        input_file.close();

    }
    else cout<<"cannot open this file";

    return 0;
}
