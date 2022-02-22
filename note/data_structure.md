# DATA STRUCTURE

- server
  - channel[] : [channel]
  - user[] : [user]
  - config
  - error
  - message ?

- config
  - server_socket
  - address_server

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

	map<command, function>

- command
  - command: enum
  - roles: set<role(enum)>

- error
  - type (enum)
  - map<errorType, std::string> errorMessages
