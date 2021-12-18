#include<iostream>
#include<string>
using namespace std;
struct Node
{
	string RegNo;
	string Name;
	int age;
	string city;
	float CGPA;
	Node* Previous;
	Node* Next;
};
class Student
{
	string RegNo;
	string Name;
	int age;
	string city;
	float CGPA;
public:
	Student()
	{
		RegNo = '\0';
		Name = '\0';
		age = 0;
		city = '\0';
		CGPA = 0;
	}
	void setRegNo(string RegNo)
	{
		this->RegNo = RegNo;
	}
	void setName(string Name)
	{
		this->Name = Name;
	}
	void setage(int age)
	{
		this->age = age;
	}
	void setcity(string city)
	{
		this->city = city;
	}
	void setCGPA(float CGPA)
	{
		this->CGPA = CGPA;
	}
	string getRegNo()
	{
		return RegNo;
	}
	string getname()
	{
		return Name;
	}
	int getage()
	{
		return age;
	}
	string getcity()
	{
		return city;
	}
	float getCGPA()
	{
		return CGPA;
	}
};
class DECK
{
	Node* Front;
	Node* Rear;
public:
	DECK()
	{
		Front = NULL;
		Rear = NULL;
	}
	void insertinfront(Node* N, Student S)
	{
		N = new Node();
		if (Front == NULL)
		{
			N->RegNo = S.getRegNo();
			N->Name = S.getname();
			N->age = S.getage();
			N->city = S.getcity();
			N->CGPA = S.getCGPA();
			N->Next = NULL;
			N->Previous = NULL;
			Front = N;
			Rear = N;
		}
		else
		{
			N->RegNo = S.getRegNo();
			N->Name = S.getname();
			N->age = S.getage();
			N->city = S.getcity();
			N->CGPA = S.getCGPA();
			Front->Previous = N;
			N->Next = Front;
			N->Previous = NULL;
			Front = N;
		}
	}
	void insertinend(Node *N,Student S)
	{
		N = new Node();
		if (Front == NULL)
		{
			insertinfront(N, S);
		}
		else
		{
			N->RegNo = S.getRegNo();
			N->Name = S.getname();
			N->age = S.getage();
			N->city = S.getcity();
			N->CGPA = S.getCGPA();
			N->Next = NULL;
			N->Previous = Rear;
			Rear->Next = N;
			Rear = N;
		}
	}
	void insertinmiddle(Node* N, Student S,string Reg_No)
	{
		Node* M = Front;
		N = new Node();
		while (M != NULL)
		{
			if (M->RegNo == Reg_No)
			{
				break;
			}
			else
			{
				M = M->Next;
			}
		}
		N->RegNo = S.getRegNo();
		N->Name = S.getname();
		N->age = S.getage();
		N->city = S.getcity();
		N->CGPA = S.getCGPA();
		Node* K = M->Next;
		N->Next = K;
		N->Previous = M;
		M->Next = N;
		K->Previous = N;
	}
	void Deleteatfront()
	{
		Node* N = Front;
		Front = Front->Next;
		Front->Previous = NULL;
		free(N);
	}
	void Deleteatend()
	{
		Node* N = Rear;
		Rear = Rear->Previous;
		Rear->Next = NULL;
		free(N);
	}
	void DeleteFromMiddle(string Reg_No)
	{
		Node* N = Front;
		if (Front->RegNo == Reg_No)
		{
			Deleteatfront();
			return;
		}
		if (Rear->RegNo == Reg_No)
		{
			Deleteatend();
			return;
		}
		while (N != NULL)
		{
			if (N->RegNo == Reg_No)
			{
				break;
			}
			else
			{
				N = N->Next;
			}
		}
		Node* Pre = N->Previous;
		Node* After = N->Next;
		Pre->Next = After;
		After->Previous = Pre;
		free(N);

	}
	void display()
	{
		Node* N = Front;
		while (N != NULL)
		{
			cout << "Student Registration Number is " << N->RegNo << endl;
			cout << "Student Name is " << N->Name << endl;
			cout << "Student age is " << N->age << endl;
			cout << "Student belongs to " << N->city << endl;
			cout << "Student CGPA is " << N->CGPA << endl;
			N = N->Next;
			cout << "\n";
		}
	}
};
int main()
{
	Node* N{};
	Student S;
	DECK D;
	S.setRegNo("BSE203146");
	S.setName("Moiz Ahmed");
	S.setage(21);
	S.setcity("Karachi");
	S.setCGPA(3.84);
	D.insertinfront(N, S);
	Student S1;
	S1.setRegNo("BSE203017");
	S1.setName("Zohaib Ahmed");
	S1.setage(24);
	S1.setcity("Jhelum");
	S1.setCGPA(3.87);
	D.insertinend(N, S1);
	Student S2;
	S2.setRegNo("BSE203097");
	S2.setName("Laiba Nazli");
	S2.setage(20);
	S2.setcity("Bahalwarpur");
	S2.setCGPA(3.47);
	D.insertinend(N, S2);
	D.display();
	Student S3;
	S3.setRegNo("BSE203166");
	S3.setName("Mariam Iqbal");
	S3.setage(22);
	S3.setcity("Rawalpindi");
	S3.setCGPA(3.52);
	D.insertinmiddle(N,S3,"BSE203017");
	D.display();
	D.Deleteatfront();
	cout << "\t\t\t\tAfter Deleting the student at front\n";
	D.display();
	D.insertinfront(N, S);
	D.Deleteatend();
	D.display();
	D.insertinend(N, S2);
	D.DeleteFromMiddle("BSE203166");
	cout << "\t\t\t\tAfter Deleting the student from middle\n";
	D.display();

}