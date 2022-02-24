#ifndef CLASS_USER_HPP
#define CLASS_USER_HPP

class Server;

class User {

    private:
    int              _sock;
    sockaddr_in	     _addr;
    socklen_t        _csize;


    public:
    User();
    ~User();
    void    uaccept(int &);
    void    usend(std::string &);
    void    uclose();
    int     urecv(std::string *);
    void    setSocket(int &);
    int     getSocket();
};

#endif
