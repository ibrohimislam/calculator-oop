#ifndef _MEM_H_
#define _MEM_H_ 1

#include "STL/vector.h"
#include "Expression.h"

using namespace std;

/**
 * Class Memori
 *
 * Kelas yang digunakan untuk menyimpan list ekspresi, merupakan
 * pembungkusan vector of ekspression.
 *
 * @class     Memori Memori.h "Memori.h"
 * @package   Memori
 * @brief     Kelas yang digunakan untuk menyimpan list ekspresi.
 * @author    Ibrohim Kholilul Islam
 * @version   0.1
 * @date      Maret 2015
 * @warning   Pada destructor, semua token yang terdapat pada ekspresi dihapus.
 * 
 */

class Memori
{
public:
	//ctor

	/**
	 * Constructor default
	 *
	 * Konstruktor yang digunakan untuk membuat Objek Memori kosong
	 *
	 */
	Memori();

	/**
	 * Destructor
	 *
	 * @param none
	 */
	~Memori();
	
	// memori bertanggung jawab atas penghapusan token
	// tidak diperlukan cctor dan opr= karena tidak pernah ada assignmen memori
	
	/**
	 * prosedur AddExpressionToken
	 *
	 * Prosedur yang digunakan untuk menambahkan Expression ke akhir memori
	 *
	 * @param T Expression
	 */

	void AddExpression(const Expression& E);

	/**
	 * Fungsi GetExpression
	 *
	 * Fungsi yang mengembalikan Expression ke i dari memori
	 *
	 * @param i integer
	 * @return Expression
	 */

	Expression& GetExpression(int i);

	/**
	 * Fungsi GetAllExpression
	 *
	 * Fungsi yang mengembalikan vector<Expression>
	 *
	 * @param none
	 * @return vector<Expression>
	 */

	vector<Expression>& GetAllExpression();
	
	/**
	 * Fungsi GetLength
	 *
	 * Fungsi yang mengembalikan banyaknya ekspresi dari memori
	 *
	 * @param none
	 * @return integer
	 */ 
	int GetLength();

	/**
	 * Fungsi Undo
	 *
	 * Fungsi yang mengembalikan boolean apakah perintah undo berhasi
	 *
	 * @param n integer
	 * @return boolean
	 */ 
	bool Undo(int n);

	/**
	 * Fungsi Redo
	 *
	 * Fungsi yang mengembalikan Expresi hasil perintah redo
	 *
	 * @param none
	 * @return Expression
	 */ 
	Expression& Redo();

	/**
	 * Prosedur Save
	 *
	 * Prosedur yang digunakan untuk menyimpan isi memori ke file
	 *
	 * @param none
	 */ 
	void Save();

	/**
	 * Prosedur ShowMem
	 *
	 * Prosedur yang digunakan menampilkan n Ekspresi terakhir ke layar
	 *
	 * @param n integer
	 */ 

	void ShowMem(int n);

	/**
	 * Prosedur ShowAll
	 *
	 * Prosedur yang digunakan menampilkan semua Ekspresi dari memori ke layar
	 *
	 * @param none
	 */ 
	 
	void ShowAll();
private:
	vector<Expression> VectorOfExpression;
	int head;
	int length;
};

#endif