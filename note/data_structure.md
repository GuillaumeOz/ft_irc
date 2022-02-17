# DATA STRUCTURE

- server
  - channel[] : [channel]
  - user[] : [user]
  - message ?

- user
  - socket : int
  - nickname : std::string
  - username : std::string
  - channel[] : [channel]
  - operator : operator
  - message ?

- channel
  - user[] : [user]
  - mode : enum

- opertaor
  - role : enum

- message
  - value : std::string
  - type : enum
  - dest : channel
  - src : user.socket

	map<command>, function>

- command
  - value : enum
  - role : role(enum)
