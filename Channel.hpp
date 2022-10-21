#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <list>
# include <vector>
# include "Client.hpp"
# include <sys/socket.h>
# include "Reply.hpp"
# include "Server.hpp"

class Server;
class Channel {

	public:
		Channel(std::string name, Client* channelOperator, Server *s);
		~Channel(void);
		Channel& operator=(Channel const &c);
		Channel(Channel const &c);

		std::string	getName(void) const;
		std::string	getTopic(void) const;
		std::list<Client*>& getUsers(void);
		Client*	getUser(std::string nick);

		void	broadcast(std::string message);
		void	broadcast_except_myself(std::string message, Client &c);

//JOIN
		void	join(Client *client);
		void	joinWelcomeSequence(Client& c);

//KICK
		void	kick(std::string nickName, Client &c);

//TOPIC
		void	topic(std::string topicInstruction, Client &c);

//MODE
		void	mode(std::list<std::string> params, Client& c);
		void	channelModes(Client& c);
		void	processMode(char sign, char c, std::list<std::string>::iterator &it);
		void	processMode(char sign, char c, std::list<std::string>::iterator &it, std::vector<std::string>& modeAndArguments, Client& executor);

//PRIVMSG && NOTICE
		void	messageToChannel(std::string message, Client& c);
		//NOTICE

		std::string	getUsersAsString(void);
		Client*	findUserInList(std::string nick, std::list<Client*> &l);
		void	removeClientFromList(std::list<Client*> &l, std::string nickName);
		void	addClientToList(std::list<Client*> &l, Client* c);

		bool	isNormalUser(std::string nickName);
		bool	isChannelOperator(std::string nickName);
		bool	isVoiced(std::string nickName);
		bool	isUserInChannel(std::string nickName);
		bool	isBanned(std::string mask);

	private:
		Channel(void);
		std::list<Client*>	users;
		std::string			_name;
		std::list<Client*>	_operators;
		std::list<Client*>	_voiced;
		std::list<Client*>	_ban;
		std::list<Client*>	_exception;

		char				_message[2048];
		std::string			_topic;
		bool				_noExternalMsg;
		bool				_topicLock;
		bool				_invitationRequired;
		bool				_secret;
		bool				_moderated;
		bool				_hasKey;
		int					_userLimit;
		std::string			_keypass;

		Server				*_server;
};

#endif
