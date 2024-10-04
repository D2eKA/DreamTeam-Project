#include "hw-3.h"

//ƒана строка, проверить €вл€етс€ ли она палиндромом (тип возвращаемого значени€ Ч bool)
bool isPalindrome(const std::string& str)
{
	assert(str.size() != 0);
	bool flag = true;
	for (size_t i = 0; i < str.size() / 2 + 1; i++)
	{
		if (str[i] != str[str.size() - 1 - i])
			flag = false;
	}
	return flag;
}

//ƒана строка, изображающа€ запись целого положительного числа в системе счислени€ с основанием b (0 < b <= 10). ¬ернуть соответствующее целое число (тип возвращаемого значени€ Ч int)
int stringToInt(const std::string& str)
{
	assert(str.find_first_not_of("0123456789") == std::string::npos);
	int num = 0;
	int pow = 1;
	for (size_t i = 0; i < str.size(); i++)
	{
		num += (static_cast<int>(str[str.size() - 1 - i]) - 48) * pow;
		pow *= 10;
	}
	return num;
}

//ƒана строка, состо€ща€ из русских слов, разделенных пробелами (одним или несколькими). Ќайти длину самого длинного слова
int longestWord(const std::string& str)
{
	int lenght = 0;
	int maxLenght = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			maxLenght = fmax(maxLenght, lenght);
			lenght = -1;
		}
		lenght++;
	}
	maxLenght = fmax(maxLenght, lenght);
	return maxLenght;
}

//ƒан вектор строк и строка-разделитель. —формировать из данного вектора одну строку посредством конкатенации через строку-разделитель
std::string vectorToString(const std::vector<std::string>& vect, const std::string& str)
{
	std::string new_str = "";
	for (size_t i = 0; i < vect.size(); i++)
	{
		new_str += vect[i];
		if (i != vect.size() - 1)
			new_str += str;
	}
	return new_str;
}

//ƒано целое число N. ¬ернуть строку из строчных английских букв в алфавитном пор€дке длины N. ѕосле символа 'z' должен идти символ 'a'
std::string alphabetString(int N)
{
	assert(N > 0);
	std::string str = "";
	for (int i = 0; i < N; i++)
		str += static_cast<char>(97 + i % 26);
	return str;
}

//ƒана строка, состо€ща€ из русских слов, набранных заглавными буквами и разделенных пробелами (одним или несколькими). —формировать вектор слов, содержащихс€ в этой строке
std::vector<std::string> stringToVector(const std::string& str)
{
	std::vector<std::string> vect;
	size_t lenght = 0;
	size_t ind = 0;
	bool flag = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			vect.push_back(str.substr(ind, lenght));
			lenght = -1;
			flag = true;
		}
		else if (flag && str[i] != ' ')
		{
			ind = i;
			flag = false;
		}
		lenght += 1;
	}
	if (str[str.size() - 1] != ' ')
		vect.push_back(str.substr(ind, lenght));
	return vect;
}

//ƒана строка, состо€ща€ из английских слов, набранных заглавными буквами и разделенных пробелами (одним или несколькими). —формировать вектор структур со следующей информацией по каждому слову в строке: позици€ начала слова, длина слова
std::vector<Word> stringToWordVector(const std::string& str)
{
	std::vector<Word> vect;
	size_t lenght = 0;
	size_t ind = 0;
	bool flag = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			vect.push_back(Word{ str.substr(ind, lenght), ind, lenght });
			lenght = -1;
			flag = true;
		}
		else if (flag && str[i] != ' ')
		{
			ind = i;
			flag = false;
		}
		lenght += 1;
	}
	if (str[str.size() - 1] != ' ')
		vect.push_back(Word{ str.substr(ind, lenght), ind, lenght });
	return vect;
}

void Word::printWord()
{
	std::cout << "—лово: " << word << std::endl << "ѕозици€: " << poz << std::endl << "ƒлина: " << lenght << std::endl << std::endl;
}