//
//  main.cpp
//  CS 32 HW 3
//
//  Created by Jake Herron on 5/6/19.
//  Copyright © 2019 Jake Herron. All rights reserved.
//

class Medium
{
public:
    Medium(string id);
    virtual string connect() const = 0;
    virtual string transmit(string msg) const;
    virtual string id() const;
    virtual ~Medium() = 0;
private:
    string m_id;
};

Medium::Medium(string id)
{
    m_id = id;
}

Medium::~Medium()
{}

string Medium::transmit(string msg) const
{
    return("text: " + msg);
}

string Medium::id() const
{
    return(m_id);
}

class TwitterAccount : public Medium
{
public:
    TwitterAccount(string id);
    virtual string connect() const;
    virtual ~TwitterAccount();
};

TwitterAccount::TwitterAccount(string id) : Medium(id)
{}

TwitterAccount::~TwitterAccount()
{
    cout << "Destroying the Twitter account " + id() + "." << endl;
}

string TwitterAccount::connect() const
{
    return("Tweet");
}

class Phone : public Medium
{
public:
    Phone(string id, CallType ct);
    virtual string connect() const;
    virtual string transmit(string msg) const;
    virtual ~Phone();
private:
    CallType m_ct;
};

Phone::Phone(string id, CallType ct) : Medium(id), m_ct(ct)
{}

Phone::~Phone()
{
    cout << "Destroying the phone " + id() + "." << endl;
}

string Phone::connect() const
{
    return("Call");
}

string Phone::transmit(string msg) const
{
    if(m_ct == TEXT)
    {
        return("text: " + msg);
    }
    else if(m_ct == VOICE)
    {
        return("voice: " + msg);
    }
    return("error");
}

class EmailAccount : public Medium
{
public:
    EmailAccount(string id);
    virtual string connect() const;
    virtual ~EmailAccount();
};

EmailAccount::EmailAccount(string id) : Medium(id)
{}

EmailAccount::~EmailAccount()
{
    cout << "Destroying the email account " + id() + "." << endl;
}

string EmailAccount::connect() const
{
    return("Email");
}
