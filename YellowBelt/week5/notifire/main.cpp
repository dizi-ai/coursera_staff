#include <iostream>
#include <string>


void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

/*
 Реализуйте здесь классы INotifier, SmsNotifier, EmailNotifier
 */
class INotifier{
public:
    virtual void Notify(const std::string& message)=0;
};
class SmsNotifier:public INotifier{
public:
    SmsNotifier(const std::string& t):number(t){
    }
    void Notify(const std::string& message) override{
        SendSms(number, message);
    }

private:
    const std::string number;
};
class EmailNotifier:public INotifier{
public:
    EmailNotifier(const std::string& t): email(t){}
    void Notify(const std::string& message) override{
        SendEmail(email, message);
    }
private:
    const std::string email="";
};
void Notify(INotifier& notifier, const std::string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms{"+7-495-777-77-77"};
    EmailNotifier email{"na-derevnyu@dedushke.ru"};

    Notify(sms, "I have White belt in C++");
    Notify(email, "And want a Yellow one");
    return 0;
}