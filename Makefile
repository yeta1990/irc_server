NAME = ircserv

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -O2 -std=c++98 -pedantic
DEBUGFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3 -fsanitize=address
INC = -I ./inc 

SRCS = srcs/main.cpp srcs/Server.cpp srcs/Client.cpp srcs/Channel.cpp srcs/Command.cpp srcs/utils.cpp 

COMMANDS_F	= 	Join.cpp Leave.cpp Kick.cpp Invite.cpp Topic.cpp List.cpp Message.cpp Whois.cpp Who.cpp Mode.cpp Nick.cpp Pass.cpp User.cpp Names.cpp

SRCS += $(addprefix srcs/commands/, $(COMMANDS_F))

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $@

debug: CXXFLAGS = $(DEBUGFLAGS)
debug: $(OBJS) 
	$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re 
