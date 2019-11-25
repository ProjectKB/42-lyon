/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 13:54:31 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 15:27:04 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using str = string;

ofstream	write_into_file(str const file_name)
{
	// use c_str if file name is into var
	//ofstream flux(file_name.c_str()); // create/replace file content
	ofstream	flux(file_name.c_str(), ios::app); // add content to the EOF (app : append)

	if (flux) // check that everything is ok
		flux << "This is a test.\n";
	return (flux);
}

ifstream	read_file(str const file_name)
{
	ifstream	flux(file_name.c_str());
	str			lign;

	if (flux)
	{
		str		word;
		char	a;

		//read one letter two times
		for (int i(0); i < 2; ++i)
		{
			flux.get(a);
			cout << "Letter is: " << a << "\n";
		}

		// read one word three times
		for (int i(0); i < 3; ++i)
		{
			flux >> word;
			cout << "Word is: " << word << "\n";
		}

		// read all file line by line
		while (getline(flux, lign))
			cout << "lign is: " << lign << "\n";
	}
	return (flux);
}

/* UTIL FUNCTION

   * get read head pos
		ifstream -> tellg()
		ofstream -> tellp()

	* move into file_name
		ifstream -> seekg(nb_char_to_add_to_position, position)
		ofstream -> seekp()
		there are three possible position : ios::beg/end/cur

	* get size of file
		file.seekg(0, ios::end), size = file.tellg()
*/

int main()
{
	string const	file_name("./test.txt");
	ifstream		flux;

	//write_into_file(file_name);
	flux = read_file(file_name);
	flux.close();
	return (0);
}
