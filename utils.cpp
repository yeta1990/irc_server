#include <utils.hpp>

std::list<std::string>	split_cpp(std::string str, char c)
{
	size_t					i;
	std::list<std::string>	l;
	std::string				sub;
	size_t					pos;

	i = 0;
	pos = 0;
	sub = "";
	while (pos != std::string::npos)
	{		
		while (str[i] == ' ')
		{
			i++;
			pos++;
		}
		pos = str.find(c, i);
		sub = str.substr(i, pos - i);
		if (sub != "")
			l.push_back(sub);
		i = pos + 1;
	}
	return (l);
}

bool	anyDuplicatedChar(std::string str)
{
	//std::string::difference_type 	n;
	size_t							i;

	i = 0;
	while (i < str.size())
	{
		if (std::count(str.begin(), str.end(), str[i]) > 1)
			return (true);
		i++;
	}
	return (false);	
}

std::string	composeModeResponse(std::vector<std::string> modeAndArguments)
{
	std::vector<std::string>::iterator	it2;
	std::string	message;
	
	message = "";
	//":" + c.getLogin() + " MODE " + this->_name + " ";
	bool	anyModeChange;

	anyModeChange = false;
	it2 = modeAndArguments.begin();
	if ((*it2).size() > 1)
	{
		message += *it2;
		anyModeChange = true;
	}
	it2++;
	if ((*it2).size() > 1)
	{
		message += *it2 + " ";
		anyModeChange = true;
	}
	else 
		message += " ";
	it2++;
	while (it2 < modeAndArguments.end())
	{
		message += *it2 + " ";
		it2++;
	}
	message += "\r\n";
	if (anyModeChange)
		return (message);//this->broadcast(message);
	return ("");
	//std::cout << message << std::endl;
}

/*
int	main(void)
{
	std::string str; 
	std::list<std::string>::iterator 	it;
	std::list<std::string>				sp;

	str = "hola que tal ";
	sp = split_cpp(str, ' ');	
	for (it = sp.begin(); it != sp.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}
*/
