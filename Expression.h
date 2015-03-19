#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include "STL/vector.h"
#include "Bilangan.h"
#include "Arab.h"
#include "Romawi.h"
#include "Perintah.h"
#include "Operator.h"
#include "Token.h"

using namespace std;

/**
 * Class Expression
 * 
 * Kelas yang digunakan untuk merepresentasikan ekspresi, merupakan 
 * pembungkusan vector of (pointer to token).
 *
 * @class     Expression Expression.h "Expression.h"
 * @package   Memori
 * @brief     Kelas yang digunakan untuk merepresentasikan ekspresi,
 *            merupakan pembungkusan vector of (pointer to token).
 * @author    Ibrohim Kholilul Islam
 * @version   0.1
 * @date      Maret 2015
 * @warning   semua pointer token yang diberikan dapat ditunjuk oleh lebih dari 1 ekspresi.
 * @warning   destructor tidak bertangung jawab kepada token yang diberikan.
 * 
 */

class Expression
{
public:
	//ctor

	/**
	 * Constructor default
	 *
	 * Konstruktor yang digunakan untuk membuat Objek Expression kosong
	 *
	 */

	Expression(){}

	/**
	 * Copy Constructor
	 *
	 * Konstruktor yang digunakan untuk membuat Objek Expression dari Objek Expression lain.
	 *
	 */

	Expression(const Expression& E1);
	//dtor tidak bertangung jawab kepada token yang diberikan
	
	/**
	 * Destructor
	 *
	 * @param none
	 */
	~Expression();

	/**
	 * Operator assignment
	 *
	 * Fungsi yang digunakan untuk menyalin objek ekspresi dari objek ekspresi
	 *
	 */

	Expression& operator= (const Expression& E1);

	/**
	 * Fungsi GetToken
	 *
	 * Fungsi yang mengembalikan pointer token ke i
	 *
	 * @param i integer
	 * @return pointer to Token
	 */ 

	Token* GetToken(int i) const;

	/**
	 * Fungsi GetLength
	 *
	 * Fungsi yang mengembalikan panjang ekspresi
	 *
	 * @param none
	 * @return integer
	 */ 

	int GetLength() const;

	/**
	 * prosedur AddToken
	 *
	 * Prosedur yang digunakan untuk menambahkan Token ke akhir ekspresi
	 *
	 * @param T Pointer to Token
	 */

	void AddToken(Token* T);
	
private:
	vector<Token*> VectorOfToken;
};

#endif