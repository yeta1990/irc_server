#include "Kick.hpp"

Kick::Kick(void) {
}

Kick::Kick(Server *s, std::string type) : Command(s, type) {}

Kick::~Kick(void)
{
}

void Kick::exec(std::string params, Client& client)
{
	std::array<std::string, 2> 	paramsAndMessage;
	std::vector<std::string>	channelsAndUsersRaw;
	std::vector<std::string>	channelsRaw;
	std::vector<std::string>	usersRaw;
	Channel						*channel;
	Client						*clientToKick;

	paramsAndMessage[0] = "";
	paramsAndMessage[1] = "";
	channel = NULL;
	clientToKick = NULL;
	paramsAndMessage = separateParamsAndMessage(params);
	channelsAndUsersRaw = splitToVector(trimSpaces(paramsAndMessage[0]), ' ');
	channelsRaw = splitToVector(channelsAndUsersRaw[0], ',');
	usersRaw = splitToVector(channelsAndUsersRaw[1], ',');
	for (size_t i = 0; i < channelsRaw.size(); i++)
	{
		channel = this->server->findChannel(channelsRaw[i]);
		if (!channel)
			client.sendReply(ERR_NOSUCHCHANNEL(client.getNickname(), channelsRaw[i]));
		else
			kickUsersFromChannel(usersRaw, channel, paramsAndMessage[1], client);
	}
}

void	Kick::kickUsersFromChannel(std::vector<std::string> &usersRaw, Channel *channel, std::string message, Client &executor)
{
	Client		*toKick;

	toKick = NULL;
	if (!channel->isUserInChannel(executor.getNickname()))
		return (executor.sendReply(ERR_NOTONCHANNEL(executor.getNickname(), channel->getName())));
	else if (!channel->isChannelOperator(executor.getNickname()))
		return (executor.sendReply(ERR_CHANOPRIVSNEEDED(executor.getNickname(), channel->getName())));
	for (size_t j = 0; j < usersRaw.size(); j++)
	{
		toKick = channel->getUser(usersRaw[j]);
		if (!toKick)
			executor.sendReply(ERR_USERNOTINCHANNEL(executor.getNickname(), usersRaw[j], channel->getName()));
		else
		{
			channel->broadcast(BROADCAST_KICK(executor.getLogin(), channel->getName(), usersRaw[j], message) + "\r\n");
			channel->removeClientFromChannel(usersRaw[j]);
		}
		
	}
}


