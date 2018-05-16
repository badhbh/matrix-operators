
#include <iostream>
#include <fstream>

using namespace std;

class matrix {
	int col, str;
	int **mot;
public:
	matrix()
	{
		col = 0;
		str = 0;
		mot = NULL;
	}
	matrix(int m, int n) {
		m = str;
		n = col;
		mot = NULL;
		if (m > 0 && n > 0) {
			mot = new int *[m];
			for (int i = 0; i < m; ++i) {
				mot[i] = new int[m];
				for (int j = 0; j < n; ++j) {
					mot[i][j] = 0;
				}
			}
			
		}
		else {
			col = 0;
			str = 0;
			mot = NULL;
		}

	}
	~matrix() {
		for (int i = 0; i < str; ++i)
			delete mot[i];
		delete[] mot;

	}
	matrix(matrix const &klon)
	{
		this->col = klon.col;
		this->str = klon.str;
		mot = new int *[str];
		for (int i = 0; i < str; ++i)
		{
			mot[i] = new int[str];
				for (int j = 0; j < col; ++j)
				{
					mot[i][j] = klon.mot[i][j];
				}
		}

	}
	
	int & operator ()(const int i, const int j)
	{
			return mot[i][j];
	}
	matrix operator * (const int k)
	{
		matrix creature(str, col);
		for(int i = 0; i < str; ++i)
			for (int j = 0; j < col; ++j)
			{
				creature.mot[i][j] = this->mot[i][j] * k;
			}
		return creature;
	}
	matrix operator +(matrix const  &klon)
	{
		matrix dodi;
		if (this->str == klon.str && this->col == klon.str)
		{
			for (int i = 0; i < str; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					dodi.mot[i][j] = this->mot[i][j] + klon.mot[i][j];
				}
			}
		}
		else { cerr << "0"; }
		return dodi;
	}
	matrix operator +(const int kok)
	{
		matrix prod;
		for (int i = 0; i < this->str; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				prod.mot[i][j] = this->mot[i][j] + kok;
			}
		}
		return prod;
	}
	matrix operator -(matrix const &klon)
	{
		matrix dodi;
		if (this->str == klon.str && this->col == klon.str)
		{
			for (int i = 0; i < str; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					dodi.mot[i][j] = this->mot[i][j] - klon.mot[i][j];
				}
			}
		}
		else { cerr << "0"; }
		return dodi;
	}
	matrix operator -(const int kok)
	{
		matrix prod;
		for (int i = 0; i < this->str; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				prod.mot[i][j] = this->mot[i][j] - kok;
			}
		}
		return prod;
	}
	matrix dot (matrix const &klon)
	{
		matrix loli(this->col, klon.str);
		if (this->col == klon.str)
		{
			for (int i = 0; i < col; ++i)
			{
				for (int j = 0; j < klon.str; ++j)
				{
					loli.mot[i][j] = this->mot[i][j] * klon.mot[i][j];
				}
			}
		}
		else { cerr << "0"; }
		return loli;
	}
	matrix operator +=(const int yk)
	{
		
		for (int i = 0; i < str; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				this->mot[i][j] = this->mot[i][j] + yk;
			}
		}
		return *this;
	}
	matrix operator +=(matrix const &klon)
	{
		if(this->str == klon.str && this->col == klon.col)
		{ 
			for (int i = 0; i < str; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					klon.mot[i][j] = klon.mot[i][j] + this->mot[i][j];
				}
			}
			return klon;
		}
		else { cerr << "0"; }
	}
	matrix operator -=(matrix const &klon)
	{
		if (this->str == klon.str && this->col == klon.col)
		{
			for (int i = 0; i < str; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					klon.mot[i][j] = klon.mot[i][j] - this->mot[i][j];
				}
			}
			return klon;
		}
		else { cerr << "0"; }
	}
	matrix operator -=(const int lol)
	{
		for (int i = 0; i < str; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				this->mot[i][j] = this->mot[i][j] - lol;
			}
		}
		return *this;
	}
	matrix operator *=(matrix const &klon)
	{
		if (this->col == klon.str)
		{
			for (int i = 0; i < col; ++i)
			{
				for (int j = 0; j < klon.str; ++j)
				{
					this->mot[i][j] = this->mot[i][j] * klon.mot[i][j];
				}
			}
		}
		else { cerr << "0"; }
		return *this;
	}
	matrix operator *=(const int ku)
	{
		for (int i = 0; i < str; ++i)
			for (int j = 0; j < col; ++j)
			{
				this->mot[i][j] = this->mot[i][j] * ku;
			}
		return *this;
	}
	void trans()
	{
		int per;
		if (this->col > 0 && this->str > 0 )
		{
			for (int i = 0; i < this->str; ++i)
			{
				for (int j = 0; j < this->col; ++j) {
					per = this->mot[i][j];
					this->mot[i][j] = this->mot[j][i];
					this->mot[j][i] = per;
				}
			}
		}
		else { cerr << "0"; }
	}
	friend ostream & operator <<(const matrix &klon, ostream &out)
	{
		for (int i = 0; i < klon.str; ++i)
		{
			for (int j = 0; j < klon.col; ++j)
				out << klon.mot[i][j];
		}
	}
	friend istream & operator >>(const matrix &klon, istream &in)
	{
		for (int i = 0; i < klon.str; ++i)
		{
			for (int j = 0; j < klon.col; ++j)
				in >> klon.mot[i][j];
		}
	}
};
int main()
{
	return 0;
}
