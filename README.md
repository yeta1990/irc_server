[addf11fd-0006-46cb-9fbf-1ef573c451de.webm](https://user-images.githubusercontent.com/65416560/227245474-a62533ae-f9b6-4b16-9dd2-8ab2a3712a20.webm)


## 🖥 IRC server 
- Based on RFC1459 protocol.
- Compatible with IRC clients who follow the same protocol (i.e.: irssi, Textual, etc.)
- Includes most of the commands and modes of users and operators.

### 🛠 Features
**Types of user by privileges:**
- Normal user
- Channel voiced users: able to send messages to the channel when "m" mode is enabled
- Channel operators: all privileges in a channel

**Available commands**
| Channel operations | Possible usages |
|--|--|
|JOIN  | JOIN #channel<br /> JOIN #channel,#channel2 |
|TOPIC  | TOPIC #channel<br/>TOPIC #channel :New topic |
|NAMES  | NAMES #channel,#channel2,#channel3 |
|LIST  | LIST #a,#b,#c |
|KICK  | KICK #channel user |
|PRIVMSG  | PRIVMSG user :hello<br />PRIVMSG #channel :hello |
|NOTICE  | NOTICE user :hello<br />NOTICE #channel :hello |
|WHO  | WHO user |
|WHOIS  | WHOIS user |

**Channel modes**

### ⚡ Usage
1. Compile by typing `make`
2. Choose a port and a pass and run the server **./ircserv port pass [-log]**, i.e.: `./ircserv 66667 1234`


### 📘 Documentation
- https://modern.ircdocs.horse/
- https://www.rfc-editor.org/rfc/rfc1459
- https://www.rfc-editor.org/rfc/rfc2810
- https://www.rfc-editor.org/rfc/rfc2811
- https://www.rfc-editor.org/rfc/rfc2812
- https://www.rfc-editor.org/rfc/rfc2813
