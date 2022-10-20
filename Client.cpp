#include "Client.hpp"

Client::Client(int fd, std::string server) : _nickname(""), _fd(fd), _server(server), _invisible(false)
{
	
}

Client::Client(void)
{
}

Client::~Client(void)
{
//	std::cout << "Destroyed client" << std::endl;
}

Client& Client::operator=(Client const &c)
{
	if (this != &c)
	{
		this->_nickname = c._nickname;
		this->_fd = c._fd;
	}
	return (*this);	
}

Client::Client(Client const &c) : _nickname(c.getNickname()), _fd(c._fd), _server(c._server) {}

std::string Client::getNickname(void) const
{
	return (this->_nickname);
}

std::string Client::getUser(void) const
{
	return (this->_user);
}

int	Client::getFd(void) const
{
	return (this->_fd);
}

void	Client::setNick(std::string nickname)
{
	this->_nickname = nickname;	
}

void	Client::setUser(std::string user)
{
	this->_user = user;	
}

std::string	Client::getLogin(void) const
{
	return (_nickname + "!" + _user + "@" + _server);
}

void	Client::processModeUser(char sign, char c, std::vector<std::string>& newModeUser)
{
	if (sign == '+' && c == 'i' && !_invisible)
	{
		this->_invisible = true;	
		newModeUser[0] += "i";
	}
	else if (sign == '-' && c == 'i' && _invisible)
	{
		this->_invisible = false;	
		newModeUser[1] += "i";
	}

}
