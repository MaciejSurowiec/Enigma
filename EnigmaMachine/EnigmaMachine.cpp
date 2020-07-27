#include <iostream>
#include <stdio.h>

using namespace std;

struct ListElement {
	int letter;
	ListElement* next;

	ListElement(int n)
	{
		letter = n;
		next = NULL;
	}
};

struct List
{
	ListElement* first;
	ListElement* last;
	int size;

	List() 
	{
		size = 0;
		first = NULL;
		last = NULL;
	}

	void Push(int letter)
	{
		ListElement* temp;
		temp = new ListElement(letter);

		if (size == 0)
		{
			first = temp;
			last = temp;
		}
		else
		{
			last->next = temp;
			last = temp;
		}

		size++;
	}

	void Pop()
	{
		if (size >= 0)
		{
			ListElement* temp = first;
			first = first->next;
			delete first;
			size--;
		}
	}

	int Get()
	{
		return first->letter;
	}
};




struct Reflector 
{
	int* permutation;

	Reflector()
	{
		permutation = NULL;
	}
};

struct Rotor
{
	int* permutation;
	int n_turn;
	int* turn;
	int speed;
	int position;

	Rotor()
	{
		permutation = NULL;
		n_turn = 0;
		turn = NULL;
		position = 1;
	}

	~Rotor()
	{
		delete[] permutation;
	}
};

struct Enigma
{
	Rotor* rotors;
	Reflector* reflectors;
	int n_rotors;
	int n_reflectors;

	Enigma()
	{
		rotors = NULL;
		reflectors = NULL;
		n_rotors = 0;
	}

	void GetRotors(int n)
	{
		scanf_s(" %d",&n_rotors);

		rotors = new Rotor[n_rotors];

		for (int i = 0; i < n_rotors; i++)
		{
			rotors[i].permutation = new int[n];
			rotors[i].speed = i;
			for (int j = 0; j < n; j++)
			{
				scanf_s(" %d", rotors[i].permutation + j);
			}

			int temp;

			scanf_s(" %d", &rotors[i].n_turn);

			if (rotors[i].n_turn)
			{
				rotors[i].turn = new int[rotors[i].n_turn];

				for (int k = 0; k < rotors[i].n_turn; k++)
				{
					scanf_s(" %d", rotors[i].turn + k);
				}
			}
		}
	}

	void GetReflectors(int n)
	{
		scanf_s(" %d", &n_reflectors);

		reflectors = new Reflector[n_reflectors];

		for (int i = 0; i < n_reflectors; i++)
		{
			reflectors[i].permutation = new int[n];
			for (int j = 0; j < n; j++)
			{
				scanf_s(" %d", &reflectors[i].permutation + j);
			}
		}
	}


	void Encrypt(List list,Rotor** u_rotors,int i_reflector,int k)
	{
		while (list.size>=0)
		{
			int temp = list.Get();


			list.Pop();
		}

	}


	void GetWord(int n)
	{
		int k;
		int i_reflector;
		Rotor** u_rotors;

		scanf_s(" %d", &k);

		u_rotors = new Rotor * [k];

		for (int l = 0; l < k; l++)
		{
			int temp, position;

			scanf_s(" %d %d", &temp, &position);

			rotors[n].position = position;
			u_rotors[l] = &rotors[n];
		}

		scanf_s(" %d", &i_reflector);

		int temp;
		scanf_s(" %d", &temp);
		List list;
		while (temp != 0)
		{
			list.Push(temp);
			scanf_s(" %d", &temp);
		}

		Encrypt(list, u_rotors,i_reflector,k);
	}
};


int main()
{
	int p;
	int n;

	Reflector* reflectors;
	Enigma enigma;

	
	scanf_s("%d", &n);

	enigma.GetRotors(n);
	enigma.GetReflectors(n);

	scanf_s(" %d", &p);

	for (int i = 0; i < p; i++)
	{
		enigma.GetWord(n);
	}
}

